#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class MyPhoneBook
{
 string* names;
 string* phones;
 int phoneBookSize;
 int * findNameArray;
 int * findPhoneArray;

 public:
 MyPhoneBook(int);
 MyPhoneBook(const MyPhoneBook&);
 bool addEntry(string ,string);
 bool displayEntryAtIndex(int);
 void displayEntryAtIndices(int*);
 void displayAll();
 int* findByName(string);
 int* findByPhone(string);
 bool updateNameAt(string, int);
 bool updatePhoneAt(string, int);
 ~MyPhoneBook();
};
//Constructors
MyPhoneBook::MyPhoneBook(int phoneBookSize){
    this->phoneBookSize=phoneBookSize;
    names=new string[phoneBookSize];
    phones=new string[phoneBookSize];
    findNameArray=new int[phoneBookSize];
    findPhoneArray=new int[phoneBookSize];

    for(int i=0;i<phoneBookSize;i++){
        names[i]=" ";
        phones[i]=" ";
        }
}

MyPhoneBook::MyPhoneBook(const MyPhoneBook &phoneBook){
    phoneBookSize=phoneBook.phoneBookSize;
    names=new string[phoneBookSize];
    phones=new string[phoneBookSize];
    findNameArray=new int[phoneBookSize];
    findPhoneArray=new int[phoneBookSize];

    for(int i=0;i<phoneBookSize;i++){
        names[i]=phoneBook.names[i];
        phones[i]=phoneBook.phones[i];
    }
}

// Destructor
MyPhoneBook::~MyPhoneBook()
{
    delete [] names;
    delete [] phones;
    delete [] findNameArray;
    delete [] findPhoneArray;
    names = NULL;
    phones = NULL;
    findNameArray = NULL;
    findPhoneArray = NULL;    
}

// Add Entry
bool MyPhoneBook::addEntry(string name ,string phone){
    bool entryAddedSuccessfully;
    string allowedPhoneNumberCharacters="0123456789";
    bool isPhoneNumberValid;

    if(phone.length()==11){
        for(int i=0;i<phone.length();i++){
            if(allowedPhoneNumberCharacters.find(phone[i])!=string::npos){
                isPhoneNumberValid=true;
            }else{
                isPhoneNumberValid=false;
                break;
            }
    }
    }else{
        isPhoneNumberValid=false;
    }

    // This is one of the conditions that leads to entry insertion failure (Phone number being not valid)
    if(isPhoneNumberValid==false){
        cout<<"Phone number is not valid! Entry not added!"<<endl;
        return false;
    }
    //Then it will check if there is an available place in the phonebook
    for(int i=0;i<phoneBookSize;i++){
        if(names[i]==" "&&phones[i]==" "){
            names[i]=name;
            phones[i]=phone;
            entryAddedSuccessfully=true;
            break;
        }else{
            entryAddedSuccessfully=false;
            continue;    
        }
    }
    if(entryAddedSuccessfully==true && isPhoneNumberValid==true){
        return true;
    }
    else
    {
        cout<<"Attempt to add an entry failed!"<<endl;
        return false;
    }
}

// displayEntryAtIndex
bool MyPhoneBook::displayEntryAtIndex(int index){
    if(index>(phoneBookSize-1) || index<0){
        return false;
    }
    else{
        cout<<"Name : "<<names[index]<<endl;
        cout<<"Phone number : "<<phones[index]<<endl;
        return true;
    }
}

// findBy

// findByName
int * MyPhoneBook::findByName(string name){
    for(int i=0;i<phoneBookSize;i++){
        if(names[i].rfind(name,0)!=string::npos){
            findNameArray[i]=1;
        }else{
            findNameArray[i]=0;
        }
    }
    return findNameArray;

}

// findByPhone
int * MyPhoneBook::findByPhone(string phone){ 
    for(int i=0;i<phoneBookSize;i++){
        if(phones[i].rfind(phone,0)!=string::npos){
            findPhoneArray[i]=1;
        }else{
            findPhoneArray[i]=0;
        }
    }
    return findPhoneArray;

}

// Function to display all entries.
void MyPhoneBook::displayAll()

{
    
    for (int i = 0; i < phoneBookSize; i++)
    {
        // If conditon to skip blank entries
        if(names[i] == " " && phones[i] == " ")
        {
            continue;
        }
        else 
        {
            cout << setw(20) << left << names[i];
            cout << setw(10) << phones[i];
            cout << endl;
        }
        
    }
    
}

// Update name at index.
bool MyPhoneBook::updateNameAt(string name, int index)
{
    bool indexIsValid = false;

    if (index < phoneBookSize && index >= 0)
    {
        indexIsValid = true;
    }
    
    if (indexIsValid)
    {
        names[index] = name;
        return true; 
    }
    else 
    {
        return false;
    }

}

// Update phone at index.
bool MyPhoneBook::updatePhoneAt(string phone, int index)
{
    string allowedPhoneNumberCharacters="0123456789";
    bool isPhoneNumberValid;

    if(phone.length()==11){
        for(int i=0;i<phone.length();i++){
            if(allowedPhoneNumberCharacters.find(phone[i])!=string::npos){
                isPhoneNumberValid=true;
            }else{
                isPhoneNumberValid=false;
                break;
            }
    }
    }else{
        isPhoneNumberValid=false;
    }

    // This is one of the conditions that leads to entry insertion failure (Phone number being not valid)
    if(isPhoneNumberValid==false){
        return false;
    }

    if (isPhoneNumberValid)
    {
        phones [index] = phone;
        return true;
    }
    else
    {
        return false;
    }
    

}

//Update phone at indices.
void MyPhoneBook::displayEntryAtIndices(int *indicesArray)
{
    bool isArrayValid = true;
    for (int i = 0; i < phoneBookSize; i++)
    {
        if (indicesArray[i] != 1 && indicesArray[i] != 0)
        {
            cout << "Array entered is not valid" << endl;
            isArrayValid = false;
            break;
        }
    }

    if (isArrayValid)
    {
        for (int i = 0; i < phoneBookSize; i++)
        {
            if (indicesArray[i] == 1)
            {
                cout << setw(10) << names[i];
                cout << setw(20) << phones[i];
                cout << endl;
            }
        
        }
    }
    
    
}

int main()
{
    int sizeOfPhoneBook;
    bool isProgramRunning = true;
    cout << "Enter the size of your phonebook: ";
    cin >> sizeOfPhoneBook;

    MyPhoneBook userPhoneBook(sizeOfPhoneBook);

    for(int i=0;i<sizeOfPhoneBook;i++)
    {
        string name;
        string phone;
        enterAgain:
        cout<<"Enter name "<<to_string(i+1)<<": ";
        cin>>name;
        cout<<"Enter phone "<<to_string(i+1)<<": ";
        cin>>phone;
        bool entryAddedSuccessfully = userPhoneBook.addEntry(name,phone);
        if(entryAddedSuccessfully==0){
            goto enterAgain;
        }
    }

    do
    {
        string userChoice;
        string allowedUserChoiceCharacters="12345678";
        bool isUserChoiceValid;

        cout<<""<<endl;
        cout<<""<<endl;
        cout<<"Enter your choice: "<<endl;
        cout<<"1- Display all phone book"<<endl;
        cout<<"2- Search for entry/entries by name"<<endl;
        cout<<"3- Search for entry/entries by phone"<<endl;
        cout<<"4- Find an entry by index"<<endl;
        cout<<"5- Update name by index"<<endl;
        cout<<"6- Update phone by index"<<endl;
        cout<<"7- Copy phone book to another and display entries of the new phone book"<<endl;
        cout<<"8- Exit"<<endl;
        cout<<"Choice: ";

        cin>>userChoice;
        int finalChoice;

        // to check user's input.
        if(userChoice.length()==1)
        {   
            if(allowedUserChoiceCharacters.find(userChoice[0])!=string::npos)
            {
                isUserChoiceValid=true;
                // Converting input of user to int.
                finalChoice = stoi(userChoice);
            }
            else
            {
                cout<<"Invalid Choice! Please choose from the menu!"<<endl;
                isUserChoiceValid=false;
            }
            
        }
        else
        {
            cout<<"Invalid Choice! Please choose from the menu!"<<endl;
            isUserChoiceValid=false;
        }
        
        

        if (isUserChoiceValid)  
        {
            switch (finalChoice)
            {
                case 1:
                    userPhoneBook.displayAll();
                    break;

                case 2:
                {
                    string nameToSearchFor;
                    cout<<"Enter the name(Or part of it) you want to search for: "<<endl;
                    cin >>nameToSearchFor;
                    int * nameSearchResultArray=userPhoneBook.findByName(nameToSearchFor);
                    for(int i=0;i<sizeOfPhoneBook;i++){
                        if(nameSearchResultArray[i]==1){
                            cout<<"Entry at index "<<i<<" is a match"<<endl;
                        }else{
                            cout<<"Entry at index "<<i<<" is not a match"<<endl;
                        }
                    }
                    
                    delete [] nameSearchResultArray;
                    nameSearchResultArray = NULL;
                    break;
                }
                case 3:
                {
                    string phoneToSearchFor;
                    cout<<"Enter the phone number(Or part of it) you want to search for: "<<endl;
                    cin >>phoneToSearchFor;
                    int * phoneSearchResultArray=userPhoneBook.findByPhone(phoneToSearchFor);
                    for(int i=0;i<sizeOfPhoneBook;i++){
                        if(phoneSearchResultArray[i]==1){
                            cout<<"Entry at index "<<i<<" is a match"<<endl;
                        }else{
                            cout<<"Entry at index "<<i<<" is not a match"<<endl;
                        }
                    }
                    delete [] phoneSearchResultArray;
                    phoneSearchResultArray = NULL;
                    
                    break;
                }
                case 4:
                {
                    string subMenuChoice;
                    int indexOfEntry;
                    cout<<"Please choose from this menu the operation you want:"<<endl;
                    cout<<"A-Find just one entry by its index"<<endl;
                    cout<<"B-Find more than one entry by their indices"<<endl;
                    cout<<"Your Choice:"<<endl;
                    cin>>subMenuChoice;
                    if(subMenuChoice=="A" ||subMenuChoice=="a"){
                        cout<<"Enter the index of the entry:"<<endl;
                        cin>>indexOfEntry;
                        bool resultOfDisplayAtIndex=userPhoneBook.displayEntryAtIndex(indexOfEntry);
                        if(resultOfDisplayAtIndex==0){
                            cout<<"Index out of range!"<<endl;
                        }
                    }
                    else if(subMenuChoice=="B"||subMenuChoice=="b"){
    
                        // By Indices


                    }
                    else{
                        cout<<"Invalid choice!"<<endl;
                    }
                    break;
                }
                case 5: // Update name by index
                {    
                    int index;
                    string updatedName;

                    cout << "Enter index: ";
                    cin >> index;

                    if (index < 0 || index > sizeOfPhoneBook)
                    {
                        cout << "Please enter a correct index.";
                    }
                    
                    cout << "Enter updated name: ";
                    cin >> updatedName;

                    bool isExecutedCorrectly = userPhoneBook.updateNameAt(updatedName,index);
                    
                    if (!isExecutedCorrectly)
                    {
                        cout << "Process not executed correctly. Please try again." << endl;
                    }

                    break;
                }
                // Update phone by index
                case 6:
                {   
                    int index;
                    string updatedPhone;

                    cout << "Enter index: ";
                    cin >> index;

                    if (index < 0 || index > sizeOfPhoneBook)
                    {
                        cout << "Please enter a correct index.";
                    }

                    cout << "Enter updated phone number: ";
                    cin >> updatedPhone;
                    
                    bool isExecutedCorrectly = userPhoneBook.updatePhoneAt(updatedPhone,index);
                    
                    if (!isExecutedCorrectly)
                    {
                        cout << "Process not executed correctly. Please try again." << endl;
                    }
                    break;
                }
                case 7:
                {    
                    MyPhoneBook copyOfUserPhoneBook(userPhoneBook);
                    cout<<"Phone book copied!"<<endl;
                    cout<<"Here is the content of the new copy of phone book :"<<endl;
                    copyOfUserPhoneBook.displayAll();
                    break;
                }
                case 8:
                {
                    isProgramRunning = false;
                    break;
                }
                
            }
        }
        


    } while (isProgramRunning);
    
    
    return 0;
}