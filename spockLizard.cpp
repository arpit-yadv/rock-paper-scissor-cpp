#include <iostream>
#include "spockLizard.h"

using namespace std;

/// Constructor
SpockLizard::SpockLizard(): RockPaperScissors(){
    initializeResultMatrix();
    initializeChoices();
}

/// Overrided welcome message to show scientific options
void SpockLizard::welcome() const
{
    cout << "\n\nWelcome to the Rock Paper Scissors Game StarWars Mode!!\n";
    for(int i = 0;i<choices.size();++i){
        cout<<"("<<i+1<<") for "<<choices[i]<<endl;
    }
    cout<<"or type change to change the mode"<<endl;
    cout<<"or type exit to exit the game"<<endl;
}

void SpockLizard:: initializeResultMatrix()
{
    // User -> Rock, Computer -> Paper 
    resultMatrix[0][1]= -1; 
    //User -> Scissors, Computer -> Paper
    resultMatrix[1][0] = 1;
    // User -> Rock, Computer -> Scissors
    resultMatrix[0][2] = 1;
    // User -> Scissors, Computer -> Rock
    resultMatrix[2][0] = -1;
    // User -> Rock, Computer -> Spock
    resultMatrix[0][3] = -1;
    // User -> Spock, Computer -> Rock
    resultMatrix[3][0] = 1;
    // User -> Rock, Computer -> Lizard
    resultMatrix[0][4] = 1;
    // User -> Lizard, Computer -> Rock
    resultMatrix[4][0] = -1;
    // User -> Paper, Computer -> Scissors
    resultMatrix[1][2] = -1;
    // User -> Scissors, Computer -> Paper
    resultMatrix[2][1] = 1;
    // User -> Paper, Computer -> Spock
    resultMatrix[1][3] = 1;
    // User -> Spock, Computer -> Paper
    resultMatrix[3][1] = -1;
    // User -> Paper, Computer -> Lizard
    resultMatrix[1][4] = -1;
    // User -> Lizard, Computer -> Paper
    resultMatrix[4][1] = 1;
    // User -> Spock Computer -> Scissors
    resultMatrix[2][3] = -1;
    // User -> Scissors, Computer -> Spock
    resultMatrix[3][2] = 1;
    // User -> Lizard, Computer -> Scissors
    resultMatrix[2][4] = 1;
    // User -> Scissors, Computer -> Lizard
    resultMatrix[4][2] = -1;
    //User -> Spock, Computer -> Lizard
    resultMatrix[3][4] = -1;
    // User -> Lizard, Computer -> Spock
    resultMatrix[4][3] = 1;
}
void SpockLizard:: initializeChoices(){
    choices.push_back("Spock");
    choices.push_back("Lizard");
}
