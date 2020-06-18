#include <iostream>
#include <vector>
#include <queue>

#define DEBUG
using namespace std;

vector<int> graph[100000];
bool used[100000];      //массив меток

vector<unsigned int> times;

int main() {
    int n, m;
    unsigned int tmp;
    unsigned int total_exp_time = 0;
    unsigned int max_time;
    cout << "Enter count of node's(experiment's) and arc's:";
    cin >> n >> m;

    cout << "Enter max time: ";
    cin >> max_time;

    cout << "Enter the time of each experiment in the numbering order!!!!!" << std::endl;
    times.resize(m);
    for (size_t i = 0; i < m; i++)
    {
        std::cin >> tmp;
        times.push_back(tmp);
    }

    cout << "enter your node's and arc's:" << std::endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> q;
    q.push(0);              //в качестве начальной вершины используем 0.
    used[0] = true;

    while (!q.empty()) {
        int cur = q.front();  //извлекаем из очереди текущую вершину
        q.pop();

#ifdef DEBUG
        cout << "BFS at vertex " << cur + 1 << endl;
#endif // DEBUG

        total_exp_time += times[cur];

        for (int neighbor : graph[cur])  //добавляем всех непосещённых соседей.
        {   
            if (!used[neighbor]) {
                q.push(neighbor);
                used[neighbor] = true;
            }
        }
    }

    std::cout << "The maximum interval between each experiment is: " << (double)(max_time - total_exp_time) / (double)m << std::endl;
}