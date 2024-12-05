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

// cos hardcoded com 7 termos 
double cos_(double rad) {
    double rad2 = rad*rad;
    return (1+rad2*(-K2+rad2*(K4+rad2*(-K6+rad2*(K8+rad2*(-K10+rad2*(K12)))))));
}

double exp_(double x) {
    // Usando o método de Horner
    // return (1+x*(1+x*(K2+x*(K3+x*(K4+x*(K5+x*(K6+x*(K7+x*(K8+x*(K9+x*(K10+x*(K11+x*(K12+x*(K13))))))))))))));
    return (1+x*(1+x*(K2+x*(K3+x*(K4+x*(K5+x*(K6+x*(K7+x*(K8+x*(K9+x*(K10)))))))))));
}

double exp_reduction(double x) {

    double_union expoente = {x};
    expoente.Double.E++;
    double dois_x = expoente.x; // 2*x

    // K = (2*x - LN(2)) / 2ln(2)
    double k = ceil((dois_x - LN2) * UM_SOBRE_DOIS_LN2);

    // r = (x - k.ln(2)) / 256
    double tmp = (x - k * LN2);
    double_union tmp_IEEE = {tmp};
    tmp_IEEE.Double.E-=8;
    double r = tmp_IEEE.x;

    // 2^n(e^r)^256
    double res = exp_(r);
    res = pow_(res, 256);
    double_union res_double = {res};
    res_double.Double.E+=k;
    res = res_double.x; 

    return res;
    
}

double func_cos(double x) {
    if (x < 0) {
        printf("-> angulo negativo!\n");

    } else if (x < PI_SOBRE_QUATRO) {
        return cos_(x);

    } else if (x < TRES_PI_SOBRE_QUATRO) {
        return sin_(-(x - PI_SOBRE_DOIS));

    } else if (x < CINCO_PI_SOBRE_QUATRO) {
        return -(cos_(x - PI));

    } else if (x < SETE_PI_SOBRE_QUATRO) {
        return sin_((x - PI_SOBRE_DOIS) - PI);

    } else if (x < DOIS_PI) {
        return cos_(x - DOIS_PI);
    }

    printf("-> Ta extrapolando ae irmão!\n");
    return 0;
}

double func_sin(double x) {
    if (x < 0) {
        printf("-> angulo negativo!\n");

    } else if (x < PI_SOBRE_QUATRO) {
        return sin_(x);

    } else if (x < TRES_PI_SOBRE_QUATRO) {
        return cos_(-(x - PI_SOBRE_DOIS));

    } else if (x < CINCO_PI_SOBRE_QUATRO) {
        return -(sin_(x - PI));

    } else if (x < SETE_PI_SOBRE_QUATRO) {
        return -(cos_((x - PI_SOBRE_DOIS) - PI));

    } else if (x < DOIS_PI) {
        return sin_(x - DOIS_PI);
    }

    printf("-> Ta extrapolando ae irmão!\n");
    return 0;
}