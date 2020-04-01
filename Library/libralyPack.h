#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

<<<<<<< HEAD
void Select_case(int num_case){
=======
char Select_case(int num_case){
>>>>>>> Data_ho
    ifstream data1;
    string local;
    switch (num_case)
    {
<<<<<<< HEAD
        case 1 : local = "database/postoperative_data/postoperative_abdominal";break;
        case 2 : local = "database/postoperative_data/postoperative_cesarean";break;
        case 3 : local = "database/postoperative_data/postoperative_eye";break;
        case 4 : local = "database/postoperative_data/postoperative_Gynecologic";break;
        case 5 : local = "database/postoperative_data/postoperative_hernia";break;
        case 6 : local = "database/postoperative_data/postoperative_hipjoint";break;
        case 7 : local = "database/postoperative_data/postoperative_spine";break;
=======
        case 1 : local = "database/postoperative_data/abdominal";break;
        case 2 : local = "database/postoperative_data/cesarean";break;
        case 3 : local = "database/postoperative_data/eye";break;
        case 4 : local = "database/postoperative_data/gynecologic";break;
        case 5 : local = "database/postoperative_data/hernia";break;
        case 6 : local = "database/postoperative_data/hip replacement";break;
        case 7 : local = "database/postoperative_data/spine";break;
>>>>>>> Data_ho
    }
    
    data1.open(local.c_str());
    string textline;

    while(getline(data1,textline)){
        cout << textline << endl;
    }
<<<<<<< HEAD

}

=======
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
>>>>>>> Data_ho
