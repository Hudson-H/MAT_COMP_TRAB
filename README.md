# TRABALHO DE MATEMÁTICA COMPUTACIONAL
## Cálculo de Seno e e^x
O seguinte trabalho tem como objetivo aplicar os conhecimentos de Matemática Computacional acerca das questões de como conseguir precisão e eficiência. Dessa forma, os objetos de base para o estudo serão a função de seno e exponencial com a constante de Euler (e^x), dessa forma, é necessário calcular o valor de seno(x) e e^x utilizando as séries de Maclaurin que tem a forma geral:

$$
\sum_{n=0}^{\infty} \frac{f^{(n)}(0)x^n}{n!}
$$

onde, $$\sin(x) = x - \frac{x^3}{3!} + \frac{x^5}{5!} - \frac{x^7}{7!} + \frac{x^9}{9!} + \dots$$

e $$e^x = 1 + x + \frac{x^2}{2!} + \frac{x^3}{3!} + \frac{x^4}{4!} + \dots$$

A série de Maclaurin, na matemática, é considerada um caso especial da série de Taylor, pois seu desenvolvimento é centrado em torno do valor 0. Ela garante $$\sin(x)$$ e $$e^x$$ podem ser representados com exatidão caso infinitos termos da série forem considerados.

## Questões a serem abordadas
O computador tem espaço de representação limitado, ou seja, não é possível representar as funções acima com exatidão, visto que apenas alguns termos das sequências serão considerados. Desse modo, precisão é perdida conforme termos da série infinita são deixados de lado. Assim, é preciso reduzir o argumento x utilizado para que a precisão não seja perdida, também é preciso reduzir a quantidade de multiplicações para que o tempo de processamento não se torne inaceitável.
