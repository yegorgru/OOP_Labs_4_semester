#pragma once
#include "MenuRender.h"
#include "EnumCode.h"

namespace Docking::Client{
	class MenuController
	{
	public:
		MenuController(MenuRender& render);
		Code Run();
	private:
		MenuRender& m_Render;
	};
}

