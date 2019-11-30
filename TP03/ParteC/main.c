#include <stdio.h>
#include "ParteC.h"

int main() {
    VetorChar *V;
    MascaraBits *M;
    VetoresR *R;
    int QtdCharRepetidos;

    IniciarVetorChar(&V, "teste");
    QtdCharRepetidos = Retorna(&V);
    IniciarMascara(&M, &V, QtdCharRepetidos, "teste");
    ShiftAnd(&M, &R,  &V,"teste", "testando teste");
}