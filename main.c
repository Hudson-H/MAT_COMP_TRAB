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

int main() {

    double func_sin = sin_(angle_reduction(5*PI/3, calculate_k(5*PI/3)));
    double normal_sin = sin(5*PI/3);
    double err_sin = fabs(func_sin - normal_sin);
    printf("sin original: %.10lf\n", normal_sin);
    printf("sin feito: %.10lf\n", func_sin);
    printf("erro sin: %.10lf\n\n", err_sin);

    // printf("angle reduction [5PI/6]: %.10lf\n" ,angle_reduction((5*PI)/6));
    // printf("angle reduction [PI/2]: %.10lf\n" ,angle_reduction(PI/2));
    // printf("angle reduction [PI]: %.10lf\n\n" ,angle_reduction(PI));

    double func_exp = exp_(1);
    double normal_exp = exp(1);
    double err_exp = fabs(func_exp - normal_exp);

    printf("exp original: %.10lf\n", normal_exp);
    printf("exp feito: %.10lf\n", func_exp);
    printf("erro exp: %.10lf\n", err_exp);

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