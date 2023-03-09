#include<stdio.h>
#include<stdlib.h>
#include <time.h>
double insertion(int a[],int n){
    clock_t start, end;
     int i,k,j;
    double cpu_time_used;
    start = clock();
    for(i=1;i<n;i++)
    {
        k=a[i];
        j=i-1;
        while(j>=0)
        {
            if(a[j]>k)
            {
                a[j+1]=a[j];
                j=j-1;
            }
        }
        a[j+1]=k;
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
     
    double time=insertion(a,n);
     for(int i=0 ; i<n ; i++){
        printf("%d " , a[i]);
     }
  
   FILE *fptr;
   fptr = fopen("time2.csv","a+");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   fprintf(fptr,"\n%d,",n);
   fprintf(fptr,"%f\n", time);
   fclose(fptr);
   n+=10000;
    }
    return 0;
}