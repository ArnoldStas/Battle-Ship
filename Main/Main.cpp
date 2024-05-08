#include <iostream>
#include <Windows.h>
#include <conio.h>
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


void DrawTitle();
void Menu();

int main()
{
	DrawTitle();
	Menu();

	//GOLD HUNTER

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
		system("cls");
		DrawTitle();
		cout << endl;

		if (selectedOption == 0)
		{
			cout << GREY << "                              Play a Game                              " << RESET << endl;
			cout << "                                 Rules                                 " << endl;
			cout << "                                 ABOUT                                 " << endl;
		}
		else if (selectedOption == 1)
		{
			cout << "                              Play a Game                              " << endl;
			cout << GREY << "                                 Rules                                 " << RESET << endl;
			cout << "                                 ABOUT                                 " << endl;
		}
		else
		{
			cout << "                              Play a Game                              " << endl;
			cout << "                                 Rules                                 " << endl;
			cout << GREY << "                                 ABOUT                                 " << RESET << endl;
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
				//system("cls");
				cout << "Starting the game..." << endl;
				break;
			case 1:
				//system("cls");
				cout << "Displaying the rules..." << endl;
				break;
			case 2:
				//system("cls");
				cout << "Showing about..." << endl;
				break;
			}
			exitMenu = true;
		}
	}
}
