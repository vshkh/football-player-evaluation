#ifndef QB_H
#define QB_H

#include "Player.h"

class QB : public Player {
private:
    int passingTouchdowns;
    int turnovers;
    double completionPercentage;
    double successPercentage;
    int gameWinningDrives;

public:
    QB(const string& name, int gamesPlayed, int gamesStarted, const string& position,
       int passingTDs, int turnovers, double completionPct, double sucPerct, int gameWinningDrives);

    void evaluatePerformance() override;

    void returnStatistics() override;

    void writeStatisticsToFile(ofstream& fout) override;
};

#endif // QB_H
