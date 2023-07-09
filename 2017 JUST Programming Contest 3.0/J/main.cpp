#include <bits/stdc++.h>

#pragma GCC optimze("Ofast")

#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define el '\n'
#define ii pair<int,int>
using namespace std;

const int N = 2e3 + 50, LOG = 25;

ll dp[N][N], vis[N][N], id, pre[N], suff[N], n, a[N];

ll solve(int l, int r) {
    if (l == r)
        return a[l];
    ll &ans = dp[l][r];
    if (vis[l][r] == id)
        return ans;
    vis[l][r] = id;
    ll sum = pre[r] - pre[l - 1];
    ll op1 = sum - solve(l + 1, r);
    ll op3 = sum - solve(l, r - 1);

    ans = max({op1, op3});
    return ans;
}

void setAnswer(int Case) {
    cin >> n;
    for (int i = 1, x; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    id++;
    cout << solve(1, n) - (pre[n] - solve(1,n)) << el;
}


signed main() {
    IO
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; ++i)
        setAnswer(i);

    return 0;
}