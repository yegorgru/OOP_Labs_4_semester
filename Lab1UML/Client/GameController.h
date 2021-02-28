#pragma once

#include "GameRender.h"
#include "GameModel.h"
#include "NetworkManager.h"
#include "EnumCode.h"

namespace Docking::Client {
	class GameController
	{
	public:
		enum class ClientCode : int {
			ClosedGame = 0,
			Position,
			Up,
			Down,
			Left,
			Right
		};

		enum class ServerCode : int {
			StartGame = 0,
			EndGame,
			SetPosition,
		};

		GameController(GameModel& game, GameRender& render);
		Code Run();

	private:
		GameModel& m_Model;
		GameRender& m_Render;

		NetworkManager m_NetworkManager;

		bool m_IsActive;
		bool m_MyTurn;
	};
}
