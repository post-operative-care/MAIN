#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>

using namespace std;


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

bool checkduplicateID(string ID)
{
    char cerent_name[100];
    ifstream file_in("data.txt");
    string textline;
    
    while (getline(file_in,textline))
    {
        //testcase
        //cout << "textline = " << textline << endl;
        sscanf(textline.c_str(),"ID = %s ",&cerent_name);
        //cout << cerent_name << endl;

        if (cerent_name == ID)
        {
            cout << "This username is already taken." << endl;
            return true;
        }
        

        
    }
    return false;
    file_in.close(); 
}


vector <string> VecID;
vector <string> VecPASS;
void sign_up_page()
{ 
    bool charcheck;
    string text_input;
    string str_id;
    string str_password;
   
    do{


        cout << "Please enter your Username : ";
        getline(cin,text_input);

        charcheck = charchecker(text_input);
        
        if (checkduplicateID(text_input) == true)
        {
            continue;
        }
        
        
        
        str_id = text_input;
        VecID.push_back(str_id);
        

        if (charcheck == true)
        {
            p1:
            cout << "Please enter your Password : ";
            getline(cin,text_input);

            charcheck = charchecker(text_input);
            if (charcheck == true)
            {
                str_password = text_input;
                VecPASS.push_back(str_password);
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


    } while (true);



}



