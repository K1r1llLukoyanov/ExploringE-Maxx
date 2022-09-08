#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

//  Алгоритм дейкстры для разряженных графов 
//  то есть для графов для которых действительное число ребер m сильно меньше максимального количетсва
//  ребер n^2.

//  Для этого используюся вспомогательные структуры данных
//  Во первых поиск начинается с самой первой вершины (начальной) s, которая добавляется в очередь вершин
//  вместе с текущим минимальным расстоянием до нее (0). Поиск будет продолжатся до тех пор пока в очереди
//  есть хотя бы один элемент.
//  На каждой новой итерации достаем пару значений элемента и удаляем его из очереди.
//  Теперь проверяем можно ли оптимизировать расстояние до вершины, если можно, то нужно удалить предыдущие
//  элементы из set с предыдущим расстоянием до вершины, так как они являются устаревшими ( большими ) обновить
//  расстояние до вершины и добавить новый элемент с новым расстоянием до вершины в set.

// using set (реализация с помощью set)
void DijkstraSET(vector<vector<pair<int, int>>> &g, int n, int s, int t){
    vector<int> d(n, INF), p(n);
    d[s] = 0;
    p[s] = -1;
    set<pair<int, int>> q;
    q.insert(make_pair(d[s], s));
    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());
        for(size_t j = 0; j < g[v].size(); j++){
            int to = g[v][j].first, len = g[v][j].second;
            if(d[v] + len < d[to]){
                q.erase(make_pair(d[to], to));
                d[to] = d[v] + len;
                p[to] = v;
                q.insert(make_pair(d[to], to));
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

// using priority_queue
void DijkstraPQ(vector<vector<pair<int, int>>> &g, int n, int s, int t){
    vector<int> d(n, INF), p(n);
    d[s] = 0;
    p[s] = -1;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, s));
    while(!q.empty()){
        int v = q.top().second, cur_d = -q.top().first;
        q.pop();
        if(cur_d > d[v]) continue;

        for(size_t j = 0; j < g[v].size(); j++){
            int to = g[v][j].first, len = g[v][j].second;
            if(d[v] + len < d[to]){
                d[to] = d[v] + len;
                p[to] = v;
                q.push(make_pair(-d[to], to));
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

int main(){
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
    DijkstraSET(g, n, start, endd);
    DijkstraPQ(g, n, start, endd);
    return 0;
}
