/*
    Hudson Henrique da Silva | RA:128849
    Vitor Azevedo Padovani | RA: 128169
    data: 17/10/24
*/

#include<stdio.h>
#include<math.h>
#include"const.h"
#include"calc.h"

int main() {

    double base;
    int exp;

    printf("base: ");
    scanf("%lf", &base);
    printf("exp: ");
    scanf("%i", &exp);
    double func_pow = pow_(base, exp);
    double normal_pow = pow(base, exp);
    printf("função feita: %.2lf\n", func_pow);
    printf("função original: %.2lf\n", normal_pow);
    printf("erro: %.15lf\n", fabs(func_pow-normal_pow));


    double func_sin = sin_(PI/4);
    double normal_sin = sin(PI/4);
    double err_sin = fabs(func_sin - normal_sin);
    printf("sin original: %.30lf\n", normal_sin);
    printf("sin feito: %.30lf\n", func_sin);
    printf("erro sin: %.30lf\n", err_sin);

    angle_reduction(PI/2);

    verifica(((double)1)/fat_(3), K3);
    printf("1/3!: %.20lf\n", 1/fat_(3));
    printf("K3: %.20lf\n\n", K3);

    printf("fat: %d\n", fat_(5));

    printf("COSSSENO");

    return 0;
}

