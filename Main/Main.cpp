#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
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
		bool exitGameBoardMenu;
		int GameBoardSelectedOption;
		char keyGameBoardPressed;
	protected:

	public:
BASE_S_M_Player() : exitGameBoardMenu(0), GameBoardSelectedOption(0), keyGameBoardPressed (' ') {}
BASE_S_M_Player(bool x, int y, char z) : exitGameBoardMenu(x), GameBoardSelectedOption(y), keyGameBoardPressed(z) {}
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

			cout <<"     SinglePlayer(A)";
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

					cout << RED << "     SinglePlayer(A)" << RESET;
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

					cout << "     SinglePlayer(A)";
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
						cout << "Displaying SINGLE PLAYER" << endl;
						break;
					case 1:
						cout << "Displaying MULTI PLAYER" << endl;
						break;
					}
					exitGameBoardMenu = true;
				}
			}
		}
};

class SinglePlayerC : public BASE_S_M_Player
{
	public:

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
