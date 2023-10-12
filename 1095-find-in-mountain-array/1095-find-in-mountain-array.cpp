/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(int i,int j,MountainArray& arr) {
        while(i<=j){
            int mid=(i+j)/2;
            if(arr.get(mid)>arr.get(mid+1))j=mid-1;
            else i=mid+1;
        }
        return i;
    }
    int search(int i,int j,MountainArray &arr,int target) {
        int ans=-1;
        while(i<=j) {
            int mid=(i+j)/2;
            if(arr.get(mid)==target){
                ans=mid;
                j=mid-1;
            }
            else if(arr.get(mid)>target)j=mid-1;
            else i=mid+1;
        }
        return ans;
    }
    int rsearch(int i,int j,MountainArray &arr,int target) {
        int ans=-1;
        while(i<=j) {
            int mid=(i+j)/2;
            if(arr.get(mid)==target){
                ans=mid;
                j=mid-1;
            }
            else if(arr.get(mid)>target)i=mid+1;
            else j=mid-1;
        }
        return ans;
    }
    int findInMountainArray(int target, MountainArray &arr) {
        int n=arr.length();
        int peak=findPeak(0,n-1,arr);
        int ans=search(0,peak,arr,target);
        if(ans!=-1)return ans;
        return rsearch(peak+1,n-1,arr,target);
    }
};