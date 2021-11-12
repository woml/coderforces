#include <iostream>
#include <algorithm>
#include <cstring>

using  namespace std;

const int N = 500;

char g[N][N];

int main(void) {
    int T;
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> g[i];
        int sx = -1, sy = -1, ex = -1, ey = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == '*') {
                    if (sx == -1) {
                        sx = i, sy = j;
                    } else {
                        ex = i, ey = j;
                    }
                }
            }
        }  
        if (sx != ex && sy != ey) {
            g[sx][ey] = '*';
            g[ex][sy] = '*';
        } else if (sx == ex) {
            int t = 1;
            if (sx >= t) {
                g[sx - t][sy] = '*';
                g[sx - t][ey] = '*';
            } else if (sx + t < n) {
                g[t + sx][sy] = '*';
                g[t + ex][ey] = '*';
            } 
        } else {
            int t = 1;
            if (sy >= t) {
                g[sx][sy - t] = '*';
                g[ex][sy - t] = '*';
            } else if (sy + t < n) {
                g[sx][sy + t] = '*';
                g[ex][sy + t] = '*';
            } 
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << g[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}