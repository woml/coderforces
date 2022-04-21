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
        int n, t;
        cin >> n;
        if (n >= 1900) t = 1;
        else if (n >= 1600) t = 2;
        else if (n >= 1400) t = 3;
        else t = 4;
        cout << "Division " << t << endl;
    }

    return 0;
}
