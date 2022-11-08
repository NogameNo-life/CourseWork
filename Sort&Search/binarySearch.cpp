#include <iostream>
#include <vector>

int BinarySearch(std::vector<int>& v,int StartIndex,int EndIndex,int wanted){
    if(EndIndex>=StartIndex){
        int MiddleIndex=StartIndex+(EndIndex-StartIndex)/2;
        if(v[MiddleIndex]==wanted)
            return MiddleIndex;
        if(v[MiddleIndex]>wanted)
            return BinarySearch(v,StartIndex,MiddleIndex-1,wanted);
        else 
            return BinarySearch(v,MiddleIndex+1,EndIndex,wanted);
    }
        return -1;


}

int Partition(std::vector<int>& v, int low, int high) {
    int pivot = v[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (v[j] <= pivot) {
            ++i; 
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[high], v[i + 1]);
    return ++i;

}

void QuickSort(std::vector<int>& v, int low, int high) {

    if (low < high) {
        int PivotIndex = Partition(v, low, high);
        QuickSort(v, low, PivotIndex - 1);
        QuickSort(v, PivotIndex + 1, high);
    }
}

void Print(std::vector<int>& v) {
    for (const auto& item : v)
        std::cout << item << " ";

    std::cout << "\n";
}


int main()
{
    
    std::vector v1{ 3,44,8,0,-1,0,-1,7,4 };
    QuickSort(v1, 0, v1.size() - 1);
    std::cout<<BinarySearch(v1,0,v1.size()-1,18)<<"\n";


}
