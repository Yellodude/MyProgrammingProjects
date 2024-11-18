#include "Match.h"
#include "iomanip"
#include "algorithm"
using namespace std;

Match::Match() {
    teamName = "";
    matchLocation = ""; 
    matchOpposition = "";
    matchDate = Date();
    matchCoach = Coach();
}

Match::Match(string tName, string loc, string opp, Date mDate) {
    teamName = tName;
    matchLocation = loc;
    matchOpposition = opp;
    matchDate = mDate;
}

void Match::setCoach(const Coach& coach) {
    matchCoach = coach;
}

void Match::addPlayer(const Player& player) {
    players.push_back(player);
}

void Match::sortPlayers() {
    sort(players.begin(), players.end(), 
       [](const Player& lpl, const Player& rpl) {
        return lpl.getLastName() < rpl.getLastName();
        });
}

void Match::printMatchInfo(ostream& out) const {
    system("cls");
    out << "Match Information" << endl << endl;
    out << setw(40) << right << "Match Date: " << matchDate << endl;
    out << setw(40) << right << "Team Name: " << teamName << endl;
    out << setw(40) << right << "Match Location: " << matchLocation << endl;
    out << setw(40) << right << "Match Opponent: " << matchOpposition << endl;
    out << "\nCOACH\n" << matchCoach << endl;
    out << "\nPLAYERS" << endl;
    int count = 1;
    for (const auto& player : players) {
        out << setw(37) << right << "#" << count << ":" << endl;
        out << player;
        count++;
    }
}

ostream& operator<<(ostream& out, const Match& match) {
    match.printMatchInfo(out);
    return out;
}
