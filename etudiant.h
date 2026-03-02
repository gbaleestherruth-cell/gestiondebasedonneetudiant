
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

}basedonnees;

                 /*prototype des fonctionprincipales*/


/*initilisation et memoire*/              
void initialiserdebase(basedonnees *bd);
void liberermemoire(basedonnees *bd);

/*gesttion de base de donne*/
void ajoueretudiant(basedonnees *bd);
void supprimeretudiant(basedonnees *bd, int id);
void modifieretudiant(basedonnees *bd, int id);

/*afficher et rechercher*/
void afficheretudiant(const basedonnees *bd);
void rechercheretudaint(const basedonnees *bd);

/*tri et option fichier*/
void trieretudaint(basedonnees *bd);
void sauvegardebinaire(const basedonnees *bd, const char *nomfichier);
void chargementbinaire(basedonnees *bd, const char *nomfichier);
void expotercsv(const basedonnees *bd, const char *nomfichier);

#endif