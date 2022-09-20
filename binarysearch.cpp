/* This program is to implement Binary Search in CPP to search an element in an array */

#include<iostream>
using namespace std;

int BinarySearch(int arr[],int n,int target){
    int s=0,e=n;
    int mid = (s+e)/2;
    while(s<=e){
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return -1;
    
}

int main(){

    int n,target;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter the target integer: ";
    cin>>target;
    int arr[n];
    cout<<"Enter elements of array separated by a space: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<BinarySearch(arr,n,target);
    return 0;
}