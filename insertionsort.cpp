/*This program implements the insertion sort -- eg deck of cards to be sorted
-- In this type of sorting we iterate through elements of an array and insert the next
element to it's proper place by comparing it to previous elements*/

#include<iostream>
using namespace std;
int main(){
    int n;
    int arr[n];
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter the elements of an array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int k=1;k<n;k++){//k to iterate through the array elements
        int temp = arr[k];
        for(int j = k-1;j>=0;j--){
            if(arr[j]>arr[j+1])
                arr[j] = arr[j+1];
        }
    }
    return 0;
}