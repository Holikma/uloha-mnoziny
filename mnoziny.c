#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int dlzka;
    int *pole;
}ZOZNAM;



// vypis mnoziny
void printlist(ZOZNAM z){
    for(int i = 0; i < z.dlzka; i++){
        printf("%i ", z.pole[i]);
    }
    printf("\n");
}

// zjednotenie linearny čas
ZOZNAM unionlists(ZOZNAM *zoz1, ZOZNAM *zoz2){
	ZOZNAM uni;
	uni.dlzka = zoz1->dlzka + zoz2->dlzka;
	uni.pole = (int*)malloc(uni.dlzka*sizeof(int));
	int j = 0;
	for(int i = 0; i < zoz1->dlzka; i++){
		uni.pole[j] = zoz1->pole[i];
  	j++;  
  	}
  	for(int i = 0; i < zoz2->dlzka; i++){
  		uni.pole[j] = zoz2->pole[i];
  	j++;
  }
  return uni;
}
// binary search
int binarySearch(ZOZNAM *zoz, int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (zoz->pole[mid] == x)
      return mid;

    // Search the left half
    if (zoz->pole[mid] > x)
      return binarySearch(zoz, x, low, mid - 1);

    // Search the right half
    return binarySearch(zoz, x, mid + 1, high);
  	}

	return -1;
}

// prazdna mnozina dlzky n
ZOZNAM emptylist(int d){
    ZOZNAM z;
    z.dlzka = d;
    z.pole = (int*)malloc(z.dlzka*sizeof(int));
    for (int i = 0; i < z.dlzka; i++){
        z.pole[i] = 0;
    }
    return z;
}

// pridat prvok na koniec
void funkcia_append(ZOZNAM *zoz, int prvok){
    int *new_ptr = realloc(zoz->pole, sizeof *(zoz->pole) * (zoz->dlzka + 1u));
    zoz->pole = new_ptr;
    zoz->pole[zoz->dlzka] = prvok;
    zoz->dlzka++;
}


// mergesort v C
void merge(int *arr, int l, int m, int r){
    int k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int*)malloc(n1*sizeof(int));
	int *R = (int*)malloc(n2*sizeof(int));
	

    for (int i = 0; i < n1; i++){
        L[i] = arr[l + i];
	}

    for (int j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
	}

    int i = 0;
    int j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
	free(R);
	free(L);
}
void mergeSort(int *arr, int l, int r){
    if (l < r){
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// prienik lineárny čas - output nová množina na pozícií *
ZOZNAM intersection(ZOZNAM *zoz1, ZOZNAM *zoz2){
	int count = 0;
	int index1 = 0;
	int index2 = 0;
	for (int i = 0; i < zoz1->dlzka + zoz2->dlzka; i++){
		if (zoz1->pole[index1] == zoz2->pole[index2]){
			index1++; index2++; count++;
		}
		else if (zoz1->pole[index1] > zoz2->pole[index2]){
			index2++;
		}
		else{
			index1++;
		}
	}

	ZOZNAM inter;
	inter.dlzka = count;
	inter.pole = (int*)malloc(inter.dlzka*sizeof(int));
	count = 0;index1 = 0; index2 =0;
	for (int i = 0; i < zoz1->dlzka + zoz2->dlzka; i++){
		if (zoz1->pole[index1] == zoz2->pole[index2]){
			inter.pole[count] = zoz1->pole[index2];
			index1++; 
			index2++;
			count++;
		}
		else if (zoz1->pole[index1] > zoz2->pole[index2]){
			index2++;
		}
		else{
			index1++;
		}
	}
	printf("%i\n", count);
	return inter;
}
// odstranit prvok 
void pop(ZOZNAM *zoz){
	memmove(zoz, zoz->pole+1, zoz->dlzka--*sizeof(int));
}
int main(){
    ZOZNAM zoznam;
    zoznam.dlzka = 3;
    zoznam.pole = (int*)malloc(zoznam.dlzka*sizeof(int));
    for(int i = 0; i < zoznam.dlzka; i++){
		if (i % 2 == 0){
			zoznam.pole[i] = -i;
		}
		else{
        	zoznam.pole[i] = i;
		}
    }
    //printlist(zoznam);
    //funkcia_append(&zoznam, 5);
    //printlist(zoznam);
    //int hladaj = 5;
    //printf("Cislo %i je na indexe: %i\n",hladaj,  binarySearch(&zoznam, hladaj, 0, zoznam.dlzka));
    //ZOZNAM k = emptylist(5);
	//printlist(k);
	//ZOZNAM uni = unionlists(&k, &zoznam);
	//printlist(uni);
	//mergeSort(zoznam.pole, 0, zoznam.dlzka);
	//printlist(zoznam);
	ZOZNAM new;
	new.dlzka = 3;
	new.pole = (int*)malloc(new.dlzka*sizeof(int));
	for(int i = 0; i < new.dlzka; i++){
		new.pole[i] = i;
    }
	printlist(zoznam);
	printlist(new);
	ZOZNAM intersect = intersection(&zoznam, &new);
	printlist(intersect);
	pop(&intersect);
	printlist(intersect);
	printf("%i", intersect.dlzka);
    free(zoznam.pole);
}