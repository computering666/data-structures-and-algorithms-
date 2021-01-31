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

vector<int> sum;

int main ()
{

    init();

    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        int n = s.length();
        sum.resize(n + 1);
        for (int i = 0; i < n; i++)
            sum[i + 1] = sum[i] + s[i] - '0';
        int ans = n;
        for (int i = 0; i <= n; i++)
            ans = min({ans, sum[i] + n - i - (sum[n] - sum[i]), i - sum[i] + sum[n] - sum[i]});
        cout << ans << endl;
    }

    return 0;
}
