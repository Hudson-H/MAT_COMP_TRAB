/*
    Hudson Henrique da Silva | RA:128849
    Vitor Azevedo Padovani | RA: 128169
    data: 17/10/24
*/

/*
sen(x), cos(x) (não é sen ou cos de x*)
angulos:
0 -> k = 0; x* = 0; seno_real = 0, cos_real = 1; ========= certo
pi/6 -> k = 0; x* = pi/6; seno_real = 0.5, cos_real = 0.86602540378; ========= certo
pi/4 -> k = 0; x* = pi/4; seno_real = 0.70710678118, cos_real = 0.70710678118; ========= certo
pi/3 -> k = 1; x* = -pi/4; seno_real = 0.86602540378, cos_real = 0.5; ========= certo
pi/2 -> k = 1; x* = 0; seno_real = 1, cos_real = 0; ========= certo
2pi/3 -> k = 1; x* = pi/6; seno_real = 0.5, cos_real = 0.86602540378; ========= certo
3pi/4 -> k = 1; x* = pi/4; seno_real = 0.70710678118, cos_real = -0.70710678118; ========= certo
5pi/6 -> k = 2; x* = -pi/6; seno_real = -0.5, cos_real = 0.86602540378; ------------------------- erro = 0.3660254038
pi -> k = 2; x* = 0; seno_real = 0, cos_real = -1; ------------------------- erro = 1
7pi/6 -> k = 2; x* = pi/6; seno_real = -0.5, cos_real = -0.86602540378; ------------------------- erro = 1.3660254038
5pi/4 -> k = 2; x* = -pi/6; seno_real = -0.70710678118, cos_real = -0.70710678118; ------------------------- erro = 1.4142135624
4pi/3 -> k = 3; x* = -pi/6; seno_real = -0.86602540378 (sen feito só errou sinal), cos_real = -0.5; ------------------------- erro = 1.7320508076 
3pi/2 (-pi/2)-> k = 3; x* = 0; seno_real = -1 (errou sinal), cos_real = 0; ------------------------- erro = 2
5pi/3 (-pi/3)-> k = 3; x* = pi/6; seno_real = -0.86602540378 (errou sinal), cos_real = 0.5; ------------------------- erro = 1.7320508076
7pi/4 (-pi/4)-> k = 3; x* = pi/4; seno_real = -0.70710678118 (errou sinal), cos_real = 0.70710678118; ------------------------- erro = 1.7320508076
11pi/6 (-pi/6) -> k = 4; x* = -pi/6; seno_real = -0.5, cos_real = 0.86602540378; ------------------------- erro = 1.7320508076
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

    fprintf(file, "Angle (rad),vitor_sin,Original Sin,Error\n");

    for (double angle = 0.0; angle <= 2 * PI; angle += 0.01) {
        double func_sin = vitor_sin(angle);
        double normal_sin = sin(angle);
        double error_sin = fabs(func_sin - normal_sin);

        fprintf(file, "%.15lf,%.15lf,%.15lf,%.15lf\n", angle, func_sin, normal_sin, error_sin);
    }

    fclose(file);
    printf("Testes gerados e salvos em 'errors_sin.txt'.\n");
}

int test_cos (double angle_to_test) {

    // double func_sin = sin_(angle_reduction(angle_to_test, calculate_k(angle_to_test)));
    double func_cos = vitor_cos(angle_to_test);

    double normal_cos = cos(angle_to_test);
    double err_cos = fabs(func_cos - normal_cos);

    printf("angulo original: %.10lf\n", angle_to_test);
    printf("cos original: %.10lf\n", normal_cos);
    printf("cos feito: %.10lf\n", func_cos);
    printf("erro cos: %.10lf\n\n", err_cos);

    if (err_cos == 0) return 0; else return 1;
}

int test_sin (double angle_to_test) {

    double func_sin = vitor_sin(angle_to_test);

    double normal_sin = sin(angle_to_test);
    double err_sin = fabs(func_sin - normal_sin);

    printf("angulo original: %.10lf\n", angle_to_test);
    printf("sin original: %.10lf\n", normal_sin);
    printf("sin feito: %.10lf\n", func_sin);
    printf("erro sin: %.10lf\n\n", err_sin);

    if (err_sin == 0) return 0; else return 1;
}

int main() {
    
    // Gerador de testes do sen
    printf("---------TESTANDO SEN---------\n");
    for (int i = 0; i < 4; i++) {

        printf("-=-=-=-=testes %d=-=-=-=-\n", i);
        test_sin((i * PI/2));
        test_sin((i * PI/2) + PI/6);
        test_sin((i * PI/2) + PI/4);
        test_sin((i * PI/2) + PI/3);
    }

    // printf("angle reduction [5PI/6]: %.10lf\n" ,angle_reduction((5*PI)/6));
    // printf("angle reduction [PI/2]: %.10lf\n" ,angle_reduction(PI/2));
    // printf("angle reduction [PI]: %.10lf\n\n" ,angle_reduction(PI));

    double func_exp = exp_(1);
    double normal_exp = exp(1);
    double err_exp = fabs(func_exp - normal_exp);

    printf("exp original: %.10lf\n", normal_exp);
    printf("exp feito: %.10lf\n", func_exp);
    printf("erro exp: %.10lf\n", err_exp);

    generate_sin_tests();

    return 0;
}

/*
sin original: 0.000000000000000122464679914735
sin feito: 1.000000000000000000000000000000
erro sin: 0.999999999999999888977697537484
angle reduction [1.0471975512]: 0.8660254038 PI/3
angle reduction [1.5707963268]: 1.0000000000 PI/2
angle reduction [3.1415926536]: 1.0000000000 PI

=================================================
PI/4
sin original: 0.707106781186547461715008466854
sin feito: 0.707106781163372999365890336776
erro sin: 0.000000000023174462349118130078
=================================================
PI/3
sin original: 0.866025403784438596588302061718
sin feito: 0.866025403786384817550469961134
erro sin: 0.000000000001946220962167899415
=================================================
PI/2
sin original: 1.000000000000000000000000000000
sin feito: 1.000000000000000000000000000000
erro sin: 0.000000000000000000000000000000
=================================================
PI
sin original: 0.000000000000000122464679914735
sin feito: 1.0000000000000000000000000
00000
erro sin: 0.999999999999999888977697537484
=================================================
2PI
sin original: -0.000000000000000244929359829471
sin feito: 1.000000000000000000000000000000
erro sin: 1.000000000000000222044604925031
*/