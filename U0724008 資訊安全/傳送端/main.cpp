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
    char a[1000]="";
    int m=0,Z=0,z=0;
    srand(time(NULL));
    for(int i=0;i<1000;i++){
        while(true){
            a[i]=(char)(rand()%75+48);
            if(a[i]>57&&a[i]<65){
                continue;
            }
            if(a[i]>90&&a[i]<97){
                continue;
            }
            if(a[i]<=57){
                if(m==305){
                    continue;
                }
                m++;                        //產生1000亂碼
                break;
            }
            if(a[i]<=90){
                if(Z==345){
                    continue;
                }
                Z++;
                break;
            }
            if(z==350){
                continue;
            }
            else {z++;break;}
        }cout<<a[i];
    }cout<<endl<<"大寫英文："<<Z<<" 小寫英文："<<z<<" 數字："<<m<<endl;
    string b(a),c,key;
    b = b.substr(0,b.length()-4);
    c=printMD5(b);                          //訊息摘要
    cout<<"訊息摘要："<<c<<endl;
    cout<<"key:";                           //輸入加密金鑰
    cin>>key;
    c+=key;                                 //加密訊息摘要
    cout<<"加密訊息摘要："<<c<<endl;
    file.open("1.txt", ios::out);
    file.write(a,1000);
    file.close();
    file.open("2.txt",ios::out);            //產生訊息檔案與加密訊息摘要檔案
    file<<c;
    file.close();
    rename("./1.txt","../接收端/1.txt");
    rename("./2.txt","../接收端/2.txt");
    file.open("1.txt", ios::out);
    file.write(a,1000);
    file.close();
    file.open("2.txt",ios::out);
    file<<c;
    file.close();
    return 0;
}
