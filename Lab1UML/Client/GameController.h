#pragma once

#include "GameRender.h"
#include "GameModel.h"
#include "NetworkManager.h"
#include "EnumCode.h"
#include "Controller.h"
#include "Singleton.h"

namespace Docking::Client {
	class GameController:public Controller, public Singleton<GameController>
	{
	public:
		Code Run() override;
		void Restore();
	private:
		GameController();

		GameModel& m_Model;
		GameRender& m_Render;

		NetworkManager& m_NetworkManager;

		bool m_IsEnd;
		bool m_MyTurn;

		friend class Singleton<GameController>;
	};
}
