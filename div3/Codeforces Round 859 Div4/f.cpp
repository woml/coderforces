#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 5e4 + 10;
int st[N];
int dx[4] = {1, -1, -1, 1}, dy[4] = {1, 1, -1, -1};  // DR, UR, UL, DL
// left & up -> 1  right & down -> 2

// (x / 7) + 1,  (x - 1) % 7 + 1

int ret_k(int x) {
    if (x == 0 || x == 2) return 1;
    return -1;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n, m, x, y, edx, edy;
        string d;
        cin >> n >> m >> x >> y >> edx >> edy >> d;
        int toward, ans = 0;
        if (d == "DR") toward = 0;
        if (d == "UR") toward = 1;
        if (d == "UL") toward = 2;
        if (d == "DL") toward = 3;
        // cout << "tow = " << toward << endl;
        bool find = false;
        while (true) {
            // cout << "x = " << x << " y = " << y << " " << edx << " " << edy << endl;
            if (abs(edx - x) == abs(edy - y)) {
                if (edx < x && edy < y && toward == 2) {
                    find = true;
                    break;
                }
                if (edx > x && edy > y && toward == 0) {
                    find = true;
                    break;
                }
                if (edx < x && edy > y && toward == 1) {
                    find = true;
                    break;
                }
                if (edx > x && edy < y && toward == 3) {
                    find = true;
                    break;
                }
                if (edx == x && edy == y) {
                    find = true;
                    break;
                }
            } 
            int k = ret_k(toward);
            int b = y - k * x;
            // printf("%d %d %d\n", toward, k, b);
            if (toward == 0) {
                int newy = k * n + b;
                if (newy > m) {
                    y = m;
                    x = (y - b) / k;
                } else {
                    x = n, y = newy;
                }
                if (y == m && x == n) toward = 2;
                else if (x == n) toward = 1;
                else toward = 3;
            } else if (toward == 1) {
                int newy = k + b;
                if (newy > m) {
                    y = m;
                    x = (y - b) / k;
                } else {
                    y = newy, x = 1;
                }
                if (y == m && x == 1) toward = 3;
                else if (x == 1) toward = 0;
                else toward = 2;
            } else if (toward == 2) {
                int newy = k + b;
                if (newy < 1) {
                    y = 1;
                    x = (y - b) / k;
                } else {
                    x = 1, y = newy;
                }
                if (y == 1 && x == 1) toward = 0;
                else if (x == 1) toward = 3;
                else toward = 1;
            } else if (toward == 3) {
                int newy = k * n + b;
                if (newy < 1) {
                    y = 1;
                    x = (y - b) / k;
                } else {
                    x = n, y = newy;
                }
                if (y == 1 && x == n) toward = 1;
                else if (y == 1) toward = 0;
                else toward = 2;
            }
            // printf("ans = %d, x = %d, y = %d\n", ans, x, y);
            ans++;
            if (ans > 2 * m + 2 * n) break;
        }
        if (find) cout << ans << endl;
        else cout << "-1" << endl;
        memset(st, 0, sizeof st);
    }

    return 0;
}
