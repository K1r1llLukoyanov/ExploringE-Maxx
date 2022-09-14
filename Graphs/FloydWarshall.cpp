#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
const int N = 10;
int n = N;

int d[N][N]; // матрица смежноти графа

void init(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)
                d[i][j] = 0;
            else
                d[i][j] = rand()%100 + 1;
        }
    }
}

void FloydWarshall(){
    int p[n][n]; // path
    memset(p, -1, sizeof(p));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                if(d[i][k] < INF && d[k][j] < INF) // смотрим расстояние между вершиной i и k, и вершиной k и j
                    if(d[i][j] > d[i][k] + d[k][j]){ // если от i до j дойти через промежуточную вершину k быстрее
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]); // то обновляем расстояние от i до j на величину d[i][k]+d[k][j]
                        p[i][j] = i; // запоминаем путь
                    }
    int a, b;
    cout << "Enter first vertex: ";
    cin >> a;
    cout << "Enter second vertex: ";
    cin >> b;
    cout << "Distance: " << d[a][b] << endl;
}

int main(){
    srand(time(NULL));
    init();
    FloydWarshall();
    return 0;
}
