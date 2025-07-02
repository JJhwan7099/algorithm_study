class Solution {
    
    fun makeCombs(n: Int, idx: Int, comb: ArrayList<Int>, combs: ArrayList<ArrayList<Int>>) {
        if(comb.size == 5) {
            combs.add(ArrayList(comb))
            return
        }
        for(i in idx..n) {
            comb.add(i)
            makeCombs(n,i+1,comb,combs)
            comb.removeLast()
        }
    }
    
    fun solution(n: Int, q: Array<IntArray>, ans: IntArray): Int {
        var answer: Int = 0
        var comb = arrayListOf<Int>()
        var combs = arrayListOf<ArrayList<Int>>()
        makeCombs(n,1,comb,combs)
        for(c in combs) {
            var m = hashMapOf<Int,Int>()
            for(num in c ) m[num]=1
            
            var b : Boolean = true
            for(i in q.indices) {
                var matchNum = ans[i]
                var matchCount = 0
                for(num in q[i]) {
                    if(m[num]==1) matchCount++
                }
                if(matchCount != matchNum) {
                    b = false
                    break
                }
            }
            if(b) answer++
        }
        
        return answer
    }
}