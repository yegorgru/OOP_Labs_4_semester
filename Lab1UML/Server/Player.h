#pragma once

#include <list>

#include <SFML/Network.hpp>

namespace Docking::Server {
    class Player {
    public:
        Player(int id, sf::TcpSocket& socket);

        virtual ~Player() noexcept = default;

        int GetId() const;

        int GetGame() const;

        void SetGame(int game);
        std::string GetName() const;
        void SetName(const std::string& name);
        void SetWins(int wins);
        int GetWins() const;
    private:
        int m_Id;
        sf::TcpSocket& m_Socket;
        int m_Game;
        std::string m_Name;
        int m_Wins;
    };
}