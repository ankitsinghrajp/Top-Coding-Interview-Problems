#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> NSR(vector<int> & heights){
   vector<int> result(heights.size(), heights.size());
   stack<int> st;
   for(int i = heights.size()-1;i>=0;i--){
       while(!st.empty() && heights[st.top()] >= heights[i]){
        st.pop();
       }

       if(!st.empty()) result[i] = st.top();
       st.push(i);
   }
   return result;
}

vector<int> NSL(vector<int> & heights){
   vector<int> result(heights.size(), -1);
   stack<int> st;
   for(int i = 0;i<heights.size();i++){
      while(!st.empty() && heights[st.top()] >= heights[i]){
        st.pop();
      }

      if(!st.empty()) result[i] = st.top();
      st.push(i);
   }
   return result;
}

int largestRectangleArea(vector<int> &heights){
    vector<int> nsr = NSR(heights);
    vector<int> nsl = NSL(heights);

    int largestArea = 0;
    for(int i = 0;i<heights.size();i++){
        int area = heights[i] * (nsr[i]-nsl[i]-1);
        largestArea = max(largestArea,area);
    }
    return largestArea;
}
int main(){
    vector<int> arr = {2,1,5,6,2,3};

    cout<<"The largest area of the histogram rectangle is: "<<largestRectangleArea(arr)<<endl;
    return 0;
}