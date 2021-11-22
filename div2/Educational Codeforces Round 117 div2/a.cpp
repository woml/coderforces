#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_map>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e6;

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int a, b;
        cin >> a >> b;
        if ((a + b) & 1) {
            cout << "-1 -1" << endl;
        } else {
            if (a % 2 == 0) {
                cout << a / 2 << " " << b / 2 << endl;
            } else {
                cout << (a + 1) / 2 << " " << (b - 1) / 2 << endl;
            }
        }
    }
    return 0;
}