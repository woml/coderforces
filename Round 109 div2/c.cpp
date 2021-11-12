#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <numeric>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

int main(void) {
    int t;
    scanf("%d", &t);
    while (t --) {
        int n, m;
        scanf("%d %d", &n, &m);
        vector<PII> r(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &r[i].x);
        char s[2];
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            if (s[0] == 'L') r[i].y = -1;
            else r[i].y = 1;
        }
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&r](int a, int b) {
            return r[a].x < r[b].x;
        });
        
        vector<int> ans(n, -1);
        vector<vector<int>> par(2);
        for (auto i : ord) {
            int p = r[i].x % 2;
            if (r[i].y == -1) {    //  <- i
                if (par[p].empty()) 
                    par[p].push_back(i);
                else {
                    int j = par[p].back(); par[p].pop_back();
                    if (r[j].y == 1)      //             j ->   <- i
                        ans[i] = ans[j] = (r[i].x - r[j].x) / 2;
                    else                  //   j ->   |  <- j    <-i
                        ans[i] = ans[j] = (r[i].x + r[j].x) / 2;
                }
            } else      //  i ->
                par[p].push_back(i);
        }

        for (int p = 0; p < 2; p++) {
            while (par[p].size() > 1) {         
                int i = par[p].back(); par[p].pop_back();
                int j = par[p].back(); par[p].pop_back();
                if (r[j].y == -1)      //    |       <- j     i ->     |
                    ans[i] = ans[j] = (2 * m - r[i].x + r[j].x) / 2;
                else                   //    |       j ->     i ->     |
                    ans[i] = ans[j] = (2 * m - r[i].x - r[j].x) / 2;
            }
        }
        for (int i = 0; i < n; i++)
            printf("%d ", ans[i]);
        printf("\n");
    }

    return 0;
}