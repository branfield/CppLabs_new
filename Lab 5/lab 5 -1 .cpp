#include<iostream>
#include <windows.h>
using namespace std;

class Rect
{
private:

	int x1, y1, x2, y2;

public:

	Rect(int abs1, int ord1, int abs2, int ord2)
	{
		this->x1 = abs1;
		this->y1 = ord1;
		this->x2 = abs2;
		this->y2 = ord2;
	}

	void sizeIncrease(int multiplier)
	{
		x1 *= multiplier;
		y1 *= multiplier;
		x2 *= multiplier;
		y2 *= multiplier;
	}

	void sizeReduce(int multiplier)
	{
		x1 /= multiplier;
		y1 /= multiplier;
		x2 /= multiplier;
		y2 /= multiplier;
	}

	void moveRight(int addendum)
	{
		x1 += addendum;
		x2 += addendum;
	}

	void moveLeft(int addendum)
	{
		x1 -= addendum;
		x2 -= addendum;
	}

	void moveUp(int addendum)
	{
		y1 += addendum;
		y2 += addendum;
	}

	void moveDown(int addendum)
	{
		y1 -= addendum;
		y2 -= addendum;
	}

	void get(int abs, int ord, int abs0, int ord0)
	{
		abs = x1;
		ord = y1;
		abs0 = x2;
		ord0 = y2;
	}
	void setx1(char* x1)
	{
		this->x1 = atoi(x1);
	}
	void sety1(char* y1)
	{
		this->y1 = atoi(y1);
	}

	void setx2(char* x2)
	{
		this->x2 = atoi(x2);
	}

	void sety2(char* y2)
	{
		this->y2 = atoi(y2);
	}
	int getx1()
	{
		return x1;
	}

	int gety1()
	{
		return y1;
	}

	int getx2()
	{
		return x2;
	}

	int gety2()
	{
		return y2;
	}

	~Rect()
	{
	}
};

void leastUnion(Rect figure1, Rect figure2)
{
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;
	int X1 = 0, Y1 = 0, X2 = 0, Y2 = 0;
	figure1.get(x1, y1, x2, y2);
	figure2.get(x3, y3, x4, y4);

	//Случаи, когда прямоугольники пересекаются
	if ((x3 > x1) && (x2 > x3) && (y1 >= y3) && (y3 <= y2))
	{
		X1 = x1;
		Y1 = y1;
		X2 = x4;
		Y2 = y4;
	}
	else if ((x3 < x1) && (x1 < x4) && (y3 >= y1) && (y1 >= y4))
	{
		X1 = x3;
		Y1 = y3;
		X2 = x2;
		Y2 = y2;
	}
	else if ((x3 > x1) && (x4 > x2) && (y3 > y1) && (y1 < y4))
	{
		X1 = x1;
		Y1 = y3;
		X2 = x4;
		Y2 = y2;
	}
	else if ((x1>x3) && (x4>x1) && (y1>y3) && (y3>y2))
	{
		X1 = x3;
		Y1 = y1;
		X2 = x2;
		Y2 = y4;
	}

	//Случай, когда один прямоугольник находится внутри другого или совпадает с ним
	else if (((x3 >= x1) && (x4 <= x2) && (y3 <= y1) && (y4 >= y2)))
	{
		X1 = x3;
		Y1 = y3;
		X2 = x4;
		Y2 = y4;
	}
	else if (((x1 >= x3) && (x2 <= x4) && (y1 <= y3) && (y2 >= y4)))
	{
		X1 = x1;
		Y1 = y1;
		X2 = x2;
		Y2 = y2;
	}

	//Случаи, когда прямоугольники НЕ пересекаются
	else if (((y2 > y3) && (y1 < y4)) || ((x2 < x3) && (x1 < x4)))
	{
		X1 = x1;
		Y1 = y1;
		X2 = x4;
		Y2 = y4;
	}
	else if (((y4 < y1) && (y3 < y2)) || ((x4 < x1) && (x3 < x2)))
	{
		X1 = x3;
		Y1 = y3;
		X2 = x2;
		Y2 = y2;
	}

	cout << "Полученные значения: " << endl;
	cout << "Верхняя левая точка: " << endl;
	cout << "x = " << X1 << endl;
	cout << "y = " << Y1 << endl;
	cout << "Нижняя правая точка: " << endl;
	cout << "x = " << X2 << endl;
	cout << "y = " << Y2 << endl;
}

void connection(Rect figure1, Rect figure2)
{
	int x1 = figure1.getx1(), y1 = figure1.gety1(), x2 = figure1.getx2(), y2 = figure1.gety2(),
		x3 = figure2.getx1(), y3 = figure2.gety1(), x4 = figure2.getx2(), y4 = figure2.gety2();
	int X1 = 0, Y1 = 0, X2 = 0, Y2 = 0;

	//Случаи, когда прямоугольники НЕ пересекаются
	if ((y2 > y3) && (y1 < y4))
	{
		cout << "Такого прямоугольника не существует!" << endl;
	}
	else if ((y4 < y1) && (y3 < y2))
	{
		cout << "Такого прямоугольника не существует!" << endl;
	}
	else if ((x2 < x3) && (x1 < x4))
	{
		cout << "Такого прямоугольника не существует!" << endl;
	}
	else if ((x4 < x1) && (x3 < x2))
	{
		cout << "Такого прямоугольника не существует!" << endl;
	}

	//Случаи, когда прямоугольники пересекаются
	else if ((x3 > x1) && (x2 > x3) && (y1 >= y3) && (y3 <= y2))
	{
		X1 = x3;
		Y1 = y3;
		X2 = x2;
		Y2 = y2;
	}
	else if ((x3 < x1) && (x1 < x4) && (y3 >= y1) && (y1 >= y4))
	{
		X1 = x1;
		Y1 = y1;
		X2 = x4;
		Y2 = y4;
	}
	else if ((x3 > x1) && (x4 > x2) && (y3 > y1) && (y1 < y4))
	{
		X1 = x3;
		Y1 = y1;
		X2 = x2;
		Y2 = y4;
	}
	else if ((x1>x3) && (x4>x1) && (y1>y3) && (y3>y2))
	{
		X1 = x1;
		Y1 = y3;
		X2 = x4;
		Y2 = y2;
	}

	//Случай, когда один прямоугольник находится внутри другого или совпадает с ним
	else if (((x3 >= x1) && (x4 <= x2) && (y3 <= y1) && (y4 >= y2)))
	{
		X1 = x1;
		Y1 = y1;
		X2 = x2;
		Y2 = y2;
	}
	else if (((x1 >= x3) && (x2 <= x4) && (y1 <= y3) && (y2 >= y4)))
	{
		X1 = x3;
		Y1 = y3;
		X2 = x4;
		Y2 = y4;
	}

	cout << "Полученные значения: " << endl;
	cout << "Верхняя левая точка: " << endl;
	cout << "x = " << X1 << endl;
	cout << "y = " << Y1 << endl;
	cout << "Нижняя правая точка: " << endl;
	cout << "x = " << X2 << endl;
	cout << "y = " << Y2 << endl;
}


bool FoolProtection(char* buff)
{

	for (int i = 0; i < strlen(buff); i++)
	{
		if (buff[0] == '-') continue;
		if (!(buff[i] >= '0' && buff[i] <= '9'))
			return false;
	}
		return true;
}

void output(Rect* random)
{
	cout << endl << "Полученные значения: " << endl;
	cout << "Верхняя левая точка: " << endl;
	cout << "x = " << random->getx1() << endl;
	cout << "y = " << random->gety1() << endl;
	cout << "Нижняя правая точка: " << endl;
	cout << "x = " << random->getx2() << endl;
	cout << "y = " << random->gety2() << endl;
}


int main()
{
	setlocale(0, "");
	cout << "Для начала работы требуется ввести координаты прямоугольника. " << endl;
	bool condition = false;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	int x3 = 0, y3 = 0, x4 = 0, y4 = 0;
	char* abs1 = new char;
	char* ord1 = new char;
	char* abs2 = new char;
	char* ord2 = new char;
	bool smth = true;

	Rect* r1 = new Rect(0, 0, 0, 0);
	while (!condition)
	{
		cout << "Введите координаты верхней левой точки: " << endl;
		cout << "x = ";

		do
		{
			cin >> abs1;
			if (FoolProtection(abs1))
			{
				r1->setx1(abs1);
				break;
			}
			else
			{
				cout << "Ошибка ввода, введите число" << endl << "x = ";
			}
		} while (true);

		cout << "y = ";
		do
		{
			cin >> ord1;
			if (FoolProtection(ord1))
			{
				r1->sety1(ord1);
				break;
			}
			else
			{
				cout << "Ошибка ввода, введите число" << endl << "y = ";
			}
		} while (true);

		cout << "Введите координаты нижней правой точки: " << endl;
		cout << "x = ";
		do
		{
			cin >> abs2;
			if (FoolProtection(abs2))
			{
				r1->setx2(abs2);
				break;
			}
			else
			{
				cout << "Ошибка ввода, введите число" << endl << "x = ";
			}
		} while (true);

		cout << "y = ";
		do
		{
			cin >> ord2;
			if (FoolProtection(ord2))
			{
				r1->sety2(ord2);
				break;
			}
			else
			{
				cout << "Ошибка ввода, введите число" << endl << "y = ";
			}
		} while (true);

		int height = 0, widht = 0;
		height = abs(r1->gety1() - r1->gety2());
		widht = abs(r1->getx2() - r1->getx1());
		if ((height <= 0) || (widht <= 0)) cout << "Полученная фигура не является прямоугольником, повторите ввод " << endl;
		else condition = true;
	}


	bool flag = false;
	bool flag1 = false;
	bool flag2 = false;
	bool flag3 = false;
	bool flag4 = false;
	int input = 0, input1 = 0, input2 = 0;
	int addendum = 0, multiplier = 0;

	Rect* r2 = new Rect(0, 0, 0, 0);
	Rect* r3 = new Rect(0, 0, 0, 0);

	while (!flag)
	{
		cout << "Выберите нужное действие: " << endl << endl;
		cout << "(1) — перемещение фигуры на плоскости" << endl;
		cout << "(2) — изменение размера фигуры" << endl;
		cout << "(3) — построение наименьшего прямоугольника, содержащего два заданных прямоугольника" << endl;
		cout << "(4) — построение наименьшего прямоугольника, являющегося пересечением двух заданных прямоугольника" << endl;
		cout << "(5) — выход из программы" << endl;

		cin >> input;

		switch (input)
		{
		case 1:
			while (!flag1)
			{
				cout << "(1) — переместить фигуру вправо " << endl;
				cout << "(2) — переместить фигуру влево " << endl;
				cout << "(3) — переместить фигуру вверх " << endl;
				cout << "(4) — переместить фигуру вниз " << endl;
				cout << "(5) — вернуться в меню " << endl;
				cin >> input1;

				switch (input1)
				{
				case 1:
					cout << "На какое значение Вы хотите сместить фигуру? " << endl;
					cin >> addendum;
					r1->moveRight(addendum);
					output(r1);
					break;

				case 2:
					cout << "На какое значение Вы хотите сместить фигуру? " << endl;
					cin >> addendum;
					r1->moveLeft(addendum);
					output(r1);
					break;

				case 3:
					cout << "На какое значение Вы хотите сместить фигуру? " << endl;
					cin >> addendum;
					r1->moveUp(addendum);
					output(r1);
					break;

				case 4:
					cout << "На какое значение Вы хотите сместить фигуру? " << endl;
					cin >> addendum;
					r1->moveDown(addendum);
					output(r1);
					break;

				case 5:

					flag1 = true;
					break;

				default:
					cout << "Введите значение от 1 до 5 " << endl;
					
				}
			}break;

		case 2:
			while (!flag2)
			{
				cout << "(1) — увеличить фигуру " << endl;
				cout << "(2) — уменьшить фигуру " << endl;
				cout << "(3) — вернуться в меню " << endl;
				cin >> input2;

				switch (input2)
				{
				case 1:
					cout << "Во сколько раз Вы хотите увеличить фигуру? " << endl;
					cin >> multiplier;
					r1->sizeIncrease(multiplier);
					output(r1);
					break;

				case 2:
					cout << "Во сколько раз Вы хотите уменьшить фигуру? " << endl;
					cin >> multiplier;
					r1->sizeReduce(multiplier);
					output(r1);
					break;

				case 3:
					flag2 = true;
					break;

				default:
					cout << "Введите значение от 1 до 3" << endl;
					break;
				} 
			}break;
			
		case 3:
			cout << "Для продолжения работы требуется второй прямоугольник" << endl;
			while (condition)
			{
				cout << "Введите координаты верхней левой точки: " << endl;
				cout << "x = ";

				do
				{
					cin >> abs1;
					if (FoolProtection(abs1))
					{
						r2->setx1(abs1);
						break;
					}
					else
					{
						cout << "Ошибка ввода, введите число" << endl << "x = ";
					}
				} while (true);

				cout << "y = ";
				do
				{
					cin >> ord1;
					if (FoolProtection(ord1))
					{
						r2->sety1(ord1);
						break;
					}
					else
					{
						cout << "Ошибка ввода, введите число" << endl << "y = ";
					}
				} while (true);

				cout << "Введите координаты нижней правой точки: " << endl;
				cout << "x = ";
				do
				{
					cin >> abs2;
					if (FoolProtection(abs2))
					{
						r2->setx2(abs2);
						break;
					}
					else
					{
						cout << "Ошибка ввода, введите число" << endl << "x = ";
					}
				} while (true);

				cout << "y = ";
				do
				{
					cin >> ord2;
					if (FoolProtection(ord2))
					{
						r2->sety2(ord2);
						break;
					}
					else
					{
						cout << "Ошибка ввода, введите число" << endl << "y = ";
					}
				} while (true);

				int height = 0, widht = 0;
				height = abs(r2->gety1() - r2->gety2());
				widht = abs(r2->getx2() - r2->getx1());
				if ((height <= 0) || (widht <= 0)) cout << "Полученная фигура не является прямоугольником, повторите ввод " << endl;
				else condition = false;
			}
			connection(*r1, *r2);
			break;


		case 4:
			cout << "Для продолжения работы требуется второй прямоугольник" << endl;
			while (!condition)
			{
				cout << "Введите координаты верхней левой точки: " << endl;
				cout << "x = ";

				do
				{
					cin >> abs1;
					if (FoolProtection(abs1))
					{
						r3->setx1(abs1);
						break;
					}
					else
					{
						cout << "Ошибка ввода, введите число" << endl << "x = ";
					}
				} while (true);

				cout << "y = ";
				do
				{
					cin >> ord1;
					if (FoolProtection(ord1))
					{
						r3->sety1(ord1);
						break;
					}
					else
					{
						cout << "Ошибка ввода, введите число" << endl << "y = ";
					}
				} while (true);

				cout << "Введите координаты нижней правой точки: " << endl;
				cout << "x = ";
				do
				{
					cin >> abs2;
					if (FoolProtection(abs2))
					{
						r3->setx2(abs2);
						break;
					}
					else
					{
						cout << "Ошибка ввода, введите число" << endl << "x = ";
					}
				} while (true);

				cout << "y = ";
				do
				{
					cin >> abs1;
					if (FoolProtection(ord2))
					{
						r3->sety2(ord2);
						break;
					}
					else
					{
						cout << "Ошибка ввода, введите число" << endl << "y = ";
					}
				} while (true);

				int height = 0, widht = 0;
				height = abs(r3->gety1() - r3->gety2());
				widht = abs(r3->getx2() - r3->getx1());
				if ((height <= 0) || (widht <= 0)) cout << "Полученная фигура не является прямоугольником, повторите ввод " << endl;
				else condition = true;
			} 
			leastUnion(*r1, *r3);
			break;

		case 5:
			system("pause");
			return 0;

		default:
			cout << "Введите значение от 1 до 5 " << endl;
		}
	}
}
