#include<iostream>
#define max 10
using namespace std;
int arr[max];
int n;
void input(){
    cout<<"Enter the no. of elements in the array\n";
    cin>>n;
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
int largest(int i,int lar){
    if(i<n){
        if(arr[i]>lar)
            lar=arr[i];
        largest(i+1,lar);
    }
    else
        return lar;
}
int main(){
    input();
    int l=largest(0,0);
    cout<<"The largest no.= "<<l<<endl;
}
