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
        string a, b;
        cin >> a >> b;
        sort(a.begin(), a.end(), [](char x, char y)  {
            return x < y;
        });
        if (b != "abc") cout << a << endl;
        else {
            bool change = true;
            int i = 0, j = 0, n = a.size();
            int a1, a2, a3;
            a1 = 0;
            while (i < n && a[i] == b[j]) i++;
            if (i == n || a1 == i) change = false;
            a2 = i;
            j++;
            while (i < n && a[i] == b[j]) i++;
            if (i == n || a2 == i) change = false;
            a3 = i;
            j++;
            while (i < n && a[i] == b[j]) i++;
            if (a3 == i) change = false;
            if (!change) cout << a << endl;
            else {
                cout << a.substr(0, a2) + a.substr(a3, i - a3) + a.substr(a2, a3 - a2) + a.substr(i) << endl;
            }
        }
    }

    return 0;
}
