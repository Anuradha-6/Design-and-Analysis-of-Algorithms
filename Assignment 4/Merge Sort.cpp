#include<iostream>
using namespace std;

void Merge(int arr[],int left,int mid,int right){
    int i=left,j=mid+1,k=left;
    int z[50];
    while(i<=mid && j<=right){

        if(arr[i]<=arr[j])
            z[k++]=arr[i++];
        else
            z[k++]=arr[j++];
    }
    while(i<=mid){
        z[k++]=arr[i++];
    }
    while(j<=right){
        z[k++]=arr[j++];

    }
    for(int i=left;i<=right;i++)
        arr[i]=z[i];
}
void MergeSort(int arr[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,right);
        Merge(arr,left,mid,right);
    }
    else
        return;
}
int main(){
    int n;
    cout<<"Enter the no. of elements\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    MergeSort(arr,0,n-1);
    cout<<"The sorted array is :\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"  ";
}
