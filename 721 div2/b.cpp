#include <iostream>

using namespace std;

char s[10100];

int main(void) {
    int T;
    cin >> T;
    while (T --) {
        int n;
        scanf("%d", &n);
        scanf("%s", s);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cnt ++;
            }
        }
        if (cnt == 0) printf("DRAW\n");
        else if (cnt == 1) printf("BOB\n");
        else {
            if (cnt & 1) printf("ALICE\n");
            else printf("BOB\n");
        }
    }

    return 0;
}