class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;

        for(auto it:moves){
            if(it == 'U')y++;
            if(it == 'D')y--;
            if(it == 'L')x--;
            if(it == 'R')x++;
        }
        return (x == 0) && (y==0);
    }
};