#pragma once

#include <SFML/Graphics.hpp>

namespace Docking::Client {
	class Render {
	public:
		virtual void Draw()=0;
		virtual sf::RenderWindow& Window()=0;
	};
}