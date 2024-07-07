#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;

class Bill{

    private:
    string Item;
    int Rate, Quantity;

    public:
    Bill():Item(""), Rate(0), Quantity(0){};


    void setItem(string item){

        Item = item;
    }
    void setRate(int rate){

        Rate = rate;
    }
    void setQuant(int quantity){

        Quantity = quantity;
    }

    string getItem(){

        return Item;
    }
    int getRate(){

        return Rate;
    }
    int getQuant(){

        return Quantity;
    }
};


void addItem(Bill b){

    bool close = false;

    while(!close){

        int choice;
        cout<<"\t1) Add."<<endl;
        cout<<"\t2) Close."<<endl;
        cout<<"\t3) Enter Choice : ";
        cin >> choice;

        if(choice == 1){

            string item;
            int rate, quant;

            cout<<"\tEnter Item Name : ";
            cin >> item;
            b.setItem(item);

            cout<<"\tEnter Item Rate : ";
            cin >>rate;
            b.setRate(rate);

            cout<<"\tEnter Item Quantity : ";
            cin >> quant;
            b.setQuant(quant);

            ofstream out("C:/Users/priya/Documents/SBS/bill.txt", ios::app);

            if(!out){

                cout<<"\tError : File can't open!"<<endl;
            }
            else{

                out<<"\t"<<b.getItem()<<" : "<<b.getRate()<<" : "<<b.getQuant()<<endl<<endl;
            }
            out.close();
            cout<<"\tItem added successfully!"<<endl;
            Sleep(3000);
        }

        else if(choice == 2){
            system("cls");
            close = true;
            cout<<"\tBack to main menu!"<<endl;
            Sleep(3000);
        }
    }
}

void printBill(){

    system("cls");
    int count = 0;
    bool close = false;

    while(!close){

        system("cls");
        int choice;
        cout<<"\t1) Add Bill."<<endl;
        cout<<"\t2) Close Session."<<endl;
        cout<<"\t3) Enter Choice."<<endl;
        cin >> choice;

        if(choice == 1){

            string item;
            int quant;
            cout<<"\tEnter Item : ";
            cin >> item;
            cout<<"\tEnter Quantity : ";
            cin >> quant;

            ifstream in("C:/Users/priya/Documents/SBS/bill.txt");
            ofstream out("C:/Users/priya/Documents/SBS/bill.txt");

            string line;
            bool found = false;

            while(getline(in, line)){

                stringstream ss;
                ss << line;
                string itemName;
                int itemRate, itemQuant;
                char delimiter;
                ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;

                if(item == itemName){

                    found = true;
                    if(quant <= itemQuant){

                        int amount = itemRate * quant;
                        cout<<"\tItem  |  Rate  |  Quantity  |  Amount"<<endl;
                        cout<<"\t"<<itemName<<"\t "<<itemRate<<"\t "<<quant<<"\t "<<amount<<endl;
                        int newQuant = itemQuant - quant;
                        itemQuant = newQuant;
                        count += amount;

                        out<<"\t"<<itemName<<" : "<<itemRate<<" : "<<itemQuant<<endl<<endl;
                    }
                    else{
                        //if quantity not available
                        cout<<"\tSorry, "<<item<<" not available!"<<endl;
                    }
                }
                else{
                    // item not found
                    out<<line<<endl;

                }
                if(!found){

                    cout<<"\tItem Not Available!"<<endl;
                }
                out.close();
                in.close();
                remove("C:/Users/priya/Documents/SBS/bill.txt");
                rename("C:/Users/priya/Documents/SBS/bill temp.txt", "C:/Users/priya/Documents/SBS/bill.txt");

            }
            if(choice == 2){

                close = true;
                cout<<"\tCounting Total Bill"<<endl;
            }
            Sleep(3000);
        }   
        system("cls");
        cout<<endl<<endl;
        cout<<"\tTotal Bill ---------------------------- : "<<count<<endl<<endl;
        cout<<"\tThanks for Shopping!"<<endl;
    }
}

int main(){

    Bill b;
    bool exit = false;

    while(!exit){

        system("cls");
        int val;
        
        cout<<"\tWelcome to Supermarket Billing System"<<endl;
        cout<<"\t*************************************"<<endl;
        cout<<"\t\t1) Add an item."<<endl;
        cout<<"\t\t2) Print Bill."<<endl;
        cout<<"\t\t3) Exit."<<endl;
        cout<<"\t\t4) Enter choice : ";
        cin >> val;

        

        if(val == 1){
            system("cls");
            addItem(b);
            Sleep(3000);
        }
        else if(val == 2){
            system("cls");
            printBill();
            Sleep(3000);

        }
        else if(val == 3){

            system("cls");
            cout<<"Good Luck!"<<endl;
            Sleep(3000);
        }
    }
}