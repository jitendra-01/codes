#include<iostream>
#include<stdio.h>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <iomanip>
using namespace std;
ofstream fout;
ifstream fin;
class Color{
	private:
         int color;
         HANDLE consoleHandle;
  	public:
        Color(int desiredColor)
		{
            consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
            color = desiredColor;
        }
        friend ostream& operator<<(ostream& , Color );
};
ostream& operator<<(ostream& ss, Color obj)
{
    SetConsoleTextAttribute(obj.consoleHandle, obj.color);
    return ss;
}
class ClothingCentre{
    private:
    char size[50];
    char name[50],color[50];
    int code,q;
    float price;
    public:
    void showAll();
    void addClothes();
    void modify();
    void MainMenu();
    void CheckClothing();
    void buyingClothes(int ,int);
};
void ClothingCentre::addClothes(){
    fstream file;
        cout<<"\n               Enter the details of the clothing you want to add:\n";
        cout<<"\n               Code: ";
        cin>>code;
        cout<<"\n               Name: ";
        cin>>name;
        cout<<"\n               Size(S/M/L/XL/XXL): ";
        cin>>size;
        cout<<"\n               Color: ";
        cin>>color;
        cout<<"\n               Quantity: ";
        cin>>q;
        cout<<"\n               Price(in Rupees): ";
        cin>>price;
        cout<<"\n               Clothing Added Successfully!";
        file.open("Clothdata.txt",ios::app|ios::out);
        file << " " << code << " " << name << " " << size << " " << color<< " " << q << " " << price << "\n";
        file.close();
}
void ClothingCentre::showAll(){
    fstream file;
        cout<<"\n                                                   ALL CLOTHES\n";
        cout<<"                                                   ===========";
        cout<<"\n\n";
    file.open("Clothdata.txt", ios::in);
        file >> code >> name >> size >> color >> q >> price;
        while (!file.eof())
        {
            cout << "\n\n\t\t\tCode: " << code << endl;
            cout << "\t\t\tName: " << name << "\n";
            cout << "\t\t\tSize.: " << size << "\n";
            cout << "\t\t\tColor: " << color << "\n";
            cout << "\t\t\tQuantity: " << q << "\n";
            cout << "\t\t\tPrice: " << price << "\n";
            file >> code >> name >> size >> color >> q >> price;
        }
        file.close();
}
void ClothingCentre::modify(){
    fstream file, file1;
    int count = 0;
    int code1;
    string name1,color1,size1;
    int q1,price1;
    cout << "\n\n\t\t\t\tUpdate Book Record";
    file1.open("Clothdata1.txt",ios::app | ios::out);
    file.open("Clothdata.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        cout << "\n\nCloth ID : ";
        int m=10;
        cin >> code1;
        file >>code>>name>>size>>color>>q>>price;
        while (!file.eof()) {
            if (code1==code&&m==10){
            cout << "\n\n\t\t\tCode: " << code << endl;
            cout << "\t\t\tName: " << name << "\n";
            cout << "\t\t\tSize.: " << size << "\n";
            cout << "\t\t\tColor: " << color << "\n";
            cout << "\t\t\tQuantity: " << q << "\n";
            cout << "\t\t\tPrice: " << price << "\n";
            cout << "\t\t\t\t"<< "Update Cloth Record";
    cout<<"\n               Code: ";
    cin>>code1;
    cout<<"\n               Name: ";
    cin>>name1;
    cout<<"\n               Size(S/M/L/XL/XXL): ";
    cin>>size1;
    cout<<"\n               Color: ";
    cin>>color1;
    cout<<"\n               Quantity: ";
    cin>>q1;
    cout<<"\n               Price(each in rupees): ";
    cin>>price1;
    cout<<"\n               ClothData Updated Successfully!";
    file1 << " " << code1 << " "<< name1<< " "<<size1<<" "<<color1 << " " <<q1<<" "<<price1<< "\n\n";
                count++;
                m=5;
            }
    else {
    file1 << " " << code << " "<< name<< " "<<size<<" "<<color << " " <<q<<" "<<price<< "\n\n";
    }
       file >> code >> name >> size >> color >> q >> price;
        }
        if (count == 0)
            cout << "\n\nCloth ID" << " Not Found...";
    }
    cout << endl;
    file.close();
    file1.close();
    remove("Clothdata.txt");
    rename("Clothdata1.txt","Clothdata.txt");
}
void ClothingCentre:: CheckClothing(){
fstream file;
    int count=0;
    int code1;
    cout << "\n\n\t\t\t\tCheck "<< "Particular Clothing";
    file.open("Clothdata.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        cout << "\n\nBook ID : ";
        cin >> code1;
        file >> code >> name >> size >> color >> q >> price;
        while (!file.eof()) {
                if (code1 == code) {
             cout << "\n\n\t\t\tCode: " << code << endl;
            cout << "\t\t\tName: " << name << "\n";
            cout << "\t\t\tSize.: " << size << "\n";
            cout << "\t\t\tColor: " << color << "\n";
            cout << "\t\t\tQuantity: " << q << "\n";
            cout << "\t\t\tPrice: " << price << "\n";
                count++;
                break;
            }
           file >> code >> name >> size >> color >> q >> price;
        }
        file.close();
        if (count == 0)
            cout << "\n\nCloth ID Not"<< " Found...";
    }
}
void ClothingCentre:: MainMenu(){
       int c;
       do{
        cout<<"\n                                   ===========================";
        cout<<"\n                                   WELCOME TO CLOTHING STORE\n";
        cout<<"                                   ===========================\n";
        cout<<"\n\n";
        cout<<"                 1.View All Clothes In The Store\n\n";
        cout<<"                 2.Add Clothing\n\n";
        cout<<"                 3.Edit Clothing\n\n";
        cout<<"                 4.Find Clothing\n\n";
        cout<<"                 5.Exit\n\n";
        cout<<"                 Please Enter Required Option: ";
        cin>>c;
        switch (c){
        case 1:
        showAll();
        break;
        case 2:
        addClothes();
        break;
        case 3:
        modify();
        break;
        case 4:
        CheckClothing();
        case 5:
        break;
        default:
            break;
        }}while(c!=5);
}
void ClothingCentre::buyingClothes(int a,int b){
   fstream file, file1;
    int count = 0;
    file1.open("Clothdata1.txt",ios::app | ios::out);
    file.open("Clothdata.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        int m=10;
        file >>code>>name>>size>>color>>q>>price;
        while (!file.eof()) {
        fstream f;
        f.open("Bill.txt",ios::app|ios::out);
        f << " " << name << " " << price << " " << b<< "\n";
        f.close();

            if (a==code&&m==10){
    file1 << " " << a << " "<< name<< " "<<size<<" "<<color << " " <<q-b<<" "<<price<< "\n\n";
                count++;
                m=5;
            }
    else {
    file1 << " " << code << " "<< name<< " "<<size<<" "<<color << " " <<q<<" "<<price<< "\n\n";
    }
       file >> code >> name >> size >> color >> q >> price;
        }
        if (count == 0)
            cout << "\n\nCloth ID" << " Not Found...";
    }
    cout << endl;
    file.close();
    file1.close();
    remove("Clothdata.txt");
    rename("Clothdata1.txt","Clothdata.txt");
}
class bookShop {
private:
int bookId;
string title;
float price;
int quantity;
public:
    void MainMenu();
    void addBookdata();
    void showBooksdata();
    void checkAbook();
    void updateBookdata();
    void buyingBooks(int,int);
};
void bookShop::MainMenu(){
 int c;
 do{
    cout<<"\n                                   WELCOME TO BOOKS STORE\n";
    cout<<"                                   ==============================\n";
    cout<<"\n\n";
    cout<<"                 1.View All Books In The Store\n\n";
    cout<<"                 2.Add Books\n\n";
    cout<<"                 3.Edit Books\n\n";
    cout<<"                 4.Find Books\n\n";
    cout<<"                 5.Exit\n\n";
    cout<<"                 Please Enter Required Option: ";
    cin>>c;
    switch (c){
    case 1:
    showBooksdata();
    break;
    case 2:
    addBookdata();
    break;
    case 3:
    updateBookdata();
    break;
    case 4:
    checkAbook();
    break;
    case 5:
    break;
    default:
    break;
    }}while(c!=5);
}
void bookShop::addBookdata(){
    fstream file;
    cout<<"\n               Enter the details of the book you want to add:\n";
    cout<<"\n               BookId: ";
    cin>>bookId;
    cout<<"\n               Title: ";
    cin>>title;
    cout<<"\n               Price(each in rupees): ";
    cin>>price;
    cout<<"\n               Quantity: ";
    cin>>quantity;
    cout<<"\n               BookData Added Successfully!";
    file.open("bookstore.txt",ios::out | ios::app);
    file << " " << bookId << " "<<title << " " << price<< " " << quantity << "\n";
    file.close();
}
void bookShop::showBooksdata(){
    fstream file;
    cout<<"\n                                                   ALL BOOKS\n";
    cout<<"                                                   ===========";
    cout<<"\n\n";
    file.open("bookstore.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        //cout << "\n\n\nBook ID\t\tBook"<< "\t\tPrice\t\tNo. of ""Books\n\n";
        file >> bookId >> title;
        file >> price >> quantity;
        while (!file.eof()) {
        cout << "\n\n\t\t\tBookId: " << bookId << endl;
        cout << "\t\t\tTitle: " << title << "\n";
        cout << "\t\t\tQuantity: " << quantity << "\n";
        cout << "\t\t\tPrice: " << price << "\n";
            file >> bookId >> title;
            file >> price >> quantity;
        }
        file.close();
    }
}
void bookShop::checkAbook()
{
    system("cls");
    fstream file;
    int count=0;
    int b_idd;
    cout << "\n\n\t\t\t\tCheck "<< "Particular Book";
    file.open("bookstore.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        cout << "\n\nBook ID : ";
        cin >> b_idd;
        file >> bookId >> title;
        file >> price >> quantity;
        while (!file.eof()) {
                if (b_idd == bookId) {
                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Check Particular Book";
                cout << "\n\nBook ID : "<< bookId;
                cout << "\nName : "<< title;
                cout << "\nPrice : "<< price;
                cout << "\nNo. of Books : "<< quantity<<endl;
                count++;
                break;
            }
            file >> bookId >> title;
            file >> price >> quantity;
        }
        file.close();
        if (count == 0)
            cout << "\n\nBook ID Not"<< " Found...";
    }
}
void bookShop::updateBookdata(){
    system("cls");
    fstream file, file1;
    int count = 0;
    int id1;
    string title1;
    int quantity1,price1;
    cout << "\n\n\t\t\t\tUpdate Book Record";
    file1.open("book1.txt",ios::app | ios::out);
    file.open("bookstore.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        cout << "\n\nBook ID : ";
        int m=10;
        cin >> id1;
        file >> bookId >> title;
        file >> price >> quantity;
        while (!file.eof()) {
            if (id1==bookId&&m==10){
                cout << "\n\nBook ID : "<< bookId;
                cout << "\nName : "<< title;
                cout << "\nPrice : "<< price;
                cout << "\nNo. of Books : "<< quantity<<endl;
                cout << "\t\t\t\t"<< "Update Book Record";
    cout<<"\n               BookId: ";
    cin>>id1;
    cout<<"\n               Title: ";
    cin>>title1;
    cout<<"\n               Price(each in rupees): ";
    cin>>price1;
    cout<<"\n               Quantity: ";
    cin>>quantity1;
    cout<<"\n               BookData Updated Successfully!";
    file1 << " " << id1 << " "<< title1<< " "<< price1 << " " <<quantity1<< "\n\n";
                count++;
                m=5;
            }
    else {
    file1 << " " << bookId<< " " << title<< " " << price<< " " << quantity<< "\n\n";
    }
            file >> bookId >> title;
            file >> price >> quantity;
        }
        if (count == 0)
            cout << "\n\nBook ID" << " Not Found...";
    }
    cout << endl;
    file.close();
    file1.close();
    remove("bookstore.txt");
    rename("book1.txt","bookstore.txt");

}
void bookShop::buyingBooks(int a,int b){
 fstream file, file1;
    int count = 0;
    file1.open("book1.txt",ios::app | ios::out);
    file.open("bookstore.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        int m=10;
         file >> bookId >> title;
         file >> price >> quantity;
        while (!file.eof()) {
            if (a==bookId&&m==10){
        fstream f;
        f.open("Bill.txt",ios::app|ios::out);
        f << " " << title << " " << price << " " << b<< "\n";
        f.close();

    file1 << " " << bookId<< " " << title<< " " << price<< " " << quantity-b<< "\n\n";
                count++;
                m=5;
            }
    else {
    file1 << " " << bookId<< " " << title<< " " << price<< " " << quantity<< "\n\n";
    }
       file >> bookId >> title;
       file >> price >> quantity;
        }
        if (count == 0)
            cout << "\n\nBook ID" << " Not Found...";
    }
    cout << endl;
    file.close();
    file1.close();
    remove("bookstore.txt");
    rename("book1.txt","bookstore.txt");
}
class GroceryShop {
private:
int groceryId;
string name;
float price;
int quantity;
public:
    void MainMenu();
    void addGroceries();
    void showGroceries();
    void checkAgrocery();
    void updateGrocerydata();
    void buyingGroceries(int ,int);
};
void GroceryShop::MainMenu(){
 int c;
 do{
    cout<<"\n                                   WELCOME TO GROCERY STORE\n";
    cout<<"                                   ==============================\n";
    cout<<"\n\n";
    cout<<"                 1.View All Groceries In The Store\n\n";
    cout<<"                 2.Add Groceries\n\n";
    cout<<"                 3.Edit Groceries\n\n";
    cout<<"                 4.Find Groceries\n\n";
    cout<<"                 5.Exit\n\n";
    cout<<"                 Please Enter Required Option: ";
    cin>>c;
    switch (c){
    case 1:
    showGroceries();
    break;
    case 2:
    addGroceries();
    break;
    case 3:
    updateGrocerydata();
    break;
    case 4:
    checkAgrocery();
    break;
    case 5:
    cout<<"\nExisting\n";
    break;
    }}while(c!=5);
}
void GroceryShop::addGroceries(){
    fstream file;
    cout<<"\n               Enter the details of the grocery you want to add:\n";
    cout<<"\n               GroceryId: ";
    cin>>groceryId;
    cout<<"\n               Name: ";
    cin>>name;
    cout<<"\n               Price(each in rupees): ";
    cin>>price;
    cout<<"\n               Quantity: ";
    cin>>quantity;
    cout<<"\n               GroceryData Added Successfully!";
    file.open("groceries.txt",ios::out | ios::app);
    file << " " << groceryId << " "<<name << " " << price<< " " << quantity << "\n";
    file.close();
}
void GroceryShop::showGroceries(){
    fstream file;
    cout<<"\n                                                   ALL GROCERIES\n";
    cout<<"                                                   ===========";
    cout<<"\n\n";
    file.open("groceries.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        file >> groceryId >> name;
        file >> price >> quantity;
        while (!file.eof()) {
        cout << "\n\n\t\t\tGroceryId: " << groceryId << endl;
        cout << "\t\t\tTitle: " << name << "\n";
        cout << "\t\t\tQuantity: " << quantity << "\n";
        cout << "\t\t\tPrice: " << price << "\n";
            file >> groceryId >> name;
            file >> price >> quantity;
        }
        file.close();
    }
}
void GroceryShop::checkAgrocery()
{
    fstream file;
    int count=0;
    int b_idd;
    cout << "\n\n\t\t\t\tCheck "<< "Particular Book";
    file.open("groceries.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        cout << "\n\nGrocery ID : ";
        cin >> b_idd;
        file >> groceryId >> name;
        file >> price >> quantity;
        while (!file.eof()) {
                if (b_idd == groceryId) {
                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Check Particular Grocery";
                cout << "\n\nGrocery ID : "<< groceryId;
                cout << "\nName : "<< name;
                cout << "\nPrice : "<< price;
                cout << "\nNo. of Groceries : "<< quantity<<endl;
                count++;
                break;
            }
            file >> groceryId >> name;
            file >> price >> quantity;
        }
        file.close();
        if (count == 0)
            cout << "\n\nGrocery ID Not"<< " Found...";
    }
}
void GroceryShop::updateGrocerydata(){
    fstream file, file1;
    int count = 0;
    int id1;
    string name1;
    int quantity1,price1;
    cout << "\n\n\t\t\t\tUpdate Grocery Record";
    file1.open("groceries1.txt",ios::app | ios::out);
    file.open("groceries.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        cout << "\n\nGrocery ID : ";
        int m=10;
        cin >> id1;
        file >> groceryId >> name;
        file >> price >> quantity;
        while (!file.eof()) {
            if (id1==groceryId&&m==10){
                cout << "\n\nGrocery ID : "<< groceryId;
                cout << "\nName : "<< name;
                cout << "\nPrice : "<< price;
                cout << "\nNo. of Groceries : "<< quantity<<endl;
                cout << "\t\t\t\t"<< "Update Grocery Record";
    cout<<"\n               GroceryId: ";
    cin>>id1;
    cout<<"\n               Name: ";
    cin>>name1;
    cout<<"\n               Price(each in rupees): ";
    cin>>price1;
    cout<<"\n               Quantity: ";
    cin>>quantity1;
    cout<<"\n               GroceryData Updated Successfully!";
    file1 << " " << id1 << " "<< name1<< " "<< price1 << " " <<quantity1<< "\n\n";
                count++;
                m=5;
            }
    else {
    file1 << " " << groceryId<< " " << name<< " " << price<< " " << quantity<< "\n\n";
    }
            file >> groceryId >> name;
            file >> price >> quantity;
        }
        if (count == 0)
            cout << "\n\nGrocery ID" << " Not Found...";
    }
    cout << endl;
    file.close();
    file1.close();
    remove("groceries.txt");
    rename("groceries1.txt","groceries.txt");

}
void GroceryShop::buyingGroceries(int a,int b){
fstream file, file1;
    int count = 0;
    file1.open("groceries1.txt",ios::app | ios::out);
    file.open("groceries.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        int m=10;
         file >> groceryId >> name;
         file >> price >> quantity;
        while (!file.eof()) {
            if (a==groceryId&&m==10){
        fstream f;
        f.open("Bill.txt",ios::app|ios::out);
        f << " " << name << " " << price << " " << b<< "\n";
        f.close();

    file1 << " " << groceryId<< " " << name<< " " << price<< " " << quantity-b<< "\n\n";
                count++;
                m=5;
            }
    else {
    file1 << " " << groceryId<< " " << name<< " " << price<< " " << quantity<< "\n\n";
    }
       file >> groceryId >> name;
       file >> price >> quantity;
        }
        if (count == 0)
            cout << "\n\nGrocery ID" << " Not Found...";
    }
    cout << endl;
    file.close();
    file1.close();
    remove("groceries.txt");
    rename("groceries1.txt","groceries.txt");
}
class ElectronicsShop {
private:
int itemId;
string name;
float price;
int quantity;
public:
    void MainMenu();
    void addItems();
    void showItems();
    void checkAItem();
    void updateItemdata();
    void buyingElectronics(int,int);
};
void ElectronicsShop::MainMenu(){
    int c;
 do{
    cout<<"\n                                   WELCOME TO GROCERY STORE\n";
    cout<<"                                   ==============================\n";
    cout<<"\n\n";
    cout<<"                 1.View All Items In The Store\n\n";
    cout<<"                 2.Add Items\n\n";
    cout<<"                 3.Edit Items\n\n";
    cout<<"                 4.Find Items\n\n";
    cout<<"                 5.Exit\n\n";
    cout<<"                 Please Enter Required Option: ";
    cin>>c;
    switch (c){
    case 1:
    showItems();
    break;
    case 2:
    addItems();
    break;
    case 3:
    updateItemdata();
    break;
    case 4:
    checkAItem();
    break;
    case 5:
    cout<<"\nExiting\n";
    break;
    }}while(c!=5);
}
void ElectronicsShop::addItems(){
    fstream file;
    cout<<"\n               Enter the details of the items you want to add:\n";
    cout<<"\n               ItemId: ";
    cin>>itemId;
    cout<<"\n               Name: ";
    cin>>name;
    cout<<"\n               Price(each in rupees): ";
    cin>>price;
    cout<<"\n               Quantity: ";
    cin>>quantity;
    cout<<"\n               Data Added Successfully!";
    file.open("electronic.txt",ios::out | ios::app);
    file << " " << itemId << " "<<name << " " << price<< " " << quantity << "\n";
    file.close();
}
void ElectronicsShop::showItems(){
    fstream file;
    cout<<"\n                                                   ALL ITEMS\n";
    cout<<"                                                   ===========";
    cout<<"\n\n";
    file.open("electronic.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        file >> itemId >> name;
        file >> price >> quantity;
        while (!file.eof()) {
        cout << "\n\n\t\t\tItemId: " << itemId << endl;
        cout << "\t\t\tName: " << name << "\n";
        cout << "\t\t\tQuantity: " << quantity << "\n";
        cout << "\t\t\tPrice: " << price << "\n";
            file >> itemId >> name;
            file >> price >> quantity;
        }
        file.close();
    }
}
void ElectronicsShop::checkAItem()
{
    fstream file;
    int count=0;
    int b_idd;
    cout << "\n\n\t\t\t\tCheck "<< "Particular Item";
    file.open("electronic.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        cout << "\n\nItem ID : ";
        cin >> b_idd;
        file >> itemId >> name;
        file >> price >> quantity;
        while (!file.eof()) {
                if (b_idd == itemId) {
                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Check Particular Item";
                cout << "\n\nItem ID : "<< itemId;
                cout << "\nName : "<< name;
                cout << "\nPrice : "<< price;
                cout << "\nNo. of Items : "<< quantity<<endl;
                count++;
                break;
            }
            file >> itemId >> name;
            file >> price >> quantity;
        }
        file.close();
        if (count == 0)
            cout << "\n\nItem ID Not"<< " Found...";
    }
}
void ElectronicsShop::updateItemdata(){
    fstream file, file1;
    int count = 0;
    int id1;
    string name1;
    int quantity1,price1;
    cout << "\n\n\t\t\t\tUpdate Item Record";
    file1.open("electronics1.txt",ios::app | ios::out);
    file.open("electronic.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        cout << "\n\nItem ID : ";
        int m=10;
        cin >> id1;
        file >> itemId >> name;
        file >> price >> quantity;
        while (!file.eof()) {
            if (id1==itemId&&m==10){
                cout << "\n\nGrocery ID : "<< itemId;
                cout << "\nName : "<< name;
                cout << "\nPrice : "<< price;
                cout << "\nNo. of Electronics : "<< quantity<<endl;
                cout << "\t\t\t\t"<< "Update Electronics Record";
    cout<<"\n               ItemId: ";
    cin>>id1;
    cout<<"\n               Name: ";
    cin>>name1;
    cout<<"\n               Price(each in rupees): ";
    cin>>price1;
    cout<<"\n               Quantity: ";
    cin>>quantity1;
    cout<<"\n               Data Updated Successfully!";
    file1 << " " << id1 << " "<< name1<< " "<< price1 << " " <<quantity1<< "\n\n";
                count++;
                m=5;
            }
    else {
    file1 << " " << itemId<< " " << name<< " " << price<< " " << quantity<< "\n\n";
    }
            file >> itemId >> name;
            file >> price >> quantity;
        }
        if (count == 0)
            cout << "\n\nItem ID" << " Not Found...";
    }
    cout << endl;
    file.close();
    file1.close();
    remove("electronic.txt");
    rename("electronics1.txt","electronic.txt");

}
void ElectronicsShop::buyingElectronics(int a,int b){
 fstream file, file1;
    int count = 0;
    file1.open("electronics1.txt",ios::app | ios::out);
    file.open("electronic.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        int m=10;
         file >> itemId >> name;
         file >> price >> quantity;
        while (!file.eof()) {
            if (a==itemId&&m==10){
        fstream f;
        f.open("Bill.txt",ios::app|ios::out);
        f << " " << name << " " << price << " " << b<< "\n";
        f.close();

    file1 << " " << itemId<< " " << name<< " " << price<< " " << quantity-b<< "\n\n";
                count++;
                m=5;
            }
    else {
    file1 << " " << itemId<< " " << name<< " " << price<< " " << quantity<< "\n\n";
    }
       file >> itemId >> name;
       file >> price >> quantity;
        }
        if (count == 0)
            cout << "\n\nItem ID" << " Not Found...";
    }
    cout << endl;
    file.close();
    file1.close();
    remove("electronic.txt");
    rename("electronics1.txt","electronic.txt");
}
class abs{
	public:
		virtual void menu()=0;
};
class ShoppingStore:public ClothingCentre,public bookShop,public GroceryShop,public ElectronicsShop,abs{
public:
void menu();
void adminstrator();
void buyer();
friend void BillGeneration();
};
void ShoppingStore::menu(){
    Menubar:
    int choice;
    cout<<Color(10)<<"\t\t\t\t***********************************************\n";
    cout<<"\t\t\t\t                                               \n";
    cout<<"\t\t\t\t             MALL MAIN MENU                    \n";
    cout<<"\t\t\t\t                                               \n";
    cout<<"\t\t\t\t***********************************************\n"<<Color(7);
    do{
        string password="";
        char ch;
    cout<<Color(1)<<"\t\t\t\tEnter your choice\n\t\t\t\t1 adminstrator\n\t\t\t\t2 buyer\n\t\t\t\t3 exit\n"<<Color(7);
    cout<<"\t\t\t\tEnter your choice: ";
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"\n\t\t\tPlease login by entering the password: ";
        ch=_getch();
        while(ch!=13){
        	password.push_back(ch);
        	cout<<"*";
        	ch=_getch();
		}
        if(password=="1234"){
        adminstrator();
        }
        else{
            cout<<Color(12)<<"\t\t\t\nInvalild Password\n"<<Color(7);
        }
        break;
        case 2:
        buyer();
        break;
        default:
        break;
}}while(choice!=3);
}
void ShoppingStore::adminstrator(){
int choice;
cout<<Color(10)<<"\n\n\t\t\t******************************\n";
cout<<"\t\t\t       ADMINSTRATOR MENU\n";
cout<<"\t\t\t******************************\n"<<Color(7);
do{
cout<<"\t\t\t\tEnter your choice\n\t\t\t\t1 Clothing Store\n\t\t\t\t2 Book Store\n\t\t\t\t3 Grocery Store\n\t\t\t\t4 Electronics Store\n\t\t\t\t5 Exit\n";
cout<<"\t\t\tEnter your choice: ";
cin>>choice;
switch(choice){
    case 1:
    ClothingCentre::MainMenu();
    break;
    case 2:
    bookShop::MainMenu();
    break;
    case 3:
    GroceryShop::MainMenu();
    break;
    case 4:
    ElectronicsShop::MainMenu();
    break;
    case 5:
    cout<<"\nExisting\n";
    break;
}}while(choice!=5);
}

void BillGeneration(){
         fstream f;
         f.open("Bill.txt",ios::app|ios::in);
         string name;
         int q,p;
         int amount=0;
         system("cls");
         cout<<Color(10)<<"***************************************************************************"<<endl;
         cout<<"S.No.               Product Name               Price               Quantity"<<endl;
         cout<<"***************************************************************************"<<Color(7)<<endl;
         if (!f){
         cout << "\n\nFile Opening Error!";
         }
         else {
        f >> name>> q >> p;
        int i=1;
        while (!f.eof()) {
        amount+=p*q;
        cout<<setw(2)<<i<<"\t"<<setw(24)<<name<<"\t"<<setw(12)<<q<<"\t"<<setw(19)<<p<<endl;
        f >> name>> q >> p;
        i++;
        }
        f.close();
       }
       cout<<"***************************************************************************"<<endl;
       cout<<"Total Amount"<<setw(63)<<amount<<endl;
       cout<<"***************************************************************************"<<endl;
}

void ShoppingStore::buyer(){
int choice;
cout<<"\t\t\t*Buyer Menu*\n";
do{
cout<<"\t\t\t\tEnter your choice\n\t\t\t\t1 Clothing Store\n\t\t\t\t2 BookStore\n\t\t\t\t3 Grocery Store\n\t\t\t\t4 Electronics Shop\n\t\t\t\t5 Exit";
cout<<"\t\t\t";
cin>>choice;
switch(choice){
    case 1:
    ClothingCentre::showAll();
    int c1;
    do{
    cout<<"\n\t\t\tDo you want to buy\n\t\t\tPress 1 for yes and 2 for no\n";
    cin>>c1;
    switch(c1){
    case 1:
    int a,b;
    cout<<"\t\t\t\tEnter the item code: ";
    cin>>a;
    cout<<"\t\t\t\tEnter the item quantity: ";
    cin>>b;
    ClothingCentre::buyingClothes(a,b);
    break;
    case 2:
    cout<<"\t\t\tExiting\n";
    break;
    }}while(c1!=2);
    break;
    case 2:
    bookShop::showBooksdata();
    int c2;
    do{
    cout<<"\t\t\tDo you want to buy\n\t\t\tPress 1 for yes and 2 for no\n";
    cin>>c2;
    switch(c2){
    case 1:
    int a,b;
    cout<<"\t\t\t\tEnter the book code: ";
    cin>>a;
    cout<<"\t\t\t\tEnter the book quantity: ";
    cin>>b;
    bookShop::buyingBooks(a,b);
    break;
    case 2:
    cout<<"\t\t\tExiting\n";
    break;
    }}while(c2!=2);
    break;
    case 3:
    GroceryShop::showGroceries();
    int c3;
    do{
    cout<<"\t\t\tDo you want to buy\n\t\t\tPress 1 for yes and 2 for no\n";
    cin>>c3;
    switch(c3){
    case 1:
    int a,b;
    cout<<"\t\t\t\tEnter the grocery code: ";
    cin>>a;
    cout<<"\t\t\t\tEnter the grocery quantity: ";
    cin>>b;
    GroceryShop::buyingGroceries(a,b);
    break;
    case 2:
    cout<<"\t\t\tExiting\n";
    break;
    }}while(c3!=2);
    break;
    case 4:
    ElectronicsShop::showItems();
    int c4;
    do{
    cout<<"\t\t\tDo you want to buy\n\t\t\tPress 1 for yes and 2 for no\n";
    cin>>c4;
    switch(c4){
    case 1:
    int a,b;
    cout<<"\t\t\t\tEnter the item code: ";
    cin>>a;
    cout<<"\t\t\t\tEnter the item quantity: ";
    cin>>b;
    ElectronicsShop::buyingElectronics(a,b);
    break;
    case 2:
    cout<<"\t\t\tExiting\n";
    break;
    }}while(c4!=2);
    break;
    case 5:
    cout<<"\t\t\tExiting\n";
    break;
}
}while(choice!=5);

BillGeneration();
}
int main(){
    ShoppingStore s;
    s.menu();
}
