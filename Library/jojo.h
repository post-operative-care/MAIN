#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
  cout << "Please input your username and password to login." << endl ;
  char usn[20];
  char pw[20];
  cout << "username: " ;
  cin >> usn;
  cout << "password: " ;
  cin >> pw;

  ifstream login_info;
  login_info.open("database/user_data.txt");
  string textline;

  int x=0;
  int n=0 ;
  bool check=0;
  bool checkDorP=0;
  char text[50] ;
 // getline(login_info, textline);
  while(getline(login_info, textline)){
    while(n<50){
      text[n]=textline[n];
      n++;
    }
  
    //sscanf for id and pass
    char format[] = "%[^=]= %s %[^:]: %s %[^:]: %s";
    char id[20];
    char pass[20];
    char type[3];
    char blank1[10];
    char blank2[10];
    char blank3[10];
    sscanf(text,format,blank1,id,blank2,pass,blank3,type);

    //how many of char id
    bool num ;
    num = id[x];
    while(num){
		  x++;
		  num = id[x];
	  }
    //check username,id
    n=0;
    bool correctID=0;
    while(n<x){
      if(id[n]==usn[n]){
        n++;
        continue;
      }else{
        break;
      }
    }
    if(n==x) correctID=1 ;
    cout << "x = " << x << endl << "n = " << n << endl ;

    //how many of char pass
    bool num1 ;
    int y=0;
    num1 = pass[y];
    while(num1){
		  y++;
		  num1 = pass[y];
	  }
    //check password
    n=0;
    bool correctPASS=0;
    while(n<y){
      if(pass[n]==pw[n]){
        n++;
        continue;
      }else{
        break;
      }
    }
    if(n==y) correctPASS=1 ;
    cout << "y = " << y << endl << "n = " << n << endl ;
    cout << "__________________________________________\n";

    //correct id and pass
    if(correctID==1&&correctPASS==1){
      //check type
      if(type[0]=='D'){
        checkDorP=1;
        check=1;
        break;
       }else{
         check=1;
         break;
         }
    }

   // n2++;
    //getline(login_info, textline);
  }
  login_info.close();

  //check login sugsess or not
  bool next=0;
  if(check){
    cout << "\nLogging in success\n" ;
    next=1;
  }else cout << "Invalid username or password";

  ifstream userdata;
  userdata.open("database/userdatabase.txt");
  int k,i=0;
  string Number(k,100);
  int select;
  if(next){
    cout << "_____________________________________________________________\n\n";
    if(checkDorP){
      cout << "Dortor : \n" ; //wait for information for Doctor
      while(true){
        cout << "your patien : \n" ;
        while(getline(userdata, textline)){
            cout << "[" << (k+1) << "]  " << textline << "\n";
            i=0;
            k++;
            while(i<100){
              Number[k+1,i] = textline[i] ;
              i++;
              }
            }
            cout << "\nSelect your partient by number or exist select 0 : " ;
            cin.ignore();
            cin >> select ;
            if(select == 0){
               break ;
               i=0;
              }else{
                while(i<100){
                cout << Number[select,i] ;
                i++;
                }
              }
          }
      }else cout << "Mr \n" ; //wait for information for Patien
  }
  
  userdata.close();
  return 0;
}