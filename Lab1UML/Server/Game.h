#pragma once

#include <array>
#include <unordered_map>
#include <set>

#include "NetworkManager.h"
#include "Player.h"

namespace Docking::Server {

    class Game {
    public:
        struct Position {
            int x;
            int y;
        };

        enum class ClientCode : int {
            ClosedGame = 0,
            Position,
            Up,
            Down,
            Left,
            Right
        };

        enum class ServerCode : int {
            StartGame = 0,
            EndGame,
            SetPosition,
        };

        Game(sf::SocketSelector& selector);

        virtual ~Game() noexcept;

        void ConnectPlayer(sf::TcpSocket& socket);
        void RunNetwork();

        bool CurrentPlayer() const;

        int GetElement(int x, int y) const;

        void SetPosition(int x, int y);

        int GetWinner() const;

        Position GetPosition() const;

        void NextTurn();

        bool MakeMove(int direction);

        bool IsEnd();
        
        bool IsActive() const;

        bool IsCompleted() const;

        void StartGame();

        void EndGame(int winner);
    private:

        void CheckElements(Position pos, int el, std::set<std::pair<int, int>>& elements);

        bool CheckClosed(Position pos);

        bool IsCorrectMove(int direction);

        std::vector<Player> m_Players;
        int m_CurrentPlayer;
        int m_Winner;

        std::array<std::array<int, 8>, 8> m_Map;
        Position m_Position;

        NetworkManager<int> m_NetworkManager;
    };
}