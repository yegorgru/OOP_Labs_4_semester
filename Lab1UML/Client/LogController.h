#pragma once

#include "LogRender.h"
#include "EnumCode.h"
#include "NetworkManager.h"
#include "Player.h"
#include "Controller.h"
#include "Singleton.h"

namespace Docking::Client {
	class LogController:public Controller, public Singleton<LogController>
	{
	public:
		Code Run() override;
		Code Run(Player& player);
	private:
		LogController();
		LogRender& m_Render;
		NetworkManager& m_NetworkManager;

		friend class Singleton<LogController>;
	};
}

