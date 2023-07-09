#include <bits/stdc++.h>

#pragma GCC optimze("Ofast")

#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define el '\n'
#define ii pair<int,int>
using namespace std;

const int N = 2e3 + 50, LOG = 25;


void setAnswer(int Case) {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    map<int,int>rows,cols;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        rows[a[i].first]++;
        cols[a[i].second]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(cols.count(a[i].first)) {
            ans += cols[a[i].first];
        }
    }
    for (int i = 0; i < n; ++i) {
        if(rows.count(a[i].second)) {
            ans += rows[a[i].second];
        }
    }
    cout << ans / 2 << el;

}


signed main() {
    IO
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; ++i)
        setAnswer(i);

    return 0;
}