#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int n = rand() % 100 + 1, g = 0, c = 0;
    
    cout << "Guess (1-100):\n";
    while (g != n) {
        cin >> g;
        c++;
        if (g < n) cout << "Higher\n";
        else if (g > n) cout << "Lower\n";
    }
    cout << "Won in " << c << " tries!\n";
    
    return 0;
}