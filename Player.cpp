#include "Player.h"

// Constructor
Player::Player(const string& name, int gp, int gs, const string& pos)
    : name(name), gamesPlayed(gp), gamesStarted(gs), position(pos), evaluate(BAD) {}

// Virtual Destructor
Player::~Player() {}

string Player::getName()
{
	return name;
}

int Player::getGamesPlayed()
{
	return gamesPlayed;
}

int Player::getGamesStarted()
{
	return gamesStarted;
}

string Player::getPosition()
{
	return position;
}

void Player::changeEvaluation(evaluation ranking)
{
	evaluate = ranking;
}

string Player::returnEvaluation() const
{
	switch(evaluate)
	{
		case GOOD:		return "Good Player";
		case AVERAGE:	return "Average Player";
		case BAD:		return "Bad Player";
		case DEFAULT:   return "Unevaluated";
	}

	return 0;
}

// Overloading the stream insertion operator for Player objects
ostream& operator<<(ostream& os, const Player& player) {
    os << "Name: " << player.name << "\n"
       << "Games Played: " << player.gamesPlayed << "\n"
       << "Games Started: " << player.gamesStarted << "\n"
       << "Position: " << player.position << "\n"
	   << "Evaluation: " << player.returnEvaluation() << endl;
    return os;
}
