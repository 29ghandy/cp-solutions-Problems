#include <bits/stdc++.h>

#pragma GCC optimze("Ofast")

#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define el '\n'
#define ii pair<int,int>
using namespace std;

const int N = 1e5 + 50, LOG = 25, base = 100003, base2 = 100019, MOD = 1e9 + 7,P = 1234567891, C = 1234567899;


int pw[N], inv[N];
int pw2[N], inv2[N];


int add(int a, int b) {
    a = (a + MOD) % MOD;
    b = (b + MOD) % MOD;
    return (0ll + a + b) % MOD;
}

int mul(int a, int b) {
    a %= MOD;
    b %= MOD;
    return (1ll * a * b) % MOD;
}

int fastpower(int base, int power) {
    if (base == 1 || power == 0) return 1;
    int hp = fastpower(base, power / 2);
    hp = mul(hp, hp);
    if (power & 1) hp = mul(hp, base);
    return hp;
}


void pre() {
    pw[0] = inv[0] = pw2[0] = inv2[0] = 1;
    int inverseP = fastpower(P, MOD - 2), inverseC = fastpower(C, MOD - 2);
    for (int i = 1; i < N; i++) {
        pw[i] = mul(pw[i - 1], P);
        pw2[i] = mul(pw2[i - 1], C);
        inv[i] = mul(inv[i - 1], inverseP);
        inv2[i] = mul(inv2[i - 1], inverseC);
    }
}
ll pref[N],pref2[N];

int ans [N];
map<ii,int> mp[N];
void setAnswer(int Case) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);

    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        reverse(a[i].begin(), a[i].end());
        mx = max(mx, (int) a[i].size());
    }
    for (int i = 1; i <= mx  ; ++i) {
        mp[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            if (j) {
                ll x = pref[j];
                pref[j] = add(pref[j - 1], mul(a[i][j] - 'a' + 1, pw[j]));
                pref2[j] = add(pref2[j - 1], mul(a[i][j] - 'a' + 1, pw2[j]));

            } else {
                pref[j] = a[i][j] - 'a' + 1;
                pref2[j] = a[i][j] - 'a' + 1;
            }
            mp[j + 1][{pref[j],pref2[j]}]++;
        }
    }

    for (int i = 1; i <= mx; ++i) {
        ans [i] = 0;
        for (auto j: mp[i]) {
            ans[i] = max(ans[i], j.second);
        }
    }
    while (m--) {
        int l;
        cin >> l;
        cout << ans[l] << el;
    }

}

signed main()
{
    pre();
    IO
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; ++i)
        setAnswer(i);

    return 0;
}