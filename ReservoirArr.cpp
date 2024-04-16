#include "ReservoirArr.h"
#include <iostream>
using namespace std;
#include <fstream>

ReservoirArr::ReservoirArr(int size)
{
	if (size>0)
	{
		array = new Reservoir[size];
		this->size = size;
		capacity = 0;
	}
	else
	{
		this->size = 1;
		array = new Reservoir[this->size];
		capacity = 0;
	}
}

ReservoirArr::ReservoirArr() :ReservoirArr(5){}

ReservoirArr::~ReservoirArr()
{
	delete[] array;
}

void ReservoirArr::addRes()
{
	if (capacity<size)
	{
		array[this->capacity].setRes();
		capacity++;
	}
	else
	{
		this->size+=5;// ������ ��� 5 ���� ������ ��� �� ��������� � �������������� ������
		Reservoir* newArr = new Reservoir[size];
		for (int i = 0; i < capacity; i++)
		{
			newArr[i] = array[i];
		}
		newArr[this->capacity].setRes();
		capacity++;
		delete[]array;
		array = newArr;
	}
}

void ReservoirArr::delRes(int ind)
{
	if (ind >0 && ind <= this->capacity)
	{
		
		Reservoir* newArr = new Reservoir[this->size];
		for (int i = 0, j = 0; i < capacity; i++)
		{
			if (i != ind-1)
			{
				newArr[j] = array[i];
				j++;
			}
		}
		capacity--;
		//delete[]array; //���� �� ���� �� �� ��������??
		array = newArr;
	}
	
}


void ReservoirArr::printRes()
{
	for (int i = 0; i < capacity; i++)
	{
		cout << "---------------------------------------------------------------------" << endl;
		cout << "Reservoir ID: " << i + 1 << endl;
		array[i].printRes();
		cout << "---------------------------------------------------------------------" << endl;
	}
}

void ReservoirArr::saveToFile()
{
	const char dataReservoir[] = "reservoirData.dat";
	const char keyRes[] = "ReservoirKey";
	FILE* file;
	if (fopen_s(&file, keyRes, "wb") == 0)
	{
		fwrite(&this->capacity, sizeof(int), 1, file);
		
	}
	fclose(file); 
	if (fopen_s(&file, dataReservoir, "wb") == 0)
	{
		for (int i = 0; i < capacity; i++)
		{
			fwrite(&array[i], sizeof(Reservoir), 1, file);
		}
	}
	fclose(file);
}


void ReservoirArr::loadFromFile()
{

	const char dataReservoir[] = "reservoirData.dat";
	const char keyRes[] = "ReservoirKey";
	FILE* file;

	if (fopen_s(&file, keyRes, "rb") == 0)
	{
		fread(&this->capacity, sizeof(int), 1, file);
	}
	fclose(file);
	if (fopen_s(&file, dataReservoir, "rb") == 0)
	{
		this->size = capacity + 5;
		Reservoir* newArray = new Reservoir[size];
		for (int i = 0; i < capacity; i++)
		{
			fread(&array[i], sizeof(Reservoir), 1, file);
		}
		this->array = newArray;
	}
	fclose(file);
	
}


void ReservoirArr::printArea()
{
	for (int i = 0; i < capacity; i++)
	{
		cout << array[i].getName() << " area: " << array[i].squareRes() << endl;
	}
}

void ReservoirArr::printVolum()
{
	for (int i = 0; i < capacity; i++)
	{
		cout << array[i].getName() << " Volume: " << array[i].approxVolRes() << endl;
	}
}

void ReservoirArr::isOneTypeRes(int index1, int index2)
{
	if (index1 > 0 && index1 <= this->capacity && index2 > 0 && index2 <= this->capacity && index1 != index2)
	{
		bool res;
		res = array[index1 - 1].isOneTypeRes(array[index2 - 1]);
		if (res == 1)
		{
			cout << "Reservoirs have the same type!" << endl;
		}
		else
			cout << "Reservoirs are not the same type!" << endl;
	}
}

void ReservoirArr::isBigSquareRes(int index1, int index2)
{
	int res = array[index1 - 1].isBigSquareRes(array[index2 - 1]);
	if (res == 1)
	{
		cout << array[index1-1].getName() << " has a large area! "  << endl;
	}
	else if(res == -1)
	{
		cout << array[index2-1].getName() << " has a large area! " << endl;
	}
	else
	{
		cout << "Areas are equal!!" << endl;
	}
}
