#include<stdio.h> // printf para teste da função

#include<math.h>
#include"const.h"
#include"calc.h"

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
    return (rad * (1 + rad2*(-K3+rad2*(K5+rad2*(-K7+rad2*(K9+rad2*(-K11)))))));
}

double calculate_sin(double rad) {
    return ((rad <= PI/4) && (rad >= -PI/4)) ? sin_(rad) : angle_reduction(rad);
}

// cos hardcoded com 7 termos 
double cos_(double rad) {
    double rad2 = rad*rad;
    return (1+rad2*(-K2+rad2*(K4+rad2*(-K6+rad2*(K8+rad2*(-K10+rad2*(K12)))))));
}

double angle_reduction (double x) {
    if ((x <= PI/4) && (x >= -PI/4)) return x; // x dentro do intervalo de confiança

    // redução aditiva
    // K = (X - X*)/C
    double k = ceil((x - MAX_VALUE) * Cinverso);
    // printf("ceil: %.5lf\n", k);
    // X* = X - K.C
    double reducted = x - (k*C);
    return cos_(reducted);
}

double exp_maclaurin(double x) {
    // Usando o método de Horner
    return 1 + x * (1 + x * (K2 + x * (K3 + x * (K4 + x * (K5 + x * (K6 + x * K7))))));
}