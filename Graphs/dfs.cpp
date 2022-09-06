#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vec = {{1,2,3}, {2,3}, {3,4}, {1,4}, {1}, {5}}; // граф как список смежности
int n = vec.size(); // число вершин графа
bool *used = new bool[n]; // посещенные вершины

void dfs(int v, vector<int> &comp){ // v - текущая вершина, comp - компонента связности
    if(used[v]) // если мы уже в ней были - выходим из функции
        return;
    used[v] = true;
    for(auto u: vec[v]){ // смотрим соседей
        if(!used[u]){
            dfs(u, comp); // опять выполняем поиск
        }
    }
    comp.push_back(v); // добавляем вершину в компоненту
}

int find_components_and_topology(){ // поиск компонент связности ( то есть все вершины, такие что из одной любой можно добраться в любую другую)
    for(int i = 0; i < n; i++)
        used[i] = false; // выставляем всё в false
    vector<int> comp;
    int j = 1;
    for(int i = 0; i < n; i++){
        dfs(i, comp); // выполняем поиск для каждой вершины
        if(comp.size()){ // если размер больше 0
            cout << "Component #" << j << ": "; // Выводим компоненту
            reverse(comp.begin(), comp.end());
            for(auto a: comp){
                cout << a << " "; // вершины выводятся в порядке от первой посещенной к последней
            }
            cout << endl;
            j++;
            comp.clear(); // очищаем место для следующей компоненты
        }
    }
}

int main(){
    find_components_and_topology();
    // Component #1: 0 1 2 3 4
    // Component #2: 5
    delete[] used;
    return 0;
}
