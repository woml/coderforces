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
        bool flag = false, first_is_even = false;
        int t = n;
        while (t) {
            if (t % 2 == 0) flag = true;
            t /= 10;
            if (t < 10 && t != 0) {
                first_is_even = (t % 2 == 0) ? true : false;
            }
        }
        if (n % 2 == 0) cout << "0" << endl;
        else if (!flag) {
            cout << "-1" << endl;
        } else if (first_is_even) {
            cout << "1" << endl;
        } else {
            cout << "2" << endl;
        }
    }

    return 0;
}
