/* This program is supposed to find all subarrays of a given array
subarray is a subsequence of an array which is continuos 
The number of subarrays of an array of size n is [n*(n+1)]/2 */ 

#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of an array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<"("<<arr[i]<<arr[j]<<")"<<endl;
        }
    }
    return 0;
}