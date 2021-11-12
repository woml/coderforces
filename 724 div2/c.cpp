#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

PII get_radio(int a, int b)  {
    int d = gcd(a, b);
    a /= d; b /= d;
    return {a, b};
}

int main(void) {
    int T;
    cin >> T;
    while (T --) {
        map<PII, int> m;
        int n;
        string s;
        cin >> n >> s;
        int k = 0, d = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'D') d++;
            else k++;
            //cout << get_radio(d, k).first << " " << get_radio(d, k).second << endl;
            m[get_radio(d, k)]++;
            cout << m[get_radio(d, k)] << " ";
        }
        cout << endl;
    }

    return 0;
}