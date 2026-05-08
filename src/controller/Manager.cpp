#include"../../include/controller/Manager.hpp"

Manager::Manager(Main_DB *db){
 this->db=db;
}
string getCurrentDate(){
    time_t now = time(0);
    tm *ltm = localtime(&now);

    return to_string(ltm->tm_mday)+ "/" +
           to_string(1 + ltm->tm_mon) + "/" +
           to_string(1900 + ltm->tm_year) ;
}
vector<string>Manager::split(string line){
    vector<string>d;
    string temp="";
    int l=line.length();
  for(int i=0;i<l;i++){
    
     if(line[i]==','){
        d.push_back(temp);
        temp="";
        continue;
     }
     else if(line[i]!=' '){
     temp+=line[i];
     }
  }
  d.push_back(temp);
  return d;
}
void Manager::updatecount(int userid,int n){
  auto lines=db->readUsers();
  vector<string>update;
  for(auto &line:lines){
     vector<string>d=split(line);
     if(d.size()<2) continue;
     if(d[0]==to_string(userid)){
      int count=stoi(d[2]);
      count=count+n;
      update.push_back(d[0]+","+d[1]+","+to_string(count));
     }
     else{
      update.push_back(line);
     }
  }
  db->UpdateUser(update);
}
void Manager::AddBook(){
    string title,Author_name,category;
    int id;
 cout<<"Enter the Title of Book :"<<endl;

 getline(cin,title);
 cout<<"Enter the Author Name of Book :"<<endl;
  getline(cin,Author_name);
 cout<<"Enter the Category of Book :"<<endl;
  getline(cin,category);
 cout<<"Enter the id of Book :"<<endl;
 cin>>id;
 Book b(id,title,Author_name,category);
   db->appendBook(b.add_to_file());
  cout<<"== Book Added =="<<endl;
}

void Manager::AddUser(){
    string name;
    int id;
    cout<<"Enter the user Name: "<<endl;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,name);
    cout<<"Enter the Id :"<<endl;
    cin>>id;
    User u(id,name);
    db->appendUser(u.add_to_file());
   cout<<"== User Added =="<<endl;

}
void Manager::SearchByTitle(){
  string title;
  cout<<"Enter the Title of Book"<<endl;
 // cin.ignore(numeric_limits<streamsize>::max(), '\n');
   getline(cin,title);
  auto lines=db->ReadBook();
  for(auto &line:lines){
       vector<string>d=split(line);
       if(d[1].find(title) != string::npos){
         cout<<"Book found :"<<endl;
        cout<<"ID|Title|Author_Name|Category|Status"<<endl;
        cout<<line<<endl;
        return;
       }
  }

  cout<<"== Book Not Found! =="<<endl;
}

void Manager::SearchByCategory(){
    string category,line;
    cout<<"Enter the Category :"<<endl;
    // cin.ignore();
    getline(cin,category);
      bool found=0;
      auto lines=db->ReadBook();
     for(auto &line:lines){
    vector<string>d=split(line);
     if(d.size() < 5) continue;
       if(d[3].find(category) != string::npos){
        if(found==0){
            cout<<"ID|Title|Author_Name|Category|Status"<<endl;
        }
        cout<<line<<endl;
        found=1;
       }
    }
    if(found==0){
        cout<<category<<"== Books Not Found ! =="<<endl;
    }

}
void Manager::Issue_Book(){
    int Book_id,User_id;
    string issue_date,line;
    bool found=0;
  cout<<"Enter The Book id :"<<endl;
  cin>>Book_id;
  cout<<"Enter The User id :"<<endl;
  cin>>User_id;
  issue_date=getCurrentDate();
  auto lines=db->ReadBook();
  vector<string>update;
   for(auto &line:lines){
  vector<string>d=split(line);
     if(d.size() < 5) continue;
       if(d[0]== to_string(Book_id)){
        found=1;
         if(d[4]=="Issued"){
            cout<<"== Book is Alredy Issued =="<<endl;
            update.push_back(line);
         }
         else{
            d[4]="Issued";
            update.push_back(d[0]+","+d[1]+","+d[2]+","+d[3]+","+d[4]);
            updatecount(User_id,1);
            db->appendLog(to_string(Book_id)+","+to_string(User_id)+","+issue_date+","+"NULL"+","+"Issued");    
         }
       }
       else{
       update.push_back(line);
       }
  }
 
  db->UpdateBooks(update);

if(!found){
    cout<<"== Book Not found =="<<endl;
}
else{
    cout<<"== Book Issued Successfully =="<<endl;
}

}
void Manager::Return_Book(){
     int Book_id,User_id;
    string Return_date,line;
    bool found=0;
  cout<<"Enter The Book id :"<<endl;
  cin>>Book_id;
  cout<<"Enter The User id :"<<endl;
  cin>>User_id;
 Return_date=getCurrentDate();
  auto lines=db->ReadBook();
  vector<string>update;
  for(auto &line:lines){
  vector<string>d=split(line);
   if(d.size() < 5) continue;
       if(d[0]== to_string(Book_id)){
        
         if(d[4]=="Available"){
            cout<<"== Book is Alredy Available =="<<endl;
           update.push_back(line);
         }
         else{
            found=1;
            d[4]="Available";
            update.push_back(d[0]+","+d[1]+","+d[2]+","+d[3]+","+d[4]);
            updatecount(User_id,-1);
              db->appendLog(to_string(Book_id)+","+to_string(User_id)+","+Return_date+","+"Returned");
         }

       }
       else{
        update.push_back(line);
       }


  }
  
  db->UpdateBooks(update);

if(!found){
    cout<<"== Book Not found =="<<endl;
}
else{
    cout<<"== Book Returned Successfully== "<<endl;
}

}
void Manager::RemoveBook(){
  int Book_id;
  cout<<"Enter the Book id which has to removed :"<<endl;
  cin>>Book_id;
  auto lines=db->ReadBook();
  vector<string>update;
  bool found;
  for(auto &line:lines){
     vector<string>d=split(line);
      if(d.size() < 5) continue;       
       if(d[0]== to_string(Book_id)){
        found=1;
        continue;
       }
       else{
         update.push_back(line);
       }
  }
 db->UpdateBooks(update);

  if(!found){
    cout<<"== Book Not Found ! =="<<endl;
  }
  else{
    cout<<"== Book Removed ! =="<<endl;
  }
  }
void Manager::UpdateBookDetails(){
    int Book_id;
    string line;
    bool found=0;
  cout<<"Enter The Book id :"<<endl;
  cin>>Book_id;
  auto lines=db->ReadBook();
  vector<string>update;
   for(auto &line:lines){
  vector<string>d=split(line);
   if(d.size() < 5) continue;
       if(d[0]== to_string(Book_id)){
        found=1;
        string Title,Category,Author_name;
        cout<<"Enter the New Title"<<endl;
        cin.ignore();
        getline(cin,Title);
         cout<<"Enter the New Author_Name"<<endl;
        getline(cin,Author_name);
         cout<<"Enter the New Category"<<endl;
        getline(cin,Category);
        update.push_back(to_string(Book_id)+","+Title+","+Author_name+","+Category+","+d[4]);
       }
       else{
        update.push_back(line);
       }

  }
 
 db->UpdateBooks(update);
if(!found){
    cout<<"== Book Not found =="<<endl;
}
else{
    cout<<"== Book Detailed Updated Successfully =="<<endl;
}

}
void Manager::Check_Availability(){
  int  Book_id;
      string line;
    cout<<"Enter The Book id :"<<endl;
     cin>>Book_id;
     auto lines=db->ReadBook();
      bool found=0;
   for(auto &line:lines){ 
    vector<string>d=split(line);
     if(d.size() < 5) continue;
       if(d[0]== to_string(Book_id)){
        if(found==0){
           if(d[4]=="Available"){
            cout<<"==  Book is Available == "<<endl;
           }
           else{
            cout<<"== Book is Not Available =="<<endl;
           }
        }
        cout<<line<<endl;
        found=1;
        break;
       }
    }
    if(found==0){
        cout<<"== Books Not Found ! =="<<endl;
    }

}