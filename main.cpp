#include <iostream>
#include <iomanip>
#include "rockPaperScissors.h"
#include "spockLizard.h"

using namespace std;

int main()
{

    /// Initialize simple RockScissorGame and SpockLizard Game.
    RockPaperScissors calc;
    SpockLizard sci;

    /// Assign calculator pointer to the simple calc object
    /// This will be used later for polymorphism
    RockPaperScissors* rpsPtr = &calc;

    /// Switch to flip scientific calc on and off
    bool sciActive = false;

    cout << "Welcome to my Rock Paper Scissors Game\n"
    << "This game has 2 modes, Normal and Spock/Lizard Mode.\n"
    << "You can change it using the 'change' keyword.\n\n";

    /// Welcome message for simple RockPaperScissorsGame
    rpsPtr->welcome();


    /// Take in input and loop
    string input = "";
    while (cin >> input && input != "exit")
    {
        /// Input to switch mode
        if (input == "change")
        {
            if (sciActive)
            {
                /// Set pointer to the simple game object
                rpsPtr = &calc;
                sciActive = false;
                cout << "\nSimple Mode Activated";
            } else /// sciActive is false
            {
                /// Set pointer to spock/lizard game object
                rpsPtr = &sci;
                sciActive = true;
                cout << "\nStar Wars Mode Activated";
                
            }
        }
        /// Call virtual functions from base class pointer to get polymorphic
        /// Executes function based on type of object
        rpsPtr->parseInput(input);
        rpsPtr->welcome();
    }

    return 0;
}
