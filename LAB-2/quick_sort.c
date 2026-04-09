#include<stdio.h>
void quickSort(int a[],int low,int high){
    if(low<high){
        int p=partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}

int partition(int a[],int low,int high){
    int i,j,temp,pivot;
    pivot=a[low];
    i=low+1;
    j=high;
    while(i<=j){
        while(a[i]<pivot) i++;
        while(a[j]>pivot) j--;
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    a[low]=a[j];
    a[j]=pivot;
    return j;
}
int main(){
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter array elements:");
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    quickSort(a,0,n-1);
    printf("\nArray elements after sorting:\n");
    for(int i=0;i<n;i++) printf("%d\t",a[i]);
    return 0;
}
