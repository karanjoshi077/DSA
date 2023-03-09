#include<stdio.h>
#include<stdlib.h>
#include <time.h>
double bubble(int a[],int n){
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;  
    return cpu_time_used;
}

int main(){
    int n=10000;
    while(n<=100000){
    int a[n];
     for(int i=0;i<n;i++){
        a[i]=rand()%100;
     }
     for(int i=0 ; i<n ; i++){
        printf("%d \t" , a[i]);
     }
     printf("\nsorted array\n");
     
    double time=bubble(a,n);
     for(int i=0 ; i<n ; i++){
        printf("%d\t" , a[i]);
     }
  
   FILE *fptr;
   fptr = fopen("time.csv","a+");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   fprintf(fptr,"\n%d,",n);
   fprintf(fptr,"%f\n", time);
   n+=10000;
    }
    return 0;
}