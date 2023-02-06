# C++ Command Line Calculator

This is an extremely simple RockPaperScissors Game I made.

Download the repo, compile and run it:
```
$git clone 
$cd to the directory
$make
```


It has two modes, regular and Spock/Lizard, that a user can switch between.

### Overview

The program has 2 classes. A simple Game class called RockPaperScissors, and a class that inherits It called SpockLizard.

Some of the member functions of RockPaperScissors are virtual and are overridden in the SpockLizard class.

The program polymorphically calls the appropriate member functions depending on the current mode (spockLizard vs simple).

The program flow is:
1. Prompt user to choose the option from the given choices (polymorphically determine the message based on the current mode; show more options while in spockLizard mode)
2. Executes function to simulate computer Behaviour to choose random option.
3. Finds winner by comparing both the choices and prints it on terminal screen.
4. Repeat from (1)

#### RockPaperScissors Class

This is the base class for the Game Program. It has data members and member functions that will display messages to the screen, prompt for user input, and logic to find winner.

Specifically, It has 2 protected data members, `choices` and `resultMatrix`. `resultMatrix` stores the logic by which winner is decided we used resultMatrix instead of if/else statements as it is more extensible and readable as well. `choices` is used to store all the possible choices like (Rock,Paper,Scissor) in case of normal mode and (Rock,Paper,Scissor,Spock,Lizard) in case of Starwars mode. both are initilized in constructors.

Public member functions `showWinner`, `displayOptions`, `setUserChoice`, `setComputerChoice`.


Then some helper member functions will be needed.
`welcome()` will print out the available options that can be entered. This is virtual so the derived class can output its own options.

`parseInput()` takes in the user input string and calls the parse the input Option from the string and calls the respective functions. This is to enable the user entering "1" or "2". This is also virtual so it can be overridden for the extra functions in the Spock/Lizard Mode.

As this class contains virtual functions, a virtual destructor will be included.

#### SpockLizard Class

SpockLizard inherits from the base class RockPaperScissors. It calls the RockPaperScissors constructor to initialize.
It has additional input options allowListed so that they can also be considered for the result and result is fetch from the resultMatrix.

It overrides the 2 virtual functions of class Calculator. `welcome()` is overridden to show all the options for the scientific calculator, and `parseInput()` is overridden to access the additional Options like Spock and Lizard.

A virtual destructor is also included.

#### Main

The class set up allows the program to polymorphically call object methods depending on the type of the object. The main program will be one user entry loop. In the loop, a base class RockPaperScissors pointer (`rpsPtr`) pointed at a RockPaperScissors object is used to call the RockPaperScissors member functions.

The switch to SpockLizard mode will be made by pointing this RockPaperScissors class pointer at a derived SpockLizard class object. Now the program dynamically calls different member functions based on the state.

This simplifies the main code as the statement `rpsPtr->welcome()` will automatically call the right welcome function, detailing out the proper options for the current mode.

#### Nifty Features

1. Users are able to enter a diff inputs that correspond to each option. For example: “1”, “Rock”, trigger the submits the same option.
