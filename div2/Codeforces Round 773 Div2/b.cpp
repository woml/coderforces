#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 3e5 + 10;

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n, idx = 0;
        cin >> n;
        map<int, int> hash;
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            hash[x]++;
        }
        for (auto d : hash) idx++;
        for (int i = 0; i < n; i++) {
            if(i >= idx) {
                idx++;
            }
            printf("%d ", idx);
        }
        printf("\n");
    }

    return 0;
}
