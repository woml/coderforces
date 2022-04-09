#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int arr[N];

bool check(int mid, vector<PII>& has_bro, int m) {

}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        priority_queue<PII> heap;
        unordered_map<int, int> mapping;
        vector<int> cnt(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            scanf("%d", &arr[i]);
            if (mapping[arr[i]] == 0) {
                mapping[arr[i]] = i;
            } else {
                cnt[i] = -1;
            }
            cnt[mapping[arr[i]]]++;
        }
        vector<PII> has_bro;
        vector<int> st(n + 1);
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 0) {
                has_bro.push_back({1, i});
            } else if (cnt[i] != -1) {
                has_bro.push_back({cnt[i], i});
            }
        }
        sort(has_bro.begin(), has_bro.end(), [](PII &a, PII &b){
            return a.first > b.first;
        });
        int m = has_bro.size();
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid, has_bro, m)) r = mid;
            else l = mid + 1;
        }
        
        cout << l << endl;
    }

    return 0;
}

       // while (heap.size()) {
        //     auto t = heap.top(); heap.pop();
        //     int rank = t.second, num = t.first;
        //     cout << rank << " " << num << " " << " ans = " << time << endl;
        //     bool find = false;
        //     while (!find && heap.size()) {
        //         if (!st[rank]) {
        //             st[rank] = time;
        //             num--;
        //             if (num > 0) {
        //                 heap.push({num, rank});
        //             }
        //             find = true;
        //         } else {
        //             num -= time - st[rank];
        //             st[rank] = time;
        //             if (num > 1) {
        //                 heap.push({num - 1, rank});
        //                 find = true;
        //             } else {
        //                 t = heap.top(); heap.pop();
        //                 rank = t.second;
        //                 num = t.first;
        //                 cout << rank << " " << num << " " << " ans = " << time << endl;
        //             }
        //         }
        //     }
            // time++;
        // }