#include <iostream>
#include <locale>
#include <vector>
#include <queue>

#define N 20 //���������� ������ �����.
#define TRUE 1
#define FALSE 0

using namespace std;

typedef struct zveno* svqz;
typedef struct zveno
{
    int Key; //������� �����.
    svqz Sled; //��������� �� ��������� ������� �������.
} Leader;

class Spisok {
private:
    svqz beg[N]; //�������� ���� ������� ���������.
    svqz res; //��������� �� ��������� �����.
    void Poisk(svqz, int);
    void Udalenie(svqz*);
public:
    Spisok();
    svqz GetPoisk() { return res; }
    void MakeGraph();
    void AddGraph(int, int);
    void DeleteGraph(int, int);
    void PrintGraph();
    void BFS();
};

void main()
{
    setlocale(LC_ALL, "Rus");
    Spisok A;
    int x; // ������ ����.
    int y; // ����� ����.


    A.MakeGraph(); // ���������� ������� ���������.
    // ����� ������� ����������.
    cout << "������������� ����� �������� ���������\n";
    A.PrintGraph(); cout << endl;
    A.BFS();


}

void Spisok::BFS()
{
    unsigned int Pcount = 0; //���-�� ������
    unsigned int Rcount = 0; //���-�� �����


    int d; //��������� ���������� �� ��������� �������
    int p; // ���������� �� �������
    int quantity; //���������� ������ �� ��������� ����������
    int end; // ��������� ����� �� ������
    cout << "������� ���������� �� ������� ������: ";
    cin >> d;
    svqz ukzv; // ������� ���������.
    p = 0;
    queue<int> qtops; // ������� ������
    ukzv = beg[1];
    qtops.push(1); // ��������� � ������� ������� 1
    int vertex; //�������

    vertex = qtops.front();
    end = qtops.back();

    while (qtops.size() != NULL) // ���� � ������� ���� �����
    {
        qtops.pop();
        while (ukzv != NULL) //���� � ������� ���� �����
        {
            cout << vertex << "->";
            cout << (*ukzv).Key;
            qtops.push((*ukzv).Key);
            ukzv = (*ukzv).Sled;
            cout << endl;

            Rcount++;
        }
        if (qtops.size() == NULL) // ��������� ���� ����������� �������
            break;

        if (vertex == end) {
            p++;
            cout << " ����������: " << p << endl;
            end = qtops.back();
            if (p == d)
            {
                cout << "���������� ������ �� �������� ���������: " << qtops.size() << endl;
            }
        }


        Pcount++;
        ukzv = beg[qtops.front()]; // ����� ��������� �������
        vertex = qtops.front();
    }

    std::cout << "��� �� ������: " << Pcount << std::endl;
    std::cout << "��� �� �����: " << Rcount << std::endl;

    std::cout << "������� ���������: " << Rcount / Pcount << std::endl;
}

void Spisok::Poisk(svqz uksp, int ment)
// ����� ����� � �������������� ����� ment � 
// ���������������� ������ uksp. res - ���������
// �� ��������� ����� ��� NULL.
{
    svqz q;

    res = NULL; q = uksp;
    while ((q != NULL) && (res == NULL))
    {
        if ((*q).Key == ment) res = q; q = (*q).Sled;
    }
}

void Spisok::AddGraph(int x, int y)
// ���������� ���� (x,y) (���� �� �� ����!) � ����,
// �������������� �������� ��������� beg .
{
    svqz ukzv, uzel; // ������� ���������.

    if (beg[x] != NULL)
    {
        Poisk(beg[x], y);
        if (GetPoisk() == NULL)
        { //���������� �������� � ����� ������, ��������� ���������� beg[x].
            uzel = new (Leader);
            (*uzel).Key = y;
            (*uzel).Sled = NULL;
            ukzv = beg[x];
            while ((*ukzv).Sled != NULL)
                ukzv = (*ukzv).Sled;
            (*ukzv).Sled = uzel;
        }
    }
    else {
        beg[x] = new (zveno);
        (*beg[x]).Key = y;
        (*beg[x]).Sled = NULL;
    }
}

void Spisok::MakeGraph()
// ���������� ������� ��������� beg �����.
{
    int x, y;

    cout << "������� ������ ����: "; cin >> x;
    cout << "������� ����� ����: "; cin >> y;
    while (x != 0)
    {
        AddGraph(x, y);
        cout << "������� ������ ����: "; cin >> x;
        cout << "������� ����� ����: "; cin >> y;
    }
}

void Spisok::Udalenie(svqz* ukstr)
//* �������� �����, �� ������� ��������� ��������� res,
// �� ����������������� ������, ��������� ���������� *ukstr 
{
    svqz ukzv, z;

    if (((**ukstr).Sled == NULL) && (res == *ukstr)) //� ������ - ���� �������! 
    {
        *ukstr = NULL; delete res;
    }
    else if (res == *ukstr) // ��������� ������� - ������.
    {
        *ukstr = (**ukstr).Sled; delete res;
    }
    else {
        z = *ukstr; ukzv = (**ukstr).Sled;
        while (ukzv != res) { z = ukzv; ukzv = (*ukzv).Sled; }
        (*z).Sled = (*res).Sled; delete res;
    }
}

void Spisok::DeleteGraph(int x, int y)
// �������� ���� (x,y) �� ������� ��������� beg.
{
    if (beg[x] != NULL)
        // �������� ����� �� ������ ��� ���������� �����.
    { // ������� � ����� ����.
        Poisk(beg[x], y);
        if (GetPoisk() != NULL) Udalenie(&beg[x]);
        else cout << "����� ���� � ����� ���!\n";
    }
    else cout << "������ ����!\n";
}

void Spisok::PrintGraph()
{
    svqz ukzv; // ������� ���������.

    for (int i = 1; i < N; i++)
    {
        ukzv = beg[i];
        if (ukzv == NULL) cout << "";
        else {
            while (ukzv != NULL) {
                cout << i << "->";
                cout << (*ukzv).Key;
                ukzv = (*ukzv).Sled;
                cout << endl;
            }
            cout << endl;
        }


    }
}

Spisok::Spisok() { for (int i = 0; i < N; i++) beg[i] = NULL; }