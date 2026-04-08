#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 1e9;
vector<vector<int>> c = {
    {0, 12, 10, 19, 8, 14},
    {11, 0, 7, 6, 12, 9},
    {9, 8, 0, 14, 10, 6},
    {18, 5, 13, 0, INF, 11},
    {7, 11, 9, 15, 0, 8},
    {13, 10, 6, 12, 9, 0}
};
vector<vector<int>> dp(64, vector<int>(6, -1));

int t(int m, int u) {
    if(m == 63) return c[u][0];
    if(dp[m][u] != -1) return dp[m][u];
    int a = INF;
    for(int v = 0; v < 6; v++) {
        if(!(m & (1 << v)) && c[u][v] != INF) {
            a = min(a, c[u][v] + t(m | (1 << v), v));
        }
    }
    return dp[m][u] = a;
}

int main() {
    cout << t(1, 0) << "\n";
    return 0;
}