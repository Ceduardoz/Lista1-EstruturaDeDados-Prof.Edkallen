#include <stdio.h>
#include "retangulo.h"

float calcular_area(Retangulo r){
    return r.base * r.altura;
}

float calcular_perimetro(Retangulo r){
    return 2 * (r.base + r.altura);
}

void exibir_retangulo(Retangulo r){
    printf("Base......: %.2f\n", r.base);
    printf("Altura....: %.2f\n", r.altura);
    printf("Area......: %.2f\n", calcular_area(r));
    printf("Perimetro.: %.2f\n", calcular_perimetro(r));
}