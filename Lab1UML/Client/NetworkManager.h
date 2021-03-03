#pragma once

#include <SFML/Network.hpp>
#include <iostream>

#include "Singleton.h"

namespace Docking::Client {
    class NetworkManager : public Singleton<NetworkManager> {
    public:
        void SetBlocking(bool value);
        bool Receive(sf::Packet& packet);
        void Send(sf::Packet& packet);
    private:
        NetworkManager(const sf::IpAddress& ip, unsigned port);
        sf::TcpSocket m_Connection;
        
        friend class Singleton<NetworkManager>;
    };
}
