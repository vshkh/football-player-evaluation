#include "Team.h"

Team::Team(string teamName)
{
	this->teamName = teamName;
}

Team::~Team()
{
	for(Player* player: players)
	{
		delete player;
	}
}

void Team::addPlayer(Player *player)
{
	players.push_back(player);
}

Player* Team::findPlayer(string &name)
{
    for (Player* player : players)
    {
        if (player->getName() == name)
        {
        	outputPlayerInfo(player);
            return player;
        }
    }
    cout << "Player Not Found!" << endl;
    return nullptr;
}

void Team::removePlayer(string &name)
{

}

void Team::readQBData(string &fileName)
{
    string tempName;
    int tempGP, tempGS;
    string tempPos;
    int tempPT;
    int tempTurn;
    double tempCP, tempSP;
    int tempGWD;

    // Open the file
    inFile.open(fileName.c_str());

    if (!inFile.is_open())
    {
        cerr << "Error opening file: " << fileName << endl;
        return;
    }

    // Read through the provided file
    while(!inFile.eof())
    {
		getline(inFile, tempName);
		inFile >> tempGP >> tempGS;
		inFile.ignore(1000, '\n');
		getline(inFile, tempPos);
		inFile >> tempPT >> tempTurn >> tempCP >> tempSP >> tempGWD;
		inFile.ignore(1000, '\n');
		inFile.ignore(1000, '\n');

		QB* tempQB = new QB(tempName, tempGP, tempGS, tempPos, tempPT, tempTurn, tempCP, tempSP, tempGWD);

		players.push_back(tempQB);
    }

    // Close the file
    inFile.close();
}


void Team::readRBData(string &fileName)
{
	string tempName;
	int tempGP, tempGS;
	string tempPos;
	int tempFumbles;
	double tempYPC;
	int tempCatch, tempLongRun;

	inFile.open(fileName.c_str());

	if (!inFile.is_open())
	{
		cerr << "Error opening file: " << fileName << endl;
		return;
	}

	while(!inFile.eof())
	{
		getline(inFile, tempName);
		inFile >> tempGP >> tempGS;
		inFile.ignore(1000, '\n');
		getline(inFile, tempPos);
		inFile >> tempFumbles >> tempYPC >> tempCatch >> tempLongRun;
		inFile.ignore(1000, '\n');
		inFile.ignore(1000, '\n');

		RB* tempRB = new RB(tempName, tempGP, tempGS, tempPos, tempFumbles,
				tempYPC, tempCatch, tempLongRun);

		players.push_back(tempRB);
	}

	// Close the file
	inFile.close();
}

void Team::readReceiverData(string &fileName)
{
    string tempName;
    int tempGP, tempGS;
    string tempPos;
    double tempCatches;
    int tempDrops, tempYards;
    double tempYPC;

    inFile.open(fileName.c_str());

    if (!inFile.is_open())
    {
        cerr << "Error opening file: " << fileName << endl;
        return;
    }

    while(!inFile.eof())
    {
        getline(inFile, tempName);
        inFile >> tempGP >> tempGS;
        inFile.ignore(1000, '\n');
		getline(inFile, tempPos);
		inFile >> tempCatches >> tempDrops >> tempYards >> tempYPC;
        inFile.ignore(1000, '\n');
        inFile.ignore(1000, '\n');

        Receiver *tempReceiver = new Receiver(tempName, tempGP, tempGS, tempPos,
                                              tempCatches, tempDrops, tempYards, tempYPC);

        players.push_back(tempReceiver);
    }

    // Close the file
    inFile.close();
}


void Team::printTeamInformation()
{
	cout << "Printing information for Team: " << teamName << endl << endl;

	for(Player* player : players)
	{
		cout << *player << endl;
		player->returnStatistics();
	}
}

void Team::filterPlayerByEvaluation(string eval)
{
	string     storeEval;

	cout << "---------------------------------------" << endl;
	cout << "Filtering for: " << eval << " Players: " << endl;
	cout << "---------------------------------------" << endl;
	if(eval == "Good")
	{
		storeEval = "Good Player";

		for(Player* player : players )
		{
			if(player->returnEvaluation() == storeEval)
			{
				cout << *player << endl;
				player -> returnStatistics();
			}
		}
	}
	else if(eval == "Average")
	{
		storeEval = "Average Player";
		for(Player* player : players )
		{
			if(player->returnEvaluation() == storeEval)
			{
				cout << *player << endl;
				player -> returnStatistics();
			}
		}
	}
	else if(eval == "Bad")
	{
		storeEval = "Bad Player";
		for(Player* player : players )
		{
			if(player->returnEvaluation() == storeEval)
			{
				cout << *player << endl;
				player -> returnStatistics();
			}
		}
	}
	else
	{
		cout << "The following evaluations possible are: Good, Average, Bad." << endl;
	}
}

void Team::outputPlayerInfo(Player *player)
{
	cout << "---------------------------------------"   << endl;
	cout << "Returning Info for: " << player->getName() << endl;
	cout << "---------------------------------------"   << endl;
	cout << *player;
	cout << endl;
	player->returnStatistics();
}

void Team::writeTeamData(string &fileName)
{
	outFile.open(fileName.c_str());

	for(Player* player : players)
	{
		outFile << player->getName();
		outFile << endl;
		outFile << player->getGamesPlayed();
		outFile << endl;
		outFile << player->getGamesStarted();
		outFile << endl;
		outFile << player->getPosition();
		outFile << endl;
		outFile << player->returnEvaluation();
		outFile << endl;
		player->writeStatisticsToFile(outFile);
	}

	// Close the file
	outFile.close();
}

void Team::evaluatePlayers()
{
	for(Player* player : players)
	{
		player->evaluatePerformance();
	}
}
