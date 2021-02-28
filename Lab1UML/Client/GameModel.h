#pragma once

#include <set>
#include <utility>
#include <array>

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
	private:
		std::array<std::array<int, 8>, 8> m_Map;
		int m_Winner;
	};

	bool operator==(const GameModel::Position& left, const GameModel::Position& right);
}