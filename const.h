// constantes
#ifndef CONST_H
#define CONST_H

typedef union double_union{
    double x; // valor decimal representado normalmente
    struct {
        unsigned long long int f : 52; // mantissa
        unsigned int E : 11; // expoente bias
        unsigned char s : 1;  // sinal
    }Double;
}double_union; //estrutura para precisão dupla

#define K2 0.5 //ka = 1/a!
#define K3 0.1666666667
#define K4 0.04166666666
#define K5 0.008333333333
#define K6 0.001388888889
#define K7 0.0001984126984
#define K8 0.0000248015873
#define K9 0.000002755731922
#define K10 0.0000002755731922
#define K11 0.00000002505210839
#define K12 0.00000000208767575699
#define K13 0.0000000001605904384
#define K15 0.0000000000007647163732
#define K17 0.00000000000000281145754
#define K19 0.0000000000000000082206352 // 8.2206352e-18

#define DOIS_PI 6.28318530718
#define PI_SOBRE_DOIS 1.57079632679
#define SETE_PI_SOBRE_QUATRO 5.49778714378
#define CINCO_PI_SOBRE_QUATRO 3.92699081699
#define TRES_PI_SOBRE_QUATRO 2.35619449019
#define PI_SOBRE_QUATRO 0.78539816339

#define LN2 0.69314718056 // ln(2)
#define DOIS_LN2 1.38629436112 // 2ln(2)
#define UM_SOBRE_DOIS_LN2 0.72134752044

#define eELEVADOA2 7.38905609893 // e^2

// pi com 50 casas decimais
#define PI 3.14159265358979323846264338327950288

// Constante C para se usar na redução aditiva do sen --> (PI/2)
#define C 1.57079632679 // C também pode ser PI/4

// maior valor do intervalo de confiança do sen (PI/4)
#define MAX_VALUE 0.78539816339

// 1/C -> 1/(pi/2)
#define Cinverso 0.6366197723675814

#endif