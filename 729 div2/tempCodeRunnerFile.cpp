#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        string s;
        cin >> s;
        int n = s.size();
        int i = 0, j = n - 1;
        bool flag = true;
        if (n < 1 || n > 26) flag = false;
        while (i <= j) {
            if ((s[i] != n + 'a' - 1) && (s[j] != n + 'a' - 1)) {
                flag = false;
                //cout << i << " " << j << endl;
                //cout << s[i] << " " << s[j] << " " << n << endl;
                break;
            }
            if (s[i] == n + 'a' - 1) i++;
            else if (s[j] == n + 'a' - 1) j--;
            n--;
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}