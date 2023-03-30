#ifndef GESTION_FOURNISSEUR_H_INCLUDED
#define GESTION_FOURNISSEUR_H_INCLUDED

#define MAX_SIZE_TAB_PROD_FOURNI 10
#define MAX_SIZE_TAB_FOURNI 100
#include "gestion_produit.h"


#define SAISIE_LST_FOURNI 1
#define CHARGE_FOURNI_FICHIER_EXTER 2
#define SUPPRIMER_FOURNISSEUR 3
#define AJOUTER_FOURNISSEUR 4
#define RECHERCHER_FOURNISSEUR 5
#define AFFICHER_LST_FOURNI 6
#define EXPORTER_LST_FOURNI 7


#define MENU_GERER_FOUNISSEUR 10
#define MODIF_FOURNI 15
#define AJOUT_LST_PROD_FOURNI 16
#define AJOUT_PROD_LST_PROD_FOURNI 17
#define MAJ_DET_PROD_LST_PROD_FOURNI 18
#define SUPP_PROD_LST_PROD_FOURNI 19
#define AFFICHER_LST_PROD_FOURNI 20
#define AFFICHER_DETAIL_PROD_FOURNI 21


#define REVENIR_MENU_PRINCPAL 22
#define QUITTER 23


struct Adresse
{
    int numero;
    char nomRue[30];
    char nomVille[30];
    int codePostal;
    char pays[30];
};
typedef struct Adresse ADR;

struct Date
{
    int jour;
    int mois;
    int annee;
};
typedef struct Date DATE;

struct Detail_Produit
{
    int code;
    float prix;
    float qteStock;
    DATE dateLimite;
};
typedef struct Detail_Produit DETPROD;

struct Fournisseur
{
    int code;
    ADR adresse;
    long tel;
    PROD tabListProduit[MAX_SIZE_TAB_PROD_FOURNI];
    DETPROD tabListDetailProd[MAX_SIZE_TAB_PROD_FOURNI];
    int nbProd;
};
typedef struct Fournisseur FOURNI;


void affiche_fournisseur(FOURNI frn); //fonction d'affichage de fournisseur
void affiche_liste_fournisseurs(FOURNI* listeFourni, int nb); //fonction d'affichage de fournisseur
FOURNI saisir_fournisseur(); // fonction de saisie de founisseur
ADR saisir_adresse(); // fonction de saisie d'adresse
void saisir_liste_fournisseurs(FOURNI* listeFourni,int nb); //fonction saisie de liste fournisseur
void tri_liste_fournisseurs_code(int nb, FOURNI* listeFourni);
void tri_liste_fournisseurs_tel(int nb, FOURNI* listeFourni);
int inserer_un_fournisseur(int nb,FOURNI* listeFourni);
int supprimer_un_fournisseur(int nb,FOURNI* listeFourni);
void rechercher_un_fournisseur(int nb,FOURNI* listeFourni);
int menu_fournisseur();
int menu_gerer_un_fournisseur();
bool rechercher_prod_fournisseur(FOURNI fournisseur, PROD prod_recherche);
FOURNI inserer_nouveau_produit_a_fournisseur(FOURNI fournisseur, PROD new_prod);
FOURNI ajouter_liste_produit_a_fournisseur(FOURNI* listeFourni, PROD listeProd[MAX_SIZE_TAB_PRODUIT], int code);
void afficher_liste_produit_fournisseur(FOURNI* listeFourni,int code, int nb);
FOURNI ajouter_produit_a_liste_produit_fournisseur(FOURNI* listeFourni,int code, int nb);
FOURNI supprimer_produit_liste_produit_fournisseur(FOURNI* listeFourni,int code, int nb);
FOURNI maj_detail_produit_fournisseur(FOURNI* listeFourni,int code, int nb);
DETPROD saisir_details_produit();
DATE saisir_date_limite();
void afficher_details_produit(FOURNI* listeFourni,int code, int nb);
void sauvegarder_liste_fournisseur(FOURNI* listeFourni, int nb_fournisseur);
int chargement_fournisseur_fichier(FOURNI* listeFourni);


#endif // GESTION_FOURNISSEUR_H_INCLUDED
