#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

struct Job{
    int deadline;
    int profit;
};

static bool cmp(Job a, Job b){
    return a.profit > b.profit;
}
vector<int> JobSequencing(vector<int> &deadline, vector<int> &profit){
   vector<Job> jobs;
   int maxDeadline = 0;
   for(int i = 0;i<deadline.size();i++){
       jobs.push_back({deadline[i],profit[i]});
       maxDeadline = max(maxDeadline,deadline[i]);
   }

   sort(jobs.begin(),jobs.end(),cmp);
   
   vector<int> Hash(maxDeadline + 1, -1);

   int totalProfit = 0;
   int count = 0;
   for(int i = 0;i<jobs.size();i++){
       for(int j = jobs[i].deadline; j>0; j--){
          if(Hash[j] == -1){
            count += 1;
            totalProfit += jobs[i].profit;
            Hash[j] = 1;
            break;
          }
       }
   }

   return {count, totalProfit};
}
int main(){
  vector<int> deadline = {2, 1, 2, 1, 1};
  vector<int> profit = {100, 19, 27, 25, 15};
  
  vector<int> ans = JobSequencing(deadline,profit);

  cout<<"The no. of jobs you can perform and maxProfit respectively is: "<<endl;

  printArray(ans);

    return 0;
}