// Question - Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Code in c++
#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int n, int k) 
{ 
    sort(arr, arr + n); 
      return arr[k - 1]; 
} 
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int k;
	    cin>>k;
	    cout<<kthSmallest(arr, n, k);
	}
	return 0;
}
