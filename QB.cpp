#include "QB.h"

QB::QB(const string& name, int gp, int gs, const string& pos,
       int passingTDs, int turnovers, double completionPct, double sucPerct, int gwd)
    : Player(name, gp, gs, pos), passingTouchdowns(passingTDs), turnovers(turnovers),
      completionPercentage(completionPct), successPercentage(sucPerct), gameWinningDrives(gwd) {}

void QB::evaluatePerformance()
{
	evaluation playerRating;

    if(passingTouchdowns < 2 && turnovers < 2)
    {
    	playerRating = BAD;
    }
    else
    {
    	if(completionPercentage < 0.6)
    	{
    		playerRating = BAD;
    	}
    	else
    	{
    		if(successPercentage < 40)
    		{
    			playerRating = BAD;
    		}
    		else
    		{
    			if(gameWinningDrives < 0.2)
    			{
    				playerRating = AVERAGE;
    			}
    			else
    			{
    				playerRating = GOOD;
    			}
    		}
    	}
    }

    changeEvaluation(playerRating);
    cout << "Quarterback Evaluation: " << this->getName() << " is a " << this->returnEvaluation() << '.' << endl;
}

void QB::returnStatistics()
{
	cout << "Statistics:" << endl;
	cout << "Passing TDs: " << passingTouchdowns << endl;
	cout << "Turnovers: "   << turnovers << endl;
	cout << "Completion %: " << completionPercentage << endl;
	cout << "Success %" << successPercentage << endl;
	cout << "Game Winning Drives: " << gameWinningDrives << endl;
	cout << endl;
}

void QB::writeStatisticsToFile(ofstream& fout)
{
	fout << passingTouchdowns << endl;
	fout << turnovers << endl;
	fout << completionPercentage << endl;
	fout << successPercentage << endl;
	fout << gameWinningDrives << endl;
	fout << endl;
}
