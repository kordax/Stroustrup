#include <iostream>
#include <vector>
#include <stdlib.h>
#include "std_lib_facilities.h"

using namespace std;

unsigned int x = 6;
unsigned int y = 11;

class signal_sub //Класс подпоследовательности
{
public:

    signal_sub() { sub_x.resize(x); sub_y.resize(y); } //Зарезервируем память в векторах.
    ~signal_sub() {}

    vector <int> sub_x;
    vector <int> sub_y;

    bool exists;
};

class signal_base //Класс последовательности
{
public:

    signal_base() { subsig.exists = false; base_x.resize(x); base_y.resize(y); } //Зарезервируем память в векторах.
    ~signal_base() {}

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
    return;
}

void generate_sub(signal_sub &ssub) //Генерируем эталонную подпоследовательность
{
    ssub.exists = true;
    for (int i = 0; i < x; i++)
    {
        if ((rand() % 10) > 5 && i != 0) ssub.sub_x[i] = ssub.sub_x[i - 1]; //В 50% случаев, x будет повторяться
        else ssub.sub_x[i] = i + 1;
    }
    for (int i = 0; i < y; i++)
    {
        ssub.sub_y[i] = y; //y элементы одинаковы
    }
    return;
}

void printsignal(const signal_base &sig) // Вывод последовательности и её подпоследовательности на экран
{
    cout << "======== INFORMATION FOR SIGNAL ============" << endl;
    for (int i = 0; i < x; i++)
    {
        cout << "VALUES" << " (x = " << sig.base_x[i] << ", y = " << sig.base_y[i] << ')';
        if (sig.subsig.exists) //Если существует подпоследовательность, выводим её.
        {
          // for (int i = 0; i < x; i++)
           // {
                cout << ' ' << "SUB_VALUES" << " (x = " << sig.subsig.sub_x[i] << ", y = " << sig.subsig.sub_y[i] << ')' << endl;
         //   }
        }
        else
        {
            if (i == 0) cout << ' ' << "#NO SUB_VALUES FOR THIS SIGNAL" << endl;
            else cout << endl;
        }
    }
    cout << "============================================" << endl;
    return;
}



//==================================================================

int main()
try
{
    signal_base signal1, signal2, signal3, signal4; //4 последовательности

    cout << "X = " << x << endl;
    cout << "Y = " << y << endl << endl;

    generate_base(signal1); //Сгенерируем эталонную последовательность
    generate_base(signal2); //Сгенерируем эталонную последовательность
    generate_base(signal3); //Сгенерируем эталонную последовательность
    generate_base(signal4); //Сгенерируем эталонную последовательность

    generate_sub(signal1.subsig); //Сгенерируем эталонные подпоследовательности для последовательностей
    generate_sub(signal3.subsig); //Подпоследовательности существуют лишь для последовательностей 1, 3 и 4.
    generate_sub(signal4.subsig);

    printsignal (signal1); //Вывод на экран последовательностей и их соответствующих последовательностей
    printsignal (signal2);
    printsignal (signal3);
    printsignal (signal4);

    return 0;
}

catch(exception& e) {
    // some error reporting
    return 1;
}
catch(...) {
    // some more error reporting
    return 2;
}
