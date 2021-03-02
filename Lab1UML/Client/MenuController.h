#pragma once
#include "MenuRender.h"
#include "EnumCode.h"
#include "NetworkManager.h"

namespace Docking::Client{
	class MenuController
	{
	public:
		MenuController(MenuRender& render, NetworkManager& network);
		Code Run();
	private:
		MenuRender& m_Render;
		NetworkManager& m_NetworkManager;
	};
}

