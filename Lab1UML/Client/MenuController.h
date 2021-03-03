#pragma once
#include "MenuRender.h"
#include "EnumCode.h"
#include "NetworkManager.h"
#include "Controller.h"
#include "Singleton.h"

namespace Docking::Client{
	class MenuController:public Controller, public Singleton<MenuController>
	{
	public:
		Code Run() override;
	private:
		MenuController();
		MenuRender& m_Render;
		NetworkManager& m_NetworkManager;

		friend Singleton<MenuController>;
	};
}

