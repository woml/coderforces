#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        unordered_map<char, int> hash;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            hash[s[i]] = i;
        }
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            ans += abs(hash[s[i]] - hash[s[i + 1]]);
        }
        cout << ans << endl;
    }

    return 0;
}