#pragma once
#include <iostream>
using namespace std;


void pritnMenu()
{
	cout << "================================================" << endl;
	cout << "1. Add reservoir" << endl; //добавить 
	cout << "2. Delete reservoir" << endl; // удалить
	cout << "3. Print all reservoir's" << endl; // распечатать список
	cout << "4. Print reservoir area" << endl; // распечатать площади
	cout << "5. Print reservoir volume" << endl;// распечатать обьемы
	cout << "6. Comparison of reservoir types" << endl;
	cout << "7. Comparison of the area of ​​reservoirs" << endl;
	cout << "8. Save to file" << endl;
	cout << "9. Load from file" << endl;
	cout << "10. EXIT" << endl;
	cout << "================================================" << endl;
}