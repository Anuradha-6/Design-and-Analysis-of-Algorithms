#include<iostream>
using namespace std;
int recursive(int arr[],int l,int r,int x){
    if(l==r){
        if(x==arr[l])
            return l;
        return -1;
    }
    else{
        int mid=(l+r)/2;
        if(arr[mid]==x)
            return mid;
        else if(x>arr[mid])
            return recursive(arr,mid+1,r,x);
        else
            return recursive(arr,l,mid-1,x);
    }
}
int main(){
    int n;
    cout<<"Enter the no. of elements\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cout<<"Enter the element to be searched\n";
    cin>>x;
    int a=recursive(arr,0,n-1,x);
    if(a==-1)
        cout<<"Element not found\n";
    else
        cout<<"Element found at position "<<a<<endl;

}
