#ifndef RECEIVER_H
#define RECEIVER_H

#include "Player.h"

class Receiver : public Player {
private:
    double catchPercentage;
    int drops;
    int yards;
    double yardsPerCatch;

public:
    Receiver(const string& name, int gamesPlayed, int gamesStarted, const string& position,
             double catchPerct, int drops, int yards, double ypc);

    void evaluatePerformance() override;

    void returnStatistics() override;

    void writeStatisticsToFile(ofstream& fout) override;
};

#endif
