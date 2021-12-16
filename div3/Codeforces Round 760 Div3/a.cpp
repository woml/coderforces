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
        int n = 7;
        int arr[8];
        int a, b, c;
        for (int i = 0; i < 7; i++) cin >> arr[i];
        a = arr[0];
        b = arr[1];
        c = arr[6] - a - b;
        cout << a << " " << b << " " << c << endl;
    }

    return 0;
}
