#include "View.h"
#include <iostream>

TowerButtons* TowerButtons::SelectedTower = nullptr;

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
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(76) << "++\n";
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(76) << "++\n";
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
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(51) << "      ____   " << std::setfill(' ') << std::setw(25) << "++\n";
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(49) << "   __|   _|" << std::setfill(' ') << std::setw(27) << "++\n";
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

	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(76) << "++\n";

	introTower();
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(76) << "++\n";
	std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(76) << "++\n";
	std::cout << std::setfill(' ') << std::setw(10) << "+" << std::setfill('+') << std::setw(77) << "\n";
	Sleep(500);
}

void View::displayMenu(size_t numberOfMaps)
{
	system("cls");
	menuState = 0;

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
			displayLevelSelect(NewGame, probaPalyaNevek, numberOfMaps);
			break;
		case 2:
			displayLevelSelect(LoadGame, probaPalyaNevek, 0);
			break;
		default:
			break;


		}
	} while (menuState > -1);
	//std::cout << "\n" << menuState;
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

	mainPpos = -1;
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
				notifyEndGameRequest();
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

void View::displayLevelSelect(LevelSelectMode mode, std::vector<std::string> &levels, int numberOfMaps)
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

	short pos = 0;
	char input;
	bool menuBool = true;

	//input = _getch();
	//Beep(723, 50);
	do
	{
		for (short i = 1; i <= numberOfMaps; i++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { push,3 + i * 3 });
			(pos == i - 1) ? SetConsoleTextAttribute(hOut, 8 + 16 * 14) : SetConsoleTextAttribute(hOut, 7);
			std::cout << i << ":\t" << levels[i - 1];
			SetConsoleTextAttribute(hOut, 7);
			(pos == i - 1) ? (std::cout << " <-") : std::cout << "   ";
		}

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { push,4 + ((short)numberOfMaps + 1) * 3 });
		(pos == numberOfMaps) ? SetConsoleTextAttribute(hOut, 8 + 16 * 14) : SetConsoleTextAttribute(hOut, 7);
		std::cout << "Back";
		SetConsoleTextAttribute(hOut, 7);
		(mainPpos == numberOfMaps) ? (std::cout << " <-") : std::cout << "   ";
		//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });

		input = _getch();
		switch (input)
		{
		case 'w':
			--pos;
			if (pos < 0)
				pos = (short)numberOfMaps;
			pos = pos % (numberOfMaps + 1);
			//Beep(723, 100);
			break;
		case 'W':
			--pos;
			if (pos < 0)
				pos = (short)numberOfMaps;
			pos = pos % (numberOfMaps + 1);
			//Beep(723, 100);
			break;
		case 's':
			++pos;
			pos = pos % (numberOfMaps + 1);
			//Beep(723, 100);
			break;
		case 'S':
			++pos;
			pos = pos % (numberOfMaps + 1);
			//Beep(723, 100);
			break;
		case '\r':
			if (pos == numberOfMaps)
			{

				system("cls");
				menuState = 0;
				return;
			}
			else
			{

				Beep(650, 100);
				// notify ide
				menuState = -1;
				notifySelectedLevel(pos);
				system("cls");
				std::cout << "\n" << levels[pos] << " nevu palya indul... WIP";// ehhes hasonlóan hivatkozhat a megfelelore Pályák tárolása vektorban pl
				//graphic();
				
				return;
			}

			break;
		case 27:
			Beep(400, 100);
			notifyEndGameRequest();
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

void View::displayGameOver(GameEnd status)
{
	if (status == WIN) 
	{
		system("cls");

		std::cout << "\n\n" << std::setfill(' ') << std::setw(10) << "+" << std::setfill('+') << std::setw(77) << "\n";
		std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(76) << "++\n";

		end();

		std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(76) << "++\n";
		std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(76) << "++\n";

		std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(76) << "++\n";
		std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(76) << "++\n";
		std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(76) << "++\n";
		std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(20) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(20) << "++\n";
		std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(23) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(23) << "++\n";
		std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(26) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(26) << "++\n";
		std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(29) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(29) << "++\n";
		std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(32) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(6) << " * " << std::setfill(' ') << std::setw(32) << "++\n";

		introTower();

		std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(76) << "++\n";
		std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(76) << "++\n";
		std::cout << std::setfill(' ') << std::setw(11) << "++" << std::setfill(' ') << std::setw(76) << "++\n";
		std::cout << std::setfill(' ') << std::setw(10) << "+" << std::setfill('+') << std::setw(77) << "\n";
	}
	else {

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
}

void View::updateGraphic()
{
	//std::cout << *playerLife << "\n";

	sf::Font font;
	playerLifeText.setString(std::to_string(*playerLife));
	playerMoneyText.setString(std::to_string(*playerMoneyV));
	auto asd = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	Position tmp(asd.x, asd.y);
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			notifyEndGameRequest();
			break;
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left) {
				if (buttonTowerProba.checkClick(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					for (auto &it: towerButtons)
					{
						it.setStateVar(false);
					}

					if (selectedButton == nullptr)
					{
						//sf::Window::ShowMouseCursor(false);
						window.setMouseCursorVisible(false);
						selectedButton = &buttonTowerProba;
					}
					else
					{
						window.setMouseCursorVisible(true);
						selectedButton = nullptr;
					}
				} else if (selectedButton == &buttonTowerProba && !gridPtr->isAreaBlocked(tmp))
				{
					selectedButton = nullptr;
					buttonTowerProba.setState(!buttonTowerProba.getVar());
					window.setMouseCursorVisible(true);
					
					notifyButtonClicked(buttonTowerProba.getType(), BASE, tmp);
				}
				else
				{
					TowerButtonsLogic();
				}


			}
			break;
		}
	}
	updateSprites();
	window.clear();
	window.draw(spriteBG);
	/*auto it = my_vector.rbegin(); it != my_vector.rend(); ++it
		RoadSprites*/

	for (auto &it : RoadSprites) { window.draw(it); }
	//for (int i = RoadSprites.size()-1; i > 0; --i) { window.draw(RoadSprites[i]); }
	for (auto it = sprites.rbegin(); it != sprites.rend(); ++it)
	{
		window.draw(*it);
	}
	//for (auto &it : towerSprites) { window.draw(it); }
	for (auto &it : towerButtons) {

		it.draw(window);
		//std::string asdasd = it.level.getString();
		//window.draw(it.level);
		it.level.setString(std::to_string(*it.levelPtr));
		window.draw(it.level);

	}
	//for (auto &it : towerButtons) {

	//	//it.draw(window);
	//	//std::string asdasd = it.level.getString();
	//	

	//}

	/*for (auto &it : towerButtons) {

		window.draw(it.level);
		
	}*/
	for (auto &it : towerButtons)
	{
		if (it.getVar())
		{

			window.draw(*it.getUpgradeButton()->getSpriteNorm());
			window.draw(*it.getSellButton()->getSpriteNorm());
			it.range.setRadius(*it.radPtr);
			
			//it.range.setOrigin((*it.radPtr)/2, (*it.radPtr)/2);
			it.range.setPosition(it.pos);
			it.range.setOrigin((*it.radPtr), (*it.radPtr));
			//sf::CircleShape tmpcirc = *it.getRangeCircPtr();
			window.draw(*it.getRangeCircPtr());


		}
	}

	window.draw(playerMoneyRizsa);
	window.draw(playerMoneyText);

	window.draw(playerLifeRizsa);
	window.draw(playerLifeText);
	window.draw(*buttonTowerProba.getSprite());
	if (selectedButton == &buttonTowerProba)
	{
		if (gridPtr->isAreaBlocked(Position(static_cast<int>(window.mapPixelToCoords(sf::Mouse::getPosition(window)).x),
											static_cast<int>(window.mapPixelToCoords(sf::Mouse::getPosition(window)).y))))
		{
			TowerShadySpriteRed.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
			radius.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
			window.draw(TowerShadySpriteRed);
			window.draw(radius);
		}
		else {
			TowerShadySprite.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
			radius.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
			window.draw(TowerShadySprite);
			window.draw(radius);
		}
	}

	if (notEoughMoneyBool && notEoughMoneyCounter<=25)
	{
		window.draw(notEoughMoney);
		++notEoughMoneyCounter;
	}


	window.display();

}

void View::setUpDisplay(std::list<std::shared_ptr<Critter>>& critterList, std::vector<std::shared_ptr<Tower>>& towerList, std::vector<std::pair<Position, Position>> &road, int* playerLifee, int * playerMoney, std::shared_ptr<Grid> gridPtr)
{
	playerMoneyV = playerMoney;
	selectedButton = nullptr;
	this->gridPtr = gridPtr;
	buttonTowerProba.setStateVar(false);
	newEntityFront.loadFromFile("pokeFront.png");
	newEntityBack.loadFromFile("pokeBack.png");
	newEntityLeft.loadFromFile("pokeLeft.png");
	newEntityRight.loadFromFile("pokeRight.png");
	/*auto itr = towerSprites.begin();
	while (itr != towerSprites.end())
	{
		delete *itr;
		*itr = nullptr;
		itr = objs.erase(itr);
		else
			++itr;
	}*/

	//towerSprites.clear();
	towerButtons.clear();
	crittersPtr = &critterList;
	towersPtr = &towerList;
	button1.loadFromFile("button1Tower.png");
	button2.loadFromFile("Button2Tower.png");
	sellButtonTex.loadFromFile("sellButton.png");
	upgradeButtonTex.loadFromFile("upgradeButton.png");
	buttonTowerProba.initialize(&button1, &button2, sf::Vector2f(450, 700), TowerPlace);
	playerLife = playerLifee;

	towerTex.loadFromFile("Tower1.png");
	TowerShady.loadFromFile("Tower2Shady.png");
	
	TowerShadySprite.setTexture(TowerShady);
	TowerShadySprite.setOrigin(25,25);

	TowerShadyRed.loadFromFile("Tower2ShadyDeny.png");
	TowerShadySpriteRed.setTexture(TowerShadyRed);
	TowerShadySpriteRed.setOrigin(25, 25);

	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "error loading font\n";
	}
	playerLifeText.setFont(font);
	playerLifeText.setString(std::to_string(*playerLife));
	playerLifeText.setCharacterSize(50); // in pixels, not points!
	playerLifeText.setFillColor(sf::Color::Red);
	playerLifeText.setStyle(sf::Text::Bold);
	playerLifeText.setPosition(900, 0);
	playerLifeText.setOutlineColor(sf::Color::Black);

	playerLifeRizsa.setFont(font);
	playerLifeRizsa.setStyle(sf::Text::Bold);
	playerLifeRizsa.setCharacterSize(50);
	playerLifeRizsa.setString("HP: ");
	playerLifeRizsa.setPosition(800, 0);
	playerLifeRizsa.setOutlineColor(sf::Color::Black);
	playerLifeRizsa.setOutlineThickness(2);

	playerMoneyText.setFont(font);
	playerMoneyText.setString(std::to_string(*playerMoneyV));
	playerMoneyText.setCharacterSize(50); // in pixels, not points!
	playerMoneyText.setFillColor(sf::Color::Yellow);
	playerMoneyText.setStyle(sf::Text::Bold);
	playerMoneyText.setPosition(500, 0);
	playerMoneyText.setOutlineColor(sf::Color::Black);

	playerMoneyRizsa.setFont(font);
	playerMoneyRizsa.setStyle(sf::Text::Bold);
	playerMoneyRizsa.setCharacterSize(50);
	playerMoneyRizsa.setString("$$: ");
	playerMoneyRizsa.setPosition(400, 0);
	playerMoneyRizsa.setFillColor(sf::Color::Yellow);
	playerMoneyRizsa.setOutlineColor(sf::Color::Black);
	playerMoneyRizsa.setOutlineThickness(2);

	radius.setOutlineColor(sf::Color::Yellow);
	radius.setOutlineThickness(3);
	radius.setRadius(baseRadius);
	radius.setOrigin(baseRadius, baseRadius);
	radius.setFillColor(sf::Color::Transparent);


	window.create(sf::VideoMode(1000, 800), "Tower defense");
	window.setPosition(sf::Vector2i(590, 0));
	window.setFramerateLimit(30);
	window.setVerticalSyncEnabled(true);

	grassTexture.create(1000, 800);
	
	grassTexture.setRepeated(true);

	if (!grassTexture.loadFromFile("grassTile.png")) {
		std::cout << "betoltes nem sikerult\n";
	}
	if (!routeTexture.loadFromFile("routeTile1.png")) {
		std::cout << "betoltes nem sikerult\n";
	}
	if (!entityTexture.loadFromFile("poke2.png")) {
		std::cout << "betoltes nem sikerult\n";
	}
	grassTexture2.loadFromFile("grassTile.png");
	grassTexture.setSmooth(true);
	routeTexture.setSmooth(true);
	entityTexture.setSmooth(true);


	spriteBG.setTexture(grassTexture);
	spriteBG.setTextureRect({ 0, 0, 1000, 800 });

	addNewSprites(critterList);
	addRouteSprites(road, routeTexture);
	//Buttons.emplace_back();

	notEoughMoney.setString("Nincs elég pénz :(");
	notEoughMoney.setCharacterSize(50);
	notEoughMoney.setFont(font);
	notEoughMoney.setStyle(sf::Text::Bold);
	notEoughMoney.setFillColor(sf::Color::Red);
	notEoughMoney.setOutlineColor(sf::Color::Black);
	notEoughMoney.setOutlineThickness(10);
	notEoughMoney.setPosition(300, 400);
	notEoughMoneyBool = false;
	notEoughMoneyCounter = 0;

	buffer.loadFromFile("nincstobbgaras2.wav");
	sound.setBuffer(buffer);

	grave.loadFromFile("grave3.png");
	

	updateGraphic();


}


void View::addSprites(std::list<std::shared_ptr<Critter>>& critterList, const sf::Texture &texture)
{
	
	for (size_t i = 0; i < critterList.size(); i++)
	{
		sprites.emplace_back();
		sprites[i].setTexture(texture);
		sprites[i].setOrigin(25,25);
		//std::next(sprites.begin(), i)->setScale(sf::Vector2f(0.1, 0.1));
		sprites[i].setPosition((*std::next(critterList.begin(), i))->getPos().x, (*std::next(critterList.begin(), i))->getPos().y);
	}
}

void View::addRouteSprites(std::vector<std::pair<Position, Position>>& road, const sf::Texture & texture)
{
	RoadSprites.clear();
	Position irany = road[0].second;
	Position pos = road[0].first;
	Position nextPoint = road[1].first;
	int size = texture.getSize().x;
	//system("pause");
	int sorsz = 0;
	for (size_t i = 1; i <= road.size(); i++)
	{
		while (!(pos == nextPoint))
		{
			RoadSprites.emplace_back();
			RoadSprites[sorsz].setTexture(texture);
			RoadSprites[sorsz].setPosition(pos.x, pos.y);
			RoadSprites[sorsz].setOrigin(25,25);
			/*std::cout << sorsz << ":\n";
			std::cout << pos.x << " " << pos.y << "\n";
			std::cout << irany.x << " " << irany.y << "\n";
			std::cout << nextPoint.x << " " << nextPoint.y << "\n\n";*/
			pos += irany *= size;
			++sorsz;

		}
		if (i < road.size())
		{
			nextPoint = road[i].first;
		}
		irany = road[i - 1].second;

	}
	RoadSprites.emplace_back();
	RoadSprites[sorsz].setTexture(texture);
	RoadSprites[sorsz].setPosition(pos.x, pos.y);
}

void View::updateSprites()
{
	Position up(0, -1);
	Position down(0, 1);
	Position left(-1, 0);
	Position right(1, 0);
	Position tmp;


	for (size_t i = 0; i < crittersPtr->size(); i++)
	{
		if ((*std::next(crittersPtr->begin(), i))->getLife()>0) {
			sprites[i].setPosition((*std::next(crittersPtr->begin(), i))->getPos().x, (*std::next(crittersPtr->begin(), i))->getPos().y);
			tmp = (*std::next(crittersPtr->begin(), i))->getDir();
			if (tmp == down)
			{
				sprites[i].setTexture(newEntityFront);
			}
			else if (tmp == up)
			{
				sprites[i].setTexture(newEntityBack);
			}
			else if (tmp == left)
			{
				sprites[i].setTexture(newEntityLeft);
			}
			else if (tmp == right)
			{
				sprites[i].setTexture(newEntityRight);
			}
		}
		else
		{
			sprites[i].setTexture(grave);
		}
	}
}

void View::addNewTower()
{
	//system("pause");

	//towerSprites.emplace_back();
	//towerSprites[towersPtr->size()-1].setTexture(towerTex);
	//towerSprites[towersPtr->size() - 1].setOrigin(25,25);
	////std::next(sprites.begin(), i)->setScale(sf::Vector2f(0.1, 0.1));
	//towerSprites[towersPtr->size() - 1].setPosition(towersPtr->back()->getPosition().x, towersPtr->back()->getPosition().y);

	towerButtons.emplace_back();
	towerButtons.back().initialize(&towerTex, &towerTex, sf::Vector2f(towersPtr->back()->getPos().x, towersPtr->back()->getPos().y), OwnTower);
	towerButtons.back().getSpriteNorm()->setOrigin(25, 25);
	//towerButtons.back().setBG(grassTexture2);

	towerButtons.back().getSellButton()->initialize(&sellButtonTex, &sellButtonTex, sf::Vector2f(towersPtr->back()->getPos().x +40, towersPtr->back()->getPos().y), TowerSell);
	towerButtons.back().getUpgradeButton()->initialize(&upgradeButtonTex, &upgradeButtonTex, sf::Vector2f(towersPtr->back()->getPos().x - 40, towersPtr->back()->getPos().y), TowerUpgrade);
	towerButtons.back().getSellButton()->getSpriteNorm()->setOrigin(15, 15);
	towerButtons.back().getUpgradeButton()->getSpriteNorm()->setOrigin(15, 15);
	towerButtons.back().setLevelPtr(towersPtr->back()->getLevelPtr());
	towerButtons.back().radPtr = towersPtr->back()->getAttackRangePtr();
	towerButtons.back().levelTextini(&font);
	
	
}

void View::addNotEnoughMoneyError()
{
	notEoughMoneyBool = true;
	notEoughMoneyCounter = 0;
}

void View::playNotEnoughMoneySound()
{
	sound.play();
}

void View::removeTower(Position & towerPos)
{
	Position tmp;
	for (auto it=towerButtons.begin(); it != towerButtons.end();++it)
	{
		tmp.x = it->getSpriteNorm()->getPosition().x;
		tmp.y = it->getSpriteNorm()->getPosition().y;
		if (tmp == towerPos) {
			towerButtons.erase(it);
			return;
		}
	}
}

void View::closeWindow()
{
	window.close();
}

void View::addNewSprites(std::list<std::shared_ptr<Critter>>& critterList)
{

	crittersPtr = &critterList;
	sprites.clear();
	addSprites(critterList, newEntityFront);
}

void View::TowerButtonsLogic()
{
	auto tmp = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	for (auto &it: towerButtons)
	{		
		if (it.getVar())
		{
			std::cout << "\nasdfghjk\n";
			if (it.getUpgradeButton()->checkClick(tmp))
			{
				notifyButtonClicked(it.getUpgradeButton()->getType(),0, Position(it.getSpriteNorm()->getPosition().x, it.getSpriteNorm()->getPosition().y) );
				std::cout << "tower upgraded";
				it.setStateVar(false);
				return;
			}
			if (it.getSellButton()->checkClick(tmp))
			{
				notifyButtonClicked(it.getSellButton()->getType(), 0, Position(it.getSpriteNorm()->getPosition().x, it.getSpriteNorm()->getPosition().y));
				std::cout << "tower sold";
				it.setStateVar(false);
				return;
			}
			//TowerButtons::SelectedTower->setStateVar(false);
			//TowerButtons::SelectedTower = nullptr;
			
			//std::cout << "DEselected          aaaaaaaaaaaa\n";
		}
		if (it.checkClickTower(tmp))
		{
			if (!it.getVar()) {

				//std::cout << "selected\n";
				for (auto &it2 : towerButtons)
				{
					it2.setStateVar(false);
				}
				it.setStateVar(true);
			}
			else if (it.getVar())
			{
				it.setStateVar(false);
			}

		}

	}
}


//Buttons
void Button::initialize(sf::Texture* normal, sf::Texture* clicked, sf::Vector2f location, ButtonType ownType) {
	this->normal.setTexture(*normal);
	//this->normal.setOrigin(0,150);
	this->clicked.setTexture(*clicked);
	//this->clicked.setOrigin(0, 143);
	pos = location;
	this->normal.setPosition(location);
	this->clicked.setPosition(location);
	currentSpr = &this->normal;
	current = false;

	//string.setString(words);
	//string.setPosition(location.x + 3, location.y + 3);
	//string.setCharacterSize(4);
	this->ownType = ownType;
	
}

bool Button::checkClick(sf::Vector2f mousePos) {

	if (mousePos.x > (getSpriteNorm()->getPosition().x - getSpriteNorm()->getOrigin().x) && mousePos.x < (getSpriteNorm()->getPosition().x + getSpriteNorm()->getTexture()->getSize().x - getSpriteNorm()->getOrigin().x)) {
		if (mousePos.y > (getSpriteNorm()->getPosition().y - getSpriteNorm()->getOrigin().y) && mousePos.y < (getSpriteNorm()->getPosition().y + getSpriteNorm()->getTexture()->getSize().y - getSpriteNorm()->getOrigin().y)) {
			setState(!current);
			return true;
		}
	}
	return false;
}
void Button::setState(bool which) {
	current = which;
	if (current) {
		currentSpr = &clicked;
		return;
	}
	currentSpr = &normal;
}
void Button::setStateVar(bool which)
{
	current = which;
}
//void Button::setText(std::string words) {
//	string.setString(words);
//}
//sf::String * Button::getText() {
//	return &String;
//}
bool Button::getVar() {
	return current;
}
sf::Sprite* Button::getSprite() {
	return currentSpr;
}

sf::Sprite * Button::getSpriteNorm()
{
	return &this->normal;
}



ButtonType Button::getType()
{
	return ownType;
}


TowerButtons::TowerButtons()
{
}

TowerButtons::~TowerButtons()
{
}

//void TowerButtons::setBG(sf::Texture bg)
//{
//	backgroundGrass.setTexture(bg);
//	backgroundGrass.setOrigin(25,25);
//	backgroundGrass.setPosition(this->getSpriteNorm()->getPosition());
//}

void TowerButtons::draw(sf::RenderWindow & window)
{
	//std::cout << "rajz\n";
	//window->draw(backgroundGrass);
	
	window.draw(*(this->getSpriteNorm()));
	

	//if (this->getVar())
	//{
	//	//std::cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n";
	//	window->draw(*this->upgradeButton.getSpriteNorm());
	//	window->draw(*this->sellButton.getSpriteNorm());
	//}
}

void TowerButtons::drawLevel(sf::RenderWindow & window)
{

	std::string tmpasd = std::to_string((*levelPtr));
	level.setString(std::to_string((*levelPtr)));
	window.draw(level);

}

bool TowerButtons::checkClickTower(sf::Vector2f mousePos)
{
	if (mousePos.x > (getSpriteNorm()->getPosition().x- getSpriteNorm()->getOrigin().x) && mousePos.x < (getSpriteNorm()->getPosition().x + getSpriteNorm()->getTexture()->getSize().x- getSpriteNorm()->getOrigin().x)) {
		if (mousePos.y > (getSpriteNorm()->getPosition().y- getSpriteNorm()->getOrigin().y) && mousePos.y < (getSpriteNorm()->getPosition().y + getSpriteNorm()->getTexture()->getSize().y- getSpriteNorm()->getOrigin().y)) {
			//setState(!current);
			return true;
		}
	}
	return false;
}

void TowerButtons::setLevelPtr(int * levelptr)
{
	levelPtr = levelptr;


}

void TowerButtons::levelTextini(sf::Font *font)
{
	
	//std::string asdas = ;
	level.setString(std::to_string(*levelPtr));
	//std::cout << "\n" << asdas << "\n";
	level.setFont(*font);
	level.setPosition(this->getSpriteNorm()->getPosition());
	level.setFillColor(sf::Color::Yellow);
	level.setOutlineColor(sf::Color::Black);
	level.setOutlineThickness(5);
	level.setCharacterSize(20);

	range.setOutlineColor(sf::Color::Yellow);
	range.setOutlineThickness(3);
	range.setRadius(*radPtr);

	//range.setOrigin(this->getSpriteNorm()->getPosition());
	
	range.setFillColor(sf::Color::Transparent);

}





