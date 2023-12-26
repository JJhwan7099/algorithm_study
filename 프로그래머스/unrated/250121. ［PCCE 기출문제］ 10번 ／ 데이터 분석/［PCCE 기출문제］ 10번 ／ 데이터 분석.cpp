#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool ccmp(vector<int>&a, vector<int>&b){return a[0]<b[0];}
bool dcmp(vector<int>&a, vector<int>&b){return a[1]<b[1];}
bool mcmp(vector<int>&a, vector<int>&b){return a[2]<b[2];}
bool rcmp(vector<int>&a, vector<int>&b){return a[3]<b[3];}
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> v;
    for(auto&a:data)
    {
        vector<int> vv;
        if(ext=="code" && a[0]<val_ext) {for(int i=0;i<4;i++) vv.push_back(a[i]); v.push_back(vv);}
        else if(ext=="date" && a[1]<val_ext) {for(int i=0;i<4;i++) vv.push_back(a[i]); v.push_back(vv);}
        else if(ext=="maximum" && a[2]<val_ext) {for(int i=0;i<4;i++) vv.push_back(a[i]); v.push_back(vv);}
        else if(ext=="remain" && a[3]<val_ext) {for(int i=0;i<4;i++) vv.push_back(a[i]);v.push_back(vv);}
    }
    if(sort_by=="code") sort(v.begin(),v.end(),ccmp);
    else if(sort_by=="date") sort(v.begin(),v.end(),dcmp);
    else if(sort_by=="maximum") sort(v.begin(),v.end(),mcmp);
    else if(sort_by=="remain") sort(v.begin(),v.end(),rcmp);
    return v;
}