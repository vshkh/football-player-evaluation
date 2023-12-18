#include "Receiver.h"

Receiver::Receiver(const string& name, int gp, int gs, const string& pos,
                   double catchPerct, int drops, int yards, double ypc)
    : Player(name, gp, gs, pos), catchPercentage(catchPerct), drops(drops), yards(yards), yardsPerCatch(ypc) {}

void Receiver::evaluatePerformance()
{
	evaluation playerRating;

	if(catchPercentage < 0.5)
	{
		playerRating = BAD;
	}
	else
	{
		if(drops > 5)
		{
			playerRating = BAD;
		}
		else
		{
			if(yards < 500)
			{
				playerRating = BAD;
			}
			else
			{
				if(yardsPerCatch < 10)
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
	cout << "Receiver Evaluation: " << this->getName() << " is a " << returnEvaluation() << "." << endl;
}

void Receiver::returnStatistics()
{
	cout << "Statistics:" << endl;
	cout << "Catch %: " << catchPercentage << endl;
	cout << "Drops: " << drops << endl;
	cout << "Yards: " << yards << endl;
	cout << "Yards Per Catch: " << yardsPerCatch << endl;
	cout << endl;
}

void Receiver::writeStatisticsToFile(ofstream& fout)
{
	fout << catchPercentage << endl;
	fout << drops << endl;
	fout << yards << endl;
	fout << yardsPerCatch << endl;
}
