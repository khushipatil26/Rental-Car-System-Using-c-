#include <iostream>
#include <fstream>
#include <limits>
#include <unistd.h>
#include <iomanip>
#include <ctime>
using namespace std;
class Customer
{
protected:
    string Customer_Name;
    int car_model;
    string car_Number;
};
class Rent : public Customer
{
    private:
        int numberofDays;
        int Rent_Fee;
        char str[200];
    public:
        Rent();
        void Welcome();
        void fileReader(char carFile[20]);
        void data();
        void invoiceAmount();
        void invoiceRecord();
};
Rent::Rent(){
    numberofDays = 0;
    Rent_Fee = 0;
}

void Rent::Welcome(){
    ifstream inputFile("welcome.txt");
    if(inputFile){
       cout << "cannot open input file.\n";
       }
       char str[1000];
       while(inputFile){
            inputFile.getline(str, 1000);
            if(inputFile)
                cout << str << endl;
       }
       inputFile.close();
       sleep(1);
       cout<<" loading up files......"<<endl;
       sleep(1);
       system ("CLS");
}
void Rent::fileReader(char carFile[20]){
    ifstream inputFile;
    inputFile.open(carFile);
    if(!inputFile){
            cout<<"Error in printing file. File not found!" << endl;
    }
    while(inputFile){
            inputFile.getline(str, 200);
            if(inputFile)
                cout << str << endl;
            }
}
void Rent::data(){
    cout << "\n\n\t\t\t\tplease Enter your Name: ";
    cin >> Customer_Name;
    cout << endl;
    do{
        cout << "\t\t\t\t_________________________________"<<endl;
        cout << "\t\t\t\tChoose a car from the options below. \n";
        cout << "\t\t\\t\tChoose a number corresponding to the car you want to select:" <<endl;
        cout << "\t\t\t\t_____________________________________"<<endl;
        cout << "\t\t\t\t1. Toyota 2021. "<<endl;
        cout << "\t\t\t\t2. Hundai 2019. "<<endl;
        cout << "\t\t\t\t3. Ford 2020. "<<endl;
        cout << endl;
        cout << "\t\t\t\t______________________________________"<<endl;
        cout << "\n\t\t\t\tChoose: ";
        if (!(cin >> car_model)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number corresponding to the car model." << endl;
                } else if (car_model < 1 || car_model > 3) {
                    cout << "Please choose a valid option (1, 2, or 3)." << endl;
                    } else {
                        validInput = true;
                    }



        switch(car_model){
            case 1:
                system("CLS");
                cout<<"You have choosed Toyota model 2021" << endl;
                fileReader("Toyota.txt");
                sleep(2);
                break;
            case 2:
                system("CLS");
                cout<<"you have choosed Hyundai model 2019"<<endl;
                fileReader("Hyundai.txt");
                sleep(2);
                break;
            case 3:
                system("CLS");
                cout<<"you have choosed ford model 2020"<<endl;
                fileReader("ford.txt");
                sleep(2);
                break;
            default:
                cout<<"Invalid car Model. please try again"<<endl;

        }

    }while(car_model >= 1 && car_model <= 3);

     cout<<"_______________________________________________"<<endl;
     cout<<"please provide following information:"<<endl;

     cout<<"please select a car no. :";
     cin>>car_Number;
     cout<<"number of days you wish to rent the car:";
     cin >> numberofDays;
     cout<<endl;
}
void Rent::invoiceAmount(){
    sleep(1);
    system("CLS");
    cout<<"Calculating rent. please wait....."<<endl;
    sleep(2);
    if(car_model == 1)
        Rent_Fee = numberofDays*150;
    if(car_model == 2)
        Rent_Fee = numberofDays*160;
    if(car_model == 3)
        Rent_Fee = numberofDays*175;

}
void Rent::invoiceRecord(){
    time_t now  = time(0);
    char *date = ctime(&now);
    cout<< setw(80) << date << endl;
    cout << "\n\t\t                  CAR RENTAL - CUSTOMER INVOICE              "<<endl;
    cout<<"\t\t ________________________________________________________________"<<endl;
    cout<<"\t\t _________________________________________________________________"<<endl;
    cout<<"\t\t   |INVOICE NO.  "<<"        |"<< setw(10) <<"01001"<<"|"<<endl;
    cout<<"\t\t   | customer name "<<"      | "<<setw(10)  <<Customer_Name<<" |"<<endl;
    cout<<"\t\t   | car model    "<<"       | "<<setw(10)  <<car_model<<" |"<<endl;
    cout<<"\t\t   | car No.   "<<"          | "<<setw(10)  <<car_Number<<" |"<<endl;
    cout<<"\t\t   | Number of days  "<<"    | "<<setw(10)  <<numberofDays<<" |"<<endl;
    cout<<"\t\t   | Rental Amount   "<<"    | "<<setw(10)  <<Rent_Fee<<" |"<<endl;
    cout<<"\t\t   | Caution Money   "<<"    | "<<setw(10)  <<"0"<<" |"<<endl;
    cout<<"\t\t   | Advanced   "<<"         | "<<setw(10)  <<"0"<<" |"<<endl;
    cout<<"\t\t   |___________________________________________________|"<<endl;
    cout<<"\t\t   | Total Rental Amount  "<<"      |"<<setw(6)<<"R"<<Rent_Fee<<" |"<<endl;
    cout<<"\t\t   ____________________________________________________"<<endl;
    cout<<"\t\t   ____________________________________________________"<<endl;
    cout<<"\t\t   NOTE: This is a computer generated invoce. "<<endl;
    cout<<"\t\t         It does notrequire an authorized signature."<<endl;
    cout<<"\t\t    ................................................."<<endl;
    cout<<"\t\t    you are advised to pay up the amount before due data."<<endl;
    cout<<"\t\t    otherwise penalty fee will be applied"<<endl;

    system("PAUSE");
    system("CLS");
    fileReader("thanks.txt");


}
int main(){
    Rent rent;
    rent.Welcome();
    rent.data();
    rent.invoiceAmount();
    rent.invoiceRecord();
    return 0;


}


