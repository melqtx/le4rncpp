class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < static_cast<long>(m) * k)
            return -1;
                 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int left = ranges::min(bloomDay);
        int right = ranges::max(bloomDay);

        while (left < right) {
            const int mid = (left + right) / 2;
            if (getBouquetCount(bloomDay, k, mid) >= m)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }

private:
    int getBouquetCount(const vector<int>& bloomDay, int k, int waitingDays) {
        int bouquetCount = 0;
        int requiredFlowers = k;

        for (const int day : bloomDay) {
            if (day > waitingDays) {
                requiredFlowers = k;
            } else if (--requiredFlowers == 0) {
                ++bouquetCount;
                requiredFlowers = k;
            }
        }

        return bouquetCount;
    }
};

//honestly i didnt get this approach initially, with the help of edutorial figured it out, this can me made 
//better imma do it tomorrow i promies.:Wq
class Solution {
public:
    int bouquetcount(vector<int>& bloomDay,int k, int mid ){
        int reqfl = k;
        int bouq = 0;
        int count = 0;
        for(int flow: bloomDay){
            if(flow <= mid){
                count++;
                if(count == k){
                    bouq++;
                    count = 0;
                }
            }else{
                count=0;
            }
        }
        return bouq;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()< m*k) return -1;

        int low = ranges::min(bloomDay);
        int high = ranges::max(bloomDay);
        while(low <= high) {
            int mid = low + (high - low)/2;
            int count =  bouquetcount(bloomDay,k,mid);
            if(count >= m){
                high = mid -1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};

// there is a common pattern in these kind of questions, we gotta have two functions, one is the main one 
// where we perform binary search, and the other one for calculating the answer.
