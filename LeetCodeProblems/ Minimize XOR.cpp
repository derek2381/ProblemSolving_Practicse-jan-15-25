// Problem Link
// https://leetcode.com/problems/minimize-xor/description/


// Source Code

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = __builtin_popcount(num2); // Count the set bits in num2
        int result = 0;

        // Set bits in result based on num1's set bits
        for (int i = 31; i >= 0 && count > 0; i--) {
            if (num1 & (1 << i)) { // If bit `i` is set in num1
                result |= (1 << i); // Set bit `i` in result
                count--;
            }
        }

        // If more bits need to be set, use the least significant unset bits
        for (int i = 0; i < 32 && count > 0; i++) {
            if (!(result & (1 << i))) { // If bit `i` is not set in result
                result |= (1 << i); // Set bit `i` in result
                count--;
            }
        }

        return result;
    }
};
