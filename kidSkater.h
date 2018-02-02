#ifndef KIDSKATER_H_
#define KIDSKATER_H_

#define MAX_FALLS 5

#include "iceSkater.h"
#include "noobSkater.h"

class kid_Skater : public noob_Skater{
private:
	int max_falls;
	void move(){ return; }
public:
	kid_Skater(int AREA, int M, int L);
	~kid_Skater();

	int fall();
	inline char print(){ return 'K'; }
};

#endif /* KIDSKATER_H_ */
