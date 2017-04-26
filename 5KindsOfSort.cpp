/*
（1）插入排序：
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

/*
（2）归并排序算法：
对于一个int数组，请编写一个归并排序算法，对数组元素排序。
给定一个int数组A及数组的大小n，请返回排序后的数组。
测试样例：
[1,2,3,5,2,3],6
[1,2,2,3,3,5]
*/

class MergeSort {
public:
    void merge(int* a,int start,int end,int* temp){
        if(start < end){
            int middle = (start + end)>>1;  //二进制右移一位，即是除2
            merge(a,start,middle,temp);
            merge(a,middle+1,end,temp);
            merge_sort(a,start,middle,end,temp);
        }
    };
    void merge_sort(int* a,int start,int middle,int end,int* temp){
        int i=start;
        int j=middle+1;
        int k = start;
        while(i<=middle && j<= end){
            if(a[i]<a[j])
                temp[k++] = a[i++];
            else
                temp[k++] = a[j++];
        }
        while(i <= middle){
            temp[k++]=a[i++];
        }
        while(j <= end){
            temp[k++] = a[j++];
        }
        for(int i=start;i<=end;++i){
            a[i] = temp[i];
        }
    };
    int* mergeSort(int* A, int n) {
        // write code here
        if(n<=1)
            return A;
        int* temp = new int[n];  //申请临时数组用于保存每次递归排序后的值
        int* a = A;
        merge(a,0,n-1,temp);
        
        delete[] temp;
        return a;
    }
};


