#include <SFML/Network.hpp>

#include "ClientController.h"
#include "MenuController.h"
#include "EnumCode.h"
#include "LogController.h"
#include "LeadersController.h"
#include "LeadersRender.h"

namespace Docking::Client {
	ClientController::ClientController():
		m_NetworkManager("localhost", 45000){}

	void ClientController::Run() {
		sf::RenderWindow window(sf::VideoMode(640, 690), "Docking", sf::Style::Titlebar | sf::Style::Close);
		GameModel model;
		GameRender gameRender(model, window);
		GameController gameController(model, gameRender, m_NetworkManager);
		MenuRender menuRender(window);
		MenuController menuController(menuRender);
		LogRender logRender(window);
		LogController logController(logRender, m_NetworkManager);
		LeadersRender leadersRender(window);
		LeadersController leadersController(leadersRender, m_NetworkManager);

		Code code = logController.Run(m_Player);
		while (true) {
			switch (code) {
			case Code::Exit: {
				window.close();
				return;
			}
			case Code::Menu: {
				code = menuController.Run();
				break;
			}
			case Code::PlayGame: {
				gameController.Restore();
				model.Restore();
				gameRender.Restore();
				code = gameController.Run();
				break;
			}
			case Code::Leaders: {
				leadersRender.SetPlayer(m_Player);
				code = leadersController.Run();
				break;
			}
			}
		}
	}
}