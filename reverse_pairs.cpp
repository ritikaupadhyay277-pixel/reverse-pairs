class Solution {
public:
 void ms(vector<int>&arr , int low,int mid,int high){
  long long left = low;
  long long ryt= mid+1;
  vector<int> temp;
   while (left<=mid && ryt <=high){
    if (arr[left]<=arr [ryt]){
        temp.push_back(arr[left]);
        left++;
    
    }
     // ryt is smaller
     else {
        temp.push_back(arr[ryt]);
        ryt++;   
     }
   }
   //left got exhausted 
   while(ryt<=high){
    temp.push_back(arr[ryt]);
    ryt++;
   }
   // ryt ot exhausted 
   while (left<=mid){
    temp.push_back(arr[left]);
    left++;
   }
   for (int i = low; i <= high; i++) {
    arr[i] = temp[i - low];
}
 
 }

  long long int countpairs (vector<int>&arr , int low, int mid , int high){
    long long cnt=0;
    int right = mid+1 ;
    for (int i =low ; i<= mid ; i++){
        while (right<= high && arr[i] > 2LL*arr[right]){
            right++;
        }
        cnt= cnt+ (right -(mid+1)); 
    }
    return cnt;
 }

 int merge (vector<int>& arr,int low,int high ) {
   long long int cnt=0;
    long long count;
    int mid= (low+high )/2; 

    if (low>=high) return 0 ;         // base case

    cnt+= merge (arr , low, mid) ;     // deals with left
    cnt+= merge (arr , mid+1 , high );       // ryt part
     cnt += countpairs(arr, low,mid ,high); 
      ms (arr,low,mid, high);
   return cnt; 
 }

    int reversePairs(vector<int>& nums) {
  int n = nums.size();
 return merge (nums,0,n-1);  
        
    }
};
