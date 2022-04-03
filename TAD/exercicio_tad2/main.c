#include <stdio.h>
#include <stdlib.h>
#include "FigurasGeometricas.h"

int main()
{
    Cubo *cubo1;
    Cilindro *cilindro1;
    Esfera *esfera1;

    cubo1 = CriaCubo(2);
    cilindro1 = CriaCilindro(3,5);
    esfera1 = CriaEsfera(10);

    printf("Hello world!\n");
    printf("\nLado cubo: %f", LadoCubo(cubo1));
    printf("\nRaio cilindro: %f", RaioCilindro(cilindro1));
    printf("\nAltura cilindro: %f", AlturaCilindro(cilindro1));
    printf("\nRaio esfera: %f", RaioEsfera(esfera1));
    printf("\n--------------");
    printf("\nArea cubo: %f", AreaCubo(cubo1));
    printf("\nArea cilindro: %f", AreaCilindro(cilindro1));
    printf("\nArea esfera: %f", AreaEsfera(esfera1));
    printf("\n--------------");
    printf("\nVolume cubo: %f", VolumeCubo(cubo1));
    printf("\nVolume cilindro: %f", VolumeCilindro(cilindro1));
    printf("\nVolume esfera: %f", VolumeEsfera(esfera1));
    return 0;
}
