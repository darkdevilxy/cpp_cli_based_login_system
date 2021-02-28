#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

void show_menu();
void login_logic();
void sign_up_logic();
void logged_in_session(int mode_choice, string user_data);
void logged_in_session_menu(string user_data);
void edit_mode(string user_data);
void view_mode(string user_data);

void show_menu()
{
    cout<<"**********Login System**********"<<endl;
    cout<<endl;
    cout<<"1. Login"<<endl;
    cout<<"2. Sign Up"<<endl;
    cout<<"3. Remove User"<<endl<<endl<<endl;
    cout<<"What do you want to do? ";

}


void login_logic()
{
    string name, password;
    string user;

    ifstream file;

    cout<<endl<<"**********Login Menu**********"<<endl;
    cout<<endl;
    cout<<"Username: "<<endl;
    cin>>name;
    cout<<"Password"<<endl;
    cin>>password;

    user = name + password;

    file.open("./user" + user);
    if (file){
        cout<<"Logging in.......";
        cout<<"Welcome "<<name<<endl;

        logged_in_session_menu(user);
    }
    else{
        cout<<"Invalid credentials or user doesnt exist"<<endl;
    }


}

void sign_up_logic()
{
    string name, password;

    cout<<endl<<"**********Sign Up Menu**********"<<endl;
    cout<<"Please create a new account here if you are new user."<<endl;
    cout<<endl;
    cout<<"Username: "<<endl;
    cin>>name;
    cout<<"Password"<<endl;
    cin>>password;

    ofstream user("./user" + name + password);

    ifstream file;
    file.open("./user" + name + password);
    if(file){
        cout<<"User Created"<<endl;
    }

    cout<<"Proceding to login menu"<<endl<<endl<<endl;
    login_logic();


}

void logged_in_session_menu(string user_data)
{
    int option;
    cout<<"1. Edit"<<endl;
    cout<<"2. View"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<endl<<"What do you want to do? "<<endl;
    cin>>option;

    logged_in_session(option, user_data);
}

void logged_in_session(int mode_choice, string user_data)
{

switch (mode_choice) {

case 1:
    edit_mode(user_data);
    break;

case 2:
    view_mode(user_data);
    break;

case 3:
    break;

default:
    cout<<"Invalid Choice";

}
}

void edit_mode(string user_data)
{
    fstream user_file("./user" + user_data);

    if(user_file){

        string user_data_input = "user_file";
        string dummy_data;
        stringstream read_data;
        cout<<"Start typing"<<endl;

        while (user_data_input != ":close") {

            if(user_data_input == ":close"){
                system("clear");
                while(user_file >> read_data.rdbuf())
                    cout<< read_data.str() <<endl;
            }

         cin>>dummy_data;
         user_data_input = dummy_data;
         user_file << user_data_input << endl;


        }

    }
user_file.close();
}

void view_mode(string user_data)
{
    stringstream read_data;
    ifstream user_file("./user" + user_data);

    while(user_file >>read_data.rdbuf()){
         cout << read_data.str() <<endl;
       }
    user_file.close();
}

int main()
{
    int options;

    show_menu();

    cin>>options;
    switch (options) {
    case 1:
        login_logic();
        break;

    case 2:
        sign_up_logic();
        break;

    default:
        cout<<"Invalid Option";

    }
    return 0;
}
