#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n+10);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin()+1, arr.begin()+n+1, [](pair<int,int>&a, pair<int,int>&b){
        return a.first > b.first;
    });

    vector<int> ans(n+10);
    set<int> cnt;
    cnt.insert(0); cnt.insert(n+1);

    for (int i = 1; i <= n; i++) {
        int t = arr[i].second;
        int idx = *prev(cnt.lower_bound(t));
        ans[idx]++;
        ans[t+1]--;
        // cout << idx << " " << t << "\n";
        cnt.insert(t);
    }
    for (int i = 1; i <= n; i++) {
        ans[i] += ans[i-1];
        cout << ans[i]-1 << " \n"[i == n];
    }

    return 0;
}