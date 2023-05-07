
#include <ctime>
#include <iostream>
#include <string>
#include <vector>


using std::size_t;
using std::string;


unsigned long int hash(string key)
{
    unsigned long int hash = 5381;
    int c;

    for (size_t i = 0; i < key.length(); i++) {
        c = key.at(i);
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

struct MapNode
{

    string key;
    unsigned long int key_hash;

    int value;

    MapNode* left;
    MapNode* right;

    MapNode(string key, int value)
    {
        this->key = key;
        this->value = value;
        this->key_hash = hash(key);

        this->left = this->right = nullptr;
    }

};

struct Map
{
    Map() {
        this->root = nullptr;
    }

    void insert(MapNode* node, MapNode* newNode)
    {
        if (newNode->key_hash < node->key_hash) {
            if (node->left == nullptr) {
                node->left = newNode;
            } else {
                insert(node->left, newNode);
            }
        } else {
            if (node->right == nullptr) {
                node->right = newNode;
            } else {
                insert(node->right, newNode);
            }
        }
    }

    void insert(string key, int value)
    {
        MapNode* newNode = new MapNode(key, value);
        if (this->root == nullptr) {
            this->root = newNode;
        } else {
            insert(this->root, newNode);
        }
    }

    int get(MapNode* node, unsigned long int key_hash)
    {
        if (node == nullptr) {
            return -1;
        }

        if (key_hash == node->key_hash) {
            return node->value;
        } else if (key_hash < node->key_hash) {
            return get(node->left, key_hash);
        } else {
            return get(node->right, key_hash);
        }
    }

    int get(string key)
    {
        return get(this->root, hash(key));
    }

    MapNode* root;
};


int main(int argc, char *argv[])
{
    srand(time(NULL));
    Map map;

    std::vector<std::string> names;
    names.push_back("Yolo");
    names.push_back("Anastasiya");
    names.push_back("Clement");
    names.push_back("Sirine");
    names.push_back("Julien");
    names.push_back("Sacha");
    names.push_back("Leo");
    names.push_back("Tanguy");

    map.insert("Yolo", 20);
    for (std::string& name : names)
    {
        if (rand() % 3 == 0)
        {
            map.insert(name, rand() % 21);
        }
    }

    printf("map[\"Margot\"]=%d\n", map.get("Margot"));
    printf("map[\"Jolan\"]=%d\n", map.get("Jolan"));
    printf("map[\"Lucas\"]=%d\n", map.get("Lucas"));
    printf("map[\"Clemence\"]=%d\n", map.get("Clemence"));
    printf("map[\"Yolo\"]=%d\n", map.get("Yolo"));
    printf("map[\"Tanguy\"]=%d\n", map.get("Tanguy"));



}























// #include <time.h>
// #include <stdio.h>
// #include <string>
// #include <vector>


// using std::size_t;
// using std::string;


// std::vector<string> names(
// {
//     "Yolo", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
//     "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
//     "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
//     "Leo", "Nils", "Vincent", "Paul", "Zoe", "Julien", "Matteo",
//     "Fanny", "Jeanne", "Elo"
// });

// unsigned long int hash(string key)
// {
// }

// struct MapNode
// {

//     string key;
//     unsigned long int key_hash;

//     int value;

//     MapNode* left;
//     MapNode* right;

//     MapNode(string key, int value)
//     {
//         this->key = key;
//         this->value = value;
//         this->key_hash = hash(key);

//         this->left = this->right = nullptr;
//     }

//     /**
//      * @brief insertNode insert a new node according to the key hash
//      * @param node
//      */
//     void insertNode(MapNode* node)
//     {

//     }

//     void insertNode(string key, int value)
//     {
//         this->insertNode(new MapNode(key, value));
//     }

// };

// struct Map
// {
//     Map() {
//         this->root = nullptr;
//     }

//     /**
//      * @brief insert create a node and insert it to the map
//      * @param key
//      * @param value
//      */
//     void insert(string key, int value)
//     {

//     }

//     /**
//      * @brief get return the value of the node corresponding to key
//      * @param key
//      * @return
//      */
//     int get(string key)
//     {
//         return -1;
//     }

//     MapNode* root;
// };


// int main(int argc, char *argv[])
// {
//     srand(time(NULL));
// 	Map map;

//     map.insert("Yolo", 20);
//     for (std::string& name : names)
//     {
//         if (rand() % 3 == 0)
//         {
//             map.insert(name, rand() % 21);
//         }
//     }

//     printf("map[\"Margot\"]=%d\n", map.get("Margot"));
//     printf("map[\"Jolan\"]=%d\n", map.get("Jolan"));
//     printf("map[\"Lucas\"]=%d\n", map.get("Lucas"));
//     printf("map[\"Clemence\"]=%d\n", map.get("Clemence"));
//     printf("map[\"Yolo\"]=%d\n", map.get("Yolo"));
//     printf("map[\"Tanguy\"]=%d\n", map.get("Tanguy"));
// }
