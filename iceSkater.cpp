#include <cstdlib>
#include "ice_Arena.hpp"
#include "iceSkater.h"
#include "commonSkater.h"

extern ice_Arena * arena;

int ice_Skater::id_count = 1;

ice_Skater::ice_Skater(int AREA)
:area(AREA), Delete(false)
{
	this->id = id_count++;
	this->lap = 0;
	this->time_to_live = rand() % arena->getT() + 1;
	this->speed = rand() % MAX_SPEED + 1;
	cout << "ID " << this->id << " in Area " << area << " speed " << speed << " lifetime "<< time_to_live << endl;
}

ice_Skater::~ice_Skater() {
	cout << "Bye bye..." << endl;
}

int ice_Skater::fall(){
	cout << "I just fell but it is nice to meet you" << endl;
	return 0;
}

void ice_Skater::spawn_Skater() {
	int i = 0;
	//Paradoxi o common edw mporei na ksekinisei apo kapou kontitera
	//apo to orio tou, alla auto tha ftiaxei stin 1i tou strofi

	//Analoga me tin pleura pou vriskomaste tha kanoume tous
	//aparaititous elegxous gia na ginei swsto spawn
	if(this->area == 0){
		this->pos.x = rand() % arena->getM() + 1;
		this->pos.y = rand() % min_y + 1;
		while(arena->Grid[this->pos.x][this->pos.y] != NULL){
			this->pos.x = i++;
			if(this->pos.x == arena->getM() + 1){
				cerr << "Unfortunately, row is full!!" << endl;
				exit(EXIT_FAILURE);
			}
		}
	} else if(this->area == 2){
		pos.x = arena->getM() - min_x;
		pos.y = rand() % arena->getL() + 1;
		while(arena->Grid[this->pos.x][this->pos.y] != NULL){
			this->pos.y = i++;
			if(this->pos.y == arena->getL() + 1){
				cerr << "Unfortunately, column is full!!" << endl;
				exit(EXIT_FAILURE);
			}
		}
	} else if(this->area == 4){
		pos.x = rand() % arena->getM() + 1;
		pos.y = arena->getL() - min_y;
		while(arena->Grid[this->pos.x][this->pos.y] != NULL){
			this->pos.x = i++;
			if(this->pos.x == arena->getM() + 1){
				cerr << "Unfortunately, row is full!!" << endl;
				exit(EXIT_FAILURE);
			}
		}
	} else if(this->area == 6){
		pos.x = rand() % min_x + 1;
		pos.y = rand() % arena->getL() + 1;
		while(arena->Grid[this->pos.x][this->pos.y] != NULL){
			this->pos.y = i++;
			if(this->pos.y == arena->getL() + 1){
				cerr << "Unfortunately, column is full!!" << endl;
				exit(EXIT_FAILURE);
			}
		}
	}
	//An tuxei kai pesoume panw se kapoion Skater ksekiname na
	//dokimazoume apo tin arxi tis grammis/stilis mexri na vroume
	//ena keno na afisoume ton Skater mas. An einai gemati i grammi tha
	//apotuxoume me EXIT_FAILURE.
}

void ice_Skater::validMove() {
	int i;

	for(i = 0; i < 8; i++)
		this->pos_dir[1] = 1;

	if(dynamic_cast<common_Skater * > (this)){
		this->pos_dir[1] = 0;
		this->pos_dir[3] = 0;
		this->pos_dir[5] = 0;
		this->pos_dir[7] = 0;
	}
	//Xrisimopoiontas tin pleura pou kinoumaste parallila
	//apokleioume kiniseis pou den einai epitreptes
	if(this->area == 0){
		//moving in the top side to the right
			this->pos_dir[7] = 0;
			this->pos_dir[6] = 0;
			this->pos_dir[5] = 0;
	}else if(this->area == 2){
		//moving in the right side to the bottom
			this->pos_dir[0] = 0;
			this->pos_dir[1] = 0;
			this->pos_dir[7] = 0;
	}else if(this->area == 4){
		//moving in the bottom side to the left
			this->pos_dir[1] = 0;
			this->pos_dir[2] = 0;
			this->pos_dir[3] = 0;
	}else if(this->area == 6){
		//moving in the left side to the top
			this->pos_dir[3] = 0;
			this->pos_dir[4] = 0;
			this->pos_dir[5] = 0;
	}

	//Elegxoume an me tin taxutita tou pagodromou, bgei apo
	//ektos oriwn tou pagodromiou k an nai, tote den ton afinoume
	//na kanei auti tin kinisi
	if(this->pos.x - this->speed <= 0){
		this->pos_dir[0] = 0;
		this->pos_dir[1] = 0;
		this->pos_dir[7] = 0;
	}
	if(this->pos.x + this->speed >= arena->getM()){
		this->pos_dir[3] = 0;
		this->pos_dir[4] = 0;
		this->pos_dir[5] = 0;
	}
	if(this->pos.y - this->speed <= 0){
		this->pos_dir[5] = 0;
		this->pos_dir[6] = 0;
		this->pos_dir[7] = 0;
	}
	if(this->pos.y + this->speed >= arena->getL()){
		this->pos_dir[1] = 0;
		this->pos_dir[2] = 0;
		this->pos_dir[3] = 0;
	}
}

void ice_Skater::moveInMap(position cur, int x, int y){
	arena->Grid[cur.x+x][cur.y+y] = arena->Grid[cur.x][cur.y];
	arena->Grid[cur.x][cur.y] = NULL;
	return;
}

void ice_Skater::move(){
	int i, x1 = 0, y1 = 0;

	this->validMove();

	for(i = 0; i < this->speed; i++){

		if(arena->Grid[this->pos.x+x1][this->pos.y+y1] != NULL){
			//make the check for collision-fail
		}
	}

	//move the skater in the map
	ice_Skater::moveInMap(this->pos, x1, y1);

	//write the new position
	this->pos.x += x1;
	this->pos.y += y1;

	return;
}

void ice_Skater::check_collision(){
	for(int i = 0; i <= this->speed; i++){
		switch(this->direction){
			case 0:
				this->pos.y--;
				break;
			case 1:
				this->pos.x++;
				this->pos.y--;
				break;
			case 2:
				this->pos.x++;
				break;
			case 3:
				this->pos.x++;
				this->pos.y++;
					break;
			case 4:
				this->pos.y++;
					break;
			case 5:
				this->pos.x--;
				this->pos.y++;
					break;
			case 6:
				this->pos.x--;
					break;
			case 7:
				this->pos.x--;
				this->pos.y--;
					break;
		}
		if(check_fall(i))
			return;
	}
}

bool ice_Skater::check_fall(int i){
	//Se periptwsi pou stamatisei se tetragwno (i iso me speed) pou vrisketai idi kapoios pou exei metakinithei (exoun idia lap)
	if(arena->Grid[this->pos.x][this->pos.y] != NULL && arena->Grid[this->pos.x][this->pos.y]->lap == this->lap && i == this->speed){
		fall();
		return true;
	}
	//Se periptwsi pou prosperasei kapoion (exoun idia directions) pou exei idi metakinithei (exoun idia lap)
	else if(arena->Grid[this->pos.x][this->pos.y] != NULL && arena->Grid[this->pos.x][this->pos.y]->lap == this->lap && arena->Grid[this->pos.x][this->pos.y]->direction == this->direction && i != this->speed){
		fall();
		return true;
	}
	return false;
}

bool ice_Skater::spawnNear(){
	int i, j;
	int depth = 2;

	if(arena->Grid[this->pos.x][this->pos.y] == this || arena->Grid[this->pos.x][this->pos.y] == NULL){
		arena->Grid[this->pos.x][this->pos.y] = this;
		return true;
	}

	for(i=-depth;i<depth;i++)
		for(j=-depth;j<depth;j++)
			if(this->pos.x + i > 0 && this->pos.x + i < arena->getM()
					&& this->pos.y + j > 0 && this->pos.y + j < arena->getL())
				if(arena->Grid[this->pos.x+i][this->pos.y+j] == this || arena->Grid[this->pos.x+i][this->pos.y+j] == NULL){
						arena->Grid[this->pos.x+i][this->pos.y+j] = this;
						return true;
					}

	this->Delete = true;

	std::cout << "Unfortunatly, there was no room to get up so the iceSkater is removed"<< std::endl;

	return false;
}
