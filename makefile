main: main.o rockPaperScissors.o spockLizard.o
	g++ -o main main.o rockPaperScissors.o spockLizard.o -std=c++11

main.o: main.cpp rockPaperScissors.h spockLizard.h
	g++ -c main.cpp -std=c++11

calculator.o: rockPaperScissors.cpp rockPaperScissors.h
	g++ -c rockPaperScissors.cpp -std=c++11

spockLizard.o: spockLizard.cpp spockLizard.h
	g++ -c spockLizard.cpp -std=c++11
