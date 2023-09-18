#include<iostream>
#define max 5
using namespace std;
class Queue{
public:
    int arr[max];
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
    void enQueue(int item){
        if(!isFull())
        {
            rear++;
            arr[rear]=item;
        }
        else
            cout<<"Queue is full\n";
    }
    int deQueue(){
        if(!isEmpty()){
            front=front+1;
            return arr[front];
        }
        else{
            cout<<"Queue is empty\n";
            return -9999;
        }
    }
    int peek(){
        if(!isEmpty())
            return arr[front+1];
        else{
            cout<<"Queue is empty\n";
            return -9999;
        }
    }
    void display(){
        if(!isEmpty()){
            cout<<"The queue is:\n";
            for(int i=front+1;i<=rear;i++)
                cout<<arr[i]<<"  ";
        }
        else
            cout<<"Queue is empty\n";
    }
};
int main(){
    int ch;
    int x;
    int item;
    Queue obj;
    while(true){
        cout<<"\n1.enQueue\n2.deQueue\n3.Peek\n4.Display\n5.Exit\n";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter the item\n";
                cin>>item;
                obj.enQueue(item);
                obj.display();
                break;
            case 2:
                x=obj.deQueue();
                if(x!=-9999){
                    cout<<x<<" is deleted\n";
                    obj.display();
                }
                break;
            case 3:
                x=obj.peek();
                if(x!=-9999)
                    cout<<x<<"\n";
                break;
            case 4:
                obj.display();
                break;
            case 5:
                cout<<"Program Terminated";
                exit(0);
                break;
            default:
                cout<<"Incorrect choice\n";
        }
    }
    return 0;
}
