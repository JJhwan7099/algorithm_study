#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=0;i<N;i++)
string solution(string new_id) {
    string answer = "";
    //1단계
    FOR(i,new_id.length())
    {
        if(isupper(new_id[i])) new_id[i] = new_id[i]+32;
    }
    //2단계
    string b = "";
    FOR(i,new_id.length())
    {
        char a = new_id[i];
        if(islower(a)||isdigit(a)||a=='-'||a=='_'||a=='.')b+=a;
    }
    new_id = b;
    //3단계
    string a = "";
    FOR(i,new_id.length())
    {
        char b = new_id[i];
        if(b=='.'&&new_id[i-1]=='.') continue;
        else a+=b;
    }
    new_id=a;
    //4단계-1 처음 . 제거
    a = "";
    bool check = true;
    FOR(i,new_id.length())
    {
        if(check && new_id[i]=='.') continue;
        else if(!check) a+=new_id[i];
        else if(check && new_id[i]!='.')
        {
            check = false;
            a+=new_id[i];
        }
    }
    new_id=a;
    //4단계-2 끝 . 제거
    a = "";
    for(int i=new_id.length()-1;i>=0;i--)
    {
        if(new_id[i]=='.') continue;
        else
        {
            for(int j=0; j<=i; j++)
            {
                a+=new_id[j];
            }
            break;
        }
    }
    new_id=a;
    //5단계
    if(new_id.length()==0) new_id = "a";
    //6단계
    if(new_id.length()>15)
    {
        a="";
        FOR(i,15) a+=new_id[i];
        new_id = a;
    }
    a = "";
    for(int i=new_id.length()-1;i>=0;i--)
    {
        if(new_id[i]=='.') continue;
        else
        {
            for(int j=0; j<=i; j++)
            {
                a+=new_id[j];
            }
            break;
        }
    }
    new_id = a;
    //7단계
    while(new_id.length()<3)
    {
        new_id+=new_id[new_id.length()-1];
    }
    cout << new_id;
    return new_id;
}