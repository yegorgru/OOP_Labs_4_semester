#pragma once

#include <array>
#include <unordered_map>
#include <set>
#include <stdexcept>

#include "NetworkManager.h"
#include "Player.h"
#include "EnumCode.h"

namespace Docking::Server {
    class Game {
    public:
        struct Position {
            int x;
            int y;
        };

        Game();

        virtual ~Game() = default;

        void ConnectPlayer(Player& player);
        void RunNetwork(sf::Packet& received, ClientCode clientCode, int playerId);

        int CurrentPlayer() const;

        int GetElement(int x, int y) const;

        void SetPosition(int x, int y);

        void SetElement(int element, Position pos);

        int GetWinnerId() const;
        std::string GetWinnerName() const;

        Position GetPosition() const;

        void NextTurn();

        void MakeMove(int direction);

        bool IsEnd();
        bool CheckClosed(Position pos);
        
        bool IsActive() const;

        bool IsCompleted() const;

        void StartGame();

        void EndGame(int winner);

        int AnotherPlayerId(int id);

        void Clear();
    private:

        void CheckElements(Position pos, int el, std::set<std::pair<int, int>>& elements);

        bool IsCorrectMove(int direction);

        std::vector<Player*> m_Players;
        int m_CurrentPlayer;
        int m_Winner;

        std::array<std::array<int, 8>, 8> m_Map;
        Position m_Position;

        NetworkManager<int>& m_NetworkManager;

        std::unordered_map<int, int>m_IdElement;
        std::unordered_map<int, int>m_ElementId;
    };
}