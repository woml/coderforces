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
        string s;
        cin >> s;
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'N') cnt++;
        }
        if (cnt == 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}
