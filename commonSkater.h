#ifndef COMMONSKATER_H_
#define COMMONSKATER_H_

#include "iceSkater.h"

class common_Skater : public ice_Skater{
private:

public:
	common_Skater(int AREA, int M, int L);
	~common_Skater();

	inline char print(){ return 'C'; }
	void move();
};

#endif /* COMMONSKATER_H_ */
