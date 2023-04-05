/**
 * @file e.cpp
 * @author woml
 * @brief wait to do
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cstring>
#include <set>
#include <map>
#include <vector>

const int N = 100100, M = N * 2;

std::map<int, int> cnt1, cnt2;
std::set<int> mad1, mad2;
std::vector<int> path, path_rank;

int h[N], e[M], ne[M], w[M], idx;
int v[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

bool dfs(int a, int b) {
    st[a] = 1;
    path.push_back(a);
    if (a == b) return true;
    for (int i = h[a]; ~i; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            path_rank.push_back(w[i]);
            if (dfs(j, b)) return true;
            path_rank.pop_back();
        }
    }
    path.pop_back();
    return false;
}

int mad() {
    int res = 0;
    if (!mad1.empty()) res = *mad1.rbegin();
    if (!mad2.empty()) res = std::max(res, *mad2.rbegin());
    return res;
}

void modify(int u, int b1, int b2) {
    cnt1[v[u]]++;
    if (cnt1[v[u]] == 2) mad1.insert(v[u]);
    cnt2[v[u]]--;
    if (cnt2[v[u]] < 2) mad2.erase(v[u]);

    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == b1 || j == b2) continue;
        modify(j, u, -1);
    }
}

void solve() {
    int n;
    std::cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        add(--a, --b, i); add(b, a, i);
    }
    std::map<int, std::vector<int>> count;
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
        cnt2[v[i]]++;
        count[v[i]].push_back(i);
        if (cnt2[v[i]] == 2) {
            mad2.insert(v[i]);
        }
    }
    while (!count.empty() && count.rbegin() -> second.size() == 1) count.erase(prev(count.end()));
    if (count.empty()) {
        for (int i = 0; i < n - 1; i++)
            std::cout << "0\n";
        return;
    }
    if (count.rbegin() -> second.size() > 2) {
        for (int i = 0; i < n - 1; i++) {
            std::cout << count.rbegin() -> first << "\n";
        }
        return;
    }
    int a = count.rbegin() -> second[0], b = count.rbegin() -> second[1];
    dfs(a, b);
    std::vector<int> ans(n - 1, v[a]);
    modify(path[0], path[1], -1);
    ans[path_rank[0]] = mad();
    for (int i = 1; i + 1 < path.size(); i++) {
        modify(path[i], path[i - 1], path[i + 1]);
        ans[path_rank[i]] = mad();
    }
    for (int i = 0; i < n - 1; i++)
        std::cout << ans[i] << "\n";
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}