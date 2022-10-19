#include<iostream>
#include<cctype>
#include<cstring>
#include<fstream>

class animal
{
	public:
	animal();
	~animal();
	int create_animal(char * copy_breed,char * copy_category, char * copy_personality, char * copy_purpose, char * copy_size, char * copy_keyword, int copy_time);
	int copy_animal(animal & to_add);
	int display_animal();
	int compare_breed(char * copy_breed);
	int compare_personality(char * copy_personality);
	int get_breed(char * copy_breed);
	int get_personality(char * copy_personality);

	private:
	char * breed;
	char * category;
	char * personality;
	char * purpose;
	char * size;
	char * keyword;
	int time;//the amount of time they've had the pet
};

const int SIZE = 20;


struct node
{
	node * left;
	node * right;
	animal object;
};


class bst
{
	public:
	bst();
	~bst();
	int add_animal(animal & to_add);
	int display_all();
	int display_breed(char * breed);
	int retrieve(char * breed, char * personality);
	int remove_breed(char * breed);
	int display_size(char * size);

	private:
	node * root;
	int add_animal(animal & to_add, node *& root, char * copy_breed);
	int display_all(node * root);
};


