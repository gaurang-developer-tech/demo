// implement simple traveling sales man problem
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;

    int c[4][4] = {
        {0,10,15,20},
        {10,0,35,25},
        {15,35,0,30},
        {20,25,30,0}
    };

    vector<int> v;
    for(int i=1;i<n;i++)
        v.push_back(i);

    int mn = INT_MAX;

    do {
        int sum = 0, k = 0;

        for(int i=0;i<v.size();i++){
            sum += c[k][v[i]];
            k = v[i];
        }

        sum += c[k][0];
        mn = min(mn, sum);

    } while(next_permutation(v.begin(), v.end()));

    cout << "Min cost: " << mn;
    return 0;
}
