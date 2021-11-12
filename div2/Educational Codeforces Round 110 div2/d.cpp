#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>


using namespace std;
typedef long long LL;

const int N = 1e6, M = 1 << 18;
int idx;
int tree[N];

int get(int x, int n) {
    for (int i = 0; i < 19; i++) {
        int t = 1 << i;
        if (x < t) {
            int res = t - x;
            return (1 << (i - 1)) - 1 + res;
        } 
    }
}


int main(void) {
    int k, t;
    string s;
    cin >> k;
    cin >> s;
    cin >> t;
    int n = s.size();
    int idx = 0;
    for (int i = 1 << k; i < 1 << (k + 1); i++) tree[i] = 1;
    for (int i = k - 1; ~i; i--) {
        for (int j = 1 << i; j < 1 << (i + 1); j++) {
            if (s[idx] == '?') tree[j] = tree[j * 2] + tree[j * 2 + 1];
            else if (s[idx] == '0') tree[j] = tree[j * 2];
            else tree[j] = tree[j * 2 + 1];
            idx++;
        }
    }
    // for (int i = 1; i <= 15; i++) {
    //     cout << tree[i] << endl;
    // }
    while (t --) {
        int a;
        char op[2];
        scanf("%d %s", &a, op);
        s[a - 1] = op[0];
        int rev_a = get(n + 1 - a, n + 1);
        //cout << rev_a << endl;
        if (*op == '?') {
            tree[rev_a] = tree[rev_a * 2] + tree[rev_a * 2 + 1]; 
            while (rev_a != 0) {
                rev_a = rev_a / 2;
                int l = get(n + 1 - rev_a, n + 1);
                int p = n - l;
                //cout << "p = " << p;
                if (s[p] == '?') tree[rev_a] = tree[rev_a * 2] + tree[rev_a * 2 + 1];
                else if (s[p] == '1') tree[rev_a] = tree[rev_a * 2 + 1];
                else tree[rev_a] = tree[rev_a * 2];
            }
        } else if (*op == '1') {
            tree[rev_a] = tree[rev_a * 2 + 1];
            while (rev_a != 0) {
                rev_a = rev_a / 2;
                int l = get(n + 1 - rev_a, n + 1);
                int p = n - l;
                if (s[p] == '?') tree[rev_a] = tree[rev_a * 2] + tree[rev_a * 2 + 1];
                else if (s[p] == '1') tree[rev_a] = tree[rev_a * 2 + 1];
                else tree[rev_a] = tree[rev_a * 2];
            }
        } else {
            tree[rev_a] = tree[rev_a * 2];
            while (rev_a != 0) {
                rev_a = rev_a / 2;
                int l = get(n + 1 - rev_a, n + 1);
                int p = n - l;
                if (s[p] == '?') tree[rev_a] = tree[rev_a * 2] + tree[rev_a * 2 + 1];
                else if (s[p] == '1') tree[rev_a] = tree[rev_a * 2 + 1];
                else tree[rev_a] = tree[rev_a * 2];
            }
        }
        cout << s << endl;
        for (int i = 0; i <= 3; i++) {
            for (int j = (1 << i); j < 1 << (i + 1); j++) {
                cout << tree[j] << " ";
            }
            cout << endl;
        }
        printf("\n\n%d\n\n", tree[1]);
    }
    return 0;
}