#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;
int main()
{
    int a;
    int b;
    cin >> a;
    cin >> b;
    
    int ans = 0;
    
    unordered_set<string> abc;
    
    for(int i = 0; i < a; i++){
        string a;
        cin >> a;
        abc.insert(a);
    }
    for(int i = 0; i < b; i++){
        string a;
        cin >> a;
        if(abc.count(a) > 0){
            ans++;
        }
    }
    cout << ans;
    
    return 0;
}