#include "gestion_produit.h"
#include "gestion_fournisseur.h"

int main()
{
    // Déclaration des variables
    PROD listeProd[MAX_SIZE_TAB_PRODUIT];
    PROD prd_supp;
    FOURNI listeFournisseur[MAX_SIZE_TAB_FOURNI];
    int nb_produit;
    int nb_fournisseur;
    int choix_utilisateur;
    int choix;
    int code_founisseur;


    /// Gestion des Produits
    do
    {
        printf("Introduire le nombre de produit a ajouter : \n");
        scanf("%d",&nb_produit);
    }
    while(nb_produit<=0||nb_produit>MAX_SIZE_TAB_PRODUIT);

    //saisie des données
    saisir_liste_produit(nb_produit,listeProd);
    affiche_liste_produit(listeProd,nb_produit);

    //tri des produits
    tri_liste_produit(nb_produit,listeProd);
    affiche_liste_produit(listeProd,nb_produit);

    //ajouter un produit
    printf("Saisir un nouveau produit ? ( 1 - Oui , 2 - Non )\n");
    scanf("%d", &choix_utilisateur);
    if( choix_utilisateur == 1 ){
        nb_produit+=inserer_un_produit(listeProd, nb_produit, choix_utilisateur);
    }
    affiche_liste_produit(listeProd,nb_produit);

    //recherche d'un produit
    rechercher_produit(nb_produit,listeProd);

    //supprimer un produit
    choix_utilisateur = 0;
    printf("Saisir un produit a supprimer ? ( 1 - Oui , 2 - Non )\n");
    scanf("%d", &choix_utilisateur);

    if( choix_utilisateur == 1 )
    {
        prd_supp = saisir_produit();
        nb_produit-=supprimer_produit(nb_produit, listeProd, prd_supp);
    }
    affiche_liste_produit(listeProd,nb_produit);

    //enregistrer les produits
    printf("Enregistrer les produits saisie ( 1 - OUI , 2 - NON ) ?\n");
    scanf("%d", &choix);

    if( choix == 1 )
    {
        save_tabproduit_in_file(nb_produit,listeProd);
    }

    //charger les produits
    printf("Charger les produits saisie ( 1 - OUI , 2 - NON ) ?\n");
    scanf("%d", &choix);

    if( choix == 1 )
    {
        load_tabproduit_from_file(listeProd);
    }

    printf("\nAffichage liste Produits enregistré :\n");



    //affichage
    printf("\nAffichage liste Produits :\n");
    affiche_liste_produit(listeProd,nb_produit);

    /// Gestion des Fournisseurs
    do
    {
        choix_utilisateur = menu_fournisseur();
        switch(choix_utilisateur)
        {
            case(SAISIE_LST_FOURNI):
                do
                {
                    printf("Introduire le nombre de fournisseur a ajouter : \n");
                    scanf("%d",&nb_fournisseur);
                }
                while(nb_fournisseur<=0||nb_fournisseur>MAX_SIZE_TAB_PRODUIT);
                saisir_liste_fournisseurs(listeFournisseur,nb_fournisseur);
                tri_liste_fournisseurs_code(nb_fournisseur, listeFournisseur);
                break;
            case(CHARGE_FOURNI_FICHIER_EXTER):
                nb_fournisseur = chargement_fournisseur_fichier(listeFournisseur);
                printf("%d\n", nb_fournisseur);
                break;
            case(SUPPRIMER_FOURNISSEUR):
                nb_fournisseur = supprimer_un_fournisseur(nb_fournisseur, listeFournisseur);
                tri_liste_fournisseurs_code(nb_fournisseur, listeFournisseur);
                break;
            case(AJOUTER_FOURNISSEUR):
                nb_fournisseur = inserer_un_fournisseur(nb_fournisseur,listeFournisseur);
                tri_liste_fournisseurs_code(nb_fournisseur, listeFournisseur);
                break;
            case(RECHERCHER_FOURNISSEUR):
                rechercher_un_fournisseur(nb_fournisseur, listeFournisseur);
                break;
            case(AFFICHER_LST_FOURNI):
                affiche_liste_fournisseurs(listeFournisseur,nb_fournisseur);
                break;
            case(EXPORTER_LST_FOURNI):
                sauvegarder_liste_fournisseur(listeFournisseur,nb_fournisseur);
                break;
            case(MENU_GERER_FOUNISSEUR):
                printf("Introduire le code du founisseur a gerer : ");
                scanf("%d",&code_founisseur);
                do
                {
                    choix_utilisateur = menu_gerer_un_fournisseur(code_founisseur);
                    switch(choix_utilisateur)
                    {
                        case(MODIF_FOURNI):
                            break;
                        case (AJOUT_LST_PROD_FOURNI):
                            ajouter_liste_produit_a_fournisseur(listeFournisseur,listeProd, code_founisseur);
                            break;
                        case(AJOUT_PROD_LST_PROD_FOURNI):
                            ajouter_produit_a_liste_produit_fournisseur(listeFournisseur,code_founisseur,nb_produit);
                            nb_produit++;
                            break;
                        case(MAJ_DET_PROD_LST_PROD_FOURNI):
                            maj_detail_produit_fournisseur(listeFournisseur,code_founisseur,nb_produit);
                            break;
                        case(SUPP_PROD_LST_PROD_FOURNI):
                            supprimer_produit_liste_produit_fournisseur(listeFournisseur,code_founisseur,nb_produit);
                            nb_produit--;
                            break;
                        case(AFFICHER_LST_PROD_FOURNI):
                            afficher_liste_produit_fournisseur(listeFournisseur,code_founisseur,nb_produit);
                            break;
                        case(AFFICHER_DETAIL_PROD_FOURNI):
                            afficher_details_produit(listeFournisseur,code_founisseur,nb_produit);
                        case(REVENIR_MENU_PRINCPAL) :
                            printf("Retour au menu principal\n");
                            break;
                        default:
                            break;
                    }
                }
                while(choix_utilisateur!=REVENIR_MENU_PRINCPAL);
                break;
            case(QUITTER):
                printf("Au revoir \n");
                break;
            default :
                break;
        }
    }
    while(choix_utilisateur != QUITTER);
    return 0;
}