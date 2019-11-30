//
// Created by Samuel on 29/11/2019.
//

#ifndef PARTEC_PARTEC_H
#define PARTEC_PARTEC_H

typedef struct {
    char Caractere;
    int *VetorBitsdoCaractere;
}Carac;

typedef struct {
    Carac *VetorMascara;
}MascaraBits;

typedef struct {
    int *CaracteresEspecificos;
    int QtdCarac;
}VetorChar;

typedef struct {
    int **R;
    int **RLinha;
}VetoresR;

void IniciarVetorChar(VetorChar *V, char *Palavra);
void IniciarMascara(MascaraBits *M, VetorChar *V, int QtdCharRepetidos, char *Palavra);
int Retorna(VetorChar *V);
void ShiftAnd(MascaraBits *M, VetoresR *Vet, VetorChar *V, char *Palavra, char *Texto);


#endif //PARTEC_PARTEC_H
