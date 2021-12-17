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

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main(void) {
    int T;
    cin >> T;
    vector<int> prime;
    prime.push_back(1);
    for (int i = 2; i <= 10000; i++) {
        bool flag = true;
        for (int j = 2; j <= i / j; j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) prime.push_back(i);
    }
    while (T -- ) {
        int n;
        cin >> n;
        for (int i = 0; i < prime.size(); i++) {
            bool find = false;
            if (n % prime[i] == 0) {
                int d = n / prime[i] - 1;
                for (int j = 0; j < prime.size(); j++) {
                    int k = d - prime[j];
                    //cout << k * prime[i]  << " " << prime[j] * prime[i]  << " " << prime[i] << endl;
                    if (k > 0 && k % prime[j] != 0) {
                        find = true;
                        cout << k * prime[i]  << " " << prime[j] * prime[i]  << " " << prime[i] << endl;
                        break;
                    }
                }
            }
            if (find) break;
        }
    }

    return 0;
}
