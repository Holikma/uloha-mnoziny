#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int dlzka;
    int *pole;
}ZOZNAM;


void destructList(ZOZNAM* list) {
	free(list->pole);
	list->pole = NULL;
    list->dlzka = 0;

}

// vypis mnoziny
void printlist(ZOZNAM *z){
    for(int i = 0; i < z->dlzka; i++){
        printf("%i ", z->pole[i]);
    }
    printf("\n");
}

// zjednotenie linearny čas
int unionlists(ZOZNAM* un, ZOZNAM *zoz1, ZOZNAM *zoz2){
	un->dlzka = zoz1->dlzka + zoz2->dlzka;
	un->pole = (int*)malloc(un->dlzka*sizeof(int));
	if(un->pole == NULL){
        return -1;
    }
	int j = 0;
	for(int i = 0; i < zoz1->dlzka; i++){
		un->pole[j] = zoz1->pole[i];
  	j++;  
  	}
  	for(int i = 0; i < zoz2->dlzka; i++){
  		un->pole[j] = zoz2->pole[i];
  	j++;
	return 1;
  }
}
// binary search
int binarySearch(ZOZNAM *zoz, int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;
    if (zoz->pole[mid] == x) return mid;
    if (zoz->pole[mid] > x) return binarySearch(zoz, x, low, mid - 1);
    return binarySearch(zoz, x, mid + 1, high);}
	return -1;
}

// prazdna mnozina dlzky n
int emptylist(ZOZNAM* n, int d){
    n->dlzka = d;
    n->pole = (int*)malloc(n->dlzka*sizeof(int));
	if (n->pole == NULL){
        return -1;
    }
    
    for (int i = 0; i < n->dlzka; i++){
        n->pole[i] = 0;
    }
}

// pridat prvok na koniec
int funkcia_append(ZOZNAM *zoz, int prvok){
    int *new_ptr = realloc(zoz->pole, sizeof *(zoz->pole) * (zoz->dlzka + 1u));
	if (new_ptr == NULL) {
        return -1;
	}
	zoz->pole = new_ptr;
	zoz->pole[zoz->dlzka] = prvok;
	zoz->dlzka++;
}

// mergesort v C
int merge(int *arr, int l, int m, int r){
    int k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int*)malloc(n1*sizeof(int));
	int *R = (int*)malloc(n2*sizeof(int));
	if (L == NULL || R == NULL) {
        return -1;
    }

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
        i++; k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++; k++;
    }
	free(L);
	free(R);
}
void mergeSort(ZOZNAM *arr, int l, int r){
    if (l < r){
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr->pole, l, m, r);
    }
}

// prienik lineárny čas - output nová množina na pozícií *
 int intersection(ZOZNAM* inter, ZOZNAM *zoz1, ZOZNAM *zoz2){
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
	inter->dlzka = count;
	inter->pole = (int*)malloc(inter->dlzka*sizeof(int));
	if (inter->pole == NULL){
		return -1;
    }
	count = 0; index1 = 0; index2 = 0;
	for (int i = 0; i < zoz1->dlzka + zoz2->dlzka; i++){
		if (zoz1->pole[index1] == zoz2->pole[index2]){
			inter->pole[count] = zoz1->pole[index1];
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
}

// odstranit prvok 
void pop(ZOZNAM *zoz){
	memmove(zoz, zoz->pole+1, zoz->dlzka--*sizeof(int));
}

int main(){
    ZOZNAM zoznam;
    zoznam.dlzka = 5;
    zoznam.pole = (int*)malloc(zoznam.dlzka*sizeof(int));
	if (zoznam.pole != NULL){
		for(int i = 0; i < zoznam.dlzka; i++){
			if (i % 2 == 0){
				zoznam.pole[i] = -i;
			}
			else{
				zoznam.pole[i] = i;
			}
		}
		puts("nový zoznam:");
    	printlist(&zoznam);

	}
//	
	if (zoznam.pole != NULL){
		puts("append function:");
    	funkcia_append(&zoznam, 5);
		funkcia_append(&zoznam, 8);
    	printlist(&zoznam);
	}
//
    int hladaj = 5;
	if (zoznam.pole != NULL){
	    printf("Cislo %i je na indexe: %i\n",hladaj,  binarySearch(&zoznam, hladaj, 0, zoznam.dlzka));
	}
    ZOZNAM k;
	emptylist(&k, 5);
//
	
	puts("empty list:");
	printlist(&k);
//
	puts("union list empty list a nového listu:");
	ZOZNAM uni; 
	unionlists(&uni, &k, &zoznam);
	printlist(&uni);
//
	puts("mergesort listu:");
	printlist(&zoznam);
	mergeSort(&zoznam, 0, zoznam.dlzka-1);
	printlist(&zoznam);
//
	ZOZNAM new;
	new.dlzka = 3;
	new.pole = (int*)malloc(new.dlzka*sizeof(int));
	if (new.pole == NULL){
		return -1;
	}
	for(int i = 0; i < new.dlzka; i++){
		new.pole[i] = i;
	}
	puts("intersection list nového listu a new listu:");
	printlist(&zoznam);
	printlist(&new);
//
	puts("prienik:");
	ZOZNAM intersect;
	intersection(&intersect, &zoznam, &new);
	printlist(&intersect);
//
	puts("delete intersect last item and return list:");
	pop(&intersect);
	printlist(&intersect);
    destructList(&zoznam);
	destructList(&new);
	destructList(&intersect);
	destructList(&uni);
	destructList(&k);
//
	puts("delete all lists:");
	printlist(&zoznam);
	printlist(&intersect);
	printlist(&new);
	printlist(&uni);
	printlist(&k);
}