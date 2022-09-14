#include <bits/stdc++.h>
using namespace std;

int n = 10;
vector<vector<pair<int, int>>> g;
const int INF = 1000000000;

/*
    Для разряженных графов O(mlog(n))
*/
void prim()
{
    vector<int> min_e(n, INF), sel_e(n, -1); // sel_e хранит предков вершин, min_e - расстояние от предка до вершины
    min_e[0] = 0;                            // расстоние от первой вершины до самой себя изначально 0
    set<pair<int, int>> q;                   // q - упорядоченное множество хранящее пару значений, первое - расстояние до вершины, второе - номер вершины
    q.insert(make_pair(0, 0));               // изначально хранится только первая вершина

    for (int i = 0; i < n; i++)
    {
        if (q.empty())
        { // пока q не станет пустым
            cout << "No MST!\n";
            exit(0);
        }
        int v = q.begin()->second; // берется вершина расстояние до которой минимально
        q.erase(q.begin());        // удаляется из множества
        if (sel_e[v] != -1)        // если у нее есть предок, он печатается
            cout << v << " " << sel_e[v] << endl;

        for (size_t j = 0; j < g[v].size(); j++)
        {                                                  // смотрим соседей этой вершины
            int to = g[v][j].first, cost = g[v][j].second; // to - номер соседней вершины, cost - расстояние до нее
            if (cost < min_e[to])                          // если расстояние от v до to меньше, чем минимальное известное расстоние до to
                q.erase(make_pair(min_e[to], to));         // то мы удаляем пару {min_e[to], to} из множества, чтобы потом ее не выбирать, так как она хранит устаревшее значение
            min_e[to] = cost;                              // устанавливаем новое значение на min_e[to] = cost
            sel_e[to] = v;                                 // устанавливаем новое значение на sel_e[to] = v
            q.insert(make_pair(cost, to));                 // добавляем новую пару в множество q
        }
    }
}

/*
    Для плотных графов O(n^2)
    Все то же самое, только вместо множество q, вершина с минимальным расстоянием v
    каждый раз ищется заново. 
 */
void prim()
{
    vector<int> min_e(n, INF), sel_e(n, -1);
    min_e[0] = 0;
    vector<bool> used(n, false);
    used[0] = true;
    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
        {
            if (!used[j] && (v != -1 || min_e[j] < min[v]))
            v = j;
        }
        if (v == -1)
            break;
        used[v] = true;
        if (sel_e[v] != -1)
            cout << v << " " << sel_e[v] << end;

        for (int to = 0; to < n; i++)
        {
            if (g[v][to] < min_e[to])
            {
                min_e[to] = g[v][to];
                sel_e[to] = v;
            }
        }
    }
}

int main()
{

    return 0;
}