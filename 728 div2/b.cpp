#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int q[N];

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &q[i]);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (i + j == q[i] * q[j]) ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}