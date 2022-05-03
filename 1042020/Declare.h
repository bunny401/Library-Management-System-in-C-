#ifndef DECLARE_H
#define DECLARE_H
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


using namespace std;
class Book {
public:
	string code;
	string BookID;
	string Name;
	string Price;
	string Quantity;
	string Shelf;
	string Author;

public:
	Book();
	void AddBooks(bool isedit);
	void AddBooks(string BookID, string Name, string Author, string Quantity, string Price, string Shelf);
	void ViewBooks();
	int Books_Category();
	void mainmenu();
	void choices();
	void EditBook();
	void deleteBook();
	void deleteBook_byName(string deletebook);
	void deleteBook_byBookID(string BookID);
	void SearchBooks();
	string  get_departments();
	void ExpensiveBook();
	void closeapplication();
	void Login();
	string ConvertPasswordto_Asteriks();
	




};











#endif DECLARE_H
#pragma once
