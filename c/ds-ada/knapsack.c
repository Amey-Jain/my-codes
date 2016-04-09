#include<stdio.h>

int max(float arr[],int start,int end){
  //returns the index of the max element
  float m=arr[start];
  int i=start,mi=start;
  for(i;i<end;i++){
    if(m<arr[i]){
      m=arr[i];
      mi=i;
    }
  }
  return mi;
}

struct resultset{
  int items;
  int result[100][2];
  int index;//index for items counter
  int profit;
};

struct resultset knap(int pw[][2],int capacity,int items){
  struct resultset res;  
  float score[items];
  int profit,weight;
  profit=weight=0;
  res.items=items;

  int i,j;
  j=0;
  for(i=0;i<items;i++){
    score[i] = (pw[i][0])/(pw[i][1]);
  }
  while(weight<=capacity){
    int index;
    index=max(score,0,items);
    if(weight + pw[index][1] <= capacity){
      profit=profit + pw[index][0];
      weight = weight + pw[index][1];
      res.result[j][0]=index;
      res.result[j][1]=1;
      j++;
      //set the bit of last score as -1 to avoid errors
      score[index]=-1;
    }
    else 
      break;
  }
  res.index=j;
  res.profit=profit;
  return res;
  }

int main(){
  int items,cap;
  struct resultset r;
  printf("Enter the number of items to be entered into the knapsack and the capacity of the sack");
  fscanf(stdin,"%d\t%d",&items,&cap);
  int input[items][2];
  int counter=0;
  printf("\tProfit\tWeight\n");
  for(counter;counter<items;counter++)
    { printf("\t");
      fscanf(stdin,"%d\t%d",&input[counter][0],&input[counter][1]);
    }
  counter=0;
  printf("Data you entered\n\tProfit\tWeight\n");
  for(counter;counter<items;counter++)
    { printf("\t");
      printf("%d\t%d\n",input[counter][0],input[counter][1]);
    }
  r=knap(input,cap,items);
  printf("\nThe max profit is %d:",r.profit);
 return 0;
  }
