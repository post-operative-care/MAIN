#include<iostream>
#include<cstring>
#include<string>
using namespace std;

string Encryption_ID(string text_input){
    string str_id;
    char str_idEnc[69];
    
    str_id = text_input;
    strcpy(str_idEnc,str_id.c_str());
    for (int i = 0; i<69 && str_idEnc[i]!='\0' ; i++) 
        {
            str_idEnc[i]=str_idEnc[i]+12;
        }
    //VecID.push_back(str_idEnc);
return str_idEnc;
}

string Encryption_PASS(string text_input){
    string str_password;
    char str_passwordEnc[69];
    str_password = text_input;
    strcpy(str_passwordEnc,str_password.c_str());
    for (int i = 0; i<69 && str_passwordEnc[i]!='\0' ; i++) {
        str_passwordEnc[i]=str_passwordEnc[i]+8;
    }
    return str_passwordEnc;
}
