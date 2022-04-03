typedef struct cubo Cubo;
typedef struct cilindro Cilindro;
typedef struct esfera Esfera;

Cubo* CriaCubo(float lado);
Cilindro* CriaCilindro(float diametro, float altura);
Esfera* CriaEsfera(float diametro);

float LadoCubo(Cubo* c);
float AlturaCilindro(Cilindro* c);
float RaioCilindro(Cilindro* c);
float RaioEsfera(Esfera* e);

float AreaCubo(Cubo* c);
float AreaCilindro(Cilindro* c);
float AreaEsfera(Esfera* e);

float VolumeCubo(Cubo* c);
float VolumeCilindro(Cilindro* c);
float VolumeEsfera(Esfera* e);
