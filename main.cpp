#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include <string>
#include <fstream>


using namespace std;

#include "MySql_Connection.hpp"


int main();
class Question;

class Quiz
{   private:
    int marks;
    string id;
    string password;
    string confirm_password;
    string name;
    int login_attempt;
    string admin_user = "Admin";
    string admin_pass = "Admin";
    char th;


    public:
    Quiz()
    {
        marks = 0;
        login_attempt = 0;
    }
    string getid(){
    return id;
    }
    string getname(){
    return name;
    }
    void Create_user_login();
    void User_login();
    void Display_user_data();
    void admin_login();

};

void Quiz :: Create_user_login()
{
    cin.get();
    cout << "Enter the ID : " ;
    getline(cin,id);
    cout << "Enter the Name : ";
    getline(cin,name);
    cout << "Enter the password : ";
    getline(cin,password);
    cout << "Confirm the password : ";
    getline(cin,confirm_password);

    if(password != confirm_password)
    {
        cout<< "\n\nRe-Enter The Details : \n";
        Create_user_login();
    }

}

void Quiz :: User_login()
{
    cin.get();
    cout << "\n\n\t\tWelcome to sign in" << endl;
    string Check_id;
    string Check_name;
    string Check_password;
    cout << "Enter the ID : " ;
    getline(cin,Check_id);
    cout << "Enter the Name : ";
    getline(cin,Check_name);
    cout << "Enter the password : ";
    getline(cin,Check_password);

    if(id == Check_id)
    {
        if(name == Check_name)
        {
            if(password == Check_password)
            {
                cout << "\n\nWelcome " << name << endl;
            }
            else
            {
                cout << "\n\nInvalid Password. " <<endl;
                cout << "Do you want to continue[y|n]!!" ;
                cin >> th;
                if(th=='y'||th=='Y')
                {
                    User_login();
                }
                else{
                    cout << "Exiting !!!" << endl;
                    main();
                }

            }
        }
        else
        {
            cout << "Invalid Name. " << endl;
            cout << "Do you want to continue[y|n]!!" ;
            cin >> th;
            if(th=='y'||th=='Y')
            {
                User_login();
            }
            else{
                cout << "Exiting !!!" << endl;
                main();
            }
        }
    }

    else
    {
        cout << "\nInvalid ID \n" << endl;
        cout << "Do you want to continue[y|n]!!" ;
        cin >> th;
        if(th=='y'||th=='Y')
        {
            User_login();
        }
        else{
            cout << "Exiting !!!" << endl;
            main();
        }
    }
}

void Quiz :: Display_user_data()
{
    cout << id << endl;
    cout << name << endl;
    cout << password << endl;
}

void Quiz ::admin_login()
{
    string check_admin_id;
    string check_admin_pass;
    cin.get();

    cout << "Enter the Admin ID : ";
    getline(cin,check_admin_id);

    cout << "Enter the Admin password : ";
    getline(cin,check_admin_pass);

     if(admin_user == check_admin_id)
    {

        if(admin_pass == check_admin_pass)
        {
            cout << "\n\nWelcome " << admin_user << "\n\n" << endl;
        }
        else
        {
            cout << "\n\nInvalid Password. " <<endl;
            admin_login();
        }

    }

    else
    {
        cout << "\nInvalid ID \n" << endl;
        admin_login();
    }


}

class Question
{
    private:
    string question;
    string option1;
    string option2;
    string option3;
    string option4;
    string correctans;
    string User_ans;
    int count=0;
    int counter = 0;
    public:
    void Get_question();
    void Show_question(int ques);
    int Show_question_User(int ques,int cou);
    int get_marks(){return count;}
    string encryption(string temp);
    string decryption(string temp);

};

string Question :: encryption(string temp)
{
    for(int i = 0;temp[i] != '\0'; i++)
    temp[i] = temp[i] + 2; //the key for encryption is 3 that is added to ASCII value
    return temp;
}

string Question :: decryption(string temp)
{
    for(int i = 0; (temp[i] != '\0'); i++)
    temp[i] = temp[i] - 2; //the key for encryption is 3 that is subtracted to ASCII value
    return temp;
}

void Question :: Get_question()
{
    cin.get();
    cout << "Enter the question : ";
    getline(cin,question);

    cout <<"Enter Option 1 : ";
    getline(cin,option1);

    cout << "Enter Option 2 : ";
    getline(cin,option2);

    cout << "Enter Option 3 : ";
    getline(cin,option3);

    cout << "Enter Option 4 : ";
    getline(cin,option4);

    cout << "Enter the Answer : ";
    getline(cin,correctans);

    ofstream myfile;
    ofstream myans;

    myfile.open("myfile.dat",ios::out|ios::app);

    myfile << encryption(question) << endl;
    myfile << encryption(option1) << endl;
    myfile << encryption(option2) << endl;
    myfile << encryption(option3) << endl;
    myfile << encryption(option4) << endl;
    myfile.close();
    myans.open("myans.dat",ios::out|ios::app);
    myans << encryption(correctans) << endl;
    myfile.close();



}

void Question :: Show_question(int ques)
{
    ifstream infile;
    ifstream inans;
    infile.open("myfile.dat");
    inans.open("myans.dat");
    string data;
    string data1;

    for(int i=0;i<ques;i++)
    {
        infile >> data;
        cout << "\nQ " << decryption(data) <<endl;
        infile >> data;
        cout << "1. " << decryption(data) << endl;
        infile >> data;
        cout << "2. " << decryption(data) << endl;
        infile >> data;
        cout << "3. " << decryption(data) << endl;
        infile >> data;
        cout << "4. " << decryption(data) << endl;
        inans >> data1;
        cout << "Answer : " << decryption(data1) << endl;
    }
    infile.close();
    inans.close();

}

int Question :: Show_question_User(int ques,int cou)
{

    ifstream infile;
    ifstream inans;
    infile.open("myfile.dat");
    inans.open("myans.dat");
    string data;
    string data1;

     for(int i=0;i<ques;i++)
    {
        infile >> data;
        cout << "\nQ " << decryption(data) <<endl;
        infile >> data;
        cout << "1. " << decryption(data) << endl;
        infile >> data;
        cout << "2. " << decryption(data) << endl;
        infile >> data;
        cout << "3. " << decryption(data) << endl;
        infile >> data;
        cout << "4. " << decryption(data) << endl;
        inans >> data1;
        cout << "Enter the Answer : " ;
        cin >> User_ans;
        if (decryption(data1) == User_ans)
        {
            cou = cou + 4;
        }
    }
    infile.close();
    inans.close();
    return cou;
}


int main()
{
    Quiz q;
    int questions;
    Question* ptr = new Question[questions];
    int c;
    MYSQL* conn = connectdatabase();
    op:
    if(conn){
    string markdb1,totaldb1;



   int option,option2;
   int count =0,total_count,marks;
   int op;
   ofstream infile;
   ifstream outfile;

    do{
        cout << "\n\n1. Sign up." << endl
             << "2. Sign in " << endl
             << "3. Sign in For Admin." << endl
             << "0. EXIT." << endl
             << "\n\nSelect Your Choice : " ;
        cin >> option;

    switch(option){
        case 1: system("cls");
                q.Create_user_login();
                break;
        case 2: system("cls");
                q.User_login();
                do{
                    system("cls");
                    cout << "\n1. proceed for test. " << endl;
                    cout << "0. Exit." << endl;
                    cin >> option2;

                    switch(option2)
                    {
                        case 1: outfile.open("myque.dat");
                                outfile >> questions;
                                outfile.close();

                                marks = ptr->Show_question_User(questions,count);

                                total_count = 4*questions;
                                cout << "\nMarks : " << marks << "/" << total_count ;
                                markdb1 = to_string(marks);
                                totaldb1 = to_string(total_count);
                                insertion(conn,q.getid(),q.getname(),markdb1,totaldb1);
                                cout << "\nPress any key to continue. " << endl;
                                cin >> op;
                                break;

                    }
                }while(option2!=0);
                break;
        case 3: system("cls");
                q.admin_login();
                do{
                    system("cls");
                    cout << "1. Set question. " << endl;
                    cout << "2. View questions." << endl;
                    cout << "3. View Score." << endl;
                    cout << "4. Delete Score." << endl;
                    cout << "0. Exit." << endl;

                    cout << "\n\nSelect Your choice : ";
                    cin >> option2;

                    switch(option2)
                    {
                        case 1: system("cls");
                                remove("myfile.dat");
                                remove("myans.dat");
                                remove("myque.dat");

                                cout << "\n\t\tWelcome to setting question.\n\n" << endl;

                                cout <<"\nEnter Number of question : " ;
                                cin >> questions;
                                infile.open("myque.dat",ios::app|ios::out);
                                infile << questions;
                                infile.close();

                                for(int i=0;i<questions;i++)
                                {
                                    ptr->Get_question();
                                }
                                break;

                        case 2: system("cls");

                                outfile.open("myque.dat");
                                outfile >> questions;
                                outfile.close();


                                cout << "\n\t Questions." << endl;
                                ptr->Show_question(questions);
                                cout << "\n\nPress any key to continue. " << endl;
                                cin >> op;
                                break;
                        case 3: system("cls");
                                cout << "\n\t\t Score.\n" << endl;
                                display(conn);
                                cout << "\n\nPress any key to continue. " << endl;
                                cin >> op;
                                break;
                        case 4: cout << "\n\t Deleting record." << endl;
                                deletedb(conn);
                                cout << "\n\nPress any key to continue. " << endl;
                                cin >> op;
                                break;

                    }

                }while(option2!=0);
                break;
            default:cout << "\n\n\t\t!!!!!Wrong Entry!!!!!\n\n" << endl;
                    cin.get();
                    main();
                    break;
            case 0: cout << "Thank You! Exiting!\n\n " << endl;
                    break;


    }

    }while(option!=0);

    }
    else{
        exit(0);
    }

    return 0;
}
