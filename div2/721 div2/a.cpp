#include <iostream>

using namespace std;

int main(void) {
    int T;
    scanf("%d", &T);
    while (T --) {
        int t;
        scanf("%d", &t);
        int cnt = 0;
        while (t) {
            t >>= 1;
            cnt++;
        }
        cout << (1 << (cnt - 1)) - 1 << endl;
    }
    return 0;
}