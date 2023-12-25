#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    stack<int> s;
    stack<int> ss;
    for(int j=0; j<arr1.size(); j++)
    {
        
        for(int i=0;i<n;i++)
        {
            if(arr1[j]!=0)
            {
                s.push(arr1[j]%2);
                arr1[j]/=2;
            }else s.push(0);
            if(arr2[j]!=0)
            {
                ss.push(arr2[j]%2);
                arr2[j]/=2;
            }else ss.push(0);
        }
        string a = "";
        for(int i=0;i<n;i++)
        {
            if(s.top()==1) a+='#';
            else a+=' ';
            s.pop();
        }
        answer.push_back(a);
        for(int i=0;i<n;i++)
        {
            if(ss.top()==1) answer[j][i]='#';
            ss.pop();
        }
    }
    return answer;
}