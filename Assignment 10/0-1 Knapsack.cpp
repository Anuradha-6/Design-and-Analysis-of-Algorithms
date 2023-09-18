//0/1 Knapsack using dynamic programming
#include<iostream>
#define s 10
using namespace std;
int p[s];
int wt[s];
int n;
int M;
void input(){
    cout<<"Enter the number of items\n";
    cin>>n;
    cout<<"Enter the capacity of knapsack\n";
    cin>>M;
    cout<<"Enter the weight of each item and their corresponding profits\n";
    for(int i=0;i<n;i++){
        cin>>wt[i];
        cin>>p[i];
    }
}
void knapsack(){
    int X[n+1][M+1];
    for(int i=0;i<=n;i++)
        X[i][0]=0;
    for(int w=0;w<=M;w++)
        X[0][w]=0;
    for(int i=1;i<=n;i++){
        for(int w=1;w<=M;w++){
            if(wt[i-1]<=w)
                X[i][w] = max(p[i-1]+X[i-1][w-wt[i-1]],X[i-1][w]);
            else
                X[i][w]=X[i-1][w];
        }
    }
    for(int i=0;i<=n;i++){
        for(int w=0;w<=M;w++){
            cout<<X[i][w]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
    // Displaying the items in knapsack
    int total=X[n][M];
    int w=M;
    cout<<"The items in the knapsack are:\n   profit  weight"<<endl;
    for(int i=n;i>0;i--){
        if(total==X[i-1][w])
            continue;
        else{
            cout<<i<<"  "<<p[i-1]<<"      "<<wt[i-1]<<endl;
            w-=wt[i-1];
            total-=p[i-1];
            if(total==0)
                break;
        }
    }
    cout<<"Total value in knapsack = "<<X[n][M]<<endl;
}
int main(){
    input();
    knapsack();
}
