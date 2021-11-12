#include <iostream>
#include <string>

using namespace std;

string s = "3 1 2";

int main(void) {
    int T;
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        if (n & 1) {
            cout << s << " ";
            for (int i = 4; i < n; i += 2) {
                cout << i + 1 << " " << i << " ";
            }
            cout << endl;
        }
        else {
            for (int i = 1; i < n; i += 2) {
                cout  << i + 1 << " " << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}