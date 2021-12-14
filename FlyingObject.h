#pragma once
#include "Timer.h"

class FlyingObject
{
protected:
	double x;		// 現在の位置 (pixel)
	double vx;		// 現在の移動速度 (pixel/s)
	double y;
	double vy;
	Timer elapsed;	// 前回のupdateからの経過時間計測用
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
