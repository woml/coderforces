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
        vector<int> arr(n);
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr[i] = x;
            hash[x]++;
        }
        sort(arr.begin(), arr.end(), [](int a, int b) {
            return a > b;
        });
        for (int i = 0; i < n / 2; i++) {
            int j = n - 1;
            while (j && hash[arr[i] % arr[j]]) j--;
            if (j == 0) n += 2;
            else {
                cout << arr[i] << " " << arr[j] << endl;
            }
        }
    }

    return 0;
}
