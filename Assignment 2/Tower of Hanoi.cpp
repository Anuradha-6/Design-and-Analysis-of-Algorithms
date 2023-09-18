#include<iostream>
using namespace std;
int c=0;
void TOH(int n,char src,char aux,char dest){
    if(n==1){
        cout<<"Move disk 1 from "<<src<<" to "<<dest<<"\n";
        c++;
        return;
    }
    else{
        TOH(n-1,src,dest,aux);
        cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<"\n";
        c++;
        TOH(n-1,aux,src,dest);
    }
}
int main(){
    int n;
    cout<<"Enter the number of disks\n";
    cin>>n;
    TOH(n,'A','B','C');
    cout<<"The total no. of moves = "<<c;
    return 0;
}
