//Завдання
//Розробити клас Reservoir(водойма).Клас обов’язково
//повинен мати поле «назва».Клас повинен містити : конструктор за замовчуванням, конструктор з параметрами,
//за необхідності реалізувати деструктор і конструктор
//копіювання.
//Додати методи для :
//1. Визначення приблизного обсягу(ширина * довжина *
//	максимальна глибина);
//2. Визначення площі водної поверхні;
//3. Метод для перевірки, чи належать водойми до одного
//типу(море - море; басейн - ставок);
//4. Для порівняння площі водної поверхні водойм одного
//типу;
//5. Для копіювання об’єктів;
//6. Решта методів на розсуд розробника(методи set
//	і get).
//	Написати інтерфейс для роботи з класом.Реалізувати
//	динамічний масив об’єктів класу з можливістю додавання, видалення об’єктів з масиву.Реалізувати можливість
//	запису інформації про об’єкти масиву в текстовий файл,
//	бінарний файл.
//	Використовуйте explicit конструктор і константні
//	функції - члени(наприклад, для відображення даних про
//		водойму і т.д.).

#include <iostream>
using namespace std;
#include "helpFunc.h"
#include "Reservoir.h"
#include "ReservoirArr.h"

//system("cls"); очистка
int main()
{
	ReservoirArr resArr(5);// для примера создадим массив на 5 резервуаров
	pritnMenu(); //печать меню
	int choice;
	bool progWork = true;
	while (progWork)
	{
		cout << "Enter action !! ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			resArr.addRes();
			break;
		}
		case 2:
		{
			resArr.printRes();
			int delID;
			cout << " Enter ID to delete! " << endl;
			cin >> delID;
			resArr.delRes(delID);
			break;
		}
		case 3:
		{
			resArr.printRes();
			break;
		}
		case 4:
		{
			resArr.printArea();
			break;
		}
		case 5:
		{
			resArr.printVolum();
			break;
		}
		case 6:
		{
			resArr.printRes();
			int resOne, resTwo;
			cout << " Enter ID to first reservoir! " << endl;
			cin >> resOne;
			cout << " Enter ID to second reservoir! " << endl;
			cin >> resTwo;
			resArr.isOneTypeRes(resOne, resTwo);
			break;
		}
		case 7:
		{
			resArr.printRes();
			int resOne, resTwo;
			cout << " Enter ID to first reservoir! " << endl;
			cin >> resOne;
			cout << " Enter ID to second reservoir! " << endl;
			cin >> resTwo;
			resArr.isBigSquareRes(resOne, resTwo);
			break;
		}
		case 8:
		{
			resArr.saveToFile();
			break;
		}
		case 9:
		{
			resArr.loadFromFile(); // НЕ РАБОТАЕТ (ПОКА ЧТО)
			break;
		}
		case 10:
		{
			progWork = false;
			break;
		}
		default:
			progWork = false;
			break;
		}
	}
	return 0;
}