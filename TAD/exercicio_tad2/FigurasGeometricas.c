#include <stdlib.h>
#include "FigurasGeometricas.h"
#define PI  3.14
struct cubo{
    float lado;
};

struct cilindro{
    float diametro;
    float altura;
};

struct esfera{
    float diametro;
};

Cubo* CriaCubo(float lado)
{
    Cubo* c = (Cubo *) malloc(sizeof(Cubo));
    c->lado = lado;
    return c;
}

Cilindro* CriaCilindro(float diametro, float altura)
{
    Cilindro* c = (Cilindro *) malloc(sizeof(Cilindro));
    c->diametro = diametro;
    c->altura = altura;
    return c;
}

Esfera* CriaEsfera(float diametro)
{
    Esfera* e = (Esfera *) malloc(sizeof(Esfera));
    e->diametro = diametro;
    return e;
}

float LadoCubo(Cubo* c)
{
    return c->lado;
}

float AlturaCilindro(Cilindro* c)
{
    return c->altura;
}

float RaioCilindro(Cilindro* c)
{
    return (c->diametro)/2;
}

float RaioEsfera(Esfera* e)
{
    return (e->diametro)/2;
}

float AreaCubo(Cubo* c)
{
    return (LadoCubo(c)*LadoCubo(c))*6;
}

float AreaCilindro(Cilindro* c)
{
    float areaLateral, areaBase;
    areaLateral = (c->diametro)*PI*(c->altura);
    areaBase = RaioCilindro(c)*RaioCilindro(c)*PI;

    return (areaLateral + (areaBase*2));
}

float AreaEsfera(Esfera* e)
{
    return (RaioEsfera(e)*RaioEsfera(e)*PI*4);
}

float VolumeCubo(Cubo* c)
{
    return (LadoCubo(c)*LadoCubo(c)*LadoCubo(c));
}

float VolumeCilindro(Cilindro* c)
{
    return (PI*RaioCilindro(c)*RaioCilindro(c)*AlturaCilindro(c));
}

float VolumeEsfera(Esfera* e)
{
    return ((4*PI*RaioEsfera(e)*RaioEsfera(e)*RaioEsfera(e))/3);
}











