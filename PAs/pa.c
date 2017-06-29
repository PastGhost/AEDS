#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct sp {
	int mana;
	int dano;
	double cb;
}spell;

void swap(spell *a,spell *b) {
	spell *c = a;
	a = b;
	b = c;
}

void heapify(spell arr[], int n, int i) {
	spell aux;
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l].cb > arr[largest].cb)
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r].cb > arr[largest].cb)
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        // swap(&arr[i], &arr[largest]);
        aux = arr[0];
        arr[0] = arr[i];
        arr[i] = aux;
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(spell arr[], int n) {
	spell aux;
	int i;
    // Build heap (rearrange array)
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (i=n-1; i>=0; i--)
    {
    	// printf("======= cb %lf=============\n",arr[0].cb);
        // Move current root to end
        // swap(&arr[0], &arr[i]);
        aux = arr[0];
        arr[0] = arr[i];
        arr[i] = aux;
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}


int min(int a,unsigned int b) {
	if(a>b)
		return b;
	else
		return a;
}


// unsigned int min_mana(spell ord[],int sp,int pos, int restante) {
// 	unsigned int aux;
// 	printf("======= cb %lf %d=============\n",ord[pos].cb,restante);
// 	if(restante <= 0)
// 		return 0;
// 	if(pos >= sp)
// 		return INT_MAX;
// 	if(ord[pos].dano>restante) {
// 		aux = min(ord[pos].mana,min_mana(ord,sp,pos + 1,restante));;
// 		printf("=============%u==========\n",aux);
// 		return aux;
// 	}
// 	else
// 		return ord[pos].mana + min_mana(ord,sp,pos + 1,restante - ord[pos].dano);
// }

unsigned int min_mana(spell ord[],int pos, int restante) {
	unsigned int aux;
	// printf("======= cb %lf %d=============\n",ord[pos].cb,restante);
	if(restante <= 0)
		return 0;
	if(pos < 0)
		return INT_MAX;
	if(ord[pos].dano>restante) {
		aux = min(ord[pos].mana,min_mana(ord,pos - 1,restante));;
		// printf("=============%u==========\n",aux);
		return aux;
	}
	else
		return ord[pos].mana + min_mana(ord,pos - 1,restante - ord[pos].dano);
}


int main () {
	unsigned int vida,spc, i, danot,manat;
	spell ord[1000];
	while(scanf("%u %u",&spc,&vida) > 1) {
		// printf("====%d===\n",vida);
		danot = 0;
		manat = 0;
		for(i=0;i<spc;i++){
			scanf("%d %d",&ord[i].dano,&ord[i].mana);
			ord[i].cb = ((double) ord[i].mana)/ord[i].dano;
			// ord[i].cb = ((double) ord[i].dano)/ord[i].mana;
			// printf("====%lf===\n",ord[i].cb);
			danot += ord[i].dano;
			manat += ord[i].mana;
		}
		if(danot < vida)
			printf("-1\n");
		else if(danot == vida)
			printf("%u\n",manat);
		else {
			heapSort(ord,spc);
			// printf("%u\n",min_mana(ord,spc,0,vida));
			printf("%u\n",min_mana(ord,spc-1,vida));
		}
		
	}
	
}