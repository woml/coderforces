for (int i = 0; i <= 3; i++) {
            for (int j = (1 << i); j < 1 << (i + 1); j++) {
                cout << tree[j] << " ";
            }
            cout << endl;
        }