#ifndef NOOBSKATER_H_
#define NOOBSKATER_H_

#include "iceSkater.h"

class noob_Skater : public ice_Skater{
protected:
	virtual void move();

public:
	noob_Skater(int AREA, int M, int L);
	virtual ~noob_Skater();

	char print(){ return 'N'; }
};

#endif /* NOOBSKATER_H_ */
