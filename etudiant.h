
#ifndef ETUDIANT_H
#define ETUDIANT_H

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
}gestionetudiant;

#endif