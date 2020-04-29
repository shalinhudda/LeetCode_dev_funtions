class Solution {
public:
    int numberOfSteps (int num) {
        int index = 0;
        while(num != 0) {
            if(num % 2 == 0) {
                num = num / 2;
                index++;
            }
            else {
                num = num - 1;
                index++;
            }
        }
    return index;
    }
};