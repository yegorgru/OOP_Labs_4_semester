#include "Player.h"

namespace Docking::Server {
    Player::Player(int id) : m_Id(id) {}

    int Player::GetId() const {
        return m_Id;
    }
}