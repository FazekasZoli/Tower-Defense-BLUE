#include "View.h"
#include <iostream>

void introTower()
{
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(42) << " _    _    _" << std::setfill(' ') << std::setw(34) << "++\n";
	Sleep(100);
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(43) << "| |__| |__| |" << std::setfill(' ') << std::setw(33) << "++\n";
	Sleep(100);
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(43) << "|           |" << std::setfill(' ') << std::setw(33) << "++\n";
	Sleep(100);
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(43) << "|__       __|" << std::setfill(' ') << std::setw(33) << "++\n";
	Sleep(100);
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(44) << "   |     |    " << std::setfill(' ') << std::setw(32) << "++\n";
	Sleep(100);
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(44) << "   |     |    " << std::setfill(' ') << std::setw(32) << "++\n";
	Sleep(100);
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(43) << " __|     |__ " << std::setfill(' ') << std::setw(33) << "++\n";
	Sleep(100);
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(44) << "|___________| " << std::setfill(' ') << std::setw(32) << "++\n";
}

void welcome()
{
	std::string welcome = "Welcome to our TOWER DEFENSE game";
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(42) << std::setfill(' ') << std::setw(76) << "++\n";
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(42) << std::setfill(' ') << std::setw(76) << "++\n";
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(19);
	for (int i = 0; i < welcome.size(); ++i)
	{
		std::cout << welcome[i];
		Sleep(50);
	}
	std::cout << std::setfill(' ') << std::setw(25) << "++\n";
}

void destroyTower()
{
	Sleep(100);
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(20) << std::setfill(' ') << std::setw(51) << "      ____   " << std::setfill(' ') << std::setw(25) << "++\n";
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(20) << std::setfill(' ') << std::setw(49) << "   __|   _|" << std::setfill(' ') << std::setw(27) << "++\n";
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(32) << "    _    " << std::setfill(' ') << std::setw(17) << " _|     |_ " << std::setfill(' ') << std::setw(27) << "++\n";
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(36) << "   | |___    " << std::setfill(' ') << std::setw(14) << "|        _| " << std::setfill(' ') << std::setw(26) << "++\n";
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(36) << " __|     |__ " << std::setfill(' ') << std::setw(13) << "|____   |_ " << std::setfill(' ') << std::setw(27) << "++\n";
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(37) << "|___________| " << std::setfill(' ') << std::setw(13) << "     |____| " << std::setfill(' ') << std::setw(26) << "++\n";
	Sleep(100);
}

void end()
{
	std::string end = "GAME OVER";

	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(33);
	for (int i = 0; i < end.size(); ++i)
	{
		std::cout << end[i];
		Sleep(50);
	}
	std::cout << std::setfill(' ') << std::setw(35) << "++\n";

}

void View::displayIntro()
{
	std::cout << "\n\n" << std::setfill(' ') << std::setw(10) << "+" << std::setfill('+') << std::setw(77) << "\n";
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(42) << std::setfill(' ') << std::setw(76) << "++\n";

	introTower();

	Sleep(1000);

	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(76) << "++\n";

	welcome();

	Sleep(1000);

	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(42) << std::setfill(' ') << std::setw(76) << "++\n";

	introTower();
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(42) << std::setfill(' ') << std::setw(76) << "++\n";
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(42) << std::setfill(' ') << std::setw(76) << "++\n";
	std::cout << std::setfill(' ') << std::setw(10) << "+" << std::setfill('+') << std::setw(77) << "\n";
	Sleep(500);
}

void View::displayMenu()
{
	system("cls");


	//console beállítások
	//HWND hWnd;
	SetConsoleTitle(("Tower Defense Game"));
	//hWnd = FindWindow(NULL, ("Tower Defense Game"));
	//COORD NewSBSize = GetLargestConsoleWindowSize(hOut);
	do {

		std::cout << "\n\n" << std::setfill(' ') << std::setw(10) << "+" << std::setfill('+') << std::setw(77) << "\n";
		for (size_t i = 0; i < 25; i++)
		{
			std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(76) << "++\n";
		}
		std::cout << std::setfill(' ') << std::setw(10) << "+" << std::setfill('+') << std::setw(77) << "\n";
		std::cout << std::setfill(' ') << std::setw(13) << " " << "Move Up/down : W/S - Enter : Select - Space : Back - ESC : Exit game\n";


		switch (menuState)
		{
		case 0:
			mainMenu();
			break;
		case 1:
			displayLevelSelect(NewGame, probaPalyaNevek);
			break;
		case 2:
			displayLevelSelect(LoadGame, probaPalyaNevek);
			break;
		default:
			break;


		}
	} while (menuState > -1);
	std::cout << "\n" << menuState;
}

void View::mainMenu() {

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(hOut, 10);

	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &info);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	std::cout << "\n";
	std::cout << std::setfill(' ') << std::setw(52) << "Main Menu\n";
	SetConsoleTextAttribute(hOut, 7);


	short push = 40;
	COORD  NewGamePos = { push,6 };
	COORD  LoadGamePos = { push,9 };
	COORD  ExitGamepos = { push,12 };

	char input;
	bool menuBool = true;
	if (mainPpos == -1)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), NewGamePos);
		std::cout << "1. New Game";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LoadGamePos);
		std::cout << "2. Load Game";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ExitGamepos);
		std::cout << "3. Exit game";
		input = _getch();
		mainPpos = 0;
	}
	//Beep(723, 50);
	do
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), NewGamePos);
		(mainPpos == 0) ? SetConsoleTextAttribute(hOut, 8 + 16 * 14) : SetConsoleTextAttribute(hOut, 7);
		std::cout << "1. New Game";
		SetConsoleTextAttribute(hOut, 7);
		(mainPpos == 0) ? (std::cout << " <-") : std::cout << "   ";

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LoadGamePos);
		(mainPpos == 1) ? SetConsoleTextAttribute(hOut, 8 + 16 * 14) : SetConsoleTextAttribute(hOut, 7);
		std::cout << "2. Load Game";
		SetConsoleTextAttribute(hOut, 7);

		(mainPpos == 1) ? (std::cout << " <-") : std::cout << "   ";

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ExitGamepos);
		(mainPpos == 2) ? SetConsoleTextAttribute(hOut, 8 + 16 * 14) : SetConsoleTextAttribute(hOut, 7);
		std::cout << "3. Exit game";
		SetConsoleTextAttribute(hOut, 7);
		(mainPpos == 2) ? (std::cout << " <-") : std::cout << "   ";
		//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});


		input = _getch();
		switch (input)
		{
		case 'w':
			--mainPpos;
			if (mainPpos < 0)
				mainPpos = 2;
			mainPpos = mainPpos % 3;
			//Beep(723, 100);
			break;
		case 'W':
			--mainPpos;
			if (mainPpos < 0)
				mainPpos = 2;
			mainPpos = mainPpos % 3;
			//Beep(723, 100);
			break;
		case 's':
			++mainPpos;
			mainPpos = mainPpos % 3;
			//Beep(723, 100);
			break;
		case 'S':
			++mainPpos;
			mainPpos = mainPpos % 3;
			//Beep(723, 100);
			break;
		case '\r':
			switch (mainPpos) {
			case 0:
				Beep(650, 100);

				SetConsoleTextAttribute(hOut, 7);
				system("cls");
				menuState = 1;//goto select level display
				return;
				break;
			case 1:
				Beep(650, 100);

				SetConsoleTextAttribute(hOut, 7);
				system("cls");
				menuState = 2;//goto select level display
				return;
				break;
			case 2:
				Beep(400, 100);
				SetConsoleTextAttribute(hOut, 7);

				//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});
				system("cls");
				std::cout << "Goodbye\n";

				menuState = -1;
				return;
			}
			break;
		case 27:
			Beep(400, 100);
			system("cls");
			std::cout << "Goodbye\n";

			menuState = -1;
			return;
			break;
		default:

			break;
		}

		//std::cout << input;
	} while (menuBool);

}

void View::displayLevelSelect(LevelSelectMode mode, std::vector<std::string> &levels)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
	SetConsoleTextAttribute(hOut, 10);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &info);


	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	std::cout << "\n";
	switch (mode)
	{
	case NewGame:
		std::cout << std::setfill(' ') << std::setw(63) << "Select New Game Level\n";
		break;
	case LoadGame:
		std::cout << std::setfill(' ') << std::setw(60) << "Select Saved Game\n";
	}
	SetConsoleTextAttribute(hOut, 7);



	short push = 40;


	//for (short i = 1; i <= levels.size(); i++)
	//{
	//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { push,4+i*3});
	//	std::cout << i<<":\t"<< levels[i-1];
	//}

	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { push,4 + ((short)levels.size()+1) * 3 });
	//std::cout << "Back";

	short pos = 0;
	char input;
	bool menuBool = true;
	//input = _getch();
	//Beep(723, 50);
	do
	{
		for (short i = 1; i <= levels.size(); i++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { push,3 + i * 3 });
			(pos == i - 1) ? SetConsoleTextAttribute(hOut, 8 + 16 * 14) : SetConsoleTextAttribute(hOut, 7);
			std::cout << i << ":\t" << levels[i - 1];
			SetConsoleTextAttribute(hOut, 7);
			(pos == i - 1) ? (std::cout << " <-") : std::cout << "   ";
		}

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { push,4 + ((short)levels.size() + 1) * 3 });
		(pos == levels.size()) ? SetConsoleTextAttribute(hOut, 8 + 16 * 14) : SetConsoleTextAttribute(hOut, 7);
		std::cout << "Back";
		SetConsoleTextAttribute(hOut, 7);
		(mainPpos == levels.size()) ? (std::cout << " <-") : std::cout << "   ";
		//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });

		input = _getch();
		switch (input)
		{
		case 'w':
			--pos;
			if (pos < 0)
				pos = (short)levels.size();
			pos = pos % (levels.size() + 1);
			//Beep(723, 100);
			break;
		case 'W':
			--pos;
			if (pos < 0)
				pos = (short)levels.size();
			pos = pos % (levels.size() + 1);
			//Beep(723, 100);
			break;
		case 's':
			++pos;
			pos = pos % (levels.size() + 1);
			//Beep(723, 100);
			break;
		case 'S':
			++pos;
			pos = pos % (levels.size() + 1);
			//Beep(723, 100);
			break;
		case '\r':
			if (pos == levels.size())
			{

				system("cls");
				menuState = 0;
				return;
			}
			else
			{
				Beep(650, 100);

				system("cls");
				std::cout << "\n" << levels[pos] << " nevu palya indul... WIP";// ehhes hasonlóan hivatkozhat a megfelelore Pályák tárolása vektorban pl
				menuState = -1;
				return;
			}

			break;
		case 27:
			Beep(400, 100);
			system("cls");
			menuState = -1;
			std::cout << "Goodbye\n";
			return;
			break;
		case ' ':
			Beep(500, 100);

			system("cls");
			menuState = 0;
			return;
		default:

			break;
		}

		//std::cout << input;
	} while (menuBool);
}

void View::displayGameOver()
{
	system("cls");

	std::cout << "\n\n" << std::setfill(' ') << std::setw(10) << "+" << std::setfill('+') << std::setw(77) << "\n";
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(42) << std::setfill(' ') << std::setw(76) << "++\n";

	introTower();

	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(42) << std::setfill(' ') << std::setw(76) << "++\n";
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(42) << std::setfill(' ') << std::setw(76) << "++\n";
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(42) << std::setfill(' ') << std::setw(76) << "++\n";

	end();

	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(42) << std::setfill(' ') << std::setw(76) << "++\n";
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(42) << std::setfill(' ') << std::setw(76) << "++\n";

	destroyTower();

	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(42) << std::setfill(' ') << std::setw(76) << "++\n";
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(42) << std::setfill(' ') << std::setw(76) << "++\n";
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(42) << std::setfill(' ') << std::setw(76) << "++\n";
	std::cout << std::setfill(' ') << std::setw(10) << "+" << std::setfill('+') << std::setw(77) << "\n";
}
