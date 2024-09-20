#include <iostream>
#include <vector>

int findKthPositive(std::vector<int>& arr, int k) {
    int missingCount = 0;
    int current = 1;
    int index = 0;

    while (missingCount < k) {
        if (index < arr.size() && arr[index] == current) {
            index++;
        } else {
            missingCount++;
            if (missingCount == k) {
                return current;
            }
        }
        current++;
    }

    return -1; // This line should never be reached
}

int main() {
    std::vector<int> arr1 = {2, 3, 4, 7, 11};
    int k1 = 5;
    std::cout << "The " << k1 << "th missing positive number is: " << findKthPositive(arr1, k1) << std::endl;

    std::vector<int> arr2 = {1, 2, 3, 4};
    int k2 = 2;
    std::cout << "The " << k2 << "th missing positive number is: " << findKthPositive(arr2, k2) << std::endl;

    return 0;
}

//main approach
class Solution {
public:
    int findKthPositive(vector<int>& A, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int l = 0, r = A.size(), m;
        while (l < r) {
            m = (l + r) / 2;
            if (A[m] - 1 - m < k)
                l = m + 1;
            else
                r = m;
        }
        return l + k;
    }
};

//additional
class Solution {
public:
    int findKthPositive(vector<int>& A, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int l = 0, r = A.size(), m;
        while (l < r) {
            m = (l + r) / 2;
            int missing = A[m]- (m + 1);
            if (missing < k)
                l = m + 1;
            else
                r = m;
        }
        return l + k;
    }
};

/*
we are returning l+k OR high + 1+ k; because we are returning the missing number,
so how do we know its a missing number?
if we found bw what index our number lies, we will just do more = k - missing;
so the ans aws arr[high] + more;
so now just chip in the fourmula for more;
arr[high] + k - missing
arr[high] + k - (arr[high] - high - 1)
it cancels
were left with high + k + 1;
*/