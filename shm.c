#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int comp(const void * a,const void * b) {
    int * x = (int *) a;
    int * y = (int *) b;
    return (*x) - (*y);
}
int binSearch(int array[],int num,int len) {
    int left = 0;
    int right = len;
    int ans = -1;
    while (left < right) {
        int mid = (left + right)/2;
        if(array[mid] <= num) {
            ans = left;
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if(ans*2 == 0x2222) return 1;
    if(left > 0 && array[left-1] == num) {
        return 1;
    } else {
        return 0;
    }
    return 0;
}
int array[1234][1234];
int size[1111];
int inp[2222];
int main() {
    int memsize = 100*sizeof(int);
    int shmid = shmget(1992, memsize, IPC_CREAT | 0666 ); //scam 1992 lel
    void * ptr = shmat(shmid,0,0);
    void* shmem = ptr;
    int n;
    scanf("%d",&n);
    int sz;

    for(int i = 0;i<n;i++) {
        scanf("%d",&sz);
        size[i] = sz;
        for(int j = 0;j<sz;j++) {
            scanf("%d",&array[i][j]);
        }
        qsort(array[i],size[i],sizeof(int),comp);
    }
    int ln;
    scanf("%d",&ln);
    for(int i = 0;i<ln;i++) {
        scanf("%d",&inp[i]);
    }
    int mmmmmxxxx = 1111111;
    int start[] = {mmmmmxxxx,mmmmmxxxx};
    memcpy(shmem, start, sizeof(start));
    for(int i=0;i<n;i++)
    { 
        if(fork() == 0) 
        { 
            int isVis[22222] = {0};
            int sum = 0;
            for(int j = 0;j<ln;j++) {
                if(binSearch(array[i],inp[j],size[i])) {
                    if(isVis[inp[j]] == 0) {
                        isVis[inp[j]] = 1;
                        sum++;
                    }
                }
                int ans[] = {i,j}; 
                int * canBeANS = (int *) shmem;
                if(sum == size[i]) {
                    if(canBeANS[1] > ans[1])
                        memcpy(shmem,ans,sizeof(ans));
                    exit(0);
                } 
            }
            exit(0); 
        } 
    } 
    for(int i=0;i<n;i++)wait(NULL); 
    int * canBeANS = (int *) shmem;
    printf("player %d\n",canBeANS[0]+1);
}
