#include <iostream>
//in here I Traversal through the tree in pre order and for tree nodes data I store in a Doubly linked list and then compare and find pairs via the linked list

using namespace std;

struct node  //node structure...
{
	int data;
	struct node* left;  //tree left node
	struct node* right; //tree right node
	struct node* next;  //linked list next node
	struct node* prev;  //linke list previous node..

};


class BST   //Binary search Tree class..
{
private:

	node* start;  //starting node...


public:

	void insertBeg(int x);  //insert node to the Linked list
	void listValue();  //assign NULL to start 
	void pairs(node* tree, int value,int &check);  //finding pairs fuction
	node* getStart();  //get the starting node
	node* insertValue(node* temp, int x);  //insert values to the tree...
	void travelPreOrder(node* temp);  //travel in the treee..


};

void BST::listValue()  //set start and end pointers to NULL
{
	start = NULL;
}

node* BST::getStart()  //get the starting pointer...
{
	return start;
}

void BST::pairs(node* tree, int value,int &check)   //finding pairs fuction..
{
	if (tree != NULL)
	{
		node* temp;
		node* compare;
		compare = tree;
		temp = tree->next;
		while (compare != NULL)
		{
			while (temp != NULL)
			{
				if (compare->data + temp->data == value)
				{
					check=1; //checking for if exist pairs..
					cout << "(" << compare->data << "," << temp->data << ")" << " ";
				}
				temp = temp->next;
			}
			compare = compare->next;
			temp = compare->next;

			if (temp == NULL)
			{
				return;
			}
		}
	}
}

void BST::insertBeg(int x)  //insert a node at the begining..
{
	struct node* newNode;  //define a new node....
	newNode = new node; //allocate memory for the new node..
	newNode->data = x;
	if (start == NULL)
	{
		start = newNode;
		newNode->prev = NULL;
		newNode->next = NULL;
	}

	else
	{
		newNode->next = start;
		newNode->prev = NULL;
		start->prev = newNode;
		start = newNode;
	}
}

node* BST::insertValue(node* temp, int x)  //insert values to the tree fuction
{
	if (temp == NULL)
	{
		temp = new node;
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;

	}

	else
	{
		if (x < temp->data)
		{
			temp->left = insertValue(temp->left, x);
		}
		else
		{
			temp->right = insertValue(temp->right, x);
		}
	}
	return temp;



}



void BST::travelPreOrder(node* temp)   //traversal in the tree and assign data to the linked list fuction..
{

	if (temp != NULL)
	{
		insertBeg(temp->data);  //assign data to the linked list...
		travelPreOrder(temp->left);
		travelPreOrder(temp->right);
	}


}



int main()
{
	BST tree;  //BST object...
	
	node* temp = NULL;
	tree.listValue();
	int noOfNodes;
	cout << "Enter the Number of nodes in the BST : ";
	cin >> noOfNodes;
	int nodeData;
	cout << "Enter the Data : " << endl;
	for (int i = 0; i < noOfNodes; i++)  //input tree elements...
	{
		cin >> nodeData;
		temp=tree.insertValue(temp, nodeData);
	}

    int check=0;
	tree.travelPreOrder(temp); //calling traversal Pre Order in the tree fuction..
	cout << endl;
	int value;
	cout << "Enter a value : ";
	cin >> value;  //given value...
	cout << "Pairs in the tree : ";
	tree.pairs(tree.getStart(), value,check);  //calling outputing pairs fuction..
	
	if(check==0)  //if pairs doesn't exist in the tree 
	{
		cout<<"There are no pairs in the tree!!!"<<endl;
	}



}
