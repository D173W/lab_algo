#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;

    unsigned int pos;
    bool es_mayor;
    bool es_menor;
    bool esta_en;
    unsigned int pos_arr;
    pos = 0;
    es_mayor = false;
    es_menor = false;
    esta_en = false;
    /*Obtencion res*/
    while (pos < length) {
        if (value >= arr[pos]) {
            es_mayor = true;
        }
        else {
            es_mayor = false;
        }
        
        if (value <= arr[pos]) {
            es_menor = true;
        }
        else {
            es_menor = false;
        }

        if (value == arr[pos]) {
            esta_en = true;
            pos_arr = pos;
        }
        pos = pos + 1;
    }
    /*Output*/
    res.is_upperbound = es_mayor;
    res.is_lowerbound = es_menor;
    res.exists = esta_en;
    res.where = pos_arr; 
    return res;
}

int main(void) {
    int a[ARRAY_SIZE];
    int pos;
    int aux;
    struct bound_data res;
    pos = 0;
    /*Pedir entrada al user*/
    while (pos < ARRAY_SIZE)
    {
        printf("Brinde un valor para el elemento %d del arreglo\n", (pos+1));
        scanf("%d", &aux);
        a[pos] = aux;
        pos = pos + 1;
    }
    printf("Brinde un valor para aplicar la funcion check_bound()");
    scanf("%d", &aux);
    res = check_bound(aux, a, ARRAY_SIZE);
    /*Impresion de Resultado*/
    printf("Es cota superior = %d\n", res.is_upperbound);
    printf("Es cota inferior = %d\n", res.is_lowerbound);
    if (res.exists == true) {
        printf("Existe en el arreglo y está en la posicion %u\n", res.where);
    } else {
        printf("No existe en el arreglo");
    }
    
    return 0;
}

