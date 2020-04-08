#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

char Select_case(int num_case){
    ifstream data1;
    string local;
    switch (num_case)
    {
        case 1 : local = "database/postoperative_data/abdominal";break;
        case 2 : local = "database/postoperative_data/cesarean";break;
        case 3 : local = "database/postoperative_data/eye";break;
        case 4 : local = "database/postoperative_data/gynecologic";break;
        case 5 : local = "database/postoperative_data/hernia";break;
        case 6 : local = "database/postoperative_data/hip replacement";break;
        case 7 : local = "database/postoperative_data/spine";break;
    }
    
    data1.open(local.c_str());
    string textline,text_read;
    

    char select;
    string skeyword,ekeyword;
    do{
        cout << "select data :" ;
        cin >> select;
        if(select == 'A' || select == 'a' )
        {
        skeyword = "!";
        ekeyword = "@";
        break;
        }
        else if(select == 'W' ||select == 'w' )
        {
        skeyword = "#";
        ekeyword = "$";
        break;
        }
        else if(select == 'D' ||select == 'd' )
        {
        skeyword = "%";
        ekeyword = "^";
        break;
        }
        else if(select == 'P' ||select == 'p' ){
        skeyword = "&";
        ekeyword = "*";
        break;
        }
        else
        {
        cout << "You entered incorrectly. Please enter again." << "\n";
    }
    }while(select != 'A' || select != 'a' || select != 'D' ||select != 'd' || select != 'W' || select != 'W' || select != 'P' ||select != 'p'  );
    
    int start,end,count=0;
    while(getline(data1,textline)){    
        int start = textline.find_first_of(skeyword);
        int end = textline.find_first_of(ekeyword);
        if(start==-1&&end==-1&&count==0){
            continue;
        }else if(start!=-1){
            cout << textline.substr(1,textline.size()) << "\n";
            count = 1;
        }else if(end==-1&&count==1) {
            cout << textline << "\n";
        }else{
            cout << textline.substr(0,textline.size()-1) << "\n";
            break;
            } ;
    }
    
    data1.close();
    return 0;
}

char check_if_read()
{
    ifstream file_userdata ("");



     char action;
    do{
        cout << "Please enter your selection : ";
        cin >> action;
        if(action == 'A' || action == 'a' )
        {
            cout << "OK, I got this." << "\n" << "----------------------------------------------------------------" << "\n";
        return 'A';
        }
        else if(action == 'E' ||action == 'e' )
        {
            cout << "Go to main menu." << "\n" << "----------------------------------------------------------------" << "\n";
        return 'E';
        }
        else
        {
            cout << "You entered incorrectly. Please enter again." << "\n";
        }
        }while(action != 'A' || action != 'a' || action != 'E' ||action != 'e' );
    
    return 0;
}
