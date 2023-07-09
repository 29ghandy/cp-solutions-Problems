#include <bits/stdc++.h>

#pragma GCC optimze("Ofast")

#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define el '\n'
#define ii pair<int,int>
using namespace std;

const int N = 1e5 + 50, LOG = 25;
ll n, x, s, k, m;

ll firstCase(vector<ii > &ab, vector<ii > &cd) {
    int ans = 0;
    for (auto i: cd) {
        if (s >= i.second) {
            n -= i.first;
            s -= i.second;
            break;
        }
    }
    for (auto i: ab) {
        if (s >= i.second and i.first < x) {
            x = i.first;
            break;

        }
    }
    return (x * n * 1ll);
}

ll secondCase(vector<ii > &ab, vector<ii > &cd) {
    for (auto i: ab) {
        if (s >= i.second and i.first < x) {
            x = i.first;
            s -= i.second;
            break;
        }
    }

    for (auto i: cd) {
        if (s >= i.second) {
            n -= i.first;
            s -= i.second;
            break;
        }
    }
    return (x * n * 1ll);
}

void setAnswer(int Case) {
    cin >> n >> m >> k >> x >> s;
    vector<ii > ab(m);
    vector<ii > cd(k);
    for (auto &i: ab) cin >> i.first;
    for (auto &i: ab) cin >> i.second;
    for (auto &i: cd) cin >> i.first;
    for (auto &i: cd) cin >> i.second;
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end(), greater<>());
    ll n1 = n, s1 = s;
    ll a1 = firstCase(ab, cd);
    n = n1, s = s1;
    ll a2 = secondCase(ab, cd);
    cout << min(a1, a2) << el;
}

signed main() {
    IO
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; ++i)
        setAnswer(i);

    return 0;
}