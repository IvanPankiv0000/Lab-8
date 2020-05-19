#include <iostream>
#include <forward_list>
#include <list>
#include <iterator>

using namespace std;

void easy()
{
    //Удалить элемент списка перед первым положительным элементом;

    //создаем список и итератор списка;
    forward_list <double> Numbers = { -4, -2, 7.2, -2, 9.1, 0, 6 };

    forward_list <double> ::iterator Place;

    cout << "Элементы списка перед удалением: ";

    //выводим на экран изначальный список;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }
    cout << endl;

    //удаляем элемент, перед этим ставим итератор перед удаляемым элементом;
    Place = Numbers.begin();
    Numbers.erase_after(Place);

    cout << "Элементы списка после удаления: ";

    //выводим на экран финальный список;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }
    cout << endl << endl;;
}

void medium()
{
    //Вставить первый элемент списка после каждого отрицательного значения;

    //создаем список и итератор списка;
    forward_list <double> Numbers = { -4, -2, 7.2, -2, 9.1, 0, 6 };

    forward_list <double> ::iterator Place;

    int number;

    cout << "Список перед добавлением: ";

    //выводим на экран изначальный список;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }
    cout << endl;

    //вставляем после каждого отрицательного элемента первый элемент списка;
    Place = Numbers.begin();
    number = *Place;
    Numbers.insert_after(Place, number);
    Place = Numbers.begin();
    advance(Place, 2);
    Numbers.insert_after(Place, number);
    Place = Numbers.begin();
    advance(Place, 5);
    Numbers.insert_after(Place, number);
    
    cout << "Список после добавления: ";

    //выводим на экран финальный список;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }
    cout << endl << endl;
}

void hard()
{
    /*Создать список с четным кол-вом элементов. Первую половину элементов записать в первый список, вторую во второй. 
    Вывести в начале указатели на первый и последний элементы изначального списка, потом на последний элемент первого
    и первый второго списков.*/

    list <double> Numbers = { -4, -2, 7.2, -2, 9.1, 0, 6, 7 };
    list <double> ::iterator Place;

    cout << "Изначальный список: ";

    //указатели на первый и последний элементы списка;
    Place = Numbers.begin();
    double* P1 = &(*Place);
    advance(Place, 7);
    double* P2 = &(*Place);

    //выводим на экран изначальный список;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }
    cout << endl << "Первый элемент списка: " << *P1 << ", последний: " << *P2 << endl << endl;

    //создаем список, вносим в него элементы первой половины изначального списка;
    list <double> Numbers1;

    Place = Numbers.begin();
    int size = Numbers.size() / 2;
    
    for (int i = 0; i < size; i++)
    {
        Numbers1.push_back(*Place);
        Place++;
    }

    cout << "Список из первой половины элементов изначального списка: ";
    for (Place = Numbers1.begin(); Place != Numbers1.end(); Place++)
    {
        cout << *Place << " ";
    }
    cout << endl;

    list <double> Numbers2;

    //во второй список записываем элементы со второй половины, перенося итератор на соотв. место;
    Place = Numbers.begin();
    advance(Place, 4);

    for (int i = 0; i < size; i++)
    {
        Numbers2.push_back(*Place);
        Place++;
    }

    //помимо второго списка выводим указатели на последний элемент первого списка и первый второго;
    cout << "Список из второй половины элементов изначального списка: ";
    for (Place = Numbers2.begin(); Place != Numbers2.end(); Place++)
    {
        cout << *Place << " ";
    }
    cout << endl;

    Place = Numbers1.begin();
    advance(Place, 3);
    double* pA = &(*Place);

    Place = Numbers2.begin();
    double* pB = &(*Place);

    cout << endl << "Последний элемент первого и первый второго списков: " << *pA << ", " << *pB << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "RU");

    int a;
    int count = 0;

    do
    {
        cout << "Введите номер задания(easy - 1, medium - 2, hard - 3): ";

        cin >> a;

        cout << endl;

        if (a == 1)
        {
            easy();
            count++;
        }

        if (a == 2)
        {
            medium();
            count++;
        }

        if (a == 3)
        {
            hard();
            count++;
        }

    } while (count == 0);

    int b;

    do
    {
        count = 0;

        cout << "Продолжить ввод? Да - 1, Нет - 2: ";

        cin >> b;

        cout << endl;

        if (b == 1)
        {
            count++;
            main();
        }

        if (b == 2)
        {
            cout << "Вы решили не продолжать";
            count++;
            break;
        }

    } while (count == 0);
}