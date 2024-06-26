/*
    Given a string s, return true if it's a palindrome

    Time: O(n)
    Space: O(1)

    so we gonna use pointers, ignore alpha num; convert to lowercase, and yeah
   thats it.
*/

class Solution {
public:
  bool isPalindrome(string s) {
    int n = s.size();
    int l = 0, r = s.size() - 1;

    // using pointers, one from left and one to right.
    while (l < r) {
      while (l < r && !isalnum(s[l])) {
        l++;
      }

      while (l < r && !isalnum(s[r])) {
        r--;
      }

      if (tolower(s[l++]) != tolower(s[r--])) {
        return false;
      }
    }
    return true;
  }
};
