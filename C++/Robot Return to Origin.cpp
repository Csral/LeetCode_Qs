class Solution {
public:
    bool judgeCircle(string moves) {
        
        int ctr = 0;
        int rtc = 0;

        // if (moves.length() % 2 != 0) return false;

        for (char x : moves) {

            switch(x) {
                case 'U':
                    rtc += 1;
                    break;

                case 'D':
                    rtc -= 1;
                    break;

                case 'R':

                    ctr += 1;
                    break;

                case 'L':

                    ctr -= 1;
                    break;

            }

        }

        return (ctr == 0 && rtc == 0);

    }
};
