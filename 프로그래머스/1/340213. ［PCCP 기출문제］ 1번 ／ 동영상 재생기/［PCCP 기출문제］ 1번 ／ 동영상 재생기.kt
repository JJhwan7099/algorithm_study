class Solution {
    fun solution(video_len: String, pos: String, op_start: String, op_end: String, commands: Array<String>): String {
        var answer: String = ""
        var totalLen = video_len.split(":")[0].toInt()*60+video_len.split(":")[1].toInt()
        var position = pos.split(":")[0].toInt()*60+pos.split(":")[1].toInt()
        var opStart = op_start.split(":")[0].toInt()*60+op_start.split(":")[1].toInt()
        var opEnd = op_end.split(":")[0].toInt()*60+op_end.split(":")[1].toInt()
        if(opStart <= position && position <= opEnd) position = opEnd
        for(cmd in commands) {
            if(cmd == "next") {
                position += 10
                if(position > totalLen) position = totalLen
            }
            else if(cmd == "prev") {
                position -= 10
                if(position < 0) position = 0
            }
            if(opStart <= position && position <= opEnd) position = opEnd
        }
        var minute : String = (position/60).toString()
        if(minute.length==1) minute = "0"+minute
        
        var second : String = (position%60).toString()
        if(second.length==1) second = "0"+second
        
        answer = minute + ":" + second

        return answer
    }
}