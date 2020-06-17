#include <iostream>
#include <locale>
#include <vector>
#include <queue>

#define N 20 //Количество вершин графа.
#define TRUE 1
#define FALSE 0

using namespace std;

typedef struct zveno* svqz;
typedef struct zveno
{
    int Key; //Вершина графа.
    svqz Sled; //Указатель на следующую смежную вершину.
} Leader;

class Spisok {
private:
    svqz beg[N]; //Описание типа списков смежности.
    svqz res; //Указатель на найденное звено.
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
    int x; // Начало дуги.
    int y; // Конец дуги.


    A.MakeGraph(); // Построение списков смежности.
    // Вывод списков смежностей.
    cout << "Представление графа списками смежности\n";
    A.PrintGraph(); cout << endl;
    A.BFS();


}

void Spisok::BFS()
{
    unsigned int Pcount = 0; //Кол-во вершин
    unsigned int Rcount = 0; //Кол-во ребер


    int d; //Выбранное расстояние от выбранной вершины
    int p; // Расстояние от вершины
    int quantity; //Количество вершин на выбранном расстоянии
    int end; // последние число на уровне
    cout << "Введите расстояние на котором искать: ";
    cin >> d;
    svqz ukzv; // Рабочий указатель.
    p = 0;
    queue<int> qtops; // очередь вершин
    ukzv = beg[1];
    qtops.push(1); // добавляем в очередь вершину 1
    int vertex; //вершина

    vertex = qtops.front();
    end = qtops.back();

    while (qtops.size() != NULL) // пока в очереде есть числа
    {
        qtops.pop();
        while (ukzv != NULL) //пока у вершины есть ребра
        {
            cout << vertex << "->";
            cout << (*ukzv).Key;
            qtops.push((*ukzv).Key);
            ukzv = (*ukzv).Sled;
            cout << endl;

            Rcount++;
        }
        if (qtops.size() == NULL) // закончить если закончились вершины
            break;

        if (vertex == end) {
            p++;
            cout << " Расстояние: " << p << endl;
            end = qtops.back();
            if (p == d)
            {
                cout << "Количество вершин на заданном растоянии: " << qtops.size() << endl;
            }
        }


        Pcount++;
        ukzv = beg[qtops.front()]; // берем следующую вершину
        vertex = qtops.front();
    }

    std::cout << "Кол во вершин: " << Pcount << std::endl;
    std::cout << "Кол во ребер: " << Rcount << std::endl;

    std::cout << "Средняя плотность: " << Rcount / Pcount << std::endl;
}

void Spisok::Poisk(svqz uksp, int ment)
// Поиск звена с информационным полем ment в 
// однонаправленном списке uksp. res - указатель
// на найденное звено или NULL.
{
    svqz q;

    res = NULL; q = uksp;
    while ((q != NULL) && (res == NULL))
    {
        if ((*q).Key == ment) res = q; q = (*q).Sled;
    }
}

void Spisok::AddGraph(int x, int y)
// Добавление дуги (x,y) (если ее не было!) в граф,
// представленный списками смежности beg .
{
    svqz ukzv, uzel; // Рабочие указатели.

    if (beg[x] != NULL)
    {
        Poisk(beg[x], y);
        if (GetPoisk() == NULL)
        { //Добавление элемента в конец списка, заданного указателем beg[x].
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
// Построение списков смежности beg графа.
{
    int x, y;

    cout << "Вводите начало дуги: "; cin >> x;
    cout << "Вводите конец дуги: "; cin >> y;
    while (x != 0)
    {
        AddGraph(x, y);
        cout << "Вводите начало дуги: "; cin >> x;
        cout << "Вводите конец дуги: "; cin >> y;
    }
}

void Spisok::Udalenie(svqz* ukstr)
//* Удаление звена, на которое ссылается указатель res,
// из однонаправленного списка, заданного указателем *ukstr 
{
    svqz ukzv, z;

    if (((**ukstr).Sled == NULL) && (res == *ukstr)) //В списке - один элемент! 
    {
        *ukstr = NULL; delete res;
    }
    else if (res == *ukstr) // Удаляемый элемент - первый.
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
// Удаление дуги (x,y) из списков смежности beg.
{
    if (beg[x] != NULL)
        // Удаление звена из списка без заглавного звена.
    { // Вершины в графе есть.
        Poisk(beg[x], y);
        if (GetPoisk() != NULL) Udalenie(&beg[x]);
        else cout << "Такой дуги в графе нет!\n";
    }
    else cout << "Список пуст!\n";
}

void Spisok::PrintGraph()
{
    svqz ukzv; // Рабочий указатель.

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