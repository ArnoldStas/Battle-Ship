#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <vector>
#include <map>

using namespace std;

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
BASE_S_M_Player() : exitGameBoardMenu(0), GameBoardSelectedOption(0), keyGameBoardPressed (' '), S(0), M(0), SPlayerBoard(10, vector<char>(10)), SPlayerBoard_second(10, vector<char>(10)), GameBoardSize(10), GameBoardSize_Horizontal(10), GameBoardSize_Vertical(10), X(0), Y(0) {}
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

			cout <<"     SinglePlayer (A)";
			cout << "                             ";
			cout << "MultiPlayer (A & B)";
			cout << endl << endl;
			cout << GREY << "       Player |A|:                      " << "Player |A|:                 Player |B|:" << RESET << endl << endl;

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
					cout << "                             ";
					cout << "MultiPlayer (A & B)";
					cout << endl << endl;
					cout << GREY << "       Player |A|:                      " << "Player |A|:                 Player |B|:" << RESET << endl << endl;

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

					cout << RED << "* " << YELLOW << "3" << RESET << BLUE << " # # " << BROWN  << "S" << BLUE << " # # # " << BROWN << "S S S" << BLUE << " #" << RED << " * " << RESET;
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
					cout << "                             ";
					cout << RED << "MultiPlayer (A & B)" << RESET;
					cout << endl << endl;
					cout << GREY << "       Player |A|:                      " << "Player |A|:                 Player |B|:" << RESET << endl << endl;

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
					cout << "* " << YELLOW << "0" << RESET << BROWN << " S" << BLUE << " # # # " << BROWN << "S S" << BLUE << " # # # #" << RED << " * "  << RESET << endl;

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
						//cout << "Displaying SINGLE PLAYER" << endl;
						S = 1;
						break;
					case 1:
						cout << "Displaying MULTI PLAYER" << endl;
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
		bool test_1, test_2, test_3, test_4;
		int test_count, selectedTest;
	public:
SinglePlayerC() : S_name(" "), test_1(false), test_2(false), test_3(false), test_4(false), test_count(0), selectedTest(0) {}
SinglePlayerC(string x) : S_name(x), test_1(false), test_2(false), test_3(false), test_4(false), test_count(0), selectedTest(0) {}
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

		void drawS_P_GameBoard()
		{
			system("cls");
			drawS_P_title();
			cout << GREY << "                                     " <<" |" << RED << S_name << "'s" << GREY << "| GAMEBOARD:                      " << RESET << endl << endl;

			cout << GREY << "                                       *********************" << RESET << endl;
			cout << GREY << "                                     * " << ORANGE << "x" << RESET << YELLOW << " A B C D E F G H I J" << GREY << " * " << RESET << endl;

			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++) { SPlayerBoard[i][j] = '#'; SPlayerBoard_second[i][j] = '#'; }

			for (int i = 0; i < 10; i++)
			{
				cout << GREY << "                                     * " << YELLOW << i << RESET << " ";
				for (int j = 0; j < 10; j++)
				{
					cout << BLUE << SPlayerBoard[i][j] << RESET << " ";
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
				if (SPlayerBoard_second[Y][X + 1] = '#')
					if (X + 2 < 10)
						if (SPlayerBoard_second[Y][X + 2] = '#')
							if (X + 3 < 10)
								if (SPlayerBoard_second[Y][X + 3] = '#') {
									test_1 = true; test_count++;
								}

			if (Y + 1 < 10)
				if (SPlayerBoard_second[Y + 1][X] = '#')
					if (Y + 2 < 10)
						if (SPlayerBoard_second[Y + 2][X] = '#')
							if (Y + 3 < 10)
								if (SPlayerBoard_second[Y + 3][X] = '#') {
									test_2 = true; test_count++;
								}

			if (X - 1 > 0)
				if (SPlayerBoard_second[Y][X - 1] = '#')
					if (X - 2 > 0)
						if (SPlayerBoard_second[Y][X - 2] = '#')
							if (X - 3 > 0)
								if (SPlayerBoard_second[Y][X - 3] = '#') {
									test_3 = true; test_count++;
								}

			if (Y - 1 > 0)
				if (SPlayerBoard_second[Y - 1][X] = '#')
					if (Y - 2 > 0)
						if (SPlayerBoard_second[Y - 2][X] = '#')
							if (Y - 3 > 0)
								if (SPlayerBoard_second[Y - 3][X] = '#') {
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
			test.open("test.txt");

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

		void drawLoading_S_P_4SHIP()
		{
			time_t startTime = time(nullptr); // Gaunamas pradinis laikas

			while (true)
			{
				//system("cls");
				//ClearScreen();
				cout << YELLOW << "GENERATING 4 LENGHT SHIP (20%): " << BROWN << "SSSS" << RESET << endl;
				Sleep(500);
				ClearScreen();
				drawS_P_title();
				drawS_P_GameBoard();
				cout << YELLOW << "GENERATING 4 LENGHT SHIP (80%): " << BROWN << "SSSS" << RESET << endl;
				Sleep(500);
				ClearScreen();
				drawS_P_title();
				drawS_P_GameBoard();
				cout << YELLOW << "GENERATING 4 LENGHT SHIP (99%): " << BROWN << "SSSS" << RESET << endl;
				Sleep(500);
				ClearScreen();
				drawS_P_title();
				drawS_P_GameBoard();
				//system("cls");
				cout << GREEN << "DONE! " << WHITE << "- " << BROWN << "SSSS(" << WHITE << "1" << BROWN << ")" << RESET << endl;
				Sleep(500);

				if (difftime(time(nullptr), startTime) >= 1) break; // Tikriname ar 1 sec jau praejo
			}
		}

};

class MultiPlayerC_BASE : public BASE_S_M_Player
{
	public:

};

class MultiPlayer_A : public MultiPlayerC_BASE
{
	public:

};

class MultiPlayer_B : public MultiPlayerC_BASE
{
	public:

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
	cout << YELLOW << "**" << RESET << BLUE << "  ~~~~~~~~~~~~~ " << RESET << CYAN << "$$$$$$$$$  $$$   $$$  $$$  $$$" << RESET << GREY <<"   * " << RESET << BLUE << "  ~~~~~~~~~~~~~   " << RESET << YELLOW << "**" << RESET << endl;
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
	single.drawS_P_GameBoard();

	single.generate_4SHIP();
	single.generate_4SHIP_zone();
	single.drawLoading_S_P_4SHIP();


}

void directionsMultiPlayerGameMenu()
{

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
