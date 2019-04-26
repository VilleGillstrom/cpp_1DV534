#pragma once
#include "Stopwatch.h"
class App
{
public:
	App();
	~App();

	void run();
private:

	Stopwatch* stopwatch;
};

