#ifndef ICE_ARENA_HPP_
#define ICE_ARENA_HPP_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "iceSkater.h"
#include "commonSkater.h"
#include "noobSkater.h"
#include "kidSkater.h"
#include "proSkater.h"

#define COMMON_POS 50
#define NOOB_POS 20
#define PRO_POS 20
#define KID_POS 10

class ice_Arena{
private:
	int M, L, N, T;

public:
	ice_Skater *** Grid;

	ice_Arena(int m, int l, int n, int t)
	:M(m), L(l), N(n), T(t)
	{
		this->Grid = new ice_Skater**[this->M+1];

		for(int i = 0; i <= this->M; i++)
			this->Grid[i] = new ice_Skater*[this->L+1];

		this->set_Empty();
		srand(time(NULL));
		return;
	}

	~ice_Arena(){
		//TODO delete the Skaters
		for(int i = 0; i <= this->M; i++)
			delete [] this->Grid[i];

		delete [] this->Grid;

		return;
	}

	void print(){
		for(int i = 0; i <= this->M; i++){
			for(int j = 0; j<= this->L ;j++)
				if(this->Grid[i][j] == NULL)
					cout << "-";
				else
					cout << this->Grid[i][j]->print();
			cout << endl;
		}
	}

	void set_Empty(){
		for(int i = 0; i <= this->M; i++)
			for(int j = 0; j<= this->L ;j++)
				this->Grid[i][j] = NULL;
		return;
	}

	inline int getM(){	return this->M; }
	inline int getL(){	return this->L; }
	inline int getT(){	return this->T; }

	void spawn(){
		int i, random;
		ice_Skater * tmp;

		for(i = 0; i < N; i++){

			random = rand()%(COMMON_POS+NOOB_POS+PRO_POS+KID_POS);

			if(random < NOOB_POS){
				tmp = new noob_Skater( (i%4)*2, this->M, this->L);
				this->Grid[tmp->pos.x][tmp->pos.y] = tmp;
			}else if(random < NOOB_POS+COMMON_POS){
				tmp = new common_Skater( (i%4)*2, this->M, this->L);
				this->Grid[tmp->pos.x][tmp->pos.y] = tmp;
			}else if(random < NOOB_POS+COMMON_POS+PRO_POS){
				tmp = new pro_Skater( (i%4)*2, this->M, this->L);
				this->Grid[tmp->pos.x][tmp->pos.y] = tmp;
			}else{
				tmp = new kid_Skater( (i%4)*2, this->M, this->L);
				this->Grid[tmp->pos.x][tmp->pos.y] = tmp;
			}
		}
	}
};

#endif /* ICE_ARENA_HPP_ */
