#include <iostream>
#include <algorithm>
using namespace std;

char b[10] = "012345678"; // 0-8 for positions

int w() {
    int p[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for(auto& r:p) if(b[r[0]]==b[r[1]] && b[r[1]]==b[r[2]]) return b[r[0]]=='O'?1:-1;
    return 0;
}

int m(bool a) {
    int s=w(), r=a?-2:2;
    if(s) return s;
    bool f=0;
    for(int i=0; i<9; i++) if(b[i]<'A') {
        f=1; char t=b[i]; b[i]=a?'O':'X';
        int v=m(!a); b[i]=t;
        r=a?max(r,v):min(r,v);
    }
    return f?r:0;
}

int main() {
    int p, i;
    for(i=0; i<9 && !w(); i++) {
        if(i%2==0) { 
            for(int j=0; j<9; j++) cout<<b[j]<<(j%3==2?"\n":" ");
            cin>>p; b[p]='X';
        } else {
            int bv=-2, bk;
            for(int j=0; j<9; j++) if(b[j]<'A') {
                char t=b[j]; b[j]='O'; int v=m(0); b[j]=t;
                if(v>bv) { bv=v; bk=j; }
            }
            b[bk]='O';
        }
    }
    for(int j=0; j<9; j++) cout<<b[j]<<(j%3==2?"\n":" ");
    cout<<(w()==1?"AI wins":(w()==-1?"You win":"Draw"));
}