#include "table.h"

using namespace std;

//Khaled Esmail, CS163, 5/16/2022, This is where I implement the functions from my table and animal class.

//table constructor
table::table(int size)
{
	hash_size = size;
	hash_table = new node * [hash_size];
	hash_table2 = new node * [hash_size];
	for(int i = 0; i < hash_size; ++i)
	{
		hash_table[i] = nullptr;
		hash_table2[i] = nullptr;

	}


}
//table destructor
table::~table()
{
	for(int i = 0; i < hash_size; ++i)
	{
		destructor(hash_table[i]);
		destructor2(hash_table2[i]);
	}
	delete [] hash_table;
	delete [] hash_table2;
	hash_table = nullptr;
	hash_table2 = nullptr;

}

//these two functions destroy the LLL that each node points to for both hash tables
int table::destructor(node *& head)
{
	if(!head)
		return 0;
	destructor(head->next);
	delete head;
	head = nullptr;
	return 1;	


}

int table::destructor2(node *& head2)
{
	if(!head2)
		return 0;
	destructor2(head2->next);
	delete head2;
	head2 = nullptr;
	return 1;


}

//this takes the info from main and copies it to each data member in the animal class
int animal::create_animal(char * copy_breed, char * copy_category, char * copy_personality, char * copy_purpose, char * copy_size, char * copy_keyword, int copy_time)
{
	//this is to prevent memory leaks
	if(breed)
	{
		delete [] breed;
		breed = nullptr;
	}
	if(category)
	{
		delete [] category;
		category = nullptr;
	}
	if(personality)
	{
		delete [] personality;
		personality = nullptr;
	}
	if(purpose)
	{
		delete [] purpose;
		purpose = nullptr;
	}
	if(size)
	{
		delete [] size;
		size = nullptr;
	}
	if(keyword)
	{
		delete [] keyword;
		keyword = nullptr;
	}
	
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

//this copies the info into the object of the class which is to_add
int animal::copy_animal(animal & to_add)
{

	if(breed)
	{
		delete [] breed;
		breed = nullptr;
	}
	if(category)
	{
		delete [] category;
		category = nullptr;
	}
	if(personality)
	{
		delete [] personality;
		personality = nullptr;
	}
	if(purpose)
	{
		delete [] purpose;
		purpose = nullptr;
	}
	if(size)
	{
		delete [] size;
		size = nullptr;
	}
	if(keyword)
	{
		delete [] keyword;
		keyword = nullptr;
	}
	
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

//This allows a user to add to both hash tables
int table::add_animal(animal & to_add, char * keyword, char * personality)
{
	int index = hash_function(keyword);
	int index2 = hash_function2(personality);
	node * temp = hash_table[index];
	node * temp2 = hash_table2[index2];
	if(!hash_table[index])
	{
		hash_table[index] = new node;
		hash_table[index]->object.copy_animal(to_add);
		hash_table[index]->next = nullptr;
	}
	else
	{
		node * temp = hash_table[index];
		hash_table[index] = new node;
		hash_table[index]->object.copy_animal(to_add);
		hash_table[index]->next = temp;
		
	}
	
	if(!hash_table2[index2])
	{
		hash_table2[index2] = new node;
		hash_table2[index2]->object.copy_animal(to_add);
		hash_table2[index2]->next = nullptr;
	}
	else
	{
		node * temp2 = hash_table2[index2];
		hash_table2[index2] = new node;
		hash_table2[index2]->object.copy_animal(to_add);
		hash_table2[index2]->next = temp2;
		
	}

	return 1;
}

//this loads the info from the external data file
int table::load_animal()
{
	char breed[SIZE];
	char category[SIZE];
	char personality[SIZE];
	char purpose[SIZE];
	char size[SIZE];
	char keyword[SIZE];
	int time;	
	animal obj;

	ifstream filein;
	filein.open("animal.txt");

	if(!filein)
	{
		filein.clear();
		return 0;
	}	
	filein.peek();
	while(filein && !filein.eof())
	{
		filein.get(breed, SIZE,'|');
		filein.ignore(100, '|');
		filein.get(category, SIZE,'|');
		filein.ignore(100, '|');
		filein.get(personality, SIZE,'|');
		filein.ignore(100, '|');
		filein.get(purpose, SIZE,'|');
		filein.ignore(100, '|');
		filein.get(size, SIZE,'|');
		filein.ignore(100, '|');
		filein.get(keyword, SIZE,'|');
		filein.ignore(100, '|');
		filein >> time;
		filein.ignore(100, '\n');

		obj.create_animal(breed,category,personality,purpose,size,keyword,time);
		add_animal(obj,keyword, personality);
		filein.peek();
	}
	filein.close();
	return 1;
}

//this is the has function for the first hash table, the main one
int table::hash_function(char * keyword)
{
	int sum = 0;
	for(int i = 0; i < strlen(keyword) ; ++i)
	{
		sum = sum + keyword[i];

	} 	
	return sum % hash_size;
}

//this hash function is for the extra credit hash table.
int table::hash_function2(char * personality)
{
	int sum = 0;
	for(int i = 0; i < strlen(personality) ; ++i)
	{
		sum = sum + personality[i];
	} 	
	return sum % hash_size;
}

//this allows the user to retrieve by using the keyword
int table::retrieve_key(char * keyword, animal results[], int results_size)
{
	int i = 0;//this is the count and index of results
	int index = hash_function(keyword);
	node * current = hash_table[index];
	while(current)
	{
		if(i < SIZE && current->object.match_keyword(keyword))
		{
			results[i].copy_animal(current->object);		
			++i;
		}
		current = current -> next;
	}
	return i;
}

//this function was used to test if the retrieve function worked
int table::display_results(animal results [], int results_size)
{
	for(int i = 0; i < results_size; ++i)
	{
		results[i].display_animal();

	}
	return 1;

}


//finds a matching keyword
int animal::match_keyword(char * keyword)
{
	if(strcmp(this->keyword, keyword) == 0)
	{
		return 1;
	} 
	return 0;
}

//finds a matching personality
int animal::match_personality(char * personality)
{
	if(strcmp(this->personality, personality) == 0)
	{
		return 1;
	}
	return 0;
}

//this function is to test if the load function worked.
int table::display_all()
{
	for(int i = 0; i < hash_size; ++i)
	{
		node * current = hash_table[i];
		if(current)
		{
			cout<<"Index is: " << i <<endl;
		}
		while(current)
		{
			current->object.display_animal();
			current = current -> next;
		}


	}


	return 1;
}

//this is to allow to to output the info in the class because it's private data
int animal::display_animal()
{
	cout<<"The breed is: "<< breed <<'|';
	cout<<"The category is : "<< category <<'|';
	cout<<"The personality is: "<< personality << '|';
	cout<<"The purpose is: "<< purpose << '|';
	cout<<"The size is: " << size << '|';
	cout<<"The keyword is: " << keyword << '|';
	cout<<"The time is: " << time << endl;
	return 1;
}

//this function calls the display animal function
int table::display_key(char * keyword)
{
	int index = hash_function(keyword);
	node * current = hash_table[index];
	while(current)
	{
		if(current->object.match_keyword(keyword) == 1)
		{
			current->object.display_animal();
		}
		current = current -> next;	
	}
	return 1;
}

//this function uses the second hash table to display the personality
int table::display_personality(char * personality)
{
	int index2 = hash_function2(personality);
	node * current2 = hash_table2[index2];
	while(current2)
	{
		if(current2->object.match_personality(personality) == 1)
		{
			current2->object.display_animal();
		}
		current2 = current2 -> next;
	}
	
	return 1;
}

//the recursive function to remove a LLL by keyword
int table::remove_animal(node *& head, char * keyword)
{
	if(head == nullptr)
		return 0;
	if(head->object.match_keyword(keyword) == 1)
	{
		node * temp = head;
		head = head -> next;
		delete temp;	
	}
	remove_animal(head->next, keyword);	
	return 1;
}

//this calls the recursive function
int table::remove_key(char * keyword)
{
	int index = hash_function(keyword);
	remove_animal(hash_table[index], keyword);	
	

	return 1;
}

//animal class constructor
animal::animal()
{
	breed = nullptr;
	category = nullptr;
	personality = nullptr;
	purpose = nullptr;
	size = nullptr;
	keyword = nullptr;

}

//animal class destructor
animal::~animal()
{
	delete [] breed;
	delete [] category;
	delete [] personality;
	delete [] purpose;
	delete [] size;
	delete [] keyword;
	breed = nullptr;
	category = nullptr;
	personality = nullptr;
	purpose = nullptr;
	size = nullptr;
	keyword = nullptr;

	

}




