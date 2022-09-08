#include <bits/stdc++.h>
using namespace std;

struct edge {
	int a, b, cost;
};

int n, m, v;
vector<edge> e;
const int INF = 1000000000;

// simple
void solve(int v){
    vector<int> d(n, INF), p(n);
    d[v] = 0;
    p[v] = -1;
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < m; j++)
            if(d[e[j].a] < INF){
                d[e[j].b] = min(d[e[j].b], d[e[j].a] + e[j].cost);
                p[e[j].b] = d[e[j].a];
            }
    vector<int> path;
    cout << "Enter target vertex: ";
    int a, b;
    cin >> a;
    b = a;
    while(a != -1){
        path.push_back(a);
        a = p[a];
    }
    reverse(path.begin(), path.end());
    cout << "Path from " << v << " to " << b << ": ";
    for(int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
    cout << ", path length: " << d[b] << endl;
}

// better
void solve2(){
    vector<int> d(n, INF), p(n);
    d[v] = 0;
    for(;;){
        bool any = false;
        for(int j = 0; j < m; j++)
            if(d[e[j].a] < INF)
                if(d[e[j].b] > d[e[j].a] + e[j].cost){
                    d[e[j].b] = d[e[j].a] + e[j].cost;
                    p[e[j].b] = d[e[j].a];
                    any = true;
                }
        if(!any)
            break;
    vector<int> path;
    cout << "Enter target vertex: ";
    int a;
    cin >> a;
    while(a != -1){
        path.push_back(a);
        a = p[a];
    }
    reverse(path.begin(), path.end());
    cout << "Path from " << v << " to " << a << ": ";
    for(int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
    cout << endl;       break;
    }
}

int main(){
    n = 0;
    m = 0;
    char c;
    set<int> vertex;
    do{
        cout << "Do you want to add edge? (y/n): ";
        cin >> c;
        if(c == 'Y' || c == 'y'){
            int a, b, c;
            cout << "Enter edge data (start end cost): ";
            cin >> a >> b >> c;
            e.push_back({a, b, c});
            if(vertex.count(a) == 0){
                n++;
                vertex.emplace(a);
            }
            if(vertex.count(b) == 0){
                n++;
                vertex.emplace(b);
            }
            m++;
        }
        else
            break;
    }while(true);
    int v;
    cout << "Enter start vertex: ";
    cin >> v;
    solve(v);
    return 0;
}
