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
        int a, b, c;
        cin >> a >> b >> c;
        int t = max(b, c);
        if (a <= t) 
            cout << t - a + 1 << " ";
        else cout << "0 ";
        t = max(a, c);
        if (b <= t) 
            cout << t - b + 1 << " ";
        else cout << "0 ";
        t = max(a, b);
        if (c <= t)
            cout << t - c + 1 << endl;
        else cout <<"0" << endl;
    }

    return 0;
}
