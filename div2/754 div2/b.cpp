#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;

bool check(string s) {
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == '1' && s[i + 1] == '0') return false;
    }
    return true;
}

int main(void) {
    int T;
    cin >> T;
    while (T --) {
        int len;
        cin >> len;
        string s;
        cin >> s;
        int cnt = 0;
        vector<vector<int>> ans(10000);
        while (true) {
            if (check(s)) break;
            int i = 0, j = len - 1;
            while (i < j) {
                while (i < j && s[i] != '1') i++;
                while (i < j && s[j] != '0') j--;
                if (i < j) {
                    swap(s[i], s[j]);
                    ans[cnt].push_back(i);
                    ans[cnt].push_back(j);
                }
                if (i >= j) {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
        for (int i = 0; i < cnt; i++) {
            cout << ans[i].size() << " ";
            for (int j = 0; j < ans[i].size(); j += 2) 
                cout << ans[i][j] + 1 << " ";
            for (int j = ans[i].size() - 1; j > 0; j -= 2) 
                cout << ans[i][j] + 1 << " ";
            cout << endl;
        }
    }

    return 0;
}