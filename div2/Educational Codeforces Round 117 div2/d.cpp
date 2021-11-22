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
        LL a, b, x;
        cin >> a >> b >> x;
        if (x > a && x > b) cout << "NO" << endl;
        else  {
        // if (a % x == 0 ||b % x == 0)
            cout << "YES" << endl;
        }
    }
    return 0;
}