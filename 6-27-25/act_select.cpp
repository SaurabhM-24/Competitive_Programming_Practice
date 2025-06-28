#include <iostream>
using namespace std;

int partition(int arr[], int low, int high, int dep_arr[]) {

    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            swap(dep_arr[i], dep_arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    swap(dep_arr[i+1], dep_arr[high]);
    return (i+1);
}

void mod_qsort(int arr[], int low, int high, int dep_arr[]) {

    if(low < high) {

        int pivot = partition(arr, low, high, dep_arr);

        mod_qsort(arr, low, pivot-1, dep_arr);
        mod_qsort(arr, pivot+1, high, dep_arr);
    }
}

int count_act(int n, int start[], int finish[]) {

    mod_qsort(finish, 0, n-1, start);

    int end = finish[0];
    int count = 1;

    for(int i=1; i<n; i++) {
        if(start[i] < end)
            continue;
        
        count++;
        end = finish[i];
    }

    return count;
}

int main() {

    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    int c = count_act(n, start, finish);
    cout << c;
    return 0;
}
