#pragma once

#include "GameRender.h"
#include "GameModel.h"
#include "NetworkManager.h"
#include "EnumCode.h"

namespace Docking::Client {
	class GameController
	{
	public:
		GameController(GameModel& game, GameRender& render, NetworkManager& network);
		Code Run();
		void Restore();
	private:
		GameModel& m_Model;
		GameRender& m_Render;

		NetworkManager& m_NetworkManager;

		bool m_IsEnd;
		bool m_MyTurn;
	};
}
