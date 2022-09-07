#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g, gr; // g - исходный ориентированный граф, gr - обратно ориентированный граф
vector<bool> used; // вектор посещенных вершин
vector<int> order, component; // order - веектор, в котором вершины отсортированны в порядке увеличения времени выхода из dfs

void dfs1(int a){		// первый поиск в грубину посещает вершины исходного графа
	used[a] = true; 	// помечаем как посещенную
	for(int i = 0; i < g[a].size(); i++){ // смотрим соседей
		if(!used[g[a][i]])					// которые еще не посещены
			dfs1(g[a][i]);					// посещаем их
	}
	order.push_back(a); 					// при выходе из dfs добавляем верщину в конец order
}

void dfs2(int a){	// второй поиск в глубину посещаем обратный граф
	used[a] = true;	// помечаем как посещенную
	component.push_back(a); // добавляем вершину в компоненту
	for(int i = 0; i < gr[a].size(); i++) // смотрим соседей
		if(!used[gr[a][i]])
			dfs2(gr[a][i]);
}

void find_strong_components(){
	int n;
	cout << "Enter number of vertices: ";
	cin >> n; // вводим число вершин в графе
	g.assign(n, {}); // заполняем пустыми векторами
	gr.assign(n, {});
	bool run = true;
	while(run){
		int a, b;
		char c;
		cout << "Do you want to add new edge?(y/n): "; // спрашиваем, хочет ли пользователь добавить новое ребро
		cin >> c;
		switch(c){
			case 'Y':
			case 'y':
				cout << "Enter edge: (a b): ";
				cin >> a >> b;
				g[a].push_back(b);
				gr[b].push_back(a);
			break;
			default:
			run = false;
		}
	}
	used.assign(n, false); // убираем пометки с вершин
	for(int i = 0; i < n; i++)
		if(!used[i])
			dfs1(i); // генерируем вектор order
	used.assign(n, false); // убираем пометки
	int j = 1; // номер компоненты
	for(int i = 0; i < n; i++){
		if(!used[i])
			dfs2(i); // вставляем вершины в компоненту
		cout << "Component #" << j++ << ": ";
		for(auto c: component){
			cout << c << " ";
		}
		cout << endl;
		component.clear();
	}
}

int main(){
	find_strong_components();
	return 0;
}
