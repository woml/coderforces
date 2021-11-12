#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10; 
char s[N];

int main(void) {
    double t = 2 / 0.7;
    int t2 = t;
    if (t > (double)t2) cout << "yes";
    cout << t << " " << t2;
    return 0;
}