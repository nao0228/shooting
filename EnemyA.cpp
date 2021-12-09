#define _USE_MATH_DEFINES	// Visual C++‚ÅM_PI‚ðŽg‚¦‚é‚æ‚¤‚É
#include <cmath>
#include "ShootingApp.h"
#include "EnemyA.h"

EnemyA::EnemyA() : Enemy()
{
}


EnemyA::~EnemyA()
{
}

void EnemyA::init()
{
	FlyingObject::init();

	phase = App::rand() * M_PI;	// M_PI‚ÍƒÎ

	x = 100 + 500 * App::rand();
	y = 100 + 200 * App::rand();

	vx = 100 + 200 * App::rand();
	vy = 100 + 200 * App::rand();

	radius = 30;
}

void EnemyA::update()
{
	double dt = elapsed.get();
	double mt = mtimer.get();
	double dx, dy;

	// update‚ÌŠÔŠu‚ª’·‚·‚¬‚é‚Æ‚«‚ÍA‹­§“I‚Édt‚ðÝ’è
	if (dt > 1.0 / 30)
		dt = 1.0 / 30;

	dx = vx * sin(2 * mt + phase) * dt;
	dy = vy * cos(5 * mt + phase) * dt;

	x += dx;
	y += dy;

	elapsed.reset();
}

void EnemyA::draw()
{
	Ellipse(App::hDC, x - radius, y - radius, x + radius, y + radius);
	LPCWSTR c;

	c = TEXT("|");
	TextOut(App::hDC, (int)x - 21, (int)y, c, lstrlen(c));
	c = TEXT("|");
	TextOut(App::hDC, (int)x + 18, (int)y, c, lstrlen(c));
	c = TEXT("---");
	TextOut(App::hDC, (int)x - 16, (int)y + 10, c, lstrlen(c));
	c = TEXT("---");
	TextOut(App::hDC, (int)x - 16, (int)y - 7, c, lstrlen(c));
	c = TEXT("--+--");
	TextOut(App::hDC, (int)x - 27, (int)y - 20, c, lstrlen(c));
}
