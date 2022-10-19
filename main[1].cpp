#include "bst.h"

using namespace std;


bst::bst()
{
	root = nullptr;
}



bst::~bst()
{



}

int animal::create_animal(char * copy_breed, char * copy_category, char * copy_personality, char * copy_purpose, char * copy_size, char * copy_keyword, int copy_time)
{
	breed = new char[strlen(copy_breed) + 1];
	strcpy(breed, copy_breed);
	 
	category = new char[strlen(copy_category) + 1];
	strcpy(category, copy_category);
	
	personality = new char[strlen(copy_personality) + 1];
	strcpy(personality, copy_personality);
	
	purpose = new char[strlen(copy_purpose) + 1];
	strcpy(purpose, copy_purpose);
	
	size = new char[strlen(copy_size) + 1];
	strcpy(size, copy_size);
	
	keyword = new char[strlen(copy_keyword) + 1];
	strcpy(keyword, copy_keyword);

	time = copy_time;

	return 1;
}

int animal::copy_animal(animal & to_add)
{
	 
	breed = new char[strlen(to_add.breed) + 1];
	strcpy(breed, to_add.breed);	
	
	category = new char[strlen(to_add.category) + 1];
	strcpy(category, to_add.category);
	
	personality = new char[strlen(to_add.personality) + 1];
	strcpy(personality, to_add.personality);
	
	purpose = new char[strlen(to_add.purpose) + 1];
	strcpy(purpose, to_add.purpose);
	
	size = new char[strlen(to_add.size) + 1];
	strcpy(size, to_add.size);
	
	keyword = new char[strlen(to_add.keyword) + 1];
	strcpy(keyword, to_add.keyword);
	
	time = to_add.time;

	return 1;
}

int animal::compare_breed(char * copy_breed)
{
	return strcmp(breed, copy_breed);
}

int animal::compare_personality(char * copy_personality)
{
	return strcmp(personality, copy_personality);
}

int animal::get_breed(char * copy_breed)
{
	copy_breed = new char[strlen(breed) + 1];
	strcpy(copy_breed, breed);
	return 1;
}


int animal::get_personality(char * copy_personality)
{
	copy_personality = new char[strlen(personality) + 1];
	strcpy(copy_personality, personality);
	return 1;
}
int bst::add_animal(animal & to_add)
{
	char * copy_breed;
	to_add.get_breed(copy_breed);
	add_animal(to_add,root, copy_breed);
	return 1;
}

int bst::add_animal(animal & to_add, node *& root, char * copy_breed)
{
	if(!root)
	{
		root = new node;
		root->object.copy_animal(to_add);
		root->left = nullptr;
		root->right = nullptr;
		return 1;
	}
	if(root->object.compare_breed(copy_breed) < 0) 
	{
		add_animal(to_add, root->left, copy_breed);

	}
	else if(root->object.compare_breed(copy_breed) > 0)
	{
		add_animal(to_add, root->right, copy_breed);
	}
	else 
	{
		char * copy_personality;
		to_add.get_personality(copy_personality);
		if(root->object.compare_personality(copy_personality) < 0)
			add_animal(to_add, root->left, copy_breed);
		else
			add_animal(to_add, root->right, copy_breed);
	}
	return 1;
}

int animal::display_animal()
{
	cout<<"The breed is: "<< breed << endl;
	cout<<"The category is: "<< category << endl;
	cout<<"The personality is: "<< personality << endl;
	cout<<"The purpose is: "<< purpose << endl;
	cout<<"The size is: "<< size << endl;
	cout<<"The keyword is: "<< keyword << endl;
	cout<<"The time is: "<< time << endl;
	return 1;

}

int bst::display_all()
{
	if(!root)
		return 0;
	display_all(root);
	return 1;
}

int bst::display_all(node * root)
{
	if(!root)
		return 0;
	display_all(root->left);
	root->object.display_animal();

	display_all(root->right);

	return 1;
}


animal::animal()
{
	breed = nullptr;
	category = nullptr;
	personality = nullptr;
	purpose = nullptr;
	size = nullptr;
	keyword = nullptr;	

}


animal::~animal()
{
	delete [] breed;
	breed = nullptr;

	delete [] category;
	category = nullptr;

	delete [] personality;
	personality = nullptr;

	delete [] purpose;
	purpose = nullptr;

	delete [] size;
	size = nullptr;

	delete [] keyword;
	keyword = nullptr;	
}
