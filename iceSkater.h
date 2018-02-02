#ifndef ICESKATER_H_
#define ICESKATER_H_

#define MAX_SPEED 5
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct position{
	int x;
	int y;
}position;

class ice_Skater{
private:
	static int id_count;
	int id;
	static void moveInMap(position cur, int x, int y);
	bool Delete;

protected:
	virtual void validMove();
	int speed, distance;
	int time_to_live;
	int max_x, max_y, min_x, min_y;
	int area; //an identifier to know in which area the skater is moving (in order to make cycles)

public:
	position pos;
	int pos_dir[8];
	int direction, lap;

	ice_Skater(int AREA);
	virtual ~ice_Skater();

	virtual void spawn_Skater();
	virtual void move()  = 0;
	virtual char print() = 0;
	virtual bool check_fall(int);
	virtual int fall();

	void check_collision();

	//accessors
	inline int get_Id(){ 	return this->id; }
	inline int get_Speed(){ return this->speed; }
	inline int get_Lap(){ 	return this->lap; }

	inline void add_Lap(){	this->lap++; this->time_to_live--; }

	bool spawnNear();

	inline bool remove(){ if(time_to_live == 0 || Delete == true) return true; }
};


#endif /* ICESKATER_H_ */
