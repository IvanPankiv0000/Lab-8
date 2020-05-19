#include <iostream>
#include <forward_list>
#include <list>
#include <iterator>

using namespace std;

void easy()
{
    //������� ������� ������ ����� ������ ������������� ���������;

    //������� ������ � �������� ������;
    forward_list <double> Numbers = { -4, -2, 7.2, -2, 9.1, 0, 6 };

    forward_list <double> ::iterator Place;

    cout << "�������� ������ ����� ���������: ";

    //������� �� ����� ����������� ������;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }
    cout << endl;

    //������� �������, ����� ���� ������ �������� ����� ��������� ���������;
    Place = Numbers.begin();
    Numbers.erase_after(Place);

    cout << "�������� ������ ����� ��������: ";

    //������� �� ����� ��������� ������;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }
    cout << endl << endl;;
}

void medium()
{
    //�������� ������ ������� ������ ����� ������� �������������� ��������;

    //������� ������ � �������� ������;
    forward_list <double> Numbers = { -4, -2, 7.2, -2, 9.1, 0, 6 };

    forward_list <double> ::iterator Place;

    int number;

    cout << "������ ����� �����������: ";

    //������� �� ����� ����������� ������;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }
    cout << endl;

    //��������� ����� ������� �������������� �������� ������ ������� ������;
    Place = Numbers.begin();
    number = *Place;
    Numbers.insert_after(Place, number);
    Place = Numbers.begin();
    advance(Place, 2);
    Numbers.insert_after(Place, number);
    Place = Numbers.begin();
    advance(Place, 5);
    Numbers.insert_after(Place, number);
    
    cout << "������ ����� ����������: ";

    //������� �� ����� ��������� ������;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }
    cout << endl << endl;
}

void hard()
{
    /*������� ������ � ������ ���-��� ���������. ������ �������� ��������� �������� � ������ ������, ������ �� ������. 
    ������� � ������ ��������� �� ������ � ��������� �������� ������������ ������, ����� �� ��������� ������� �������
    � ������ ������� �������.*/

    list <double> Numbers = { -4, -2, 7.2, -2, 9.1, 0, 6, 7 };
    list <double> ::iterator Place;

    cout << "����������� ������: ";

    //��������� �� ������ � ��������� �������� ������;
    Place = Numbers.begin();
    double* P1 = &(*Place);
    advance(Place, 7);
    double* P2 = &(*Place);

    //������� �� ����� ����������� ������;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }
    cout << endl << "������ ������� ������: " << *P1 << ", ���������: " << *P2 << endl << endl;

    //������� ������, ������ � ���� �������� ������ �������� ������������ ������;
    list <double> Numbers1;

    Place = Numbers.begin();
    int size = Numbers.size() / 2;
    
    for (int i = 0; i < size; i++)
    {
        Numbers1.push_back(*Place);
        Place++;
    }

    cout << "������ �� ������ �������� ��������� ������������ ������: ";
    for (Place = Numbers1.begin(); Place != Numbers1.end(); Place++)
    {
        cout << *Place << " ";
    }
    cout << endl;

    list <double> Numbers2;

    //�� ������ ������ ���������� �������� �� ������ ��������, �������� �������� �� �����. �����;
    Place = Numbers.begin();
    advance(Place, 4);

    for (int i = 0; i < size; i++)
    {
        Numbers2.push_back(*Place);
        Place++;
    }

    //������ ������� ������ ������� ��������� �� ��������� ������� ������� ������ � ������ �������;
    cout << "������ �� ������ �������� ��������� ������������ ������: ";
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

    cout << endl << "��������� ������� ������� � ������ ������� �������: " << *pA << ", " << *pB << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "RU");

    int a;
    int count = 0;

    do
    {
        cout << "������� ����� �������(easy - 1, medium - 2, hard - 3): ";

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

        cout << "���������� ����? �� - 1, ��� - 2: ";

        cin >> b;

        cout << endl;

        if (b == 1)
        {
            count++;
            main();
        }

        if (b == 2)
        {
            cout << "�� ������ �� ����������";
            count++;
            break;
        }

    } while (count == 0);
}