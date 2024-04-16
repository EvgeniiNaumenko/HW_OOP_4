//��������
//��������� ���� Reservoir(�������).���� ����������
//������� ���� ���� ������.���� ������� ������ : ����������� �� �������������, ����������� � �����������,
//�� ����������� ���������� ���������� � �����������
//���������.
//������ ������ ��� :
//1. ���������� ����������� ������(������ * ������� *
//	����������� �������);
//2. ���������� ����� ����� �������;
//3. ����� ��� ��������, �� �������� ������� �� ������
//����(���� - ����; ������ - ������);
//4. ��� ��������� ����� ����� ������� ������ ������
//����;
//5. ��� ��������� �ᒺ���;
//6. ����� ������ �� ������ ����������(������ set
//	� get).
//	�������� ��������� ��� ������ � ������.����������
//	��������� ����� �ᒺ��� ����� � ��������� ���������, ��������� �ᒺ��� � ������.���������� ���������
//	������ ���������� ��� �ᒺ��� ������ � ��������� ����,
//	������� ����.
//	�������������� explicit ����������� � ���������
//	������� - �����(���������, ��� ����������� ����� ���
//		������� � �.�.).

#include <iostream>
using namespace std;
#include "helpFunc.h"
#include "Reservoir.h"
#include "ReservoirArr.h"

//system("cls"); �������
int main()
{
	ReservoirArr resArr(5);// ��� ������� �������� ������ �� 5 �����������
	pritnMenu(); //������ ����
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
			resArr.loadFromFile(); // �� �������� (���� ���)
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