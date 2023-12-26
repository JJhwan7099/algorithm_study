#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> numbers) {
    int sum=0;
    map<int,int> m;
    for(auto&a :numbers)
    {
        m[a]=1;
    }
    for(int i=1;i<=9; i++)
    {
        if(m[i]!=1)sum+=i;
    }
    return sum;
}