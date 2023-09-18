#include<iostream>
#define max 10
using namespace std;
class Queue{
public:
    char arr[max];
    int front,rear;
    Queue(){
        front=-1;
        rear=-1;
    }
    bool isFull(){
        if(rear==max-1)
            return true;
        else
            return false;
    }
    bool isEmpty(){
        if(front==rear)
            return true;
        else
            return false;
    }
    void enQueue(char item){
        if(!isFull())
        {
            rear++;
            arr[rear]=item;
        }
        else
            cout<<"Queue is full\n";
    }
    char deQueue(){
        if(!isEmpty()){
            front=front+1;
            return arr[front];
        }
        else{
            cout<<"Queue is empty\n";
            return INT_MIN;
        }
    }
    char peek(){
        if(!isEmpty())
            return arr[front+1];
        else{
            cout<<"Queue is empty\n";
            return INT_MIN;
        }
    }
    void display(){
        if(!isEmpty()){
            for(int i=front +1;i<=rear;i++)
                cout<<arr[i]<<"  ";
        }
        else
            cout<<"Queue is empty\n";
    }
};
