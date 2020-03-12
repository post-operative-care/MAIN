#include<iostream>
#include<fstream>
#include<iomanip>

struct Pt_data
{
    string name;
    int age;
    string doc_name;
    string Disease_name;
    
};

using namespace std;
int main() 
{
    fstream file("data.txt");
    string textline;
    while (getline(file,textline))
    {
        

    }
    


}

