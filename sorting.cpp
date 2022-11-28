#include<bits/stdc++.h>
using namespace std;

int *bubbleSort(int *arr, int n){
    for(int i = 0; i < n - 1; i++){
        int m = 0;
        for(int j = 1; j < n - i; j++){
            if(arr[m] > arr[j]){
                swap(arr[j],arr[m]);
            }
            m = j;
        }
    }
    return arr;
}   

int *selectionSort(int *arr, int n){
    for(int i = 0; i < n - 1; i++){
        int m = i;
        for(int j = i + 1; j < n; j++){
            if(arr[m] > arr[j]){
                m = j;
            }
        }
        swap(arr[m], arr[i]);
    }
    return arr;
}

int *insertionSort(int *arr, int n){
    for(int i = 1; i < n; i++){
        int j = i, key = arr[i];
        while((arr[j - 1] > key) && j >= 1){
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
    return arr;
}

int quickPartition(int arr[], int low, int high){
    int left = low, right = high, pivotElement = arr[low];
    while(left <= right){
        while(arr[left] <= pivotElement){
            left++;
        }
        while(arr[right] > pivotElement){
            right--;
        }
        if(left < right){
            swap(arr[left], arr[right]);
        }
    }
    arr[low] = arr[right];
    arr[right] = pivotElement;
    return right;
}

void quickSort(int *arr, int low, int high){
    int pivot;
    if(low < high){{
        pivot = quickPartition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void mergeSort(int *arr, int n, int low, int high){
    if(high > low){
        int mid = high - (high - low) / 2;
        mergeSort(arr, n, low, mid);
        mergeSort(arr, n, mid + 1, high);
        merge(arr, n, low, mid, right);
    }
}

int main(){
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
} 

