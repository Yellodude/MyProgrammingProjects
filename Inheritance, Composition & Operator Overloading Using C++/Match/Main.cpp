//A program that collects data on a volleyball team and their upcoming match 
// and creates a report for the team.

// Include Statements
#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
#include <string>
#include <iomanip>
#include "Date.h"
#include "Player.h"
#include "Coach.h"
#include "Match.h"
using namespace std;


// Following function pauses and waits for user to enter to continue
void pressEnterToContinue() {
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("pause");
}


// Following function tokenizes the date entered by the user
void tokenizeDate(char* cDate, int& month, int& day, int& year)
{
    char seps[] = "/";
    char* token = NULL;
    char* next_token = NULL;

    token = NULL;
    next_token = NULL;
    // Establish string and get the tokens: 
    token = strtok_s(cDate, seps, &next_token);
    month = atoi(token);
    token = strtok_s(NULL, seps, &next_token);
    day = atoi(token);
    token = strtok_s(NULL, seps, &next_token);
    year = atoi(token);
}


// Function to input a date from the user
Date inputDate() {
    int day, month, year;
    char cDate[11];
    cin >> cDate;
    tokenizeDate(cDate, month, day, year);
    return Date(day, month, year);
}


// the purpose of this project is to generate a report on a volleyball team
// using inheritance techniques and operator overloading
int main() {
    cout << "Volleyball Match\n" << endl;

    // Match form variables
    string teamName, matchLocation, matchOpponent;
    Date matchDate;
    Match volleyballMatch;

    // Match form filled by the user
    cout << "\nTeam Name: ";
    getline(cin, teamName);
    cout << "\nMatch Location: ";
    getline(cin, matchLocation);
    cout << "\nMatch Opponent: ";
    getline(cin, matchOpponent);
    cout << "\nMatch Date (mm/dd/yyyy): ";
    matchDate = inputDate();
    // Following line creates an instance of Match to commence the match.
    volleyballMatch = Match(teamName, matchLocation, matchOpponent, matchDate);
    cout << endl;
    pressEnterToContinue();


    /* Menu and user interaction loop */
    // Menu variables
    char selection;
    bool coachIsPresent = false;
    vector<Player> players;
    // Menu loop
    while (true) {
        system("cls");
        cout << "Main Menu\n" << endl;
        cout << "C -- Add coach\n";
        cout << "P -- Add Player (" << players.size() << " of 3 Players entered)\n";
        cout << "L -- List Match Information\n";
        cout << "Q -- Quit\n";
        cout << "\nSelection: ";
        cin >> selection;
        selection = toupper(selection); // handle both upper and lower case


        if (selection == 'C') {
            if (coachIsPresent) {
                cout << "A coach has already been assigned for this match.\n";
                pressEnterToContinue();
                continue;
            }

            /* Entering Coach Information */
            // Coach variables
            string firstName; 
            string lastName;
            string title;
            Date birthdate, hireDate;
            double salary;
            int yearsCoached;
            // Coach Details
            system("cls");
            cout << setw(40) << right << "Enter Coach for Match:\n" << endl;
            cin.ignore(); // clear input buffer
            cout << setw(40) << right << "First Name: ";
            getline(cin, firstName);
            cout << setw(40) << right << "Last Name: ";
            getline(cin, lastName);
            cout << setw(40) << right << "Jersey Number: " << "00" << endl;
            cout << setw(40) << right << "Birth Date (mm/dd/yyyy): ";
            birthdate = inputDate();
            cout << setw(40) << right << "Years Coached (whole number only): ";
            cin >> yearsCoached;
            cout << setw(40) << right << "Hire Date (mm/dd/yyyy): ";
            hireDate = inputDate();
            cin.ignore(); // clear input buffer
            cout << setw(40) << right << "Title: ";
            getline(cin, title);
            cout << setw(40) << right << "Annual Salary: ";
            cin >> salary;

            // Following line create a coach instance with the user-updated variables.
            Coach coach(firstName, lastName, birthdate, title, hireDate, salary, yearsCoached);
            // Following line adds the coach variable above to the match instance.
            volleyballMatch.setCoach(coach);
            // Updater for coach status in match
            coachIsPresent = true;
            cout << endl;
            pressEnterToContinue();
        }
        else if (selection == 'P') {
            if (players.size() >= 3) {
                cout << "All three players have already been assigned. Operation canceled.\n";
                pressEnterToContinue();
                continue;
            }

            // Input player details
            string firstName, lastName, jerseyNumber, position, skillLevel;
            Date birthdate, graduationDate;
            double avgPoints;
            int yearsPlayed;

            cin.ignore(); // clear input buffer
            system("cls");
            cout << setw(40) << right << "Enter Player #" << players.size() + 1 << ":" << endl << endl;
            cout << setw(40) << right << "First Name: ";
            getline(cin, firstName);
            cout << setw(40) << right << "Last Name: ";
            getline(cin, lastName);
            cout << setw(40) << right << "Jersey Number: ";
            getline(cin, jerseyNumber);
            cout << setw(40) << right << "Birth Date (mm/dd/yyyy): ";
            birthdate = inputDate();
            cin.ignore(); // clear input buffer
            cout << setw(40) << right << "Years Played (whole number only): ";
            cin >> yearsPlayed;
            cout << setw(40) << right << "Graduation Date (mm/dd/yyyy): ";
            graduationDate = inputDate();
            cin.ignore(); // clear input buffer
            cout << setw(40) << right << "Position (e.g., Setter, Blocker): ";
            getline(cin, position);
            cout << setw(40) << right << "Points Average Per Game: ";
            cin >> avgPoints;
            cin.ignore(); // clear input buffer
            cout << setw(40) << right << "Skill Level (Intermediate, Advanced): ";
            getline(cin, skillLevel);

            Player player(firstName, lastName, birthdate, graduationDate, yearsPlayed, jerseyNumber, position, avgPoints, skillLevel);
            players.push_back(player);
            volleyballMatch.addPlayer(player);
            
            cout << endl << endl;
            pressEnterToContinue();
        }
        else if (selection == 'L') {
     
            if (!coachIsPresent) {
                cout << "A coach has not been assigned for this match. Operation canceled.\n";
            }
            if (players.size() < 3) {
                cout << "One or more of the three required players are missing.\n";
            }
            if (coachIsPresent && players.size() == 3) {
                volleyballMatch.sortPlayers();
                cout << volleyballMatch << endl;
            }
            pressEnterToContinue();
        }
        else if (selection == 'Q') {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid selection. Please try again.\n";
            pressEnterToContinue();
        }
    }

    return 0;
}
