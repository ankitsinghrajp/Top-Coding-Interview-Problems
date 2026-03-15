#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
    int value;
    int weight;
};

static bool comp(Item a, Item b){
      double first = (double)a.value/a.weight;
      double second = (double)b.value/b.weight;
      return first > second;
}
int FractionalKnapSack(vector<pair<int,int>> arr, int w){
    vector<Item> Items;
    for(int i = 0;i<arr.size();i++){
        Items.push_back({arr[i].first,arr[i].second});
    }

    sort(Items.begin(),Items.end(),comp);

    int totalValue = 0;
    for(int i = 0;i<Items.size();i++){
        if(Items[i].weight <= w){
            totalValue += Items[i].value;
            w = w - Items[i].weight;
        }
        else{
            totalValue += (double)Items[i].value/ Items[i].weight * w;
            break;
        }
    }
    return totalValue;
}
int main(){
    vector<pair<int,int>> arr = {{100,20},{60,10},{100,50},{200,50}};
    int w = 90;

    cout<<"The maximum value you can hold in the Bag of Weight: "<<w<<" is: "<<FractionalKnapSack(arr,w);
    return 0;
}