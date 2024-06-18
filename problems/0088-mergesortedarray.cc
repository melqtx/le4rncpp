class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // Index for nums1
        int j = n - 1; // Index for nums2
        int k = m + n - 1; // Index for the merged array

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                // If the current element in nums1 is greater than the current element in nums2,
                // place the element from nums1 at the end of the merged array.
                nums1[k--] = nums1[i--];
            } else {
                // Otherwise, place the element from nums2 at the end of the merged array.
                nums1[k--] = nums2[j--];
            }
        }
    }
};
