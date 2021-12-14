#pragma once
#include "Timer.h"

class FlyingObject
{
protected:
	double x;		// ���݂̈ʒu (pixel)
	double vx;		// ���݂̈ړ����x (pixel/s)
	double y;
	double vy;
	Timer elapsed;	// �O���update����̌o�ߎ��Ԍv���p
	double radius=0;
	Timer mtimer;
	Timer etimer;

public:
	FlyingObject();
	virtual ~FlyingObject();

	virtual void init();
	virtual void cleanup();
	virtual void update();
	virtual void draw();
	virtual void drawDebug();
	unsigned int status = 0;
	bool checkCollision(FlyingObject* fo);
	void drawExplosion();

	enum STATUS {
		ACTIVE = 1,
		COLLISION = 2
	};
};
