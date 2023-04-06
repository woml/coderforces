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

void solve() {
    int n, s1, s2;
    std::cin >> n >> s1 >> s2;
    std::vector<int> a, b;
    std::vector<PII> arr;
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        arr.push_back({x, i});
    }
    std::sort(arr.begin(), arr.end(), [](PII &x, PII &y) {
        return x.first > y.first;
    });
    if (s1 <= s2) {
        int t1 = 1, t2 = 1;
        for (int i = 0; i < arr.size(); i++) {
            if (t1 * s1 <= s2 * t2) {
                a.push_back(arr[i].second);
                t1++;
            } else {
                b.push_back(arr[i].second);
                t2++;
            }
        }
    } else {
        int t1 = 1, t2 = 1;
        for (int i = 0; i < arr.size(); i++) {
            if (t1 * s1 >= s2 * t2) {
                // cout << "i = " << i << "-->\n";
                b.push_back(arr[i].second);
                t2++;
            } else {
                // cout << "i = " << i << "<--\n";
                a.push_back(arr[i].second);
                t1++;
            }
        }
    }
    std::cout << a.size() << " ";
    for (auto x : a) std::cout << x << " ";
    std::cout << "\n";
    std::cout << b.size() << " ";
    for (auto x : b) std::cout << x << " ";
    std::cout << "\n";
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
