#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<windows.h>
#include"ho.h"

using namespace std;

void pt_page(string user,int num_case)
{
    
    cout << "Wecome back " << user << " have a good day!" << endl;
    cout << "-------------------------------------------------------" << endl;
    Select_case(num_case);
    cout << "-------------------------------------------------------" << endl;
}