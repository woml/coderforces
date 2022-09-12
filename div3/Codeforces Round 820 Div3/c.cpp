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
        string s;
        cin >> s;
        int n = s.size();
        vector<vector<int>> arr(26);
        for (int i = 0; i < s.size(); i++) {
            int t = s[i] - 'a';
            arr[t].push_back(i + 1);
        }
        int cost = abs(s[n - 1] - s[0]);
        int m = 0, del = 1;
        if (s[n - 1] >= s[0]) {
            for (char i = s[0]; i <= s[n - 1]; i += del) {
                int t = i - 'a';
                m += arr[t].size();
            }
            cout << cost << " " << m << endl;
            
            for (char i = s[0]; i <= s[n - 1]; i += del) {
                int t = i - 'a';
                // cout << "t = " << t << endl;
                for (int j = 0; j < arr[t].size(); j++) 
                    cout << arr[t][j] << " ";
            }
        } else {
            for (char i = s[0]; i >= s[n - 1]; i -= 1) {
                int t = i - 'a';
                m += arr[t].size();
            }
            cout << cost << " " << m << endl;
            
            for (char i = s[0]; i >= s[n - 1]; i -= 1) {
                int t = i - 'a';
                // cout << "t = " << t << endl;
                for (int j = 0; j < arr[t].size(); j++) 
                    cout << arr[t][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
