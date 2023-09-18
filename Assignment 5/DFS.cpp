#include<iostream>
#include "Stack.cpp"
#include<fstream>
#define size 10
using namespace std;
class DFS{
public:
    int v;
    int mat[size][size];
    int visited[];
    DFS(){
        mat[v][v];
        visited[v];
        ifstream fp("inputmat.txt");
        fp>>v;
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                fp>>mat[i][j];
            }
        }
        fp.close();
        cout<<"Printing the adjacency matrix:\n";
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void initialise(){
        //Initialising visited array to 0.
        for(int i=0;i<v;i++)
            visited[i]=0;
    }
    void dfs_iterative(char s){
        Stack ob;
        ob.push(s);
        visited[(int)s-65]=1;
        while(!ob.isEmpty()){
            char x=ob.pop();
            cout<<x<<" ";
            for(int i=0;i<v;i++){
                if(mat[(int)x-65][i]==1 && visited[i]==0){
                    ob.push(char(i+65));
                    visited[i]=1;
                }
            }
        }
    }
    void dfs_recursive(char s){
        visited[(int)s-65]=1;
        cout<<s<<" ";
        for(int i=0;i<v;i++){
            if(mat[(int)s-65][i]==1 && visited[i]==0){
                dfs_recursive(char(i+65));
            }
        }
    }
};
int main(){
    DFS obj;
    char a;
    cout<<"Enter starting vertex\n";
    cin>>a;
    obj.initialise();
    cout<<"Iterative Depth first search:\n";
    obj.dfs_iterative(a);
    cout<<endl;
    obj.initialise();
    cout<<"Recursive Depth first search:\n";
    obj.dfs_recursive(a);
}
