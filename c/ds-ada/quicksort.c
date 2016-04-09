#include<stdio.h>
int partition(float a[],int left,int right){
  int i,j,t;
  float x=a[right];//pivot element x
  i=left - 1;
  for(j=left;j<=right;j++){
    if(a[j]<x){
      i=i+1;
      //swap a[j] and a[i]
     
      t=a[i];
      a[i]=a[j];
      a[j]=t;
    }  
  }
  //swap a[i] with a[r]
      t=a[i+1];
      a[i+1]=a[right];
      a[right]=t;
      return i+1;

}

void quicksort(float a[],int l,int r){
  if(l<r){
    int q=partition(a,l,r);
    quicksort(a,l,q-1);
    quicksort(a,q+1,r);
  }
}



int main(){
  printf("Enter the number of elements to be entered in array");
  int n;
  scanf("%d",&n);
  float a[n];
  int i=0;

  while(i<n){
    fprintf(stdout,">");
    fscanf(stdin,"%f",&a[i]);
    i++;
  }
  i=0;
  quicksort(a,0,n-1);
  fprintf(stdout,"The arraya after sorting is");
  while(i<n){
    fprintf(stdout,"\n\n%f\t\n\n",a[i]);
    i++;
  }
  return 0;
}



