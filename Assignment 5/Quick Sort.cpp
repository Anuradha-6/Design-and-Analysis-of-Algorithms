#include<iostream>
using namespace std;
int count=0,compare=0;
void swap(int *x,int *y){
    int temp=*y;
    *y=*x;
    *x=temp;
}
void display(int arr[],int l,int u){
    for(int i=l;i<u;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int partition(int arr[],int low,int high){
    int left=low;
    int right=high+1;
    int pivot=arr[low];
    cout<<"Pivot= "<<pivot<<endl;
    while(left<right){
        do{
            left++;
        }while(arr[left]<pivot && left<=high);
        do{
            right--;
        }while(arr[right]>pivot);
        if(left<right){
            compare++;
            cout<<"Swapping "<<arr[left]<<" and "<<arr[right]<<":\n";
            swap(&arr[left],&arr[right]);
            display(arr,low,high+1);
        }
    }
    compare++;
    cout<<"Swapping "<<arr[right]<<" and "<<arr[low]<<":\n";
    swap(&arr[low],&arr[right]);
    display(arr,low,high+1);
    return right;
}
void quick_sort(int arr[],int low,int high){
    if(low<high){
        cout<<"pass "<<++count<<":\n";
        int j=partition(arr,low,high);
        cout<<"The two sub arrays are:\n";
        display(arr,low,j);
        display(arr,j+1,high+1);
        quick_sort(arr,low,j-1);
        quick_sort(arr,j+1,high);
    }
}
int main(){
    int n;
    cout<<"Enter the no of elements\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quick_sort(arr,0,n-1);
    cout<<"The sorted array is:\n";
    display(arr,0,n);
    cout<<"The no. of passes= "<<count<<endl;
    cout<<"The no. of comparisons= "<<compare;
}
