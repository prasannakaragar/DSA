#include <iostream>
using namespace std;

int main() {
    int height = 5;   // Height of tree

    // Tree leaves
    for (int i = 1; i <= height; i++) {
        // Print spaces
        for (int j = i; j < height; j++) {
            cout << " ";
        }
        // Print stars
        for (int k = 1; k <= (2 * i - 1); k++) {
            cout << "*";
        }
        cout << endl;
    }

    // Tree trunk
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < height - 1; j++) {
            cout << " ";
        }
        cout << "|" << endl;
    }

    return 0;
}
