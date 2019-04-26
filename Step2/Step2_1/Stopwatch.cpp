#include "Stopwatch.h"


Stopwatch::Stopwatch()
{
	clock = new Clock();
}

Stopwatch::~Stopwatch()
{
	delete clock;
}

void Stopwatch::start()
{
	startTime = clock->give_me_the_time();
}

void Stopwatch::stop()
{
	stopTime = clock->give_me_the_time();
}

MyTime Stopwatch::getTime()
{
	return startTime - stopTime;
}


