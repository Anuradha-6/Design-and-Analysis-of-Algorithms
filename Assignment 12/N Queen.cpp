#include<iostream>
#define s 10
using namespace std;
int n;
int x[s];
static int c=0;
bool place(int k, int i){
    for(int j=1;j<k;j++){
        if(x[j]==i or (abs(x[j]-i)==abs(j-k)))
            return false;
    }
    return true;
}
void print(){
    c++;
    for(int i=1;i<=n;i++)
        cout<<x[i]<<"  ";
    cout<<endl;
}
void nQueens(int k,int n){
    for(int i=1;i<=n;i++){
        if(place(k,i)){
            x[k]=i;
            if(k==n)
                print();
            else
                nQueens(k+1,n);
        }
    }
}
int main(){
    cout<<"Enter the value of n\n";
    cin>>n;
    nQueens(1,n);
    if(c == 0)
        cout<<"No possible solution exists\n";
    else
        cout<<"The number of possible solutions = "<<c;
}
