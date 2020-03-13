#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>

using namespace std;

class ID_Pass
{
    private:
        string id;
        string pass;

    public:
        void create(string,string);
        string showID();
    
};

void ID_Pass::create(string user,string password)
{
    id = user;
    pass = password;
}

string ID_Pass::showID()
{
    return id;
}

class userdetails
{
    private:
        string name;
        int age;
        string doc_name;
        string Disease_name;

    public:
        void put_data(string,string);
    
};


bool charchecker(string text_input)
{
    bool check;
    for (int i = 0; i < text_input.size(); i++)
        {
            if (((text_input[i] >= 65 && text_input[i] <= 90) || (text_input[i] >= 97 && text_input[i] <= 122) || (text_input[i] >= 48 && text_input[i] <= 57)))
            //User name must be only a-z,A-Z,0-9
            {
                //if true reture true to charchecker()
                check = true;
            }
            else
            {
                //if false reture false to charchecker()
                check = false;
                break;
            }
            
            
        }
    return check;
}


vector <ID_Pass> database1;

void sign_up_page()
{ 
    bool charcheck;
    string text_input;
    string id;
    string password;
   
    do{


        cout << "Please enter your Username : ";
        getline(cin,text_input);

        charcheck = charchecker(text_input);
        id = text_input;
        

        if (charcheck == true)
        {
            p1:
            cout << "Please enter your Password : ";
            getline(cin,text_input);

            charcheck = charchecker(text_input);
            if (charcheck == true)
            {
                password = text_input;
                break;
            }
            else
            {
                cout << "Password must be only a-z,A-Z,0-9" << endl;
                goto p1;
            }
            
            
        }
        else
        {
            cout << "Username must be only a-z,A-Z,0-9" << endl;
    
        }
        
        ID_Pass username;
        username.create(id,password);
        database1.push_back(username);
        
    } while (true);



}



