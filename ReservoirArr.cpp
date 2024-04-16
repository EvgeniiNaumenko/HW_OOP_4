#include "ReservoirArr.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <cstring>

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
		this->size+=5;// сделал шаг 5 чтоб каждый раз не создавать и перезаписывать массив
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
		//delete[]array; //если он есть то не работает??
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
	FILE* file;
	 
	if (fopen_s(&file, dataReservoir, "wb") == 0)
	{
		fwrite(&capacity, sizeof(int), 1, file);
		for (int i = 0; i < capacity; i++)
		{
			int nameLength = strlen(array[i].getName());
			fwrite(reinterpret_cast<const char*>(&nameLength), sizeof(int),1,file);
			fwrite(array[i].getName(),sizeof(char), nameLength,file);
			int typeLength = strlen(array[i].getType());
			fwrite(reinterpret_cast<const char*>(&typeLength), sizeof(int), 1, file);
			fwrite(array[i].getType(), sizeof(char), typeLength, file);
			double length = array[i].getLength();
			fwrite(&length, sizeof(double), 1, file);
			double width = array[i].getWidth();
			fwrite(&width, sizeof(double), 1, file);
			double depth = array[i].getDepth();
			fwrite(&depth, sizeof(double), 1, file);
		}
	}
	fclose(file);
}

void ReservoirArr::loadFromFile()
{

	const char dataReservoir[] = "reservoirData.dat";

	FILE* file;

	if (fopen_s(&file, dataReservoir, "rb") == 0)
	{
		fread(&capacity, sizeof(int), 1, file);
		this->size = capacity + 5;
		Reservoir* newArray = new Reservoir[size];

		for (int i = 0; i < capacity; i++)
		{
			int nameLength;
			fread(reinterpret_cast<char*>(&nameLength), sizeof(int),1,file);
			char* name = new char[nameLength + 1];
			fread(name,sizeof(char), nameLength,file);
			name[nameLength] = '\0';
			int typeLength;
			fread(reinterpret_cast<char*>(&typeLength), sizeof(int), 1, file);
			char* type = new char[typeLength + 1];
			fread(type, sizeof(char), typeLength, file);
			type[typeLength] = '\0';
			double length;
			fread(&length, sizeof(double), 1, file);
			double width;
			fread(&width, sizeof(double), 1, file);
			double depth;
			fread(&depth, sizeof(double), 1, file);

			array[i].setName(name);
			delete[] name;
			array[i].setType(type);
			delete[] type;
			array[i].setLength(length);
			array[i].setWidth(width);
			array[i].setDepth(depth);
		}
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
