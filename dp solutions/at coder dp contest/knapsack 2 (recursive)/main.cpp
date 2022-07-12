#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define el endl
#define ull unsigned long long
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int mod = 1e9+7;
const int N = 1e2 + 1,M = 1e5 + 5;

using namespace std;
int n,weights[N],values[N],dp[N][M],maxCapacity;
int solve(int i ,int sumValues) {
    if(i == n)
        return (sumValues <= 0 ? 0 : 1e9 );

    if(dp[i][sumValues] != -1)
        return dp[i][sumValues];

    int ans = solve(i + 1,sumValues);
    if(values[i] <= sumValues)
        ans = min(ans, solve(i + 1,sumValues - values[i]) + weights[i]);
    return dp[i][sumValues] = ans;
}
int main() {
    fio
    int sum = 0;
    memset(dp,-1,sizeof dp);
    cin >> n >> maxCapacity;
    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
        sum += values[i];
    }
    for (int curSum = sum; curSum >= 0 ; --curSum) {
        if(solve(0,curSum) <= maxCapacity) {
            cout << curSum << el;
            break;
        }
    }
    return 0;
}