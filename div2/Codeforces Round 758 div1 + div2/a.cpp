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

bool prime_check(int x) {
    if (x == 2) return true;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        for (int i = 2;; i++) {
            if (prime_check(i)) {
                cout << i << " ";
                n--;
                if (n == 0) break;
            }
        }
        cout << endl;
    }

    return 0;
}
