#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using  namespace std;

const int N = 1000;

int a[N];

int main(void) {
    int T;
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        unordered_map<int, int> h;
        for (int i =  0; i < n; i++) {
            cin >> a[i];
            h[a[i]]++;
        }
        int t = 0;
        for (auto [k,v] : h) {
            if (v == 1) t = k;
        }
        for (int i = 0; i < n; i++)
            if (a[i] == t) 
                cout << i + 1 << endl;


    }
    return 0;
}
