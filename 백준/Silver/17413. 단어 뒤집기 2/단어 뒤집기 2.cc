#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int i = 0;
string tag(string a)
{
    string b = "";
    while(true)
    {
        
        b += a[i];
        if(a[i] == '>')
        {
            return b;
            break;
        }
        i++;
    }
}

int main()
{
    string a; getline(cin, a);
    vector<string> vt;
    string b = "";
    for(i = 0; i < a.length(); i++)
    {
        if(a[i] == '<'){
            if(b != "")
            {
                string abc = "";
                for(int j = 0 ; j < b.length(); j++){
                    abc += b[b.length() - 1 - j];
                }
                vt.push_back(abc);
            }
            b = tag(a);
            vt.push_back(b);
            b = "";
            continue;
        }else if(a[i] == ' ')
        {
            string abc = "";
            for(int j = 0 ; j < b.length(); j++){
                abc += b[b.length() - 1 - j];
            }
            //sort(b.begin(),b.end());
            vt.push_back(abc);
            vt.push_back(" ");
            b = "";
            continue;
        }else if(i == a.length()-1)
        {
            b+=a[i];
            string abc = "";
            for(int j = 0 ; j < b.length(); j++){
                abc += b[b.length() - 1 - j];
            }
            vt.push_back(abc);
            b = "";
        }else
        {
            b += a[i];
        }
    }

    for(int j = 0; j < vt.size(); j++){
        cout << vt[j];
    }

    return 0;
}