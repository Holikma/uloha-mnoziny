#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int dlzka;
    int *pole;
}ZOZNAM;

// prienik lineárny čas - output nová množina na pozícií *
// odstranit prvok 
// mergesort v C


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

int main(){
    ZOZNAM zoznam;
    zoznam.dlzka = 3;
    zoznam.pole = (int*)malloc(zoznam.dlzka*sizeof(int));
    for(int i = 0; i < zoznam.dlzka; i++){
        zoznam.pole[i] = i+1;
    }
    printlist(zoznam);
    funkcia_append(&zoznam, 5);
    printlist(zoznam);
    printf("%i", zoznam.dlzka);
    int hladaj = 5;
    printf("Cislo %i je na indexe: %i\n",hladaj,  binarySearch(&zoznam, hladaj, 0, zoznam.dlzka));
    ZOZNAM k = emptylist(5);
	printlist(k);
	// zjednotenie sa robí síce v lineárnom čase, ale potom treba sortnuť finálne pole, ak byboli polia už sortnuté, tak sa použije 
	// algoritmus, ktorý porovnáva jednotlivé prvky polí pomocou indexov a menší vloží do nového pola, ale keďže máme aj funkciu na sort, 
	// tak som sa rozhodol použiť jednoduchší spôsob.
	ZOZNAM uni = unionlists(&k, &zoznam);
	printlist(uni);
    free(zoznam.pole);
}