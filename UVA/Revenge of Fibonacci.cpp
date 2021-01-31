#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

void __init__ ()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct Node
{
    int id;
    Node* next[10];
    Node ()
    {
        id = -1;
        for (int i = 0; i < 10; i++) next[i] = NULL;
    }
};

const int maxn = 40 + 5, maxnn = 1e5;
Node* const root = new Node();
char s[maxn], fib[maxn];
int F[2][maxnn];

void add_Node (char* s, int id)
{
    Node* p = root;
    int len = strlen(s);
    for (int i = 0; i < len && i < maxn; i++)
    {
        int v = s[i] - '0';
        if (!p->next[v]) p->next[v] = new Node();
        p = p->next[v];
        if (-1 == p->id) p->id = id;
    }
}

void init ()
{
    F[0][0] = F[1][0] = 1;
    add_Node((char*)"1", 0);
    int start = 0, end = 1;
    for (int i = 2; i < maxnn; i++)
    {
        int p = i % 2, q = (i + 1) % 2;
        for (int j = start; j < end; j++) F[p][j] += F[q][j];
        for (int j = start; j < end; j++)
            if (F[p][j] >= 10)
            {
                F[p][j] %= 10;
                F[p][j + 1]++;
            }
        if (F[p][end]) end++;
        if (end - start > maxn + 5) start++;
        int r = end - 1, cnt = 0;
        memset(fib, '\0', sizeof(fib));
        while(r >= 0 && cnt < maxn) fib[cnt++] = F[p][r--] + '0';
        add_Node(fib, i);
    }
}

int query (char* s)
{
    Node* p = root;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        p = p->next[s[i] - '0'];
        if (!p) return -1;
    }
    return p->id;
}

int main ()
{
    __init__();

    init();       
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> s;
        cout << "Case #" << i << ": " << query(s) << endl;
    }

    return 0;
}
