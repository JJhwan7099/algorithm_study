#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char,int> m;
    string ty="";
    string tm="";
    string td="";
        for(int i=0; i<today.length();i++)
        {
            if(i<4) ty+=today[i];
            else if(i>4&&i<7) tm+=today[i];
            else if(i>7&&i<10) td+=today[i];
        }
    for(auto&a:terms)
    {
        char alpha = a[0];
        string term = "";
        for(int i=2;i<a.length();i++) term+=a[i];
        m[alpha] = stoi(term);
    }
    int cnt=0;
    for(auto&a :privacies)
    {
        cnt++;
        string year="";
        string month="";
        string day="";
        char term;
        for(int i=0;i<a.length();i++)
        {
            if(i<4) year+=a[i];
            else if(i>4&&i<7) month+=a[i];
            else if(i>7&&i<10) day+=a[i];
            else if(i==a.length()-1) term = a[i];
        }
        int yy,mm,dd;
        yy = stoi(year)+(m[term]/12);
        mm = stoi(month)+(m[term]%12);
        if(mm>12){mm-=12; yy++;}
        dd = stoi(day);
        cout << yy << "." << mm << "." << dd << endl;
        if(yy<stoi(ty)) answer.push_back(cnt);
        else if(yy==stoi(ty)&&mm<stoi(tm)) answer.push_back(cnt);
        else if(yy==stoi(ty)&&mm==stoi(tm)&&dd<=stoi(td)) answer.push_back(cnt);
    }
    return answer;
}