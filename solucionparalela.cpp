
#include <iostream>
#include <omp.h>

// Definiendo las constantes de precompilación:
#define N 1000
#define chunk 100
#define mostrar 10 

void imprimeArreglo(float *d);

int main()
{
    std::cout << "Sumando Arreglos en paralelo!\n";
    float a[N], b[N], c[N];
    int i;

    for (i = 0; i < N; i++)
    {
        a[i] = i^3+20;
        b[i] = 2*((-1)^(i)); 
    }
    int pedazos = chunk;

    #pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)

    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i]; 

    std::cout << "Imprimiendo los primeros " << mostrar << " valores de arreglo a: " << std::endl; 
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores de arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores de arreglo c: " << std::endl;
    imprimeArreglo(c);

}
void imprimeArreglo(float *d)
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}

