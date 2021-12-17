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
        vector<int> temp;
        int x;
        for (int i = 1; i <= n / 3; i++) {
            print(i * 3 - 2, 3 * i - 1, 3 * i);
            cin >> x;
            if (x == 1 && more_good == -1) more_good = i * 3 - 2;
            if (x == 0 && more_bad == -1) more_bad = i * 3 - 2;
            temp.push_back(x);
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
        int res1, res2;
        for (int i = 1; i <= n / 3; i++) {
            if (i != more_good / 3 + 1 && i != more_bad / 3 + 1) {
                int x = i * 3 - 2, y = i * 3 - 1, z = i * 3;
                if (temp[i - 1] == 0) {
                    print(x, y, good_people);
                    cin >> res1;
                    print(y, z, good_people);
                    cin >> res2;
                    if (res1 == 0 && res2 == 0) ans.push_back(x), ans.push_back(y), ans.push_back(z);
                    else if (res1 == 0 && res2 == 1) ans.push_back(x), ans.push_back(y);
                    else if (res1 == 1 && res2 == 0) ans.push_back(y), ans.push_back(z);
                    else ans.push_back(x), ans.push_back(z);
                } else {
                    print(x, y, bad_people);
                    cin >> res1;
                    print(y, z, bad_people);
                    cin >> res2;
                    if (res1 == 0 && res2 == 1) ans.push_back(x);
                    else if (res1 == 1 && res2 == 0) ans.push_back(z);
                    else if (res1 == 0 && res2 == 0) ans.push_back(y);
                }
            }
        }
        for (int i = more_good; i <= more_good + 2; i++) {
            int x;
            if (i != good_people) {
                print(good_people, bad_people, i);
                cin >> x;
                if (x == 0) ans.push_back(i);
            }
        }
        for (int i = more_bad; i <= more_bad + 2; i++) {
            int x;
            if (i != bad_people) {
                print(good_people, bad_people, i);
                cin >> x;
                if (x == 0) ans.push_back(i);
            }
        }
        ans.push_back(bad_people);
        print_ans(ans);
    }

    return 0;
}
