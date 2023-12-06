#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <string.h>


struct Graphe {
    int ordre;
    int **matrice;
    int taille;
    int min;
};


void exclusion() {
    struct Graphe monGraphe;
    FILE *fichier;
    char nom[100];




    fichier = fopen("exclusion.txt", "r");

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

    fichier = fopen("exclusion.txt", "r");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s\n", nom);
        exit(1);
    }

    monGraphe.matrice = (int **)malloc((ordre+1) * sizeof(int *));
    for (int i = 0; i < ordre+1; i++) {
        monGraphe.matrice[i] = (int *)malloc((ordre+1) * sizeof(int));
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


int groupemax;
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
                groupemax=groupe;

            }















        }
    }
    }
}



printf("contrainte d'exclusion\n ");
for (int i9=1;i9<groupemax+1;i9++ ){
    printf("\n groupe %d \n:",i9);
for (int i5=0;i5< monGraphe.ordre+1; i5++){
    if (tab2[i5]!=-10 && tab2[i5]==i9){

        printf(" %d," ,i5) ;
    }
    }
}
    int variable;
    int groupes[monGraphe.ordre];
    printf("\n");
    for (int i7=0; i7<monGraphe.ordre+1;i7++){
        groupes[i7]=-10;
    }
    for (int i7=0; i7<monGraphe.ordre+1;i7++){
        variable=0;
        for (int i8=0; i8<monGraphe.ordre+1;i8++){
            if (tab2[i8]==i7){
                variable++;
            }


        }
        groupes[i7]=variable;

        if (variable!=0){
            printf("le groupe %d est compose de %d sommets \n",i7,variable);
        }

    }


    fclose(fichier);

    for (int i = 0; i < ordre + 1; i++) {
        free(monGraphe.matrice[i]);
    }
    free(monGraphe.matrice);


}

void  exclusion_temps() {
    struct Graphe monGraphe;
    char nomdufichier [100];
    FILE *fichier;
    char nom[100];




    fichier = fopen("exclusion.txt", "r");

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

    fichier = fopen("exclusion.txt", "r");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s\n", nom);
        exit(1);
    }

    monGraphe.matrice = (int **)malloc((ordre+1 )* sizeof(int *));
    for (int i = 0; i < ordre+1; i++) {
        monGraphe.matrice[i] = (int *)malloc((ordre+1) * sizeof(int));
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



    FILE *file = fopen("operations.txt", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");

    }



    int a10=0;

    // Initialisation du tableau des sommets avec la valeur -10



    int num2;
    int min2;
    double time2;
    while (fscanf(file, "%d %lf", &num2, &time2) != EOF) {
        if (a10==0){
            min2=num2;
        }

        if (num2>a10){
            a10=num2;
        }

    }

    fclose(file);
    char nomdufichier2 [100];


    FILE *file2 = fopen("temps_cycle.txt", "r");
    if (file2 == NULL) {
        perror("Erreur lors de l'ouverture du fichier");

    }
float temps_cycle;
fscanf(file2,"%f",&temps_cycle);


fclose (file2);
    FILE *file3 = fopen("operations.txt", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");

    }

    // Initialisation du tableau des sommets avec la valeur -10
    float tableau[a10];
    for (int i = min2; i <a10+1 ; i++) {
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
    float tabtemps[monGraphe.ordre+1];
    for (int z5=0; z5<monGraphe.ordre+1;z5++){
        tabtemps[z5]=0;
    }
    int a;
    int h=0;
    int ve=0;
    int groupe=0-min2;
    int tab2[monGraphe.ordre+1];
    int groupemax=0;
    for (int o=0 ;o<monGraphe.ordre+1;o++){
        tab2[o]=-10;

    }
    for (int z=0 ; z<monGraphe.ordre+1;z++){
        if (tab2[z]==-10){
            groupe++;
            if (groupe>1){
            for (int i6=0 ;i6<monGraphe.ordre;i6++){
                if (tab2[i6]>=groupemax){
                    groupemax=tab2[i6];

                }

            }

            groupe=groupemax+1;
            }






        }



        for (int z1=0 ; z1<monGraphe.ordre+1;z1++){


            if (tab2[z1]==-10){





                if (monGraphe.matrice[z][z1] ==0  ){
                    if (tab2[z]==-10 &&  tabtemps[groupe]+tableau[z]<=temps_cycle){
                        tabtemps[groupe]=tabtemps[groupe]+tableau[z];
                        tab2[z]=groupe;
                    }



                    a=3;
                    for (int z2=0 ; z2<monGraphe.ordre+1;z2++){


                        if (tab2[z2]==groupe){
                            if (monGraphe.matrice[z2][z1] !=0 && monGraphe.matrice[z1][z2] !=0 ){
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

    for (int i9=1;i9<groupemax+1;i9++ ){
        printf("\n groupe %d \n:",i9);
        for (int i5=0;i5< monGraphe.ordre+1; i5++){
            if (tab2[i5]!=-10 && tab2[i5]==i9){

                printf(" %d," ,i5) ;
            }
        }
    }
    printf("\n");
    int variable;
    int groupes[monGraphe.ordre];
    for (int i7=0; i7<monGraphe.ordre+1;i7++){
        groupes[i7]=-10;
    }
    for (int i7=0; i7<monGraphe.ordre+1;i7++){
        variable=0;
        for (int i8=0; i8<monGraphe.ordre+1;i8++){
            if (tab2[i8]==i7){
                variable++;
            }


        }
        groupes[i7]=variable;

        if (variable!=0){
            printf("le groupe %d est compose de %d sommets \n",i7,variable);
        }

    }
    for (int i5=0; i5<monGraphe.ordre ;i5++){
    if (tabtemps[i5]!=0){
        printf("le temps du groupe %d est %f\n",i5,tabtemps[i5]);

    }
    }

    for (int i = 0; i < ordre + 1; i++) {
        free(monGraphe.matrice[i]);
    }
    free(monGraphe.matrice);
}
void exclusion_precedence(){
    struct Graphe monGraphe;
    FILE *fichier;
    char nom[100];


    fichier = fopen("exclusion.txt", "r");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier \n");
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

    fichier = fopen("exclusion.txt", "r");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s\n", nom);
        exit(1);
    }

    monGraphe.matrice = (int **)malloc((ordre+1) * sizeof(int *));
    for (int i = 0; i < ordre+1; i++) {
        monGraphe.matrice[i] = (int *)malloc((ordre+1) * sizeof(int));
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

    FILE *fichier2;


int min3=100;
    fichier2 = fopen("precedences.txt", "r");

    if (fichier2 == NULL) {
        printf("Erreur lors de l'ouverture du fichier \n");
        exit(1);
    }
int ordre2=0;
    while ( fscanf(fichier2, "%d %d ", &u, &v) != EOF) {

        if (u<min3){
            min3=u;
        }


        if (v<min3){
            min3=v;
        }


        taille++;
        if (u>ordre2){
            ordre2=u;
        }
        if (v>ordre2){
            ordre2=v;
        }

    }
fclose (fichier2);
    FILE *fichier3;



    fichier3 = fopen("precedences.txt", "r");

    if (fichier3 == NULL) {
        printf("Erreur lors de l'ouverture du fichier \n");
        exit(1);
    }

    int precedence[ordre2+min3][ordre2+min3];
    for (int h8=0;h8<ordre2+min3;h8++){
        for (int h9=0;h9<ordre2+min3;h9++){
            precedence[h8][h9]=-2;

        }
    }
// le sommet u doit etre fait avant le sommet v si =1 si =2 possible si =-2 le le sommet u n'existe pas
    while ( fscanf(fichier3, "%d %d ", &u, &v) != EOF) {


        for (int h10=0;h10<ordre2+min3;h10++){
            precedence[u][h10]=2;
        }
        precedence[u][v]=1;

    }

    int groupemax;
    int a;
    int ve=0;
    int groupe=0-min;
    int tab2[monGraphe.ordre+1];
    int tab3[monGraphe.ordre+1];
    for (int o=0 ;o<monGraphe.ordre+1;o++){
        tab2[o]=-10;

    }
    int debut[ordre2+min3];
    for (int o=0 ;o<ordre2+min3;o++){
        debut[o]=-10;

    }
    int compteur=0;
    int g=0;
 for (int z=min3;z<ordre2+min3;z++){
     g=2;
     for (int z2=min3;z2<ordre2+min3;z2++){
         if (precedence[z2][z]==2){
             compteur++;
         }
         if (precedence[z2][z]==1 ){

             g=1;
         }


     }
     if (g==2 && compteur>=1){
         debut[z]=1;
         printf("%d\n",z);
     }
 }

    for (int i9=1;i9<groupemax+1;i9++ ){
        printf("\n groupe %d \n:",i9);
        for (int i5=0;i5< monGraphe.ordre+1; i5++){
            if (tab2[i5]!=-10 && tab2[i5]==i9){

                printf(" %d," ,i5) ;
            }
        }
    }
    printf("\n");
    int variable;
    int groupes[monGraphe.ordre];
    for (int i7=0; i7<monGraphe.ordre+1;i7++){
        groupes[i7]=-10;
    }
    for (int i7=0; i7<monGraphe.ordre+1;i7++){
        variable=0;
        for (int i8=0; i8<monGraphe.ordre+1;i8++){
            if (tab2[i8]==i7){
                variable++;
            }


        }
        groupes[i7]=variable;

        if (variable!=0){
            printf("le groupe %d est compose de %d sommets \n",i7,variable);
        }

    }


    for (int i = 0; i < ordre + 1; i++) {
        free(monGraphe.matrice[i]);
    }
    free(monGraphe.matrice);
}

void tout(){
    printf("pas encore implémenté ");
}
int main() {
    int passage=0;

int h=1;
while (passage!=6){
    printf("\n \n \n");
    printf("1-temps de cycle + precedence\n");
    printf("2-algorithme d'exclusion\n");
    printf("3-algorithme d'exclusion + precedence\n");
    printf("4-algorithme d'exclusion + temps de cycle\n");
    printf("5-calcule en fonction de toute les contraintes\n");
    printf("6-quitter \n");


    char input[100];
    int estUnNombre = 1;


    printf("Entrez un nombre entre 1 et 6 : \n ");
    scanf("%s", input);

    // Vérifiez si chaque caractère est un chiffre
    for (int i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i])) {
            estUnNombre = 0;
            break;
        }
    }

    // Si tous les caractères sont des chiffres, convertissez en entier
    if (estUnNombre) {
        passage = atoi(input);

        // Vérifiez si le nombre est dans la plage 1-6
        if (passage >= 1 && passage <= 6) {
            printf("Le nombre %d est valide et compris entre 1 et 6.\n", passage);
        } else {
            printf("Le nombre doit etre entre 1 et 6.\n");
        }
    } else {
        printf("Vous n'avez pas entre un nombre valide.\n");
    }

    if (passage==1){
        printf("taff de robin\n");

    }
    if (passage==2){

      exclusion();

    }
    if (passage==3){
        exclusion_precedence();

    }
    if (passage==4){


        exclusion_temps();


    }
    if (passage==5){
        tout();

    }

h=1;
}






    return 0;
}
