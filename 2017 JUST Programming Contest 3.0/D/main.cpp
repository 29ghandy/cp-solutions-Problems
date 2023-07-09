#include <bits/stdc++.h>

#pragma GCC optimze("Ofast")

#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define el '\n'
#define ii pair<int,int>
using namespace std;

const int N = 2e4 + 50, LOG = 25;

int dis[N];
struct node {
    int top,sum;
    node (int x,int y) {
        this->sum = y;
        this->top = x;
    }
};
void bfs() {
    ::memset(dis,-1,sizeof dis);
    queue<node>q;
    q.push(node(1,0));
    dis[0] = 0;
    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        for (int i = 1; i <= 6 ; ++i) {
            if(i == cur.top or i + cur.top == 7) continue;
            if(!~dis[cur.sum + i]) {
                dis[cur.sum + i] = dis[cur.sum] + 1;
                q.push(node(i,cur.sum + i));
            }
        }
    }

}
void setAnswer(int Case) {
    int n;
    cin >> n;
    cout << dis[n] << el;
}


signed main() {
    IO
    bfs();
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; ++i)
        setAnswer(i);

    return 0;
}