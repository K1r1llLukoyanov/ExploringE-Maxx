#include <bits/stdc++.h>
using namespace std;

// Длина объединения отрезков

unsigned segment_union_measure(const vector<pair<int, int>> &a){
    unsigned n = a.size(); // количество отрезков
    vector<pair<int, bool>> x(2*n); // создаем массив пар первый элемент - координата точки, второй - является ли данная точка правой
    for(unsigned i = 0; i < n; i++){
        x[2*i] = make_pair(a[i].first, false); // левая точка, начало отрезка
        x[2*i + 1] = make_pair(a[i].second, true); // правая точка, конец отрезка
    }

    sort(x.begin(), x.end());   // сортируем массив в порядке увеличения, причем если встречаются точка с одинаковыми коррдинатами,
                                // первой будет точка, которая является началом отрезка

    unsigned result = 0;        // ответ - длина объединения
    unsigned c = 0;             // количество левых точек - количество правых точек(c всегда больше 0, так как перед каждой правой, есть как минимум одна левая)

    for(int i = 0; i < 2*n; i++){ // обходим все точки
        if(c > 0)   // если c > 0, то есть (количество левых точек - количество правых точек) > 0
            result += unsigned(x[i].first - x[i-1].first); // присоединяем отрезок (плюсуем его длину)
        if(x[i].second) // если точка является началом отрезка 
            ++c;        // прибавляем единицу
        else
            --c;        // иначе убавляем единицу
    }
    return result;
}

int main(){
    vector<pair<int, int>> a = {{4,10}, {6,10}};
    int uum = segment_union_measure(a);
    cout << uum << endl; // output: 6
    return 0;
}
