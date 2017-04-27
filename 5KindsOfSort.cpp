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
    void merge_sort(int* a,int start,int middle,int end,int* temp){  //对排好序的左右区间进行合并
        int i=start;
        int j=middle+1;
        int k = start;
        while(i<=middle && j<= end){   //判断从左区间和右区间取出的数哪个更小，将其存入合并序列，并继续向下扫描
            if(a[i]<a[j])
                temp[k++] = a[i++];
            else
                temp[k++] = a[j++];
        }
        while(i <= middle){  //合并后，左区间还没扫描完，将其全部复制到合并序列
            temp[k++]=a[i++];
        }
        while(j <= end){     //合并后，右区间还没扫描完，将其全部复制到合并序列
            temp[k++] = a[j++];
        }
        for(int i=start;i<=end;++i){  //将合并序列复制到原始序列中
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

/*
(3)快速排序
对于一个int数组，请编写一个快速排序算法，对数组元素排序。
给定一个int数组A及数组的大小n，请返回排序后的数组。
测试样例：
[1,2,3,5,2,3],6
[1,2,2,3,3,5]
*/

class QuickSort {
public:
    void quickSort_ab(int* a,int start,int end){ //递归
        if(start < end){
            int mid = partition(a,start,end);  //找一个随机数，将其他数按照随机数
            quickSort_ab(a,start,mid);
            quickSort_ab(a,mid+1,end);
        }
    }
    
    int partition(int* A,int start,int end){    
        int target = A[start];
        int l = start,r = end;
        while(l < r){
            while (l < r && A[r] >= target)
                r--;
            if (l < r) A[l++] = A[r];
            while (l < r && A[l] <= target)
                l++;
            if (l < r) A[r--] = A[l];
        }
        A[l] = target;
        return l;
    }
    int* quickSort(int* A, int n) {
        // write code here
        if(A == NULL || n<2)
            return A;
        quickSort_ab(A,0,n-1);
        return A;
    }
};
