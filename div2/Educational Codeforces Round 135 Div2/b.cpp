#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        if (n & 1) {
            cout << "1 2 3 ";
            for (int i = n - 2; i >= 4; i--) cout << i << " "; 
        } else {
            for (int i = n - 2; i; i--) {
                cout << i << " ";
            }
        }
            cout << n - 1 << " " << n << endl; 
    }

    return 0;
}
