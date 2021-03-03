#pragma once

#include <string>

namespace Docking::Client {
	class Player
	{
	public:
		Player();
		Player(const std::string& name, int wins);
		std::string GetName() const;
		void SetName(const std::string& name);
		void SetWins(int wins);
		int GetWins() const;
	private:
		std::string m_Name;
		int m_Wins;
	};
}

