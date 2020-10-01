// Megafon_task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <Windows.h>
#include <ctime>
#define n 10 // в данной команде задаем размерность игрового поля
using namespace std;
vector<vector<bool>> field1(n, vector<bool>(n, 0));
vector<vector<bool>> field2(n, vector<bool>(n, 0)); // создаются два массива , в одном будут храниться текущие значения ячеек , во вторую запишем результаты вычислений 
int mod(int a, int b)
{
    int c;
    if (a >= 0)
    {
        c = a % b;
    }
    else
    {
        c = ((a / b) - 1) * b - a;
    }
    return abs(c);
}// в данной функции реализовано "правильное " деление по модолю , каким образом оно определено в теории чисел 
//это понадобится в дальнейшем для вычисления значений ,а конкрентно для замыкания поля , т.е соединены левый край с правым , верхний край с нижним .
int count_life(int x, int y)
{
    int count = 0;
    for (int i = x - 1; i < x + 2; i++)
    {
        for (int j = y - 1; j < y + 2; j++)
        {

            count += field1[mod(i, n)][mod(j, n)];
        }
    }
     // в данном цикле  рассчитываются новые значения для каждой клетки , в частности , для крайних клеток где как раз используется написанная выше функция mod
    return count - field1[x][y];
}
void fill_the_field1()
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < n; j++)

        {

            field1[i][j] = rand() % 2;

        }
    }
}// в данной функции массив заполняется случайными значениями 
void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (field1[i][j] == 1)
            {
                cout << " * ";

            }
            else { cout << " " << 0 << " "; }
        }
        cout << endl;
    }
}// это функция для вывода поля 
void run_life()
{

    while (1)
    {

        for (int i = 0; i < n; i++)
        {


            for (int j = 0; j < n; j++)
            {
                if (count_life(i, j) == 3 && field1[i][j] == 0)
                {
                    field2[i][j] = 1;
                }
                else if (field1[i][j] == 1 && (count_life(i, j) == 2 or count_life(i, j) == 3))
                {
                    field2[i][j] = 1;
                }
                else { field2[i][j] = 0; }
            }

        }
        field1 = field2;
        Sleep(1000);
        system("cls");
        print();

    }
}// в данной функции собрано окончательная часть решения , в частности поле заполняется новыми значениями , при использовании функций выше

int main()
{
    fill_the_field1();
    print();
    run_life();
   

}

