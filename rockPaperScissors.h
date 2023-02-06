#ifndef ROCKPAPERSCISSORS_H
#define ROCKPAPERSCISSORS_H

#include <string>
#include <array>
#include <cmath>
#include<vector>

using namespace std;

class RockPaperScissors
{
public:
    RockPaperScissors();           /// Constructor
    virtual ~RockPaperScissors() = default;    /// Virtual destructor to prevent delete errors
    void setComputerChoice(); // function to generate Random number for computer's choice
    void setUserChoice(int input); // function to set User's choice in data member
    void displayChoices(); // function to display choices 
    void showWinner(); // function to find the winner and output on the screen
    int isValidInput(string input);
    


    /// provides data on user options, will be overloaded
    virtual void welcome() const; 
    virtual void initializeResultMatrix(); // function to initialize matrix
    virtual void initializeChoices(); // function to initialize choices

    /// parse input and decide which member func to call
    virtual void parseInput(const std::string&);

/// protected so derived class can access.
protected:
    vector<vector<int> > resultMatrix;      /// data member to store comparison result b/w all the possible clashes
    int computerChoice; // data member to store choice of computer generated randomly.
    int userChoice;  // data member to save userChoice from input.
    vector<string>choices; // data member to save all the choices which are possible(Eg - Rock/Paper/Scissor/Spock/Lizard)
};

#endif // ROCKPAPERSCISSORS_H
