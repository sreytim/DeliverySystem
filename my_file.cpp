#include<iostream>
#include<fstream>
#include<cstring>
#include<thread>
#include<chrono>
#include "getch.h"
#define pause getch();
using namespace std;
void gotoy(){
    cout<<"\n\n\n\n\n";
}
void Loading() {
    gotoy();
    cout << "\t\t\t\t\tWelcome.....!!" << endl;
    
    cout << "\t\t\t\t\t";
    for (int i = 0; i < 8; i++) {
        this_thread::sleep_for(chrono::seconds(1));
        cout << ".";
        cout.flush();
    } 
    cout<<"Login Successfully!";
}
class Register{
    private:
    char username[20];
    char email[20];
    char password[20];
    public:
    void Input(){
        re:
        gotoy();
        cout<<"\t\t\t\t*************Register Here*************"<<endl;
        cout<<"\t\t\t\t\tEnter Username:";cin.getline(username,20);
        cout<<"\t\t\t\t\tEnter Email   :";cin.getline(email,20);
        cout<<"\t\t\t\t\tEnter Password:";cin.getline(password,20);
        cout<<"\t\t\t\t***************************************"<<endl;
        if(strlen(password) < 8){
            cout<<"\t\t\tYour password must be at least 8 characters!"<<endl;
            pause;
            system("clear");
            goto re;
        }
    }
    char * getUsername(){
        return username;
    }
    char * getEmail(){
        return email;
    }
    char * getPassword(){
        return password;
    }
};
void Regist(){
    Register reg;
    fstream file;
    file.open("UserRecord.bin",ios::app|ios::binary);
    reg.Input();
    file.write((char*)&reg,sizeof(reg))<<endl;
    file.close();
}
void Login(){
    Register arr[100],reg;
    fstream file;
    int count = 0;
    char nameoremail[20], password[20];
    file.open("UserRecord.bin", ios::in|ios::binary);
    while(file.read((char*)&reg,sizeof(reg))){
        arr[count] = reg;
        count++;
    }
    again:
    gotoy();
        cout<<"\t\t\t\t************* Login Form **************"<<endl;
        cout<<"\t\t\t\t\tEnter Username or Email:";cin.getline(nameoremail,20);
        cout<<"\t\t\t\t\tEnter Password:";cin.getline(password,20);
        cout<<"\t\t\t\t***************************************"<<endl;
        for(int i = 0; i<count;i++){
            if(((strcmp(nameoremail,arr[i].getUsername()) == 0) || (strcmp(nameoremail,arr[i].getEmail()) == 0)) && (strcmp(password,arr[i].getPassword()) == 0)){
                system("clear");
                Loading();
                return;
            }else{
                cout<<"\t\t\t\t Invalid Username or Email or Password.";
                pause;
                system("clear");
                goto again;
            }
        }
        file.close();
}
void Form(){
    int op;
    sys:
    gotoy();
    cout<<"\t\t\t\t***************************************"<<endl;
    cout<<"\t\t\t\t*                                     *"<<endl;
    cout<<"\t\t\t\t*         <<<DELIVERY SYSTEM>>>       *"<<endl;
    cout<<"\t\t\t\t*                                     *"<<endl;
    cout<<"\t\t\t\t***************************************"<<endl;
    cout<<"\t\t\t\t** 1. Sign In *********** 2. Sign Up **"<<endl;
    cout<<"\t\t\t\t***************************************"<<endl;
    cout<<"\t\t\t\tChoose one option:";cin>>op;
    if(op == 1){
        system("clear");
        cin.ignore();
        Login();
    }else if(op == 2){
        system("clear");
        cin.ignore();
        Regist();
        pause;
        system("clear");
        goto sys;
    }else{
        system("clear");
        goto sys;
    }
}
void Menu(){
    gotoy();
    cout<<"\t\t\t\t************* Input Form **************"<<endl;
    cout<<"\t\t\t\t| 1. Write Data                       |"<<endl;
    cout<<"\t\t\t\t***************************************"<<endl; 
    cout<<"\t\t\t\t| 2. Read Data                        |"<<endl;
    cout<<"\t\t\t\t***************************************"<<endl; 
    cout<<"\t\t\t\t| 3. Update Data                      |"<<endl;
    cout<<"\t\t\t\t***************************************"<<endl; 
    cout<<"\t\t\t\t| 4. Delete Data                      |"<<endl;
    cout<<"\t\t\t\t***************************************"<<endl; 
}
class Customer{
    private:
    int id;
    char name[20];
    char tel[20];
    char location[20];
    char time[20];
    public:
    Customer(){
        id = 0;
        strcpy(name,"undifine");
        strcpy(tel,"undifine");
        strcpy(location,"undifine");
        strcpy(time,"undifine");
    }
    void Input(){
        cout<<"\t\t\t\t************* Input Form **************"<<endl;
        cout<<"\t\t\t\t\tEnter ID       :";cin>>id;
        cout<<"\t\t\t\t\tEnter Name     :";cin.ignore();cin.getline(name,20);
        cout<<"\t\t\t\t\tEnter Tel      :";cin.getline(tel,20);
        cout<<"\t\t\t\t\tEnter Time     :";cin.getline(time,20);
        cout<<"\t\t\t\t\tEnter Location :";cin.getline(location,20);
        cout<<"\t\t\t\t***************************************"<<endl;
    }
    void Output(){
        cout<<"\t\t\t"<<id<<"\t\t"<<name<<"\t\t"<<tel<<"\t\t"<<time<<"\t\t"<<location<<endl;
    }
    int getID(){
        return id;
    }
};
int main(){
    Customer cus;
    Form();
    fstream file;
    system("clear");
    int op;
    do{
        Menu();
        cout<<"\t\t\t\t  Enter one option:";cin>>op;
        switch(op){
            case 1:{
                system("clear");
                gotoy();
                file.open("CustomerRecord.bin", ios::app | ios::binary);
                cus.Input();
                file.write((char*)&cus, sizeof(cus));
                cout<<"\t\t\t\t        Data was recorded!";
                file.close();
                break;
            }
            case 2:{
                system("clear");
                gotoy();
                file.open("CustomerRecord.bin", ios::in | ios::binary);
                cout<<"\t\t                                       Record Data"<<endl;
                cout<<"\t\t **********************************************************************************************"<<endl;
                cout<<"\t\t        ID\t\tName\t\tTel\t\t\tTime\t\tLocation"<<endl;
                cout<<"\t\t **********************************************************************************************"<<endl;
                while(file.read((char*)&cus,sizeof(cus))){
                    cus.Output();
                    cout<<"\t\t **********************************************************************************************"<<endl;               
                }
                pause;
                file.close();
                break;
            }
            case 3:{
                int sid;
                fstream tmp;
                system("clear");
                file.open("CustomerRecord.bin", ios::in | ios::binary);
                tmp.open("Tmp.bin",ios::out | ios::binary);
                gotoy();
                int check = 0;
                cout<<"\t\t\t\t **************** Update Form ***************"<<endl<<endl;
                cout<<"\t\t\t\t\t Enter ID you want to update:";cin>>sid;
                cout<<"\t\t\t\t ********************************************"<<endl;
                while(file.read((char*)&cus,sizeof(cus))){
                    if(sid == cus.getID()){
                        pause;
                        system("clear");
                        gotoy();
                        cus.Input();
                        tmp.write((char*)&cus,sizeof(cus));
                        check = 1;
                        cout<<"\t\t\t\t\t  Update successfully!"<<endl;
                    }else{
                        tmp.write((char*)&cus,sizeof(cus));
                    }
                }
                if(check == 0){
                    
                    cout<<"\t\t\t\t\tID not found, please try again!"<<endl;
                    pause;
                    pause;
                    system("clear");
                }
                file.close();
                tmp.close();
                remove("CustomerRecord.bin");
                rename("Tmp.bin","CustomerRecord.bin");
                break;
            }
            case 4:{
                int sid;
                fstream tmp;
                system("clear");
                file.open("CustomerRecord.bin", ios::in | ios::binary);
                tmp.open("Tmp.bin",ios::out | ios::binary);
                gotoy();
                int check = 0;
                cout<<"\t\t\t\t **************** Delete Form ***************"<<endl<<endl;
                cout<<"\t\t\t\t\t Enter ID you want to delete:";cin>>sid;
                cout<<"\t\t\t\t ********************************************"<<endl;
                while(file.read((char*)&cus,sizeof(cus))){
                    if(sid == cus.getID()){
                        system("clear");
                        gotoy();
                        check = 1;
                        cout<<"\t\t\t\t\t  Delete successfully!"<<endl;
                    }else{
                        tmp.write((char*)&cus,sizeof(cus));
                    }
                }
                if(check == 0){
                    
                    cout<<"\t\t\t\t\tID not found, please try again!"<<endl;
                    pause;
                    pause;
                    system("clear");
                }
                file.close();
                tmp.close();
                remove("CustomerRecord.bin");
                rename("Tmp.bin","CustomerRecord.bin");
                break;
            }  
        }
        pause;
    }while(op<5);
}