// edited by phird
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<string>
#include<conio.h>
#include<windows.h>
#include <stdlib.h>
using namespace std ;

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
void changeColor(int desiredColor){
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}
//=====================================================================
 //====================================================================
//============================= OLD VERSION ================================
 bool checkduplicateName(string fname,string lname)
 { 
    char current_fname[100];
    char current_lname[100];
    ifstream database_file("database/postoperative_data/userdatabase.txt");
    string textline;
    
    while (getline(database_file,textline))
    {
        sscanf(textline.c_str(),"Name : %s LastName : %s  Date of Birth %d %s %d",&current_fname, &current_lname );
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

//=-------------=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
/* ool checkduplicateName(string fname,string lname)
 { 
    char current_fname[100];
    char current_lname[100];
    ifstream database_file("database/postoperative_data/userdatabase.txt");
    string textline;
    while(getline(database_file,textline))
    {
        sscanf(textline.c_str(),"Name : %s LastName : %s  Date of Birth %d %s %d",&current_fname, &current_lname );   
        cout << current_fname << " and " << current_lname << endl;
     /*         string ucfn(current_fname);
            string ucln(current_lname);
            ucfn = upper_string(current_fname);
            ucln = upper_string(current_lname);
            string ufn=upper_string(fname);
            string uln=upper_string(lname);        
     //if (ucfn == ufn && ucln == uln) 
     if (current_fname == fname && current_lname == lname)
            {    
            database_file.close(); 
            return true;
        }
        //cout << "THIS JUST TEST FOR UPPER ::  "<< ucfn << " : " << ucln << " and " << ufn << " : " << uln << endl;
        return false;
    } 
 } */
//===========================================================================
//===========================================================================
/* bool checkduplicateFName(string fname)
 {
    char cfname[fname.size()+1];
    char current_fname[100];
    ifstream database_file("database/postoperative_data/userdatabase.txt");
    string textline;
    
    while (getline(database_file,textline))
    {
        sscanf(textline.c_str(),"Name : %s",&current_fname);
        //for (int i = 0; i < strlen(cfname); i++) { putchar(toupper(cfname[i]));}
        //for (int i = 0; i < strlen(current_fname); i++) { putchar(toupper(current_fname[i]));}
        cout<<"Got From FName Is ::"<< current_fname << endl;
        if (current_fname == fname)
        {
            cout << "This is from F_name." << endl;
            return true;
        }        
    }
    return false;
    database_file.close(); 
 }
bool checkduplicateLName(string lname)
{
    char clname[lname.size()+1];
    char current_lname[100];
    ifstream database_file("database/postoperative_data/userdatabase.txt");
    string textline;
    
    while (getline(database_file,textline))
    {
        sscanf(textline.c_str(),"LastName : %s",&current_lname);
        //for (int i = 0; i < strlen(clname); i++) { putchar(toupper(clname[i]));}
        //for (int i = 0; i < strlen(current_lname); i++) { putchar(toupper(current_lname[i]));}
        cout<<"Got From LName Is ::"<< current_lname << endl;
        if (current_lname == lname)
        {
            cout << "This is from L_name" << endl;
            return true;
        }        
    }
    return false;
    database_file.close(); 
} */

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
int che=1;
do
{
    che=1;
    int recieve;
    cout << "\t\t\t ==>  ";
    cin>>recieve;
    switch (recieve)
    {
    case 1: cout << "\t\t\tStill wait for Fix "<< endl; break; // Wait for fix
    case 0: cout << "\t\t\tStill wait for Mainmenu "<< endl; break;
    default:
    che = 0 ;
    cout << "Check our Command";
        break; 
    }
    cin.clear();  
} while (che!=1); 
}
 
//===========================================================================
void ShowHasDone(int day,int month,int year,string fname,string lname,string weight,string height){
cout<< "\t\t\t-=========================================-"<< endl;
cout<<"\t\t\t Data of  "<<" "<< fname << " " << lname <<endl;
cout<<"\t\t\tWeight :"<< weight << " " << "Height :" << height <<endl;
cout<<"\t\t\t"<< "Date of Birth is "<< day << " "<< findNameMonth(month) <<" "<< year <<endl;
cout << "\t\t\thas added in database , THANKS !\n"  ;
cout<< "\t\t\t-=========================================-"<<endl;
cout<< "\t\t\t[ Press (1) : if you want to add new patient ]" << endl;
cout<< "\t\t\t[ Press (0) : Back To MENU ! ]"<< endl;
Command();
cout<< "\t\t\t-=========================================-"<<endl;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main(){

string fname,lname;
int day=0, month=0, year=0 ;
//system("COLOR 5F"); //COLOR 
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
                cout<<"\t\t\tPlease enter your patient firstname!\n";
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
do
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
//THIS FOR CHECK AND GET DATE OF BIRTH !
int chb = 1;
do
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
} 
while( chb !=1 );
//=======================================================================
// all here is for check before push back 
ShowHasDone(day,month,year,fname,lname,weight,height);
ofstream write("database/postoperative_data/userdatabase.txt",ios::out|ios::app); //Plan to delete what we just added
write << "Name : " <<fname<< " "<< "LastName : " <<lname << "  Date of Birth: "<<day<<" "<< findNameMonth(month) <<" "<< year << "   height:" << height << "  Weight:" << weight << endl;
write.close();

}
