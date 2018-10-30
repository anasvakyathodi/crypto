//Created by Anand Baburajan when he was bored

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void encrypt()
{
    char fname[50];
    string data;
    cout << endl << endl << " Enter the file name: ";
    cin >> fname;
    fstream file1;
    file1.open(fname,ios::in);
    while(file1)
    {
        getline(file1, data);
    }
    file1.close();
    char key[20];
    cout <<" Enter the key: ";
    cin >> key;
    int a,i,j,l,k;
    l=data.length();
    k=strlen(key)-1;
    int haha[l];
    for(i=0,j=k;data[i]!='\0';i++,j--)
    {
           a=data[i]-key[j];
                haha[i]=a;
    if(j==0)
        j=k;
    }
    fstream file2;
    file2.open(fname,ios::out);
    for(i=0;data[i]!='\0';i++)
        file2<< haha[i] << " ";
    cout << endl << " Encryption successful..."<< endl << endl;
    file2.close();
}

void decrypt()
{
    fstream file3;
    int i,j,k,lc=-1,nc;
    char fname1[50];
    cout << endl << " Enter the file name: ";
    cin >> fname1;
    file3.open(fname1,ios::in);
    while(file3){
        file3 >> nc;
        lc++;
    }
    file3.close();
    int hah[lc],hahaa[lc];
    fstream file5;
    file5.open(fname1,ios::in);
    for(i = 0; i < lc; i++)
    file5 >> hahaa[i];
    file5.close();

    char keyy[20];
    cout<<" Enter the key: ";
    cin>>keyy;
    k=strlen(keyy)-1;
    for(i=0,j=k;i<lc;i++,j--)
    {
        hah[i]=hahaa[i]+keyy[j];
    if(j==0)
    j=k;
    }
    char ch;
    fstream file4;
    file4.open(fname1,ios::out);
    for(i=0;i<lc;i++)
    {
        ch = hah[i];
        file4 << ch;
    }
    cout << endl << " Decryption successful..."<< endl << endl;
    file4.close();
}

int main()
{
    int n;
    cout << endl << " Encrypt (1) / Decrypt (2) - - ";
    cin >> n;
    if(n==1)
        encrypt();
    else if(n==2)
        decrypt();
    else
        cout << endl << " Invalid input."<< endl << endl;
    system("pause");
    return 0;
}
