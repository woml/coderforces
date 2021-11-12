#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>


using namespace std;
typedef long long LL;


int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int m = max(a, b);
        int n = max(c, d);
        if (m < min(c, d) || n < min(a, b)) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}