
// dude you're n2 algorithm
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<int> printLeadersBruteForce(int arr[], int n) {

  vector<int> ans;
  
  for(int i = 0; i < n; i++) {
    bool leader = true;
    for(int j = i+1; j < n; j++) {
       if(arr[j] > arr[i]){
         leader = false;
        }
    }
    if(leader){
      ans.push_back(arr[i]);
    }
  }
  return ans;
}

vector<int> func2(int arr[], int n) {
  vector<int> ans;
  int max = arr[n-1];
  ans.push_back(arr[n-1]);

  for(int i = n-2; i >= 0; i--) {
    if(arr[i] > max) {
      ans.push_back(arr[i]);
      max = arr[i];
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
  
}

/*
vector<int> func2(int arr[], int n) {
    vector<int> ans;
    int max = arr[n0];
    ans.push_back(arr[n0]);
    for(int i = n-1; i >= 0; i--) {
        if(arr[i] > max) {
            ans.push_back(arr[i]);
            max = arr[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
*/

int main() {
    
  // Array Initialization.
  int n = 6;
  int arr[n] = {10, 22, 12, 3, 0, 6};

  vector<int> ans = func2(arr,n);
  
  for(int i: ans){
    cout << i << " ";
  }
  
  cout<<endl;
  return 0;
}


