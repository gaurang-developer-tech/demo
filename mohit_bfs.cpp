#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void b(int s, vector<vector<int>>& g, vector<bool>& v) {
    queue<int> q;
    q.push(s);
    v[s] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int i : g[u]) {
            if(!v[i]) {
                v[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    int n, m, x, y, s;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<bool> v(n, 0);
    while(m--) { cin >> x >> y; g[x].push_back(y); g[y].push_back(x); }
    cin >> s;
    b(s, g, v);
}   