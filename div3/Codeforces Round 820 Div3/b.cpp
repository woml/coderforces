#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        string s, ans;
        cin >> n >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                char c = s[i] - '0' + 'a' - 1;
                ans.push_back(c);
            } else {
                if (i + 1 < n && s[i + 1] == '0') {
                    char b = ans.back(); ans.pop_back();
                    int t = (b - 'a' + 1) * 10;
                    ans.push_back(t + 'a' - 1);
                    i++;
                } else {
                    char a = ans.back(); ans.pop_back();
                    char b = ans.back(); ans.pop_back();
                    int t = (b - 'a' + 1) * 10 + (a - 'a' + 1);
                    ans.push_back(t + 'a' - 1);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
