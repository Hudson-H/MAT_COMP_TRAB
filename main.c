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

    double func_sin = calculate_sin(PI);
    double normal_sin = sin(PI);
    double err_sin = fabs(func_sin - normal_sin);
    printf("sin original: %.30lf\n", normal_sin);
    printf("sin feito: %.30lf\n", func_sin);
    printf("erro sin: %.30lf\n", err_sin);

    printf("angle reduction [%.10lf]: %.10lf\n", PI/3 ,angle_reduction(PI/3));
    printf("angle reduction [%.10lf]: %.10lf\n", PI/2 ,angle_reduction(PI/2));
    printf("angle reduction [%.10lf]: %.10lf\n", PI ,angle_reduction(PI));

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