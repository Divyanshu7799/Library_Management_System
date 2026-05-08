#ifndef MANAGER_H
#define MANAGER_H
#include<iostream>
#include"../models/Book.hpp"
#include"../models/User.hpp"
#include"../repository/File_DB.hpp"
#include"../repository/Main_DB.hpp"
#include"../service/Library_Helper.hpp"
#include<limits>
#include<vector>
using namespace std;
class Manager{
private:
Library_Helper service;
public:
Manager(Main_DB *db);
void UpdateBookDetails();
void AddBook();
void AddUser();
void Issue_Book();
void Return_Book();
void SearchByTitle();
void SearchByCategory();
void RemoveBook();
void Check_Availability();
vector<string> split(string s);
void updatecount(int userid,int n);
} ; 

#endif