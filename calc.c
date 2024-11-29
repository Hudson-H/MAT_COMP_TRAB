#include<stdio.h> // printf para teste da função

#include<math.h>
#include"const.h"
#include"calc.h"

// função calcula fatorial :P
long fat_(int num) {
    long res = 1;
    while(num > 1) {
        res *= num;
        num--;
    }

    return num;
}

// verifica as condições pra usar horner
double pow_(double base, int exp) {
    if(!base && !exp) { // base = 0, exp = 0
        return NAN;
    } else if(!base && exp<0) { // base = 0, exp < 0
        return INFINITY;
    } else if(!base && exp>0) { // base = 0, exp > 0
        return 0;
    } else if(base == 1 || (base && !exp)) { // (base = 1) ou (base != 1, exp = 0)
        return 1;
    } else if (exp == 1) { // exp = 1, base pertencendo aos reais
        return base;
    } else if(base && exp<0) { // base != 0, exp < 0
        return 1 / pow_calc(base, -exp);
    } else if(exp <= 3){ // exp = 3 é o máximo possível que não precisa usar o método de horner.
        return exp == 2 ? base*base : base*base*base;
    }
    return pow_calc(base, exp);
}

// calcula o fatorial com horner
double pow_calc(double base, int exp) {
    // acumulador
    double res = 1;

    while(exp > 0) {
        if(exp & 1) { // exp é ímpar?
            res *= base; // multiplicação em evidência
        }

        base *= base;
        exp = exp >> 1;
    }

    return res;
}


// sin hardcoded com *10 TERMOS* (todo: mudar para 6 termos)
double sin_(double rad) {
    double rad2 = rad*rad;
    return (rad * (1 + rad2*(-K3+rad2*(K5+rad2*(-K7+rad2*(K9+rad2*(-K11+rad2*(K13 + rad2*(-K15+rad2*(K17+rad2*(-K19)))))))))));
}

// cos hardcoded com 7 termos 
double cos_(double rad) {
    double rad2 = rad*rad;
    return (1-rad2*(K2+rad2*(K4-rad2*(K6+rad2*(K8-rad2*(K10+rad2*(K12)))))));
}

double angle_reduction (double x) {
    if ((x <= PI/4) && (x >= -PI/4)) return x; // x dentro do intervalo de confiança

    // double reducted = x - PI/2; // reducted é o tal do x*

    // redução aditiva
    // K = (X - X*)/C
    double k = ceil((x - MAX_VALUE) * Cinverso);
    printf("K: %.3lf\n", k);
    // X* = X - K.C
    double reducted = x - (k*C);

    printf("reducted: %.12f\n", reducted);
    printf("cos: %.12lf\n", cos_(reducted));
    printf("cos: %.12lf\n", cos(reducted));
}
