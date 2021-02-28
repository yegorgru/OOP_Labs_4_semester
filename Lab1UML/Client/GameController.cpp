#include "GameController.h"

#include <SFML/Network.hpp>

namespace Docking::Client {
	GameController::GameController(GameModel& gameModel, GameRender& render) :
		m_Model(gameModel),
		m_Render(render),
		m_NetworkManager("localhost", 45000),
		m_IsActive(false),
		m_MyTurn(false) {}

	Code GameController::Run()
	{
		sf::Event event;

		while (m_Render.Window().isOpen())
		{
			sf::Vector2i pos = sf::Mouse::getPosition(m_Render.Window());
			int x = pos.x / m_Render.get_element_size();
			int y = pos.y / m_Render.get_element_size();
			while (m_Render.Window().pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					sf::Packet closed;
					closed << static_cast<int>(ClientCode::ClosedGame);
					m_NetworkManager.Send(closed);
					return Code::Exit;
				}
				if (event.type == sf::Event::MouseButtonPressed) {
					if (event.key.code == sf::Mouse::Left) {
						sf::Packet position;
						position << static_cast<int>(ClientCode::Position) << x << y;
						m_NetworkManager.Send(position);
					}
				}
				if (event.type == sf::Event::KeyPressed)
				{
					sf::Packet move;
					if (event.key.code == sf::Keyboard::Left) {
						move << static_cast<int>(ClientCode::Left);
						m_NetworkManager.Send(move);

					}
					if (event.key.code == sf::Keyboard::Right) {
						move << static_cast<int>(ClientCode::Right);
						m_NetworkManager.Send(move);
					}
					if (event.key.code == sf::Keyboard::Up) {
						move << static_cast<int>(ClientCode::Up);
						m_NetworkManager.Send(move);
					}
					if (event.key.code == sf::Keyboard::Down) {
						move << static_cast<int>(ClientCode::Down);
						m_NetworkManager.Send(move);
					}
				}
			}
			sf::Packet received;
			if (m_NetworkManager.Receive(received)) {
				int code;
				received >> code;

				auto serverCode = static_cast<ServerCode>(code);
				switch (serverCode) {
				case ServerCode::StartGame: {
					int id;
					received >> id;
					m_Model.Restore();
					m_IsActive = true;
					std::cout << "Server started game" << std::endl;
					break;
				}
				case ServerCode::EndGame: {
					m_IsActive = false;
					int winner;
					received >> winner;
					m_Model.SetWinner(winner);
					break;
				}
				case ServerCode::SetPosition: {
					GameModel::Position newPos, oldPos;
					int el;
					received >> el >> newPos.x >> newPos.y >> oldPos.x >> oldPos.y;
					m_Model.SetElement(el, newPos, oldPos);
					break;
				}
				}
			}
			m_Render.draw();
		}
	}
}