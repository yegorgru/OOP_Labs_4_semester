#pragma once

#include <SFML/Network.hpp>
#include <iostream>

namespace Docking::Client {
    class NetworkManager {
    public:
        NetworkManager(const sf::IpAddress& ip, unsigned port);
        ~NetworkManager() = default;

        void SetBlocking(bool value);
        bool Receive(sf::Packet& packet);
        void Send(sf::Packet& packet);
    private:
        sf::TcpSocket m_Connection;
    };
}
