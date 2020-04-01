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

  int n2=0;
  int n=0 ;
  bool check=0;
  bool checkDorP=0;
  char text[50] ;
  getline(login_info, textline);
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
    int x=0;
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
    getline(login_info, textline);
  }

  //check login sugsess or not
  if(check){
    cout << "Logging in sugsess" ;
  }else cout << "Invalid username or password";

  return 0;
}