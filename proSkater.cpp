#include "proSkater.h"

pro_Skater::pro_Skater(int AREA, int M, int L)
:ice_Skater(AREA) {
	this->distance = 100;
	min_x = min_y = 1;
	max_x = M;
	max_y = L;
	spawn_Skater();
}

pro_Skater::~pro_Skater(){ }

void pro_Skater::move(){
	this->validMove();

	//Epilegoume tuxaia mia apo tis diathesimes kiniseis
	while(1){
		this->direction = rand() % 8;
		if(this->pos_dir[this->direction] != 0)
			break;
	}
	check_collision();
}
