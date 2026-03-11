#include <iostream>

using namespace std;

int main() {
    int arr[9];
    for(int i=1; i<=8; i++) {
        cin >> arr[i];
    }
    
    for(int i=1; i<=8; i++) {
        if(arr[i]!=i) break;
        if(i==8) {
            cout << "ascending";
            return 0;
        }
    }
    
    for(int i=1; i<=8; i++) {
        if(arr[8-i+1]!=i) break;
        if(i==8) {
            cout << "descending";
            return 0;
        }
    }
    
    cout << "mixed";
}