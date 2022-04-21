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

char s[55][55];

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> s[i];

        // column 
        for (int j = 0; j < m; j++) {
            int cnt = 0, last_o = n;
            for (int i = n - 1; i >= 0; i--) {
                if (s[i][j] == '*') {
                    cnt++;
                    s[i][j] = '.';
                }
                else if (s[i][j] == 'o') {
                    for (int k = last_o - 1; cnt > 0; cnt--, k--) {
                        s[k][j] = '*';
                    }
                    last_o = i;
                }
            }
            for (int k = last_o - 1; cnt > 0; cnt--, k--) {
                s[k][j] = '*';
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << s[i][j];
            cout << endl;
        }
        // cout << endl;
    }

    return 0;
}
