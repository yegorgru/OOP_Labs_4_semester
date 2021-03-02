#pragma once

#include "LogRender.h"
#include "EnumCode.h"
#include "NetworkManager.h"
#include "Player.h"

namespace Docking::Client {
	class LogController
	{
	public:
		LogController(LogRender& render, NetworkManager& network);
		Code Run(Player& player);
	private:
		LogRender& m_Render;
		NetworkManager& m_NetworkManager;

	};
}

