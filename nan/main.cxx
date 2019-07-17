#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    float a = -numeric_limits<float>::infinity();
    float b = nan("");
    cout << max(a, b) << endl;
    cout << "a: " << a << endl;
    cout << "a == a: " << (a == a) << endl;
    cout << "b: " << b << endl;
    cout << "b == b: " << (b == b) << endl;
    cout << "b > 0: " << (b > 0) << endl;
    cout << "b < 0: " << (b < 0) << endl;
    cout << "b == 0: " << (b == 0) << endl;

    return 0;
}
