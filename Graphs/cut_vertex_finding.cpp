#include <iostream>
#include <vector>
using namespace std;

#define NMAX 5

bool used[NMAX];
vector<int> g[NMAX];
vector<int> cutpoints;

int timer = 0, tin[NMAX], fuv[NMAX];

void IS_CUTPOINT(int v)
{
    cutpoints.push_back(v);
}

void dfs(int v, int p = -1)
{
    used[v] = true;
    tin[v] = fuv[v] = timer++;
    int children = 0;
    for (size_t i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (to == p)
            continue;
        if (used[to])
            fuv[v] = min(fuv[v], tin[to]);
        else
        {
            dfs(to, v);
            fuv[v] = min(fuv[v], fuv[to]);
            if (fuv[to] >= tin[v] && p != -1)
                IS_CUTPOINT(v);
            ++children;
        }
    }
    if (p == -1 && children > 1)
        IS_CUTPOINT(v);
}

void find_cut_point()
{
    for (int i = 0; i < NMAX; i++)
        used[i] = false;
    for (int i = 0; i < NMAX; i++)
    {
        if (!used[i])
            dfs(i, -1);
    }
    cout << "Cutpoints: ";
    for (int i = 0; i < cutpoints.size(); i++)
    {
        cout << cutpoints[i] << " ";
    }
    cout << endl;
}

int main()
{
    g[0] = {1};
    g[1] = {2};
    g[2] = {3};
    g[3] = {4};
    find_cut_point(); // 3 2 1
    return 0;
}
