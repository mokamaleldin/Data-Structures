#include <iostream>
using namespace std;

// TS
// any (int, float, string)

template <typename T>
T amr(T x, T y)
{
    return x + y;
};

int main()
{
    amr(5, 6); // 11
}
