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
    int beds = 0,kithcens = 0,living = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if(s[0] == 'b') beds++;
        else if(s[0] == 'l') living++;
        else kithcens++;
    }
    int ans = 0;
    while (beds - 2 >= 0 and living > 0 and kithcens > 0) {
        ans ++;
        beds -= 2;
        living--;
        kithcens--;
    }
    cout << ans << el;
}


signed main() {
    IO
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; ++i)
        setAnswer(i);

    return 0;
}