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
                m++;                        //����1000�ýX
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
    }cout<<endl<<"�j�g�^��G"<<Z<<" �p�g�^��G"<<z<<" �Ʀr�G"<<m<<endl;
    string b(a),c,key;
    b = b.substr(0,b.length()-4);
    c=printMD5(b);                          //�T���K�n
    cout<<"�T���K�n�G"<<c<<endl;
    cout<<"key:";                           //��J�[�K���_
    cin>>key;
    c+=key;                                 //�[�K�T���K�n
    cout<<"�[�K�T���K�n�G"<<c<<endl;
    file.open("1.txt", ios::out);
    file.write(a,1000);
    file.close();
    file.open("2.txt",ios::out);            //���ͰT���ɮ׻P�[�K�T���K�n�ɮ�
    file<<c;
    file.close();
    rename("./1.txt","../������/1.txt");
    rename("./2.txt","../������/2.txt");
    file.open("1.txt", ios::out);
    file.write(a,1000);
    file.close();
    file.open("2.txt",ios::out);
    file<<c;
    file.close();
    return 0;
}
