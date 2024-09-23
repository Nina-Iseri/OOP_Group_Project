#include <iostream>
using namespace std;

int main() {
    int n = 2;
    cin >> n;
    while (n < -1 || n > 5) {
        cout << "Dame\n";
        cin >> n;
    }
    return 0;
}