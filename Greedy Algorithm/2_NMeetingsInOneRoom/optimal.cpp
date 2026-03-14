#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxMeetings(vector<int> start, vector<int> end){
    vector<pair<int,int>> meetings;

    for(int i = 0;i<start.size();i++){
        meetings.push_back({end[i],start[i]});
    }

    int count = 1;
    int freeTime = 0;
    
    sort(meetings.begin(),meetings.end());
   
    for(int i = 1;i<start.size();i++){
        if(meetings[i].second > freeTime){
            count += 1;
            freeTime = meetings[i].first;
        }
    }
    return count;
}
int main(){
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9};

    cout<<"The max meetings can be done in one room: "<<maxMeetings(start,end);

    return 0;
}