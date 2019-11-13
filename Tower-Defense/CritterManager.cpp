#include "CritterManager.h"

void CritterManager::createCrittersForGame()
{
	{
		_crittersForGame.resize(3);
		// 0. kör critterei
		for (int i = 0; i < 5; i++)
		{
			_crittersForGame[0].push_back(createCritter(NORMAL));
		}

		for (int i = 0; i < 10; i++)
		{
			_crittersForGame[1].push_back(createCritter(NORMAL));
		}

		for (int i = 0; i < 15; i++)
		{
			_crittersForGame[2].push_back(createCritter(NORMAL));
		}
	}
}

CritterManager::CritterManager()
{
	// add normal critter template
	std::shared_ptr<Critter>critter_ptr(new Critter);
	_critterTemplates.insert(std::make_pair(NORMAL, critter_ptr));

	createCrittersForGame();

	_startTime = std::chrono::high_resolution_clock::now();
}

std::list<std::shared_ptr<Critter>>& CritterManager::getCrittersForRound(int actualRound)
{
	return _crittersForGame[actualRound];
}

std::shared_ptr<Critter> CritterManager::createCritter(CritterType critterType)
{
	return _critterTemplates[critterType]->clone();
}

void CritterManager::moveActualRoundCritters(int actualRound, const std::vector<std::pair<Position, Position>>& road)
{
	int i = 0;
	
	std::chrono::duration<double> diff = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - _startTime);

	for (auto critterIt = _crittersForGame[actualRound].begin(); critterIt != _crittersForGame[actualRound].end(); critterIt++)
	{
		if (i > std::min(_crittersForGame[actualRound].size(), static_cast<size_t>(diff.count() / 0.3)))
		{
			//std::cout << "asd\n";
			//system("pause");
			break;
		} 
		
		(*critterIt)->move(road);

		if ((*critterIt)->getPos() == road.back().first)
		{
			notifyCritterFinishedRoad();
			// mark critter death
			(*critterIt)->setIsAlive(false);
		}

		i++;
	}
}

void CritterManager::resurectCritters(int actualRound)
{
	for (auto& critter : _crittersForGame[actualRound])
	{
		critter->setLife(10);
	}
}
