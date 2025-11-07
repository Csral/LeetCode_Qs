class Solution:
    def judgeCircle(self, moves: str) -> bool:
        
        ctr = 0
        rtc = 0
        # if len(moves) % 2 != 0:
        #     return False

        for x in moves:
            if x == 'U':
                ctr += 1
            elif x == 'R':
                rtc += 1
            elif x == 'D':
                ctr -= 1
            else:
                rtc -= 1

        return (ctr == 0 and rtc == 0)
