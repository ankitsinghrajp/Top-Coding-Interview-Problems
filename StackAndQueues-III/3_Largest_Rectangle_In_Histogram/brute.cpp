#include<iostream>
#include<vector>
using namespace std;
int largestRectangleArea(vector<int> &heights){
    int largestArea = 0;
    for(int i = 0;i<heights.size();i++){
        int right = i+1;
        int width = 1;
        while(right < heights.size() && heights[right] >= heights[i]){
            right ++;
            width++;
        }
       
        int left = i-1;
        while(left >= 0 && heights[left] >= heights[i]){
            left --;
            width ++;
        }

        int area = heights[i] * width;
        largestArea = max(area,largestArea);
    }
    return largestArea;
}
int main(){
    vector<int> arr = {2,1,5,6,2,3};

    cout<<"The largest area of the histogram rectangle is: "<<largestRectangleArea(arr)<<endl;
    return 0;
}