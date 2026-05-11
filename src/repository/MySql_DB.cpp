#include"../../include/repository/MySql_DB.hpp"
MySql_DB::MySql_DB(){

    cout<<"MYSQL DATABASE CONNECTED\n";

    driver =
    sql::mysql::
    get_mysql_driver_instance();

    con =
    driver->connect(
        "tcp://127.0.0.1:3306",
        "root",
        "friday"
    );

    con->setSchema("library");
}

vector<Book> MySql_DB::loadBooks(){
    vector<Book> books;

    sql::Statement* stmt =
    con->createStatement();

    sql::ResultSet* res =
    stmt->executeQuery(
        "SELECT * FROM books"
    );

    while(res->next()){

        books.push_back(

            Book(
                res->getInt("id"),
                res->getString("title"),
                res->getString("author"),
                res->getString("category")
            )
        );
    }

    return books;
}
void MySql_DB::saveBooks(
    const vector<Book>& books
){

    cout<<"MYSQL saveBooks CALLED\n";

    sql::Statement* stmt =
    con->createStatement();

    stmt->execute(
        "DELETE FROM books"
    );

    for(const auto& book : books){

        string query =

        "INSERT INTO books VALUES("

        + to_string(book.get_id())

        + ",'"

        + book.get_title()

        + "','"

        + book.get_Author()

        + "','"

        + book.get_category()

        + "','"

        + to_string(book.get_status())

        + "')";

        cout<<query<<endl;

        stmt->execute(query);
    }

    delete stmt;
}

void MySql_DB::appendLog(  const string&log){
      sql::Statement* stmt =
    con->createStatement();

    string query =
    "INSERT INTO logs(log) VALUES('"
    + log + "')";

    stmt->execute(query);
}
vector<User>
MySql_DB::loadUsers(){

    vector<User> users;

    // create statement
    sql::Statement* stmt =
    con->createStatement();

    // execute query
    sql::ResultSet* res =
    stmt->executeQuery(
        "SELECT * FROM users"
    );

    // read row by row
    while(res->next()){

        User u(

            res->getInt("id"),

            res->getString("name")
        );

        users.push_back(u);
    }

    // cleanup
    delete res;

    delete stmt;

    return users;
}
void MySql_DB::saveUsers(
    const vector<User>& users
){

    sql::Statement* stmt =
    con->createStatement();

    // clear old data
    stmt->execute(
        "DELETE FROM users"
    );

    // insert all users again
    for(const auto& user : users){

        string query =

        "INSERT INTO users VALUES("

        + to_string(user.get_user_id())

        + ",'"

        + user.get_name()

        + "',"

        + to_string(
            user.getcount()
        )

        + ")";

        stmt->execute(query);
    }

    delete stmt;
}

