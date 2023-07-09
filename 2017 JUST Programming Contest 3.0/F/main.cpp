#include <bits/stdc++.h>

#pragma GCC optimze("Ofast")

#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define el '\n'
#define ii pair<int,int>
using namespace std;

const int N = 2e3 + 50, LOG = 25;

ll ctr = 1e9;

void setAnswer(int Case) {
    int n,q;
    cin >> n >> q;
    vector<ll> pre(n + 1,0);
    for (int i = 1; i <= n ; ++i) {
        ll x;
        cin >> x;
        ctr = 0;
        while (x > 1) {
            if(x % 2) x--;
            else x /= 2;
            ctr++;
        }
        pre[i] = ctr;
    }
    for (int i = 1; i <= n ; ++i) {
        pre[i] += pre[i - 1];
    }
    while (q--) {
        int l,r;
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << el;
    }
}


signed main() {
    IO
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; ++i)
        setAnswer(i);

    return 0;
}