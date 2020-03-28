#include"library/ho.h"





int main()
 {
   char NowType;
 
   //Start();
   //selectPage();
   //register_page();
   NowType = login_page();
   cout << "now tpye is " << NowType << endl;
   direct_to(NowType);


   return 0;
 }

 void direct_to(char type)
   {
      if (type == 'D')
      {
         //goto doc page
      }
      else if (type == 'P')
      {
         //goto patient page
      }
   }

