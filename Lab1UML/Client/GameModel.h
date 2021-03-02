#pragma once

#include <set>
#include <utility>
#include <array>
#include <vector>

#include "Player.h"

namespace Docking::Client {
	class GameModel
	{
	public:
		struct Position {
			int x;
			int y;
		};

		GameModel();

		void Restore();

		void SetElement(int element, Position newPos, Position oldPos = {-1,-1});
		void SetWinner(int winner);

		int GetElement(Position pos);
		int GetWinner();

		void AddPlayer(const Player& player);
		std::vector<Player>& GetPlayers();
	private:
		std::array<std::array<int, 8>, 8> m_Map;
		int m_Winner;
		std::vector<Player>m_Players;
	};

	bool operator==(const GameModel::Position& left, const GameModel::Position& right);
}