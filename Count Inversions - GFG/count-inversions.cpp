//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
     long long merge(long long arr[],long long i,long long mid,long long j){
        long long cnt=0;
        vector<long long> ans;
        int a=i,b=mid+1;
        while(a<=mid && b<=j){
            if(arr[a]<=arr[b]){
                ans.push_back(arr[a]);
                a++;
            }else{
                ans.push_back(arr[b]);
                b++;
                cnt+=(mid-a+1);
            }
        }
        while(a<=mid){
            ans.push_back(arr[a]);
            a++;
        }
        while(b<=j){
            ans.push_back(arr[b]);
            b++;
        }
        for(int k=i;k<=j;k++){
            arr[k]=ans[k-i];
        }
        return cnt;
    }
    long long int mergeSort(long long arr[],long long i,long long j){
        if(i>=j)return 0;
        long long int ans=0;
        long long int mid=(i+j)/2;
        ans+=mergeSort(arr,i,mid);
        ans+=mergeSort(arr,mid+1,j);
        ans+=merge(arr,i,mid,j);
        return ans;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends