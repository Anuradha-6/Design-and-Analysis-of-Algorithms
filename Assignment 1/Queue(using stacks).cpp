#include<stdio.h>
#include"Stack.cpp"
#define MAX 10
using namespace std;
class Queue_using_stack{
public:
    Stack s1;
    Stack s2;
    void insert(int item){
        s1.push(item);
    }
    void del(){
        while(!s1.isEmpty()){
            int item=s1.pop();
            s2.push(item);
        }
        s2.pop();
        while(!s2.isEmpty()){
            int item=s2.pop();
            s1.push(item);
        }
    }
    void display(){
        s1.display();
    }
};
int main(){
    Queue_using_stack ob;
    int ch;
    int item;
    while(true){
        cout<<"1.Insert an item\n2.Delete an item\n3.Display\n4.Exit\n";
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"Enter the item\n";
            cin>>item;
            ob.insert(item);
            break;
        case 2:
            ob.del();
            break;
        case 3:
            ob.display();
            break;
        case 4:
            exit(0);
        }
    }
}
