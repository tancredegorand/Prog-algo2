
#include <time.h>     
#include <iostream>
using namespace std;

int max(int n1, int n2) {
    if (n1 > n2) {
        return n1;
    }
    else {
        return n2;
    }
}

struct SearchTreeNode
{    
    SearchTreeNode* left;
    SearchTreeNode* right;
    int value;

    void initNode(int value)
    {
        // init initial node without children
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }

	void insertNumber(int value) {
        // create a new node and insert it in right or left child
        if (value >= this->value) {
            if (this->right == nullptr) {
                this->right = new SearchTreeNode(value);
            }
            else {
                this->right->insertNumber(value);
            }
        }
        else {
            if (this->left == nullptr) {
                this->left = new SearchTreeNode(value);
            }
            else {
                this->left->insertNumber(value);
            }
        }
    }

	int height() const	{
        // should return the maximum height between left child and
        // right child +1 for itself. If there is no child, return
        // just 1
        if (this->right == nullptr && this->left == nullptr) {
            return 1;
        }

        int heightRight, heightLeft;
        if (this->right != nullptr) {
            int heightRight = this->right->height();
        }
        else {
            heightRight = 0;
        }
        if (this->left != nullptr) {
            int heightLeft = this->left->height();
        }
        else {
            heightLeft = 0;
        }
        
        return 1 + max(heightRight,heightLeft);  // MAX À DÉFINIR
    }

	int nodesCount() const {
        // should return the sum of nodes within left child and
        // right child +1 for itself. If there is no child, return
        // just 1
        int heightRight, heightLeft;
        if (this->right != nullptr) {
            int heightRight = this->right->height();
        }
        else {
            heightRight = 0;
        }
        if (this->left != nullptr) {
            int heightLeft = this->left->height();
        }
        else {
            heightLeft = 0;
        }

        return 1 + heightRight + heightLeft;
	}

	bool isLeaf() const {
        // return True if the node is a leaf (it has no children)
        return this->right == nullptr && this->left == nullptr;
	}

	void allLeaves(SearchTreeNode* leaves[], int* leavesCount) {
        // fill leaves array with all leaves of this tree
        if (this->right == nullptr && this->left == nullptr) {
            leaves[*leavesCount] = this;
            (*leavesCount)++;
        }
        else {
            if (this->left != nullptr) {
                this->left->allLeaves(leaves,leavesCount);
            }
            if (this->right != nullptr) {
                this->right->allLeaves(leaves,leavesCount);
            }
        }
	}

	void inorderTravel(SearchTreeNode* nodes[], int* nodesCount) {
        // fill nodes array with all nodes with inorder travel
        if (this->left != nullptr) {
            this->left->inorderTravel(nodes,nodesCount);
        }
        nodes[*nodesCount] = this;
        (*nodesCount)++;
        if (this->right != nullptr) {
            this->right->inorderTravel(nodes,nodesCount);
        }
	}

	void preorderTravel(SearchTreeNode* nodes[], int* nodesCount) {
        // fill nodes array with all nodes with preorder travel
        nodes[*nodesCount] = this;
        (*nodesCount)++;
        if (this->left != nullptr) {
            this->left->preorderTravel(nodes,nodesCount);
        }
        if (this->right != nullptr) {
            this->right->preorderTravel(nodes,nodesCount);
        }
	}

	void postorderTravel(SearchTreeNode* nodes[], int* nodesCount) {
        // fill nodes array with all nodes with postorder travel
        if (this->left != nullptr) {
            this->left->postorderTravel(nodes,nodesCount);
        }
        if (this->right != nullptr) {
            this->right->postorderTravel(nodes,nodesCount);
        }
        nodes[*nodesCount] = this;
        (*nodesCount)++;
	}

	SearchTreeNode* find(int value) {
        // find the node containing value

        if (this->value == value) {
            return this;
        }
        else if (this->value <= value && this->right != nullptr) {
            return this->right->find(value);
        }
        else if (this->value > value && this->left != nullptr) {
            return this->left->find(value);
        }
        else {
            return nullptr;
        }
	}

    void reset()
    {
        if (left != nullptr)
            delete left;
        if (right != nullptr)
            delete right;
        left = right = nullptr;
    }


    SearchTreeNode(int value) {initNode(value);}
    ~SearchTreeNode() {}
    int get_value() const {return value;}
    SearchTreeNode* get_left_child() const {return left;}
    SearchTreeNode* get_right_child() const {return right;}
};

SearchTreeNode* createNode(int value) {
    return new SearchTreeNode(value);
}



void printArray(SearchTreeNode * array[],int size) {
    cout << endl;
    cout << "--------------" << endl;
    for (int i=0; i<size; i++)
    {
        cout << array[i]->value << " ";
    }
}


int main(int argc, char *argv[])
{
	// QApplication a(argc, argv);
	// MainWindow::instruction_duration = 200;
    // w = new BinarySearchTreeWindow<SearchTreeNode>();
	// w->show();

	// return a.exec();

    srand(time(NULL));

    SearchTreeNode *stn = new SearchTreeNode(rand()%15);

    for (int i=0 ; i<9 ; i++) {
        stn->insertNumber(rand()%15);
    }


    cout << endl << stn->nodesCount() << endl;

    SearchTreeNode* array[10];

    int count = 0;
    stn->allLeaves(array,&count);

    printArray(array,count);

    count = 0;
    stn->inorderTravel(array,&count);
    printArray(array,count);

    count = 0;
    stn->preorderTravel(array,&count);
    printArray(array,count);

    count = 0;
    stn->postorderTravel(array,&count);
    printArray(array,count);

    int toFind = rand()%15;
    SearchTreeNode * find = stn->find(toFind);
    cout << "to find : " << toFind << endl;
    if (find == nullptr) {
        cout << "not find" << endl;
    }
    else {
        cout << "find" << endl;
    }
}