#include <SFML/Network.hpp>

#include "ClientController.h"
#include "MenuController.h"
#include "EnumCode.h"

namespace Docking::Client {
	ClientController::ClientController() {}

	void ClientController::Run() {
		sf::RenderWindow window(sf::VideoMode(640, 640), "Docking", sf::Style::Titlebar | sf::Style::Close);
		GameModel model;
		GameRender gameRender(model, window);
		GameController gameController(model, gameRender);
		MenuRender menuRender(window);
		MenuController menuController(menuRender);
		Code code = menuController.Run();
		while (true) {
			switch (code) {
			case Code::Exit: {
				window.close();
				return;
			}
			case Code::PlayGame: {
				code = gameController.Run();
			}
			}
		}
	}
}