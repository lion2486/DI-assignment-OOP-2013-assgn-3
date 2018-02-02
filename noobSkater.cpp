#include "noobSkater.h"

noob_Skater::noob_Skater(int AREA, int M, int L)
:ice_Skater(AREA)
{
	this->distance = rand() % 10 + 1;
	this->speed = 1;
	min_x = (M/2) * this->distance/100 + 1;
	max_x = M - min_x;
	min_y = (L/2) * this->distance/100 + 1;
	max_y = L - min_y;
	spawn_Skater();
}

noob_Skater::~noob_Skater(){}

void noob_Skater::move(){
	int flag = 0;
	this->validMove();

	//Epilegoume tuxaia mia apo tis diathesimes kiniseis
	while(1){
		this->direction = rand() % 8;
		if(this->pos_dir[this->direction] != 0)
			break;
	}
	//Kai analoga me tin pleura stin opoia kinoumsaste parallila
	//kanoume tin kinisi, elegxontas PRWTA omws mipws perasei o pagodromos
	//to orio pou prepei na krataei apo tin pleura
	//Me to flag katalavainoume an perasame to orio k egine i kinisi i oxi
	if(this->area == 0){
		if(this->pos.x + this->speed >= this->max_x){
			this->pos.x = this->max_x;
			this->area = 2;
			if(this->direction == 1)
				this->pos.y -= this->speed;
			else if(this->direction == 3)
				this->pos.y += this->speed;
			this->direction = 4;
			flag = 1;
		}
	} else if(this->area == 2){
		if(this->pos.y + this->speed >= this->max_y){
			this->pos.y = this->max_y;
			this->area = 4;
			if(this->direction == 3)
				this->pos.x += this->speed;
			else if(this->direction == 5)
				this->pos.x -= this->speed;
			this->direction = 6;
			flag = 1;
		}
	} else if(this->area == 4){
		if(this->pos.x - this->speed <= this->min_x){
			this->pos.x = this->min_x;
			this->area = 6;
			if(this->direction == 5)
				this->pos.y += this->speed;
			else if(this->direction == 7)
				this->pos.y -= this->speed;
			this->direction = 0;
			flag = 1;
		}
	} else if(this->area == 6){
		if(this->pos.y - this->speed >= this->min_y){
			this->pos.y = this->min_y;
			this->area = 0;
			if(this->direction == 1)
				this->pos.x -= this->speed;
			else if(this->direction == 3)
				this->pos.x += this->speed;
			this->direction = 2;
			flag = 1;
		}
	}
	if(flag == 0)
		check_collision();
	else
		check_fall(this->speed);
}
