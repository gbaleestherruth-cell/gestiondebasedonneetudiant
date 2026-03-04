
#ifndef ETUDIANT_H
#define ETUDIANT_H

 /*defintionde la structure*/

typedef struct 
{
    char nom[50];
    char prenom[50];
    int id;
    float moyenne;


}etudiant;

typedef struct  
{
    etudiant *liste;

    int nmbretudiant; 
    int capacite;

}gestionetudiant;

                 /*prototype des fonctionprincipales*/


/*initilisation et memoire*/              
void initialiserdebase(gestionetudiant *bd);
void liberermemoire(gestionetudiant *bd);

/*gesttion de base de donne*/
void ajoueretudiant(gestionetudiant *bd);
void supprimeretudiant(gestionetudiant *bd, int id);
void modifieretudiant(gestionetudiant *bd, int id);

/*afficher et rechercher*/
void afficheretudiant(const gestionetudiant *bd);
void rechercheretudaint(const gestionetudiant *bd);

/*tri et option fichier*/
void trieretudaint(gestionetudiant *bd);
void sauvegardebinaire(const gestionetudiant *bd, const char *nomfichier);
void chargementbinaire(gestionetudiant *bd, const char *nomfichier);
void expotercsv(const gestionetudiant *bd, const char *nomfichier);

#endif