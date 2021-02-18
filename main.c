#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct info{
                        int numeros;
                        char nom[12];
                        char prenom[12];
                        char compte_gmail[20];
                    }info;
                    info sur;
            //LISTE DESFONCTION
            void ajouter();
            void suprimer();
            void modifier();
int main()
{
    char n[5];
    int x;
    do
        {
                printf("+++++++++++++++++++++++++++++++++++++++BONJOUR ET BIEN VENU DANS CE PROGRAMME .+++++++++++++++++++++++++++++++++++++++++++\n\n\n");
                    printf("\n");
                    puts("++++++++++++++QUE DESIRER VOUS FAIRE ?++++++++++++++++++++++++++++++++++++++++++");
                    printf("\n");
                    puts("1-POUR AJOUTER LES INFORMATION");printf("\n");
                    puts("2-POUR MODIFER LES INFORMATION DUN INDIVIDU");printf("\n");
                    puts("3-POUR SUPRIMER LES INFORMATION D`UN INDIVIDU");printf("\n");
                    scanf("%d",&x);
                    system("cls");
    switch(x)
            {
            case 1:
                ajouter();
                break;
            case 2:
                modifier();

                break;
            case 3:
                suprimer();

                break;
            default: puts("vous avez du faire une erreur lord de la saisi");
            }
            puts("VOULEZ VOUS RECOMENCER");
            printf("ENTRER OUI POUR SORTIR \n\n");
            scanf("%s",&n);
            system("cls");
        }while(strcmp(n,"oui")!=0);

    return 0;
}

void ajouter()
  {
  	    FILE*fichier;
    fichier=fopen("information.txt","a+");
      // RECUPERATION DES INFORMATION DE L`INDIVIDUE A ENREGISTRER
    printf("\n");
    puts("VOUS VOULEZ AJOUTER UN CANDIDAT");printf("\n");
    printf("\n");
    puts("ENTRER VOTRE NUMEROS TELEPHONIQUE");
    scanf("%9d",&sur.numeros);
    puts("ENTRER VOTRE NOM");
    scanf("%s",sur.nom);
    puts("ENTRER VOTRE PRENOM");
    scanf("%s",sur.prenom);
    puts("ENTRER VOTRE COMPTE gmail");
    scanf("%s",sur.compte_gmail);
    //ENREGIRTREMENT DANS LE FICHIER
        puts("UNE ERREUR EST SURVENUE LORSD DE L`OUVERTURE");
            fprintf(fichier,"%d %s %s %s",sur.numeros,sur.nom,sur.prenom,sur.compte_gmail);


    fclose(fichier);
    puts("FIN DE L`AJOUT DE L`INDIVIDUE");
  puts(" ");

  }



  void suprimer()
  { int z;
    puts("VOUS VOULER SUPRIMER UN CANDIDAT");printf("\n");
    puts("ENTRER LE NUMEROS DE L`INDIVIDU A SUPRIMER");printf("\n");
    scanf("%d",&z);
    FILE*dres;
	FILE*deux;
    deux=fopen("temporaire.txt","w+");
    dres=fopen("information.txt","r+");
    while(fscanf(dres,"%d %s %s %s",&sur.numeros,&sur.nom,&sur.prenom,&sur.compte_gmail)!=EOF)
    {
        if(sur.numeros!=z)
            {
                fprintf(deux,"%d %s %s %s",sur.numeros,sur.nom,sur.prenom,sur.compte_gmail);
            }
    }
    fclose(dres);
    fclose(deux);
    remove("information.txt");
    rename("temporaire.txt","information.txt");  puts(" ");
     puts("FIN DE LA SUPRESSION DE L`INDIIDUE");
      
  }



  void modifier(){
      int z;
      printf("\n");
    puts("VOUS VOULER MODIFIER UN CANDIDAT");printf("\n");
    puts("ENTRER LE NUMEROS DE L`INDIVIDU A SUPRIMER");printf("\n");
    scanf("%d",&z);
    FILE*dres;
	FILE*deux;
    deux=fopen("temporaire.txt","a+");
    dres=fopen("information.txt","r+");
    while(fscanf(dres,"%d %s %s %s",&sur.numeros,&sur.nom,&sur.prenom,&sur.compte_gmail)!=EOF)
    {
        if(sur.numeros==z)
            {
                // RECUPERATION DES INFORMATION DE L`INDIVIDUE A ENREGISTRER
    puts("VOUS VOULEZ AJOUTR UN CANDIDAT");printf("\n");
    puts("ENTRER VOTRE NUMEROS TELEPHONIQUE");printf("\n");
    scanf("%9d",&sur.numeros);
    puts("ENTRER VOTRE NOM");printf("\n");
    scanf("%s",sur.nom);
    puts("ENTRER VOTRE PRENOM");
    scanf("%s",sur.prenom);
    puts("ENTRER VOTRE COMPTE gmail");
    scanf("%s",sur.compte_gmail);
    //ENREGIRTREMENT DANS LE FICHIER
    fprintf(deux,"%d %s %s %s",sur.numeros,sur.nom,sur.prenom,sur.compte_gmail);
            }
        else
        {
            fprintf(deux,"%d %s %s %s",sur.numeros,sur.nom,sur.prenom,sur.compte_gmail);
        }
    }
    fclose(dres);
    fclose(deux);
    remove("information.txt");
    rename("temporaire.txt","information.txt");
        puts(" ");
        puts(" ");
      PUTS("FIN DE LA MODIFICATION .");
  }
