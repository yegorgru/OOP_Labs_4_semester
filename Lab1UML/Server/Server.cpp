#include "Server.h"

namespace Docking::Server {

    Server::Server() {
        //на будущее. загрузка данных про игроков(логин пароль) с файла?

        m_IsRunning = false;

        m_Port = 45000;
        m_Listener.listen(m_Port);
        m_Selector.add(m_Listener);

        m_Games.reserve(20000);
        m_Games.emplace_back(m_Selector);
        m_UncompletedGame = 0;
    }

    bool Server::logUpPlayer(const std::string& name, const std::string& password) {
        if (m_PlayersStorage.find(name) == m_PlayersStorage.end()) {
            m_PlayersStorage[name] = password;
            return true;
        }
        return false;
    }

    bool Server::logInPlayer(const std::string& name, const std::string& password) {
        auto it = m_PlayersStorage.find(name);
        if (it != m_PlayersStorage.end() && it->second == password) {
            return true;
        }

        return false;
    }

    void Server::Run() {
        m_IsRunning = true;

        while (m_IsRunning) {
            if (!m_Selector.wait())
                continue;

            if (m_Selector.isReady(m_Listener)) {
                m_Sockets.emplace_back();
                if (m_Listener.accept(m_Sockets.back()) == sf::Socket::Done) {
                    m_Games[m_UncompletedGame].ConnectPlayer(m_Sockets.back());
                    m_Selector.add(m_Sockets.back());
                    if (m_Games[m_UncompletedGame].IsCompleted()) {
                        m_Games[m_UncompletedGame].StartGame();
                        m_Games.emplace_back(m_Selector);
                        m_UncompletedGame++;
                    }
                }
            }
            else
            {
                for (auto& game : m_Games)
                {
                    game.RunNetwork();
                }
            }
        }
    }
}