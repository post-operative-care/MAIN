#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<windows.h>
#include<cstdio>
#include<conio.h>
#include <stdlib.h>

HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
using namespace std;

//from jojo.h
//for doc search patient v0
void find_data(){
    int n=4; 
    vector<string> x(n);
    for(int i=0; i<n; i++){
        cout << "testcin : " ; 
        string nn;
        cin >> nn ;
        x[i] = nn ;
    }
    
    string b = ("bra bra bra") ;
    string c = ("information") ;
    for(int i=0; i<n; i++){
        cout << "[" << i+1 << "] " << x[i] << "\t" << b  << "\n" ;
    }

    while(true){
        cout << "select : " ;
        int i;
        cin >> i ;
        if(i==0)break;
        cout << "--------------------------------------------------\n" ;
        cout << x[i-1] << " : " << b << " " << c << "\n" ;
        cout << "--------------------------------------------------\n" ;
    }
    
}

//from Pack.h
void Select_case(int num_case){
    ifstream data1;
    string local;
    switch (num_case)
    {
        case 1 : local = "database/postoperative_data/postoperative_abdominal";break;
        case 2 : local = "database/postoperative_data/postoperative_cesarean";break;
        case 3 : local = "database/postoperative_data/postoperative_eye";break;
        case 4 : local = "database/postoperative_data/postoperative_Gynecologic";break;
        case 5 : local = "database/postoperative_data/postoperative_hernia";break;
        case 6 : local = "database/postoperative_data/postoperative_hipjoint";break;
        case 7 : local = "database/postoperative_data/postoperative_spine";break;
    }
    
    data1.open(local.c_str());
    string textline;

    while(getline(data1,textline)){
        cout << textline << endl;
    }

}

//from phird.h
string EncryptionID(string x){
    char encryp[69];

    strcpy(encryp,x.c_str());
    for (int i = 0; i < 69 && encryp[i] != '\0' ; i++)
    {
        encryp[i]=encryp[i]+2;
    }
    string a = encryp;
    //cout <<"WHAT DAFUQ :: " << a << " ";
return a;

}

string EncryptionPASS(string y){
    char encrypPass[69];

    strcpy(encrypPass,y.c_str());
    for (int j = 0; j < 69 && encrypPass[j] != '\0' ; j++)
    {
        encrypPass[j]=encrypPass[j]+3;
    }
    string p = encrypPass;
    //cout <<" Pass DAFUQ :: " << p << " ";
return p;
}

string DecrypttionID(string x){
    char decrypID[69];

    strcpy(decrypID,x.c_str());
    for (int i = 0; i < 69 && decrypID[i] != '\0' ; i++)
    {
        decrypID[i]=decrypID[i]-2;
    }
    string deID = decrypID;
return deID;
}

string DecrypttionPASS(string x){
    char decrypPASS[69];

    strcpy(decrypPASS,x.c_str());
    for (int i = 0; i < 69 && decrypPASS[i] != '\0' ; i++)
    {
        decrypPASS[i]=decrypPASS[i]-3;
    }
    string dePASS = decrypPASS;
return dePASS;
}


//from mek.h
bool charchecker(string text_input)
// this function used to detect input on username must be only a-z,A-Z,0-9
{
    bool check;
    for (int i = 0; i < text_input.size(); i++)
        {
            if (((text_input[i] >= 65 && text_input[i] <= 92) || (text_input[i] >= 97 && text_input[i] <= 124) || (text_input[i] >= 48 && text_input[i] <= 57)))
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

bool passchecker(string text_input)
// this function used to detect input on username must be only a-z,A-Z,0-9
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
/* this function used to detect input on username that user gave
 not in used in database */
{
    char cerent_name[100];
    ifstream file_in("database/user_data.txt");
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
    file_in.close(); 
    return false;
}


vector <string> VecID;
vector <string> VecPASS;

void sign_up_page()
/*This function is the main core for register page. It cin
 Username and password then put it back to VecID and VecPASS.*/
{ 
    bool charcheck;
    string textInput;
    string idEncryp;
    string passInput;
    string passInput1;
    string passInput2;
    string PassEncryp;
    //string str_id;
    //char str_idEnc[69];
    //string str_password;
    //char str_passwordEnc[69];
    do{


        cout << "Please enter your Username(Register) : ";
        getline(cin,textInput);
        charcheck = charchecker(textInput);
        
        if (checkduplicateID(textInput) == true)
        {
            continue;
        }
        idEncryp=EncryptionID(textInput);
        VecID.push_back(idEncryp);
        

        if (charcheck == true)
        {
            p1:
            cout << "Please enter your Password(Register) : "; // enter password for register
            getline(cin,passInput1);

            charcheck = passchecker(passInput1);
            if (charcheck == true)
            {
            cout << "Please confirm your Password(Register) : "; // confirm password
            getline(cin,passInput2);
            cout << "-------------------------------------------------------" << endl;

            if (passInput1 == passInput2)
            {
                PassEncryp=EncryptionPASS(passInput2);
                VecPASS.push_back(PassEncryp);
                break;
            }
            else
            {
                cout << "Password and confirm password does not match" << endl;
                cout << "Please try again" << endl;
                cout << "-------------------------------------------------------" << endl;
                goto p1;
            }
            
            
           
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


void register_page() 
/*not spacial in this func just make absaction for easy way to use in main*/
{
char ID[69];
string id_one;
char Pass[69];
string pass_one;

    ofstream file_out("database/user_data.txt",ios::app);
    
    sign_up_page();
    /*id_one = VecID;
    strcpy(ID,id_one.c_str());
    pass_one = VecPASS;
    strcpy(Pass,pass_one.c_str());
    for (int i = 0; i < 69 && ID[i] != '\0'; i++){
        ID[i]=ID[i]-12;
    }
    for (int j = 0; j < 69 && Pass[j] != '\0'; j++){
        Pass[j]=Pass[j]-8;
    } */

    //cout << "ID  = " << VecID[0] << " PASSWORD : " << VecID[0] << endl;
    
    file_out << "ID = " << VecID[0] << " PASSWORD : " << VecPASS[0] << " | TYPE : P" << endl;
    
    
}

string login_page()
{   
    bool login_success = false;
    bool usernamecheck = false;
    bool charcheck;
    string text_input;
    string str_id;
    string str_password;
    string now_username;
    string now_password;
    
   
    do{
        cout << "-------------------------------------------------------" << endl;
       
        cout << "Please enter your Username(Login) : ";
        getline(cin,now_username);

        cout << "Please enter your Password(Login) : ";
        getline(cin,now_password);

        cout << "-------------------------------------------------------" << endl;

        char database_name[100];
        char database_pass[100];
        char type;
        ifstream file_in("database/user_data.txt");
        string textline;

        while (getline(file_in,textline)) // find username and pass in database
        {
            //testcase
            //cout << "textline = " << textline << endl;
            sscanf(textline.c_str(),"ID = %s PASSWORD : %s | TYPE : %c",&database_name,&database_pass,&type);
            string enID = EncryptionID(now_username);

            //cout << databzse_name << " " << database_pass << endl;
        
           if (database_name == enID) 
            /*If Username that user input it's already in database 
            program will change usernamecheck to true*/
            {
                usernamecheck = true;
                //cout << usernamecheck << 1;
                break;
            }
            
        }
        file_in.close();
        
        //cout << usernamecheck << 2;
        if (usernamecheck == true)
        {
            string enPASS = EncryptionPASS(now_password);
            if (database_pass == enPASS)
            {
                cout << "login success" << endl;
                cout << "-------------------------------------------------------" << endl;
                login_success = true;

                string output = now_username+" "+type;
                return output;
            }
        }
        else
        {
            cout << "Username or Password  worng" << endl;
            cout << "Please enter your Username and Password again" << endl;
            continue;
            cout << "-------------------------------------------------------" << endl;
        }
        
    } while (login_success == false);
   return 0;
}

//from yoyo.h
void Start(){
    string detect;
    cout << setw(50) <<"Welcome To Post Operative Care\n";
    cout << setw(47) <<"Press Enter To Contineue\n" ;
    if(getline(cin,detect)){
    }
}

void selectPage(){
    string input;
    cout << "Did You Have An Accout?\n";
    cout << "[1] If you have\n[2] IF you don't have\n[3] If You are Medical Staff\n[4] For Exit\n";
    cout << "-------------------------------------------------------" << endl;
    do{cout << "Input Your Command Here: ";
    //cin >> input;
    getline(cin,input);
    cout << "-------------------------------------------------------" << endl;
    
    if(input == "1"){
        //login
        login_page();
        break;
    }else if(input == "2"){
        //register and login
        register_page();
        login_page();
        break;
    }else if(input == "3"){
        //wait for medical staff func
        break;
    }else if(input == "4"){
        //exit
        break;
    }else{
        cout << "Error Invalid Input\n";
    }
    }while(true);
}

//from pdatabase.h

bool isNotNumber(string s) 
 { 
    for (int i = 0; i < s.length(); i++) 
        if (isdigit(s[i]) == true) 
            return false; 
  
    return true; 
 } 


string upper_string(string str)
 {
    for(int i=0;str[i]!='\0';i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')   //checking for lowercase characters
            str[i] = str[i] - 32;        //converting lowercase to uppercase
    }
    return str;
 }

//THIS FOR CHANGE TEXT COLOR IN CONSOLE
void changeColor(int desiredColor)
 {
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
 }
//=====================================================================
//============================= OLD VERSION - And it's a new duplicate checker  ================================
 bool checkduplicateName(string fname,string lname)
  { 
    char current_fname[100];
    char current_lname[100];
    ifstream database_file("database/userdatabase.txt");
    string textline;
    
    while (getline(database_file,textline))
    {
        sscanf(textline.c_str(),"Name : %s LastName : %s  Date of Birth %d %d %d",&current_fname, &current_lname );
        //cout<<"DP Got From FName Is ::"<< current_fname << endl;
        //cout<<"DP Got From LName Is ::"<< current_lname << endl;
        string ucfn(current_fname);
        string ucln(current_lname);
         ucfn = upper_string(current_fname);
         ucln = upper_string(current_lname);
        string ufn=upper_string(fname);
        string uln=upper_string(lname);        
     
        if (ucfn == ufn && ucln == uln) //if (current_fname == fname && current_lname == lname)
        {
            database_file.close(); 
            return true;
            cout << "after return";
        }
        //cout << "LOOP IS ALIVE !!"<< endl;

    }
    return false;
    
  } 


//================================= END OF OLD VERSION =================================
//======================================================================
//THIS FOR FIND NAME OF MONTH BY INT THAT GET FROM USER 
string findNameMonth(int a)
 {
 switch (a)
    {
    case 1: return "January";
    case 2: return "February";
    case 3: return "March";
    case 4: return "April";
    case 5: return "May";
    case 6: return "June";
    case 7: return "July";
    case 8: return "August";
    case 9: return "September";
    case 10: return "October";
    case 11: return "November";
    case 12: return "December";   
    };
    return 0;
 }
//=======================================================================
void Command(){
 
 }
 
//===========================================================================
void ShowHasDone(int day,int month,int year,string fname,string lname,string weight,string height){
 cout<< "\t\t\t-=========================================-"<< endl;
 cout<<"\t\t\t Data of  "<<" "<< fname << " " << lname <<endl;
 cout<<"\t\t\tWeight :"<< weight << " " << "Height :" << height <<endl;
 cout<<"\t\t\t"<< "Date of Birth is "<< day << " "<< findNameMonth(month) <<" "<< year <<endl;
 cout << "\t\t\thas added in database , THANKS !\n"  ;
 cout<< "\t\t\t-=========================================-"<<endl;
 }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++







int main(){
cin.clear(); 
string fname,lname;
int day=0, month=0, year=0 ;
cout<< "\t\t\t-=========================================-"<< endl;
cout<<"\t\t\t\t WELCOME TO REGISTER PAGE"<<endl;
cout<< "\t\t\t-=========================================-"<<endl;
cout<<"\t\t\t Enter Your Patient Data Follow This \n"<<endl;
//=======================================================================================

 int acheck=1;
  do // IN DUOLICATE CHECK LOOP,LOOP ISN'T WORKIMG BUT USING GOTO INSTEAD !  
  {
    int acheck=1;
        int ch=1;
        //=========================== Loop FirstName Start here ==================================
       RegisterHere :
        do
        {
            ch = 1;
            cout<<"\t\t\t Input your patient FirstName :  ";
            getline(cin,fname);
            if(fname.find_first_not_of( "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")!=string::npos)
            {
                ch = 0;
                changeColor(12);
                cout<<"\t\t\tYou can only input alpha here!\n";
                changeColor(7);
            }
            else if(fname.empty())
            {
                ch = 0;
                changeColor(12);
                cout<<"\n\t\t\tPlease enter your patient firstname!\n";
                changeColor(7);
            }
        cin.clear();
        } 
        while( ch !=1 );
    //==================================Loop FirstName End here=================================
    //THIS FOR CHECK AND GET LASTNAME !
        int che=1;
        //==================== Loop Lastname Start here =============================================== 
        do{
            che = 1;
            cout<<"\t\t\t Input your patient LastName :  ";
            getline(cin,lname);
            if(lname.find_first_not_of( "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")!=string::npos)
            {
                che = 0;
                changeColor(12);
                cout<<"\t\t\tYou can only input alpha here!\n";
                changeColor(7);
            }
            else if(lname.empty())
            {
                che = 0;
                changeColor(12);
                cout<<"\t\t\tPlease enter your patient lastname!\n";
                changeColor(7);
        }
        cin.clear();
        }while( che !=1 );
         //======================== Loop lasname end here ================================================
    if (checkduplicateName(fname,lname) == true)
    {
        acheck = 0;
        changeColor(12);
        cout<<"\t\t\tThis Patient has already Registred.\n";
        changeColor(7);
        goto RegisterHere ;
    }
    cin.clear(); 
 }while ( acheck!=1 );

//========================================================================================

string weight,height;

int chw = 1 ;
do  //CHECK PATIENT WEIGHT AND HEIGHT
 {
    chw = 1;
    cout<<"\t\t\t Input your patient Weight (kg) : ";
    cin>>weight;
    if (isNotNumber(weight))
    {
        chw = 0;
        changeColor(12);
        cout<<"\t\t\tPlease Check your patient Weight !! \n";
        changeColor(7);
    }
    cin.clear();  
 } while (chw!=1);

 //=============================================================================================
 int chh=1;
 do
  {
    chh=1;
    cout<<"\t\t\t Input your patient height (cm) : ";
    cin>>height;
    if (isNotNumber(height))
    {
        chh = 0;
        changeColor(12);
        cout<<"\t\t\tPlease Check your patient Height ! \n";
        changeColor(7);
    }
    cin.clear();  
 } while (chh!=1);

//========================================================================================

int chb = 1;
do  //THIS FOR CHECK AND GET DATE OF BIRTH !
 {
    chb = 1;
    cout<<"\t\t\t Input your patient Birthday (dd mm yyyy) e.g 01 02 2000 ::  ";
    cin>>day>>month>>year;
    if(month < 1 or month > 12)
    {
        chb = 0;
        changeColor(12);
        cout<<"\t\t\tPlease Input Month between 1-12 ! \n";
        changeColor(7);
        if (month==1 or month==3 or month==5 or month==7 or month==8 or month==10 or month==12)
        {
           if (day>31 or day<1)
           {
           chb = 0;
           changeColor(12);
           cout<<"\t\t\tPlease Input Day between 1-31 ! \n";
           changeColor(7);
           }
        } 
        else if (month == 2)
        {
            if (day>29 or day<1)
            {
            chb = 0;
            changeColor(12);
            cout<<"\t\t\tPlease Input Day between 1-29 ! \n";
            changeColor(7);
            }
        }
        else if (month==4 or month==6 or month==9 or month==11)
        {
            //if (day>30 or day<1){
            if (day>30 or day<1)
            {
            chb = 0;
            changeColor(12);
            cout<<"\t\t\tPlease Input Day between 1-30 ! \n";
            changeColor(7);
            }
        }   
    }
    else if(year<1919 or year > 2020)
        {
            chb = 0;
           changeColor(12);
           cout<<"\t\t\tPlease CHECK  Years ! \n";
           changeColor(7);
        }
     cin.clear();     
 } while( chb !=1 );
//=======================================================================
// all here is for check before push back 
ShowHasDone(day,month,year,fname,lname,weight,height);
//======================================================

//========================================================
ofstream write("database/userdatabase.txt",ios::out|ios::app); //Plan to delete what we just added
write << "Name : " <<fname<< " "<< "LastName : " <<lname << "  Date of Birth: "<<day<<" / "<<month<<" / "<< year << "   height:" << height << "  Weight:" << weight << endl;
write.close();

}