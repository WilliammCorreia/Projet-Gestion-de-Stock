#include "gestion_fournisseur.h"


void affiche_fournisseur(FOURNI frn)
{
    printf("Fournisseur <%d>\n", frn.code);
}
void affiche_liste_fournisseurs(FOURNI* listeFourni, int nb)
{
    int i; // Boucle
    for( i = 0; i < nb; i ++ )
    {
        affiche_fournisseur(listeFourni[i]);
    }
}

FOURNI saisir_fournisseur()
{
    FOURNI foutmp;
    printf("Introduire le code :\n");
    scanf("%d", &foutmp.code);
    foutmp.adresse = saisir_adresse();
    printf("Saisir le numero de telephone :\n");
    scanf("%ld", &foutmp.tel);
    printf("Saisir le nombre de produit(s) :\n");
    scanf("%d", &foutmp.nbProd);

    return foutmp;
}

ADR saisir_adresse()
{
    ADR adrtmp;
    printf("Saisir une adresse :\n");
    printf("Saisir le numero de la rue :\n");
    scanf("%d", &adrtmp.numero);
    printf("Saisir le nom de la rue :\n");
    scanf("%s", adrtmp.nomRue);
    adrtmp.nomRue[29] = '\0';
    fflush(stdin);
    printf("Saisir le nom de la ville :\n");
    scanf("%s", adrtmp.nomVille);
    adrtmp.nomVille[29] = '\0';
    fflush(stdin);
    printf("Saisir le code postal :\n");
    scanf("%d", &adrtmp.codePostal);
    printf("%s", adrtmp.pays);
    adrtmp.pays[29] = '\0';
    fflush(stdin);

    return adrtmp;
}
void saisir_liste_fournisseurs(FOURNI* listeFourni,int nb)
{
    int i;
    for(i=0; i< nb;i++){
        listeFourni[i] = saisir_fournisseur();
    }
}
void tri_liste_fournisseurs_code(int nb, FOURNI* listeFourni)
{
    int i; // Boucle 1
    int j; // Boucle 2
    FOURNI LstFouTmp; // Liste Fournisseur Permutation

    for( i = 0; i < nb; i++ )
    {
        for( j = 0; j < (nb-1); j++)
        {
            if( listeFourni[j].code > listeFourni[j+1].code )
            {
                LstFouTmp = listeFourni[j];
                listeFourni[j] = listeFourni[j+1];
                listeFourni[j] = LstFouTmp;
            }
        }
    }
}

void tri_liste_fournisseurs_tel(int nb, FOURNI* listeFourni)
{

//TO DO

}
int inserer_un_fournisseur(int nb,FOURNI* listeFourni)
{
    listeFourni[nb] = saisir_fournisseur();
    nb++;
    return nb;
}

int supprimer_un_fournisseur(int nb,FOURNI* listeFourni)
{
    int i; // Boucle 1
    int j; // Boucle 2
    int code; // Code du fournisseur

    printf("Saisir le code du fournisseur a supprimer :\n");
    scanf("%d", &code);

    for (i = 0; i < nb; i++) {
        if ( code == listeFourni[i].code )
        {
            for (j = 0; j < (nb - i); j++)
            {
                listeFourni[i] = listeFourni[i+1];
            }
        }
    }
    nb--;
    return nb;
}

void rechercher_un_fournisseur(int nb,FOURNI* listeFourni)
{
    int code; // Code du fournisseur
    int i; // Boucle
    printf("Saisir le code du fournisseur a rechercher :\n");
    scanf("%d", &code);
    for( i = 0; i < nb; i ++)
    {
        if( code == listeFourni[i].code )
        {
            affiche_fournisseur(listeFourni[i]);
        }
    }
}

int menu_fournisseur()
{
    int choix;
    do
    {
        printf("********* Menu 1 : Gestion des fournisseurs *********\n");
        printf("Introduire votre choix :\n");
        printf("-%d Saisie Liste Fournisseurs\n",SAISIE_LST_FOURNI);
        printf("-%d Chargement Fournisseurs from File\n",CHARGE_FOURNI_FICHIER_EXTER);
        printf("-%d Supprimer Fournisseurs\n",SUPPRIMER_FOURNISSEUR);
        printf("-%d Ajouter Fournisseurs\n",AJOUTER_FOURNISSEUR);
        printf("-%d Rechercher Fournisseurs\n",RECHERCHER_FOURNISSEUR);
        printf("-%d Afficher Liste Fournisseurs\n",AFFICHER_LST_FOURNI);
        printf("-%d Exporter Liste Fournisseurs\n",EXPORTER_LST_FOURNI);
        printf("-%d *** Menu gerer un fournisseur *** \n",MENU_GERER_FOUNISSEUR);
        printf("-%d QUITTER\n",QUITTER);
        scanf("%d",&choix);
    }
    while(choix!= SAISIE_LST_FOURNI
            && choix != CHARGE_FOURNI_FICHIER_EXTER
            && choix != SUPPRIMER_FOURNISSEUR
            && choix != QUITTER
            && choix != MENU_GERER_FOUNISSEUR
            && choix != AJOUTER_FOURNISSEUR
            && choix != RECHERCHER_FOURNISSEUR
            && choix != AFFICHER_LST_FOURNI
            && choix != EXPORTER_LST_FOURNI
         );
    return choix;
}

int menu_gerer_un_fournisseur(int code_fournisseur){
/*
Plan du menu
Modifier un fournisseur
• Ajouter une liste de produit à un fournisse
• Ajouter un produit à la liste produit du fournisseur
• Mettre à jour le détail de produit d’un produit d’un fournisseur
• Supprimer un produit dans la liste de produit du fournisseur
• Afficher la liste de produit du fournisseur
• Revenir au menu 1
*/

 int choix;
    do
    {
        printf("******** Menu 2 : Gerer founisseur < %d > ********\n",code_fournisseur);
        printf("Introduire votre choix :\n");
        printf("-%d Modifier un fournisseur\n",MODIF_FOURNI);
        printf("-%d Ajouter une liste de produit au fournisseur\n",AJOUT_LST_PROD_FOURNI);
        printf("-%d Ajouter produit à la liste du fournisseur\n",AJOUT_PROD_LST_PROD_FOURNI);
        printf("-%d Mettre a jour le detail de produit d'un produit du fournisseur\n", MAJ_DET_PROD_LST_PROD_FOURNI);
        printf("-%d Supprimer un produit dans la liste de produit du fournisseur\n", SUPP_PROD_LST_PROD_FOURNI);
        printf("-%d Afficher la liste produit du fournisseur\n",AFFICHER_LST_PROD_FOURNI);
        printf("-%d Afficher les details d un produit du fournisseur\n",AFFICHER_DETAIL_PROD_FOURNI);
        printf("-%d Revenir au menu principal\n",REVENIR_MENU_PRINCPAL);
        scanf("%d",&choix);
    }
    while(choix != MODIF_FOURNI
            && choix != AJOUT_LST_PROD_FOURNI
            && choix != AJOUT_PROD_LST_PROD_FOURNI
            && choix != REVENIR_MENU_PRINCPAL
            && choix != MAJ_DET_PROD_LST_PROD_FOURNI
            && choix != SUPP_PROD_LST_PROD_FOURNI
            && choix != AFFICHER_LST_PROD_FOURNI
            && choix != AFFICHER_DETAIL_PROD_FOURNI
         );
    return choix;
}

/**
Rechercher un produit dans le tableau des produit d'un fournisseur
et de retourner true s'il est retrouvé
et de retourner false s'il n'est pas retrouvé
*/
bool rechercher_prod_fournisseur(FOURNI fournisseur, PROD prod_recherche)
{

//les variables
    int i;
    bool retrouve = false;
    for(i=0; retrouve == false && i<fournisseur.nbProd; i++)
    {
        if(strcmp(fournisseur.tabListProduit[i].designation,prod_recherche.designation) == 0
                &&
                strcmp(fournisseur.tabListProduit[i].nom, prod_recherche.nom) == 0
                &&
                fournisseur.tabListProduit[i].prix==prod_recherche.prix)
        {
            retrouve = true;
        }
    }
    return retrouve;
}
/**
Insérer un nouveau produit dans un founisseur
Le produit doit etre déja non existant dans le tableau des produits du fournisseurs
Cette fonction doit être appelée une fois la recherche du nouveau produit a retourné flase (0)
*/
FOURNI inserer_nouveau_produit_a_fournisseur(FOURNI fournisseur, PROD new_prod)
{


}

FOURNI ajouter_liste_produit_a_fournisseur(FOURNI* listeFourni, PROD listeProd[MAX_SIZE_TAB_PRODUIT], int code)
{
    int i; // Boucle

    for( i = 0; i < MAX_SIZE_TAB_PROD_FOURNI; i++)
    {
        strcpy(listeFourni[code].tabListProduit[i].nom, listeProd[i].nom);
        strcpy(listeFourni[code].tabListProduit[i].designation, listeProd[i].designation);
        listeFourni[code].tabListProduit[i].prix = listeProd[i].prix;
    }
    return* listeFourni;
}

void afficher_liste_produit_fournisseur(FOURNI* listeFourni,int code, int nb)
{
    int i; // Boucle

    printf("              NOM             |          DESIGNATION         |    PRIX    \n");
    for( i = 0; i < nb; i++ )
    {
        printf("%30s|%30s|%4.3f\n",listeFourni[code].tabListProduit[i].nom,listeFourni[code].tabListProduit[i].designation, listeFourni[code].tabListProduit[i].prix);
    }
}

FOURNI ajouter_produit_a_liste_produit_fournisseur(FOURNI* listeFourni,int code, int nb)
{
    listeFourni[code].tabListProduit[nb] = saisir_produit();

    return* listeFourni;
}

FOURNI supprimer_produit_liste_produit_fournisseur(FOURNI* listeFourni,int code, int nb)
{
    int i;
    int j;
    PROD prd_supp;

    printf("Saisir le produit a supprimer\n");

    prd_supp = saisir_produit();

    for (i = 0; i < nb; i++) {
        if (strcmp(prd_supp.nom, listeFourni[code].tabListProduit[i].nom) == 0
            && strcmp(prd_supp.designation, listeFourni[code].tabListProduit[i].designation) == 0
            && prd_supp.prix == listeFourni[code].tabListProduit[i].prix) {
            for (j = 0; j < (nb - i); j++) {
                copieProd(listeFourni[code].tabListProduit[i + 1],&listeFourni[code].tabListProduit[i] );
            }
        }
    }
    return* listeFourni;
}

FOURNI maj_detail_produit_fournisseur(FOURNI* listeFourni,int code, int nb)
{
    int i; // Boucle
    int j; // Boucle 2
    PROD prd;

    printf("Saisir le produit dont les details devront etre mis a jour :\n");

    prd = saisir_produit();

    for (i = 0; i < nb; i++) {
        if (strcmp(prd.nom, listeFourni[code].tabListProduit[i].nom) == 0
            && strcmp(prd.designation, listeFourni[code].tabListProduit[i].designation) == 0
            && prd.prix == listeFourni[code].tabListProduit[i].prix) {
            for (j = 0; j < (nb - i); j++) {
                listeFourni[code].tabListDetailProd[i] = saisir_details_produit();
            }
        }
    }
    return* listeFourni;
}

DETPROD saisir_details_produit()
{
    DETPROD prdtmp;

    printf("Saisir le code du produit\n");
    scanf("%d", &prdtmp.code);
    printf("Saisir le prix du produit\n");
    scanf("%f", &prdtmp.prix);
    printf("Saisir la quantite de stock du produit\n");
    scanf("%f", &prdtmp.qteStock);
    printf("Saisir la date limite\n");
    prdtmp.dateLimite = saisir_date_limite();

    return prdtmp;
}

DATE saisir_date_limite()
{
    DATE prddate;

    printf("Saisir le jour :\n");
    scanf("%d", &prddate.jour);
    printf("Saisir le mois (en chiffre) :\n");
    scanf("%d", &prddate.mois);
    printf("Saisir l annee (en chiffre) :\n");
    scanf("%d", &prddate.annee);

    return prddate;
}

int choix_produit_a_detaille(FOURNI* listeFourni,int code, int nb)
{
    int emplacement;

    printf("Saisir l'emplacement du produit a detaille :\n");
    scanf("%d", &emplacement);

    return emplacement;
}

void afficher_details_produit(FOURNI* listeFourni,int code, int nb)
{
    int emplacement;

    printf("Saisir l'emplacement du produit a detaille :\n");
    scanf("%d", &emplacement);
    emplacement--;

    printf("***** Detail du produit *****\n");
    printf("Code : %d\n", listeFourni[code].tabListDetailProd[emplacement].code);
    printf("Prix : %f\n", listeFourni[code].tabListDetailProd[emplacement].prix);
    printf("Quantite de stock : %f\n", listeFourni[code].tabListDetailProd[emplacement].qteStock);
    printf("Date limite : %d/%d/%d\n", listeFourni[code].tabListDetailProd[emplacement].dateLimite.jour, listeFourni[code].tabListDetailProd[emplacement].dateLimite.mois, listeFourni[code].tabListDetailProd[emplacement].dateLimite.annee);
}

void sauvegarder_liste_fournisseur(FOURNI* listeFourni, int nb_fournisseur)
{
    FILE* fp_write = NULL;
    int i;
    fp_write= fopen("listefournisseur.txt","w"); /**r:read ; w: write ; a : append ; r+ : lecture et ?criture*/

    if(!fp_write)
    {
        printf("Erreur de l'ouverture du fichier");
    }

    //Sauvegarde de la liste de fournisseur
    for(i=0; i<nb_fournisseur; i++)
    {
        fprintf(fp_write,"%d\n", listeFourni[i].code);
    }
    fclose(fp_write);
}

int chargement_fournisseur_fichier(FOURNI* listeFourni)
{
    FILE* fp_read = NULL;
    int i = 0; //incrémentation

    fp_read = fopen("listefournisseur.txt", "r");
    if (!fp_read)
    {
        printf("Erreur d'ouverture du fichier");
        return 1;
    }
    char ligne[256];

    while(fgets(ligne, 255, fp_read) != NULL)
    {
        printf("Test\n");
        sscanf(ligne, "%d", &listeFourni[i].code);
        printf("Position : %ld\n", ftell(fp_read));
        i++;
    }

    fclose(fp_read);
    return i;
}