#include"include/controller/Manager.hpp"
#include "include/repository/File_DB.hpp"
#include"include/repository/MySql_DB.hpp"
int main(){
        cout<<"Select the DataBase"<<endl;
        cout<<"1) File DataBase\n2) SQL Database"<<endl;   
int c1;
Main_DB *db;
cin>>c1;
if(c1==1){
db= new File_DB(); 
  
}
else if(c1==2){
 db= new MySql_DB(); 

}
else{
db= new File_DB(); 
  
}
  Manager m(db);
int choice;
while(1){
cout<<endl;
cout<<"-------Library Management-------"<<endl;
cout<<"1) Add a Book                :"<<endl;
cout<<"2) Add a User                :"<<endl;
cout<<"3) Issue a Book              :"<<endl;
cout<<"4) Return a Book             :"<<endl;
cout<<"5) Search a Book By Title    :"<<endl;
cout<<"6) Search a Book By Category :"<<endl;
cout<<"7) Remove a Book             :"<<endl;
cout<<"8) Update Book Details       :"<<endl;
cout<<"9) Check Availability        :"<<endl;
cout<<"10) Exit the program         :"<<endl;
cout<<"\nEnter choice : ";
cin>>choice;

switch(choice){
    case 1: m.AddBook();
           break;
    case 2: m.AddUser();
           break;
    case 3: m.Issue_Book();
            break;
    case 4: m.Return_Book();
            break;
    case 5: m.SearchByTitle(); 
            break;
    case 6: m.SearchByCategory();
            break;
    case 7: m.RemoveBook();
            break;
    case 8: m.UpdateBookDetails();
            break;
    case 9: m.Check_Availability();
            break;
    case 10: exit(0);
           break;
    default :cout<<"Invalid input"<<endl;
}
}
delete db;
}