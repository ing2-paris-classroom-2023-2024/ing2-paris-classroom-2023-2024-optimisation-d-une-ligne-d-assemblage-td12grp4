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


    while ( fscanf(fichier, "%d %d ", &u, &v) != EOF) {


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
    }


// si la station n'existe pas la valeur vaut -2
    for (int i1 = 0; i1 < monGraphe.ordre+1; i1++) {
       if (tab[i1]!=0){
           for (int i2 = 0; i2 < monGraphe.ordre; i2++){
               monGraphe.matrice[i1][i2] = -2;
               monGraphe.matrice[i2][i1] = -2;
           }
       }
    }

    for (int i1 = 0; i1 < monGraphe.ordre+1; i1++) {
        for (int i2 = 0; i2 < monGraphe.ordre+1; i2++) {
            if (monGraphe.matrice[i1][i2] ==-2) {
                printf("%d %d %d \n",i1,i2 ,monGraphe.matrice[i1][i2]);
            }
        }
    }

    // idée pour contrainte d'exclusion chercher dans chaque ligne les stations compatibles entre
    // elle exemple la station 1 peut etre compatible avec la 2 3 4 5 puis après vérifier si la 2 3 4 5
    // sont toutes compatibles entre elles avec le meme programme

    fclose(fichier);

    return monGraphe;
}

int main() {
    printf("fisndif");
    printf("Hello, World!\n");
    struct Graphe graphe = affichergraphe();
    return 0;
}
