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
        int t = 0;
        bool f = true;
        for (int i = 0, j = n - 1; i < n; i++, j --) {
            if (s[i] == '0') {
                cnt ++;
            }
            if (s[i] != s[j]) {
                f = false;
                t++;
            }
        }
        t /= 2;
        // easy version palindrome
        if (f) {
            if (cnt == 0) printf("DRAW\n");
            else if (cnt == 1) printf("BOB\n");
            else {
                if (cnt & 1) printf("ALICE\n");
                else printf("BOB\n");
            }
        }
        else {
            if (t >= 2) {
                printf("ALICE\n");
            }
            else if (t == 1) {
                if (cnt == 2) printf("DRAW\n");
                else printf("ALICE\n");
            }
        }
        
    }
    return 0;
}