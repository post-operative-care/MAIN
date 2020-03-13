#include"library1_1.h"

/*from Dev
    -Now my code can get ID and password
     and put back to Vector*/
 

int main() 
{
    
    ofstream file_out("data.txt");
    ifstream file_in("data.txt");
    string textline;

    sign_up_page();

    cout << "ID = " << VecID[0] << " PASSWORD = " << VecPASS[0];
    return 0;
}

