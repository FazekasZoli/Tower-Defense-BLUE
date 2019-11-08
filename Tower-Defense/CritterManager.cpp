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
}

std::shared_ptr<Critter> CritterManager::createCritter(CritterType critterType)
{
	return _critterTemplates[critterType]->clone();
}

void CritterManager::moveActualRoundCritters(int actualRound, const std::vector<std::pair<Position, Position>>& road)
{
	for (auto critter : _crittersForGame[actualRound])
	{
		critter->move(road);

		if (critter->getPos() == road.back().first)
		{
			notifyCritterFinishedRoad(critter);

			// mark critter death

		}
	}
}
