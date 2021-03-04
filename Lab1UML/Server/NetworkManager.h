#pragma once

#include <iostream>

#include <SFML/Network.hpp>

#include "Singleton.h"

namespace Docking::Server {
    template <typename Id>
    class NetworkManager : public Singleton<NetworkManager<Id>> {
    public:
        bool IsReady(Id id);
        void ConnectPlayer(Id id, sf::TcpSocket& socket);
        void Send(sf::Packet& packet);
        void Send(sf::Packet& packet, Id id);
        bool Receive(Id id, sf::Packet& packet);
    private:
        explicit NetworkManager(sf::SocketSelector& selector);

        virtual ~NetworkManager() noexcept = default;

        sf::SocketSelector& m_Selector;
        std::unordered_map<Id, sf::TcpSocket*>m_Sockets;

        friend Singleton<NetworkManager<Id>>;
    };

    template <typename PlayerId>
    NetworkManager<PlayerId>::NetworkManager(sf::SocketSelector& selector) :
        m_Selector(selector)
    {}

    template <typename Id>
    bool NetworkManager<Id>::IsReady(Id id) {
        return m_Selector.isReady(*m_Sockets[id]);
    }

    template<typename Id>
    void NetworkManager<Id>::ConnectPlayer(Id id, sf::TcpSocket& socket) {
        m_Sockets[id] = &socket;
    }

    template<typename Id>
    void NetworkManager<Id>::Send(sf::Packet& packet) {
        for (auto& socketNode : m_Sockets) {
            if (socketNode.second->send(packet) != sf::Socket::Done) {
                std::cout << "Failed to send data to socket #{0}" << std::endl;
            }
        }
    }

    template<typename Id>
    void NetworkManager<Id>::Send(sf::Packet& packet, Id id) {
        if (m_Sockets[id]->send(packet) != sf::Socket::Done) {
            std::cout << "Failed to send packet" << std::endl;
        }
    }

    template<typename Id>
    bool NetworkManager<Id>::Receive(Id id, sf::Packet& packet) {
        if (m_Sockets[id]->receive(packet) == sf::Socket::Done) {
            return true;
        }
        return false;
    }
}