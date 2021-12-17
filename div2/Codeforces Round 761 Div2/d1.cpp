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

int arr[N];

void print(int a, int b, int c) {
    printf("? %d %d %d\n", a, b, c);
    cout.flush();
}
void print_ans(vector<int> &ans) {
    printf("! %d ", ans.size());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
    cout.flush();
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        int more_good = -1, more_bad = -1;
        int x;
        for (int i = 1; i <= n / 3; i++) {
            print(i * 3 - 2, 3 * i - 1, 3 * i);
            cin >> x;
            if (x == 1 && more_good == -1) more_good = i * 3 - 2;
            if (x == 0 && more_bad == -1) more_bad = i * 3 - 2;
        }
        int x2;
        print(more_good, more_good + 1, more_bad);
        cin >> x;
        print(more_good, more_good + 1, more_bad + 1);
        int good_people = -1, bad_people = -1;
        cin >> x2;
        if (x == 1 && x2 == 1) {
            good_people = more_good;
            print(more_bad, more_bad + 1, more_good);
            cin >> x;
            print(more_bad, more_bad + 1, more_good + 1);
            cin >> x2;
            if (x == 0 && x2 == 0) bad_people = more_bad;
            else bad_people = more_bad + 2;
        }
        else if (x != x2) good_people = more_good + 2, bad_people = more_bad + 2;
        else bad_people = more_bad, good_people = more_good + 2;
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (i == bad_people) {
                ans.push_back(bad_people);
            } else if (i != good_people) {
                print(good_people, bad_people, i);
                int x;
                cin >> x;
                if (x == 0) ans.push_back(i);
            }
        }
        print_ans(ans);
    }

    return 0;
}
