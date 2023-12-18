#include "RB.h"

RB::RB(const string& name, int gp, int gs, const string& pos,
       int fumbles, double ypc, int catches, int lr)
    : Player(name, gp, gs, pos), fumbles(fumbles), yardsPerCarry(ypc), catches(catches), longestRun(lr) {}

void RB::evaluatePerformance()
{
	evaluation playerRating;

	if(fumbles < 2)
	{
		playerRating = BAD;
	}
	else
	{
		if(yardsPerCarry < 3.5)
		{
			playerRating = BAD;
		}
		else
		{
			if(catches < 20)
			{
				playerRating = BAD;
			}
			else
			{
				if(longestRun < 40)
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

	cout << "Runningback Evaluation: " << this->getName() << " is a " << returnEvaluation() << "." << endl;
}

void RB::returnStatistics()
{
	cout << "Statistics:" << endl;
	cout << "Fumbles: " << fumbles << endl;
	cout << "Yards Per Carry: " << yardsPerCarry << endl;
	cout << "Catches: " << catches << endl;
	cout << "Longest Run: " << longestRun << endl;
	cout << endl;
}

void RB::writeStatisticsToFile(ofstream& fout)
{
	fout << fumbles << endl;
	fout << yardsPerCarry << endl;
	fout << catches << endl;
	fout << longestRun << endl;
	fout << endl;
}
