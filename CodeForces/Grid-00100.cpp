#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int INF = 0x3f3f3f3f;

void init ()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main ()
{

    init();

    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        if (k % n) cout << 2 << endl;
        else cout << 0 << endl;
        int a[n][n];
        memset(a, 0, sizeof(a));
        for (int i = 0; i < k % n; i++)
            for (int j = i; j <= i + k / n; j++)
                a[i][j % n] = 1;
        for (int i = k % n; i < n; i++)
            for (int j = i; j < i + k / n; j++)
                a[i][j % n] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << a[i][j];
            cout << endl;
        }
    }

    return 0;
}
