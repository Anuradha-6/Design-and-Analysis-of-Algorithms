//To find maximum and minimum elements using divide and conquer method.
#include<iostream>
using namespace std;
void maxmin(int arr[],int low,int high,int &max,int &min){
    if(low==high){
        max=arr[low];
        min=arr[low];
        return;
    }
    if(low==high-1){
        if(arr[low]>arr[high]){
            max=arr[low];
            min=arr[high];
        }
        else{
            max=arr[high];
            min=arr[low];
        }
        return;
    }
    else{
        int mid=(low+high)/2;
        int max1=INT_MIN;
        int min1=INT_MAX;
        maxmin(arr,low,mid,max,min);
        maxmin(arr,mid+1,high,max1,min1);
        if(max<max1)
            max=max1;
        if(min>min1)
            min=min1;
    }
}
int main(){
    int n;
    cout<<"Enter the no. of elements\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int max=INT_MIN;
    int min=INT_MAX;
    maxmin(arr,0,n-1,max,min);
    cout<<"Maximum element= "<<max<<endl;
    cout<<"Minimum element= "<<min<<endl;
}
