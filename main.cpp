#include <iostream>
#include <cstdlib>
#include "ice_Arena.hpp"

//global variable arena
ice_Arena * arena;

using namespace std;

int main(int argc, char * argv[]){
	int M, L, N, T;

	//check if the input is valid and fair enough
	if(argc != 5){
		cerr << "Invalid arguments, use M L N T " << endl;
		exit(EXIT_FAILURE);
	}
	M = atoi(argv[1]);
	L = atoi(argv[2]);
	N = atoi(argv[3]);
	T = atoi(argv[4]);

	if(M < 4 || L < 4){
		cerr << "Invalid arguments, min width-height of the grid is 4!" << endl;
		exit(EXIT_FAILURE);
	}

	if(N > 60*M*L/100){
		cerr << "Invalid arguments, use smaller N or bigger Grid! (we accept only up to 60% fill of the grid)! " << endl;
		exit(EXIT_FAILURE);
	}

	if(T < 1){
		cerr << "Invalid arguments, use positive T (times) " << endl;
		exit(EXIT_FAILURE);
	}

	//Dimiourgia tou pagodromiou
	arena = new ice_Arena(M, L, N, T);

	//Emfanisi twn pagodromwn
	arena->spawn();

	arena->print();
	//TODO run the loop for T times

	//Diagrafi tou pagodromiou
	delete arena;

	return 0;
}
