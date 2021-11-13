#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10, INF = 1e9;

string str[] = {"aa", "aba", "aca", "abca", "acba", "abbacca", "accabba"};

vector<string> t(str, str + 7);

int main(void) {
    int T;
    cin >> T;
    while (T --) {
        int len, ans = -1;
        cin >> len;
        string s;
        cin >> s;
        for (int i = 0; i < t.size(); i++) {
            int j = t[i].size();
            for (int k = 0; k + j - 1 < len; k++) {
                if (s.substr(k, j) == t[i]) {
                    ans = j;
                    break;
                }
            }
            if (ans != -1) break;
        }
        cout << ans << endl;
    }

    return 0;
}
