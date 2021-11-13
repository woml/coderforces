#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10, M = 2 * N;

int e[M], ne[M], idx;
int w_cnt, b_cnt;


void dfs(int t, int c, vector<int>& color, vector<int>& h) {
    //cout << "t = " << t << endl;
    color[t] = c;
    if (c == 1) b_cnt++;
    else w_cnt++;
    for (int i = h[t]; ~i; i = ne[i]) {
        int j = e[i];
        if (color[j] == -1) dfs(j, (c + 1) % 2, color, h);
    }
}

int main(void) {
    int T;
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        vector<int> h(n + 5, -1);
        vector<int> color(n + 5, -1);
        idx = 0;
        w_cnt = b_cnt = 0;
        for (int i = 1; i < n; i ++) {
            int a, b;
            cin >> a >> b;
            e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
            e[idx] = a; ne[idx] = h[b]; h[b] = idx++;
        }
        
        // /*
        //     Test:
        // */
        // for (int i = 1; i <= n; i++) {
        //     for (int k = h[i]; k != -1; k = ne[k]) {
        //         int j = e[k];
        //         cout << i << "-" << j << endl; 
        //     }
        //     cout << "------" << endl;
        // }
        
        for (int i = 1; i <= n; i ++) 
            if (color[i] == -1 && i == 1) dfs(i, 1, color, h);
        
        // /*
        //     Test:
        // */
        // for (int i = 1; i <= n; i ++ ) {
        //     cout << "Node " << i << " : " << color[i] << endl;
        // }
        

        int target = w_cnt > b_cnt ? b_cnt : w_cnt;
        // cout << target << " " << w_cnt << " " << b_cnt;
        bool st[100];
        memset(st, 0, sizeof st);
        for (int i = 1; (1 << (i - 1)) <= target; i ++) {
            if ((1 << (i - 1)) & target) {
                st[i] = 1;
            }
            //cout << "st[" << i << "] = " << st[i] << endl;
        }

        vector<int> black_num;
        vector<int> white_num;
        int len = 1, hig = 1;
        
        for (int i = 1; i <= n; i++) {
            if ((i | hig) > i) {
                len++;
                hig = hig << 1;
            }
            //cout << "i = " << i << " len = " << len << " h = " << h << endl;
            if (st[len]) {
                if (target == w_cnt) white_num.push_back(i);
                else black_num.push_back(i);
            } else {
                if (target == w_cnt) black_num.push_back(i);
                else white_num.push_back(i);
            }
        }
        // for (auto x : white_num) 
        //     cout << x << " ";
        int b_now = 0, w_now = 0;
        for (int i = 1; i <= n; i ++ ) {
            if (color[i] == 0) 
                cout << white_num[w_now++] << " ";
            else 
                cout << black_num[b_now++] << " ";
        }
        cout << endl;
    }

    return 0;
}