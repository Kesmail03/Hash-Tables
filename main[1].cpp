#include "table.h"

using namespace std;



int main()
{
	table my_table;//object fro my table class 
	animal to_add;//the object for the keyword hash table;
	animal to_add2;//the object for the personality hash table
	animal results[SIZE];//the array of items that I will copy into from the hash table
	//these are the arrays I pass into my functions that I get from the user
	char copy_breed[SIZE];
	char copy_category[SIZE];
	char copy_personality[SIZE];
	char copy_purpose[SIZE];
	char copy_size[SIZE];
	char copy_keyword[SIZE];
	int copy_time;
	bool stop = true;//stopping condition for my loop
	char option = ' ';//user option
	int results_size = 0;//size of the array that I use for the retrieve function
	//the menu
	while(stop == true)
	{
		cout<<"Please choose what you would like to do"<<endl;
		cout<<"1.Add an animal"<<endl<<"2.Load info"<<endl<<"3.Display keyword"<<endl<<"4.Retrieve keyword"<<endl
			<<"5.Remove by keyword"<<endl<<"6.Display Personality"<<endl<<"7.Display all"<<endl<<"8.Quit"<<endl;
		cin >> option;
		cin.ignore(100,'\n');
		switch(option)
		{
			case'1':cout<<"Please enter the breed of the animal"<<endl;
				cin.get(copy_breed,SIZE,'\n');
				cin.ignore(100,'\n');
				cout<<"Please enter the category of the animal"<<endl;
				cin.get(copy_category,SIZE,'\n');
				cin.ignore(100,'\n');
				cout<<"Please enter the personality of the animal"<<endl;
				cin.get(copy_personality,SIZE,'\n');
				cin.ignore(100,'\n');
				cout<<"Please enter the purpose of the animal"<<endl;
				cin.get(copy_purpose,SIZE,'\n');
				cin.ignore(100,'\n');
				cout<<"Please enter the size of the animal"<<endl;
				cin.get(copy_size,SIZE,'\n');
				cin.ignore(100,'\n');
				cout<<"Please enter the keyword of the animal"<<endl;
				cin.get(copy_keyword,SIZE,'\n');
				cin.ignore(100,'\n');
				cout<<"Please enter the time you have had animal"<<endl;
				cin >> copy_time;
				cin.ignore(100,'\n');
				to_add.create_animal(copy_breed,copy_category,copy_personality,copy_purpose,copy_size,copy_keyword,copy_time);
				my_table.add_animal(to_add, copy_keyword, copy_personality); 
				break;

			case'2':my_table.load_animal();
				break;

			case'3':cout<<"Please enter the keyword of the animal"<<endl;
				cin.get(copy_keyword,SIZE,'\n');
				cin.ignore(100,'\n');
				my_table.display_key(copy_keyword);
				break;
			
			case'4':cout<<"Please enter the keyword of the animal"<<endl;
				cin.get(copy_keyword,SIZE,'\n');
				cin.ignore(100,'\n');
				results_size = my_table.retrieve_key(copy_keyword, results, SIZE);
				my_table.display_results(results, results_size);
				break;

			case'5':cout<<"Please enter the keyword of the animal"<<endl;
				cin.get(copy_keyword,SIZE,'\n');
				cin.ignore(100,'\n');
				my_table.remove_key(copy_keyword);
				break;
			case'6':cout<<"Please enter the personality of the animal"<<endl;
				cin.get(copy_personality,SIZE,'\n');
				cin.ignore(100,'\n');
				my_table.display_personality(copy_personality);
				break;
			case'7':my_table.display_all();
				break;
				
			case'8':stop = false;
				break;

		}

	}
	return 0;
}




