#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int cnt=1;
    while(cnt++)
    {
        if(n%cnt==1)
        {
            answer = cnt;
            break;
        }
    }
    return answer;
}