#pragma once

#include <SFML/Graphics.hpp>

#include "Render.h"
#include "Singleton.h"

namespace Docking::Client {
	class MenuRender:public Render, public Singleton<MenuRender>
	{
	public:
		sf::RenderWindow& Window() override;
		void Draw() override;
	private:
		MenuRender(sf::RenderWindow& window);

		sf::RenderWindow& m_Window;
		sf::RectangleShape m_Rectangle;

		sf::Text m_TextPlay;
		sf::Text m_TextLeaders;
		sf::Text m_TextExit;

		friend  Singleton<MenuRender>;
	};
}
