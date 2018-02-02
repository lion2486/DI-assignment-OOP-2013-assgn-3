#include "kidSkater.h"

kid_Skater::kid_Skater(int AREA, int M, int L)
:noob_Skater(AREA, M, L)
{
	this->max_falls = rand() % MAX_FALLS + 1;
	spawn_Skater();
}

kid_Skater::~kid_Skater() {
	cout << "I want to stay longer...." << endl;
}

int kid_Skater::fall(){
	cout << "Crying..." << endl;
	if( --(this->max_falls) == 0 )
		return 1;
	else
		return 0;
}
