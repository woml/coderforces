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
int arr[N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        int minv = 1e7;
        for (int i = 0; i < n; i++) minv = min(minv, arr[i]);
        int gg = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] != minv) {
                int d = arr[i] - minv;
                if (gg == -1) gg = d;
                else gg = gcd(gg, d);
            }
        }
        cout << gg << endl;
    }

    return 0;
}
