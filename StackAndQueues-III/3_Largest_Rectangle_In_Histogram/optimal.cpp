#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int> &heights){
   stack<int> st;
   int maxArea = 0;
   for(int i = 0;i<heights.size();i++){
    while(!st.empty() && heights[st.top()] > heights[i]){
        int element = heights[st.top()];
        st.pop();
        int nse = i;
        int pse = st.empty()? -1: st.top();

        maxArea = max(maxArea, (nse-pse-1) * element);
    }
    st.push(i);
   }

   while(!st.empty()){
      int element = heights[st.top()];
      st.pop();
      int nse = heights.size();
      int pse = st.empty()? -1: st.top();

      maxArea = max(maxArea, (nse-pse-1) * element);
   }
   return maxArea;
}
int main(){
    vector<int> arr = {2,1,5,6,2,3};

    cout<<"The largest area of the histogram rectangle is: "<<largestRectangleArea(arr)<<endl;
    return 0;
}