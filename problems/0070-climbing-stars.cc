// think of the first approach, yeah, recursion using the same logic as fibonacchi numbers.
//

class Solution { //time limit exceeded
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

//somehow this doesnt pass all the test cases.
//same as doing the fibonacchi appraoch and it works well;
class Solution {
public:
    int climbStairs(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (n == 0 || n == 1) {
            return 1;
        }
        int one = 1, two = 1;
        for(int i = 2; i <= n; i++) {
            //int temp = one;
            //one+= two; 
            //two = temp; 
            one = one + two;
            two = one - two;
        }
        return one;
    }
};
