#include <stdio.h>

//Definition structure representer place parking
typedef struct 
{
    int num; //numero place parking
    int etat; //1 si occuper 0 sinon
} PlaceParking;


// Déclaration des variables de nombre de places pour chaque type de parking
int nb_places_parking_personnel = 10;
int nb_places_parking_etudiant = 20;
int nb_places_parking_visiteur = 5;


void afficher_menu();

void initialiser_Personnel(PlaceParking Personnel[], int etat_initial, int nbPlaces);
void initialiser_Etudient(PlaceParking Etudient[], int etat_initial, int nbPlaces);
void initialiser_Visiteur(PlaceParking Visiteur[], int etat_initial, int nbPlaces);


void affiche_Personnel(PlaceParking Personnel[], int nbPlaces);
void affiche_Etudient(PlaceParking Etudient[], int nbPlaces);
void affiche_Visiteur(PlaceParking Visiteur[], int nbPlaces);

int trouver_Place_Libre_Personnel(PlaceParking Personnel[], int nbPlaces);
int trouver_Place_Libre_Etudient(PlaceParking Etudient[], int nbPlaces);
int trouver_Place_Libre_Visiteur(PlaceParking Visiteur[], int nbPlaces);

void occuper_place_Personnel(PlaceParking Personnel[], int numPlace);
void occuper_place_Etudient(PlaceParking Etudient[], int numPlace);
void occuper_place_Visiteur(PlaceParking Visiteur[], int numPlace);

void liberer_place_Personnel(PlaceParking Personnel[], int numPlaceL);
void liberer_place_Etudient(PlaceParking Etudient[], int numPlaceL);
void liberer_place_Visiteur(PlaceParking Visiteur[], int numPlaceL);



int main()
{
    //Declaration tableau Parking
    PlaceParking Personnel[nb_places_parking_personnel];
    PlaceParking Etudient[nb_places_parking_etudiant];
    PlaceParking Visiteur[nb_places_parking_visiteur];

    initialiser_Personnel(Personnel, 0, nb_places_parking_personnel);
    initialiser_Etudient(Etudient, 0, nb_places_parking_etudiant);
    initialiser_Visiteur(Visiteur, 0, nb_places_parking_visiteur);

    int choix = 0;
    char entrez[50];
    
    while (choix != 4)
    {
        afficher_menu();

        //Recuperer l'entrez utilisateur sous forme chaine de caractere
        while (fgets(entrez,sizeof(entrez),stdin))
        {
            //Convertir la chaine de caractere entrez en Entier
            if (sscanf(entrez, "%d", &choix) == 1 && choix >=1 && choix <=4) //RENVOYE 1 si conversion Reussi; 0 Si la comversion Echoue
            {
                break;
            }
            else
            {
                printf("\tEURREUR!\n");
                printf("  La saisie doit etre un nombre entre 1 et 4.\n");
                printf("------------------------------------------\n");
                printf("VEUILLER SAISIR VOTRE CHOIX >> ");
            }
        }
        
        switch (choix)
        {
            case 1:
                printf("Place de parking: \n");
                affiche_Personnel(Personnel, nb_places_parking_personnel);
                printf("\n");
                affiche_Etudient(Etudient, nb_places_parking_etudiant);
                printf("\n");
                affiche_Visiteur(Visiteur, nb_places_parking_visiteur);
                break;

            case 2:
                printf("OCCUPER UNE PLACE\n");
                int type_parking, numPlace;
                
                printf("Type de parking (1 pour personnel, 2 pour étudiant, 3 pour visiteur) : ");
                scanf("%d", &type_parking);

                if (type_parking == 1)
                {
                    printf("Occuper Personnel\n");
                                    
                    printf("Numéro de place : ");
                    scanf("%d", &numPlace);

                    occuper_place_Personnel(Personnel, numPlace);                    
                }
                else if (type_parking == 2)
                {
                    printf("Occuper Etudient\n");
                                    
                    printf("Numéro de place : ");
                    scanf("%d", &numPlace);

                    occuper_place_Etudient(Etudient, numPlace);
                }
                else if (type_parking == 3)
                {
                    printf("Occuper Visiteur\n");
                                    
                    printf("Numéro de place : ");
                    scanf("%d", &numPlace);

                    occuper_place_Visiteur(Visiteur, numPlace);
                }
                break;


            case 3:
                printf("Liberer une Place\n");
                int type;
                int numPlaceL;
                printf("Type de parking (1 pour personnel, 2 pour étudiant, 3 pour visiteur) : ");
                scanf("%d", &type);

                if (type == 1)
                {
                    printf("Liberer Personnel\n");
                                    
                    printf("Numéro de place : ");
                    scanf("%d", &numPlaceL);

                    liberer_place_Personnel(Personnel, numPlaceL);
                }
                else if (type == 2)
                {
                    printf("Occuper Etudient\n");
                                    
                    printf("Numéro de place : ");
                    scanf("%d", &numPlaceL);

                    liberer_place_Etudient(Etudient, numPlaceL);
                }
                else if (type == 3)
                {
                    printf("Occuper Visiteur\n");
                                    
                    printf("Numéro de place : ");
                    scanf("%d", &numPlaceL);

                    liberer_place_Visiteur(Visiteur, numPlaceL);
                }
                break;                
                
            case 4:
                printf("Au revoir !\n");
            default:
            break;
        }
    }  
}

void afficher_menu()
{
    printf("======================================================================\n");
    printf("\t\tQue souhaitez-vous faire? \n\n");
    printf("\t[1] Voir l'etat du parking\n");
    printf("\t[2] Garer une voiture\n");
    printf("\t[3] Liberez une place \n");
    printf("\t[4] Quitter\n");
    printf("------------------------------------------\n");
    printf("VEUILLER SAISIR VOTRE CHOIX >> ");
}

//Initialiser Personnel
void initialiser_Personnel(PlaceParking Personnel[], int etat_initial, int nbPlaces)
{
    for (int i = 0; i < nbPlaces; i++)
    {
        Personnel[i].num = i+1;
        Personnel[i].etat = etat_initial;
    }   
}
//initialiser Etudient
void initialiser_Etudient(PlaceParking Etudient[], int etat_initial, int nbPlaces)
{
    for (int i = 0; i < nbPlaces; i++)
    {
        Etudient[i].num = i+1;
        Etudient[i].etat = etat_initial;
    }   
}
//initialiser Visiteur
void initialiser_Visiteur(PlaceParking Visiteur[], int etat_initial, int nbPlaces)
{
    for (int i = 0; i < nbPlaces; i++)
    {
        Visiteur[i].num = i+1;
        Visiteur[i].etat = etat_initial;
    }   
}


//Afficher Place Parking
//Afficher Personnel
void affiche_Personnel(PlaceParking Personnel[], int nbPlaces)
{
    printf("Parking Pour Personnel: \n");
    for (int i = 0; i < nbPlaces; i++)
    {
        printf("Place numero %d : %s\n", Personnel[i].num, Personnel[i].etat ? "occuper" : "libre");
    }    
}
//Afficher Etudient
void affiche_Etudient(PlaceParking Etudient[], int nbPlaces)
{
    printf("Parking pour Etudient: \n");
    for (int i = 0; i < nbPlaces; i++)
    {
        printf("Place numero %d : %s\n", Etudient[i].num, Etudient[i].etat ? "occuper" : "libre");
    }   
}
//Afficher Visiteur
void affiche_Visiteur(PlaceParking Visiteur[], int nbPlaces)
{
    printf("Parking pour Visiteur");
    for (int i = 0; i < nbPlaces; i++)
    {
        printf("Place numero %d : %s\n", Visiteur[i].num, Visiteur[i].etat ? "occuper" : "libre");
    }   
}


//Trouver Place Libre
//PERSONNEL
int trouver_Place_Libre_Personnel(PlaceParking Personnel[], int nbPlaces)
{
    for (int i = 0; i < nbPlaces; i++)
    {
        if (!Personnel[i].etat)
        {
            return i;
        }
    }
    return -1;
}
//ETUDIENT
int trouver_Place_Libre_Etudient(PlaceParking Etudient[], int nbPlaces)
{
    for (int i = 0; i < nbPlaces; i++)
    {
        if (!Etudient[i].etat)
        {
            return i;
        }
    }
    return -1;
}
//VISITEUR
int trouver_Place_Libre_Visiteur(PlaceParking Visiteur[], int nbPlaces)
{
    for (int i = 0; i < nbPlaces; i++)
    {
        if (!Visiteur[i].etat)
        {
            return i;
        }
    }
    return -1;
}



//OCCUPER PLACE
//PERSONNEL
void occuper_place_Personnel(PlaceParking Personnel[], int numPlace)
{
    if (Personnel[numPlace-1].etat == 1)
    {
        printf("La place %d est deja occupee.\n", numPlace);
    }
    else if (Personnel[numPlace-1].etat == 0)
    {
        Personnel[numPlace-1].etat = 1;
        printf("Vous venez d'occuper la place %d.\n", numPlace);
    }
}
//ETUDIENT
void occuper_place_Etudient(PlaceParking Etudient[], int numPlace)
{
    if (Etudient[numPlace-1].etat == 1)
    {
        printf("La place %d est deja occupee.\n", numPlace);
    }
    else if (Etudient[numPlace-1].etat == 0)
    {
        Etudient[numPlace-1].etat = 1;
        printf("Vous venez d'occuper la place %d.\n", numPlace);
    }
}
//VISITEUR
void occuper_place_Visiteur(PlaceParking Visiteur[], int numPlace)
{
    if (Visiteur[numPlace-1].etat == 1)
    {
        printf("La place %d est deja occupee.\n", numPlace);
    }
    else if (Visiteur[numPlace-1].etat == 0)
    {
        Visiteur[numPlace-1].etat = 1;
        printf("Vous venez d'occuper la place %d.\n", numPlace);
    }
}


//Liberer une Place
//PERSONNEL
void liberer_place_Personnel(PlaceParking Personnel[], int numPlaceL)
{
    if(Personnel[numPlaceL-1].etat == 0)
    {
        printf("La place %d est deja libre.\n",numPlaceL);
    }
    else if (Personnel[numPlaceL-1].etat == 1)
    {
        Personnel[numPlaceL-1].etat = 0;
        printf("Vous venez de librer la place %d.\n", numPlaceL);
    }
}
//ETUDIENT
void liberer_place_Etudient(PlaceParking Etudient[], int numPlaceL)
{
    if(Etudient[numPlaceL-1].etat == 0)
    {
        printf("La place %d est deja libre.\n",numPlaceL);
    }
    else if (Etudient[numPlaceL-1].etat == 1)
    {
        Etudient[numPlaceL-1].etat = 0;
        printf("Vous venez de librer la place %d.\n", numPlaceL);
    }
}
//VISITEUR
void liberer_place_Visiteur(PlaceParking Visiteur[], int numPlaceL)
{
    if(Visiteur[numPlaceL-1].etat == 0)
    {
        printf("La place %d est deja libre.\n",numPlaceL);
    }
    else if (Visiteur[numPlaceL-1].etat == 1)
    {
        Visiteur[numPlaceL-1].etat = 0;
        printf("Vous venez de librer la place %d.\n", numPlaceL);
    }
}
