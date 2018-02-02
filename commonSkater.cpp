#include "commonSkater.h"

common_Skater::common_Skater(int AREA, int M, int L)
:ice_Skater(AREA)
{
	this->distance = rand() % 30 + 1;
	min_x = (M/2) * this->distance/100 + 1;
	max_x = M - min_x;
	min_y = (L/2) * this->distance/100 + 1;
	max_y = L - min_y;
	spawn_Skater();
}

void common_Skater::move(){
	//Analoga to se poia pleura, kinite parallila
	//o common proxwraei kata tin antistoixi katethunsi
	//An kata tin diarkeia tis kinisis ftasei sto orio tou distance
	//tote strivei k allazei pleura stin opoia kinite parallila

	if(this->area == 0){
		for(int i = 1; i <= this->speed; i++){
			this->pos.x += i;
			this->check_fall(i);
			if(this->pos.x == this->max_x){
				this->area = 2;
				this->direction = 4;
			}
		}
	} else if(this->area == 2){
		for(int i = 1; i <= this->speed; i++){
			this->pos.y += i;
			this->check_fall(i);
			if(this->pos.y == this->max_y){
				this->area = 4;
				this->direction = 6;
			}
		}
	} else if(this->area == 4){
		for(int i = 1; i <= this->speed; i++){
			this->pos.x -= i;
			this->check_fall(i);
			if(this->pos.x == this->min_x){
				this->area = 6;
				this->direction = 0;
			}
		}
	} else if(this->area == 6){
		for(int i = 1; i <= this->speed; i++){
			this->pos.y -= i;
			this->check_fall(i);
			if(this->pos.y == this->max_y){
				this->area = 0;
				this->direction = 2;
			}
		}
	}
}

common_Skater::~common_Skater()
{}
