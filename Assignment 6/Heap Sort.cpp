#include<iostream>
using namespace std;
    void print(int arr[],int n){
        for(int i=1;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    void heapAdjust(int arr[],int i,int n){
        int key=arr[i];
        int j=2*i; //Leftchild
        while(j<=n){
            if(arr[j]<arr[j+1]&&j+1<=n)
                j=j+1;
            if(arr[j]<=key)
                break;
            arr[j/2]=arr[j];
            j=j*2;
        }
        arr[j/2]=key;
    }
    void heapify(int arr[],int n){
        for(int i=n/2;i>=1;i--)
            heapAdjust(arr,i,n);
    }
    void heapsort(int arr[],int n){
        heapify(arr,n);
        cout<<"Max heap:\n";
        print(arr,n);
        for(int i=n-1;i>1;i--){
            int temp=arr[1];
            arr[1]=arr[i];
            arr[i]=temp;
            print(arr,n);
            heapAdjust(arr,1,i-1);
            print(arr,i);
        }
    }
    int main(){
        int n;
        cout<<"Enter the no. of elements\n";
        cin>>n;
        n+=1;
        int arr[n];
        arr[0]=-9999;
        cout<<"Enter the array elements\n";
        for(int i=1;i<n;i++)
            cin>>arr[i];
        heapsort(arr,n);
        cout<<"Sorted array is: \n";
        print(arr,n);
}
