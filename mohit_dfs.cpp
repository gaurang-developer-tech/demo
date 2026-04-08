#include<iostream>
#include<vector>
using namespace std;

void d(int u, vector<vector<int>>& g, vector<bool>& v) {
    v[u]=1; cout<<u<<" ";
    for(int i:g[u]) if(!v[i]) d(i,g,v);
}

int main() {
    int n,m,x,y,s;
    cin>>n>>m;
    vector<vector<int>> g(n);
    vector<bool> v(n,0);
    while(m--) { cin>>x>>y; g[x].push_back(y); g[y].push_back(x); }
    cin>>s;
    d(s,g,v);
}