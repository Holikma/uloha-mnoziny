#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int dlzka;
    int *pole;
}ZOZNAM;

// zjednotenie linearny čas
// prienik lineárny čas - output nová množina na pozícií *
// binary search
// odstranit prvok 
// mergesort v C


// vypis mnoziny
void printlist(ZOZNAM z){
    for(int i = 0; i < z.dlzka; i++){
        printf("%i ", z.pole[i]);
    }
    printf("\n");
}

// prazdna mnozina dlzky n
ZOZNAM emptylist(int d){
    ZOZNAM z;
    z.dlzka = d;
    z.pole = (int*)malloc(z.dlzka*sizeof(int));
    for (int i = 0; i < z.dlzka; i++){
        z.pole[i] = 0;
    }
    printlist(z);
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
    ZOZNAM k = emptylist(5);
    free(zoznam.pole);
}