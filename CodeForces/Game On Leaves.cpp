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
        int n, x;
        cin >> n >> x;
        int degree = 0;
        for (int i  = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            if (u == x || v == x) degree++;
        }
        if (1 == degree || !degree) cout << "Ayush" << endl;
        else 
        {
            if ((n - 1) & 1) cout << "Ayush" << endl;
            else cout << "Ashish" << endl;
        }
    }

    return 0;
}

