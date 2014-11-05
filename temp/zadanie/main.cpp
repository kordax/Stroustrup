#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

unsigned int x = 6;
unsigned int y = 11;

vector< vector<int> > subsvec;

class signal_sub //Класс подпоследовательности
{
public:

    signal_sub() { sub_x.resize(x); sub_y.resize(y); }; //Зарезервируем память в векторах.
    ~signal_sub() {};

    unsigned int index;

    vector <int> sub_x;
    vector <int> sub_y;
};

class signal_base //Класс последовательности
{
public:

    signal_base() { base_x.resize(x); base_y.resize(y); }; //Зарезервируем память в векторах.
    ~signal_base() {};

    unsigned int index;

    vector <int> base_x;
    vector <int> base_y;
    signal_sub subsig;
};

void generate_base(signal_base &sbase) //Генерируем эталонную последовательность
{
    for (int i = 0; i < x; i++)
    {
        sbase.base_x[i] = i + 1; //х не бывает 0, отсчёт с единицы
    }
    for (int i = 0; i < y; i++)
    {
        sbase.base_y[i] = y;
    }
    sbase.base_y[0] = y - 1; //Первый элемент
    sbase.base_y[ sbase.base_y.size() - 1 ] = y - 1; //Последний элемент (Размер массива - 1)
}

void generate_sub(signal_sub &ssub) //Генерируем эталонную подпоследовательность
{
    for (int i = 0; i <= x; i++)
    {
        if ((rand() % 10) > 5 && i != 0) ssub.sub_x[i] = ssub.sub_x[i - 1]; //В 30% случаев, x будет повторяться
        else ssub.sub_x[i] = i + 1;
    }
    for (int i = 0; i <= y; i++)
    {
        ssub.sub_y[i] = y;
    }
}

void printsignal(const signal_base &signal)
{

}

int main()
{
    signal_base signal;
    signal_sub subsignal;

    generate_base(signal); //Сгенерируем эталонную последовательность
    generate_sub(subsignal); //Сгенерируем эталонные подпоследовательности



    return 0;
}

