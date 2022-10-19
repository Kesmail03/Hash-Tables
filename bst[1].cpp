#include "bst.h"

using namespace std;


int main()
{
	bst my_bst;
	animal to_add;
	char copy_breed[SIZE];
	char copy_category[SIZE];
	char copy_personality[SIZE];
	char copy_purpose[SIZE];
	char copy_size[SIZE];
	char copy_keyword[SIZE];
	int copy_time;
	bool stop = true;
	char option = ' ';
	while(stop)
	{
		cout<<"Please choose what you would like to do" <<endl;
		cout<<"1.Add a pet"<<endl<<"2.Display all"<<endl<<"3.Display of a certain breed"<<endl<<"4.Retreive breed and personality"
		    <<endl<<"5.Remove by breed"<<endl<<"6.Display by Size"<<endl<<"7.Quit"<<endl;
		cin >> option;
		cin.ignore(100,'\n');
		switch(option)
		{
			case'1':cout<<"Please enter the breed of the animal"<<endl;
				cin.get(copy_breed, SIZE,'\n');
				cin.ignore(100,'\n');
				cout<<"Please enter the category of the animal"<<endl;
				cin.get(copy_category, SIZE,'\n');
				cin.ignore(100, '\n');
				cout<<"Please enter the personality of the animal"<<endl;
				cin.get(copy_personality, SIZE,'\n');
				cin.ignore(100, '\n');
				cout<<"Please enter the purpose of the animal"<<endl;
				cin.get(copy_purpose, SIZE,'\n');
				cin.ignore(100, '\n');
				cout<<"Please enter the size of the animal"<<endl;
				cin.get(copy_size, SIZE,'\n');
				cin.ignore(100, '\n');
				cout<<"Please enter the keyword of the animal"<<endl;
				cin.get(copy_keyword, SIZE,'\n');
				cin.ignore(100, '\n');
				cout<<"Please enter the time of the animal"<<endl;
				cin >> copy_time;
				cin.ignore(100, '\n');
				to_add.create_animal(copy_breed,copy_category,copy_personality,copy_purpose,copy_size,copy_keyword,copy_time);
				my_bst.add_animal(to_add);
				break;
			case'2':my_bst.display_all();
				break;
			case'7':stop = false;
				break;
			
		}	



	}










	return 0;
}
