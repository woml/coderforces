#include <bits/stdc++.h>

using namespace std;

bool solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    string s;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> s;
    vector<int> sub, add; 
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') sub.push_back(a[i]);
        else add.push_back(a[i]);
    }
    sort(add.begin(), add.end(), [](int &a, int &b) {
        return a > b;
    });
    sort(sub.begin(), sub.end());
    int l = 1, r = n;
    for (auto t : add) {
        if (t > r) return false;
        r--;
    }
    for (auto t : sub) {
        if (t < l) return false;
        l++;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T -- ) 
    if (solve()) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}