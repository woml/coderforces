#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

int main(void) {
    int T;
    cin >> T;
    while (T --) {
        int n, a, b;
        cin >> n >> a >> b;
        unordered_map<int, int> h;
        bool flag = false;
        if (a == 1) {
            if (n == 1) flag = true;
            else {
                n -= 1;
                if (n % b == 0) {
                    flag = true;
                }  
            }
        } else {
            int j = 0;
            LL sum = 1;
            while (sum <= n) {
                int t = n - sum;
                if (t % b == 0) {
                    flag = true;
                    break;
                }
                sum = (LL)sum * a;
            }
        }
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}