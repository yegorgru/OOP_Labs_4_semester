#pragma once

#include <string>
#include <unordered_map>
#include <map>

#include <SFML/Network.hpp>

#include "Game.h"
#include "Player.h"

namespace Docking::Server {
    class Server {
    public:
        Server();
        virtual ~Server() noexcept = default;

        bool logUpPlayer(const std::string& name, const std::string& password);
        bool logInPlayer(const std::string& name, const std::string& password);
        void FormLeaders(sf::Packet& packet);
        void Run();
    private:
        bool m_IsRunning;

        std::unordered_map<std::string, std::string> m_PlayersStorage;
        std::unordered_map<std::string, int>m_PlayersWins;
        std::unordered_map<int, Player>m_Players;
        std::multimap<int, std::string>m_WinsPlayers;
        std::unordered_map<int, Game>m_Games;
       
        size_t m_UncompletedGame;

        NetworkManager<int> m_NetworkManager;

        unsigned short m_Port;
        sf::TcpListener m_Listener;
        sf::SocketSelector m_Selector;
        std::list<sf::TcpSocket> m_Sockets;
        int m_NextIdPlayer;
    };
}