#include<iostream>
using namespace std;
int count=0;
int n;
void Merge(int arr[],int left,int mid,int right){
    int t=1;
    int i=left,j=mid+1,k=left;
    int z[50];
    while(i<=mid && j<=right && ++count){

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
    cout<<"sub pass "<<t++<<endl;
	for(int i=0 ; i<n ; ++i)
		cout<<arr[i]<<" ";
		cout<<endl;
    for(int i=left;i<=right;i++)
        arr[i]=z[i];
}
void MergeSort(int arr[],int left,int right){
    static int t=0;
    if(left<right){
        int mid=(left+right)/2;
        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,right);
        Merge(arr,left,mid,right);
        cout<<"pass "<<t++<<endl;
		for(int i=0 ; i<n ; ++i)
			cout<<arr[i]<<" ";
		cout<<endl;
    }
    else
        return;
}
int main(){
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
    cout<<"\nNo. of comparisons = "<<count;
}
