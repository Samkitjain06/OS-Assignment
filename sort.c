#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
int a[54321];
int b[12345];
typedef struct params {
    int left;int right;
} params;
params * newParams(int left,int right) {params * new = (params *) malloc(sizeof(params));new->left = left;new->right = right;return new;}
void * mergesort(void * arg) {
    params * params1 = (params *) arg;
    int left = params1->left;
    int right = params1->right;
    if(left == right) return NULL;
    pthread_t thr1,thr2;
    int mid = (left + right)/2;
    params * arg1,* arg2;
    arg1 = newParams(left,mid);
    arg2 = newParams(mid+1,right);
    if(pthread_create(&thr1,NULL,mergesort,arg1) > 0) return NULL;
    if(pthread_create(&thr2,NULL,mergesort,arg2) > 0) return NULL;
    pthread_join(thr1,NULL);pthread_join(thr2,NULL);
    int k = left ,i = left ,j = mid+1;
    while (i<=mid && j<=right){
        if (a[i] < a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    for (;i<=mid;i++) b[k++] = a[i];
    for (;j<=right;j++) b[k++] = a[j];
    for (i=left;i<=right;i++) a[i] = b[i];
    return NULL;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++) scanf("%d",&a[i]);
    params * init = newParams(0,n-1);
    mergesort(init);
    for(int i = 0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
}