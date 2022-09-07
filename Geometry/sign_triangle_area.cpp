#include <iostream>
#include <vector>
using namespace std;

// a x b = |a|*|b|*sin(a,b)

//      | x1 y1 1 |
// 2S = | x2 y2 1 |
//      | x3 y3 1 |

// 2S = x1(y2 - y3) - x2*(y1 - y3) + x3*(y1-y2)
// 2S = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1)

//      | x2 - x1   y2 - y1 |
// 2S = | x3 - x1   y3 - y1 |

int triangle_area_2(int x1, int y1, int x2, int y2, int x3, int y3)
{ // знаковая(+-) площадь не поделенная на 2 треугольник
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

double triangle_area(int x1, int y1, int x2, int y2, int x3, int y3)
{ // обычная площадь треугольника
    return abs(triangle_area_2(x1, y1, x2, y2, x3, y3)) / 2.0;
}

bool clockwise(int x1, int y1, int x2, int y2, int x3, int y3)
{   // идут ли точки по часовой стрелке
    // ((x1 < x2) ^ (y1 < y3)) && (((y1 < y2) && (x1 < x3)) || (y2 < y1 && x3 < x1))
    return triangle_area_2(x1, y1, x2, y2, x3, y3) < 0;
}

bool counter_clockwise(int x1, int y1, int x2, int y2, int x3, int y3)
{   // идут ли точки против часовой стрелке
    // (x2 < x1 && y2 < y1 && x1 < x3 && y3 < y1)
    return triangle_area_2(x1, y1, x2, y2, x3, y3) > 0;
}

int main()
{
    int x1 = 1, y1 = 1, x2 = -2, y2 = -2, x3 = -2, y3 = 4;
    cout << triangle_area_2(x1, y1, x2, y2, x3, y3) << endl;
    cout << triangle_area(x1, y1, x2, y2, x3, y3) << endl;
    if (clockwise(x1, y1, x2, y2, x3, y3))
    {
        cout << "Number are in clockwise!\n";
    }
    return 0;
}
