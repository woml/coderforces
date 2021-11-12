#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

typedef long long LL;

const int N = 1010;
string s;

bool check(string b) {
    int n = b.size();
    for (int i = 0; i < s.size() - n + 1; i++) {
        string l = s.substr(i, n);
        if (l == b) return false;
    }
    return true;
}

int main(void) {
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n >> s;
        bool flag = false;
        for (int len = 1; ; len++) {
            string b = string(len, 'a');
            while (true) {
                if (check(b)) {
                    flag = true;
                    cout << b << endl;
                    break;
                }
                b[b.size() - 1]++;
                //cout << b << endl;
                int m = 0;
                bool jump = false;
                while (b[b.size() - 1 - m] == 'z' + 1) {
                    b[b.size() - 1 - m] = 'a';
                    if (b.size() < 2 + m) {
                        jump = true;
                        break;
                    }
                    b[b.size() - 2 - m]++;
                    m++;
                }
                if (flag || jump) break;
            }
            if (flag) break;
        }
    }

    return 0;
}