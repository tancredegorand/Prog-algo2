#include <iostream>

using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
};

struct DynaTableau{
    int* donnees;
    int nombre_val;
    int capacite; 
};











void initialise(Liste* liste)
{
    liste->premier = nullptr; 
}

bool est_vide(const Liste* liste)
{
    if (liste->premier == nullptr){
        return true; 
    }else{
        return false;
    }
}

void ajoute(Liste* liste, int valeur)
{   
    //si premier n est null alors creer un n
    if (liste->premier == nullptr){
        liste->premier = new Noeud; 
        liste->premier->donnee = valeur; 
        liste->premier->suivant = nullptr; 
    }
    else {
        Noeud* current = liste->premier;  //premier noeud
        while (current->suivant != nullptr){
            current = current->suivant; 
        }
        //crer le nouveau noeud
        Noeud* lastNoeud = new Noeud; 
        //assigner les valeurs
        lastNoeud->donnee = valeur; 
        lastNoeud->suivant = nullptr; 

        //ratacher à la liste; 
        current->suivant = lastNoeud; 
    }

 
}

void affiche(const Liste* liste)
{
    Noeud* current = liste->premier; 
    int count = 0; 
    while (current->suivant != nullptr){
        cout << "N - " << count << " : " << current->donnee << endl;  
        current = current->suivant; 
        count = count + 1; 
    }
    
}

int recupere(const Liste* liste, int n)
{
    Noeud* current = liste->premier; 
    int count = 0; 
    while (current->suivant != nullptr){
        if(count == n){
            return current->donnee; 
        }
        else {
            current = current->suivant; 
            count = count + 1; 
        }
    }
    

    return 0;
}

int cherche(const Liste* liste, int valeur)
{
    Noeud* current = liste->premier; 
    int count = 0; 

    while (current->suivant != nullptr)
    {
        if (current->donnee == valeur){
            return count; 
        }
        else {
            current = current->suivant; 
            count = count + 1; 
        }
    }
    
    return -1;
}

void stocke(Liste* liste, int n, int valeur)
{
    Noeud *current = liste->premier;
    int count = 0;
    while (current->suivant != nullptr)
    {
        if (count == n)
        {
            current->donnee = valeur;
        }
        current = current->suivant;
        count++;
    }
}















void ajoute(DynaTableau* tableau, int valeur)
{   
    if(tableau->capacite <= (tableau->nombre_val + 1)){
        tableau->capacite = tableau->capacite + 1; 
        tableau->donnees = (int*)realloc(tableau->donnees, tableau->capacite*sizeof(int));
    }
    tableau->donnees[tableau->nombre_val] = valeur;
    tableau->nombre_val += 1;

}


void initialise(DynaTableau* tableau, int capacite)
{  
    tableau->capacite = capacite; 
    tableau->nombre_val = 0; 
    tableau->donnees=(int*)malloc(sizeof(int)*capacite); //allouer mémoire
}

bool est_vide(const DynaTableau* tableau)
{
    if (tableau->nombre_val == 0){
        return true; 
    }
    return false;
}

void affiche(const DynaTableau* tableau)
{
    cout << "Tableau : " << endl; 
    for(int i=0; i < tableau->nombre_val; i++){
        cout << tableau->donnees[i] << endl;
    }

}

int recupere(const DynaTableau* tableau, int n)
{
    if (tableau->nombre_val > 0 && tableau->nombre_val > n){
        return tableau->donnees[n];
    }
    return 0;
}

int cherche(const DynaTableau* tableau, int valeur)
{
    int count = 0;
    for (int i = 0; i < tableau->nombre_val; i++){
        if (tableau->donnees[i] == valeur){
            return count;
        }
        count = count + 1;
    }

    return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    if (tableau->nombre_val > 0 && tableau->nombre_val > n){
        tableau->donnees[n] = valeur; 
    }
}













//void pousse_file(DynaTableau* liste, int valeur)
void pousse_file(Liste* liste, int valeur)
{
    Noeud *newNoeud = new Noeud;
    newNoeud->donnee = valeur;
    newNoeud->suivant = nullptr;
    if (liste->premier != nullptr){ 
        Noeud *current = liste->premier;
        while (current->suivant != nullptr){
            current = current->suivant;
        }
        current->suivant = newNoeud;
    }
    else{
        liste->premier = newNoeud;
    }
}


//int retire_file(Liste* liste)
int retire_file(Liste* liste)
{
    int firstVal = 0;
    if (liste->premier != nullptr){
        Noeud *firstNoeud = liste->premier;
        firstVal = firstNoeud->donnee;
        liste->premier = firstNoeud->suivant;
    }
    return firstVal;
}



//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(Liste* liste, int valeur)
{
    Noeud *newNoeud = new Noeud;
    newNoeud->donnee = valeur;
    newNoeud->suivant = nullptr;

    if (liste->premier != nullptr){ 
        Noeud *current = liste->premier;
        while (current->suivant != nullptr){
            current = current->suivant;
        }
        current->suivant = newNoeud;
    }
    else{
        liste->premier = newNoeud;
    }
}


//int retire_pile(DynaTableau* liste)
int retire_pile(Liste* liste)
{
    int lastVal = 0; 
    if (liste->premier != nullptr){
        Noeud* current = liste->premier; 
        while (current->suivant->suivant != nullptr)
        {
           current = current->suivant; 
        }
        lastVal = current->suivant->donnee; 
        current->suivant = nullptr;
    }
    return lastVal; 
}









int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoute(&tableau, i*5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherche(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise(&pile);
    initialise(&file);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while(!est_vide(&file) && compteur > 0)
    {
        std::cout << retire_file(&file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
