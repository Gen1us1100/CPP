// A program to implement bubble sort

#include<iostream>

using namespace std;



void bubbleSort(int arr[],int n){
    int counter = 1 ;
    while(counter<n){ //counter is for the pass or the round 
        for(int i = 0;i<n-counter;i++){//last elements each round will be sorted so n-counter
            if(arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            
            }
                
        }
        counter++;
    }
}


int main(){
    int n;
    cout<<"Enter size of an array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of an array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}