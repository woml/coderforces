#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

bool check(vector<int> arr) {
    for (int i = 0; i < arr.size()-1; i++) {
        if (arr[i] > arr[i+1]) return false;
    }
    return true;
}

vector<int> del(vector<int> &a, int idx) {
    vector<int> res, t;
    for (int i = 0; i < a.size(); i++) {
        if (i == idx) continue;
        t.push_back(a[i]);
    }
    for (int i = 0; i < t.size()-1; i++) {
        res.push_back(gcd(t[i], t[i+1]));
    }
    return res;
}

bool solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) {
        b[i] = gcd(a[i], a[i+1]);
        // cout << b[i] << " ";
    }
    // cout << "\n";
    bool used = false;
    for (int i = 0; i < n-1; i++) {
        if (b[i] > b[i+1]) {
            if (used) return false;
            // cout << "i = " << i << "\n";
            if (check(del(a, i)) || check(del(a, i+1)) || check(del(a, i+2))) return true;
            used = true;
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T -- ) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
        // cout << "\n";
    }
    return 0;
}