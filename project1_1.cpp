//#include"library/ho.h"
#include"Library/patient_page.h"

void direct_to(string,char);

int main()
 {

   // Start();
   // NowType = login_page();
   // SetConsoleTextAttribute(h, 6); //chage color console
   // cout << "now tpye is " << NowType << endl;
   //selectPage();

   string user_and_type = login_page();

   char user_login[100];
   char type_user;

   sscanf(user_and_type.c_str(),"%s %c",&user_login,&type_user);

   direct_to(user_login,type_user);


   return 0;
 }


 void direct_to(string username,char type)
{
   if (type == 'D')
   {
      //doc_page(username);
      cout << "doc page" << endl;
   }
   else if (type == 'P')
   {
      pt_page(username,1);
   }
}


