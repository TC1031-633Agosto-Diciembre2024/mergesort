#include <iostream>
#include <vector>

using namespace std;


void merge(vector<int>& vec,int left,int mid,int right) {
    int sizeLeft=mid-left + 1;
    int sizeRight=right-mid;
    vector<int> left_temp(sizeLeft);
    vector<int> right_temp(sizeRight);
    for(int i=0;i< sizeLeft;i++) {
        left_temp[i]=vec[left+i];
    }
    for(int j=0;j<sizeRight;j++) {
        right_temp[j]=vec[mid+j+1];
    }
    int leftIndex=0;
    int rightIndex=0;
    int originalIndex=left;

    while(leftIndex<sizeLeft && rightIndex<sizeRight) {
        if(left_temp[leftIndex]<=right_temp[rightIndex]) {
            vec[originalIndex]=left_temp[leftIndex];
            leftIndex++;
        }else {
            vec[originalIndex]=right_temp[rightIndex];
            rightIndex++;
        }
        originalIndex++;
    }

    while(leftIndex<sizeLeft) {
        vec[originalIndex]=left_temp[leftIndex];
        leftIndex++;
        originalIndex++;
    }
    while(rightIndex<sizeRight) {
        vec[originalIndex]=right_temp[rightIndex];
        rightIndex++;
        originalIndex++;
    }
}

void mergeSort(vector<int>& vec,int left,int right) {
    if(left<right) {
        int mid=left + (right-left) / 2;
        mergeSort(vec,left,mid);
        mergeSort(vec,mid+1,right);
        merge(vec,left,mid,right);
    }
}
void printVector(vector<int>& vec) {
    int size=vec.size();
    cout<<"[";
    for(int i=0;i<size;i++) {
        cout<<vec[i]<<",";
    }
    cout<<"]"<<endl;
}
int main() {
    vector<int> vec={5,2,3,1,8,4,7,6};
    printVector(vec);

    mergeSort(vec,0,vec.size()-1);
    printVector(vec);

    return 0;
}
