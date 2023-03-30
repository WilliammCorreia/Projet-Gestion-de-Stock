#include "gestion_produit.h"

/**fonction d'affichage de produit
*/
void affiche_produit(PROD prd){
    printf("%30s|%30s|%4.3f\n",prd.nom, prd.designation, prd.prix);
}
/**
Fonction d'affichage d'une liste de produit de taille nb
Cette fonction affiche à partir d'un tableau de produit "listeProd"
Passé en argument de la fonction
le type de retour est vide (void)
*/
void affiche_liste_produit(PROD* listeProd, int nb){
    int i;
    printf("              NOM             |          DESIGNATION         |    PRIX    \n");
    for(i =0; i< nb;i++ ){
        affiche_produit(listeProd[i]);
    }
}
 /** fonction de saisie de produit
    Elle saisie un produit temporaire et le retourne à la fin de la saisie
 */
PROD saisir_produit(){
    PROD prdtmp;
    printf("Introduire le nom : ");
    scanf("%s",prdtmp.nom);
    prdtmp.nom[39] = '\0';
    fflush(stdin);
    printf("Introduire la designation : ");
    scanf("%s",prdtmp.designation);
    prdtmp.nom[59] = '\0';
    fflush(stdin);
    printf("Introduire le prix : ");
    scanf("%f",&prdtmp.prix);

    return prdtmp;
}
/**
Fonction de saisie d'une liste de produit de taille nb
*/

void saisir_liste_produit(int nb, PROD * listeProd){
    int i;
    for(i=0; i< nb;i++){
        listeProd[i] = saisir_produit();
    }
}

/**fonction de tri de liste produit
Cette fonction demande à l'utilisateur le choix du type du tri
1 - tri par nom
2 - tri par prix
Elle prend en argument un nombre de produit ainsi que la liste de ces produits
Le tri s'effectue sur le tableau listeProduit
*/
void tri_liste_produit(int nb, PROD* listeProd){
    PROD prdTmp;
    int i;
    int j;
    int choix_utilisateur;
    int resultat_strcoll;

    printf("Trier par :\n1 - Nom\n2 - Prix\nSaisir:");
    scanf("%d", &choix_utilisateur);

    do
    {
        if( choix_utilisateur == 1 )
        {
            for( i = 0; i < nb; i++)
            {
                for( j = 0; j < (nb-1); j++)
                {
                   // strlwr(listeProd[j].nom); //Met en minuscule la chaîne de charactère
                    resultat_strcoll = strcoll(listeProd[j].nom,listeProd[j+1].nom); //Triage
                    if( resultat_strcoll > 0 )
                    {
                        copieProd(listeProd[j],&prdTmp);
                        copieProd(listeProd[j+1],&listeProd[j]);
                        copieProd(prdTmp,&listeProd[j+1]);
                    }
                }
            }
        }
        else if( choix_utilisateur == 2 )
        {
            for( i = 0; i < nb; i++)
            {
                for( j = 0; j < (nb-1); j++)
                {
                   // strlwr(listeProd[j].nom); //Met en minuscule la chaîne de charactère
                    if( listeProd[j].prix > listeProd[j+1].prix )
                    {
                        copieProd(listeProd[j],&prdTmp);
                        copieProd(listeProd[j+1],&listeProd[j]);
                        copieProd(prdTmp,&listeProd[j+1]);
                    }
                }
            }
        }
        else
        {
            printf("Taper 1 ou 2 !\n");
        }
    }while ( choix_utilisateur != 1 && choix_utilisateur != 2 );
}
void copieProd(PROD prdSource, PROD*prDdestination){
    strcpy(prDdestination->designation, prdSource.designation);
    strcpy(prDdestination->nom, prdSource.nom);
    prDdestination->prix = prdSource.prix;
}

int inserer_un_produit(PROD* listeProd,int nb, int choix_utilisateur){

    listeProd[nb] = saisir_produit();
    return 1;
}

int rechercher_produit(int nb, PROD*listProduit){
    int i;
    PROD prd_recheche;
    int choix_utilisateur;

    printf("Rechercher un produit ? ( 1 - Oui , 2 - Non )\n");
    scanf("%d", &choix_utilisateur);
    if ( choix_utilisateur == 1 )
    {
        printf("Saisir un produit a rechercher :\n");
        scanf("%s", prd_recheche.nom);
        prd_recheche.nom[39] = '\0';
        fflush(stdin);
        for( i = 0; i < nb; i ++)
        {
            if( strcmp(prd_recheche.nom,listProduit[i].nom) == 0 )
            {
                printf("Index du produit %s :\n", listProduit[i].nom);
                affiche_produit(listProduit[i]);
            }
        }
    }
}

/**
 *
 * @param nb
 * @param listProduit
 * @param choix_utilisateur
 * @return
 * 1 si suppression sinon 0
 */
int supprimer_produit(int nb, PROD*listProduit, PROD prd_supp) {
    int i;
    int j;

    for (i = 0; i < nb; i++) {
        if (strcmp(prd_supp.nom, listProduit[i].nom) == 0
            && strcmp(prd_supp.designation, listProduit[i].designation) == 0
            && prd_supp.prix == listProduit[i].prix) {
            for (j = 0; j < (nb - i); j++) {
                copieProd(listProduit[i + 1],&listProduit[i] );
            }
        }
    }
    return 1;
}
/**
Fonction d'enregistrement d'une liste de produit dans un fichier
identifié par son nom (ça peut être un path "C:\\fileproduit\fichierproduit.txt")
*/
void save_tabproduit_in_file(int nb, PROD*listProduit){
    FILE* fp_write = NULL;
    int i;
    fp_write= fopen("listeproduit.txt","w"); /**r:read ; w: write ; a : append ; r+ : lecture et ?criture*/

    if(!fp_write)
    {
        printf("Erreur de l'ouverture du fichier");
    }
    //traitement
    //CHANEL|Sac|6000
    //DELL|Ordinateur|1200
    for(i=0; i<nb; i++)
    {
        fprintf(fp_write,"%s|%s|%f\n",listProduit[i].nom, listProduit[i].designation, listProduit[i].prix);
    }
    fclose(fp_write);

}
/**
Fonction de chargement d'une liste de produit à partir d'un fichier externe
identifié par son nom (ça peut être un path "C:\\fileproduit\fichierproduit.txt")
Cette fonction retourne :
- le nombre de ligne du fichier => le nombre de produit
- si le fichier est vide ==> 0
*/
int load_tabproduit_from_file(PROD*listProduit) {
    FILE* fp_read = NULL;

    fp_read = fopen("listeproduit.txt", "r");
    if (!fp_read) {
        printf("Erreur d'ouverture du fichier");
        return 1;
    }
    char str[MAX_LISTE_SIZE];
    while (fgets(str, MAX_LISTE_SIZE, fp_read) != NULL)
        printf("%s", str);
    fclose(fp_read);
    return 0;
}