#include <time.h>
#include <vector>
#include <string>
#include <iostream>

struct Element
{
    std::string value;
    Element * next;

    Element(std::string value) {
        this->value = value;
        this->next = nullptr;
    }
};


int hash(std::vector<Element*> hash_table, std::string element)
{
    return (int) element[0] % hash_table.size();
}

void insert(std::vector<Element*>* hash_table, std::string element)
{
    if ((*hash_table)[hash(*hash_table, element)] == nullptr) {
        (*hash_table)[hash(*hash_table, element)] = new Element(element);
    }
    else {
        Element* aux = (*hash_table)[hash(*hash_table, element)];
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = new Element(element);
    }
}

bool contains(std::vector<Element*> hash_table, std::string element)
{
    if (hash_table[hash(hash_table, element)] == nullptr) {
        return false;
    }
    Element* aux = hash_table[hash(hash_table, element)];
    while (aux != nullptr) {
        if (aux->value == element) {
            return true;
        }
        aux = aux->next;
    }
    return false;
}

void display(Element * element) {
    Element * aux = element;
    while (aux != nullptr) {
        std::cout << aux->value << " ; ";
        aux = aux->next;
    }
    std::cout << std::endl;
}

void buildHashTable(std::vector<Element*>* hash_table, std::string* names, int namesCount)
{
    for (int i = 0; i < namesCount; i++) {
        insert(hash_table, names[i]);
    }
}

int main(int argc, char *argv[])

{
    /*std::vector<std::string> names({
        "Yolo", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
        "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
        "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
        "Leo", "Nils", "Vincent", "Paul", "Zoe", "Julien", "Matteo",
        "Fanny", "Jeanne", "Elo"
    });*/
    std::vector<std::string> names;
    names.push_back("Yolo");
    names.push_back("Anastasiya");
    names.push_back("Clement");
    names.push_back("Sirine");
    names.push_back("Julien");
    names.push_back("Sacha");
    names.push_back("Leo");

    std::vector<Element*> hash_table;
    hash_table.resize(names.size());
    for (int i = 0; i < names.size(); i++) {
        hash_table[i] = nullptr;
    }

    std::cout << "name size : " << names.size() << std::endl;
    for (int i = 0; i < names.size(); i++)
    {
        std::cout << names[i] << " " ;
    }
    std::cout << std::endl;

    std::cout <<"-----------" << std::endl; 


    buildHashTable(&hash_table, names.data(), names.size());
    
    for (int i = 0; i < names.size(); i++) {
        display(hash_table[i]);
    }

    std::cout <<"-----------" << std::endl; 
    std::cout << contains(hash_table, "Julien") << std::endl; 


}
