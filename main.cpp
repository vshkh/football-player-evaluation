#include "Team.h"
#include "QB.h"
#include "RB.h"
#include "Receiver.h"

using namespace std;

int main() {
	string qb_data = "qbs.txt";
	string rb_data = "rb.txt";
	string receiver_data = "receiver.txt";
	string output_data   = "output.txt";
	string testPlayer  = "Aaron Rodgers";
	string testPlayer2 = "Tiger Woods";

    Team myTeam("MyTeam");

    myTeam.readQBData(qb_data);
    myTeam.readRBData(rb_data);
    myTeam.readReceiverData(receiver_data);
    myTeam.printTeamInformation();

    myTeam.evaluatePlayers();

    myTeam.filterPlayerByEvaluation("Bad");
    myTeam.findPlayer(testPlayer2);

    myTeam.writeTeamData(output_data);


    return 0;
}
