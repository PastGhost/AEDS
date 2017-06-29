#include <stdio.h>

int max(int a, int b) { return (a > b)? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W

int knapsack(int W, int wt[], int val[], int n)

{

   int i, w;

   int K[n+1][W+1];

 

   // Build table K[][] in bottom up manner

   for (i = 0; i <= n; i++)

   {

       for (w = 0; w <= W; w++)

       {

           if (i==0 || w==0)

               K[i][w] = 0;

           else if (wt[i-1] <= w)

                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);

           else

                 K[i][w] = K[i-1][w];

       }

   }

 

   return K[n][W];

}

int main () {
  int vida,spc, i, danot,manat;
  int dano[1000],mana[1000];
  while(scanf("%u %u",&spc,&vida) > 1) {
    // printf("====%d===\n",vida);
    danot = 0;
    manat = 0;
    for(i=0;i<spc;i++){
      scanf("%d %d",&dano[i],&mana[i]);
      // ord[i].cb = ((double) ord[i].dano)/ord[i].mana;
      // printf("====%lf===\n",ord[i].cb);
      danot += dano[i];
      manat += mana[i];
    }
    if(danot < vida)
      printf("-1\n");
    else if(danot == vida)
      printf("%u\n",manat);
    else {
      printf("%d\n",manat - knapsack(danot - vida,dano,mana,spc));
    }
    
  }
  
}