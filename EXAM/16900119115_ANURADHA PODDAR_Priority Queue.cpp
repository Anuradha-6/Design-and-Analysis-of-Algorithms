//Priority Queue using min heap.
#include<iostream>
#define size 30 //Total capacity
using namespace std;
int n=0;
int arr[size];
    void heapAdjust(int* arr,int i,int n){
        int key=arr[i];
        int j=2*i; //Leftchild
        while(j<=n){
            if(arr[j]>arr[j+1] && j+1<=n)
                j=j+1;
            if(arr[j]>=key)
                break;
            arr[j/2]=arr[j];
            j=j*2;
        }
        arr[j/2]=key;
    }
    int getMinimum(){
        //Returns minimum element.
        return arr[1];
    }
    int extractMinimum(){
    //Removes minimum element from heap.
        if(n<=0)
            return -9999;
        if(n==1){
            n-=1;
            return arr[1];
        }
        int min=arr[1];
        arr[1]=arr[n];
        n=n-1;
        heapAdjust(arr,1,n);
        return min;
    }
    void decreaseKey(int in,int newVal){
        int i=in;
        arr[i]=newVal;
        while(i>=1 && arr[i/2]>arr[i]){
            int temp=arr[i];
            arr[i]=arr[i/2];
            arr[i/2]=temp;
            i/=2;
        }
    }
    void insertKey(int k){
        if(n>size){
            cout<<"Overflow. Could not insert key"<<endl;
            return;
        }
        n=n+1;
        arr[n]=k;
        int i=n;
        while(i>1 && arr[i/2]>arr[i]){
            int temp=arr[i];
            arr[i]=arr[i/2];
            arr[i/2]=temp;
            i/=2;
        }
    }
    void deleteKey(int i){
        if(i>n){
            cout<<"Delete not possible"<<endl;
            return;
        }
        decreaseKey(i,-9999);
        extractMinimum();
    }
    void print(){
        for(int i=1;i<=n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    bool isEmpty(){
        if(n==0)
            return true;
        return false;
    }
