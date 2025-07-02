class Solution {
    
    var dx = listOf(1,-1,0,0)
    var dy = listOf(0,0,1,-1)
    var visit : Array<Array<Int>> = Array(52){Array(52){0}}
    
    fun getSide(x: Int, y: Int, board: Array<Array<Char>>, tg : Char) {
        visit[x][y] = 1
        board[x][y] = '.'
        for(i in 0..3) {
            var X = x + dx[i]
            var Y = y + dy[i]
            if(X<0 || Y<0 || X>=board.size || Y>=board[0].size) continue
            else if(visit[X][Y]==0) {
                
                if(board[X][Y]=='.') {
                    getSide(X,Y,board,tg)
                }
                else if(board[X][Y]==tg) {
                    board[X][Y]='.'
                    visit[X][Y]=1
                }
            }
        }
    }
    
    fun getCrain(board: Array<Array<Char>>, tg : Char) {
        for(i in board.indices) {
            for(j in board[i].indices) {
                if(board[i][j]==tg) board[i][j]='.'
            }
        }
    }
    
    fun solution(storage: Array<String>, requests: Array<String>): Int {
        var answer: Int = 0
        
        var N: Int = storage.size
        var M: Int = storage[0].length
        
        val board: Array<Array<Char>> = Array(N + 2) { Array(M + 2) { '.' } }
        
        for(i in 1..N) {
            for(j in 1..M) {
                board[i][j] = storage[i-1][j-1]
            }
        }
        
        for(request in requests) {
            if(request.length==1) {
                for(i in 0..N+1) for(j in 0..M+1) visit[i][j] = 0
                getSide(0,0,board,request[0])
            }
            else if(request.length==2) {
                getCrain(board,request[0])
            }
        }
        
        for(line in board) {
            for(c in line) {
                if(c!='.') answer++
            }
        }
        return answer
    }
}