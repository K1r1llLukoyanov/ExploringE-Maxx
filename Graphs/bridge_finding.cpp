// Time: O(N + M)
// Алгоритм поиска мостов, то есть таких ребер, удаление которых приведет к увеличению компонент связности
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 5 // максимальное кол-во вершин

vector<int> g[MAXN];             // вектор графа (список смежности)
bool used[MAXN];                 // помеченные вершины
vector<pair<int, int>> bridges;  // вектор мостов
int timer, tin[MAXN], fuv[MAXN]; // timer - для выставления времени входа в вершину, tin - вектор времен входа в вершину
// fuv - вектор, хранящий min(минимальное время входа своих потомков, Время входа в текущую вершину), то есть если найдется
// такой потомок вершины v to, что у него не найдется потомок u для которого fuv[v] > tin[u], то ребро между v и to - мост

void IS_BRIDGE(int v, int to) // функция для добавления мостов
{
    bridges.push_back(make_pair(v, to));
}

void dfs(int v, int p = -1) // v - текущая вершина, to - следущая вершина
{
    used[v] = true;                          // помечаем вершину
    tin[v] = fuv[v] = timer++;               // высталяем время входа
    for (size_t i = 0; i < g[v].size(); i++) // смотрим соседей
    {
        int to = g[v][i];
        if (to == p) // если следующая == предыдущей, то пропускаем, чтобы не было бесконечного цикла
            continue;
        if (used[to])                      // если следующая уже помечена
            fuv[v] = min(fuv[v], tin[to]); // берем минимум между fuv[v] и tin[to]
        else
        {
            dfs(to, v);                    // продолжаем поиск
            fuv[v] = min(fuv[v], fuv[to]); // берем минимум между fuv[v] и fuv[to]
            if (fuv[to] > fuv[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges()
{
    timer = 0;
    for (int i = 0; i < MAXN; ++i)
        used[i] = false;
    for (int i = 0; i < MAXN; ++i)
        if (!used[i])
            dfs(i);

    cout << "Bridges: \n";
    for (int i = 0; i < bridges.size(); i++)
    {
        cout << i + 1 << ") " << bridges[i].first << " " << bridges[i].second << "\n"; // вывод мостов
    }
}

int main()
{
    g[0] = {1};
    g[1] = {2};
    g[2] = {3};
    g[3] = {4};
    g[4] = {};
    find_bridges();
    return 0;
}
