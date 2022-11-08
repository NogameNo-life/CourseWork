#include <iostream>

void MergeSort(int *arr,int low,int high){
    int mid=(low+high)/2;
    auto n=high*sizeof(int);
    int *artmp=new int[n];
    int i=low;
    int j=mid+1;
    int end=high-low+1;
    if(low==high) 
        return;
    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    for(int start{};start<end;++start){
        if(j>high || i<=mid+1 && arr[i]<arr[j]){
            artmp[start]=arr[i];
            ++i;
        }
        else {
            artmp[start]=arr[j];
            ++j;
        }
    }

    for(int start{};start<end;++start){
        arr[low+start]=artmp[start];
    }
    delete []artmp;
}
  
void Print(int *array,int n){
    for(int i{};i<n;++i){
        std::cout<<array[i]<<" ";
    }
    std::cout<<"\n";
}

int main(){
    int array[]{5,7,1,0,-3,0};
    std::size_t n = sizeof(array) / sizeof(array[0]);
    MergeSort(array,0,n-1);
    Print(array,n);
}