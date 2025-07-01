class Solution {
    fun solution(n: Int, w: Int, num: Int): Int {
        var answer: Int = 1
        
        answer += (n-1)/w - (num-1)/w
        
        var index: Int
        if(((num-1)/w)%2==0) {
            index = (num-1)%w
        } else {
            index = (w-1)-(num-1)%w
        }
        println(index)
        var detail: Int
        if(((n-1)/w)%2==0) {
            detail = (n-1)%w
        } else {
            detail = (w-1)-(n-1)%w
        }
        
        if(((n-1)/w)%2==0) {
            if(index > detail) answer -= 1
        } else {
            if(index < detail) answer -= 1
        }
        
        println("$index $detail")
        
        return answer
    }
}