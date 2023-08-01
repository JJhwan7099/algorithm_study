#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void Count(int a,int b,vector<string> board)
{
    int count = 0;
    vector<int> minini;
    for(int i = 0; i < b-7; i++)//B시작
    {
        
        for(int j = 0; j < a-7; j++)//j가 세로
        {
            int linec = 1;
            for(int x = j; x < j + 8; x++ )
            {
                //B시작
                if(linec%2 == 1)//홀수번째줄일때
                {
                    for(int y = 0; y <4 ; y++)
                    {
                        if(board[x+1][i+(y*2)]=='W')
                        {
                            count++;
                        }
                        if(board[x+1][i+(y*2+1)]=='B')
                        {
                            count++;
                        }
                    }
                    linec++;
                }else{//짝수번째줄일때
                    for(int y = 0; y < 4 ; y++)
                    {
                        if(board[x+1][i+(y*2)]=='B')
                        {
                            count++;
                        }
                        if(board[x+1][i+(y*2+1)]=='W')
                        {
                            count++;
                        }
                    }
                    linec++;
                }
            }
            minini.push_back(count);
            count = 0;
            linec = 1;
            for(int x = j; x < j + 8; x++ )
            {
                if(linec%2 == 1)//홀수번째줄일때
                {
                    for(int y = 0; y < 4 ; y++)
                    {
                        if(board[x+1][i+(y*2)]=='B')
                        {
                            count++;
                        }
                        if(board[x+1][i+(y*2+1)]=='W')
                        {
                            count++;
                        }
                    }
                    linec++;
                }else{//짝수번째줄일때
                    for(int y = 0; y < 4 ; y++)
                    {
                        if(board[x+1][i+(y*2)]=='W')
                        {
                            count++;
                        }
                        if(board[x+1][i+(y*2+1)]=='B')
                        {
                            count++;
                        }
                    }
                    linec++;
                }
            }
            minini.push_back(count);
            count = 0;                
            
        }
    }
    int min = min_element(minini.begin(), minini.end()) - minini.begin();
    cout<< minini[min] << '\n';

}
int main()
{
    int a, b;
    cin >> a;
    cin >> b;

    vector<string> board;
    for(int i = 0; i < a + 1; i++)
    {
        string line; getline(cin, line); 
        board.push_back(line);
    }
    Count(a,b,board);
    
    return 0;
    
}