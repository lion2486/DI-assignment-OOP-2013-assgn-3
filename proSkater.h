#ifndef PROSKATER_H_
#define PROSKATER_H_

#include "iceSkater.h"

class pro_Skater : public ice_Skater{
public:
	pro_Skater(int AREA, int M, int L);
	~pro_Skater();

	void move();
	inline char print(){ return 'P'; }
	int fall(){ cout << "I just overcame the situation" << endl; return 0; };
};

#endif /* PROSKATER_H_ */
