#include <iostream>
#include <limits.h>

using namespace std;
 int** Initialization()
{
	int** m = new int* [1];
	m[0] = new int[2];
	m[0][0] = 0;
	m[0][1] = 0;
	return m;
}
void Delete(int** m)
{
	for (int i = 1; i <= m[0][0]; i++)
	{
		delete[] m[i];
	}
	delete[] m[0];
	delete[] m;
}
int** Input(bool flag)
{
	setlocale(LC_ALL, "ru-RU");
	int a, b;	
	if (flag)
	{
		cout << "введите количество строк и столбцов в матрице" << endl;
		cin >> a >> b;
	}
	else
	{
		cout << "введите размер вектора" << endl;
		cin >> b;
		a = 1;
	}
	int** m;
	m = new int* [a+1];
	m[0] = new int[2];
	m[0][0] = a;
	m[0][1] = b;
	cout << "введите значения" << endl;
	for (int i = 1; i <= a; i++)
	{	
		m[i] = new int[b];
		for (int k = 0; k < b; k++)
		{
			cin >> m[i][k];
		}
	}
	return m;
}

void Output(int** m)
{
	for (int i = 1; i <= m[0][0]; i++)
	{
		int* q = m[i];
		for (; m[i] < q + m[0][1]; ++m[i])
		{
			cout << *m[i]<< " ";
		}
		m[i] -= m[0][1];
		cout << endl;
	}
}bool Operation(int** m, int** v)
{
	if (m[0][1] == v[0][1])
	{
		int* temp = new int[v[0][1]];
		for (int i = 0; i < v[0][1]; i++)
			temp[i] = 0;
		for (int i = 0; i < v[0][1]; i++)
		{
			for (int k = 0; k < v[0][1]; k++)
			{
				temp[i] += (m[i+1][k]) * (v[1][k]);
			}
		}
		delete v[1];
		v[1] = temp;
		return true;
	}
	else
	{
		return false;
	}
}