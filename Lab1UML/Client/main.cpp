#include "GameModel.h"
#include "ClientController.h"
#include "GameRender.h"
#include "ClientController.h"
#include "MenuController.h"
#include "LogController.h"
#include "LeadersController.h"
#include "LeadersRender.h"
#include "NetworkManager.h"
#include "Assets.h"

#include <fstream>

//#define DOCTEST_CONFIG_IMPLEMENT
//#include "doctest.h"

//#include <random>
//std::random_device rd;
//std::mt19937 mersenne(rd());

/*TEST_CASE("testing GameModel") {
    GameModel model;
    SUBCASE("testing constructor") {
        CHECK(model.get_winner() == 0);
        CHECK(!model.is_end());
        bool red_turn = true;
        for (int i = 0; i < 10; i++) {
            CHECK(red_turn == model.is_red_turn());
            model.next_turn();
            red_turn = !red_turn;
        }
    }
    SUBCASE("testing restore") {
        GameModel new_model;
        for (int i = 0; i < 100; i++) {
            model.is_red_turn() ? model.set_red_position(mersenne() % 8, mersenne() % 8) : model.set_blue_position(mersenne() % 8, mersenne() % 8);
            model.make_move(mersenne() % 4);
            model.next_turn();
        }
        model.restore();
        CHECK(model == new_model);
    }
    SUBCASE("testing setters & getters of position") {
        for (int i = 0; i < 100; i++) {
            int x = mersenne() % 8, y = mersenne() % 8;
            model.set_red_position(x, y);
            CHECK(model.get_red_x_pos() == x);
            CHECK(model.get_red_y_pos() == y);
        }
        for (int i = 0; i < 100; i++) {
            int x = mersenne() % 8, y = mersenne() % 8;
            model.set_blue_position(x, y);
            CHECK(model.get_blue_x_pos() == x);
            CHECK(model.get_blue_y_pos() == y);
        }
    }
    SUBCASE("testing correct move") {
        SUBCASE("testing going beyond the map boundaries") {
            REQUIRE(model.is_red_turn());

            model.set_red_position(0, 4);
            CHECK(!model.make_move(0));
            CHECK(model.make_move(1));

            model.next_turn();

            REQUIRE(!model.is_red_turn());

            model.set_blue_position(4, 0);
            CHECK(!model.make_move(2));
            CHECK(model.make_move(3));

            model.next_turn();

            REQUIRE(model.is_red_turn());

            model.set_red_position(7, 4);
            CHECK(!model.make_move(1));
            CHECK(model.make_move(0));

            model.next_turn();

            REQUIRE(!model.is_red_turn());

            model.set_blue_position(4, 7);
            CHECK(!model.make_move(3));
            CHECK(model.make_move(2));

            model.next_turn();
        }
        SUBCASE("testing block occupancy with allies") {
            REQUIRE(model.is_red_turn());

            model.set_red_position(0, 5);
            CHECK(model.make_move(2));
            model.set_red_position(0, 4);
            CHECK(model.make_move(2));
            model.set_red_position(0, 3);
            CHECK(!model.make_move(2));

            model.next_turn();

            REQUIRE(!model.is_red_turn());

            model.set_blue_position(2, 0);
            CHECK(model.make_move(1));
            model.set_blue_position(3, 0);
            CHECK(model.make_move(1));
            model.set_blue_position(4, 0);
            CHECK(!model.make_move(1));
        }
        SUBCASE("testing block occupancy with enemies") {
            REQUIRE(model.is_red_turn());

            model.set_red_position(0, 2);
            CHECK(model.make_move(1));

            model.next_turn();

            REQUIRE(!model.is_red_turn());

            model.set_blue_position(2, 7);
            CHECK(model.make_move(2));
            model.set_blue_position(2, 4);
            CHECK(model.make_move(2));
            model.set_blue_position(2, 3);
            CHECK(!model.make_move(2));

            model.next_turn();

            REQUIRE(model.is_red_turn());
            model.set_red_position(2, 2);
            CHECK(!model.make_move(3));
            CHECK(model.make_move(2));
            model.set_red_position(2, 1);
            CHECK(!model.make_move(2));
        }
        SUBCASE("testing connecting") {
            SUBCASE("red winner") {
                REQUIRE(model.is_red_turn());

                model.set_red_position(0, 2);
                CHECK(model.make_move(1));
                model.set_red_position(2, 2);
                CHECK(model.make_move(1));
                model.set_red_position(4, 2);
                CHECK(model.make_move(1));
                CHECK(model.get_winner() == 0);

                model.set_red_position(0, 3);
                CHECK(model.make_move(1));
                model.set_red_position(2, 3);
                CHECK(model.make_move(1));
                model.set_red_position(4, 3);
                CHECK(model.make_move(1));
                CHECK(model.get_winner() == 0);

                model.set_red_position(0, 4);
                CHECK(model.make_move(1));
                model.set_red_position(2, 4);
                CHECK(model.make_move(1));
                model.set_red_position(4, 4);
                CHECK(model.make_move(1));
                CHECK(model.get_winner() == 0);

                model.set_red_position(0, 5);
                CHECK(model.make_move(1));
                model.set_red_position(2, 5);
                CHECK(model.make_move(1));
                model.set_red_position(4, 5);
                CHECK(model.make_move(1));

                CHECK(model.get_winner() == 1);
            }
            SUBCASE("blue winner") {
                model.next_turn();
                REQUIRE(!model.is_red_turn());

                model.set_blue_position(2, 0);
                CHECK(model.make_move(3));
                model.set_blue_position(2, 2);
                CHECK(model.make_move(3));
                model.set_blue_position(2, 4);
                CHECK(model.make_move(3));
                CHECK(model.get_winner() == 0);

                model.set_blue_position(3, 0);
                CHECK(model.make_move(3));
                model.set_blue_position(3, 2);
                CHECK(model.make_move(3));
                model.set_blue_position(3, 4);
                CHECK(model.make_move(3));
                CHECK(model.get_winner() == 0);

                model.set_blue_position(4, 0);
                CHECK(model.make_move(3));
                model.set_blue_position(4, 2);
                CHECK(model.make_move(3));
                model.set_blue_position(4, 4);
                CHECK(model.make_move(3));
                CHECK(model.get_winner() == 0);

                model.set_blue_position(5, 0);
                CHECK(model.make_move(3));
                model.set_blue_position(5, 2);
                CHECK(model.make_move(3));
                model.set_blue_position(5, 4);
                CHECK(model.make_move(3));

                CHECK(model.get_winner() == 2);
            }
        }
        SUBCASE("testing blocking") {
            SUBCASE("blocking in corner") {
                REQUIRE(model.is_red_turn());
                model.set_red_position(0, 5);
                CHECK(model.make_move(2));
                CHECK(model.get_winner() == 0);

                model.next_turn();

                model.set_blue_position(3, 0);
                CHECK(model.make_move(0));
                CHECK(model.get_winner() == 0);

                model.set_blue_position(2, 7);
                CHECK(model.make_move(2));
                CHECK(model.get_winner() == 0);

                model.set_blue_position(2, 5);
                CHECK(model.make_move(2));
                CHECK(model.get_winner() == 0);

                model.set_blue_position(2, 3);
                CHECK(model.make_move(2));
                CHECK(model.get_winner() == 0);

                model.set_blue_position(2, 1);
                CHECK(model.make_move(0));
                CHECK(model.get_winner() == 0);

                model.set_blue_position(1, 1);
                CHECK(model.make_move(0));

                CHECK(model.get_winner() == 2);
            }
            SUBCASE("blocking in corner") {
                REQUIRE(model.is_red_turn());
                model.set_red_position(0, 2);
                CHECK(model.make_move(1));
                model.set_red_position(2, 2);
                CHECK(model.make_move(1));
                CHECK(model.get_winner() == 0);

                model.next_turn();

                model.set_blue_position(3, 0);
                CHECK(model.make_move(3));
                CHECK(model.get_winner() == 0);

                model.set_blue_position(4, 0);
                CHECK(model.make_move(3));
                CHECK(model.get_winner() == 0);

                model.set_blue_position(4, 7);
                CHECK(model.make_move(2));
                CHECK(model.get_winner() == 0);
                model.set_blue_position(4, 4);
                CHECK(model.make_move(2));
                CHECK(model.get_winner() == 0);

                model.set_blue_position(5, 0);
                CHECK(model.make_move(3));

                CHECK(model.get_winner() == 2);
            }
        }
    }
}*/

int main(){
    using namespace Docking::Client;
    sf::RenderWindow window(sf::VideoMode(640, 690), "Docking", sf::Style::Titlebar | sf::Style::Close);
    Assets::Create();
    std::ifstream fin("config.txt");
    int port;
    fin >> port;
    fin.close();

    NetworkManager::Create("localhost", port);
    ClientController::Create(window);
    GameModel::Create();
    GameRender::Create(window);
    GameController::Create();
    MenuRender::Create(window);
    MenuController::Create();
    LogRender::Create(window);
    LogController::Create();
    LeadersRender::Create(window);
    LeadersController::Create();
    Docking::Client::ClientController::Get().Run();
	return 0;
}