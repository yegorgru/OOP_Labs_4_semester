#pragma once

namespace Docking::Server {
    class Player {
    public:
        Player(int id);

        virtual ~Player() noexcept = default;

        int GetId() const;
    private:
        int m_Id;
    };
}