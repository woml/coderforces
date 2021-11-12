#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10; 
char s[N];

int main(void) {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cin >> s;
        int cnt_m = 0, cnt_tt = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'T') cnt_tt++;
            else {
                cnt_m++;
                if (cnt_m > cnt_tt) {
                    flag = false;
                    break;
                }
            }
        }
        cnt_m = cnt_tt = 0;
        for (int i = n - 1; ~i; i--) {
            if (s[i] == 'T') cnt_tt++;
            else {
                cnt_m++;
                if (cnt_m > cnt_tt) {
                    flag = false;
                    break;
                }
            }
        }
        if (cnt_m * 2 != cnt_tt) flag = false;
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
        }
    return 0;
}