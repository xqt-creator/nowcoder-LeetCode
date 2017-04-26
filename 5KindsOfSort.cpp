/*
插入排序：
对于一个int数组，请编写一个插入排序算法，对数组元素排序。
给定一个int数组A及数组的大小n，请返回排序后的数组。
测试样例：
[1,2,3,5,2,3],6
[1,2,2,3,3,5]
*/

class InsertionSort {
public:
    int* insertionSort(int* A, int n) {
        // write code here
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){                   //这里从前往后 依次与固定位置值比较的形式，
                if(A[j]>A[i]){
                    int temp = A[j];
                    A[j] = A[i];
                    A[i] = temp;
                }
            }
        }
        return A;
    }
};
/*
插入排序 用从后往前比较的方式
*/
class InsertionSort {
public:
    int* insertionSort(int* A, int n) {
        // write code here
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(A[j]>A[j+1]){
                    int temp = A[j+1];
                    A[j+1] = A[j];
                    A[j] = temp;
                }
            }
        }
        return A;
    }
};
