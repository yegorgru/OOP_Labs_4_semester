#pragma once

#include <string>
#include <unordered_map>

#include <SFML/Network.hpp>

#include "Game.h"

namespace Docking::Server {

    class Server {
    public:
        Server();
        virtual ~Server() noexcept = default;

        bool logUpPlayer(const std::string& name, const std::string& password);
        bool logInPlayer(const std::string& name, const std::string& password);
        void Run();
    private:
        bool m_IsRunning;

        std::unordered_map<std::string, std::string> m_PlayersStorage;
        std::vector<Game>m_Games;
        size_t m_UncompletedGame;

        //sf::IpAddress m_IpAdress;
        unsigned short m_Port;
        sf::TcpListener m_Listener;
        sf::SocketSelector m_Selector;
        std::list<sf::TcpSocket> m_Sockets;
    };
}