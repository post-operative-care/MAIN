#include"library1_1.h"

/*from Dev
    -Now my code can get ID and password
     and put back to Vector*/
 

int main() 
{
    
    ofstream file_out("data.txt",ios::app);
    

    cout << "-------------------------------------------------------" << endl;
    sign_up_page();
    cout << "-------------------------------------------------------" << endl;
    cout << "ID = " << VecID[0] << " PASSWORD : " << VecPASS[0] << endl;
    cout << "-------------------------------------------------------" << endl;
    file_out << "ID = " << VecID[0] << " PASSWORD : " << VecPASS[0] << endl;
    

    return 0;
    
}

