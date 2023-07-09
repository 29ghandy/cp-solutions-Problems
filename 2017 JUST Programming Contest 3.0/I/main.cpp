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
    int n,s,e;
    cin >> n >> s >> e;
    vector<string>a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> dis(n + 1 ,1e9);
    vector<vector<int>> g(n + 1);
    vector<unordered_map<char,int>> mp(n + 1);
    for (int i = 1; i <= n ; ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            mp[i][a[i][j]]++;
        }
    }
    for (int i = 1; i <= n ; ++i) {
        for (int j = i + 1; j <= n ; ++j) {
            int common = 0;
            for(char  k  = '0'; k <= '9';k++) common += min(mp[i][k],mp[j][k]);
            if(common == 17) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    queue<int>q;
    q.push(s);
    dis[s] = 0;
    while (!q.empty())
    {
        int  cur = q.front();
        q.pop();
        if(cur == e) {
            cout << dis[e] << el;
            return;
        }
        for(auto i : g[cur]) {
            if(dis[i] > dis[cur] + 1) {
                dis[i] = dis[cur] + 1;
                q.push(i);
            }
        }
    }
    cout << "-1\n";
}


signed main() {
    IO
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; ++i)
        setAnswer(i);

    return 0;
}