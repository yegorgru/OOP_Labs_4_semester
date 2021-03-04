#pragma once

#include "SignRender.h"
#include "EnumCode.h"
#include "NetworkManager.h"
#include "Player.h"
#include "Controller.h"
#include "Singleton.h"

namespace Docking::Client {
	class SignController:public Controller, public Singleton<SignController>
	{
	public:
		Code Run() override;
		Code Run(Player& player);
	private:
		SignController();
		SignRender& m_Render;
		NetworkManager& m_NetworkManager;

		friend class Singleton<SignController>;
	};
}

