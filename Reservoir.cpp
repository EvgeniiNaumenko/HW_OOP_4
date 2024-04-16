#include "Reservoir.h"
#include <iostream>
using namespace std;

Reservoir::Reservoir(char* name, char* type, int length, int width, int depth)
{
	if (name != nullptr)
	{
		int nameSize = 0;
		for (int i = 0; name[i] != '\0'; i++)
		{
			if (name[i] != '\0')
			{
				nameSize++;
			}
		}
		this->name = new char[nameSize + 1];
		for (int i = 0; i < nameSize; i++)
		{
			this->name[i] = name[i];
		}
		this->name[nameSize] = '\0';		
	}
	if (type != nullptr)
	{
		int typeSize = 0;
		for (int i = 0; type[i] != '\0'; i++)
		{
			if (type[i] != '\0')
			{
				typeSize++;
			}
		}
		this->type = new char[typeSize + 1];
		for (int i = 0; i < typeSize; i++)
		{
			this->type[i] = type[i];
		}
		this->type[typeSize] = '\0';
	}

	this->length = length;

	this->width = width;

	this->depth = depth;

	reservoirCounter++;
}

Reservoir::Reservoir(char*, char*, int, int) :Reservoir(name, type, length, width, 0) {}

Reservoir::Reservoir(char*, char*, int) :Reservoir(name, type, length, 0, 0) {}

Reservoir::Reservoir(char*, char*) :Reservoir(name, type, 0, 0, 0) {}

Reservoir::Reservoir(char* name) :Reservoir(name, nullptr, 0, 0, 0) {}

Reservoir::Reservoir() :Reservoir(nullptr, nullptr, 0, 0, 0) {}

Reservoir::Reservoir(const Reservoir& res)
{
	int nameSize = strlen(res.name);
	this->name = new char[nameSize+1];
	for (int i = 0; i < nameSize; i++)
	{
		this->name[i] = res.name[i];
	}
	this->name[nameSize] = '\0';
	
	int typeSize = strlen(res.type);
	this->type = new char[typeSize+1];
	for (int i = 0; i < typeSize; i++)
	{
		this->type[i] = res.type[i];
	}
	this->type[typeSize] = '\0';

	this->length = res.length;

	this->width = res.width;

	this->depth = res.depth;
}

Reservoir::~Reservoir()
{
	if (name!=nullptr)
	{
		delete[] name;
	}if (type!=nullptr)
	{
		delete[] type;
	}
}

double Reservoir::approxVolRes()
{
	return length * width * depth;
}

double Reservoir::squareRes()
{
	return length * width;
}

bool Reservoir::isOneTypeRes(const Reservoir& res)
{
	int result = strcmp(this->type, res.type);
	return !result;
}

int Reservoir::isBigSquareRes(const Reservoir& res)
{
	int comparison = this->length * this->width - res.length * res.width;
	if (comparison > 0)
	{
		return 1;
	}
	else if (comparison < 0)
	{
		return -1;
	}
	else
		return 0;
}

void Reservoir::setName(char* name)
{
	if (name != nullptr)
	{
		int size = 0;
		for (int i = 0; name[i] != '\0'; i++)
		{
			if (name[i] != '\0')
			{
				size++;
			}
		}
		this->name = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			this->name[i] = name[i];
		}
		this->name[size] = '\0';
	}
}

void Reservoir::setType(char* type)
{
	if (type != nullptr)
	{
		int size = 0;
		for (int i = 0; type[i] != '\0'; i++)
		{
			if (type[i] != '\0')
			{
				size++;
			}
		}
		this->type = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			this->type[i] = type[i];
		}
		this->type[size] = '\0';
	}
}

void Reservoir::setLength(int l)
{
	this->length = l;
}

void Reservoir::setWidth(int w)
{
	this->width = w;
}

void Reservoir::setDepth(int d)
{
	this->depth = d;
}

void Reservoir::setRes()
{
	int const nameSize = 100;
	char nameMes[nameSize];
	cout << "Enter name of reservoir!" << endl;
	cin.ignore(100, '\n');
	cin.getline(nameMes, nameSize - 1);
	setName(nameMes);

	int const typeSize = 100;
	char typeMes[typeSize];
	cout << "Enter type of reservoir!" << endl;
	//cin.ignore(100, '\n');
	cin.getline(typeMes, typeSize - 1);
	setType(typeMes);
	

	cout << "Enter length of reservoir!" << endl;
	cin >> this->length;

	cout << "Enter width of reservoir!" << endl;
	cin >> this->width;

	cout << "Enter depth of reservoir!" << endl;
	cin >> this->depth;
}

char* Reservoir::getName()
{
	int size = strlen(this->name);
	char* copyName = new char[size];
	for (int i = 0; i < size; i++)
	{
		copyName[i] = this->type[i];
	}
	copyName[size] = '\0';
	return copyName;
}

char* Reservoir::getType()
{
	int size = strlen(this->type);
	char* copyType = new char[size];
	for (int i = 0; i < size; i++)
	{
		copyType[i] = this->type[i];
	}
	copyType[size] = '\0';
	return copyType;
}

double Reservoir::getLength()
{
	return this->length;
}

double Reservoir::getWidth()
{
	return this->width;
}

double Reservoir::getDepth()
{
	return this->depth;
}

int Reservoir::getCountObj()
{
	return reservoirCounter;
}

Reservoir::Reservoir(Reservoir&& res)
{
	name = res.name;
	res.name = nullptr; 
	type = res.type;
	res.type = nullptr;
	length = res.length;
	width = res.width;
	depth = res.depth;
}

Reservoir& Reservoir::operator=(Reservoir&& res)
{
	this->name = res.name;
	res.name = nullptr;
	type = res.type;
	res.type = nullptr;
	length = res.length;
	width = res.width;
	depth = res.depth;
	return *this;
}

Reservoir Reservoir::operator=(const Reservoir& res)
{
	int size = strlen(res.name);
	this->name = new char[size + 1];
	strcpy_s(this->name, size + 1, res.name);
	size = strlen(res.type);
	this->type = new char[size + 1];
	strcpy_s(this->type, size + 1, res.type);
	length = res.length;
	width = res.width;
	depth = res.depth;
	return *this;
}

void Reservoir::printRes()
{
	cout << "Reservoir name: " << this->name << endl;
	cout << "Reservoir type: " << this->type << endl;
	cout << "Reservoir lendth: " << this->length << endl;
	cout << "Reservoir width: " << this->width << endl;
	cout << "Reservoir depth: " << this->depth << endl;

}



int Reservoir::reservoirCounter = 0;