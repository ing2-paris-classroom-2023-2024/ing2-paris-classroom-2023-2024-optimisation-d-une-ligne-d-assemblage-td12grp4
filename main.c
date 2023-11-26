#include <stdio.h>
#include <stdlib.h>


struct Graphe {
    int ordre;
    int **matrice;
    int taille;
};


struct Graphe affichergraphe() {
    struct Graphe monGraphe;
    FILE *fichier;
    char nom[100];

    printf("Donnez le nom du fichier (mettez graphe.txt) :\n ");
    scanf("%s", nom);

    fichier = fopen(nom, "r");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s\n", nom);
        exit(1);
    }

    int u, v,poids ;
    char carractere[100];
    int taille = 0;
    int ordre = 0;
    int min=0;
    int f=0;
    while ( fscanf(fichier, "%d %d ", &u, &v) != EOF) {
        if (f==0){
            min=u;

        }
        f++;


        taille++;
        if (u>ordre){
            ordre=u;
        }
        if (v>ordre){
            ordre=v;
        }

    }
    int tab[ordre];

    for (int i=0;i<ordre+1 ;i++){
        tab[i]=i;
    }
    monGraphe.ordre=ordre;
    monGraphe.taille=taille;
    fclose(fichier);

    fichier = fopen(nom, "r");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s\n", nom);
        exit(1);
    }

    monGraphe.matrice = (int **)malloc(ordre * sizeof(int *));
    for (int i = 0; i < ordre+1; i++) {
        monGraphe.matrice[i] = (int *)malloc(ordre * sizeof(int));
    }
// si on  peut  mettre les stations ensemble la valeur vaut 0
    for (int i1 = 0; i1 < ordre+1; i1++) {
        for (int i2 = 0; i2 < ordre+1; i2++) {
            monGraphe.matrice[i1][i2] = 0;
        }
    }
    printf("taille vaux %d\n",taille);
// si on ne peut pas mettre les stations ensemble la valeur vaut -1
    for (int i = 0; i < taille; i++) {
        fscanf(fichier, "%d %d ", &u, &v);

        tab[u]=0;
        tab[v]=0;
        monGraphe.matrice[u][v] = -1;
        monGraphe.matrice[v][u] = -1;
    }


// si la station n'existe pas la valeur vaut -2
    for (int i1 = 0; i1 < monGraphe.ordre+1; i1++) {
        if (tab[i1]!=0){
            for (int i2 = 0; i2 < monGraphe.ordre+1; i2++){
                monGraphe.matrice[i1][i2] = -2;
                monGraphe.matrice[i2][i1] = -2;
                monGraphe.matrice[i2][i2] = -2;
            }
        }
    }

    for (int i=0 ; i<min ; i++){
        for (int i2 = 0; i2 < monGraphe.ordre+1; i2++){
            monGraphe.matrice[i][i2] = -2;
            monGraphe.matrice[i2][i] = -2;
        }
    }

    for (int i1 = 0; i1 < monGraphe.ordre+1; i1++) {

        for (int i2 = 0; i2 < monGraphe.ordre+1; i2++){
            if (monGraphe.matrice[i1][i2] == 0){


            }

        }
    }

    int a;
    int ve=0;
    int groupe=0-min;
    int tab2[monGraphe.ordre+1];
    for (int o=0 ;o<monGraphe.ordre+1;o++){
        tab2[o]=-10;

    }
    for (int z=0 ; z<monGraphe.ordre+1;z++){
        if (tab2[z]==-10){
            groupe++;
        }



        for (int z1=0 ; z1<monGraphe.ordre+1;z1++){

            if (tab2[z1]==-10){



                if (monGraphe.matrice[z][z1] ==0  ){

                    a=3;
                    for (int z2=0 ; z2<monGraphe.ordre+1;z2++){


                        if (tab2[z2]==groupe){
                            if (monGraphe.matrice[z2][z1] !=0 && monGraphe.matrice[z1][z2] !=0 ){
                                a=2;
                            }
                        }

                    }
                    if (a==3){
                        tab2[z1]=groupe;

                    }















                }
            }
        }
    }

/*
    for (int i1 = 0; i1 < monGraphe.ordre+1; i1++) {
        for (int i2 = 0; i2 < monGraphe.ordre+1; i2++) {
            if (monGraphe.matrice[i1][i2] !=0  && monGraphe.matrice[i1][i2] !=-1 && monGraphe.matrice[i1][i2] !=-2 ) {
                printf("%d %d %d \n",i1,i2 ,monGraphe.matrice[i1][i2]);
            }
        }
    }
*/
    for (int i5=0;i5< monGraphe.ordre+1; i5++)
        if (tab2[i5]!=-10){
            printf("le sommet %d appartient au groupe %d \n" ,i5,tab2[i5]) ;
        }

    fclose(fichier);

    return monGraphe;
}

int main() {


    struct Graphe graphe = affichergraphe();
    return 0;
}
