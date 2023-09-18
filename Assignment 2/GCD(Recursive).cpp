#include<iostream>
using namespace std;
int gcd(int n1,int n2){
    if(n2!=0){
        return (n2,n2%n1);
    }
    else{
        return n1;
    }
}
int main(){
    int n1,n2;
    cout<<"Enter the first no.\n";
    cin>>n1;
    cout<<"Enter the second no.\n";
    cin>>n2;
    if(n1>n2){
        int t=n1;
        n1=n2;
        n2=t;
    }
    int x=gcd(n1,n2);
    cout<<"The GCD of the two nos. = "<<x<<endl;
}
