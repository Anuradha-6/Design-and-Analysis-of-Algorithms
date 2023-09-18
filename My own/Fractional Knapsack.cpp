//Fractional Knapsack
#include<iostream>
#include <bits/stdc++.h>
#define size 10
using namespace std;
int W;
int n;
struct Item{
    int p;
    int w;
    float d;
};
void input(Item items[],int a){
    n=a;
    cout<<"Enter the capacity of Knapsack\n";
    cin>>W;
    cout<<"Enter the weight of each item\n";
    for(int i=0;i<n;i++)
        cin>>items[i].w;
    cout<<"Enter the profit of corresponding items\n";
    for(int i=0;i<n;i++)
        cin>>items[i].p;
}
bool compare(Item i1, Item i2) {
   return (i1.d > i2.d);
}
void calculate(Item items[]){
    float tp=0.0;
    for(int i=0;i<n;i++)
        items[i].d=float(items[i].p)/items[i].w;
    sort(items, items + n, compare);
    int i;
    for(i=0;i<n;i++){
        if(W>items[i].w){
            tp+=items[i].p;
            W-=items[i].w;

        }
        else{
            break;
        }
    }
    tp=tp+(items[i].d)*W;
    cout<<"Total amount that can be stolen= "<<tp<<endl;
}

int main(){
    int n;
    cout<<"Enter the no. of elements\n";
        cin>>n;
    Item items[n];
    input(items,n);
    calculate(items);
}
