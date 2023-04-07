#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

const int N = 1e5 + 10;
std::vector<int> primes;

void solve() {
    int a, b, k, ta, tb;
    std::cin >> a >> b >> k;
    int cnt_a = 0, cnt_b = 0;
    ta = a, tb = b;
    for (auto prime : primes) {
        while (a % prime == 0) {
            a /= prime;
            cnt_a++;
        }
        if (a == 1) break;
    }
    for (auto prime : primes) {
        while (b % prime == 0) {
            b /= prime;
            cnt_b++;
        }
        if (b == 1) break;
    }
    if (a > 1) cnt_a++;
    if (b > 1) cnt_b++;
    if (k == 1) {
        if (ta < tb) std::swap(ta, tb);
        if (ta % tb == 0 && ta != tb) std::cout << "Yes\n";
        else std::cout << "No\n";
    } else if (k <= cnt_b +  cnt_a) std::cout << "Yes\n";
    else std::cout << "No\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int cases;
    std::cin >> cases;
    for (int i = 2; i * i <= 1e9; i++) {
        bool is_prime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) primes.push_back(i);
    }
    while (cases -- ) {
        solve();
    }
}