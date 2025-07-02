#include <string>
#include <vector>

using namespace std;

bool check(pair<int,int> walletSize, pair<int,int> billSize) {
    if(walletSize.first >= billSize.first && walletSize.second >= billSize.second)
        return true;
    else if(walletSize.second >= billSize.first && walletSize.first >= billSize.second)
        return true;
    
    return false;
}

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    while(!check({wallet[0],wallet[1]},{bill[0],bill[1]})){
        if(bill[0] > bill[1]) {
            bill[0] /= 2;
        }
        else bill[1] /=2;
        answer++;
    }
    return answer;
}