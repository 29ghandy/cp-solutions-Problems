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
    double y,x;
    cin >> y >> x;
    double ADD = 1.0 + (x / 100.0) ;

    cout << fixed << setprecision(0)<< (y / ADD) << el;
}


signed main() {
    IO
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; ++i)
        setAnswer(i);

    return 0;
}