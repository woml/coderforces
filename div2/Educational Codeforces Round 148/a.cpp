#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
    string s;
    vector<int> cnt(26);
    cin >> s;
    int t_odd = -1, t_even = 0;
    for (auto c : s) {
        cnt[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) 
        if (cnt[i] & 1) t_odd = i;
        else if (cnt[i] > 0) t_even++;
    if (t_even > 1 || (t_odd != -1 && cnt[t_odd] > 1 && t_even > 0)) cout << "YES\n";
    else cout << "NO\n";
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int cases;
    std::cin >> cases;
    while (cases -- ) {
        solve();
    }

    return 0;
}
