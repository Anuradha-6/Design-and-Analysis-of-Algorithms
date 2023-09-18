#include<iostream>
#define MAX 30
using namespace std;
class Stack{
public:
    char arr[MAX];
    int top;
    Stack(){

        top=-1;
        }
    void push(char a){
        if(isFull())
            cout<<"Overflow\n";
        else
            arr[++top]=a;
    }
    char pop(){
    if(!isEmpty()){
        char x=arr[top];
        top--;
        return x;
    }
    else
        return '-1';
    }
    char peek(){
        if(!isEmpty())
            return arr[top];
    }
    int isFull(){
        if(top==MAX-1)
            return 1;
        else
            return 0;
    }
    int isEmpty(){
        if(top==-1)
            return 1;
        else
            return 0;
    }
    void display(){
        if(!isEmpty()){
            for(int i=top;i>=0;i--)
                cout<<arr[i]<<"\n";
        }
    }
};
