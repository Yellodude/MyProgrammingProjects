#include "Player.h"
#include "iomanip"
using namespace std;

Player::Player() {
    Person;
    jerseyNumber = "";
    position = "";
    averagePoints = 0;
    skillLevel = "";
    yearsPlayed = 0;
    graduationDate;
}

Player::Player(
    string fName, string lName, Date bDate,
    Date gradDate, int yearsPl,string jerseyNum, 
    string pos, double avgPoints, string skillLvl) {
    setPerson(fName, lName, bDate);
    yearsPlayed = yearsPl;
    graduationDate = gradDate;
    jerseyNumber = jerseyNum;
    position = pos;
    averagePoints = avgPoints;
    skillLevel = skillLvl;
}

Player::~Player() {}

string Player::getJerseyNumber() const { return jerseyNumber; }
string Player::getPosition() const { return position; }
double Player::getAveragePoints() const { return averagePoints; }
string Player::getSkillLevel() const { return skillLevel; }

void Player::setJerseyNumber(string jerseyNum) { jerseyNumber = jerseyNum; }
void Player::setPosition(string pos) { position = pos; }
void Player::setAveragePoints(double avgPoints) { averagePoints = avgPoints; }
void Player::setSkillLevel(string skillLvl) { skillLevel = skillLvl; }

void Player::printInfo(ostream& out) const {
    out << setw(40) << right << "Name - Position: " << firstName << ", " << lastName << " - " << position << endl;
    out << setw(40) << right << "Jersey #: " << jerseyNumber << endl;
    out << setw(40) << right << "Birth Date: " << birthDate << endl;
    out << setw(40) << right << "Years Played: " << yearsPlayed << endl;
    out << setw(40) << right << "Graduation Date: " << graduationDate << endl;
    out << setw(40) << right << "Skill Level: " << skillLevel << endl;
    out << setw(40) << right << "Average Points per Game: " << averagePoints << endl << endl;
}

ostream& operator<<(ostream& out, const Player& player) {
    player.printInfo(out);
    return out;
}
