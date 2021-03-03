#pragma once

#include "GameRender.h"
#include "GameModel.h"
#include "GameController.h"
#include "MenuController.h"
#include "Player.h"
#include "Singleton.h"

namespace Docking::Client {
	class ClientController : public Singleton<ClientController>
	{		
	public:
		void Run();
	private:
		ClientController(sf::RenderWindow& window);

		Player m_Player;
		sf::RenderWindow& m_Window;

		friend class Singleton<ClientController>;
	};
}
