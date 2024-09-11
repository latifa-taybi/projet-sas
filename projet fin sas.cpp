#include<stdio.h>
#include<string.h>

struct etudiant{
	    int id;
	    char nom[50];
	    char prenom[50];
	    char date_nais[10];
	    char departement[50];
	    int note;
};


struct etudiant etudiants[1000];
int count=0;


struct dep{
	char nom_dep[50];
	float somme_note;
	int nbr_etd;
};


struct dep departements[30];
int nbr_dep=0;



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
		scanf("%d",&etudiants[count].note);
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
	printf("l'etudiant %d :\n", i+1);
	printf("     l'id d'etudiant: %d \n ",etudiants[i].id);        
	printf("     le nom d'etudiant: %s \n",etudiants[i].nom);
	printf("     le prenom d'etudiant: %s \n",etudiants[i].prenom);
	printf("     la date de naissance d'etudiant: %s \n",etudiants[i].date_nais);
	printf("     le departement d'etudiant: %s \n",etudiants[i].departement);
	printf("     la note generale d'etudiant: %d \n",etudiants[i].note);
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
	printf("la note : %d\n",etudiants[index].note);
	printf("entrer la nouvelle note:  ");
	scanf(" %d",&note_modifier);
	etudiants[index].note=note_modifier;
}


void modifier(){
	int choix;
	int id;
	int index;
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
	printf("le nombre totale des etudiants inscrits est: %d\n", count);
}


void affiche_nb_etd_dep(){
	printf("tableau des departements et nombre d'etudiants :\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < nbr_dep; i++) {
        printf("D�partement : %s | Nombre d'�tudiants : %d\n", departements[i].nom_dep, departements[i].nbr_etd);
    }
    printf("------------------------------------------\n");
}

 
void affiche_etd_note_sup_seuil(){
	int seuil;
	printf("entrer un seuil : ");
	scanf("%d",&seuil);
	for(int i=0 ; i < count ; i++){
		if(etudiants[i].note > seuil){
		affiche_element(i);
		}
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
 	for (int i = 0 ; i < 3 ; i++){
 		affiche_element(i);
	}
}

void nb_etd_reus(){
	int existe = 0;
	for (int i = 0 ; i < count ; i++){	
		if (etudiants[i].note > 10 ){
			affiche_element(i);
			existe= 1;
		}
	}if (!existe){
		printf("aucun etudiant n'a reussi.\n");
	}
}
 
 
 
 
void statistique(){
	int choix;
    printf("1 : afficher le nombre total d'�tudiants inscrits.\n");
   	printf("2 : afficher le nombre d'�tudiants dans chaque d�partement.\n");
    printf("3 : afficher les �tudiants ayant une moyenne g�n�rale sup�rieure � un certain seuil.\n");
    printf("4 : afficher les 3 �tudiants ayant les meilleures notes.\n");
    printf("5 : afficher le nombre d'�tudiants ayant r�ussi dans chaque d�partement.\n");
    printf("entrer un choix : ");
	scanf("%d",&choix);
    switch(choix){
   	    case 1:
    		affiche_nb_total();
    		break;
/*        case 2:
    		affiche_nb_etd_dep();
    		break;*/
    	case 3:
    		affiche_etd_note_sup_seuil();
    		break;
    	case 4:
    		trois_prem_etd();
    		break;
    	case 5:
    		nb_etd_reus();
    		break;
    	case 0:
    		printf("quitter le programme.\n");
    			break;
    	default:
    		printf("entrer un autre  choix.\n");
    		break;
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
	printf("1 : rechercher un �tudiant par son nom.\n");
	printf("2 : afficher la liste des �tudiants inscrits dans un d�partement sp�cifique.\n");
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

void tri(){
	int choix;
	printf("1 : tri alphab�tique des �tudiants en fonction de leur nom.\n");
	printf("2 : tri des �tudiants par moyenne g�n�rale, du plus �lev� au plus faible ou inversement.\n");
	printf("3 : tri des �tudiants selon leur statut de r�ussite.\n");
	printf("entrer un choix : ");
	scanf("%d",&choix);
	switch(choix){
		case 1:
			tri_alph();
			break;
		case 2:
			tri_note();
			break;
/*		case 3:
			tri_reus();
			break;*/
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
/*			case 5:
				calculer();
				break;*/
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
