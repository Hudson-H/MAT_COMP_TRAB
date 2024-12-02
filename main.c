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

    double func_sin = calculate_sin((PI)/3);
    double normal_sin = sin((PI)/3);
    double err_sin = fabs(func_sin - normal_sin);
    printf("sin original: %.10lf\n", normal_sin);
    printf("sin feito: %.10lf\n", func_sin);
    printf("erro sin: %.10lf\n", err_sin);

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