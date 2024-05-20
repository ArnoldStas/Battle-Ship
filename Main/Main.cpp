#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <ctype.h>
#include <sstream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace chrono;

#define RESET "\033[0m" //Reset to DEFAULT color
#define RED "\033[31m" //RED color
#define GREEN "\033[32m" //GREEN color
#define YELLOW "\033[33m" //YELLOW color
#define BLUE "\033[34m" //BLUE color
#define MAGENTA "\033[35m" //MAGENTA color
#define CYAN "\033[36m" //CYAN color
#define WHITE "\033[37m" //WHITE color
#define GREY "\033[38;5;8m" //GREY color
#define BROWN "\033[38;5;130m" //BROWN color
#define ORANGE "\033[38;5;208m" //ORANGE color

class BASE_S_M_Player
{
private:
	bool exitGameBoardMenu, S, M;
	int GameBoardSelectedOption;
	char keyGameBoardPressed;
protected:
	vector <vector<char>> SPlayerBoard;
	vector <vector<char>> SPlayerBoard_second;
	const int GameBoardSize, GameBoardSize_Horizontal, GameBoardSize_Vertical;
	int X, Y;
public:
	BASE_S_M_Player() : exitGameBoardMenu(0), GameBoardSelectedOption(0), keyGameBoardPressed(' '), S(0), M(0), SPlayerBoard(10, vector<char>(10)), SPlayerBoard_second(10, vector<char>(10)), GameBoardSize(10), GameBoardSize_Horizontal(10), GameBoardSize_Vertical(10), X(0), Y(0) {}
	BASE_S_M_Player(bool x, int y, char z) : exitGameBoardMenu(x), GameBoardSelectedOption(y), keyGameBoardPressed(z), S(0), M(0), SPlayerBoard(10, vector<char>(10)), SPlayerBoard_second(10, vector<char>(10)), GameBoardSize(10), GameBoardSize_Horizontal(10), GameBoardSize_Vertical(10), X(0), Y(0) {}
	~BASE_S_M_Player() {}

	void ClearScreen()
	{
		HANDLE hOut;
		COORD Position;

		hOut = GetStdHandle(STD_OUTPUT_HANDLE);

		Position.X = 0;
		Position.Y = 0;
		SetConsoleCursorPosition(hOut, Position);
	}

	void ClearScreen_the_whole()
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		DWORD count;
		COORD homeCoords = { 0, 0 };

		if (hOut == INVALID_HANDLE_VALUE) return;

		if (!GetConsoleScreenBufferInfo(hOut, &csbi)) return;

		DWORD cellCount = csbi.dwSize.X * csbi.dwSize.Y;

		FillConsoleOutputCharacter(hOut, ' ', cellCount, homeCoords, &count);

		FillConsoleOutputAttribute(hOut, csbi.wAttributes, cellCount, homeCoords, &count);
		SetConsoleCursorPosition(hOut, homeCoords);
	}

	void ShowConsoleCursor(bool showFlag)
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_CURSOR_INFO     cursorInfo;

		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = showFlag; // set the cursor visibility
		SetConsoleCursorInfo(out, &cursorInfo);
	}

	void drawGameBoard_DESIGN()
	{
		ClearScreen();

		cout << "     SinglePlayer (A)";
		cout << "                        ";
		cout << "Artificial Intelligence (A & B)";
		cout << endl << endl;
		cout << GREY << "       Player |A|:                      " << "Player |A|:                AI Player |B|:" << RESET << endl << endl;

		//1 KETURVIETIS LAIVAS
		//2 TRIVIECIAI LAIVAI
		//3 DVIVIECIAI LAIVAI
		//4 VIENVIECIAI LAIVAI

		cout << "  *********************";
		cout << "          ";
		cout << "  *********************";
		cout << "     ";
		cout << "  *********************" << endl;

		cout << "* " << ORANGE << "x" << RESET << YELLOW << " A B C D E F G H I J" << RESET << " * ";
		cout << "       ";
		cout << "* " << ORANGE << "x" << RESET << YELLOW << " A B C D E F G H I J" << RESET << " * ";
		cout << "  ";
		cout << "* " << ORANGE << "x" << RESET << YELLOW << " A B C D E F G H I J" << RESET << " * " << endl;

		cout << "* " << YELLOW << "0" << RESET << BROWN << " S" << BLUE << " # # # " << BROWN << "S S" << BLUE << " # # # #" << RESET << " * ";
		cout << "       ";
		cout << "* " << YELLOW << "0" << RESET << BROWN << " S" << BLUE << " # # # " << BROWN << "S S" << BLUE << " # # # #" << RESET << " * ";
		cout << "  ";
		cout << "* " << YELLOW << "0" << RESET << BROWN << " S" << BLUE << " # # # " << BROWN << "S S" << BLUE << " # # # #" << RESET << " * " << endl;

		cout << "* " << YELLOW << "1" << RESET << BLUE << " # # # # # # # " << BROWN << "S" << BLUE << " # #" << RESET << " * ";
		cout << "       ";
		cout << "* " << YELLOW << "1" << RESET << BLUE << " # # # # # # # " << BROWN << "S" << BLUE << " # #" << RESET << " * ";
		cout << "  ";
		cout << "* " << YELLOW << "1" << RESET << BLUE << " # # # # # # # " << BROWN << "S" << BLUE << " # #" << RESET << " * " << endl;

		cout << "* " << YELLOW << "2" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # # # # #" << RESET << " * ";
		cout << "       ";
		cout << "* " << YELLOW << "2" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # # # # #" << RESET << " * ";
		cout << "  ";
		cout << "* " << YELLOW << "2" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # # # # #" << RESET << " * " << endl;

		cout << "* " << YELLOW << "3" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # " << BROWN << "S S S" << BLUE << " #" << RESET << " * ";
		cout << "       ";
		cout << "* " << YELLOW << "3" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # " << BROWN << "S S S" << BLUE << " #" << RESET << " * ";
		cout << "  ";
		cout << "* " << YELLOW << "3" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # " << BROWN << "S S S" << BLUE << " #" << RESET << " * " << endl;

		cout << "* " << YELLOW << "4" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # # # # #" << RESET << " * ";
		cout << "       ";
		cout << "* " << YELLOW << "4" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # # # # #" << RESET << " * ";
		cout << "  ";
		cout << "* " << YELLOW << "4" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # # # # #" << RESET << " * " << endl;

		cout << "* " << YELLOW << "5" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # " << BROWN << "S" << BLUE << " # # # #" << RESET << " * ";
		cout << "       ";
		cout << "* " << YELLOW << "5" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # " << BROWN << "S" << BLUE << " # # # #" << RESET << " * ";
		cout << "  ";
		cout << "* " << YELLOW << "5" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # " << BROWN << "S" << BLUE << " # # # #" << RESET << " * " << endl;

		cout << "* " << YELLOW << "6" << RESET << BLUE << " # " << BROWN << "S" << BLUE << " # # # # # # # #" << RESET << " * ";
		cout << "       ";
		cout << "* " << YELLOW << "6" << RESET << BLUE << " # " << BROWN << "S" << BLUE << " # # # # # # # #" << RESET << " * ";
		cout << "  ";
		cout << "* " << YELLOW << "6" << RESET << BLUE << " # " << BROWN << "S" << BLUE << " # # # # # # # #" << RESET << " * " << endl;

		cout << "* " << YELLOW << "7" << RESET << BLUE << " # # # " << BROWN << "S S S" << BLUE << " # # " << BROWN << "S" << BLUE << " #" << RESET << " * ";
		cout << "       ";
		cout << "* " << YELLOW << "7" << RESET << BLUE << " # # # " << BROWN << "S S S" << BLUE << " # # " << BROWN << "S" << BLUE << " #" << RESET << " * ";
		cout << "  ";
		cout << "* " << YELLOW << "7" << RESET << BLUE << " # # # " << BROWN << "S S S" << BLUE << " # # " << BROWN << "S" << BLUE << " #" << RESET << " * " << endl;

		cout << "* " << YELLOW << "8" << RESET << BLUE << " # # # # # # # # " << BROWN << "S" << BLUE << " #" << RESET << " * ";
		cout << "       ";
		cout << "* " << YELLOW << "8" << RESET << BLUE << " # # # # # # # # " << BROWN << "S" << BLUE << " #" << RESET << " * ";
		cout << "  ";
		cout << "* " << YELLOW << "8" << RESET << BLUE << " # # # # # # # # " << BROWN << "S" << BLUE << " #" << RESET << " * " << endl;

		cout << "* " << YELLOW << "9" << RESET << BROWN << " S S" << BLUE << " # # # # # # # #" << RESET << " * ";
		cout << "       ";
		cout << "* " << YELLOW << "9" << RESET << BROWN << " S S" << BLUE << " # # # # # # # #" << RESET << " * ";
		cout << "  ";
		cout << "* " << YELLOW << "9" << RESET << BROWN << " S S" << BLUE << " # # # # # # # #" << RESET << " * " << endl;

		cout << "  *********************";
		cout << "          ";
		cout << "  *********************";
		cout << "     ";
		cout << "  *********************" << endl;
	}

	void drawGameBoard_CURSOR()
	{
		while (!exitGameBoardMenu)
		{
			ShowConsoleCursor(false);
			ClearScreen();

			drawGameBoard_DESIGN();

			if (GameBoardSelectedOption == 0)
			{
				ClearScreen();

				cout << RED << "     SinglePlayer (A)" << RESET;
				cout << "                        ";
				cout << "Artificial Intelligence (A & B)";
				cout << endl << endl;
				cout << GREY << "       Player |A|:                      " << "Player |A|:                AI Player |B|:" << RESET << endl << endl;

				cout << RED << "  *********************" << RESET;
				cout << "          ";
				cout << "  *********************";
				cout << "     ";
				cout << "  *********************" << endl;

				cout << RED << "* " << ORANGE << "x" << RESET << YELLOW << " A B C D E F G H I J" << RED << " * " << RESET;
				cout << "       ";
				cout << "* " << ORANGE << "x" << RESET << YELLOW << " A B C D E F G H I J" << RESET << " * ";
				cout << "  ";
				cout << "* " << ORANGE << "x" << RESET << YELLOW << " A B C D E F G H I J" << RESET << " * " << endl;

				cout << RED << "* " << YELLOW << "0" << RESET << BROWN << " S" << BLUE << " # # # " << BROWN << "S S" << BLUE << " # # # #" << RED << " * " << RESET;
				cout << "       ";
				cout << "* " << YELLOW << "0" << RESET << BROWN << " S" << BLUE << " # # # " << BROWN << "S S" << BLUE << " # # # #" << RESET << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "0" << RESET << BROWN << " S" << BLUE << " # # # " << BROWN << "S S" << BLUE << " # # # #" << RESET << " * " << endl;

				cout << RED << "* " << YELLOW << "1" << RESET << BLUE << " # # # # # # # " << BROWN << "S" << BLUE << " # #" << RED << " * " << RESET;
				cout << "       ";
				cout << "* " << YELLOW << "1" << RESET << BLUE << " # # # # # # # " << BROWN << "S" << BLUE << " # #" << RESET << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "1" << RESET << BLUE << " # # # # # # # " << BROWN << "S" << BLUE << " # #" << RESET << " * " << endl;

				cout << RED << "* " << YELLOW << "2" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # # # # #" << RED << " * " << RESET;
				cout << "       ";
				cout << "* " << YELLOW << "2" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # # # # #" << RESET << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "2" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # # # # #" << RESET << " * " << endl;

				cout << RED << "* " << YELLOW << "3" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # " << BROWN << "S S S" << BLUE << " #" << RED << " * " << RESET;
				cout << "       ";
				cout << "* " << YELLOW << "3" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # " << BROWN << "S S S" << BLUE << " #" << RESET << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "3" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # " << BROWN << "S S S" << BLUE << " #" << RESET << " * " << endl;

				cout << RED << "* " << YELLOW << "4" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # # # # #" << RED << " * " << RESET;
				cout << "       ";
				cout << "* " << YELLOW << "4" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # # # # #" << RESET << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "4" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # # # # #" << RESET << " * " << endl;

				cout << RED << "* " << YELLOW << "5" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # " << BROWN << "S" << BLUE << " # # # #" << RED << " * " << RESET;
				cout << "       ";
				cout << "* " << YELLOW << "5" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # " << BROWN << "S" << BLUE << " # # # #" << RESET << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "5" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # " << BROWN << "S" << BLUE << " # # # #" << RESET << " * " << endl;

				cout << RED << "* " << YELLOW << "6" << RESET << BLUE << " # " << BROWN << "S" << BLUE << " # # # # # # # #" << RED << " * " << RESET;
				cout << "       ";
				cout << "* " << YELLOW << "6" << RESET << BLUE << " # " << BROWN << "S" << BLUE << " # # # # # # # #" << RESET << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "6" << RESET << BLUE << " # " << BROWN << "S" << BLUE << " # # # # # # # #" << RESET << " * " << endl;

				cout << RED << "* " << YELLOW << "7" << RESET << BLUE << " # # # " << BROWN << "S S S" << BLUE << " # # " << BROWN << "S" << BLUE << " #" << RED << " * " << RESET;
				cout << "       ";
				cout << "* " << YELLOW << "7" << RESET << BLUE << " # # # " << BROWN << "S S S" << BLUE << " # # " << BROWN << "S" << BLUE << " #" << RESET << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "7" << RESET << BLUE << " # # # " << BROWN << "S S S" << BLUE << " # # " << BROWN << "S" << BLUE << " #" << RESET << " * " << endl;

				cout << RED << "* " << YELLOW << "8" << RESET << BLUE << " # # # # # # # # " << BROWN << "S" << BLUE << " #" << RED << " * " << RESET;
				cout << "       ";
				cout << "* " << YELLOW << "8" << RESET << BLUE << " # # # # # # # # " << BROWN << "S" << BLUE << " #" << RESET << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "8" << RESET << BLUE << " # # # # # # # # " << BROWN << "S" << BLUE << " #" << RESET << " * " << endl;

				cout << RED << "* " << YELLOW << "9" << RESET << BROWN << " S S" << BLUE << " # # # # # # # #" << RED << " * " << RESET;
				cout << "       ";
				cout << "* " << YELLOW << "9" << RESET << BROWN << " S S" << BLUE << " # # # # # # # #" << RESET << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "9" << RESET << BROWN << " S S" << BLUE << " # # # # # # # #" << RESET << " * " << endl;

				cout << RED << "  *********************" << RESET;
				cout << "          ";
				cout << "  *********************";
				cout << "     ";
				cout << "  *********************" << endl;
			}

			if (GameBoardSelectedOption == 1)
			{
				ClearScreen();

				cout << "     SinglePlayer (A)";
				cout << "                        ";
				cout << RED << "Artificial Intelligence (A & B)" << RESET;
				cout << endl << endl;
				cout << GREY << "       Player |A|:                      " << "Player |A|:                AI Player |B|:" << RESET << endl << endl;

				cout << "  *********************";
				cout << "          ";
				cout << RED << "  *********************";
				cout << "     ";
				cout << "  *********************" << RESET << endl;

				cout << "* " << ORANGE << "x" << RESET << YELLOW << " A B C D E F G H I J" << RESET << " * ";
				cout << "       ";
				cout << RED << "* " << ORANGE << "x" << RESET << YELLOW << " A B C D E F G H I J" << RED << " * ";
				cout << "  ";
				cout << "* " << ORANGE << "x" << RESET << YELLOW << " A B C D E F G H I J" << RED << " * " << RESET << endl;

				cout << "* " << YELLOW << "0" << RESET << BROWN << " S" << BLUE << " # # # " << BROWN << "S S" << BLUE << " # # # #" << RESET << " * ";
				cout << "       ";
				cout << RED << "* " << YELLOW << "0" << RESET << BROWN << " S" << BLUE << " # # # " << BROWN << "S S" << BLUE << " # # # #" << RED << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "0" << RESET << BROWN << " S" << BLUE << " # # # " << BROWN << "S S" << BLUE << " # # # #" << RED << " * " << RESET << endl;

				cout << "* " << YELLOW << "1" << RESET << BLUE << " # # # # # # # " << BROWN << "S" << BLUE << " # #" << RESET << " * ";
				cout << "       ";
				cout << RED << "* " << YELLOW << "1" << RESET << BLUE << " # # # # # # # " << BROWN << "S" << BLUE << " # #" << RED << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "1" << RESET << BLUE << " # # # # # # # " << BROWN << "S" << BLUE << " # #" << RED << " * " << RESET << endl;

				cout << "* " << YELLOW << "2" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # # # # #" << RESET << " * ";
				cout << "       ";
				cout << RED << "* " << YELLOW << "2" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # # # # #" << RED << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "2" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # # # # #" << RED << " * " << RESET << endl;

				cout << "* " << YELLOW << "3" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # " << BROWN << "S S S" << BLUE << " #" << RESET << " * ";
				cout << "       ";
				cout << RED << "* " << YELLOW << "3" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # " << BROWN << "S S S" << BLUE << " #" << RED << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "3" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # " << BROWN << "S S S" << BLUE << " #" << RED << " * " << RESET << endl;

				cout << "* " << YELLOW << "4" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # # # # #" << RESET << " * ";
				cout << "       ";
				cout << RED << "* " << YELLOW << "4" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # # # # #" << RED << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "4" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # # # # # #" << RED << " * " << RESET << endl;

				cout << "* " << YELLOW << "5" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # " << BROWN << "S" << BLUE << " # # # #" << RESET << " * ";
				cout << "       ";
				cout << RED << "* " << YELLOW << "5" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # " << BROWN << "S" << BLUE << " # # # #" << RED << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "5" << RESET << BLUE << " # # " << BROWN << "S" << BLUE << " # # " << BROWN << "S" << BLUE << " # # # #" << RED << " * " << RESET << endl;

				cout << "* " << YELLOW << "6" << RESET << BLUE << " # " << BROWN << "S" << BLUE << " # # # # # # # #" << RESET << " * ";
				cout << "       ";
				cout << RED << "* " << YELLOW << "6" << RESET << BLUE << " # " << BROWN << "S" << BLUE << " # # # # # # # #" << RED << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "6" << RESET << BLUE << " # " << BROWN << "S" << BLUE << " # # # # # # # #" << RED << " * " << RESET << endl;

				cout << "* " << YELLOW << "7" << RESET << BLUE << " # # # " << BROWN << "S S S" << BLUE << " # # " << BROWN << "S" << BLUE << " #" << RESET << " * ";
				cout << "       ";
				cout << RED << "* " << YELLOW << "7" << RESET << BLUE << " # # # " << BROWN << "S S S" << BLUE << " # # " << BROWN << "S" << BLUE << " #" << RED << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "7" << RESET << BLUE << " # # # " << BROWN << "S S S" << BLUE << " # # " << BROWN << "S" << BLUE << " #" << RED << " * " << RESET << endl;

				cout << "* " << YELLOW << "8" << RESET << BLUE << " # # # # # # # # " << BROWN << "S" << BLUE << " #" << RESET << " * ";
				cout << "       ";
				cout << RED << "* " << YELLOW << "8" << RESET << BLUE << " # # # # # # # # " << BROWN << "S" << BLUE << " #" << RED << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "8" << RESET << BLUE << " # # # # # # # # " << BROWN << "S" << BLUE << " #" << RED << " * " << RESET << endl;

				cout << "* " << YELLOW << "9" << RESET << BROWN << " S S" << BLUE << " # # # # # # # #" << RESET << " * ";
				cout << "       ";
				cout << RED << "* " << YELLOW << "9" << RESET << BROWN << " S S" << BLUE << " # # # # # # # #" << RED << " * ";
				cout << "  ";
				cout << "* " << YELLOW << "9" << RESET << BROWN << " S S" << BLUE << " # # # # # # # #" << RED << " * " << RESET << endl;

				cout << "  *********************";
				cout << "          ";
				cout << RED << "  *********************";
				cout << "     ";
				cout << "  *********************" << RESET << endl;
			}

			cout << endl;
			cout << BLUE << "SELECTED OPTION (GAMEBOARD MENU): " << RESET << GameBoardSelectedOption + 1 << endl << endl;

			while (true)
			{
				if (_kbhit())
				{
					keyGameBoardPressed = _getch();
					switch (keyGameBoardPressed)
					{
					case 77: //Move right
						if (GameBoardSelectedOption == 0) {
							GameBoardSelectedOption++;
						}
						else if (GameBoardSelectedOption == 1) {
							GameBoardSelectedOption--;
						}
						break;
					case 75: //Move left
						if (GameBoardSelectedOption == 1) {
							GameBoardSelectedOption--;
						}
						else if (GameBoardSelectedOption == 0) {
							GameBoardSelectedOption++;
						}
						break;
					}
					break;
				}
			}

			if (GetAsyncKeyState(VK_RETURN))
			{
				switch (GameBoardSelectedOption)
				{
				case 0:
					S = 1;
					break;
				case 1:
					M = 1;
					break;
				}
				exitGameBoardMenu = true;
			}
		}
	}

	bool retr_S()
	{
		return S;
	}

	bool retr_M()
	{
		return M;
	}

};

class SinglePlayerC : public BASE_S_M_Player
{
private:
	string S_name;
	bool test_1, test_2, test_3, test_4, validInput, validas, klaida_used;
	int test_count, selectedTest;
	char letter;
	int number, letter_number;
	int S_P_score, ships_count;
	string letter_to_str, number_to_str, letter_number_str, ltr_str, nmb_ltr_str;
public:
	SinglePlayerC() : S_name(" "), test_1(false), test_2(false), test_3(false), test_4(false), test_count(0), selectedTest(0), letter(' '), number(0), validInput(false), letter_number(0), validas(false), S_P_score(0), ships_count(20), letter_to_str(" "), number_to_str(" "), letter_number_str(" "), klaida_used(0), ltr_str(" "), nmb_ltr_str(" ") {}
	SinglePlayerC(string x) : S_name(x), test_1(false), test_2(false), test_3(false), test_4(false), test_count(0), selectedTest(0), letter(' '), number(0), validInput(false), letter_number(0), validas(false), S_P_score(0), ships_count(20), letter_to_str(" "), number_to_str(" "), letter_number_str(" "), klaida_used(0), ltr_str(" "), nmb_ltr_str(" ") {}
	~SinglePlayerC() {}
	void drawLoading_S_P_GameBoard()
	{
		time_t startTime = time(nullptr); // Gaunamas pradinis laikas

		while (true)
		{
			system("cls");
			ClearScreen();
			cout << YELLOW << "LOADING SINGLE PLAYER MODE." << RESET << endl;
			Sleep(500);
			ClearScreen();
			cout << YELLOW << "LOADING SINGLE PLAYER MODE.." << RESET << endl;
			Sleep(500);
			ClearScreen();
			cout << YELLOW << "LOADING SINGLE PLAYER MODE..." << RESET << endl;
			Sleep(500);

			if (difftime(time(nullptr), startTime) >= 1) break; // Tikriname ar 1 sec jau praejo
		}
	}

	void drawS_P_title()
	{
		cout << YELLOW << " ***************************************************************************************************" << RESET << endl;
		cout << YELLOW << "** " << RESET << RED << "########" << ORANGE << "  ##  ###   ##  ########  ##        ########    ##     ##  ########  #######   " << RED << "########" << YELLOW << " **" << RESET << endl;
		cout << YELLOW << "** " << RESET << ORANGE << "##        ##  ## #  ##  ##        ##        ##          ## # # ##  ##    ##  ##    ##  ##      " << YELLOW << " **" << RESET << endl;
		cout << YELLOW << "** " << RESET << RED << "########  ##  ##  # ##  ##  ####  ##        ########    ##  #  ##  ##    ##  ##    ##  ########" << YELLOW << " **" << RESET << endl;
		cout << YELLOW << "** " << RESET << ORANGE << "      ##  ##  ##   ###  ##    ##  ##        ##          ##     ##  ##    ##  ##    ##  ##      " << YELLOW << " **" << RESET << endl;
		cout << YELLOW << "** " << RESET << RED << "########" << ORANGE << "  ##  ##    ##  ########  ########  ########    ##     ##  ########  #######   " << RED << "########" << YELLOW << " **" << RESET << endl;
		cout << YELLOW << " ***************************************************************************************************" << RESET << endl;
		cout << endl;
	}

	void enterYourName()
	{
		system("cls");
		drawS_P_title();
		cout << GREY << "Please ENTER your name: " << RESET;

		cout << RED;
		cin >> S_name;
		cout << RESET;
	}

	void Board_SP()
	{
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++) { SPlayerBoard[i][j] = '#'; SPlayerBoard_second[i][j] = '#'; }
	}

	void drawS_P_GameBoard()
	{
		system("cls");

		drawS_P_title();
		cout << GREY << "                                     " << " |" << RED << S_name << "'s" << GREY << "| GAMEBOARD:                      " << RESET << endl << endl;

		cout << GREY << "                                       *********************" << RESET << endl;
		cout << GREY << "                                     * " << ORANGE << "x" << RESET << YELLOW << " A B C D E F G H I J" << GREY << " * " << RESET << endl;

		for (int i = 0; i < 10; i++)
		{
			cout << GREY << "                                     * " << YELLOW << i << RESET << " ";
			for (int j = 0; j < 10; j++)
			{
				if (SPlayerBoard[i][j] == 'O') cout << CYAN << SPlayerBoard[i][j] << RESET << " ";
				if (SPlayerBoard[i][j] == 'X') cout << RED << SPlayerBoard[i][j] << RESET << " ";
				if (SPlayerBoard[i][j] == '#') cout << BLUE << SPlayerBoard[i][j] << RESET << " ";
			}
			cout << GREY << "*" << RESET << endl;
		}
		cout << GREY << "                                       *********************" << RESET << endl;
		cout << endl;
	}

	void drawS_P_GameBoard_without_cls()
	{
		system("cls");

		drawS_P_title();
		cout << GREY << "                                     " << " |" << RED << S_name << "'s" << GREY << "| GAMEBOARD:                      " << RESET << endl << endl;

		cout << GREY << "                                       *********************" << RESET << endl;
		cout << GREY << "                                     * " << ORANGE << "x" << RESET << YELLOW << " A B C D E F G H I J" << GREY << " * " << RESET << endl;

		for (int i = 0; i < 10; i++)
		{
			cout << GREY << "                                     * " << YELLOW << i << RESET << " ";
			for (int j = 0; j < 10; j++)
			{
				if (SPlayerBoard[i][j] == 'O') cout << CYAN << SPlayerBoard[i][j] << RESET << " ";
				if (SPlayerBoard[i][j] == 'X') cout << RED << SPlayerBoard[i][j] << RESET << " ";
				if (SPlayerBoard[i][j] == '#') cout << BLUE << SPlayerBoard[i][j] << RESET << " ";
			}
			cout << GREY << "*" << RESET << endl;
		}
		cout << GREY << "                                       *********************" << RESET << endl;
		cout << endl;
	}

	void generate_4SHIP()
	{
		/*
		 x  0  1  2  3  4  5  6  7  8  9
		 0 0A 0B 0C 0D 0E 0F 0G 0H 0I 0J
		 1 1A 1B 1C 1D 1E 1F 1G 1H 1I 1J
		 2 2A 2B 2C 2D 2E 2F 2G 2H 2I 2J
		 3 3A 3B 3C 3D 3E 3F 3G 3H 3I 3J
		 4 4A 4B 4C 4D 4E 4F 4G 4H 4I 4J
		 5 5A 5B 5C 5D 5E 5F 5G 5H 5I 5J
		 6 6A 6B 6C 6D 6E 6F 6G 6H 6I 6J
		 7 7A 7B 7C 7D 7E 7F 7G 7H 7I 7J
		 8 8A 8B 8C 8D 8E 8F 8G 8H 8I 8J
		 9 9A 9B 9C 9D 9E 9F 9G 9H 9I 9J
		*/

		srand(static_cast<unsigned int>(time(0)));

		X = rand() % GameBoardSize;
		Y = rand() % GameBoardSize;

		//X = 3;
		//Y = 2;

		SPlayerBoard_second[Y][X] = 'S';

		if (X + 1 < 10)
			if (SPlayerBoard_second[Y][X + 1] == '#')
				if (X + 2 < 10)
					if (SPlayerBoard_second[Y][X + 2] == '#')
						if (X + 3 < 10)
							if (SPlayerBoard_second[Y][X + 3] == '#') {
								test_1 = true; test_count++;
							}

		if (Y + 1 < 10)
			if (SPlayerBoard_second[Y + 1][X] == '#')
				if (Y + 2 < 10)
					if (SPlayerBoard_second[Y + 2][X] == '#')
						if (Y + 3 < 10)
							if (SPlayerBoard_second[Y + 3][X] == '#') {
								test_2 = true; test_count++;
							}

		if (X - 1 >= 0)
			if (SPlayerBoard_second[Y][X - 1] == '#')
				if (X - 2 >= 0)
					if (SPlayerBoard_second[Y][X - 2] == '#')
						if (X - 3 >= 0)
							if (SPlayerBoard_second[Y][X - 3] == '#') {
								test_3 = true; test_count++;
							}

		if (Y - 1 >= 0)
			if (SPlayerBoard_second[Y - 1][X] == '#')
				if (Y - 2 >= 0)
					if (SPlayerBoard_second[Y - 2][X] == '#')
						if (Y - 3 >= 0)
							if (SPlayerBoard_second[Y - 3][X] == '#') {
								test_4 = true; test_count++;
							}

		if (test_1 == true && test_2 == false && test_3 == false && test_4 == false) selectedTest = 0; //0 1 2 3 (0)
		if (test_1 == false && test_2 == true && test_3 == false && test_4 == false) selectedTest = 1; //0 1 2 3 (1)
		if (test_1 == false && test_2 == false && test_3 == true && test_4 == false) selectedTest = 2; //0 1 2 3 (2)
		if (test_1 == false && test_2 == false && test_3 == false && test_4 == true) selectedTest = 0; //0 1 2 3 (3)
		if (test_1 == true && test_2 == true && test_3 == false && test_4 == false) selectedTest = rand() % test_count; //0 1 2 3 (01)
		if (test_1 == true && test_2 == false && test_3 == true && test_4 == false)
		{
			do {
				selectedTest = rand() % (test_count + 1); //0 1 2 3 (02)
			} while (selectedTest == 1);
		}
		if (test_1 == true && test_2 == false && test_3 == false && test_4 == true)
		{
			do {
				selectedTest = rand() % (test_count + 2); //0 1 2 3 (03)
			} while (selectedTest == 1 || selectedTest == 2);
		}
		if (test_1 == true && test_2 == true && test_3 == true && test_4 == false) selectedTest = rand() % test_count; //0 1 2 3 (012)
		if (test_1 == true && test_2 == true && test_3 == false && test_4 == true)
		{
			do {
				selectedTest = rand() % (test_count + 1); //0 1 2 3 (013)
			} while (selectedTest == 2);
		}
		if (test_1 == true && test_2 == false && test_3 == true && test_4 == true)
		{
			do {
				selectedTest = rand() % (test_count + 1); //0 1 2 3 (023)
			} while (selectedTest == 1);
		}
		if (test_1 == false && test_2 == true && test_3 == true && test_4 == false)
		{
			do {
				selectedTest = rand() % (test_count + 1); //0 1 2 3 (12)
			} while (selectedTest == 0);
		}
		if (test_1 == false && test_2 == true && test_3 == false && test_4 == true)
		{
			do {
				selectedTest = rand() % (test_count + 2); //0 1 2 3 (13)
			} while (selectedTest == 0 || selectedTest == 2);
		}
		if (test_1 == false && test_2 == true && test_3 == true && test_4 == true)
		{
			do {
				selectedTest = rand() % (test_count + 1); //0 1 2 3 (123)
			} while (selectedTest == 0);
		}
		if (test_1 == false && test_2 == false && test_3 == true && test_4 == true)
		{
			do {
				selectedTest = rand() % (test_count + 2); //0 1 2 3 (23)
			} while (selectedTest == 0 || selectedTest == 1);
		}

		if (selectedTest == 0) {

			SPlayerBoard_second[Y][X + 1] = 'S';
			SPlayerBoard_second[Y][X + 2] = 'S';
			SPlayerBoard_second[Y][X + 3] = 'S';

		}
		if (selectedTest == 1) {

			SPlayerBoard_second[Y + 1][X] = 'S';
			SPlayerBoard_second[Y + 2][X] = 'S';
			SPlayerBoard_second[Y + 3][X] = 'S';

		}
		if (selectedTest == 2) {

			SPlayerBoard_second[Y][X - 1] = 'S';
			SPlayerBoard_second[Y][X - 2] = 'S';
			SPlayerBoard_second[Y][X - 3] = 'S';

		}
		if (selectedTest == 3) {

			SPlayerBoard_second[Y - 1][X] = 'S';
			SPlayerBoard_second[Y - 2][X] = 'S';
			SPlayerBoard_second[Y - 3][X] = 'S';

		}
	}

	void generate_4SHIP_zone()
	{
		ofstream test;
		test.open("test_4SHIP.txt");

		test << "X: " << X << endl;
		test << "Y: " << Y << endl << endl;

		test << "test_1: " << test_1 << endl;
		test << "test_2: " << test_2 << endl;
		test << "test_3: " << test_3 << endl;
		test << "test_4: " << test_4 << endl << endl;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (SPlayerBoard_second[i][j] == 'S' && i > 0 && SPlayerBoard_second[i - 1][j] == '#') SPlayerBoard_second[i - 1][j] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && i < 9 && SPlayerBoard_second[i + 1][j] == '#') SPlayerBoard_second[i + 1][j] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && j > 0 && SPlayerBoard_second[i][j - 1] == '#') SPlayerBoard_second[i][j - 1] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && j < 9 && SPlayerBoard_second[i][j + 1] == '#') SPlayerBoard_second[i][j + 1] = '-';

				if (SPlayerBoard_second[i][j] == 'S' && (i > 0 && j > 0) && SPlayerBoard_second[i - 1][j - 1] == '#') SPlayerBoard_second[i - 1][j - 1] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && (i < 9 && j > 0) && SPlayerBoard_second[i + 1][j - 1] == '#') SPlayerBoard_second[i + 1][j - 1] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && (i > 0 && j < 9) && SPlayerBoard_second[i - 1][j + 1] == '#') SPlayerBoard_second[i - 1][j + 1] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && (i < 9 && j < 9) && SPlayerBoard_second[i + 1][j + 1] == '#') SPlayerBoard_second[i + 1][j + 1] = '-';
			}
		}

		test << "  *********************" << endl;
		test << "* " << "x" << " A B C D E F G H I J" << " * " << endl;
		for (int i = 0; i < 10; i++)
		{
			test << "* " << i << " ";
			for (int j = 0; j < 10; j++)
			{
				test << SPlayerBoard_second[i][j] << " ";
			}
			test << "*" << endl;
		}
		test << "  *********************" << endl;

		test.close();
	}

	void generate_3SHIP()
	{
		srand(static_cast<unsigned int>(time(0)));

		while (true)
		{
			while (SPlayerBoard_second[Y][X] == 'S' || SPlayerBoard_second[Y][X] == '-')
			{
				X = rand() % GameBoardSize;
				Y = rand() % GameBoardSize;
			}

			//X = 3;
			//Y = 2;

			SPlayerBoard_second[Y][X] = 'S';

			test_1 = false;
			test_2 = false;
			test_3 = false;
			test_4 = false;
			test_count = 0;

			if (X + 1 < 10)
				if (SPlayerBoard_second[Y][X + 1] == '#')
					if (X + 2 < 10)
						if (SPlayerBoard_second[Y][X + 2] == '#') {
							test_1 = true; test_count++;
						}

			if (Y + 1 < 10)
				if (SPlayerBoard_second[Y + 1][X] == '#')
					if (Y + 2 < 10)
						if (SPlayerBoard_second[Y + 2][X] == '#') {
							test_2 = true; test_count++;
						}

			if (X - 1 >= 0)
				if (SPlayerBoard_second[Y][X - 1] == '#')
					if (X - 2 >= 0)
						if (SPlayerBoard_second[Y][X - 2] == '#') {
							test_3 = true; test_count++;
						}

			if (Y - 1 >= 0)
				if (SPlayerBoard_second[Y - 1][X] == '#')
					if (Y - 2 >= 0)
						if (SPlayerBoard_second[Y - 2][X] == '#') {
							test_4 = true; test_count++;
						}
			if (test_count != 0) break;
		}

		/*cout << "X: " << X << endl;
		cout << "Y: " << Y << endl << endl;

		cout << "test_1: " << test_1 << endl;
		cout << "test_2: " << test_2 << endl;
		cout << "test_3: " << test_3 << endl;
		cout << "test_4: " << test_4 << endl << endl;*/

		if (test_1 == true && test_2 == false && test_3 == false && test_4 == false) selectedTest = 0; //0 1 2 3 (0)
		if (test_1 == false && test_2 == true && test_3 == false && test_4 == false) selectedTest = 1; //0 1 2 3 (1)
		if (test_1 == false && test_2 == false && test_3 == true && test_4 == false) selectedTest = 2; //0 1 2 3 (2)
		if (test_1 == false && test_2 == false && test_3 == false && test_4 == true) selectedTest = 0; //0 1 2 3 (3)
		if (test_1 == true && test_2 == true && test_3 == false && test_4 == false) selectedTest = rand() % test_count; //0 1 2 3 (01)
		if (test_1 == true && test_2 == false && test_3 == true && test_4 == false)
		{
			do {
				selectedTest = rand() % (test_count + 1); //0 1 2 3 (02)
			} while (selectedTest == 1);
		}
		if (test_1 == true && test_2 == false && test_3 == false && test_4 == true)
		{
			do {
				selectedTest = rand() % (test_count + 2); //0 1 2 3 (03)
			} while (selectedTest == 1 || selectedTest == 2);
		}
		if (test_1 == true && test_2 == true && test_3 == true && test_4 == false) selectedTest = rand() % test_count; //0 1 2 3 (012)
		if (test_1 == true && test_2 == true && test_3 == false && test_4 == true)
		{
			do {
				selectedTest = rand() % (test_count + 1); //0 1 2 3 (013)
			} while (selectedTest == 2);
		}
		if (test_1 == true && test_2 == false && test_3 == true && test_4 == true)
		{
			do {
				selectedTest = rand() % (test_count + 1); //0 1 2 3 (023)
			} while (selectedTest == 1);
		}
		if (test_1 == false && test_2 == true && test_3 == true && test_4 == false)
		{
			do {
				selectedTest = rand() % (test_count + 1); //0 1 2 3 (12)
			} while (selectedTest == 0);
		}
		if (test_1 == false && test_2 == true && test_3 == false && test_4 == true)
		{
			do {
				selectedTest = rand() % (test_count + 2); //0 1 2 3 (13)
			} while (selectedTest == 0 || selectedTest == 2);
		}
		if (test_1 == false && test_2 == true && test_3 == true && test_4 == true)
		{
			do {
				selectedTest = rand() % (test_count + 1); //0 1 2 3 (123)
			} while (selectedTest == 0);
		}
		if (test_1 == false && test_2 == false && test_3 == true && test_4 == true)
		{
			do {
				selectedTest = rand() % (test_count + 2); //0 1 2 3 (23)
			} while (selectedTest == 0 || selectedTest == 1);
		}

		//cout << selectedTest << endl;

		if (selectedTest == 0) {
			SPlayerBoard_second[Y][X + 1] = 'S';
			SPlayerBoard_second[Y][X + 2] = 'S';
		}
		if (selectedTest == 1) {
			SPlayerBoard_second[Y + 1][X] = 'S';
			SPlayerBoard_second[Y + 2][X] = 'S';
		}
		if (selectedTest == 2) {
			SPlayerBoard_second[Y][X - 1] = 'S';
			SPlayerBoard_second[Y][X - 2] = 'S';
		}
		if (selectedTest == 3) {
			SPlayerBoard_second[Y - 1][X] = 'S';
			SPlayerBoard_second[Y - 2][X] = 'S';
		}
	}

	void generate_3SHIP_zone()
	{
		ofstream test;
		test.open("test_3SHIP.txt");

		test << "X: " << X << endl;
		test << "Y: " << Y << endl << endl;

		test << "test_1: " << test_1 << endl;
		test << "test_2: " << test_2 << endl;
		test << "test_3: " << test_3 << endl;
		test << "test_4: " << test_4 << endl << endl;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (SPlayerBoard_second[i][j] == 'S' && i > 0 && SPlayerBoard_second[i - 1][j] == '#') SPlayerBoard_second[i - 1][j] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && i < 9 && SPlayerBoard_second[i + 1][j] == '#') SPlayerBoard_second[i + 1][j] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && j > 0 && SPlayerBoard_second[i][j - 1] == '#') SPlayerBoard_second[i][j - 1] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && j < 9 && SPlayerBoard_second[i][j + 1] == '#') SPlayerBoard_second[i][j + 1] = '-';

				if (SPlayerBoard_second[i][j] == 'S' && (i > 0 && j > 0) && SPlayerBoard_second[i - 1][j - 1] == '#') SPlayerBoard_second[i - 1][j - 1] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && (i < 9 && j > 0) && SPlayerBoard_second[i + 1][j - 1] == '#') SPlayerBoard_second[i + 1][j - 1] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && (i > 0 && j < 9) && SPlayerBoard_second[i - 1][j + 1] == '#') SPlayerBoard_second[i - 1][j + 1] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && (i < 9 && j < 9) && SPlayerBoard_second[i + 1][j + 1] == '#') SPlayerBoard_second[i + 1][j + 1] = '-';
			}
		}

		test << "  *********************" << endl;
		test << "* " << "x" << " A B C D E F G H I J" << " * " << endl;
		for (int i = 0; i < 10; i++)
		{
			test << "* " << i << " ";
			for (int j = 0; j < 10; j++)
			{
				test << SPlayerBoard_second[i][j] << " ";
			}
			test << "*" << endl;
		}
		test << "  *********************" << endl;

		test.close();
	}

	void generate_2SHIP()
	{
		srand(static_cast<unsigned int>(time(0)));

		while (true)
		{
			while (SPlayerBoard_second[Y][X] == 'S' || SPlayerBoard_second[Y][X] == '-')
			{
				X = rand() % GameBoardSize;
				Y = rand() % GameBoardSize;
			}

			//X = 3;
			//Y = 2;

			SPlayerBoard_second[Y][X] = 'S';

			test_1 = false;
			test_2 = false;
			test_3 = false;
			test_4 = false;
			test_count = 0;

			if (X + 1 < 10)
				if (SPlayerBoard_second[Y][X + 1] == '#') {
					test_1 = true; test_count++;
				}

			if (Y + 1 < 10)
				if (SPlayerBoard_second[Y + 1][X] == '#') {
					test_2 = true; test_count++;
				}

			if (X - 1 >= 0)
				if (SPlayerBoard_second[Y][X - 1] == '#') {
					test_3 = true; test_count++;
				}

			if (Y - 1 >= 0)
				if (SPlayerBoard_second[Y - 1][X] == '#') {
					test_4 = true; test_count++;
				}

			if (test_count != 0) break;
		}

		if (test_1 == true && test_2 == false && test_3 == false && test_4 == false) selectedTest = 0; //0 1 2 3 (0)
		if (test_1 == false && test_2 == true && test_3 == false && test_4 == false) selectedTest = 1; //0 1 2 3 (1)
		if (test_1 == false && test_2 == false && test_3 == true && test_4 == false) selectedTest = 2; //0 1 2 3 (2)
		if (test_1 == false && test_2 == false && test_3 == false && test_4 == true) selectedTest = 0; //0 1 2 3 (3)
		if (test_1 == true && test_2 == true && test_3 == false && test_4 == false) selectedTest = rand() % test_count; //0 1 2 3 (01)
		if (test_1 == true && test_2 == false && test_3 == true && test_4 == false)
		{
			do {
				selectedTest = rand() % (test_count + 1); //0 1 2 3 (02)
			} while (selectedTest == 1);
		}
		if (test_1 == true && test_2 == false && test_3 == false && test_4 == true)
		{
			do {
				selectedTest = rand() % (test_count + 2); //0 1 2 3 (03)
			} while (selectedTest == 1 || selectedTest == 2);
		}
		if (test_1 == true && test_2 == true && test_3 == true && test_4 == false) selectedTest = rand() % test_count; //0 1 2 3 (012)
		if (test_1 == true && test_2 == true && test_3 == false && test_4 == true)
		{
			do {
				selectedTest = rand() % (test_count + 1); //0 1 2 3 (013)
			} while (selectedTest == 2);
		}
		if (test_1 == true && test_2 == false && test_3 == true && test_4 == true)
		{
			do {
				selectedTest = rand() % (test_count + 1); //0 1 2 3 (023)
			} while (selectedTest == 1);
		}
		if (test_1 == false && test_2 == true && test_3 == true && test_4 == false)
		{
			do {
				selectedTest = rand() % (test_count + 1); //0 1 2 3 (12)
			} while (selectedTest == 0);
		}
		if (test_1 == false && test_2 == true && test_3 == false && test_4 == true)
		{
			do {
				selectedTest = rand() % (test_count + 2); //0 1 2 3 (13)
			} while (selectedTest == 0 || selectedTest == 2);
		}
		if (test_1 == false && test_2 == true && test_3 == true && test_4 == true)
		{
			do {
				selectedTest = rand() % (test_count + 1); //0 1 2 3 (123)
			} while (selectedTest == 0);
		}
		if (test_1 == false && test_2 == false && test_3 == true && test_4 == true)
		{
			do {
				selectedTest = rand() % (test_count + 2); //0 1 2 3 (23)
			} while (selectedTest == 0 || selectedTest == 1);
		}

		if (selectedTest == 0) {
			SPlayerBoard_second[Y][X + 1] = 'S';
		}
		if (selectedTest == 1) {
			SPlayerBoard_second[Y + 1][X] = 'S';
		}
		if (selectedTest == 2) {
			SPlayerBoard_second[Y][X - 1] = 'S';
		}
		if (selectedTest == 3) {
			SPlayerBoard_second[Y - 1][X] = 'S';
		}
	}

	void generate_2SHIP_zone()
	{
		ofstream test;
		test.open("test_2SHIP.txt");

		test << "X: " << X << endl;
		test << "Y: " << Y << endl << endl;

		test << "test_1: " << test_1 << endl;
		test << "test_2: " << test_2 << endl;
		test << "test_3: " << test_3 << endl;
		test << "test_4: " << test_4 << endl << endl;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (SPlayerBoard_second[i][j] == 'S' && i > 0 && SPlayerBoard_second[i - 1][j] == '#') SPlayerBoard_second[i - 1][j] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && i < 9 && SPlayerBoard_second[i + 1][j] == '#') SPlayerBoard_second[i + 1][j] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && j > 0 && SPlayerBoard_second[i][j - 1] == '#') SPlayerBoard_second[i][j - 1] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && j < 9 && SPlayerBoard_second[i][j + 1] == '#') SPlayerBoard_second[i][j + 1] = '-';

				if (SPlayerBoard_second[i][j] == 'S' && (i > 0 && j > 0) && SPlayerBoard_second[i - 1][j - 1] == '#') SPlayerBoard_second[i - 1][j - 1] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && (i < 9 && j > 0) && SPlayerBoard_second[i + 1][j - 1] == '#') SPlayerBoard_second[i + 1][j - 1] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && (i > 0 && j < 9) && SPlayerBoard_second[i - 1][j + 1] == '#') SPlayerBoard_second[i - 1][j + 1] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && (i < 9 && j < 9) && SPlayerBoard_second[i + 1][j + 1] == '#') SPlayerBoard_second[i + 1][j + 1] = '-';
			}
		}

		test << "  *********************" << endl;
		test << "* " << "x" << " A B C D E F G H I J" << " * " << endl;
		for (int i = 0; i < 10; i++)
		{
			test << "* " << i << " ";
			for (int j = 0; j < 10; j++)
			{
				test << SPlayerBoard_second[i][j] << " ";
			}
			test << "*" << endl;
		}
		test << "  *********************" << endl;

		test.close();
	}

	void generate_1SHIP()
	{
		srand(static_cast<unsigned int>(time(0)));

		while (SPlayerBoard_second[Y][X] == 'S' || SPlayerBoard_second[Y][X] == '-')
		{
			X = rand() % GameBoardSize;
			Y = rand() % GameBoardSize;
		}

		//X = 3;
		//Y = 2;

		SPlayerBoard_second[Y][X] = 'S';
	}

	void generate_1SHIP_zone()
	{
		ofstream test;
		test.open("test_1SHIP.txt");

		test << "X: " << X << endl;
		test << "Y: " << Y << endl << endl;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (SPlayerBoard_second[i][j] == 'S' && i > 0 && SPlayerBoard_second[i - 1][j] == '#') SPlayerBoard_second[i - 1][j] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && i < 9 && SPlayerBoard_second[i + 1][j] == '#') SPlayerBoard_second[i + 1][j] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && j > 0 && SPlayerBoard_second[i][j - 1] == '#') SPlayerBoard_second[i][j - 1] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && j < 9 && SPlayerBoard_second[i][j + 1] == '#') SPlayerBoard_second[i][j + 1] = '-';

				if (SPlayerBoard_second[i][j] == 'S' && (i > 0 && j > 0) && SPlayerBoard_second[i - 1][j - 1] == '#') SPlayerBoard_second[i - 1][j - 1] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && (i < 9 && j > 0) && SPlayerBoard_second[i + 1][j - 1] == '#') SPlayerBoard_second[i + 1][j - 1] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && (i > 0 && j < 9) && SPlayerBoard_second[i - 1][j + 1] == '#') SPlayerBoard_second[i - 1][j + 1] = '-';
				if (SPlayerBoard_second[i][j] == 'S' && (i < 9 && j < 9) && SPlayerBoard_second[i + 1][j + 1] == '#') SPlayerBoard_second[i + 1][j + 1] = '-';
			}
		}

		test << "  *********************" << endl;
		test << "* " << "x" << " A B C D E F G H I J" << " * " << endl;
		for (int i = 0; i < 10; i++)
		{
			test << "* " << i << " ";
			for (int j = 0; j < 10; j++)
			{
				test << SPlayerBoard_second[i][j] << " ";
			}
			test << "*" << endl;
		}
		test << "  *********************" << endl;

		test.close();
	}

	void S_P_Shooting()
	{
		set <string> used_c;
		map <char, int> koordinate = {
			{'A', 0}, {'A', 1}, {'A', 2}, {'A', 3}, {'A', 4}, {'A', 5}, {'A', 6}, {'A', 7}, {'A', 8}, {'A', 9},
			{'B', 0}, {'B', 1}, {'B', 2}, {'B', 3}, {'B', 4}, {'B', 5}, {'B', 6}, {'B', 7}, {'B', 8}, {'B', 9},
			{'C', 0}, {'C', 1}, {'C', 2}, {'C', 3}, {'C', 4}, {'C', 5}, {'C', 6}, {'C', 7}, {'C', 8}, {'C', 9},
			{'D', 0}, {'D', 1}, {'D', 2}, {'D', 3}, {'D', 4}, {'D', 5}, {'D', 6}, {'D', 7}, {'D', 8}, {'D', 9},
			{'E', 0}, {'E', 1}, {'E', 2}, {'E', 3}, {'E', 4}, {'E', 5}, {'E', 6}, {'E', 7}, {'E', 8}, {'E', 9},
			{'F', 0}, {'F', 1}, {'F', 2}, {'F', 3}, {'F', 4}, {'F', 5}, {'F', 6}, {'F', 7}, {'F', 8}, {'F', 9},
			{'G', 0}, {'G', 1}, {'G', 2}, {'G', 3}, {'G', 4}, {'G', 5}, {'G', 6}, {'G', 7}, {'G', 8}, {'G', 9},
			{'H', 0}, {'H', 1}, {'H', 2}, {'H', 3}, {'H', 4}, {'H', 5}, {'H', 6}, {'H', 7}, {'H', 8}, {'H', 9},
			{'I', 0}, {'I', 1}, {'I', 2}, {'I', 3}, {'I', 4}, {'I', 5}, {'I', 6}, {'I', 7}, {'I', 8}, {'I', 9},
			{'J', 0}, {'J', 1}, {'J', 2}, {'J', 3}, {'J', 4}, {'J', 5}, {'J', 6}, {'J', 7}, {'J', 8}, {'J', 9},
		};

		cout << BLUE << "Score: - - " << RESET << endl;
		cout << BLUE << "Last taken shot: - - " << RESET << endl;
		cout << BLUE << "Remaining ship's parts: " << ships_count << RESET << endl;

		while (!validInput)
		{
			cout << endl;
			cout << GREEN << "LETTER & NUMBER (Exp. A 2) " << RESET << endl;
			cout << ORANGE << "Please ENTER coordinate of the gameboard: " << RESET;

			cout << RED;
			cin >> letter >> number;
			cout << RESET;
			letter = toupper(letter);

			number_to_str = to_string(number);
			letter_to_str = string(1, letter);
			letter_number_str = letter_to_str + number_to_str;

			if (used_c.find(letter_number_str) != used_c.end()) klaida_used = true;

			used_c.insert(letter_number_str);
				
			try
			{
				if (koordinate.find(letter) != koordinate.end() && number >= 0 && number < 10) {
					validInput = true;
					validas = true;
					throw "You entered valid coordinates!";
				}
				else {
					validas = false;
					throw "Invalid coordinates, please try again.";
				}
			}

			catch (const char* message)
			{
				if (validas == true) cout << GREEN << message << RESET;
				else cout << RED << message << " - " << ORANGE << letter << " " << number << RESET;
				Sleep(800);
			}

			if (letter == 'A') letter_number = 0;
			if (letter == 'B') letter_number = 1;
			if (letter == 'C') letter_number = 2;
			if (letter == 'D') letter_number = 3;
			if (letter == 'E') letter_number = 4;
			if (letter == 'F') letter_number = 5;
			if (letter == 'G') letter_number = 6;
			if (letter == 'H') letter_number = 7;
			if (letter == 'I') letter_number = 8;
			if (letter == 'J') letter_number = 9;

			ltr_str = to_string(letter_number);
			nmb_ltr_str = ltr_str + number_to_str;

			if (SPlayerBoard_second[number][letter_number] == '#' || SPlayerBoard_second[number][letter_number] == '-') {
				cout << endl;
				if (letter >= 'A' && letter <= 'J') SPlayerBoard[number][letter_number] = 'O';
				ShowConsoleCursor(false);
				ClearScreen();
				drawS_P_title();
				drawS_P_GameBoard_without_cls();
				if (letter >= 'A' && letter <= 'J') {
					if (klaida_used == true) {
						cout << RED << "INVALID - USED COORDINATE" << RESET << endl << endl;
						klaida_used = false;
					}
					else {
						cout << RED << "MISSED shot! " << RESET << endl << endl;
						S_P_score = S_P_score - 100;
					}
				}
				else cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
				validInput = false;
				score_table();
			}
			else {
				cout << endl;
				if (letter >= 'A' && letter <= 'J') SPlayerBoard[number][letter_number] = 'X';
				ShowConsoleCursor(false);
				ClearScreen();
				drawS_P_title();
				drawS_P_GameBoard_without_cls();
				if (letter >= 'A' && letter <= 'J') {
					if (klaida_used == true) {
						cout << RED << "INVALID - USED COORDINATE" << RESET << endl << endl;
						klaida_used = false;
					}
					else {
						cout << GREEN << "HIT shot! " << RESET << endl << endl;
						ships_count--;
						S_P_score = S_P_score + 100;
					}
				}
				else cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
				if (ships_count == 0) {
					S_P_Victory(); break;
				}
				validInput = false;
				score_table();
			}
		}
	}

	const void score_table()
	{
		cout << BLUE << "Score: " << S_P_score << RESET << endl;
		cout << BLUE << "Last taken shot: " << letter << " " << number << RESET << endl;
		cout << BLUE << "Remaining ship's parts: " << ships_count << RESET << endl;
	}

	const void S_P_Victory()
	{
		system("cls");
		drawS_P_title();
		cout << YELLOW << "                   *****************************************************************" << RESET << endl;
		cout << YELLOW << "                  ** " << RESET << CYAN << "##   ##  ##  #######  ########  #######  #######  ##    ##  ##" << YELLOW << " **" << RESET << endl;
		cout << YELLOW << "                  ** " << RESET << GREEN << "##   ##  ##  ##          ##     ##   ##  ##   ##   ##  ##   ##" << YELLOW << " **" << RESET << endl;
		cout << YELLOW << "                  ** " << RESET << RED << "##   ##  ##  ##          ##     ##   ##  #####       ##     ##" << YELLOW << " **" << RESET << endl;
		cout << YELLOW << "                  ** " << RESET << GREEN << " ## ##   ##  ##          ##     ##   ##  ##  ##      ##       " << YELLOW << " **" << RESET << endl;
		cout << YELLOW << "                  ** " << RESET << CYAN << "   #     ##  #######     ##     #######  ##   ##     ##     ##" << YELLOW << " **" << RESET << endl;
		cout << YELLOW << "                   ******************************************************************" << RESET << endl << endl;

		cout << GREY << "|" << RED << S_name << "'s" GREY << "|" << ORANGE << " GAME RESULTS: " << endl << endl;
		cout << BLUE << "Score: " << S_P_score << RESET << endl;
		cout << BLUE << "SUNKED ship's parts: 20" << RESET << endl;
	}

};

class MultiPlayerC_BASE : BASE_S_M_Player
{
private:

protected:
	vector <vector<char>> AI_PlayerBoard;
	vector <vector<char>> N_PlayerBoard_second;

public:
MultiPlayerC_BASE() : AI_PlayerBoard(10, vector<char>(10, '#')), N_PlayerBoard_second(10, vector<char>(10, '#')) {}
MultiPlayerC_BASE(bool x, int y, char z) : AI_PlayerBoard(10, vector<char>(10, '#')), N_PlayerBoard_second(10, vector<char>(10, '#')) {}
~MultiPlayerC_BASE() {}

	void ClearScreen()
	{
		HANDLE hOut;
		COORD Position;

		hOut = GetStdHandle(STD_OUTPUT_HANDLE);

		Position.X = 0;
		Position.Y = 0;
		SetConsoleCursorPosition(hOut, Position);
	}

	void ClearScreen_the_whole()
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		DWORD count;
		COORD homeCoords = { 0, 0 };

		if (hOut == INVALID_HANDLE_VALUE) return;

		if (!GetConsoleScreenBufferInfo(hOut, &csbi)) return;

		DWORD cellCount = csbi.dwSize.X * csbi.dwSize.Y;

		FillConsoleOutputCharacter(hOut, ' ', cellCount, homeCoords, &count);

		FillConsoleOutputAttribute(hOut, csbi.wAttributes, cellCount, homeCoords, &count);
		SetConsoleCursorPosition(hOut, homeCoords);
	}

	void ShowConsoleCursor(bool showFlag)
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_CURSOR_INFO     cursorInfo;

		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = showFlag; // set the cursor visibility
		SetConsoleCursorInfo(out, &cursorInfo);
	}

	void drawLoading_A_I_GameBoard()
	{
		time_t startTime = time(nullptr); // Gaunamas pradinis laikas

		while (true)
		{
			system("cls");
			ClearScreen();
			cout << YELLOW << "LOADING ARTIFICIAL INTELLIGENCE MODE." << RESET << endl;
			Sleep(500);
			ClearScreen();
			cout << YELLOW << "LOADING ARTIFICIAL INTELLIGENCE MODE.." << RESET << endl;
			Sleep(500);
			ClearScreen();
			cout << YELLOW << "LOADING ARTIFICIAL INTELLIGENCE MODE..." << RESET << endl;
			Sleep(500);

			if (difftime(time(nullptr), startTime) >= 1) break; // Tikriname ar 1 sec jau praejo
		}
	}

	void drawA_I_title()
	{
		cout << YELLOW << " ***********************************************************" << RESET << endl;
		cout << YELLOW << "** " << RED << " ######   ##    ##     ##  ########  #######   ########" << YELLOW << " **" << RESET << endl;
		cout << YELLOW << "** " << ORANGE << "##    ##        ## # # ##  ##    ##  ##    ##  ##      " << YELLOW << " **" << RESET << endl;
		cout << YELLOW << "** " << RED << "########  ##    ##  #  ##  ##    ##  ##    ##  ########" << YELLOW << " **" << RESET << endl;
		cout << YELLOW << "** " << ORANGE << "##    ##  ##    ##     ##  ##    ##  ##    ##  ##      " << YELLOW << " **" << RESET << endl;
		cout << YELLOW << "** " << RED << "##    ##  ##    ##     ##  ########  #######   ########" << YELLOW << " **" << RESET << endl;
		cout << YELLOW << " ***********************************************************" << RESET << endl;
		cout << endl;
	}

};

class MultiPlayer_A : public MultiPlayerC_BASE
{
private:
	string P_name;
	char P_letter;
	int P_number, P_letter_number;
	bool PvalidInput, Pvalidas;
	set <string> P_can_c;
	int left_ships;
	string P_letter_to_str, P_number_to_str, P_letter_number_str;
	bool P_klaida_cant;
	string P_ltr_str, P_nmb_ltr_str;

	int A_I_score, A_I_ships_count, A_I_steps;
	char A_letter;
	int A_number;
	int A_X_l, A_Y_n;
	int A_GameBoardSize;

	bool eile, stulpelis;
	bool eile_desine, stulpelis_apacia;
	bool eile_kaire, stulpelis_virsus;
	bool eile_is_desines, eile_is_kaires;
	bool stulpelis_is_apacios, stulpelis_is_virsaus;
	
public:
MultiPlayer_A() : P_name(" "), P_letter(' '), P_number(0), P_letter_number(0), PvalidInput(0), Pvalidas(0), left_ships(10), P_letter_to_str(" "), P_number_to_str(" "), P_letter_number_str(" "), P_klaida_cant(0), P_ltr_str(" "), P_nmb_ltr_str(" "), A_I_score(0), A_I_ships_count(20), A_I_steps(1), A_letter(' '), A_number(0), A_X_l(0), A_Y_n(0), A_GameBoardSize(10), eile(0), stulpelis(0), eile_desine(0), stulpelis_apacia(0), eile_kaire(0), stulpelis_virsus(0), eile_is_desines(0), eile_is_kaires(0), stulpelis_is_apacios(0), stulpelis_is_virsaus(0) {}
MultiPlayer_A(string x) : P_name(x), P_letter(' '), P_number(0), P_letter_number(0), PvalidInput(0), Pvalidas(0), left_ships(10), P_letter_to_str(" "), P_number_to_str(" "), P_letter_number_str(" "), P_klaida_cant(0), P_ltr_str(" "), P_nmb_ltr_str(" "), A_I_score(0), A_I_ships_count(20), A_I_steps(1), A_letter(' '), A_number(0), A_X_l(0), A_Y_n(0), A_GameBoardSize(10), eile(0), stulpelis(0), eile_desine(0), stulpelis_apacia(0), eile_kaire(0), stulpelis_virsus(0), eile_is_desines(0), eile_is_kaires(0), stulpelis_is_apacios(0), stulpelis_is_virsaus(0) {}
~MultiPlayer_A() {}

	void enterYourName()
	{
		system("cls");
		drawA_I_title();
		cout << GREY << "Please ENTER your name: " << RESET;

		cout << RED;
		cin >> P_name;
		cout << RESET;
	}

	void drawN_P_GameBoard()
	{
		ClearScreen();
		drawA_I_title();
		cout << GREY << "                     " << " |" << RED << P_name << "'s" << GREY << "| GAMEBOARD:                      " << RESET << endl << endl;

		cout << GREY << "                    *********************" << RESET << endl;
		cout << GREY << "                  * " << ORANGE << "x" << RESET << YELLOW << " A B C D E F G H I J" << GREY << " * " << RESET << endl;

		for (int i = 0; i < 10; i++)
		{
			cout << GREY << "                  * " << YELLOW << i << RESET << " ";
			for (int j = 0; j < 10; j++)
			{
				if (N_PlayerBoard_second[i][j] == 'S') cout << BROWN << N_PlayerBoard_second[i][j] << RESET << " ";
				else cout << BLUE << N_PlayerBoard_second[i][j] << RESET << " ";
			}
			cout << GREY << "*" << RESET << endl;
		}
		cout << GREY << "                    *********************" << RESET << endl;
		cout << endl;
	}

	void generate_N_P_SHIPS()
	{
		generateN_P_4SHIP();
		generateN_P_3SHIP();
		generateN_P_2SHIP();
		generateN_P_1SHIP();
	}

	void generateN_P_4SHIP()
	{
		map <char, int> Pkoordinate = {
			{'A', 0}, {'A', 1}, {'A', 2}, {'A', 3}, {'A', 4}, {'A', 5}, {'A', 6}, {'A', 7}, {'A', 8}, {'A', 9},
			{'B', 0}, {'B', 1}, {'B', 2}, {'B', 3}, {'B', 4}, {'B', 5}, {'B', 6}, {'B', 7}, {'B', 8}, {'B', 9},
			{'C', 0}, {'C', 1}, {'C', 2}, {'C', 3}, {'C', 4}, {'C', 5}, {'C', 6}, {'C', 7}, {'C', 8}, {'C', 9},
			{'D', 0}, {'D', 1}, {'D', 2}, {'D', 3}, {'D', 4}, {'D', 5}, {'D', 6}, {'D', 7}, {'D', 8}, {'D', 9},
			{'E', 0}, {'E', 1}, {'E', 2}, {'E', 3}, {'E', 4}, {'E', 5}, {'E', 6}, {'E', 7}, {'E', 8}, {'E', 9},
			{'F', 0}, {'F', 1}, {'F', 2}, {'F', 3}, {'F', 4}, {'F', 5}, {'F', 6}, {'F', 7}, {'F', 8}, {'F', 9},
			{'G', 0}, {'G', 1}, {'G', 2}, {'G', 3}, {'G', 4}, {'G', 5}, {'G', 6}, {'G', 7}, {'G', 8}, {'G', 9},
			{'H', 0}, {'H', 1}, {'H', 2}, {'H', 3}, {'H', 4}, {'H', 5}, {'H', 6}, {'H', 7}, {'H', 8}, {'H', 9},
			{'I', 0}, {'I', 1}, {'I', 2}, {'I', 3}, {'I', 4}, {'I', 5}, {'I', 6}, {'I', 7}, {'I', 8}, {'I', 9},
			{'J', 0}, {'J', 1}, {'J', 2}, {'J', 3}, {'J', 4}, {'J', 5}, {'J', 6}, {'J', 7}, {'J', 8}, {'J', 9},
		};

		cout << BLUE << "Last coordinate: - - " << RESET << endl;
		cout << BLUE << "Remaining ships to place: " << left_ships << RESET << endl;

		while (!PvalidInput)
		{
			cout << endl;
			cout << BROWN << "SSSS" << GREY << " - COORDINATES" << RESET << endl << endl;
			cout << GREEN << "LETTER & NUMBER (Exp. A 2) " << RESET << endl;
			cout << GREY << "(1) ENTER coordinate of " << BROWN << "|SSSS| " << GREY << "ship: ";

			cout << RED;
			cin >> P_letter >> P_number;
			cout << RESET;

			P_letter = toupper(P_letter);

			if (P_letter == 'A') P_letter_number = 0;
			if (P_letter == 'B') P_letter_number = 1;
			if (P_letter == 'C') P_letter_number = 2;
			if (P_letter == 'D') P_letter_number = 3;
			if (P_letter == 'E') P_letter_number = 4;
			if (P_letter == 'F') P_letter_number = 5;
			if (P_letter == 'G') P_letter_number = 6;
			if (P_letter == 'H') P_letter_number = 7;
			if (P_letter == 'I') P_letter_number = 8;
			if (P_letter == 'J') P_letter_number = 9;

			try
			{
				if (Pkoordinate.find(P_letter) != Pkoordinate.end() && P_number >= 0 && P_number < 10) {
					PvalidInput = true;
					Pvalidas = true;
					throw "You entered valid coordinates!";
				}
				else {
					Pvalidas = false;
					throw "Invalid coordinates, please try again.";
				}
			}

			catch (const char* message)
			{
				if (Pvalidas == true) {
					cout << GREEN << message << RESET;
					Sleep(800);
					N_PlayerBoard_second[P_number][P_letter_number] = 'S';
				}
				else {
					cout << RED << message << " - " << ORANGE << P_letter << " " << P_number << RESET;
					Sleep(800);
					ShowConsoleCursor(false);
					system("cls");
					drawA_I_title();
					drawN_P_GameBoard();
					cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
					P_table();
				}
			}
		}

		if (P_letter_number + 1 < 10)
		{
			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number + 1);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);
		}

		if (P_letter_number - 1 >= 0)
		{
			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number - 1);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);
		}

		if (P_number + 1 < 10)
		{
			P_number_to_str = to_string(P_number + 1);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);
		}

		if (P_number - 1 >= 0)
		{
			P_number_to_str = to_string(P_number - 1);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);
		}

		PvalidInput = false;

		while (!PvalidInput)
		{
			ShowConsoleCursor(false);
			system("cls");
			drawA_I_title();
			drawN_P_GameBoard();
			if (Pvalidas == false) cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
			Pvalidas = false;
			P_table();

			cout << endl;
			cout << BROWN << "SSSS" << GREY << " - COORDINATES" << RESET << endl << endl;
			cout << GREEN << "LETTER & NUMBER (Exp. A 2) " << RESET << endl;
			cout << GREY << "(2) ENTER coordinate of " << BROWN << "|SSSS| " << GREY << "ship: ";

			cout << RED;
			cin >> P_letter >> P_number;
			cout << RESET;

			P_letter = toupper(P_letter);

			if (P_letter == 'A') P_letter_number = 0;
			if (P_letter == 'B') P_letter_number = 1;
			if (P_letter == 'C') P_letter_number = 2;
			if (P_letter == 'D') P_letter_number = 3;
			if (P_letter == 'E') P_letter_number = 4;
			if (P_letter == 'F') P_letter_number = 5;
			if (P_letter == 'G') P_letter_number = 6;
			if (P_letter == 'H') P_letter_number = 7;
			if (P_letter == 'I') P_letter_number = 8;
			if (P_letter == 'J') P_letter_number = 9;

			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;

			if (P_can_c.find(P_letter_number_str) == P_can_c.end()) P_klaida_cant = true;

			try
			{
				if (Pkoordinate.find(P_letter) != Pkoordinate.end() && P_number >= 0 && P_number < 10) {
				if (P_klaida_cant == true) PvalidInput = false;
				else PvalidInput = true;
					Pvalidas = true;
					throw "You entered valid coordinates!";
				}
				else {
					Pvalidas = false;
					throw "Invalid coordinates, please try again.";
				}
			}

			catch (const char* message)
			{
				if (Pvalidas == true && P_klaida_cant == false) {
					cout << GREEN << message << RESET;
					Sleep(800);
					N_PlayerBoard_second[P_number][P_letter_number] = 'S';
				}
				else {
					if (P_klaida_cant == true) P_klaida_cant = false;
					cout << RED << message << " - " << ORANGE << P_letter << " " << P_number << RESET;
					Sleep(800);
					ShowConsoleCursor(false);
					system("cls");
					drawA_I_title();
					drawN_P_GameBoard();
					cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
					P_table();
				}
			}
		}

		P_can_c.clear();

		if (P_number - 1 >= 0)
		{
			P_number_to_str = to_string(P_number - 1);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);

			if (P_number + 2 < 10)
			{
				P_number_to_str = to_string(P_number + 2);
				P_letter_to_str = string(1, P_letter_number);
				P_letter_number_str = P_number_to_str + P_letter_to_str;
				P_can_c.insert(P_letter_number_str);
			}
		}

		if (P_letter_number + 1 < 10)
		{
			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number + 1);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);

			if (P_letter_number - 2 >= 0)
			{
				P_number_to_str = to_string(P_number);
				P_letter_to_str = string(1, P_letter_number - 2);
				P_letter_number_str = P_number_to_str + P_letter_to_str;
				P_can_c.insert(P_letter_number_str);
			}
		}

		if (P_letter_number - 1 >= 0)
		{
			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number - 1);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);

			if (P_letter_number + 2 < 10)
			{
				P_number_to_str = to_string(P_number);
				P_letter_to_str = string(1, P_letter_number + 2);
				P_letter_number_str = P_number_to_str + P_letter_to_str;
				P_can_c.insert(P_letter_number_str);
			}
		}

		if (P_number + 1 < 10)
		{
			P_number_to_str = to_string(P_number + 1);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);

			if (P_number - 2 >= 0)
			{
				P_number_to_str = to_string(P_number - 2);
				P_letter_to_str = string(1, P_letter_number);
				P_letter_number_str = P_number_to_str + P_letter_to_str;
				P_can_c.insert(P_letter_number_str);
			}
		}

		PvalidInput = false;

		while (!PvalidInput)
		{
			ShowConsoleCursor(false);
			system("cls");
			drawA_I_title();
			drawN_P_GameBoard();
			if (Pvalidas == false) cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
			Pvalidas = false;
			P_table();

			cout << endl;
			cout << BROWN << "SSSS" << GREY << " - COORDINATES" << RESET << endl << endl;
			cout << GREEN << "LETTER & NUMBER (Exp. A 2) " << RESET << endl;
			cout << GREY << "(3) ENTER coordinate of " << BROWN << "|SSSS| " << GREY << "ship: ";

			cout << RED;
			cin >> P_letter >> P_number;
			cout << RESET;

			P_letter = toupper(P_letter);

			if (P_letter == 'A') P_letter_number = 0;
			if (P_letter == 'B') P_letter_number = 1;
			if (P_letter == 'C') P_letter_number = 2;
			if (P_letter == 'D') P_letter_number = 3;
			if (P_letter == 'E') P_letter_number = 4;
			if (P_letter == 'F') P_letter_number = 5;
			if (P_letter == 'G') P_letter_number = 6;
			if (P_letter == 'H') P_letter_number = 7;
			if (P_letter == 'I') P_letter_number = 8;
			if (P_letter == 'J') P_letter_number = 9;

			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;

			if (P_can_c.find(P_letter_number_str) == P_can_c.end()) P_klaida_cant = true;

			try
			{
				if (Pkoordinate.find(P_letter) != Pkoordinate.end() && P_number >= 0 && P_number < 10) {
				if (P_klaida_cant == true) PvalidInput = false;
				else PvalidInput = true;
					Pvalidas = true;
					throw "You entered valid coordinates!";
				}
				else {
					Pvalidas = false;
					throw "Invalid coordinates, please try again.";
				}
			}

			catch (const char* message)
			{
				if (Pvalidas == true && P_klaida_cant == false) {
					cout << GREEN << message << RESET;
					Sleep(800);
					N_PlayerBoard_second[P_number][P_letter_number] = 'S';
				}
				else {
					if (P_klaida_cant == true) P_klaida_cant = false;
					cout << RED << message << " - " << ORANGE << P_letter << " " << P_number << RESET;
					Sleep(800);
					ShowConsoleCursor(false);
					system("cls");
					drawA_I_title();
					drawN_P_GameBoard();
					cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
					P_table();
				}
			}
		}

		P_can_c.clear();

		if (P_number - 1 >= 0)
		{
			P_number_to_str = to_string(P_number - 1);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);
			if (P_number + 3 < 10)
			{
				P_number_to_str = to_string(P_number + 3);
				P_letter_to_str = string(1, P_letter_number);
				P_letter_number_str = P_number_to_str + P_letter_to_str;
				P_can_c.insert(P_letter_number_str);
			}
		}

		if (P_letter_number + 1 < 10)
		{
			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number + 1);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);

			if (P_letter_number - 3 >= 0)
			{
				P_number_to_str = to_string(P_number);
				P_letter_to_str = string(1, P_letter_number - 3);
				P_letter_number_str = P_number_to_str + P_letter_to_str;
				P_can_c.insert(P_letter_number_str);
			}
		}


		if (P_letter_number - 1 >= 0)
		{
			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number - 1);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);

			if (P_letter_number + 3 < 10)
			{
				P_number_to_str = to_string(P_number);
				P_letter_to_str = string(1, P_letter_number + 3);
				P_letter_number_str = P_number_to_str + P_letter_to_str;
				P_can_c.insert(P_letter_number_str);
			}
		}

		if (P_number + 1 < 10)
		{
			P_number_to_str = to_string(P_number + 1);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);

			if (P_number - 3 >= 0)
			{
				P_number_to_str = to_string(P_number - 3);
				P_letter_to_str = string(1, P_letter_number);
				P_letter_number_str = P_number_to_str + P_letter_to_str;
				P_can_c.insert(P_letter_number_str);
			}
		}

		PvalidInput = false;

		while (!PvalidInput)
		{
			ShowConsoleCursor(false);
			system("cls");
			drawA_I_title();
			drawN_P_GameBoard();
			if (Pvalidas == false) cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
			Pvalidas = false;
			P_table();

			cout << endl;
			cout << BROWN << "SSSS" << GREY << " - COORDINATES" << RESET << endl << endl;
			cout << GREEN << "LETTER & NUMBER (Exp. A 2) " << RESET << endl;
			cout << GREY << "(4) ENTER coordinate of " << BROWN << "|SSSS| " << GREY << "ship: ";

			cout << RED;
			cin >> P_letter >> P_number;
			cout << RESET;

			P_letter = toupper(P_letter);

			if (P_letter == 'A') P_letter_number = 0;
			if (P_letter == 'B') P_letter_number = 1;
			if (P_letter == 'C') P_letter_number = 2;
			if (P_letter == 'D') P_letter_number = 3;
			if (P_letter == 'E') P_letter_number = 4;
			if (P_letter == 'F') P_letter_number = 5;
			if (P_letter == 'G') P_letter_number = 6;
			if (P_letter == 'H') P_letter_number = 7;
			if (P_letter == 'I') P_letter_number = 8;
			if (P_letter == 'J') P_letter_number = 9;

			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;

			if (P_can_c.find(P_letter_number_str) == P_can_c.end()) P_klaida_cant = true;

			try
			{
				if (Pkoordinate.find(P_letter) != Pkoordinate.end() && P_number >= 0 && P_number < 10) {
				if (P_klaida_cant == true) PvalidInput = false;
				else PvalidInput = true;
					Pvalidas = true;
					throw "You entered valid coordinates!";
				}
				else {
					Pvalidas = false;
					throw "Invalid coordinates, please try again.";
				}
			}

			catch (const char* message)
			{
				if (Pvalidas == true && P_klaida_cant == false) {
					Sleep(800);
					cout << GREEN << message << RESET;
					N_PlayerBoard_second[P_number][P_letter_number] = 'S';
				}
				else {
					if (P_klaida_cant == true) P_klaida_cant = false;
					cout << RED << message << " - " << ORANGE << P_letter << " " << P_number << RESET;
					Sleep(800);
					ShowConsoleCursor(false);
					system("cls");
					drawA_I_title();
					drawN_P_GameBoard();
					cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
					P_table();
				}
			}
		}

		P_can_c.clear();
		PvalidInput = false;

		SHIP_zone();
		ShowConsoleCursor(false);
		system("cls");
		drawA_I_title();
		drawN_P_GameBoard();
		P_table();

	}

	void generateN_P_3SHIP()
	{
		map <char, int> Pkoordinate = {
			{'A', 0}, {'A', 1}, {'A', 2}, {'A', 3}, {'A', 4}, {'A', 5}, {'A', 6}, {'A', 7}, {'A', 8}, {'A', 9},
			{'B', 0}, {'B', 1}, {'B', 2}, {'B', 3}, {'B', 4}, {'B', 5}, {'B', 6}, {'B', 7}, {'B', 8}, {'B', 9},
			{'C', 0}, {'C', 1}, {'C', 2}, {'C', 3}, {'C', 4}, {'C', 5}, {'C', 6}, {'C', 7}, {'C', 8}, {'C', 9},
			{'D', 0}, {'D', 1}, {'D', 2}, {'D', 3}, {'D', 4}, {'D', 5}, {'D', 6}, {'D', 7}, {'D', 8}, {'D', 9},
			{'E', 0}, {'E', 1}, {'E', 2}, {'E', 3}, {'E', 4}, {'E', 5}, {'E', 6}, {'E', 7}, {'E', 8}, {'E', 9},
			{'F', 0}, {'F', 1}, {'F', 2}, {'F', 3}, {'F', 4}, {'F', 5}, {'F', 6}, {'F', 7}, {'F', 8}, {'F', 9},
			{'G', 0}, {'G', 1}, {'G', 2}, {'G', 3}, {'G', 4}, {'G', 5}, {'G', 6}, {'G', 7}, {'G', 8}, {'G', 9},
			{'H', 0}, {'H', 1}, {'H', 2}, {'H', 3}, {'H', 4}, {'H', 5}, {'H', 6}, {'H', 7}, {'H', 8}, {'H', 9},
			{'I', 0}, {'I', 1}, {'I', 2}, {'I', 3}, {'I', 4}, {'I', 5}, {'I', 6}, {'I', 7}, {'I', 8}, {'I', 9},
			{'J', 0}, {'J', 1}, {'J', 2}, {'J', 3}, {'J', 4}, {'J', 5}, {'J', 6}, {'J', 7}, {'J', 8}, {'J', 9},
		};

		while (!PvalidInput)
		{
			cout << endl;
			cout << BROWN << "{1} SSS" << GREY << " - COORDINATES" << RESET << endl << endl;
			cout << GREEN << "LETTER & NUMBER (Exp. A 2) " << RESET << endl;
			cout << GREY << "(1) ENTER coordinate of " << BROWN << "|SSS| " << GREY << "ship: ";

			cout << RED;

			cin >> P_letter >> P_number;
			cout << RESET;

			P_letter = toupper(P_letter);

			if (P_letter == 'A') P_letter_number = 0;
			if (P_letter == 'B') P_letter_number = 1;
			if (P_letter == 'C') P_letter_number = 2;
			if (P_letter == 'D') P_letter_number = 3;
			if (P_letter == 'E') P_letter_number = 4;
			if (P_letter == 'F') P_letter_number = 5;
			if (P_letter == 'G') P_letter_number = 6;
			if (P_letter == 'H') P_letter_number = 7;
			if (P_letter == 'I') P_letter_number = 8;
			if (P_letter == 'J') P_letter_number = 9;

			try
			{
				if (Pkoordinate.find(P_letter) != Pkoordinate.end() && P_number >= 0 && P_number < 10 && N_PlayerBoard_second[P_number][P_letter_number] != 'S' && N_PlayerBoard_second[P_number][P_letter_number] != '-') {
					PvalidInput = true;
					Pvalidas = true;
					throw "You entered valid coordinates!";
				}
				else {
					Pvalidas = false;
					throw "Invalid coordinates, please try again.";
				}
				
			}

			catch (const char* message)
			{
				if (Pvalidas == true) {
					cout << GREEN << message << RESET;
					Sleep(800);
					N_PlayerBoard_second[P_number][P_letter_number] = 'S';
				}
				else {
					cout << RED << message << " - " << ORANGE << P_letter << " " << P_number << RESET;
					Sleep(800);
					ShowConsoleCursor(false);
					system("cls");
					drawA_I_title();
					drawN_P_GameBoard();
					cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
					P_table();
				}
			}
		}

		if (P_letter_number + 1 < 10)
		{
			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number + 1);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);
		}

		if (P_letter_number - 1 >= 0)
		{
			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number - 1);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);
		}

		if (P_number + 1 < 10)
		{
			P_number_to_str = to_string(P_number + 1);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);
		}

		if (P_number - 1 >= 0)
		{
			P_number_to_str = to_string(P_number - 1);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);
		}

		PvalidInput = false;

		while (!PvalidInput)
		{
			ShowConsoleCursor(false);
			system("cls");
			drawA_I_title();
			drawN_P_GameBoard();
			if (Pvalidas == false) cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
			Pvalidas = false;
			P_table();

			cout << endl;
			cout << BROWN << "{1} SSS" << GREY << " - COORDINATES" << RESET << endl << endl;
			cout << GREEN << "LETTER & NUMBER (Exp. A 2) " << RESET << endl;
			cout << GREY << "(2) ENTER coordinate of " << BROWN << "|SSS| " << GREY << "ship: ";

			cout << RED;
			cin >> P_letter >> P_number;
			cout << RESET;

			P_letter = toupper(P_letter);

			if (P_letter == 'A') P_letter_number = 0;
			if (P_letter == 'B') P_letter_number = 1;
			if (P_letter == 'C') P_letter_number = 2;
			if (P_letter == 'D') P_letter_number = 3;
			if (P_letter == 'E') P_letter_number = 4;
			if (P_letter == 'F') P_letter_number = 5;
			if (P_letter == 'G') P_letter_number = 6;
			if (P_letter == 'H') P_letter_number = 7;
			if (P_letter == 'I') P_letter_number = 8;
			if (P_letter == 'J') P_letter_number = 9;

			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;

			if (P_can_c.find(P_letter_number_str) == P_can_c.end()) P_klaida_cant = true;

			try
			{
				if (Pkoordinate.find(P_letter) != Pkoordinate.end() && P_number >= 0 && P_number < 10 && N_PlayerBoard_second[P_number][P_letter_number] != 'S' && N_PlayerBoard_second[P_number][P_letter_number] != '-') {
					if (P_klaida_cant == true) PvalidInput = false;
					else PvalidInput = true;
					Pvalidas = true;
					throw "You entered valid coordinates!";
				}
				else {
					Pvalidas = false;
					throw "Invalid coordinates, please try again.";
				}
			}

			catch (const char* message)
			{
				if (Pvalidas == true && P_klaida_cant == false) {
					cout << GREEN << message << RESET;
					Sleep(800);
					N_PlayerBoard_second[P_number][P_letter_number] = 'S';
				}
				else {
					if (P_klaida_cant == true) P_klaida_cant = false;
					cout << RED << message << " - " << ORANGE << P_letter << " " << P_number << RESET;
					Sleep(800);
					ShowConsoleCursor(false);
					system("cls");
					drawA_I_title();
					drawN_P_GameBoard();
					cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
					P_table();
				}
			}
		}

		P_can_c.clear();

		if (P_number - 1 >= 0)
		{
			P_number_to_str = to_string(P_number - 1);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);

			if (P_number + 2 < 10)
			{
				P_number_to_str = to_string(P_number + 2);
				P_letter_to_str = string(1, P_letter_number);
				P_letter_number_str = P_number_to_str + P_letter_to_str;
				P_can_c.insert(P_letter_number_str);
			}
		}

		if (P_letter_number + 1 < 10)
		{
			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number + 1);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);

			if (P_letter_number - 2 >= 0)
			{
				P_number_to_str = to_string(P_number);
				P_letter_to_str = string(1, P_letter_number - 2);
				P_letter_number_str = P_number_to_str + P_letter_to_str;
				P_can_c.insert(P_letter_number_str);
			}
		}

		if (P_letter_number - 1 >= 0)
		{
			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number - 1);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);

			if (P_letter_number + 2 < 10)
			{
				P_number_to_str = to_string(P_number);
				P_letter_to_str = string(1, P_letter_number + 2);
				P_letter_number_str = P_number_to_str + P_letter_to_str;
				P_can_c.insert(P_letter_number_str);
			}
		}

		if (P_number + 1 < 10)
		{
			P_number_to_str = to_string(P_number + 1);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);

			if (P_number - 2 >= 0)
			{
				P_number_to_str = to_string(P_number - 2);
				P_letter_to_str = string(1, P_letter_number);
				P_letter_number_str = P_number_to_str + P_letter_to_str;
				P_can_c.insert(P_letter_number_str);
			}
		}

		PvalidInput = false;

		while (!PvalidInput)
		{
			ShowConsoleCursor(false);
			system("cls");
			drawA_I_title();
			drawN_P_GameBoard();
			if (Pvalidas == false) cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
			Pvalidas = false;
			P_table();

			cout << endl;
			cout << BROWN << "{1} SSS" << GREY << " - COORDINATES" << RESET << endl << endl;
			cout << GREEN << "LETTER & NUMBER (Exp. A 2) " << RESET << endl;
			cout << GREY << "(3) ENTER coordinate of " << BROWN << "|SSS| " << GREY << "ship: ";

			cout << RED;
			cin >> P_letter >> P_number;
			cout << RESET;

			P_letter = toupper(P_letter);

			if (P_letter == 'A') P_letter_number = 0;
			if (P_letter == 'B') P_letter_number = 1;
			if (P_letter == 'C') P_letter_number = 2;
			if (P_letter == 'D') P_letter_number = 3;
			if (P_letter == 'E') P_letter_number = 4;
			if (P_letter == 'F') P_letter_number = 5;
			if (P_letter == 'G') P_letter_number = 6;
			if (P_letter == 'H') P_letter_number = 7;
			if (P_letter == 'I') P_letter_number = 8;
			if (P_letter == 'J') P_letter_number = 9;

			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;

			if (P_can_c.find(P_letter_number_str) == P_can_c.end()) P_klaida_cant = true;

			try
			{
				if (Pkoordinate.find(P_letter) != Pkoordinate.end() && P_number >= 0 && P_number < 10 && N_PlayerBoard_second[P_number][P_letter_number] != 'S' && N_PlayerBoard_second[P_number][P_letter_number] != '-') {
					if (P_klaida_cant == true) PvalidInput = false;
					else PvalidInput = true;
					Pvalidas = true;
					throw "You entered valid coordinates!";
				}
				else {
					Pvalidas = false;
					throw "Invalid coordinates, please try again.";
				}
			}

			catch (const char* message)
			{
				if (Pvalidas == true && P_klaida_cant == false) {
					cout << GREEN << message << RESET;
					Sleep(800);
					N_PlayerBoard_second[P_number][P_letter_number] = 'S';
				}
				else {
					if (P_klaida_cant == true) P_klaida_cant = false;
					cout << RED << message << " - " << ORANGE << P_letter << " " << P_number << RESET;
					Sleep(800);
					ShowConsoleCursor(false);
					system("cls");
					drawA_I_title();
					drawN_P_GameBoard();
					cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
					P_table();
				}
			}
		}

		P_can_c.clear();
		PvalidInput = false;

		SHIP_zone();
		ShowConsoleCursor(false);
		system("cls");
		drawA_I_title();
		drawN_P_GameBoard();
		P_table();

		while (!PvalidInput)
		{
			cout << endl;
			cout << BROWN << "{1} SSS" << GREY << " - COORDINATES" << RESET << endl << endl;
			cout << GREEN << "LETTER & NUMBER (Exp. A 2) " << RESET << endl;
			cout << GREY << "(1) ENTER coordinate of " << BROWN << "|SSS| " << GREY << "ship: ";

			cout << RED;
			cin >> P_letter >> P_number;
			cout << RESET;

			P_letter = toupper(P_letter);

			if (P_letter == 'A') P_letter_number = 0;
			if (P_letter == 'B') P_letter_number = 1;
			if (P_letter == 'C') P_letter_number = 2;
			if (P_letter == 'D') P_letter_number = 3;
			if (P_letter == 'E') P_letter_number = 4;
			if (P_letter == 'F') P_letter_number = 5;
			if (P_letter == 'G') P_letter_number = 6;
			if (P_letter == 'H') P_letter_number = 7;
			if (P_letter == 'I') P_letter_number = 8;
			if (P_letter == 'J') P_letter_number = 9;

			try
			{
				if (Pkoordinate.find(P_letter) != Pkoordinate.end() && P_number >= 0 && P_number < 10 && N_PlayerBoard_second[P_number][P_letter_number] != 'S' && N_PlayerBoard_second[P_number][P_letter_number] != '-') {
					PvalidInput = true;
					Pvalidas = true;
					throw "You entered valid coordinates!";
				}
				else {
					Pvalidas = false;
					throw "Invalid coordinates, please try again.";
				}

			}

			catch (const char* message)
			{
				if (Pvalidas == true) {
					cout << GREEN << message << RESET;
					Sleep(800);
					N_PlayerBoard_second[P_number][P_letter_number] = 'S';
				}
				else {
					cout << RED << message << " - " << ORANGE << P_letter << " " << P_number << RESET;
					Sleep(800);
					ShowConsoleCursor(false);
					system("cls");
					drawA_I_title();
					drawN_P_GameBoard();
					cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
					P_table();
				}
			}
		}

		if (P_letter_number + 1 < 10)
		{
			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number + 1);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);
		}

		if (P_letter_number - 1 >= 0)
		{
			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number - 1);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);
		}

		if (P_number + 1 < 10)
		{
			P_number_to_str = to_string(P_number + 1);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);
		}

		if (P_number - 1 >= 0)
		{
			P_number_to_str = to_string(P_number - 1);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);
		}

		PvalidInput = false;

		while (!PvalidInput)
		{
			ShowConsoleCursor(false);
			system("cls");
			drawA_I_title();
			drawN_P_GameBoard();
			if (Pvalidas == false) cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
			Pvalidas = false;
			P_table();

			cout << endl;
			cout << BROWN << "{2} SSS" << GREY << " - COORDINATES" << RESET << endl << endl;
			cout << GREEN << "LETTER & NUMBER (Exp. A 2) " << RESET << endl;
			cout << GREY << "(2) ENTER coordinate of " << BROWN << "|SSS| " << GREY << "ship: ";

			cout << RED;
			cin >> P_letter >> P_number;
			cout << RESET;

			P_letter = toupper(P_letter);

			if (P_letter == 'A') P_letter_number = 0;
			if (P_letter == 'B') P_letter_number = 1;
			if (P_letter == 'C') P_letter_number = 2;
			if (P_letter == 'D') P_letter_number = 3;
			if (P_letter == 'E') P_letter_number = 4;
			if (P_letter == 'F') P_letter_number = 5;
			if (P_letter == 'G') P_letter_number = 6;
			if (P_letter == 'H') P_letter_number = 7;
			if (P_letter == 'I') P_letter_number = 8;
			if (P_letter == 'J') P_letter_number = 9;

			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;

			if (P_can_c.find(P_letter_number_str) == P_can_c.end()) P_klaida_cant = true;

			try
			{
				if (Pkoordinate.find(P_letter) != Pkoordinate.end() && P_number >= 0 && P_number < 10 && N_PlayerBoard_second[P_number][P_letter_number] != 'S' && N_PlayerBoard_second[P_number][P_letter_number] != '-') {
					if (P_klaida_cant == true) PvalidInput = false;
					else PvalidInput = true;
					Pvalidas = true;
					throw "You entered valid coordinates!";
				}
				else {
					Pvalidas = false;
					throw "Invalid coordinates, please try again.";
				}
			}

			catch (const char* message)
			{
				if (Pvalidas == true && P_klaida_cant == false) {
					cout << GREEN << message << RESET;
					Sleep(800);
					N_PlayerBoard_second[P_number][P_letter_number] = 'S';
				}
				else {
					if (P_klaida_cant == true) P_klaida_cant = false;
					cout << RED << message << " - " << ORANGE << P_letter << " " << P_number << RESET;
					Sleep(800);
					ShowConsoleCursor(false);
					system("cls");
					drawA_I_title();
					drawN_P_GameBoard();
					cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
					P_table();
				}
			}
		}

		P_can_c.clear();

		if (P_number - 1 >= 0)
		{
			P_number_to_str = to_string(P_number - 1);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);

			if (P_number + 2 < 10)
			{
				P_number_to_str = to_string(P_number + 2);
				P_letter_to_str = string(1, P_letter_number);
				P_letter_number_str = P_number_to_str + P_letter_to_str;
				P_can_c.insert(P_letter_number_str);
			}
		}

		if (P_letter_number + 1 < 10)
		{
			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number + 1);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);

			if (P_letter_number - 2 >= 0)
			{
				P_number_to_str = to_string(P_number);
				P_letter_to_str = string(1, P_letter_number - 2);
				P_letter_number_str = P_number_to_str + P_letter_to_str;
				P_can_c.insert(P_letter_number_str);
			}
		}

		if (P_letter_number - 1 >= 0)
		{
			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number - 1);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);

			if (P_letter_number + 2 < 10)
			{
				P_number_to_str = to_string(P_number);
				P_letter_to_str = string(1, P_letter_number + 2);
				P_letter_number_str = P_number_to_str + P_letter_to_str;
				P_can_c.insert(P_letter_number_str);
			}
		}

		if (P_number + 1 < 10)
		{
			P_number_to_str = to_string(P_number + 1);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;
			P_can_c.insert(P_letter_number_str);

			if (P_number - 2 >= 0)
			{
				P_number_to_str = to_string(P_number - 2);
				P_letter_to_str = string(1, P_letter_number);
				P_letter_number_str = P_number_to_str + P_letter_to_str;
				P_can_c.insert(P_letter_number_str);
			}
		}

		PvalidInput = false;

		while (!PvalidInput)
		{
			ShowConsoleCursor(false);
			system("cls");
			drawA_I_title();
			drawN_P_GameBoard();
			if (Pvalidas == false) cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
			Pvalidas = false;
			P_table();

			cout << endl;
			cout << BROWN << "{2} SSS" << GREY << " - COORDINATES" << RESET << endl << endl;
			cout << GREEN << "LETTER & NUMBER (Exp. A 2) " << RESET << endl;
			cout << GREY << "(3) ENTER coordinate of " << BROWN << "|SSS| " << GREY << "ship: ";

			cout << RED;
			cin >> P_letter >> P_number;
			cout << RESET;

			P_letter = toupper(P_letter);

			if (P_letter == 'A') P_letter_number = 0;
			if (P_letter == 'B') P_letter_number = 1;
			if (P_letter == 'C') P_letter_number = 2;
			if (P_letter == 'D') P_letter_number = 3;
			if (P_letter == 'E') P_letter_number = 4;
			if (P_letter == 'F') P_letter_number = 5;
			if (P_letter == 'G') P_letter_number = 6;
			if (P_letter == 'H') P_letter_number = 7;
			if (P_letter == 'I') P_letter_number = 8;
			if (P_letter == 'J') P_letter_number = 9;

			P_number_to_str = to_string(P_number);
			P_letter_to_str = string(1, P_letter_number);
			P_letter_number_str = P_number_to_str + P_letter_to_str;

			if (P_can_c.find(P_letter_number_str) == P_can_c.end()) P_klaida_cant = true;

			try
			{
				if (Pkoordinate.find(P_letter) != Pkoordinate.end() && P_number >= 0 && P_number < 10 && N_PlayerBoard_second[P_number][P_letter_number] != 'S' && N_PlayerBoard_second[P_number][P_letter_number] != '-') {
					if (P_klaida_cant == true) PvalidInput = false;
					else PvalidInput = true;
					Pvalidas = true;
					throw "You entered valid coordinates!";
				}
				else {
					Pvalidas = false;
					throw "Invalid coordinates, please try again.";
				}
			}

			catch (const char* message)
			{
				if (Pvalidas == true && P_klaida_cant == false) {
					cout << GREEN << message << RESET;
					Sleep(800);
					N_PlayerBoard_second[P_number][P_letter_number] = 'S';
				}
				else {
					if (P_klaida_cant == true) P_klaida_cant = false;
					cout << RED << message << " - " << ORANGE << P_letter << " " << P_number << RESET;
					Sleep(800);
					ShowConsoleCursor(false);
					system("cls");
					drawA_I_title();
					drawN_P_GameBoard();
					cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
					P_table();
				}
			}
		}

		P_can_c.clear();
		PvalidInput = false;

		SHIP_zone();
		ShowConsoleCursor(false);
		system("cls");
		drawA_I_title();
		drawN_P_GameBoard();
		P_table();

	}

	void generateN_P_2SHIP()
	{
		map <char, int> Pkoordinate = {
			{'A', 0}, {'A', 1}, {'A', 2}, {'A', 3}, {'A', 4}, {'A', 5}, {'A', 6}, {'A', 7}, {'A', 8}, {'A', 9},
			{'B', 0}, {'B', 1}, {'B', 2}, {'B', 3}, {'B', 4}, {'B', 5}, {'B', 6}, {'B', 7}, {'B', 8}, {'B', 9},
			{'C', 0}, {'C', 1}, {'C', 2}, {'C', 3}, {'C', 4}, {'C', 5}, {'C', 6}, {'C', 7}, {'C', 8}, {'C', 9},
			{'D', 0}, {'D', 1}, {'D', 2}, {'D', 3}, {'D', 4}, {'D', 5}, {'D', 6}, {'D', 7}, {'D', 8}, {'D', 9},
			{'E', 0}, {'E', 1}, {'E', 2}, {'E', 3}, {'E', 4}, {'E', 5}, {'E', 6}, {'E', 7}, {'E', 8}, {'E', 9},
			{'F', 0}, {'F', 1}, {'F', 2}, {'F', 3}, {'F', 4}, {'F', 5}, {'F', 6}, {'F', 7}, {'F', 8}, {'F', 9},
			{'G', 0}, {'G', 1}, {'G', 2}, {'G', 3}, {'G', 4}, {'G', 5}, {'G', 6}, {'G', 7}, {'G', 8}, {'G', 9},
			{'H', 0}, {'H', 1}, {'H', 2}, {'H', 3}, {'H', 4}, {'H', 5}, {'H', 6}, {'H', 7}, {'H', 8}, {'H', 9},
			{'I', 0}, {'I', 1}, {'I', 2}, {'I', 3}, {'I', 4}, {'I', 5}, {'I', 6}, {'I', 7}, {'I', 8}, {'I', 9},
			{'J', 0}, {'J', 1}, {'J', 2}, {'J', 3}, {'J', 4}, {'J', 5}, {'J', 6}, {'J', 7}, {'J', 8}, {'J', 9},
		};


		for (int i = 1; i < 4; i++)
		{
				while (!PvalidInput)
				{
					cout << endl;
					cout << BROWN << "{" << i <<"} SS" << GREY << " - COORDINATES" << RESET << endl << endl;
					cout << GREEN << "LETTER & NUMBER (Exp. A 2) " << RESET << endl;
					cout << GREY << "(1) ENTER coordinate of" << BROWN << " |SS| " << GREY << "ship: ";

					cout << RED;

					cin >> P_letter >> P_number;
					cout << RESET;

					P_letter = toupper(P_letter);

					if (P_letter == 'A') P_letter_number = 0;
					if (P_letter == 'B') P_letter_number = 1;
					if (P_letter == 'C') P_letter_number = 2;
					if (P_letter == 'D') P_letter_number = 3;
					if (P_letter == 'E') P_letter_number = 4;
					if (P_letter == 'F') P_letter_number = 5;
					if (P_letter == 'G') P_letter_number = 6;
					if (P_letter == 'H') P_letter_number = 7;
					if (P_letter == 'I') P_letter_number = 8;
					if (P_letter == 'J') P_letter_number = 9;

					try
					{
						if (Pkoordinate.find(P_letter) != Pkoordinate.end() && P_number >= 0 && P_number < 10 && N_PlayerBoard_second[P_number][P_letter_number] != 'S' && N_PlayerBoard_second[P_number][P_letter_number] != '-') {
							PvalidInput = true;
							Pvalidas = true;
							throw "You entered valid coordinates!";
						}
						else {
							Pvalidas = false;
							throw "Invalid coordinates, please try again.";
						}

					}

					catch (const char* message)
					{
						if (Pvalidas == true) {
							cout << GREEN << message << RESET;
							Sleep(800);
							N_PlayerBoard_second[P_number][P_letter_number] = 'S';
						}
						else {
							cout << RED << message << " - " << ORANGE << P_letter << " " << P_number << RESET;
							Sleep(800);
							ShowConsoleCursor(false);
							system("cls");
							drawA_I_title();
							drawN_P_GameBoard();
							cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
							P_table();
						}
					}
				}

				if (P_letter_number + 1 < 10)
				{
					P_number_to_str = to_string(P_number);
					P_letter_to_str = string(1, P_letter_number + 1);
					P_letter_number_str = P_number_to_str + P_letter_to_str;
					P_can_c.insert(P_letter_number_str);
				}

				if (P_letter_number - 1 >= 0)
				{
					P_number_to_str = to_string(P_number);
					P_letter_to_str = string(1, P_letter_number - 1);
					P_letter_number_str = P_number_to_str + P_letter_to_str;
					P_can_c.insert(P_letter_number_str);
				}

				if (P_number + 1 < 10)
				{
					P_number_to_str = to_string(P_number + 1);
					P_letter_to_str = string(1, P_letter_number);
					P_letter_number_str = P_number_to_str + P_letter_to_str;
					P_can_c.insert(P_letter_number_str);
				}

				if (P_number - 1 >= 0)
				{
					P_number_to_str = to_string(P_number - 1);
					P_letter_to_str = string(1, P_letter_number);
					P_letter_number_str = P_number_to_str + P_letter_to_str;
					P_can_c.insert(P_letter_number_str);
				}

				PvalidInput = false;

				while (!PvalidInput)
				{
					ShowConsoleCursor(false);
					system("cls");
					drawA_I_title();
					drawN_P_GameBoard();
					if (Pvalidas == false) cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
					Pvalidas = false;
					P_table();

					cout << endl;
					cout << BROWN << "{1} SS" << GREY << " - COORDINATES" << RESET << endl << endl;
					cout << GREEN << "LETTER & NUMBER (Exp. A 2) " << RESET << endl;
					cout << GREY << "(2) ENTER coordinate of" << BROWN << "|SS| " << GREY << "ship: ";

					cout << RED;
					cin >> P_letter >> P_number;
					cout << RESET;

					P_letter = toupper(P_letter);

					if (P_letter == 'A') P_letter_number = 0;
					if (P_letter == 'B') P_letter_number = 1;
					if (P_letter == 'C') P_letter_number = 2;
					if (P_letter == 'D') P_letter_number = 3;
					if (P_letter == 'E') P_letter_number = 4;
					if (P_letter == 'F') P_letter_number = 5;
					if (P_letter == 'G') P_letter_number = 6;
					if (P_letter == 'H') P_letter_number = 7;
					if (P_letter == 'I') P_letter_number = 8;
					if (P_letter == 'J') P_letter_number = 9;

					P_number_to_str = to_string(P_number);
					P_letter_to_str = string(1, P_letter_number);
					P_letter_number_str = P_number_to_str + P_letter_to_str;

					if (P_can_c.find(P_letter_number_str) == P_can_c.end()) P_klaida_cant = true;

					try
					{
						if (Pkoordinate.find(P_letter) != Pkoordinate.end() && P_number >= 0 && P_number < 10 && N_PlayerBoard_second[P_number][P_letter_number] != 'S' && N_PlayerBoard_second[P_number][P_letter_number] != '-') {
							if (P_klaida_cant == true) PvalidInput = false;
							else PvalidInput = true;
							Pvalidas = true;
							throw "You entered valid coordinates!";
						}
						else {
							Pvalidas = false;
							throw "Invalid coordinates, please try again.";
						}
					}

					catch (const char* message)
					{
						if (Pvalidas == true && P_klaida_cant == false) {
							cout << GREEN << message << RESET;
							Sleep(800);
							N_PlayerBoard_second[P_number][P_letter_number] = 'S';
						}
						else {
							if (P_klaida_cant == true) P_klaida_cant = false;
							cout << RED << message << " - " << ORANGE << P_letter << " " << P_number << RESET;
							Sleep(800);
							ShowConsoleCursor(false);
							system("cls");
							drawA_I_title();
							drawN_P_GameBoard();
							cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
							P_table();
						}
					}
				}

				P_can_c.clear();
				PvalidInput = false;

				SHIP_zone();
				ShowConsoleCursor(false);
				system("cls");
				drawA_I_title();
				drawN_P_GameBoard();
				P_table();
			}
		
	}

	void generateN_P_1SHIP()
	{
		map <char, int> Pkoordinate = {
			{'A', 0}, {'A', 1}, {'A', 2}, {'A', 3}, {'A', 4}, {'A', 5}, {'A', 6}, {'A', 7}, {'A', 8}, {'A', 9},
			{'B', 0}, {'B', 1}, {'B', 2}, {'B', 3}, {'B', 4}, {'B', 5}, {'B', 6}, {'B', 7}, {'B', 8}, {'B', 9},
			{'C', 0}, {'C', 1}, {'C', 2}, {'C', 3}, {'C', 4}, {'C', 5}, {'C', 6}, {'C', 7}, {'C', 8}, {'C', 9},
			{'D', 0}, {'D', 1}, {'D', 2}, {'D', 3}, {'D', 4}, {'D', 5}, {'D', 6}, {'D', 7}, {'D', 8}, {'D', 9},
			{'E', 0}, {'E', 1}, {'E', 2}, {'E', 3}, {'E', 4}, {'E', 5}, {'E', 6}, {'E', 7}, {'E', 8}, {'E', 9},
			{'F', 0}, {'F', 1}, {'F', 2}, {'F', 3}, {'F', 4}, {'F', 5}, {'F', 6}, {'F', 7}, {'F', 8}, {'F', 9},
			{'G', 0}, {'G', 1}, {'G', 2}, {'G', 3}, {'G', 4}, {'G', 5}, {'G', 6}, {'G', 7}, {'G', 8}, {'G', 9},
			{'H', 0}, {'H', 1}, {'H', 2}, {'H', 3}, {'H', 4}, {'H', 5}, {'H', 6}, {'H', 7}, {'H', 8}, {'H', 9},
			{'I', 0}, {'I', 1}, {'I', 2}, {'I', 3}, {'I', 4}, {'I', 5}, {'I', 6}, {'I', 7}, {'I', 8}, {'I', 9},
			{'J', 0}, {'J', 1}, {'J', 2}, {'J', 3}, {'J', 4}, {'J', 5}, {'J', 6}, {'J', 7}, {'J', 8}, {'J', 9},
		};


		for (int i = 1; i < 5; i++)
		{
			while (!PvalidInput)
			{
				cout << endl;
				cout << BROWN << "{" << i << "} S" << GREY << " - COORDINATES" << RESET << endl << endl;
				cout << GREEN << "LETTER & NUMBER (Exp. A 2) " << RESET << endl;
				cout << GREY << "(1) ENTER coordinate of" << BROWN << " |S| " << GREY << "ship: ";

				cout << RED;

				cin >> P_letter >> P_number;
				cout << RESET;

				P_letter = toupper(P_letter);

				if (P_letter == 'A') P_letter_number = 0;
				if (P_letter == 'B') P_letter_number = 1;
				if (P_letter == 'C') P_letter_number = 2;
				if (P_letter == 'D') P_letter_number = 3;
				if (P_letter == 'E') P_letter_number = 4;
				if (P_letter == 'F') P_letter_number = 5;
				if (P_letter == 'G') P_letter_number = 6;
				if (P_letter == 'H') P_letter_number = 7;
				if (P_letter == 'I') P_letter_number = 8;
				if (P_letter == 'J') P_letter_number = 9;

				try
				{
					if (Pkoordinate.find(P_letter) != Pkoordinate.end() && P_number >= 0 && P_number < 10 && N_PlayerBoard_second[P_number][P_letter_number] != 'S' && N_PlayerBoard_second[P_number][P_letter_number] != '-') {
						PvalidInput = true;
						Pvalidas = true;
						throw "You entered valid coordinates!";
					}
					else {
						Pvalidas = false;
						throw "Invalid coordinates, please try again.";
					}

				}

				catch (const char* message)
				{
					if (Pvalidas == true) {
						cout << GREEN << message << RESET;
						Sleep(800);
						N_PlayerBoard_second[P_number][P_letter_number] = 'S';
					}
					else {
						cout << RED << message << " - " << ORANGE << P_letter << " " << P_number << RESET;
						Sleep(800);
						ShowConsoleCursor(false);
						system("cls");
						drawA_I_title();
						drawN_P_GameBoard();
						cout << GREY << "INVALID COORDINATE" << RESET << endl << endl;
						P_table();
					}
				}
			}

			P_can_c.clear();
			PvalidInput = false;

			SHIP_zone();
			ShowConsoleCursor(false);
			system("cls");
			drawA_I_title();
			drawN_P_GameBoard();
			P_table();
		}
	}

	const void P_table()
	{
		cout << BLUE << "Last coordinate: " << P_letter << " " << P_number << RESET << endl;
		cout << BLUE << "Remaining ships to place: " << left_ships << RESET << endl;
	}

	void SHIP_zone()
	{
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (N_PlayerBoard_second[i][j] == 'S' && i > 0 && N_PlayerBoard_second[i - 1][j] == '#') N_PlayerBoard_second[i - 1][j] = '-';
				if (N_PlayerBoard_second[i][j] == 'S' && i < 9 && N_PlayerBoard_second[i + 1][j] == '#') N_PlayerBoard_second[i + 1][j] = '-';
				if (N_PlayerBoard_second[i][j] == 'S' && j > 0 && N_PlayerBoard_second[i][j - 1] == '#') N_PlayerBoard_second[i][j - 1] = '-';
				if (N_PlayerBoard_second[i][j] == 'S' && j < 9 && N_PlayerBoard_second[i][j + 1] == '#') N_PlayerBoard_second[i][j + 1] = '-';

				if (N_PlayerBoard_second[i][j] == 'S' && (i > 0 && j > 0) && N_PlayerBoard_second[i - 1][j - 1] == '#') N_PlayerBoard_second[i - 1][j - 1] = '-';
				if (N_PlayerBoard_second[i][j] == 'S' && (i < 9 && j > 0) && N_PlayerBoard_second[i + 1][j - 1] == '#') N_PlayerBoard_second[i + 1][j - 1] = '-';
				if (N_PlayerBoard_second[i][j] == 'S' && (i > 0 && j < 9) && N_PlayerBoard_second[i - 1][j + 1] == '#') N_PlayerBoard_second[i - 1][j + 1] = '-';
				if (N_PlayerBoard_second[i][j] == 'S' && (i < 9 && j < 9) && N_PlayerBoard_second[i + 1][j + 1] == '#') N_PlayerBoard_second[i + 1][j + 1] = '-';
			}
		}
		left_ships--;
	}
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	void drawA_I_GameBoard()
	{
		system("cls");

		drawA_I_title();
		cout << GREY << "                     " << " |" << RED << "AI's" << GREY << "| GAMEBOARD:                      " << RESET << endl << endl;

		cout << GREY << "                    *********************" << RESET << endl;
		cout << GREY << "                  * " << ORANGE << "x" << RESET << YELLOW << " A B C D E F G H I J" << GREY << " * " << RESET << endl;

		for (int i = 0; i < 10; i++)
		{
			cout << GREY << "                  * " << YELLOW << i << RESET << " ";
			for (int j = 0; j < 10; j++)
			{
				if (AI_PlayerBoard[i][j] == 'O') cout << CYAN << AI_PlayerBoard[i][j] << RESET << " ";
				if (AI_PlayerBoard[i][j] == 'X') cout << RED << AI_PlayerBoard[i][j] << RESET << " ";
				if (AI_PlayerBoard[i][j] == '#') cout << BLUE << AI_PlayerBoard[i][j] << RESET << " ";
			}
			cout << GREY << "*" << RESET << endl;
		}
		cout << GREY << "                    *********************" << RESET << endl;
		cout << endl;
	}

	void A_I_shooting()
	{

		while (A_I_ships_count != 0)
		{
			drawA_I_GameBoard();

			A_I_shooting_stats();

			srand(static_cast<unsigned int>(time(0)));

			do
			{
				A_X_l = rand() % A_GameBoardSize;
				A_Y_n = rand() % A_GameBoardSize;
			} while (AI_PlayerBoard[A_Y_n][A_X_l] == 'O' || AI_PlayerBoard[A_Y_n][A_X_l] == 'X');

			if (N_PlayerBoard_second[A_Y_n][A_X_l] == 'S')
			{
				A_I_ships_count--;
				A_I_pataike();
			}
			else {
				AI_PlayerBoard[A_Y_n][A_X_l] = 'O';
				cout << RED << "MISSED shot! " << RESET << endl << endl;
			}

			A_number = A_Y_n;

			if (A_X_l == 0) A_letter = 'A';
			if (A_X_l == 1) A_letter = 'B';
			if (A_X_l == 2) A_letter = 'C';
			if (A_X_l == 3) A_letter = 'D';
			if (A_X_l == 4) A_letter = 'E';
			if (A_X_l == 5) A_letter = 'F';
			if (A_X_l == 6) A_letter = 'G';
			if (A_X_l == 7) A_letter = 'H';
			if (A_X_l == 8) A_letter = 'I';
			if (A_X_l == 9) A_letter = 'J';

			cout << GREY << "AI COORDINATE: " << RED << A_letter << " " << A_number << RESET << endl;
			Sleep(2000);

			A_I_steps++;

			drawA_I_GameBoard();
		}

	}

	void A_I_pataike()
	{

		drawA_I_GameBoard();
		A_I_shooting_stats();
		A_I_steps++;

		A_number = A_Y_n;

		if (A_X_l == 0) A_letter = 'A';
		if (A_X_l == 1) A_letter = 'B';
		if (A_X_l == 2) A_letter = 'C';
		if (A_X_l == 3) A_letter = 'D';
		if (A_X_l == 4) A_letter = 'E';
		if (A_X_l == 5) A_letter = 'F';
		if (A_X_l == 6) A_letter = 'G';
		if (A_X_l == 7) A_letter = 'H';
		if (A_X_l == 8) A_letter = 'I';
		if (A_X_l == 9) A_letter = 'J';


		AI_PlayerBoard[A_Y_n][A_X_l] = 'X';
		N_PlayerBoard_second[A_Y_n][A_X_l] = 'U';

		cout << GREEN << "HIT shot! " << RESET << endl << endl;

		cout << GREY << "AI COORDINATE: " << RED << A_letter << " " << A_number << RESET << endl;
		Sleep(2000);

		drawA_I_GameBoard();


		eile = false;
		stulpelis = false;

		eile_desine = false;
		stulpelis_apacia = false;

		eile_kaire = false;
		stulpelis_virsus = false;

		eile_is_desines = false;
		eile_is_kaires = false;

		stulpelis_is_apacios = false;
		stulpelis_is_virsaus = false;


		if (A_X_l + 1 < 10) {
			A_X_l = A_X_l + 1;

			drawA_I_GameBoard();
			A_I_shooting_stats();
			A_I_steps++;

			A_number = A_Y_n;

			if (A_X_l == 0) A_letter = 'A';
			if (A_X_l == 1) A_letter = 'B';
			if (A_X_l == 2) A_letter = 'C';
			if (A_X_l == 3) A_letter = 'D';
			if (A_X_l == 4) A_letter = 'E';
			if (A_X_l == 5) A_letter = 'F';
			if (A_X_l == 6) A_letter = 'G';
			if (A_X_l == 7) A_letter = 'H';
			if (A_X_l == 8) A_letter = 'I';
			if (A_X_l == 9) A_letter = 'J';

			if (N_PlayerBoard_second[A_Y_n][A_X_l] == 'S')
			{
				AI_PlayerBoard[A_Y_n][A_X_l] = 'X';
				A_I_ships_count--;
				N_PlayerBoard_second[A_Y_n][A_X_l] = 'U';
				eile_desine = true;
				eile = true;
				eile_is_desines = true;
				cout << GREEN << "HIT shot! " << RESET << endl << endl;
			}
			else
			{
				AI_PlayerBoard[A_Y_n][A_X_l] = 'O';
				eile_desine = false;
				eile = false;
				A_X_l = A_X_l - 1;
				cout << RED << "MISSED shot! " << RESET << endl << endl;
			}

			cout << GREY << "AI COORDINATE: " << RED << A_letter << " " << A_number << RESET << endl;
			Sleep(2000);

			drawA_I_GameBoard();

			if (eile_desine == true)
			{
				if (A_X_l + 1 < 10)
				{
					A_X_l = A_X_l + 1;

					drawA_I_GameBoard();
					A_I_shooting_stats();
					A_I_steps++;

					A_number = A_Y_n;

					if (A_X_l == 0) A_letter = 'A';
					if (A_X_l == 1) A_letter = 'B';
					if (A_X_l == 2) A_letter = 'C';
					if (A_X_l == 3) A_letter = 'D';
					if (A_X_l == 4) A_letter = 'E';
					if (A_X_l == 5) A_letter = 'F';
					if (A_X_l == 6) A_letter = 'G';
					if (A_X_l == 7) A_letter = 'H';
					if (A_X_l == 8) A_letter = 'I';
					if (A_X_l == 9) A_letter = 'J';

					if (N_PlayerBoard_second[A_Y_n][A_X_l] == 'S')
					{
						AI_PlayerBoard[A_Y_n][A_X_l] = 'X';
						A_I_ships_count--;
						N_PlayerBoard_second[A_Y_n][A_X_l] = 'U';
						eile_desine = true;
						eile = true;
						cout << GREEN << "HIT shot! " << RESET << endl << endl;
					}
					else
					{
						AI_PlayerBoard[A_Y_n][A_X_l] = 'O';
						eile_desine = false;
						A_X_l = A_X_l - 2;
						cout << RED << "MISSED shot! " << RESET << endl << endl;
					}

					cout << GREY << "AI COORDINATE: " << RED << A_letter << " " << A_number << RESET << endl;
					Sleep(2000);

					drawA_I_GameBoard();

					if (eile_desine == true)
					{
						if (A_X_l + 1 < 10)
						{
							A_X_l = A_X_l + 1;

							drawA_I_GameBoard();
							A_I_shooting_stats();
							A_I_steps++;

							A_number = A_Y_n;

							if (A_X_l == 0) A_letter = 'A';
							if (A_X_l == 1) A_letter = 'B';
							if (A_X_l == 2) A_letter = 'C';
							if (A_X_l == 3) A_letter = 'D';
							if (A_X_l == 4) A_letter = 'E';
							if (A_X_l == 5) A_letter = 'F';
							if (A_X_l == 6) A_letter = 'G';
							if (A_X_l == 7) A_letter = 'H';
							if (A_X_l == 8) A_letter = 'I';
							if (A_X_l == 9) A_letter = 'J';

							if (N_PlayerBoard_second[A_Y_n][A_X_l] == 'S')
							{
								AI_PlayerBoard[A_Y_n][A_X_l] = 'X';
								A_I_ships_count--;
								N_PlayerBoard_second[A_Y_n][A_X_l] = 'U';
								eile_desine = true;
								eile = true;
								cout << GREEN << "HIT shot! " << RESET << endl << endl;
							}
							else
							{
								AI_PlayerBoard[A_Y_n][A_X_l] = 'O';
								eile_desine = false;
								A_X_l = A_X_l - 3;
								cout << RED << "MISSED shot! " << RESET << endl << endl;
							}

							cout << GREY << "AI COORDINATE: " << RED << A_letter << " " << A_number << RESET << endl;
							Sleep(2000);

							drawA_I_GameBoard();

							if (eile_desine == true)
							{
								if (A_X_l + 1 < 10)
								{
									A_X_l = A_X_l + 1;

									drawA_I_GameBoard();
									A_I_shooting_stats();
									A_I_steps++;

									A_number = A_Y_n;

									if (A_X_l == 0) A_letter = 'A';
									if (A_X_l == 1) A_letter = 'B';
									if (A_X_l == 2) A_letter = 'C';
									if (A_X_l == 3) A_letter = 'D';
									if (A_X_l == 4) A_letter = 'E';
									if (A_X_l == 5) A_letter = 'F';
									if (A_X_l == 6) A_letter = 'G';
									if (A_X_l == 7) A_letter = 'H';
									if (A_X_l == 8) A_letter = 'I';
									if (A_X_l == 9) A_letter = 'J';

									if (N_PlayerBoard_second[A_Y_n][A_X_l] == 'S')
									{
										AI_PlayerBoard[A_Y_n][A_X_l] = 'X';
										A_I_ships_count--;
										N_PlayerBoard_second[A_Y_n][A_X_l] = 'U';
										eile_desine = false;
										eile = true;
										cout << GREEN << "HIT shot! " << RESET << endl << endl;
									}
									else
									{
										AI_PlayerBoard[A_Y_n][A_X_l] = 'O';
										eile_desine = false;
										A_X_l = A_X_l - 4;
										cout << RED << "MISSED shot! " << RESET << endl << endl;
									}

									cout << GREY << "AI COORDINATE: " << RED << A_letter << " " << A_number << RESET << endl;
									Sleep(2000);

									drawA_I_GameBoard();
								}
								else
								{
									eile_desine = false;
								}
							}
						}
						else
						{
							eile_desine = false;
						}
					}
				}
				else
				{
					eile_desine = false;
				}
			}
		}
		else
		{
			eile_desine = false;
			eile = false;
		}





		if (A_X_l - 1 >= 0) {
			A_X_l = A_X_l - 1;

			drawA_I_GameBoard();
			A_I_shooting_stats();
			A_I_steps++;

			A_number = A_Y_n;

			if (A_X_l == 0) A_letter = 'A';
			if (A_X_l == 1) A_letter = 'B';
			if (A_X_l == 2) A_letter = 'C';
			if (A_X_l == 3) A_letter = 'D';
			if (A_X_l == 4) A_letter = 'E';
			if (A_X_l == 5) A_letter = 'F';
			if (A_X_l == 6) A_letter = 'G';
			if (A_X_l == 7) A_letter = 'H';
			if (A_X_l == 8) A_letter = 'I';
			if (A_X_l == 9) A_letter = 'J';

			if (N_PlayerBoard_second[A_Y_n][A_X_l] == 'S')
			{
				AI_PlayerBoard[A_Y_n][A_X_l] = 'X';
				A_I_ships_count--;
				N_PlayerBoard_second[A_Y_n][A_X_l] = 'U';
				eile_kaire = true;
				eile = true;
				eile_is_kaires = true;
				cout << GREEN << "HIT shot! " << RESET << endl << endl;
			}
			else
			{
				AI_PlayerBoard[A_Y_n][A_X_l] = 'O';
				eile_kaire = false;
				eile = false;
				A_X_l = A_X_l + 1;
				cout << RED << "MISSED shot! " << RESET << endl << endl;
			}

			cout << GREY << "AI COORDINATE: " << RED << A_letter << " " << A_number << RESET << endl;
			Sleep(2000);

			drawA_I_GameBoard();

			if (eile_kaire == true)
			{
				if (A_X_l - 1 >= 0)
				{
					A_X_l = A_X_l - 1;

					drawA_I_GameBoard();
					A_I_shooting_stats();
					A_I_steps++;

					A_number = A_Y_n;

					if (A_X_l == 0) A_letter = 'A';
					if (A_X_l == 1) A_letter = 'B';
					if (A_X_l == 2) A_letter = 'C';
					if (A_X_l == 3) A_letter = 'D';
					if (A_X_l == 4) A_letter = 'E';
					if (A_X_l == 5) A_letter = 'F';
					if (A_X_l == 6) A_letter = 'G';
					if (A_X_l == 7) A_letter = 'H';
					if (A_X_l == 8) A_letter = 'I';
					if (A_X_l == 9) A_letter = 'J';

					if (N_PlayerBoard_second[A_Y_n][A_X_l] == 'S')
					{
						AI_PlayerBoard[A_Y_n][A_X_l] = 'X';
						A_I_ships_count--;
						N_PlayerBoard_second[A_Y_n][A_X_l] = 'U';
						eile_kaire = true;
						eile = true;
						cout << GREEN << "HIT shot! " << RESET << endl << endl;
					}
					else
					{
						AI_PlayerBoard[A_Y_n][A_X_l] = 'O';
						eile_kaire = false;
						A_X_l = A_X_l + 2;
						cout << RED << "MISSED shot! " << RESET << endl << endl;
					}

					cout << GREY << "AI COORDINATE: " << RED << A_letter << " " << A_number << RESET << endl;
					Sleep(2000);

					drawA_I_GameBoard();

					if (eile_kaire == true)
					{
						if (A_X_l - 1 >= 0)
						{
							A_X_l = A_X_l - 1;

							drawA_I_GameBoard();
							A_I_shooting_stats();
							A_I_steps++;

							A_number = A_Y_n;

							if (A_X_l == 0) A_letter = 'A';
							if (A_X_l == 1) A_letter = 'B';
							if (A_X_l == 2) A_letter = 'C';
							if (A_X_l == 3) A_letter = 'D';
							if (A_X_l == 4) A_letter = 'E';
							if (A_X_l == 5) A_letter = 'F';
							if (A_X_l == 6) A_letter = 'G';
							if (A_X_l == 7) A_letter = 'H';
							if (A_X_l == 8) A_letter = 'I';
							if (A_X_l == 9) A_letter = 'J';

							if (N_PlayerBoard_second[A_Y_n][A_X_l] == 'S')
							{
								AI_PlayerBoard[A_Y_n][A_X_l] = 'X';
								A_I_ships_count--;
								N_PlayerBoard_second[A_Y_n][A_X_l] = 'U';
								eile_kaire = true;
								eile = true;
								cout << GREEN << "HIT shot! " << RESET << endl << endl;
							}
							else
							{
								AI_PlayerBoard[A_Y_n][A_X_l] = 'O';
								eile_kaire = false;
								A_X_l = A_X_l + 3;
								cout << RED << "MISSED shot! " << RESET << endl << endl;
							}

							cout << GREY << "AI COORDINATE: " << RED << A_letter << " " << A_number << RESET << endl;
							Sleep(2000);

							drawA_I_GameBoard();

							if (eile_kaire == true)
							{
								if (A_X_l - 1 >= 0)
								{
									A_X_l = A_X_l - 1;

									drawA_I_GameBoard();
									A_I_shooting_stats();
									A_I_steps++;

									A_number = A_Y_n;

									if (A_X_l == 0) A_letter = 'A';
									if (A_X_l == 1) A_letter = 'B';
									if (A_X_l == 2) A_letter = 'C';
									if (A_X_l == 3) A_letter = 'D';
									if (A_X_l == 4) A_letter = 'E';
									if (A_X_l == 5) A_letter = 'F';
									if (A_X_l == 6) A_letter = 'G';
									if (A_X_l == 7) A_letter = 'H';
									if (A_X_l == 8) A_letter = 'I';
									if (A_X_l == 9) A_letter = 'J';

									if (N_PlayerBoard_second[A_Y_n][A_X_l] == 'S')
									{
										AI_PlayerBoard[A_Y_n][A_X_l] = 'X';
										A_I_ships_count--;
										N_PlayerBoard_second[A_Y_n][A_X_l] = 'U';
										eile_kaire = false;
										eile = true;
										cout << GREEN << "HIT shot! " << RESET << endl << endl;
									}
									else
									{
										AI_PlayerBoard[A_Y_n][A_X_l] = 'O';
										eile_kaire = false;
										A_X_l = A_X_l + 4;
										cout << RED << "MISSED shot! " << RESET << endl << endl;
									}

									cout << GREY << "AI COORDINATE: " << RED << A_letter << " " << A_number << RESET << endl;
									Sleep(2000);

									drawA_I_GameBoard();
								}
								else
								{
									eile_kaire = false;
								}
							}
						}
						else
						{
							eile_kaire = false;
						}
					}
				}
				else
				{
					eile_kaire = false;
				}
			}
		}
		else
		{
			eile_kaire = false;
			eile = false;
		}
		






		if (eile_is_desines == true || eile_is_kaires == true) A_I_shooting();








		if (A_Y_n + 1 < 10) {
			A_Y_n = A_Y_n + 1;

			drawA_I_GameBoard();
			A_I_shooting_stats();
			A_I_steps++;

			A_number = A_Y_n;

			if (A_X_l == 0) A_letter = 'A';
			if (A_X_l == 1) A_letter = 'B';
			if (A_X_l == 2) A_letter = 'C';
			if (A_X_l == 3) A_letter = 'D';
			if (A_X_l == 4) A_letter = 'E';
			if (A_X_l == 5) A_letter = 'F';
			if (A_X_l == 6) A_letter = 'G';
			if (A_X_l == 7) A_letter = 'H';
			if (A_X_l == 8) A_letter = 'I';
			if (A_X_l == 9) A_letter = 'J';

			if (N_PlayerBoard_second[A_Y_n][A_X_l] == 'S')
			{
				AI_PlayerBoard[A_Y_n][A_X_l] = 'X';
				A_I_ships_count--;
				N_PlayerBoard_second[A_Y_n][A_X_l] = 'U';
				stulpelis_apacia = true;
				stulpelis = true;
				stulpelis_is_apacios = true;
				cout << GREEN << "HIT shot! " << RESET << endl << endl;
			}
			else
			{
				AI_PlayerBoard[A_Y_n][A_X_l] = 'O';
				stulpelis_apacia = false;
				stulpelis = false;
				A_Y_n = A_Y_n - 1;
				cout << RED << "MISSED shot! " << RESET << endl << endl;
			}

			cout << GREY << "AI COORDINATE: " << RED << A_letter << " " << A_number << RESET << endl;
			Sleep(2000);

			drawA_I_GameBoard();

			if (stulpelis_apacia == true)
			{
				if (A_Y_n + 1 < 10)
				{
					A_Y_n = A_Y_n + 1;

					drawA_I_GameBoard();
					A_I_shooting_stats();
					A_I_steps++;

					A_number = A_Y_n;

					if (A_X_l == 0) A_letter = 'A';
					if (A_X_l == 1) A_letter = 'B';
					if (A_X_l == 2) A_letter = 'C';
					if (A_X_l == 3) A_letter = 'D';
					if (A_X_l == 4) A_letter = 'E';
					if (A_X_l == 5) A_letter = 'F';
					if (A_X_l == 6) A_letter = 'G';
					if (A_X_l == 7) A_letter = 'H';
					if (A_X_l == 8) A_letter = 'I';
					if (A_X_l == 9) A_letter = 'J';

					if (N_PlayerBoard_second[A_Y_n][A_X_l] == 'S')
					{
						AI_PlayerBoard[A_Y_n][A_X_l] = 'X';
						A_I_ships_count--;
						N_PlayerBoard_second[A_Y_n][A_X_l] = 'U';
						stulpelis_apacia = true;
						stulpelis = true;
						cout << GREEN << "HIT shot! " << RESET << endl << endl;
					}
					else
					{
						AI_PlayerBoard[A_Y_n][A_X_l] = 'O';
						stulpelis_apacia = false;
						A_Y_n = A_Y_n - 2;
						cout << RED << "MISSED shot! " << RESET << endl << endl;
					}

					cout << GREY << "AI COORDINATE: " << RED << A_letter << " " << A_number << RESET << endl;
					Sleep(2000);

					drawA_I_GameBoard();

					if (stulpelis_apacia == true)
					{
						if (A_Y_n + 1 < 10)
						{
							A_Y_n = A_Y_n + 1;

							drawA_I_GameBoard();
							A_I_shooting_stats();
							A_I_steps++;

							A_number = A_Y_n;

							if (A_X_l == 0) A_letter = 'A';
							if (A_X_l == 1) A_letter = 'B';
							if (A_X_l == 2) A_letter = 'C';
							if (A_X_l == 3) A_letter = 'D';
							if (A_X_l == 4) A_letter = 'E';
							if (A_X_l == 5) A_letter = 'F';
							if (A_X_l == 6) A_letter = 'G';
							if (A_X_l == 7) A_letter = 'H';
							if (A_X_l == 8) A_letter = 'I';
							if (A_X_l == 9) A_letter = 'J';

							if (N_PlayerBoard_second[A_Y_n][A_X_l] == 'S')
							{
								AI_PlayerBoard[A_Y_n][A_X_l] = 'X';
								A_I_ships_count--;
								N_PlayerBoard_second[A_Y_n][A_X_l] = 'U';
								stulpelis_apacia = true;
								stulpelis = true;
								cout << GREEN << "HIT shot! " << RESET << endl << endl;
							}
							else
							{
								AI_PlayerBoard[A_Y_n][A_X_l] = 'O';
								stulpelis_apacia = false;
								A_Y_n = A_Y_n - 3;
								cout << RED << "MISSED shot! " << RESET << endl << endl;
							}

							cout << GREY << "AI COORDINATE: " << RED << A_letter << " " << A_number << RESET << endl;
							Sleep(2000);

							drawA_I_GameBoard();

							if (stulpelis_apacia == true)
							{
								if (A_Y_n + 1 < 10)
								{
									A_Y_n = A_Y_n + 1;

									drawA_I_GameBoard();
									A_I_shooting_stats();
									A_I_steps++;

									A_number = A_Y_n;

									if (A_X_l == 0) A_letter = 'A';
									if (A_X_l == 1) A_letter = 'B';
									if (A_X_l == 2) A_letter = 'C';
									if (A_X_l == 3) A_letter = 'D';
									if (A_X_l == 4) A_letter = 'E';
									if (A_X_l == 5) A_letter = 'F';
									if (A_X_l == 6) A_letter = 'G';
									if (A_X_l == 7) A_letter = 'H';
									if (A_X_l == 8) A_letter = 'I';
									if (A_X_l == 9) A_letter = 'J';

									if (N_PlayerBoard_second[A_Y_n][A_X_l] == 'S')
									{
										AI_PlayerBoard[A_Y_n][A_X_l] = 'X';
										A_I_ships_count--;
										N_PlayerBoard_second[A_Y_n][A_X_l] = 'U';
										stulpelis_apacia = false;
										stulpelis = true;
										cout << GREEN << "HIT shot! " << RESET << endl << endl;
									}
									else
									{
										AI_PlayerBoard[A_Y_n][A_X_l] = 'O';
										stulpelis_apacia = false;
										A_Y_n = A_Y_n - 4;
										cout << RED << "MISSED shot! " << RESET << endl << endl;
									}

									cout << GREY << "AI COORDINATE: " << RED << A_letter << " " << A_number << RESET << endl;
									Sleep(2000);

									drawA_I_GameBoard();
								}
								else
								{
									stulpelis_apacia = false;
								}
							}
						}
						else
						{
							stulpelis_apacia = false;
						}
					}
				}
				else
				{
					stulpelis_apacia = false;
				}
			}
		}
		else
		{
			stulpelis_apacia = false;
			stulpelis = false;
		}





		if (A_Y_n - 1 >= 0) {
			A_Y_n = A_Y_n - 1;

			drawA_I_GameBoard();
			A_I_shooting_stats();
			A_I_steps++;

			A_number = A_Y_n;

			if (A_X_l == 0) A_letter = 'A';
			if (A_X_l == 1) A_letter = 'B';
			if (A_X_l == 2) A_letter = 'C';
			if (A_X_l == 3) A_letter = 'D';
			if (A_X_l == 4) A_letter = 'E';
			if (A_X_l == 5) A_letter = 'F';
			if (A_X_l == 6) A_letter = 'G';
			if (A_X_l == 7) A_letter = 'H';
			if (A_X_l == 8) A_letter = 'I';
			if (A_X_l == 9) A_letter = 'J';

			if (N_PlayerBoard_second[A_Y_n][A_X_l] == 'S')
			{
				AI_PlayerBoard[A_Y_n][A_X_l] = 'X';
				A_I_ships_count--;
				N_PlayerBoard_second[A_Y_n][A_X_l] = 'U';
				stulpelis_virsus = true;
				stulpelis = true;
				stulpelis_is_virsaus = true;
				cout << GREEN << "HIT shot! " << RESET << endl << endl;
			}
			else
			{
				AI_PlayerBoard[A_Y_n][A_X_l] = 'O';
				stulpelis_virsus = false;
				stulpelis = false;
				A_Y_n = A_Y_n + 1;
				cout << RED << "MISSED shot! " << RESET << endl << endl;
			}

			cout << GREY << "AI COORDINATE: " << RED << A_letter << " " << A_number << RESET << endl;
			Sleep(2000);

			drawA_I_GameBoard();

			if (stulpelis_virsus == true)
			{
				if (A_Y_n - 1 >= 0)
				{
					A_Y_n = A_Y_n - 1;

					drawA_I_GameBoard();
					A_I_shooting_stats();
					A_I_steps++;

					A_number = A_Y_n;

					if (A_X_l == 0) A_letter = 'A';
					if (A_X_l == 1) A_letter = 'B';
					if (A_X_l == 2) A_letter = 'C';
					if (A_X_l == 3) A_letter = 'D';
					if (A_X_l == 4) A_letter = 'E';
					if (A_X_l == 5) A_letter = 'F';
					if (A_X_l == 6) A_letter = 'G';
					if (A_X_l == 7) A_letter = 'H';
					if (A_X_l == 8) A_letter = 'I';
					if (A_X_l == 9) A_letter = 'J';

					if (N_PlayerBoard_second[A_Y_n][A_X_l] == 'S')
					{
						AI_PlayerBoard[A_Y_n][A_X_l] = 'X';
						A_I_ships_count--;
						N_PlayerBoard_second[A_Y_n][A_X_l] = 'U';
						stulpelis_virsus = true;
						stulpelis = true;
						cout << GREEN << "HIT shot! " << RESET << endl << endl;
					}
					else
					{
						AI_PlayerBoard[A_Y_n][A_X_l] = 'O';
						stulpelis_virsus = false;
						A_Y_n = A_Y_n + 2;
						cout << RED << "MISSED shot! " << RESET << endl << endl;
					}

					cout << GREY << "AI COORDINATE: " << RED << A_letter << " " << A_number << RESET << endl;
					Sleep(2000);

					drawA_I_GameBoard();

					if (stulpelis_virsus == true)
					{
						if (A_Y_n - 1 >= 0)
						{
							A_Y_n = A_Y_n - 1;

							drawA_I_GameBoard();
							A_I_shooting_stats();
							A_I_steps++;

							A_number = A_Y_n;

							if (A_X_l == 0) A_letter = 'A';
							if (A_X_l == 1) A_letter = 'B';
							if (A_X_l == 2) A_letter = 'C';
							if (A_X_l == 3) A_letter = 'D';
							if (A_X_l == 4) A_letter = 'E';
							if (A_X_l == 5) A_letter = 'F';
							if (A_X_l == 6) A_letter = 'G';
							if (A_X_l == 7) A_letter = 'H';
							if (A_X_l == 8) A_letter = 'I';
							if (A_X_l == 9) A_letter = 'J';

							if (N_PlayerBoard_second[A_Y_n][A_X_l] == 'S')
							{
								AI_PlayerBoard[A_Y_n][A_X_l] = 'X';
								A_I_ships_count--;
								N_PlayerBoard_second[A_Y_n][A_X_l] = 'U';
								stulpelis_virsus = true;
								stulpelis = true;
								cout << GREEN << "HIT shot! " << RESET << endl << endl;
							}
							else
							{
								AI_PlayerBoard[A_Y_n][A_X_l] = 'O';
								stulpelis_virsus = false;
								A_Y_n = A_Y_n + 3;
								cout << RED << "MISSED shot! " << RESET << endl << endl;
							}

							cout << GREY << "AI COORDINATE: " << RED << A_letter << " " << A_number << RESET << endl;
							Sleep(2000);

							drawA_I_GameBoard();

							if (stulpelis_virsus == true)
							{
								if (A_Y_n - 1 >= 0)
								{
									A_Y_n = A_Y_n - 1;

									drawA_I_GameBoard();
									A_I_shooting_stats();
									A_I_steps++;

									A_number = A_Y_n;

									if (A_X_l == 0) A_letter = 'A';
									if (A_X_l == 1) A_letter = 'B';
									if (A_X_l == 2) A_letter = 'C';
									if (A_X_l == 3) A_letter = 'D';
									if (A_X_l == 4) A_letter = 'E';
									if (A_X_l == 5) A_letter = 'F';
									if (A_X_l == 6) A_letter = 'G';
									if (A_X_l == 7) A_letter = 'H';
									if (A_X_l == 8) A_letter = 'I';
									if (A_X_l == 9) A_letter = 'J';

									if (N_PlayerBoard_second[A_Y_n][A_X_l] == 'S')
									{
										AI_PlayerBoard[A_Y_n][A_X_l] = 'X';
										A_I_ships_count--;
										N_PlayerBoard_second[A_Y_n][A_X_l] = 'U';
										stulpelis_virsus = false;
										stulpelis = true;
										cout << GREEN << "HIT shot! " << RESET << endl << endl;
									}
									else
									{
										AI_PlayerBoard[A_Y_n][A_X_l] = 'O';
										stulpelis_virsus = false;
										A_Y_n = A_Y_n + 4;
										cout << RED << "MISSED shot! " << RESET << endl << endl;
									}

									cout << GREY << "AI COORDINATE: " << RED << A_letter << " " << A_number << RESET << endl;
									Sleep(2000);

									drawA_I_GameBoard();
								}
								else
								{
									stulpelis_virsus = false;
								}
							}
						}
						else
						{
							stulpelis_virsus = false;
						}
					}
				}
				else
				{
					stulpelis_virsus = false;
				}
			}
		}
		else
		{
			stulpelis_virsus = false;
			stulpelis = false;
		}

		A_I_shooting();

	}

	void A_I_shooting_stats()
	{
		cout << BLUE << "SHOOTING STEP: " << A_I_steps << RESET << endl;
		cout << BLUE << "Score: " << A_I_score << RESET << endl;
		cout << BLUE << "Last taken shot: " << A_letter << " " << A_number << RESET << endl;
		cout << BLUE << "Remaining ship's parts: " << A_I_ships_count << RESET << endl << endl;
	}

	const void A_I_Victory()
	{
		system("cls");
		drawA_I_title();
		cout << YELLOW << " *****************************************************************" << RESET << endl;
		cout << YELLOW << "** " << RESET << CYAN << "##   ##  ##  #######  ########  #######  #######  ##    ##  ##" << YELLOW << " **" << RESET << endl;
		cout << YELLOW << "** " << RESET << GREEN << "##   ##  ##  ##          ##     ##   ##  ##   ##   ##  ##   ##" << YELLOW << " **" << RESET << endl;
		cout << YELLOW << "** " << RESET << RED << "##   ##  ##  ##          ##     ##   ##  #####       ##     ##" << YELLOW << " **" << RESET << endl;
		cout << YELLOW << "** " << RESET << GREEN << " ## ##   ##  ##          ##     ##   ##  ##  ##      ##       " << YELLOW << " **" << RESET << endl;
		cout << YELLOW << "** " << RESET << CYAN << "   #     ##  #######     ##     #######  ##   ##     ##     ##" << YELLOW << " **" << RESET << endl;
		cout << YELLOW << " ******************************************************************" << RESET << endl << endl;

		cout << GREY << "|" << RED << "AI's" GREY << "|" << ORANGE << " GAME RESULTS: " << endl << endl;
		cout << BLUE << "Shooting steps: " << A_I_steps << RESET << endl;
		cout << BLUE << "Score: " << A_I_score << RESET << endl;
		cout << BLUE << "SUNKED ship's parts: 20" << RESET << endl;
	}

};

void DrawTitle();
void Menu();

void ClearScreen(); // Istrinti ekrana kaskart
void ShowConsoleCursor(bool showFlag); // Panaikinti cursor'iu

void directionsGameMenu();

void directionsSinglePlayerGameMenu();
void directionsMultiPlayerGameMenu();

int main()
{
	DrawTitle();
	Menu();


	return 0;
}
void DrawTitle()
{
	cout << YELLOW << " ********************************************************************* " << RESET << endl;
	cout << YELLOW << "**" << RESET << RED << " ###########     #####    #########  #########  ###        ######### " << RESET << YELLOW << "**" << RESET << endl;
	cout << YELLOW << "**" << RESET << ORANGE << " ###     ####   #######   #########  #########  ###        ######### " << RESET << YELLOW << "**" << RESET << endl;
	cout << YELLOW << "**" << RESET << ORANGE << " ###      ###  ###   ###     ###        ###     ###        ###       " << RESET << YELLOW << "**" << RESET << endl;
	cout << YELLOW << "**" << RESET << RED << " ############  #########     ###        ###     ###        ######### " << RESET << YELLOW << "**" << RESET << endl;
	cout << YELLOW << "**" << RESET << ORANGE << " ###      ###  ###   ###     ###        ###     ###        ###       " << RESET << YELLOW << "**" << RESET << endl;
	cout << YELLOW << "**" << RESET << ORANGE << " ###     ####  ###   ###     ###        ###     #########  ######### " << RESET << YELLOW << "**" << RESET << endl;
	cout << YELLOW << "**" << RESET << RED << " ###########   ###   ###     ###        ###     #########  ######### " << RESET << YELLOW << "**" << RESET << endl;
	cout << YELLOW << " *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << RESET << endl;
	cout << YELLOW << "**" << RESET << CYAN << "                $$$$$$$$$  $$$   $$$  $$$  $$$$$$$$                  " << RESET << YELLOW << "**" << RESET << endl;
	cout << YELLOW << "**" << RESET << RED << "        +       " << RESET << GREEN << "$$$$$$$$$  $$$   $$$  $$$  $$$   $$$" << RESET << RED << "       +         " << RESET << YELLOW << "**" << RESET << endl;
	cout << YELLOW << "**" << RESET << RED << "        +++     " << RESET << GREEN << "$$$        $$$   $$$  $$$  $$$   $$$" << RESET << RED << "       +++       " << RESET << YELLOW << "**" << RESET << endl;
	cout << YELLOW << "**" << RESET << RED << "        +       " << RESET << CYAN << "$$$$$$$$$  $$$$$$$$$  $$$  $$$$$$$$" << RESET << RED << "        +         " << RESET << YELLOW << "**" << RESET << endl;
	cout << YELLOW << "**" << RESET << BROWN << "  +++++++++++++ " << RESET << GREEN << "      $$$  $$$   $$$  $$$  $$$" << RESET << GREY << "   * " << RESET << BROWN << "  +++++++++++++   " << RESET << YELLOW << "**" << RESET << endl;
	cout << YELLOW << "**" << RESET << BROWN << "   +++++++++++  " << RESET << GREEN << "$$$$$$$$$  $$$   $$$  $$$  $$$" << RESET << GREY << " |*" << RESET << RED << "X" << RESET << GREY << "*| " << RESET << BROWN << " +++++++++++    " << RESET << YELLOW << "**" << RESET << endl;
	cout << YELLOW << "**" << RESET << BLUE << "  ~~~~~~~~~~~~~ " << RESET << CYAN << "$$$$$$$$$  $$$   $$$  $$$  $$$" << RESET << GREY << "   * " << RESET << BLUE << "  ~~~~~~~~~~~~~   " << RESET << YELLOW << "**" << RESET << endl;
	cout << YELLOW << " ********************************************************************* " << RESET << endl;
}

void Menu()
{
	bool exitMenu = false;
	int selectedOption = 0;
	char keyPressed = ' ';

	while (!exitMenu)
	{
		ShowConsoleCursor(false);
		ClearScreen();
		DrawTitle();
		cout << endl;

		if (selectedOption == 0)
		{
			cout << RED << "                              Play a Game                              " << RESET << endl;
			cout << "                                 Rules                                 " << endl;
			cout << "                                 ABOUT                                 " << endl;
		}
		else if (selectedOption == 1)
		{
			cout << "                              Play a Game                              " << endl;
			cout << RED << "                                 Rules                                 " << RESET << endl;
			cout << "                                 ABOUT                                 " << endl;
		}
		else
		{
			cout << "                              Play a Game                              " << endl;
			cout << "                                 Rules                                 " << endl;
			cout << RED << "                                 ABOUT                                 " << RESET << endl;
		}

		cout << endl;
		cout << BLUE << "SELECTED OPTION (MENU): " << RESET << selectedOption + 1 << endl << endl;

		while (true)
		{
			if (_kbhit())
			{
				keyPressed = _getch();
				switch (keyPressed)
				{
				case 72: //Move up
					if (selectedOption > 0) {
						selectedOption--;
					}
					else if (selectedOption == 0) {
						selectedOption += 2;
					}
					break;
				case 80: //Move down
					if (selectedOption < 2) {
						selectedOption++;
					}
					else if (selectedOption == 2) {
						selectedOption -= 2;
					}
					break;
				}
				break;
			}
		}

		if (GetAsyncKeyState(VK_RETURN))
		{
			switch (selectedOption)
			{
			case 0:
			{
				time_t startTime = time(nullptr); // Gaunamas pradinis laikas

				while (true)
				{
					system("cls");
					ClearScreen();
					cout << YELLOW << "LOADING THE GAME." << RESET << endl;
					Sleep(500);
					ClearScreen();
					cout << YELLOW << "LOADING THE GAME.." << RESET << endl;
					Sleep(500);
					ClearScreen();
					cout << YELLOW << "LOADING THE GAME..." << RESET << endl;
					Sleep(500);

					if (difftime(time(nullptr), startTime) >= 1) break; // Tikriname ar 5 sec jau praejo
				}
				directionsGameMenu();
				break;
			}
			case 1:
				cout << "Displaying the rules..." << endl;
				break;
			case 2:
				cout << "Showing about..." << endl;
				break;
			}
			exitMenu = true;
		}
	}
}

void directionsGameMenu()
{
	BASE_S_M_Player bazinis;
	bazinis.drawGameBoard_DESIGN();

	bazinis.drawGameBoard_CURSOR();

	bool S, M;
	S = bazinis.retr_S();
	M = bazinis.retr_M();

	if (S == true) directionsSinglePlayerGameMenu();
	if (M == true) directionsMultiPlayerGameMenu();

	//cout << "S = " << S << endl;
	//cout << "M = " << M;

}

void directionsSinglePlayerGameMenu()
{
	SinglePlayerC single;

	single.drawLoading_S_P_GameBoard();
	single.enterYourName();
	single.Board_SP();
	single.drawS_P_GameBoard();

	single.generate_4SHIP(); // VIENAS 4 ILGIO LAIVAS
	single.generate_4SHIP_zone();

	for (int i = 0; i < 2; i++) // PIRMAS IR ANTRAS 3 ILGIO LAIVAI
	{
		single.generate_3SHIP();
		single.generate_3SHIP_zone();
	}
	
	for (int i = 0; i < 3; i++) // PIRMAS, ANTRAS IR TRECIAS 2 ILGIO LAIVAI
	{
		single.generate_2SHIP();
		single.generate_2SHIP_zone();
	}

	for (int i = 0; i < 4; i++) // PIRMAS, ANTRAS, TRECIAS IR KETVIRTAS 1 ILGIO LAIVAI
	{
		single.generate_1SHIP();
		single.generate_1SHIP_zone();
	}

	single.S_P_Shooting();

}

void directionsMultiPlayerGameMenu()
{
	MultiPlayerC_BASE mbazinis;

	mbazinis.drawLoading_A_I_GameBoard();
	mbazinis.drawA_I_title();
	
	MultiPlayer_A AI;

	AI.enterYourName();
	AI.drawN_P_GameBoard();
	AI.generate_N_P_SHIPS();

	AI.A_I_shooting();
	AI.A_I_Victory();
}

void ClearScreen()
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}