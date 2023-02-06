#include <iostream>
#include<vector>
#include<cstdlib>
#include "rockPaperScissors.h"

using namespace std;

/// Constructor
/// Initilize data members to 0 doubles
RockPaperScissors::RockPaperScissors() : computerChoice(0), resultMatrix(vector<vector<int> >(5,vector<int>(5,0))) {
    initializeChoices();
    initializeResultMatrix();
}


/**
 * @brief Get the Computer Choice using random number Generator
 * 
 */
void RockPaperScissors::setComputerChoice(){
    int range = choices.size();
    srand(time(0));
    computerChoice = rand()%range;
}
/**
 * @brief function to fetch player choice from terminal input
 * 
 */
void RockPaperScissors::setUserChoice(int input){
    userChoice = input;
}

/**
 * @brief initialise choices for the game
 * 
 */
void RockPaperScissors::initializeChoices(){
    choices.push_back("Rock");
    choices.push_back("Paper");
    choices.push_back("Scissors");
}

void RockPaperScissors::initializeResultMatrix()
{
    // User -> Rock, Computer -> Paper 
    resultMatrix[0][1]= -1; 
    //User -> Scissors, Computer -> Paper
    resultMatrix[1][0] = 1;
    // User -> Rock, Computer -> Scissors
    resultMatrix[0][2] = 1;
    // User -> Scissors, Computer -> Rock
    resultMatrix[2][0] = -1;
    // User -> Paper, Computer -> Scissors
    resultMatrix[1][2] = -1;
    // User -> Scissors, Computer -> Paper
    resultMatrix[2][1] = 1;
}

/**
 * @brief Display what options user and computer have choosen
 * 
 */
void RockPaperScissors::displayChoices(){
    cout<<"Computer Picked - "<<choices[computerChoice]<<endl;
    cout<<"You Picked - "<<choices[userChoice]<<endl;
}

/**
 * @brief Contains the logic to find the winner of the game and output to the terminal
 * 
 */
void RockPaperScissors::showWinner(){
    int result = resultMatrix[userChoice][computerChoice];
    cout<<"\n\n\n\n"<<endl;
    if(!result){
        cout<<"Both picked "<<choices[userChoice]<<endl;
        cout<<"It's a TIE!!!"<<endl;
    }else if(result ==1){
        cout<<choices[userChoice]<<" beats "<<choices[computerChoice]<<endl;
        cout<<"Yayy, You WON!!!"<<endl;
    }else{
        cout<<choices[userChoice]<<" loses to "<<choices[computerChoice]<<endl;
        cout<<"Ohh No, You Lost:("<<endl;
    }
}

void RockPaperScissors::welcome() const
{
    cout << "\n\n\nWelcome to the Rock Paper Scissors Game Normal Mode!!\n";
    for(int i = 0;i<choices.size();++i){
        cout<<"("<<i+1<<") for "<<choices[i]<<endl;
    }
    cout<<"or type change to change the mode"<<endl;
    cout<<"or type exit to exit the game"<<endl;
}

int RockPaperScissors::isValidInput(string input){
    char inputMax = '0' + choices.size();
    if(input.length() == 1 && input[0] >= '1' && input[0] <= inputMax)
        return (int)(input[0]-'1');
    for(int i = 0;i<choices.size();++i){
        if(input==choices[i]){
            return i;
        }
    }
    return -1;
}

/// parse input and decide which member func to call
void RockPaperScissors::parseInput(const string& input)
{
    int userInput = isValidInput(input);
    if(userInput!=-1){
        setUserChoice(userInput);
        
        // get computer's choice using random number generator
        setComputerChoice();

        // display what choices both have made 
        displayChoices();
        
        // decides winner on basis of choices and displays it on terminal 
        showWinner();
    }
    
}
