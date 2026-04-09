#include<stdio.h>

void mergeSort(int a[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void merge(int a[],int low,int mid,int high){
    int i=low,j=mid+1,c[20],k=low;
    while(i<=mid && j<=high){
        if(a[i]<a[j]) c[k++]=a[i++];
        else c[k++]=a[j++];
    }
    while(i<=mid) c[k++]=a[i++];
    while(j<=high) c[k++]=a[j++];
    for(i=low;i<=high;i++) a[i]=c[i];
}

int main(){
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements:");
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    mergeSort(a,0,n-1);
    printf("Array elements after sorting:\n");
    for(int i=0;i<n;i++) printf("%d\t",a[i]);
    return 0;
}
