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
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        bool is_ans = true;
        int last_odd = -1, last_even = -1;
        
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i + 1]) {
                is_ans = false;
            }
            if (arr[i + 1] & 1) last_odd = i + 1;
            else last_even = i + 1;
        }
        if (is_ans) cout << "0" << endl;
        else {
            if (arr[1] & 1) {
                last_odd = max(1, last_odd);
                cout << n - 1 << endl;
                for (int i = 1; i < last_odd; i++) 
                    if (arr[i] & 1) cout << i << " " << last_odd << endl;
                for (int i = 2; i <= n; i++) 
                    if (arr[i] % 2 == 0) cout << "1 " << i << endl;
            } else {
                last_even = max(1, last_even);
                cout << n - 1 << endl;
                for (int i = 1; i < last_even; i++) 
                    if (arr[i] % 2 == 0) cout << i << " " << last_even << endl;
                for (int i = 2; i <= n; i++) 
                    if (arr[i] & 1) cout << "1 " << i << endl;
            }
        }
    }

    return 0;
}
