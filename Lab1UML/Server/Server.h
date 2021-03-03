#pragma once

#include <string>
#include <unordered_map>
#include <map>

#include <SFML/Network.hpp>

#include "Game.h"
#include "Player.h"
#include "PlayersStorage.h"
#include "Singleton.h"

namespace Docking::Server {
    class Server : public Singleton<Server> {
    public:
        void Run();
    private:
        Server();
        virtual ~Server() noexcept = default;

        bool m_IsRunning;

        PlayersStorage m_PlayersStorage;
        std::unordered_map<int, Player>m_Players;
        std::unordered_map<int, Game>m_Games;
       
        size_t m_UncompletedGame;

        NetworkManager<int>& m_NetworkManager;

        unsigned short m_Port;
        sf::TcpListener m_Listener;
        sf::SocketSelector m_Selector;
        std::list<sf::TcpSocket> m_Sockets;
        int m_NextIdPlayer;

        friend Singleton<Server>;
    };
}