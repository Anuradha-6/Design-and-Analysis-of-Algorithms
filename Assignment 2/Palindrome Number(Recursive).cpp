#include<iostream>
using namespace std;
int isPalindrome(int num,int n,int rev){  //n stores the copy of num
    if(num==0){
        if(n==rev)
            return 1;
        else
            return 0;
    }
    else{
        rev=rev*10+num%10;
        isPalindrome(num/10,n,rev);
    }
}
int main(){
    int num;
    cout<<"Enter the number\n";
    cin>>num;
    int x=isPalindrome(num,num,0);
    (x==1)?cout<<"PALINDROME":cout<<"NOT PALINDROME";
}
