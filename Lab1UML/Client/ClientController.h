#pragma once

#include "GameRender.h"
#include "GameModel.h"
#include "GameController.h"
#include "MenuController.h"
#include "Player.h"

namespace Docking::Client {
	class ClientController
	{		
	public:
		ClientController();
		void Run();
	private:
		NetworkManager m_NetworkManager;
		Player m_Player;
	};
}
