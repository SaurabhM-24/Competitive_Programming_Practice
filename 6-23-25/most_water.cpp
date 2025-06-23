#include <iostream>
using namespace std;

int maxArea(int height[], int n) {
    
    int i=0, j=n-1;
    int max = 0;

    while(i < j) {

        int depth = min(height[i], height[j]);
        int width = j-i;

        int water = depth*width;

        if(water > max)
            max = water;
        
        if(height[i] < height[j])
            i++;
        else
            j--;
    }

    return max;
}

int main() {

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i=0;i <n; i++) {
        cin >> arr[i];
    }

    int max_water = maxArea(arr, n);
    cout << max_water;

    return 0;
}
