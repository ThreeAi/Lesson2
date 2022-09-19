#include <iostream>
#include <limits.h>
#include "matrix.h"

using namespace std;

int main()
{   
    setlocale(LC_ALL, "ru-RU");
    char answer = NULL;
    string str = "";
    int** m, ** v;
    m = Initialization();
    v = Initialization();
    do
    {
        cout << endl;
        cout << "Нажмите клавишу для проверки функции:" << endl;
        cout << "       m - ввод матицы" << endl;
        cout << "       v - ввод вектора" << endl;
        cout << "       o - произвести опреацию умножения матрицы на вектор" << endl;
        cout << "       i - вывод матрицы" << endl;
        cout << "       k - вывод вектора" << endl;
        cout << "       e - Выход из программы" << endl;
        cin >> str;
        answer = str[0];
        switch (answer)
        {
            case 'm':
            {
                Delete(m);
                m = Input(true);
                break;
            }
            case 'v':
            {
                Delete(v);
                v = Input(false);
                break;
            }
            case 'o':
            {
                if (Operation(m, v))
                {
                    cout << "умножение произошло успешно" << endl;
                }
                else
                {
                    cout << "несоответствие разменов матрицы и вектора" << endl;
                }
                break;
            }
            case 'i':
            {
                Output(m);
                break;
            }
            case 'k':
            {
                Output(v);
                break;
            }
        }

    } while (answer != 'e');    
}

