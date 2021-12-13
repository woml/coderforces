#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 5e5 + 10;

int arr[N];
PII a[N];

int q[N], tmp[N];
long long int ans;

void merge_sort(int q[], int l, int r) {
    if (l >= r) return;
    
    int mid = l + r >> 1;
    merge_sort(q, l, mid); merge_sort(q, mid + 1, r);
    
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else {
            ans += mid - i + 1;
            tmp[k++] = q[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = q[i++];
    }
    while (j <= r) tmp[k++] = q[j++];
    
    for (i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}

int main(void) {
    int T;
    scanf("%d", &T);
    while (T -- ) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &q[i]);
        }
        ans = 0;
        bool flag = false, t = true;
        for (int i = 0; i < n - 1; i++) {
            if (q[i] > q[i + 1]) {
                t = false;
                break;
            }
        }
        if (t) flag = true;
        for (int i = 0; i < n - 1; i++) {
            if (q[i] < q[i + 1]) {
                t = false;
                break;
            }
        }
        if (t) flag = true;
        if (flag) printf("YES\n");
        else {
            merge_sort(q, 0, n - 1);
            if (ans & 1) printf("NO\n");
            else printf("YES\n");
        }
    }

    return 0;
}
