#pragma once
class Reservoir
{
	char* name;
	char* type;
	double length;
	double width;
	double depth;
	static int reservoirCounter;
public:
	Reservoir(char*,char*,int,int,int);
	Reservoir(char*,char*,int,int);
	Reservoir(char*,char*,int);
	Reservoir(char*,char*);
	Reservoir(char*);
	Reservoir();
	Reservoir(const Reservoir&);//5. ��� ��������� �ᒺ���;
	Reservoir (Reservoir &&);
	Reservoir& operator=(Reservoir&&);
	Reservoir operator=(const Reservoir&);
	~Reservoir();
	static int getCountObj();
	double approxVolRes();//1. ���������� ����������� ������(������ * ������� * ����������� �������);
	double squareRes();//2. ���������� ����� ����� �������;
	bool isOneTypeRes(const Reservoir&);//3. ����� ��� ��������, �� �������� ������� �� ������ ����(���� - ����; ������ - ������);
	int isBigSquareRes(const Reservoir&);//4. ��� ��������� ����� ����� ������� ������ ������ ����;
	void setName(char*);
	void setType(char*);
	void setLength(int);
	void setWidth(int);
	void setDepth(int);
	void setRes();
	char* getName();
	char* getType();
	double getLength();
	double getWidth();
	double getDepth();
	void printRes();

};

