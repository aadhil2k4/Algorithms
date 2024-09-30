//Mostly in dynamic graphs
// Disjoint sets are used to keep track of the connected components of a graph

#include<iostream>
#include<vector>

using namespace std;

int find(int i){
    if(parent[i] == i){
        return i;
    }else{
        return find(parent[i]);
    }
}

int main(){

}