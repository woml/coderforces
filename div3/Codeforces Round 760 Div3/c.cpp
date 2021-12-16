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
 
LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}
 
LL arr[N];
 
int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        LL a = arr[0];
        for (int i = 0; i < n; i += 2) {
            a = gcd(a, arr[i]);
        }
        vector<LL> cnt;
        // for (LL i = 1; i <= a / i; i++) {
        //     if (a % i == 0) {
        //         cnt.push_back(i);
        //         cnt.push_back(a / i);
        //     }
        // }
        cnt.push_back(a);
        bool find = false;
        for (int i = 0; i < cnt.size(); i++) {
            LL t = cnt[i];
            bool flag = true;
            for (int j = 1; j < n; j += 2) {
                if (arr[j] % t == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                find = true;
                cout << t << endl;
                break;
            }
        }
        if (!find) {
            a = arr[1];
            for (int i = 1; i < n; i += 2) {
                a = gcd(a, arr[i]);
            }
            cnt.clear();
            cnt.push_back(a);
            // for (LL i = 1; i <= a / i; i++) {
            //     if (a % i == 0) {
            //         cnt.push_back(i);
            //         cnt.push_back(a / i);
            //     }
            // }
            for (int i = 0; i < cnt.size(); i++) {
                LL t = cnt[i];
                bool flag = true;
                for (int j = 0; j < n; j += 2) {
                    if (arr[j] % t == 0) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    find = true;
                    cout << t << endl;
                    break;
                }
            }
        }
        if (!find) cout << "0" << endl;
    }
 
    return 0;
}