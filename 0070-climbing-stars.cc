// think of the first approach, yeah, recursion using the same logic as fibonacchi numbers.
//

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

//somehow this doesnt pass all the test cases.
