class Solution {
    fun solution(schedules: IntArray, timelogs: Array<IntArray>, startday: Int): Int {
        var answer: Int = 0
        for(i in schedules.indices) {
            var due = schedules[i]+10
            if(due%100>59) {
                due = due+100-(due%100)+(due%100-59)
            }
            var day = startday
            var good: Boolean = true
            for(time in timelogs[i]) {
                if(!(day==6 || day==7)) {
                    if(time > due) {
                        good = false
                    }
                }
                day++
                day = (day-1)%7+1
            }
            if(good) answer++
        }
        return answer
    }
}