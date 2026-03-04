#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "etudiant.h"


/*code d'initilisationde de la base de donnee (memoire)*/
void initialiserbase(gestionetudiant *db){

    db -> nmbretudiant = 0;
    db -> capacite = 5;

    db -> liste = malloc(db -> capacite * sizeof(etudiant));

    if (db -> liste == NULL){
        printf("erreur de memoire !\n");
        exit(1);
    }
    
}




/*verification de securite (liberation de la memoire RAM)*/
void liberermemoire(gestionetudiant *db){

    if (db -> liste != NULL){
        free(db -> liste);
        db -> liste = NULL;
    }
    db -> nmbretudiant = 0;
    db -> capacite = 0;
 
}



/*verificationde la capacite(cas ou la capacite est insuffissante)*/

void ajouteretudiant(gestionetudiant *db){

    if (db -> nmbretudiant >= db -> capacite)
    {
        int nouvellecapacite = db -> capacite + 5;

        etudiant *temp   = realloc(db -> liste, nouvellecapacite * sizeof(etudiant));

        if (temp == NULL){
            printf("erreur : plus de memoire disponible pour agrandir la base.\n");
            return;
        }


        /*mise a jour de adresse du tableau (ajouter la nouvelle liste)*/

        db -> liste = temp;
        db -> capacite = nouvellecapacite;
        printf("la capacite a augmenter à %d places\n", db-> capacite);
    }
    
        /*saisir les informatoins de  etudiant*/

          
        /*saisir et verification de id valide*/

        int idsaisi;
        int existe = 0;

        etudiant nouveletudiant;
        do{
           existe = 0;
           printf("entrez l'identifiant (un ID unique)");
           scanf("%d", &idsaisi);

           /*parcouru la base pour voir si ID est deja utiliser*/

           for (int i = 0; i < db->nmbretudiant; i++){
            if (db->liste[i].id == idsaisi){
                printf("Erreur : cet ID  (%d) est déja utiliser par %s !\n", idsaisi, db->liste[i].nom);
                existe = 1;
                break;
            } 
           
           }   
         
        } while (existe == 1);

        printf("entrez l'identifiant (UN ID UNIQUE) : ");
        scanf("%d" , &nouveletudiant.id);

        printf("nom : ");   
        scanf("%s" , nouveletudiant.nom);

        printf("prenom : ");
        scanf("%s" , nouveletudiant.prenom);

       /*regle de condiictions pour la moyenne*/
       do
       {
         printf("veillez saissir une moyenne compris en (0.0 à 20.0) : ");
         scanf("%f" , &nouveletudiant.moyenne);

         if (nouveletudiant.moyenne < 0 || nouveletudiant.moyenne > 20)
         {
            printf("erreur : la moyenne doit etre compris entre 0 et 20\n");
         }
         
       } while (nouveletudiant.moyenne < 0 || nouveletudiant.moyenne > 20);
       
        /*enregistrer final du nouvelle etudiant*/

        db -> liste[db -> nmbretudiant] = nouveletudiant;
        db -> nmbretudiant++;

        printf("Succés : etudiant ajouter\n");

    }


        /*afficher les donnees des etudiant*/

        void afficherliste(gestionetudiant *db){

            if (db->nmbretudiant == 0)
            {
                printf("la liste est actuellemnt vide.\n");

                return;
            }

            printf("\nLISTE DES ETUDIAINS (%d/%d)", db->nmbretudiant, db->capacite);
            printf("ID\t\t| NOM\t\t| PRENOM\t| moyenne\n");

            for (int i = 0; i < db->nmbretudiant; i++)
            {
                printf("%d | %s |%s | %.2f/20\n",
                    db->liste[i].id,
                    db->liste[i].nom,
                    db->liste[i].prenom,
                    db->liste[i].moyenne);
            }
            

        }
        
 
        void modifieretudiant(gestionetudiant *db, int id){

            int trouve = 0;
            for ( int i = 0; i < db->nmbretudiant; i++){
                
                if (db->liste[i].id == id)
                {
                   trouve = 1;
                   printf("modification de l'étudiant : %s %s\n", db->liste[i].nom, db->liste[i].prenom);

                   printf("modifier le nom : ");
                   scanf("%s" , db->liste[i].nom);

                   printf("modifer le prenom : ");
                   scanf("%s" , db->liste[i].prenom);

                   do
                   {
                    printf("modifier la moyenne de 0.0 a 20.0");
                    scanf("%f" , &db->liste[i].moyenne);
                    if (db->liste[i].moyenne < 0 || db->liste[i].moyenne > 20)
                    {
                        printf("erreur : la moyenne dois etre compris en 0.0 et 20.0.\n");
                    }
                    
                   } while (db->liste[i].moyenne < 0 || db->liste[i].moyenne > 20);
                   

                   printf("la modification a été effecuer avec succés");
                   break;

                } 
                
                if (!trouve)
                {
                    printf("Erreur : aucun etudiant  avec ID %d  à été retrouver\n", id);
                }
            }

        }

        void rechercheretudiant(const gestionetudiant *db){

            char nomrechercher[50];
            int trouve = 0;

            printf("Entrez le nom de etudiant que vous rechercher\n");
            scanf("%s" , nomrechercher);

            for ( int i = 0; i < db->nmbretudiant; i++){
                if (strcmp(db->liste[i].nom, nomrechercher) == 0)
                {
                    
                    printf("ID: %d | %s %s | moyenne: %2f/20\n",
                        db->liste[i].id,
                        db->liste[i].nom,
                        db->liste[i].prenom,
                        db->liste[i].moyenne);
                        trouve = 1;
                }
            
            }

                if (trouve == 1)
                {
                    printf("aucun etudiant au nom de '%s'.\n", nomrechercher);
                } 
    
        }


        void trieretudiant(gestionetudiant *db){


            if (db->nmbretudiant < 2) return;
           
             int choix;
             printf("Trier par : 1. NOM | 2. MOYENNE");
             scanf("%d" , &choix);
            
             for (int i = 0; i < db->nmbretudiant - 1; i++){
                for (int  j = 0; j < db->nmbretudiant -i - 1; i++){

                    int condition = 0;
                    if (choix == 1){
                        if (strcmp(db->liste[j].nom, db->liste[j + 1].nom) > 0) condition = 1;

                    }
                    else{
                        
                        if (db->liste[j].moyenne < db->liste[j + 1].moyenne) condition = 1;
                    }

                    if (condition)
                    {
                        etudiant temp = db->liste[j];
                        db->liste[j] = db->liste[j + 1];
                        db->liste[j + 1] = temp;
                    }
                    
                }
                
             }
             

            printf("la liste a été trier avec succés !\n");

        }
        
        void suprimeretudiant(gestionetudiant *db, int id){

            int index = -1;

             /*rechercher etudiant par id*/

            for (int  i = 0; i < db->nmbretudiant; i++){
                if (db->liste[i].id == id){
                    index = i;
                    break;  
                }   
                
            } 

            if (index != -1){
             for (int  i = index; i < db->nmbretudiant -1; i++){
                
                db->liste[i] = db->liste[i +1];
             }

             db->nmbretudiant--;
             printf("etudiant suprimer.\n"); 
            } 
            else{
                printf("ID introuvable.\n");
            }
                  
        }
        

        void chargementbinaire(gestionetudiant *db, const char *nomfichier){

            /*mode rb*/
            FILE *fichier = fopen(nomfichier, "rb");

            if (fichier == NULL)
            {
                printf("aucune sauvegarde existante. demarrage d'une nouvelle base.\n");
                return;
            }
             /*lire le nombre etudiant sauves*/

            int nombrelus;
            fread(&nombrelus, sizeof(int), 1, fichier);


            /*liberer et allouer la taille exact lue*/
            free(db->liste);
            db->liste = malloc(nombrelus * sizeof(etudiant));

            if (db->liste == NULL && nombrelus > 0)
            {
                printf("Erreur : memoire au chargement.\n");
                fclose(fichier);
                return;
            }
            
            /*charger tout le tableau*/

            fread(db->liste, sizeof(etudiant), nombrelus, fichier);

            /*compteur mis a jout */
            db->nmbretudiant = nombrelus;
            db->capacite = nombrelus;

            fclose(fichier);

            printf("chargement reussi : %d etudiant recuperes !\n", nombrelus);

        }

        void expotercsv(const gestionetudiant *db, const char *nomfichier){

            /*mode "w"*/
            FILE *fichier = fopen(nomfichier, "w");

            if (fichier == NULL)
            {
                printf("Erreur : de creation du CSV.\n");
            }

            fprintf(fichier, "ID;NOM;PRENOM;MOYENNE\n");
            
            for (int  i = 0; i < db->nmbretudiant; i++)
            {
                fprintf(fichier,"%d;%s%s;%.2f\n",
                db->liste[i].id,
                db->liste[i].nom,
                db->liste[i].prenom,
                db->liste[i].moyenne);

            }
            fclose(fichier);
            printf("EXportation CSV terminée ! %s\n", nomfichier);
            
        
        }


    
        

  



