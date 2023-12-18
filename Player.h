#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

enum evaluation {
	GOOD,
	AVERAGE,
	BAD,
	DEFAULT
};

class Player {
protected:
    string name;
    int gamesPlayed;
    int gamesStarted;
    string position;
    evaluation evaluate;

public:
    // Constructor
    Player(const string& name, int gamesPlayed, int gamesStarted, const string& position);

    // Destructor
    virtual ~Player();

    // Pure virtual function for performance evaluation.
    virtual void evaluatePerformance() = 0;

    // Pure virtual function to return the attributes of each position.
    virtual void returnStatistics() = 0;

     // Pure virtual function to output statistics of a player to a file.
    virtual void writeStatisticsToFile(ofstream& fout) = 0;

    // Return the name of the player
    string getName();

    // Return the games played by the player
    int getGamesPlayed();

    // Return the games started by the player
    int getGamesStarted();

    // Return the position of the player
    string getPosition();

    // Change the player's evaluation
    void changeEvaluation(evaluation ranking);

    // Returns the player's evaluation in string format
    string returnEvaluation() const;

    // Overloading the stream insertion operator for output
    friend ostream& operator<<(ostream& os, const Player& player);
};

#endif // PLAYER_H
