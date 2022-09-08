#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1000000000;

//  Алгоритм Дейкстры - алгоритм поиска минимального расстояния от одной вершины до другой в взвешанном графе
//  Время работы алгоритма O(N^2 + M), алгоритм требует n итераций, на каждой из которой выбирается одна из n
//  непосещенных вершин с минимальным расстоянием от исходной, если таких вершин не осталось, алгоритм прекращает работу.
//  После выбора ближайшей вершины проиходит оптимизация (минимизация расстояния до всех ее соседей).

void Dijkstra(vector<vector<pair<int, int>>> &g, int n, int s, int t)
{
    vector<int> d(n, INF), p(n);
    d[s] = 0; // расстояние до начальной вершины равно 0
    p[s] = -1;
    vector<bool> u(n, false);
    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
        {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j; // выбор ближайшей непомеченной вершины
        }
        if (d[v] == INF)
            break;
        u[v] = true; // пометка вершины
        for (size_t j = 0; j < g[v].size(); j++)
        {
            int to = g[v][j].first, len = g[v][j].second;
            if (d[v] + len < d[to])
            { // оптимизация
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
    cout << "Distance from vertex " << s << " to " << t << ": " << d[t] << endl;
    vector<int> path;
    for (int v = t; v != -1; v = p[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    cout << "Path from " << s << " to " << t << ": ";
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter max number of vertex: ";
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    char c;
    do
    {
        cout << "Do you want to add new edge? (y/n): ";
        cin >> c;
        if (c == 'Y' || c == 'y')
        {
            int a, b, l;
            cout << "Enter edge (start end weight): ";
            cin >> a >> b >> l;
            if (a >= n || b >= n)
            {
                cout << "Out of vertex range!\n";
            }
            g[a].push_back(make_pair(b, l));
        }
        else
            break;
    } while (true);
    int start, endd;
    cout << "Enter start and end vertex: ";
    cin >> start >> endd;
    Dijkstra(g, n, start, endd);
    return 0;
}
