#include <iostream>
using namespace std;

char b[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void draw() {
    cout << "\n";
    for(int i=0; i<3; i++) cout << " " << b[i][0] << " | " << b[i][1] << " | " << b[i][2] << "\n";
    cout << "\n";
}

bool win() {
    for(int i=0; i<3; i++) {
        // Check rows and columns
        if(b[i][0]==b[i][1] && b[i][1]==b[i][2]) return 1;
        if(b[0][i]==b[1][i] && b[1][i]==b[2][i]) return 1;
    }
    // Check diagonals
    if(b[0][0]==b[1][1] && b[1][1]==b[2][2]) return 1;
    if(b[0][2]==b[1][1] && b[1][1]==b[2][0]) return 1;
    return 0;
}

int main() {
    int c, t = 0; 
    char p = 'X';
    
    while(t < 9) {
        draw();
        cout << "Player " << p << ", enter a number (1-9): "; 
        cin >> c;
        
        int r = (c-1)/3, col = (c-1)%3;
        
        // Validate move
        if(c < 1 || c > 9 || b[r][col] == 'X' || b[r][col] == 'O') {
            cout << "Invalid move! Try again.\n"; 
            continue;
        }
        
        b[r][col] = p; // Place marker
        
        if(win()) { 
            draw(); 
            cout << "Player " << p << " wins!\n"; 
            return 0; 
        }
        
        p = (p == 'X') ? 'O' : 'X'; // Swap player
        t++;
    }
    draw(); 
    cout << "It's a draw!\n";
}