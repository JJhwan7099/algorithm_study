#include <iostream>
#include <string>
using namespace std;
int graph[65][65];
string result = "";
void search(int N, int startX, int startY)
{
    if(N==1)
    {
        result += to_string(graph[startX][startY]);
        return;
    }else{
        int n = N;
        int color = graph[startX][startY];
        bool check = true;
        for(int i = startX; i <= startX + n - 1; i++)
        {
            for(int j = startY; j <=startY + n - 1; j++)
            {
                if(graph[i][j] != color)
                {
                    check = false;
                    break;
                }
            }            
            if(check == false)
            {
                break;
            }
        }
        if(check == false)
        {
            result += '(';
            for(int k = 0; k < 2; k++)
            {
                for(int kk = 0; kk < 2; kk++)
                {
                    
                    
                    search(n/2, startX + (n/2)*k, startY + (n/2)*kk);
                }
            }
            result += ')';
        }else{
            result += to_string(color);
        }
        return;
    }
}
int main()
{
    int N; cin >> N;
    for(int i = 1; i <= N; i++)
    {
        string line; cin >> line;
        for(int j = 0; j < line.length(); j++)
        {
            graph[i][j+1] = (int)(line[j]) - 48;
        }
    }
    search(N , 1 , 1);
    cout << result;
    return 0;
}