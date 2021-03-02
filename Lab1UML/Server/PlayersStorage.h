#pragma once

#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <set>
#include <utility>

#include "Player.h"

namespace Docking::Server {
    class PlayersStorage
    {
    public:
        PlayersStorage();
        int GetWins(const std::string& name);
        std::vector<std::pair<int, std::string>> GetLeaders();
        bool LogIn(const std::string& name, const std::string& password);
        bool LogUp(const std::string& name, const std::string& password);
        void LogOut(const std::string& name);
        void Win(const std::string name);
    private:
        void BackUp();

        std::unordered_map<std::string, std::string> m_PlayersPasswords;
        std::unordered_map<std::string, int>m_PlayersWins;
        std::multimap<int, std::string>m_WinsPlayers;
        std::set<std::string>m_OnlinePlayers;
    };
}
