#include<iostream>
using namespace std;
int sum(int n,int s){
    if(n!=0){
        s+=n%10;
        sum(n/10,s);
    }
    else
        return s;
}
int main(){
    int n;
    cout<<"Enter the number\n";
    cin>>n;
    int sod=sum(n,0);
    cout<<"The sum of digits of the no.= "<<sod<<endl;
}
