#pragma once

namespace Docking::Server {
    enum class ClientCode : int {
        ClosedWindow = 0,
        ClosedGame,
        Position,
        Up,
        Down,
        Left,
        Right,
        Login,
        Logup,
        Game,
        FindPlayer,
        Leaders
    };

    enum class ServerCode : int {
        StartGame = 0,
        EndGame,
        SetPosition,
        Confirm,
        NotConfirm,
        Leaders
    };
}