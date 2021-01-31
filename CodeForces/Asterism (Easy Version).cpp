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

vector<int> a;
set<int> st;

int main ()
{

    init();

    int n, p;
    cin >> n >> p;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int start = -1;
    for (int i = 0; i < n; i++) start = max(start, a[i] - i);
    for (int x = start; x < a[n - 1]; x++)
    {
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            int cnt = upper_bound(a.begin(), a.end(), x + i) - a.begin();
            cnt -= i;
            if (cnt % p == 0) 
            {
                ok = false;
                break;
            } 
        }
        if (ok) st.insert(x);
    }
    cout << st.size() << endl;
    for (const auto& e : st) cout << e << " ";

    return 0;
}
