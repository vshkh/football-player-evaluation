#include "Player.h"
#include "QB.h"
#include "RB.h"
#include "Receiver.h"

#include<vector>
#include<fstream>
#include<sstream>

#ifndef TEAM_H_
#define TEAM_H_

class Team {
private:
	string teamName;
	vector<Player*> players;
	ifstream inFile;
	ofstream outFile;

public:
	Team(string teamName);
	virtual ~Team();

	// Adds a player to a team.
	void    addPlayer(Player* player);

	// Removes a player given a name if they exist, otherwise does nothing.
	void    removePlayer(string& name);

	// Finds and returns a player if they exist, otherwise does nothing.
	Player* findPlayer(string& name);

	// Output information of player
	void    outputPlayerInfo(Player* player);

	void    filterPlayerByEvaluation(string eval);

	// Reads quarterback data and adds into a team.
	void    readQBData(string& fileName);

	// Reads runningback data and adds into a team.
	void    readRBData(string& fileName);

	// Reads receiver data and adds into a team.
	void    readReceiverData(string& fileName);

	// Outputs information relevant to each player on a team.
	void    printTeamInformation();

	// Outputs information of each player into an output file.
	void    writeTeamData(string& fileName);

	// Runs a function evaluating every player on the team.
	void    evaluatePlayers();
};

#endif
