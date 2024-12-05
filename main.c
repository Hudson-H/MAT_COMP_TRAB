/*
    Hudson Henrique da Silva | RA:128849
    Vitor Azevedo Padovani | RA: 128169
    data: 17/10/24
*/

#include<stdio.h>
#include<math.h>
#include"const.h"
#include"calc.h"

void generate_sin_tests() {
    FILE *file = fopen("errors_sin.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(file, "Angle (rad),        func_sin,        Original Sin,        Error\n");

    for (double angle = 0.0; angle <= DOIS_PI; angle += 0.01) {
        double funct_sin = func_sin(angle);
        double normal_sin = sin(angle);
        double error_sin = fabs(funct_sin - normal_sin);

        fprintf(file, "%.15lf,%.15lf,%.15lf,%.15lf\n", angle, funct_sin, normal_sin, error_sin);
    }

    fclose(file);
    printf("Testes gerados e salvos em 'errors_sin.txt'.\n");
}

void generate_exp_tests() {
    FILE *file = fopen("errors_exp.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(file, "exponent,        func_exp,       original_exp,        Error\n");

    for(double exponent = -5; exponent <= 5; exponent += 0.01) {
        double func_exp = exp_reduction(exponent);
        double normal_exp = exp(exponent);
        double err_exp = fabs(func_exp - normal_exp);

        fprintf(file, "%.15lf,%.15lf,%.15lf,%.15lf\n", exponent, func_exp, normal_exp, err_exp);
    }

    fclose(file);
    printf("Testes gerados e salvos em 'errors_exp.txt'.\n");
}

int test_cos (double angle_to_test) {

    double func_coss = func_cos(angle_to_test);

    double normal_cos = cos(angle_to_test);
    double err_cos = fabs(func_coss - normal_cos);

    printf("angulo original: %.10lf\n", angle_to_test);
    printf("cos original: %.10lf\n", normal_cos);
    printf("cos feito: %.10lf\n", func_coss);
    printf("erro cos: %.10lf\n\n", err_cos);

    return (!err_cos) ? 0 : 1;
}

int test_sin (double angle_to_test) {

    double funct_sin = func_sin(angle_to_test);

    double normal_sin = sin(angle_to_test);
    double err_sin = fabs(funct_sin - normal_sin);

    printf("angulo original: %.10lf\n", angle_to_test);
    printf("sin original: %.10lf\n", normal_sin);
    printf("sin feito: %.10lf\n", funct_sin);
    printf("erro sin: %.10lf\n\n", err_sin);

    return (!err_sin) ? 0 : 1;
}

int main() {

    generate_sin_tests();
    generate_exp_tests();

    return 0;
}