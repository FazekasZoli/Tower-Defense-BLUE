#include "CritterManager.h"

void CritterManager::createCrittersForGame()
{
	{
		_crittersForGame.resize(5);
		// 0. kör critterei
		/*for (int i = 0; i < 5; i++)
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
		}*/
		for (int j=0 ; j< _crittersForGame.size(); j++)
		{
			for (int i = 0; i < 5*(j+1); i++)
			{
				_crittersForGame[j].push_back(createCritter(NORMAL));

			}
			auto it = _crittersForGame[j].begin();
			for (int i=0; i <(j+1); i++)
			{
				(*it)->setSpeed(5);
				(*it)->setMaxLife(30);
				++it;
				++it;
			}
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
	if(!_startTimeIsValid)
	{
		_startTime = std::chrono::high_resolution_clock::now();
		_startTimeIsValid = true;
	}

	int i = 0;

	std::chrono::duration<double> diff = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - _startTime);

	for (auto &critterIt : _crittersForGame[actualRound])
	{

		if (i > std::min(_crittersForGame[actualRound].size(), static_cast<size_t>(diff.count() / 0.3)))
		{			
			//std::cout << "asd\n";
			//system("pause");
			break;
		} 
		if (critterIt->getIsAlive()) {
			(critterIt)->move(road);
		}

		if ((critterIt)->getPos() == road.back().first && critterIt->getIsAlive())
		{
			notifyCritterFinishedRoad();
			// mark critter death
			(critterIt)->setIsAlive(false);
		}
		i++;
	}
}

void CritterManager::resetCritters(Position &startPos)
{
	_startTimeIsValid = false;
	for (auto& level : _crittersForGame)
	{
		for (auto& critter : level)
		{
			critter->setLife(critter->getMaxLife());
			critter->setIsAlive(true);
			critter->setPosTw(startPos);
		}
	}
}

bool CritterManager::allCritterIsDead(int actualRound)
{
	for (auto &it : _crittersForGame[actualRound])
	{
		if (it->getIsAlive())
		{
			return false;
		}
	}
	return true;
}

void CritterManager::resetTimer()
{
	_startTimeIsValid = false;
}
