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
	Reservoir(const Reservoir&);//5. Для копіювання об’єктів;
	Reservoir (Reservoir &&);
	Reservoir& operator=(Reservoir&&);
	Reservoir operator=(const Reservoir&);
	~Reservoir();
	static int getCountObj();
	double approxVolRes();//1. Визначення приблизного обсягу(ширина * довжина * максимальна глибина);
	double squareRes();//2. Визначення площі водної поверхні;
	bool isOneTypeRes(const Reservoir&);//3. Метод для перевірки, чи належать водойми до одного типу(море - море; басейн - ставок);
	int isBigSquareRes(const Reservoir&);//4. Для порівняння площі водної поверхні водойм одного типу;
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

