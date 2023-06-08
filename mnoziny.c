#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int dlzka;
    int *pole;
}ZOZNAM;

ZOZNAM nahodne_pole(int k){

}
// zjednotenie linearny čas
// prienik lineárny čas - output nová množina na pozícií *
// prazdna mnozina dlzky n
// binary search
// pridat prvok na koniec
// odstranit prvok 
// vypis mnoziny
// mergesort v C


ZOZNAM funkcia_append(ZOZNAM *z){
    z->dlzka++;
    z->pole = (int*)malloc(z->dlzka * sizeof(int));
    return *z;
}

void printlist(ZOZNAM z){
    for(int i = 0; i < z.dlzka; i++){
        printf("%d ", z.pole[i]);
    }
}
int main(){
    ZOZNAM zoznam;
    zoznam.dlzka = 3;
    zoznam.pole = (int*)malloc(zoznam.dlzka*sizeof(int));
    for(int i = 0; i < zoznam.dlzka; i++){
        zoznam.pole[i] = i;
    }
    
    printf("dlzka pred funkciou: %d\n", zoznam.dlzka);
    funkcia_append(&zoznam);
    printf("dlzka po funkcii: %d\n", zoznam.dlzka);
    printf("mnozina:");
    printlist(zoznam);
    printf("\n");
    free(zoznam.pole);
}