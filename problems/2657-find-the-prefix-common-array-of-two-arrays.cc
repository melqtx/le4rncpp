class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
       
     int n = A.size();
      vector<int> result(n);
      unordered_set<int> setA, setB;
      int count = 0;
    
     for(int i = 0; i < n; i++) {
         setA.insert(A[i]);
          setB.insert(B[i]);
        
          // If same number is inserted in both sets, it's common
          if(setA.count(B[i])) count++;
          if(setB.count(A[i]) && A[i] != B[i]) count++;
        
         result[i] = count;
      }
      return result;
    }
};

//tfw you write a linear soln
