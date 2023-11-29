#include <stdio.h>
#include <stdlib.h>


struct Graphe {
    int ordre;
    int **matrice;
    int taille;
    int min;
};


struct Graphe exclusion() {
    struct Graphe monGraphe;
    FILE *fichier;
    char nom[100];

    printf("Donnez le nom du fichier (mettez exclusion.txt) :\n ");
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
    monGraphe.min=min;
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

    printf("contrainte d'exclusion\n ");
    for (int i5=0;i5< monGraphe.ordre+1; i5++)
        if (tab2[i5]!=-10){
            printf("le sommet %d appartient au groupe %d \n" ,i5,tab2[i5]) ;
        }

    fclose(fichier);

    return monGraphe;
}

void  exclusion_temps(struct Graphe graphe) {

    char nomdufichier [100];
    printf("Entrez le nom du fichier (operations.txt) :\n");
    scanf("%s", nomdufichier);

    FILE *file = fopen(nomdufichier, "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");

    }



    int a10=0;

    // Initialisation du tableau des sommets avec la valeur -10



    int num2;
    int min;
    double time2;
    while (fscanf(file, "%d %lf", &num2, &time2) != EOF) {
        if (a10==0){
            min=num2;
        }

        if (num2>a10){
            a10=num2;
        }

    }

    fclose(file);
    char nomdufichier2 [100];
    printf("Entrez le nom du fichier (temps_cycle.txt) :\n");
    scanf("%s", nomdufichier2);

    FILE *file2 = fopen(nomdufichier2, "r");
    if (file2 == NULL) {
        perror("Erreur lors de l'ouverture du fichier");

    }
    float temps_cycle;
    fscanf(file2,"%f",&temps_cycle);


    fclose (file2);
    FILE *file3 = fopen(nomdufichier, "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");

    }

    // Initialisation du tableau des sommets avec la valeur -10
    float tableau[a10];
    for (int i = min; i <a10+1 ; i++) {
        tableau[i] = -10.0;
    }

    int num;
    double time;
    while (fscanf(file, "%d %lf", &num, &time) != EOF) {

        tableau[num] = time;



    }
    fclose(file3);

    // Affichage du tableau des temps
    /*
    for (int i = min; i < a10+1; i++) {
        if (tableau[i] != -10.0) {
            printf("Sommet %d a un temps de %0.2lf\n", i, tableau[i]);
        } else {
            printf("Sommet %d n'existe pas dans le fichier et a donc une valeur de %0.2lf\n", i, tableau[i]);
        }
    }
*/
    float tabtemps[graphe.ordre+1];
    for (int z5=0; z5<graphe.ordre+1;z5++){
        tabtemps[z5]=0;
    }
    int a;
    int h=0;
    int ve=0;
    int groupe=0-min;
    int tab2[graphe.ordre+1];
    int groupemax=0;
    for (int o=0 ;o<graphe.ordre+1;o++){
        tab2[o]=-10;

    }
    for (int z=0 ; z<graphe.ordre+1;z++){
        if (tab2[z]==-10){
            groupe++;
            if (groupe>1){
                for (int i6=0 ;i6<graphe.ordre;i6++){
                    if (tab2[i6]>=groupemax){
                        groupemax=tab2[i6];

                    }

                }

                groupe=groupemax+1;
            }






        }



        for (int z1=0 ; z1<graphe.ordre+1;z1++){


            if (tab2[z1]==-10){





                if (graphe.matrice[z][z1] ==0  ){
                    if (tab2[z]==-10 &&  tabtemps[groupe]+tableau[z]<=temps_cycle){
                        tabtemps[groupe]=tabtemps[groupe]+tableau[z];
                        tab2[z]=groupe;
                    }



                    a=3;
                    for (int z2=0 ; z2<graphe.ordre+1;z2++){


                        if (tab2[z2]==groupe){
                            if (graphe.matrice[z2][z1] !=0 && graphe.matrice[z1][z2] !=0 ){
                                a=2;
                            }
                        }

                    }

                    if (a==3 && tabtemps[groupe]+tableau[z1]<temps_cycle && tab2[z1]==-10){
                        tab2[z1]=groupe;


                        tabtemps[groupe]=tabtemps[groupe]+tableau[z1];





                    }
















                }
            }
        }
    }

    printf("contrainte d'exclusion + temps de cycle \n");
    for (int i5=0;i5< graphe.ordre+1; i5++){


        if (tab2[i5]!=-10){
            printf("le sommet %d appartient au groupe %d \n" ,i5,tab2[i5]) ;
        }

    }
    int variable;
    int groupes[graphe.ordre];
    for (int i7=0; i7<graphe.ordre+1;i7++){
        groupes[i7]=-10;
    }
    for (int i7=0; i7<graphe.ordre+1;i7++){
        variable=0;
        for (int i8=0; i8<graphe.ordre+1;i8++){
            if (tab2[i8]==i7){
                variable++;
            }


        }
        groupes[i7]=variable;

        if (variable!=0){
            printf("le groupe %d est compose de %d sommets \n",i7,variable);
        }

    }
    for (int i5=0; i5<graphe.ordre ;i5++){
        if (tabtemps[i5]!=0){
            printf("le temps du groupe %d est %f\n",i5,tabtemps[i5]);

        }
    }


}

int main() {
    printf("Hello, World!\n");
    struct Graphe graphe = exclusion();
    exclusion_temps(graphe);




    return 0;
}
