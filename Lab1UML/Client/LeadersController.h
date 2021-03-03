#pragma once

#include "LeadersRender.h"
#include "NetworkManager.h"
#include "EnumCode.h"
#include "Controller.h"
#include "Singleton.h"

namespace Docking::Client {
	class LeadersController:public Controller, public Singleton<LeadersController>
	{
	public:
		Code Run() override;
	private:
		LeadersController();

		LeadersRender& m_Render;
		NetworkManager& m_NetworkManager;

		friend class Singleton<LeadersController>;
	};
}
