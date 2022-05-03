//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include "stdafx.h"
#include<windows.h> 
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include<string>
#include <sstream>
#include <algorithm>
#include <limits>
#include <math.h>
#include"Declare.h"
 
using namespace std;

// Program includes
//  1- OOP , 2- Dynamic Memory Management , 
//  3- File Management ,4- Exception Handling
//   5- function overloading

   


	
	// constructor

	Book::Book()
	{
}


void Book:: AddBooks(bool isedit) //this helps the Librarian to add boos
{

	try {
	
	
	system("cls");
	if(!isedit)
	{
		 code = get_departments();// get code from Shelf,
		 if(code == "0")
		 {
			 mainmenu();
			 return;
		 }
	}
    
	ofstream file;
	
	
	file.open ("LMS_Data.txt", fstream::app); //open file

	cin.ignore();
	
	cout<<"\n\t\t\tPlease write Book ID : ";
	getline(cin, BookID); //  getline() 
	// cin could be any input stream


	cout<<"\n\t\t\tPlease write Book Name:  ";
	getline(cin, Name); 

	cout<<"\n\t\t\tPlease write Author:  ";
	getline(cin, Author); 

	cout<<"\n\t\t\tPlease write Price: ";
	getline(cin, Price); 

	cout<<"\n\t\t\tPlease write Quantity: ";
	getline(cin, Quantity);

	cout<<"\n\t\t\tPlease write Shelf: " + code +"-";
	getline(cin, Shelf);

	choicesselection:
	cout<<"\n\n\n\t\t\Are you sure you want to save ?(y/n):";
	char c2 ; // dynamic memory allocation
	fflush(stdin);
	scanf("%c",&c2);
	if(c2=='Y' || c2=='y')
	{

	file <<"\n";
	file << BookID ;
	file<<"\t";

	file << Name;
	file<<"\t";

	file << Author;
	file<<"\t";

	file << Price;
	file<<"\t";

	file << Quantity;
	file<<"\t";

	file << Shelf;
	file<<"\t";

	file << code;
	file<<"\t";

	if(isedit == true)
	{
		
	file.close();   //Close the file after filling all the details
		cout << "Book is updated sucessfully !!!";}
	else
	{
		
	file.close();
	cout << "Book is added sucessfully !!!";}

	}
	else if (c2=='N' || c2=='n')
	{
	}
		else
			goto choicesselection;
	
	cout<<"\n\n\n\t\t\tAdd More Book(y/n):";

	fflush(stdin);
	scanf("%c",&c2);
	if(c2=='Y' || c2=='y'){
		AddBooks(false);}
	
	else if(c2=='n' || c2=='N'){
			cout<<"\n\n\n\t\t\tPress Enter To Continue...";
			system("cls");
	mainmenu();
	getch();}
	else
		goto choicesselection;
		
	
	
	system("cls");
	choices();
	getch();}
	catch(runtime_error err) {
   throw  err;

	}

}

void Book::AddBooks(string BookID, string Name , string Author, string Quantity, string Price, string Shelf)
{
 
	    try {


	ofstream file;

	file.open ("LMS_Data.txt", fstream::app);

	
	file <<"\n";
	file << BookID ;
	file<<"\t";

	file << Name;
	file<<"\t";

	file << Author;
	file<<"\t";

	file << Price;
	file<<"\t";

	file << Quantity;
	file<<"\t";

	file << Shelf;
	file<<"\t";		file.close();
		}
	 catch (int x ) { 
      cout << "Exception Caught \n"; 
   } 

}

void Book:: ViewBooks()  //This otption used to view all the books stored in the library
{
	system("cls");

	string line,  id,name,author,price, quantity, shelf;
	std::fstream myfile;
	std::fstream temp;
	temp.open("temp.txt",ios::out);
	myfile.open("LMS_Data.txt");
	if (!myfile.is_open()){
		//cout << "\n\nCould not open file: "<<file<<endl;
		exit(0);}
	cout<<"********************************************************************************************************\n\n" ;
	cout<<"BOOKID"<<setw(15)<<"NAME"<<setw(25)<<"AUTHOR"<<setw(21)<<"PRICE"<<setw(20)<<"QUANTITY"<<setw(15)<<"SHELF"<<"\n\n" ;
	cout<<"*********************************************************************************************************\n\n" ;
	while (myfile.good()){
		getline (myfile,line);
		istringstream ss(line);
		if(line !="")
		{
			ss >> id ;
			ss >> name;
			ss >> author;
			ss >> price;
			ss >> quantity;
			ss >> shelf;

			cout<<id<<setw(25)<<name<<setw(20)<<author<<setw(20)<<price<<setw(15)<<quantity<<setw(15)<<shelf<<"\n\n" ;}}
	myfile.close();
	temp.close();
	cout<<"press any key to continue";
	getch();
	mainmenu();


}
int Book::Books_Category()  //This tell us that from whcih department does the book belongs
{

	cout<<"\n\n\n\t\t\tChoose The Department Of Book\n";
	cout<<"\t\t\t1)Computer Science(CS)\n";
	cout<<"\t\t\t2)Electrical Engineering(EE)\n";
	cout<<"\t\t\t3)Electronic Engineering(ELE) \n";
	cout<<"\t\t\t4)Mechanical Engineering(ME)  \n";
	cout<<"\t\t\t5)Civil Engineering(CE)\n";
	cout<<"\t\t\t6)Architecture Engineering (AR)\n";
	//cout<<"\n\t\t\tChoose The Department:";
	int a;
	//scanf("%d",&a);*/
	 
	do
	{
	    cout<<"\n\n\n\t\t\tChoose The Department:";
		cin >>a;
	} while(a > 6);
	
	return a;

}

void Book::mainmenu() //This is the main menu which is going to appear after logging in successfully
{

	system("cls");
	cout<<"\n\n\t\t     Welcome to Main menu of System       "<<endl;  

	cout<<"\n\n\t\t\t1)  Add Book(s).\n";
	cout<<"\t\t\t2)  Edit Book(s).\n";
	cout<<"\t\t\t3)  Delete Book(s).\n";
	cout<<"\t\t\t4)  Search Book(s).\n";
	cout<<"\t\t\t5)  View Book(s).\n";
	cout<<"\t\t\t6)  Expensive Book(s).";
	cout<<"\n\t\t\t7)  Close The Program";

	choices();
}

 void Book:: choices()
{
//int *pointer = new int[1];
int a = 0;
	do
	{   cout<<"\n\n\n\tEnter The Choice:  ";
        cin >> a;
		cin.ignore(std::numeric_limits<std::streamsize>::max_digits10, '\n');
		cin.clear() ;
		
	}while(a > 7);
	
	switch(a)
	{
	case 1:
		AddBooks(false);
		break;
	case 2:
		EditBook();
		break;
	case 3:
		deleteBook();
		break;
	case 4:
		SearchBooks();

		break;
	case 5:
		ViewBooks();
		break;

	case 6:
		ExpensiveBook();
		break;
	case 7:
		closeapplication();
		break;}

}
 
bool isBookExists(string book_id)
{
	string id, name;
	string line;	size_t pos;
	std::fstream myfile;
	std::fstream temp;
	bool found =false;
	temp.open("temp.txt",ios::out);
	myfile.open("LMS_Data.txt");
	if (!myfile.is_open()){
		exit;
	}
	while (myfile.good()){
		getline (myfile,line);

		pos = line.find(book_id);
		istringstream ss(line);
		ss >> id ;
		ss >> name;

		if (id != book_id)
		{
			found= false;
		}
		else
		{
			found = true;
			break;
	    }
	}
	return found;
}

//edit books ***************************************************************************************************
void Book::EditBook()   //Edit the details of the books by providing sufficient information
{
	// enter book to update 
	//what to do if book doesnt exists

	try {
	system("cls"); char c2;
	string line, id, name, author, price, quantity, shelf;
	string id_u, name_u, author_u, quantity_u,price_u, shelf_u, name_old;
	string book_id;
	choices:
	cout<<"\n\n\t\tEnter Book ID : ";
	cin>>book_id;
	bool status = isBookExists(book_id);
	if(status == true)
	{
		system("cls");
	ifstream input;
	size_t pos;
	

	input.open("LMS_Data.txt");
	cout<<"\n\n" ;
	
	while(getline(input,line))
	{
		pos = line.find(book_id);
		istringstream ss(line);
		/*string id_ , name_;*/
			ss >> id ;
		ss >> name;

		if(id ==book_id)
		{
			istringstream ss(line);
			ss >> id ;
			ss >> name;
			ss >> author;
			ss >> price;
			ss >> quantity;
			ss >> shelf;

			id_u = id;
			name_u = name;
			name_old = name;
			author_u = author;
			price_u = price;
			quantity_u = quantity;

			cout <<"\t\tPrevious Book Information  \n\n";
			cout<<"\t\tBook id:"<<setw(10)<<id<<"\n";
	cout<<"\t\tName:"<<setw(10)<<name<<"\n";
	cout<<"\t\tAuthor:"<<setw(10)<<author<<"\n";
	cout<<"\t\tPrice:"<<setw(10)<<price<<"\n";
	cout<<"\t\tQuantity:"<<setw(10)<<quantity<<"\n";
	cout<<"\t\tShelf:"<<setw(10)<<shelf<<"\n";
	input.close();
		}
	
	}
		cin.ignore();
		cout<<"\n\n\n\t\t\Are you sure you want to Change Book Name(y/n):";
	
	fflush(stdin);
	scanf("%c",&c2);
	if(c2=='Y' || c2=='y')
	{
		cout<<"\n\n\t\tEnter name : ";
		cin >> name;
		name_u = name;//update data
	 
	}
	else{
			 }
	

	cout<<"\n\n\n\t\t\Are you sure you want to Change Author Name(y/n):";
	
	fflush(stdin);
	scanf("%c",&c2);
	if(c2=='Y' || c2=='y')
	{
		cout<<"\n\n\t\tEnter Author Name : ";
		cin >> author;
		author_u = author;
		//update data
	 
	}
	else{
			}

	cout<<"\n\n\n\t\t\Are you sure you want to Change Price(y/n):";
	 
	fflush(stdin);
	scanf("%c",&c2);
	if(c2=='Y' || c2=='y')
	{
		cout<<"\n\n\t\tEnter Price : ";
		cin >> price;
		price_u = price;
	 //update data
	}
	else{
			}
	
	cout<<"\n\n\n\t\t\Are you sure you want to Change Quantity(y/n):";
	 
	fflush(stdin);
	scanf("%c",&c2);
	if(c2=='Y' || c2=='y')
	{
		cout<<"\n\n\t\tEnter Quantity : ";
	 cin >> quantity;
		quantity_u = quantity;
	 //update data
	}
	else{
			}


		deleteBook_byName(name_old);
	    AddBooks(id_u , name_u, author_u , quantity_u , price_u, shelf);
		cout<<"\n\n\t\t Book updated Sucessfully ! ";
			cout<<"press any key to continue";
	getch();
	mainmenu();;

		
	}
	else
	{
		cout << "No such Book Found! ";
		goto choices;
	    getche();
	}
	}
	 catch (int x ) { 
      cout << "Exception Caught \n"; 
   } 
	
}

void Book:: deleteBook()  //Delete the book whcih is not needed in the Library
{
	try {
	system("cls");
	string deletebook;
	cout<<"\n\n\t\tEnter Book ID : ";
	cin>>deletebook;

	bool status = isBookExists(deletebook);
	if(status == true)
	{
choiceselection:
		cout<<"\n\n\n\t\t\Are you sure you want to delete Book (y/n):";
	char c2;
	fflush(stdin);
	scanf("%c",&c2);
	
	if(c2=='Y' || c2=='y')
	{
		 

		deleteBook_byBookID(deletebook);
		cout <<"Book is deleted sucessfully\n";
	}
	else
	{
		 
		//cout <<"Enter Choice Again: ";
		//scanf("%c",&c2);
		goto choiceselection;
		


	}

	}
	else
		cout <<"No such Book exists ";
	
	cout<<"press any key to continue";
	getch();
	mainmenu();;
	}
	 catch (int x ) { 
      cout << "Exception Caught \n"; 
   } 
}

void Book:: deleteBook_byName(string deletebook)
{
	try {
	string id, name;
	string line;
	std::fstream myfile;
	std::fstream temp;
	//int status_ = remove("temp.txt");
	temp.open("temp.txt");
	myfile.open("LMS_Data.txt");
	if (!myfile.is_open()){
		exit(0);
	}
	while (myfile.good()){
		
		getline (myfile,line);

		istringstream ss(line);
		ss >> id ;
		ss >> name;
		if (name != deletebook)
		{
			temp << line << endl;
		}
		else
		{
			//delete
		}
	}
	
	temp.close();
	myfile.close();
	int status = remove("LMS_Data.txt");
	rename("temp.txt","LMS_Data.txt");
	cout <<endl<<endl<<endl;
	}
	 catch (int x ) { 
      cout << "Exception Caught \n"; 
   } 
	
}

void Book:: deleteBook_byBookID(string BookID)
{
	try {
	string id, name;
	string line;
	std::fstream myfile;
	std::fstream temp;
	//int status_ = remove("temp.txt");
	temp.open("temp.txt");
	myfile.open("LMS_Data.txt");
	if (!myfile.is_open()){
		exit(0);
	}
	while (myfile.good()){
		
		getline (myfile,line);

		istringstream ss(line);
		ss >> id ;
		ss >> name;
		if (id != BookID)
		{
			temp << line << endl;
		}
		else
		{
			//delete
		}
	}
	
	temp.close();
	myfile.close();
	int status = remove("LMS_Data.txt");
	rename("temp.txt","LMS_Data.txt");
	cout <<endl<<endl<<endl;
	}
	 catch (int x ) { 
      cout << "Exception Caught \n"; 
   } 
	
}

void Book:: SearchBooks() //Search the specific book
{

	system("cls");
	string Name;
    cout <<"\n\n\t\t\tPlease Write Book Name : ";
	cin >> Name;

	if(Name != "") 
	{	
	}

	ifstream input;
	size_t pos;
	string line, id, name, author, price, quantity, shelf;

	input.open("LMS_Data.txt");
	cout<<"********************************************************************************************************\n\n" ;
	cout<<"BOOKID"<<setw(15)<<"NAME"<<setw(25)<<"AUTHOR"<<setw(21)<<"PRICE"<<setw(20)<<"QUANTITY"<<setw(15)<<"SHELF"<<"\n\n" ;
	cout<<"*********************************************************************************************************\n\n" ;

	while(getline(input,line))
	{
		pos = line.find(Name);
		istringstream ss(line);
		/*string id_ , name_;*/
			ss >> id ;
		ss >> name;

		if(name ==Name)
		{
			istringstream ss(line);
			ss >> id ;
			ss >> name;
			ss >> author;
			ss >> price;
			ss >> quantity;
			ss >> shelf;

	cout<<id<<setw(25)<<name<<setw(20)<<author<<setw(20)<<price<<setw(15)<<quantity<<setw(15)<<shelf;
	cin.ignore(std::numeric_limits<std::streamsize>::max_digits10, '\n');
	cin.clear() ;
		break;}
	
	}
	cout<<"\npress any key to continue\n";
	getch();
	mainmenu();
}

 string Book::  get_departments()
{
	
	string code;
	int category = 0;
	int a=Books_Category();
	if(a==0)
	{
		mainmenu();
	}
	system("cls");
		
    printf("\n\n\n\t\t\t\tEnter The Book Information");
    switch(a)
    {
    	case 1:

    		printf("\n\n\t\t\tDepartment Name:Computer Science\n");
			category=1;
    		break;
        case 2:
        	printf("\n\t\t\tDepartment Name:Electrical Engineering\n");
			category=2;
        		break;
        	case 3:
        		printf("\n\t\t\tDepartment Name:Electronic Engineering\n");
				category=3;
        			break;
        		case 4:
        		printf("\n\t\t\tDepartment Name:Mechanical Engineering\n");
				category=4;
        			break;
        			case 5:
        		printf("\n\t\t\tDepartment Name:Civil Engineering\n");
				category=5;
        			break;
        			case 6:
        				printf("\n\t\t\tDepartment Name:Architecture Engineering\n");
						category=6;
        				break;
				

	}
	
	switch(category)
    {
    	case 1:
		code="CS";
    		break;
    		case 2:
    			code="EE";
    			break;
    			case 3:
    				code="ELE";
    				break;
    				case 4:
    					code="ME";
    					break;
    					case 5:
    						code="CE";
    						break;
    						case 6:
    							code="AR";
								break;
							default:
								code="0";
							
	}

	return code;
	getche();
}

 void Book:: ExpensiveBook()
{
	system("cls");
	ifstream inputFile("LMS_Data.txt");
	string line;
	int  min = 0;
	int  max = 0;
	int next;
	string id, name,author,price, quantity, shelf;
	int price1=0;
	string max_name, max_quantity, max_shelf, max_id,max_author,max_price;

	cout <<"\n Most Expensive Book in Library is : \n";
		cout<<"********************************************************************************************************\n\n" ;
		cout<<"BOOKID"<<setw(15)<<"NAME"<<setw(25)<<"AUTHOR"<<setw(21)<<"PRICE"<<setw(20)<<"QUANTITY"<<setw(15)<<"SHELF"<<"\n\n" ;
		cout<<"*********************************************************************************************************\n\n" ;
	while (getline(inputFile, line))
	{
		istringstream ss(line);
		ss >> id >> name >> author >> price >>quantity >>shelf;

		stringstream geek(price); 
		int x = 0; 
		geek >> x; 
		price1 = x;

		if (price1 > max)
		{
			max = price1;
			max_id = id;
			max_price = price;
			max_name = name;
			max_quantity = quantity;
			max_shelf= shelf;
			max_author = author;
			max_quantity= quantity;
			 
			
		}
		if (price1 < min)
		{
			min = price1;
		}


	}
	cout<<max_id<<setw(25)<<max_name<<setw(20)<<max_author<<setw(20)<<max_price<<setw(15)<<max_quantity<<setw(15)<<max_shelf<<"\n\n" ;
	cout<<"press any key to continue";
	getch();
	mainmenu();


	   
}

 void Book:: closeapplication()
{
	exit(0);
}

#pragma region Authentication
void Book:: Login() //For authenticated and successful login
{
	
	    		 
	/*printf("Enter UserName:");*/
		string username, password;cout << "\n\n";
	  
    cout << "\n";

   
	cout << "\n\n\t\t\tEnter User Name: ";	
     getline(cin , username);//take user name

	cout << "\n\n";
	cout << "\n\n\t\t\tEnter Password(4 Character): ";
	password = ConvertPasswordto_Asteriks();
        // finally print the right "wall" and a carraige return
   

	if (password == "1234" && username == "Areeba") {

		cout << "\n\n";
		cout << "Password Accepted";
		mainmenu();

	}
	else {
		cout << "\n\n";
		cout << "Password Denied Try Again !!!";
		Login();	}
} 

string Book::ConvertPasswordto_Asteriks()
{
	const int LEN = 4;
	char pass[LEN], lett;
	int iter;
	int len;
	string password2;
	//replace the password with *
	iter = 0;
	while(iter != LEN)
	{
		pass[iter] = '\0';
		iter++;
	}
	iter = 0;
	len = 0;
	lett = '\0';
	while( lett != '\r' )
	{
		lett = getch();
		if( lett == '\b' && pass[0] == '\0')
		{
			iter = 0;
			len = 0;
		}
		else
		{
			if( lett == '\b' && pass[0] != '\0')
			{
				cout << "\b";
				cout << " ";
				cout << "\b";
				iter--;
				pass[iter] = '\0';
				len--;
			}
			else
			{
				if( isprint( lett) != 0 && iter < LEN)
				{
					pass[iter] = tolower(lett);
					cout << "*" ;
				}
				iter++;
				if (iter <= LEN)
					len++;
			}
		}
	}
	//conversion of password to string
	iter = 0;
	len = len;
	password2 = "";
	while (iter != len)
	{
		password2 = password2+pass[iter];
		iter++;
	}
	return password2;
}
#pragma endregion

// end of class




