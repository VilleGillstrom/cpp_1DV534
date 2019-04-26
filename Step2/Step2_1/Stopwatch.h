#pragma once
#include "MyTime.h"
#include "Clock.h"

class Stopwatch
{
public:
	Stopwatch();
	~Stopwatch();

	void start();
	void stop();
	MyTime getTime();

private:
	Clock* clock;
	MyTime startTime;
	MyTime stopTime;
};

