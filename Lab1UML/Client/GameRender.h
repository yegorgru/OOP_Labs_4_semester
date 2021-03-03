#pragma once

#include <SFML/Graphics.hpp>

#include "GameModel.h"
#include "Render.h"
#include "Singleton.h"

namespace Docking::Client {
	class GameRender:public Render, public Singleton<GameRender>
	{
	public:
		sf::RenderWindow& Window() override;
		void Draw() override;

		int GetElementSize();

		void SetEndText(const std::string& text);

		void Restore();
	private:
		GameRender(sf::RenderWindow& window);

		GameModel& m_GameModel;

		sf::RenderWindow& m_Window;

		sf::RectangleShape m_Square;

		sf::Text m_TextPlayers;

		sf::Text m_TextEnd;
		sf::Text m_TextWaiting;
		int m_ElementSize;

		friend class Singleton<GameRender>;
	};
}
