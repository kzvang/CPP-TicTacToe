#pragma once

#include <iostream>
#include "Game.h"

class TicTacToe : public Game
{
public :
	char m_board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
		int m_Player=0;



		virtual bool IsGameOver() const {
			if (m_board[0] == m_board[1] && m_board[1] == m_board[2] && m_board[0] != ' ') {
				return true;
			}
			else if (m_board[3] == m_board[4] && m_board[4] == m_board[5] && m_board[3] != ' ') {
				return true;
			}
			else if (m_board[6] == m_board[7] && m_board[7] == m_board[8] && m_board[6] != ' ') {
				return true;
			}
			else if (m_board[0] == m_board[3] && m_board[3] == m_board[6] && m_board[0] != ' ') {
				return true;
			}
			else if (m_board[1] == m_board[4] && m_board[4] == m_board[7] && m_board[1] != ' ') {
				return true;
			}
			else if (m_board[2] == m_board[5] && m_board[5] == m_board[8] && m_board[2] != ' ') {
				return true;
			}
			else if (m_board[0] == m_board[4] && m_board[4] == m_board[8] && m_board[0] != ' ') {
				return true;
			}
			else if (m_board[2] == m_board[4] && m_board[4] == m_board[6] && m_board[2] != ' ') {
				return true;
			}
			else if (m_board[0] != ' ' &&
					 m_board[1] != ' ' && 
					 m_board[2] != ' ' &&
					 m_board[0] != ' ' &&
					 m_board[3] != ' ' && 
					 m_board[4] != ' ' && 
					 m_board[5] != ' ' && 
					 m_board[6] != ' ' && 
					 m_board[7] != ' ' && 
					 m_board[8] != ' ')
			{
				std::cout << "It's a tie!" << std::endl;
				return true;
			
			}
			else {
				return false;
			}
		}
		virtual void TakeTurn() {
			if (m_Player == 0) {
				int input;
				std::cout << "Player 1, enter a number (1-9): ";
				std::cin >> input;
				if (input < 1 || input > 9 || (m_board[input - 1] != ' ' && m_board[input - 1] != 0)) {
					std::cout << "Invalid input. Try again." << std::endl;
					return;
				}
				m_board[input - 1] = 'X';
				m_Player = 1;
			}
			else {
				int input;
				std::cout << "Player 2, enter a number (1-9): ";
				std::cin >> input;
				if (input < 1 || input > 9 || (m_board[input - 1] != ' ' && m_board[input - 1] != 0)) {
					std::cout << "Invalid input. Try again." << std::endl;
					return;
				}
				m_board[input - 1] = 'O';
				m_Player = 0;
			}
		}
		virtual void Display() const;
};