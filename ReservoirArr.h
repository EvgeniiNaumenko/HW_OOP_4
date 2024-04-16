#pragma once
#include "Reservoir.h"

class ReservoirArr
{
	Reservoir* array;
	int capacity;
	int size;
public:
	ReservoirArr(int);
	ReservoirArr();
	~ReservoirArr();
	void addRes();
	void delRes(int);
	void printRes();
	void printArea();
	void printVolum();
	void isOneTypeRes(int, int);
	void isBigSquareRes(int, int);
	void saveToFile();
	void loadFromFile();
};

