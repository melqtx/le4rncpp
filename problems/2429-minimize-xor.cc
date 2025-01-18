class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bits_in_num1 = __builtin_popcount(num1);
        int bits_in_num2 = __builtin_popcount(num2);
        int result = num1;
        for (int i = 0; i < 32; ++i) {
            if (bits_in_num1 > bits_in_num2 && (1 << i) & num1) {
                result ^= 1 << i;
                bits_in_num1--;
            }
            if (bits_in_num1 < bits_in_num2 && !((1 << i) & num1)) {
                result ^= 1 << i;
                bits_in_num1++;
            }
        }
        return result;
    }
};

/*
 num1 = 7 (111 in binary)
num2 = 1 (001 in binary)

bits_in_num1 = 3  // 7 has three 1s
bits_in_num2 = 1  // 1 has one 1

Need to remove two 1s from num1

Loop through bits:
i = 0: See 1, remove it (using ^=): 110
i = 1: See 1, remove it: 100
i = 2: Done because we now have one 1

Result: 4 (100 in binary)
*/

