#include<stdio.h>
#include<string.h>

struct etudiant{
	    int id;
	    char nom[50];
	    char prenom[50];
	    char date_nais[10];
	    char departement[50];
	    float note;
};


struct etudiant etudiants[1000];
int count=0;



int id_trouve(int id){
	for(int i=0 ; i<count ;i++){
		if(etudiants[i].id==id)
	    return i;
	}
	return -1;
}

void ajout(){
	int index;
	if(count>=1000){
		printf("impossibles d'ajouter un autre etudiant.\n");
	}else{
		 printf("\n ============= ajouter un etudiant ==================\n");
    	printf("l'etudiant %d :\n", count+1);
    
    	do{
    		printf("     entrer l'id d'etudiant:  ");
			scanf("%d",&etudiants[count].id);
			index= id_trouve(etudiants[count].id);
			if(index!= -1){
				printf("l id existe deja.\n");
			}
		}while(index != -1);
		printf("     entrer le nom d'etudiant:  ");
		scanf(" %s",etudiants[count].nom);
		printf("     entrer le prenom d'etudiant:  ");
		scanf(" %s",etudiants[count].prenom);
		printf("     entrer la date de naissance d'etudiant:  ");
		scanf(" %s",etudiants[count].date_nais);
		printf("     entrer le departement d'etudiant:  ");
		scanf(" %s",etudiants[count].departement);
		printf("     entrer la note generale d'etudiant:  ");
		scanf("%f",&etudiants[count].note);
		count++;		
	}
}

int recherche_etd(int num_unique){
	for(int i = 0 ; i < count ; i++){
		if(num_unique==etudiants[i].id)
		return i;
	}return -1;
}


void affiche_element(int i){
	printf("\n--- les informations de l'etudiant %d :---\n", i + 1);
	printf("     l'id d'etudiant: %d \n ",etudiants[i].id);        
	printf("     le nom d'etudiant: %s \n",etudiants[i].nom);
	printf("     le prenom d'etudiant: %s \n",etudiants[i].prenom);
	printf("     la date de naissance d'etudiant: %s \n",etudiants[i].date_nais);
	printf("     le departement d'etudiant: %s \n",etudiants[i].departement);
	printf("     la note generale d'etudiant: %f \n",etudiants[i].note);
	printf("------------------------------------------\n");
}

void modif_nom(int index){
	char nom_modifier[50];
		printf("le nom : %s\n",etudiants[index].nom);
		printf("entrer le nouvelle nom:  ");
		scanf(" %s",nom_modifier);
		strcpy(etudiants[index].nom,nom_modifier);
}


void modif_prenom(int index){
	char prenom_modifier[50];
		printf("le prenom : %s\n",etudiants[index].prenom);
		printf("entrer le nouvelle prenom:  ");
		scanf(" %s",prenom_modifier);
		strcpy(etudiants[index].prenom,prenom_modifier);
}


void modif_dat_nais(int index){
	char dat_nais_modifier[50];
		printf("la date de naissance : %s\n",etudiants[index].date_nais);
		printf("entrer la nouvelle date de naissance:  ");
		scanf(" %s",dat_nais_modifier);
		strcpy(etudiants[index].date_nais,dat_nais_modifier);
}

void modif_dep(int index){
	char dep_modifier[50];
		printf("le departement : %s\n",etudiants[index].departement);
		printf("entrer le nouvelle departement:  ");
		scanf(" %s",dep_modifier);
		strcpy(etudiants[index].departement,dep_modifier);
}



void modif_note(int index){
	int note_modifier;
	printf("la note : %f\n",etudiants[index].note);
	printf("entrer la nouvelle note:  ");
	scanf(" %f",&note_modifier);
	etudiants[index].note=note_modifier;
}


void modifier(){
	int choix;
	int id;
	int index;
	printf("\n =========== modification des informations des etudiants  ============\n");
	printf("entrer l'id de l etudiant dont on va faire la modification : ");
	scanf("%d",&id);
	index=recherche_etd(id);
	if(index!=-1){
		affiche_element(index);
	
	printf("1 : modifier le nom d'etudiant.\n");
	printf("2 : modifier le prenom d'etudiant.\n");
	printf("3 : modifier la date de naissance d'etudiant.\n");
	printf("4 : modifier le departement d'etudiant.\n");
	printf("5 : modifier la note d'etudiant.\n");
	printf("entrer un choix : ");
	scanf("%d",&choix);
	
   	switch(choix){
    	case 1:
    		modif_nom(index);
    		break;
    	case 2:
    		modif_prenom(index);
    		break;
    	case 3:
    		modif_dat_nais(index);
    		break;
    	case 4:
    		modif_dep(index);
    		break;
    	case 5:
    		modif_note(index);
    		break;
    	case 0:
    		printf("quitter le programme.\n");
    		break;
    	default:
    		printf("entrer un autre  choix.\n");
    		break;
		}
		printf("l'etudiant apres la modification: \n");
		affiche_element(index);
	}else{
		printf("l'etudiant n'existe pas.\n");
	}
}

void supprimer(){
	int id;
	printf("entrer l'id qui va etre supprimer: ");
	scanf("%d",&id);
	int index=recherche_etd(id);
	if(index!=-1){
		for(int i=index ; i<count-1 ; i++){
			etudiants[i]=etudiants[i+1];
		}count--;
	}else{
		printf("l'etudiant n'existe pas.\n");
	}
}



void afficher(){
	for(int i=0 ;i < count ;i++){
		affiche_element(i);
	}
}



void affiche_nb_total(){
	printf("\n--- le nombre total des etudiants ---\n");
	printf("le nombre totale des etudiants inscrits est: %d\n", count);
	printf("------------------------------------------\n");
}

void affiche_nb_etd_dep(){
	printf("\n----- nombre d'etudiants par dppartement -----:\n");
	char dep[20][50];
	int count_dep=0;
            for (int i = 0; i < count; i++) {
                int existe=0; 
                for (int j = 0; j < count_dep; j++) {
                    if (strcmp(etudiants[i].departement, etudiants[j].departement) == 0) {
                        existe = 1;
                        break;
                    }
                }if (!existe)
                strcpy(dep[count_dep], etudiants[i].departement);
        count_dep++;
        }
    for (int i = 0; i < count; i++)
    {
        int count_dep = 0;
        for (int j = 0; j < count; j++)
        {
            if (strcmp(dep[i], etudiants[j].departement) == 0)
            {
                count_dep++;
            }
        }
        printf("departement %s contient : %d etudiants\n", dep[i], count_dep);
    }
}

 
void affiche_etd_note_sup_seuil(){
	float seuil;
	printf("entrer un seuil : ");
	scanf("%f",&seuil);
	for(int i=0 ; i < count ; i++){
		if(etudiants[i].note > seuil){
		affiche_element(i);
		}
	}
}



 
void trois_prem_etd(){
 	struct etudiant tmp;
 	for(int i = 0 ; i < count-1 ; i++){
 		for (int j = i+1 ; j < count ; j++){
 			if( etudiants[i].note < etudiants[j].note){
 				tmp= etudiants[i];
 				etudiants[i] = etudiants[j];
 				etudiants[j] = tmp;
			}
	    }
    }
    printf("\n--- les 3 premiers etudiants ---\n");
 	for (int i = 0 ; i < 3 ; i++){
 		affiche_element(i);
	}
	printf("------------------------------------------\n");
}


void nb_etd_reus_dep(){
    int reussi=0;
    char dep[20];
    printf("entrer le nom de departement: ");
    scanf(" %s",dep);
    for (int i = 0; i < count; i++){
        if (strcmp(etudiants[i].departement, dep) == 0 && etudiants[i].note >= 10){
            reussi++;
        }
    }
    printf("Le nombre d'etudiants ayant reussi dans le departement %s:%d\n",dep,reussi);
}
   
 
 
 void calculer(){
 float somme_note_dep[30] = {0};
    int nb_etd_dep[30] = {0};
    char departements[30][50];
    int nbr_dep = 0;
    float somme_note_univer = 0;
    int nb_etd_univer = 0;
    for (int i = 0; i < count; i++) {
        int index_dep = -1;
        for (int j = 0; j < nbr_dep; j++) {
            if (strcmp(departements[j], etudiants[i].departement) == 0) {
                index_dep = j;
                break;
            }
        }
        if (index_dep == -1) {
            strcpy(departements[nbr_dep], etudiants[i].departement);
            index_dep = nbr_dep;
            nbr_dep++;
        }
        somme_note_dep[index_dep] += etudiants[i].note;
        nb_etd_dep[index_dep]++;
        
        somme_note_univer += etudiants[i].note;
        nb_etd_univer++;
    }

    printf("\n--- la moyenne generale de chaque departement ---\n");
    for (int i = 0; i < nbr_dep; i++) {
        float moyenne_dep = somme_note_dep[i] / nb_etd_dep[i];
        printf(" departement %s : moyenne generale = %f\n", departements[i], moyenne_dep);
    }

    float moyenne_univer = somme_note_univer / nb_etd_univer;
    printf("\n--- moyenne generale de l'universite ---\n");
    printf(" Moyenne generale = %f\n", moyenne_univer);
    printf("------------------------------------------\n");
}
 
 
 
void statistique(){
	int choix;
    printf("1 : afficher le nombre total d'étudiants inscrits.\n");
   	printf("2 : afficher le nombre d'étudiants dans chaque département.\n");
    printf("3 : afficher les étudiants ayant une moyenne générale supérieure à un certain seuil.\n");
    printf("4 : afficher les 3 étudiants ayant les meilleures notes.\n");
    printf("5 : afficher le nombre d'étudiants ayant réussi dans chaque département.\n");
    printf("entrer un choix : ");
	scanf("%d",&choix);
    switch(choix){
   	    case 1:
    		affiche_nb_total();
    		break;
        case 2:
    		affiche_nb_etd_dep();
    		break;
    	case 3:
    		affiche_etd_note_sup_seuil();
    		break;
    	case 4:
    		trois_prem_etd();
    		break;
    	case 5:
    		nb_etd_reus_dep();
    		break;
    	case 0:
    		printf("quitter le programme.\n");
    			break;
    	default:
    		printf("entrer un autre  choix.\n");
    		break;
	}
}

void rech_etd_nom(){
	char nom_a_rechercher[50];
	int existe = 0;
	printf("entrer le nom d'etudiant a rechercher: ");
	scanf(" %s",nom_a_rechercher);
	for(int i = 0; i < count; i++){
		if(strcmp(etudiants[i].nom,nom_a_rechercher)==0){
			affiche_element(i);
			existe = 1;
		}
	}if(!existe){
		printf("l'etudiant n'existe pas.\n");
	}
}

void affiche_etd_dep(){
	char dep_recherche[50];
	int exist = 0;
	printf("entrer le nom de departement: ");
	scanf(" %s",dep_recherche);
	for(int i = 0; i < count; i++){
		if(strcmp(etudiants[i].departement,dep_recherche)==0){
			affiche_element(i);
			exist = 1;
		}	
	}
	if(!exist){
		printf("pas d etudiants dans ce departement.\n");
	}
}

void recherche(){
	int choix;
	printf("1 : rechercher un étudiant par son nom.\n");
	printf("2 : afficher la liste des étudiants inscrits dans un département spécifique.\n");
	printf("entrer un choix : ");
	scanf("%d",&choix);
	switch(choix){
		case 1:
			rech_etd_nom();
			break;
		case 2:
			affiche_etd_dep();
			break;
		case 0:
			printf("quitter le programme.");
			break;
		default:
			printf("entrer un autre choix.\n");
			break;
	}
}

void tri_note(){
	struct etudiant tmp;
	for(int i = 0 ; i < count-1 ; i++){
 		for (int j = i+1 ; j < count ; j++){
 			if( etudiants[i].note < etudiants[j].note){
 			    tmp = etudiants[i];
 				etudiants[i] = etudiants[j];
 				etudiants[j] = tmp;
			}
	    }
    }
 	for (int i = 0 ; i < count ; i++){
 		affiche_element(i);
	}
}


void tri_alph(){
    struct etudiant tmp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(etudiants[i].nom, etudiants[j].nom) > 0) {
                tmp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = tmp;
            }
        }
    }
    for (int i = 0; i < count; i++) {
    	affiche_element(i);
	}
}


void tri_reuss() {
    struct etudiant tmp;
    int count_reuss = 0;
    for (int i = 0; i < count; i++) {
        if (etudiants[i].note >= 10) {
            etudiants[count_reuss++] = etudiants[i];
        }
    }
    for (int i = 0; i < count_reuss - 1; i++) {
        for (int j = i + 1; j < count_reuss; j++) {
            if (etudiants[i].note < etudiants[j].note)  {
                tmp = etudiants[i]; 
                etudiants[i] = etudiants[j]; 
                etudiants[j] = tmp;  
            }
        }
    }
    printf("les etudiants reussits en ordre croissant :\n");
    for (int i = 0; i < count_reuss; i++) {
    	affiche_element(i);
    }
}

void tri(){
	int choix;
	printf("1 : tri alphabétique des étudiants en fonction de leur nom.\n");
	printf("2 : tri des étudiants par moyenne générale, du plus élevé au plus faible ou inversement.\n");
	printf("3 : tri des étudiants selon leur statut de réussite.\n");
	printf("entrer un choix : ");
	scanf("%d",&choix);
	switch(choix){
		case 1:
			tri_alph();
			break;
		case 2:
			tri_note();
			break;
		case 3:
			tri_reuss();
			break;
		case 0:
			printf("quitter le programme.");
			break;
		default:
			printf("entrer un autre choix.\n");
			break;
	}
}

void menu(){
	int choix;
	do{
		printf("\n--- le menu principal ---\n");
		printf("1 : ajouter un etudiant.\n");
		printf("2 : modifier les informations d un etudiant.\n");
		printf("3 : supprimer un etudiant.\n");
		printf("4 : afficher les details d un etudiant.\n");
		printf("5 : calculer la moyenne generale.\n");
		printf("6 : les statistiques.\n");
		printf("7 : rechercher un etudiant.\n");
		printf("8 : trier un etudiant.\n");
		printf("entrer un choix : ");
		scanf("%d",&choix);
		switch(choix){
			case 1:
				ajout();
				break;
			case 2:
				modifier();
				break;
			case 3:
				supprimer();
				break;
			case 4:
				afficher();
				break;
			case 5:
				calculer();
				break;
			case 6:
				statistique();
				break;
			case 7:
				recherche();
				break;
			case 8:
				tri();
				break;
			case 0:
				printf("quitter le programme .\n");
				break;
			default:
				printf("entrer un autre choix.\n");
		}
	}while(choix!=0);
}


int main(){
	menu();
	return 0;
}
