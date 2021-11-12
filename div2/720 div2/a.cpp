#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n, s;

bool check(vector<int> &a) {
    for (int i = 0, j = a.size() - 1; i < j; i++, j--) {
        if (a[i] != a[j]) return false;
    }
    return true;
}

int main(void) {
    cin >> n >> s;
    while (n) {
        s++;
        int cnt = 0;
        vector<int> a;
        for (int i = 2; i <= 10; i++) {
            int t = s;
            a.clear();
            while (t) {
                a.push_back(t % i);
                t /= i;
            }
            if (check(a)) cnt++;
            if (cnt >= 2)  {
                cout << s << endl;
                n--;
            }
        }
    }
    return 0;
}