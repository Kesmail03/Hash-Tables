#include<iostream>
#include<cstring>
#include<cctype>
#include<fstream>

//Khaled Esmail, CS163, 5/16/2022, this is the header file that contains the struct node, and the classes

class animal
{
	public:
	int create_animal(char * copy_breed, char * copy_category, char * copy_personality, char * copy_purpose, char * copy_size, char * copy_keyword, int copy_time);
	int copy_animal(animal & to_add);
	int display_animal();
	int match_keyword(char * keyword);
	int match_personality(char * personality);
	animal();
	~animal();	


	private:
	char * breed;
	char * category;
	char * personality;
	char * purpose;
	char * size;
	char * keyword;
	int time;//how long they've had their pet

};

const int SIZE = 15;

struct node
{
	node * next;
	animal object;


};



class table
{
	public:
	table(int size = 101);
	~table();
	int hash_function(char * keyword);
	int hash_function2(char * personality);
	int add_animal(animal & to_add, char * keyword, char * personality);
	int load_animal();
	int display_key(char * copy_keyword);
	int retrieve_key(char * copy_keyword, animal results[], int results_size);
	int remove_key(char * copy_keyword);
	int display_personality(char * copy_personality); 
	int remove_animal();
	int display_results(animal results[], int results_size);
	int display_all();
	private:
	node ** hash_table;//hash table for keyword
	node ** hash_table2;//The hash table for personality
	int hash_size;//hash size for keyword
	int destructor(node *& head);
	int destructor2(node *& head2);
	int remove_animal(node *& head, char * keyword);
	
};
