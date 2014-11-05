

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

unsigned int x = 6;
unsigned int y = 11;
unsigned int signal_size = 6;
unsigned int n = 3;

class signal_sub //Класс подпоследовательности
{
public:

    signal_sub() { sub_x.resize(signal_size); sub_y.resize(signal_size); } //Зарезервируем память в векторах.
    ~signal_sub() {}

    vector <int> sub_x;
    vector <int> sub_y;
};

class signal_node // Отсчёт с подпоследовательностью (узел)
{
public:

    signal_node() {exists = false;};
    ~signal_node() {}

    int base_x;
    int base_y;

    signal_sub subsig;

    signal_sub& operator[](unsigned int i);

    bool exists = true;
};


class signal_base //Класс последовательности
{
public:

    signal_base() { base_x.resize(signal_size); base_y.resize(signal_size); nod.resize(signal_size); } //Зарезервируем память в векторах.
    ~signal_base() {}

    vector <int> base_x;
    vector <int> base_y;

    void generate_base();
    void generate_sub();

    void filter(int n);

    vector<signal_node> nod; //Nodes
};

void signal_base::generate_base() //Генерируем эталонную последовательность
{
    for (int i = 0; i < signal_size; i++)
    {
        base_x[i] = i + 1; //х не бывает 0, отсчёт с единицы
    }
    for (int i = 0; i < signal_size; i++)
    {
        base_y[i] = y;
    }
    base_y[0] = y - 1; //Первый элемент
    base_y[ base_y.size() - 1 ] = y - 1; //Последний элемент (Размер массива - 1)
    return;
}

void signal_base::generate_sub() //Генерируем эталонную подпоследовательность
{
    for (int i = 0; i < base_x.size(); i++)
    {
        if ((rand() % 10) > 4 && i != 0) //В 60% случаев NODE существует
        {
            nod[i].exists = true;
            if (i == signal_size - 1) y = base_y[base_y.size() - 1];
            else int y = base_y[2];
            for (int n = 0; n < signal_size; n++)
            {
            nod[i].subsig.sub_x[n] = n + 1;
            nod[i].subsig.sub_y[n] = y;
            }
        }
    }
    return;
}

void printall(const signal_base &sig) // Вывод последовательности и её подпоследовательности на экран
{
    cout << "======== INFORMATION FOR SIGNAL ============" << endl;

    // Вывод
        for (int i = 0; i < signal_size; i++)
        {
            cout << "(x=" << sig.base_x[i] << ", y=" << sig.base_y[i] << ") ";
            if (i == signal_size - 1)
            {
                cout << endl;
            }
        }
        int n = 0;
        while (n < signal_size)
        {
        for (int i = 0; i < signal_size; i++)
        {
            if (sig.nod[i].exists && n < sig.nod[i].subsig.sub_x.size())
            {
                cout << "(x=" << sig.nod[i].subsig.sub_x[n];
                cout << ", y=" << sig.nod[i].subsig.sub_y[n] << ") ";
            }
            else
            {
                cout  << "==NO NODE== "; //Подпоследовательности не существует
            }
            if (i == signal_size - 1)
            {
                cout << endl;
            }
        }

        n++;

        }
    // Вывод
    return;
}

void signal_base::filter(int n) //Прореживаем (фильтруем) последовательности
{
    for (int f = 0; f < signal_size; f++)
    {
    if (nod[f].exists)
    for (int i = 0; i < nod[f].subsig.sub_x.size(); i++)
    {
        vector<int>::iterator itx = nod[f].subsig.sub_x.begin();
        vector<int>::iterator ity = nod[f].subsig.sub_y.begin();
        //if (base_x[i] != n && i != 0)
       //{
            if (nod[f].subsig.sub_x[i] != n && i > 0)
            {
                if (nod[f].subsig.sub_x[i] != nod[f].subsig.sub_x[nod[f].subsig.sub_x.size() - 1]) //Удаляем только в том случае, если элемент не является первым, n-нным и последним
                {
                nod[f].subsig.sub_x.erase(itx + i);
                i--;
                }
            };
       //}
    }
    }
}

//==================================================================
int main()
{
    cout << "n = 3" << endl;

    signal_base signal; // последовательность

    signal.generate_base(); //Сгенерируем эталонную последовательность
    signal.generate_sub(); //Генерируем подпоследовательность

    printall (signal); //Вывод на экран последовательностей и их соответствующих последовательностей
    signal.filter(n); //n = 3

    cout << "============ FILTERED SIGNAL ==============" << endl;

    printall (signal); //Вывод на экран прореженой последовательности.
    return 0;
}
