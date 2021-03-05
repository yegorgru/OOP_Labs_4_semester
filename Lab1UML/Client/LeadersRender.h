#pragma once

#include <SFML/Graphics.hpp>

#include <string>

#include "Player.h"
#include "Render.h"
#include "Singleton.h"

namespace Docking::Client {
	class LeadersRender : public Render, public Singleton<LeadersRender>
	{
	public:
		sf::RenderWindow& Window() override;
		void Draw() override;

		void Restore();

		void AddLetter(char letter);
		void EraseLetter();
		std::string GetName() const;
		void IncorrectName();

		void SetPlayer(const Player& player);
		void AddLeader(const Player& player);
	private:
		LeadersRender(sf::RenderWindow& window);

		sf::RenderWindow& m_Window;
		sf::RectangleShape m_RectangleName;
		sf::RectangleShape m_RectangleFind;

		sf::Text m_TextName;
		sf::Text m_TextFind;
		sf::Text m_TextWins;
		sf::Text m_TextWinsNumber;
		sf::Text m_TextLeaders;

		Player m_Player;

		friend class Singleton<LeadersRender>;
	};
}

