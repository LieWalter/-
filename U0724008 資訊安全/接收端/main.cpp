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
    file.getline(a,1001);           //讀取訊息
    file.close();
    for(int i=0;i<1000;i++){cout<<a[i];}
    string b(a),c;
    c=printMD5(b);                  //產生訊息摘要
    cout<<endl<<"訊息摘要:"<<c<<endl;
    cout<<"key:";                   //輸入解密金鑰
    cin>>key;
    file.open("2.txt",ios::in);
    file.getline(d,sizeof(d));
    file.close();
    c+=key;                         //解密訊息摘要
    if(c==(string)d){
        cout<<"TRUE"<<endl;         //比對訊息摘要
    }
    else cout<<"false"<<endl;
}
