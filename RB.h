#ifndef RB_H
#define RB_H

#include "Player.h"

class RB : public Player {
private:
    int fumbles;
    double yardsPerCarry;
    int catches;
    int longestRun;

public:
    RB(const string& name, int gamesPlayed, int gamesStarted, const string& position,
       int fumbles, double ypc, int catches, int longestRun);

    void evaluatePerformance() override;

    void returnStatistics() override;

    void writeStatisticsToFile(ofstream& fout) override;
};

#endif // RB_H
