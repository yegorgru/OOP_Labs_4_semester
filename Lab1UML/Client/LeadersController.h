#pragma once

#include "LeadersRender.h"
#include "NetworkManager.h"
#include "EnumCode.h"

namespace Docking::Client {
	class LeadersController
	{
	public:
		LeadersController(LeadersRender& render, NetworkManager& network);
		Code Run();
	private:
		LeadersRender& m_Render;
		NetworkManager& m_NetworkManager;
	};
}
