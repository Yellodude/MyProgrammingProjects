#pragma once
// Include statements
#include "Player.h"
#include "Coach.h"
#include <vector>

// the purpose of this class is to create match
// objects without needing to access implementation.
// It uses operator overloading on the console display
// function
class Match {
private:
    // Variable declarations
    std::string teamName;
    std::string matchLocation;
    std::string matchOpposition;
    Date matchDate;
    Coach matchCoach;
    std::vector<Player> players;

public:
    // Constructors
    Match();
    Match(std::string, std::string, std::string, Date);
    // Setters
    void setCoach(const Coach&);
    // Additional functions
    void addPlayer(const Player&);
    void sortPlayers();

    // Following function displays match info on console
    void printMatchInfo(std::ostream& out) const;
    // Operator overloading for printing match information
    friend std::ostream& operator<<(std::ostream&, const Match&);
};
