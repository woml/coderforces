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
        vector<int> cnt(26, 0);
        for (int i = 0; i < 2; i++) {
            string s;
            cin >> s;
            cnt[s[0] - 'a']++;
            cnt[s[1] - 'a']++;
        }
        int four = 0, three = 0, two = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 4) four++;
            else if (cnt[i] == 3) three++;
            else if (cnt[i] == 2) two++;
        }
        if (four == 1) cout << "0" << endl;
        else if (three == 1) cout << "1" << endl;
        else if (two == 2) cout << "1" << endl;
        else if (two == 1) cout << "2" << endl;
        else cout << "3" << endl; 
    }

    return 0;
}
