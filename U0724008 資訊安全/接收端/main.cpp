#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "./src/md5.h"

using namespace std;

string printMD5(const string& message) {
  return MD5(message).toStr();
}

int main()
{
    fstream  file;
    char a[1001],d[200];
    string key;
    file.open("1.txt",ios::in);
    file.getline(a,1001);           //Ū���T��
    file.close();
    for(int i=0;i<1000;i++){cout<<a[i];}
    string b(a),c;
    c=printMD5(b);                  //���ͰT���K�n
    cout<<endl<<"�T���K�n:"<<c<<endl;
    cout<<"key:";                   //��J�ѱK���_
    cin>>key;
    file.open("2.txt",ios::in);
    file.getline(d,sizeof(d));
    file.close();
    c+=key;                         //�ѱK�T���K�n
    if(c==(string)d){
        cout<<"TRUE"<<endl;         //���T���K�n
    }
    else cout<<"false"<<endl;
}
