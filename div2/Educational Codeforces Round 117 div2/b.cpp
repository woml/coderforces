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
        int n, a, b;
        cin >> n >> a >> b;
        if (a < b) {
            if (n - b > (n / 2 - 1) || a - 1 > (n / 2 - 1))
                cout << "-1" << endl;
            else {
                for (int i = n; i > b; i--) cout << i << " ";
                cout << a << " ";
                for (int i = b - 1; i > a; i--) cout << i << " ";
                cout << b << " ";
                for (int i = a - 1; i > 0; i--) cout << i << " ";
                cout << endl;
            }
        } else {
            if (n - a < (n / 2 - 1) || b - 1 < (n / 2 - 1))
                cout << "-1" << endl;
            else {
                for (int i = n; i > 0; i--) cout << i << " ";
                cout << endl;
            }
        }
    }
    return 0;
}