#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

void Select_case(int num_case){
    ifstream data1;
    string local;
    switch (num_case)
    {
        case 1 : local = "database/postoperative_data/abdominal/information";break;
        case 2 : local = "database/postoperative_data/cesarean/information";break;
        case 3 : local = "database/postoperative_data/eye/information";break;
        case 4 : local = "database/postoperative_data/gynecologic/information";break;
        case 5 : local = "database/postoperative_data/hernia/information";break;
        case 6 : local = "database/postoperative_data/hip Replacement/information";break;
        case 7 : local = "database/postoperative_data/spine/information";break;
    }
    
    data1.open(local.c_str());
    string textline;

    while(getline(data1,textline)){
        cout << textline << endl;
    }

}

