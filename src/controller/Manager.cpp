#include"../../include/controller/Manager.hpp"
Manager::Manager(Main_DB *db):service(db){ }
void Manager::AddBook(){
    int id;
    string title;
    string author;
    string category;
    cout<<"Enter ID: ";
    cin>>id;
    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );
    cout<<"Enter Title: ";
    getline(cin,title);

    cout<<"Enter Author: ";
    getline(cin,author);

    cout<<"Enter Category: ";
    getline(cin,category);

    Book b(id, title, author,category);

    service.addBook(b);

    cout<<"== Book Added ==\n";
}
void Manager::AddUser(){

    int id;
    string name;
    cout<<"Enter User ID: ";
    cin>>id;

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );

    cout<<"Enter Name : ";
    getline(cin,name);

    User u(id,name );

    service.addUser(u);

    cout<<"== User Added ==\n";
}
void Manager::SearchByTitle(){

    string title;

    cout<<"Enter Title: ";
    getline(cin,title);
    Book* book = service.searchByTitle(title);

    if(book == nullptr){
        cout<<"Book Not Found\n";
        return;
    }

    cout<<"\n===== Book Found=====\n";

   cout<<book->add_to_file()<<endl;
}
void Manager::SearchByCategory(){
    string category;
    cout<<"Enter Category: ";

    getline(cin,category);

    auto books =    service.searchByCategory(category);

    if(books.empty()){
        cout<<"No Books Found\n";
        return;
    }

    for(auto& book : books){

        cout<<"\n";

        cout<<"ID: "
            << book.get_id()
            << endl;

        cout<<"Title: "
            << book.get_title()
            << endl;

        cout<<"Author: "
            << book.get_Author()
            << endl;

        cout<<"Category: "
            << book.get_category()
            << endl;

        cout<<"Status: "
            << book.get_status()
            << endl;
    }
}
void Manager::Issue_Book(){

    int bookId;
    int userId;

    cout<<"Enter Book ID: ";
    cin>>bookId;

    cout<<"Enter User ID: ";
    cin>>userId;

    bool ok =
    service.issueBook(
        bookId,
        userId
    );

    if(ok)
        cout<<"== Book Issued ==\n";
    else
        cout<<"== Issue Failed ==\n";
}
void Manager::Return_Book(){

    int bookId;
    int userId;

    cout<<"Enter Book ID: ";
    cin>>bookId;

    cout<<"Enter User ID: ";
    cin>>userId;

    bool ok =
    service.returnBook(
        bookId,
        userId
    );

    if(ok)
        cout<<"== Book Returned ==\n";
    else
        cout<<"== Return Failed ==\n";
}
void Manager::RemoveBook(){

    int id;

    cout<<"Enter Book ID: ";

    cin>>id;

    bool ok =
    service.removeBook(id);

    if(ok)
        cout<<"== Removed ==\n";
    else
        cout<<"== Book Not Found ==\n";
}
void Manager::UpdateBookDetails(){

    int id;

    string title;
    string author;
    string category;

    cout<<"Enter Book ID: ";

    cin>>id;

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );

    cout<<"Enter New Title: ";
    getline(cin,title);

    cout<<"Enter New Author: ";
    getline(cin,author);

    cout<<"Enter New Category: ";
    getline(cin,category);

    bool ok =
    service.updateBook(
        id,
        title,
        author,
        category
    );

    if(ok)
        cout<<"== Updated ==\n";
    else
        cout<<"== Book Not Found ==\n";
}
void Manager::Check_Availability(){

    int id;

    cout<<"Enter Book ID: ";

    cin>>id;

    bool available =
    service.checkAvailability(id);

    if(available)
        cout<<"== Available ==\n";
    else
        cout<<"== Not Available ==\n";
}