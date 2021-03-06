#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
/* 
Group : SG1
Team members:
[Name: Mostafa Ibrahim Abdellatif, ID:20205006] [Name: Youssef Mohamed Emam, ID:20205031]
*/
// Class declaration.
class MyPhoneBook
{
    private:
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


// Parameterized constructor
MyPhoneBook::MyPhoneBook(int phoneBookSize)
{
    this->phoneBookSize=phoneBookSize;

    names=new string[phoneBookSize];
    phones=new string[phoneBookSize];

    findNameArray=new int[phoneBookSize];
    findPhoneArray=new int[phoneBookSize];

    for(int i=0;i<phoneBookSize;i++)
    {
        names[i]=" ";
        phones[i]=" ";
    }
}

// Copy constructor
MyPhoneBook::MyPhoneBook(const MyPhoneBook &phoneBook)
{
    phoneBookSize=phoneBook.phoneBookSize;

    names=new string[phoneBookSize];
    phones=new string[phoneBookSize];

    findNameArray=new int[phoneBookSize];
    findPhoneArray=new int[phoneBookSize];

    for(int i=0;i<phoneBookSize;i++)
    {
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

// addEntry function
bool MyPhoneBook::addEntry(string name ,string phone)
{
    bool entryAddedSuccessfully; 
    string allowedPhoneNumberCharacters="0123456789";
    bool isPhoneNumberValid;

    // Checking User's input.
    if(phone.length()==11)
    {
        for(int i=0;i<phone.length();i++)
        {
            if(allowedPhoneNumberCharacters.find(phone[i])!=string::npos) 
            {
                isPhoneNumberValid=true;
            }
            else
            {
                cout << "Phone number is not valid! Entry not added!" << endl; ;
                isPhoneNumberValid=false;
                break;
            }
        }
    }
    else
    {
        isPhoneNumberValid=false;
    }

    // This is one of the conditions that leads to entry insertion failure (Phone number being not valid).
    if(isPhoneNumberValid==false)
    {
        cout<<"Phone number is not valid! Entry not added!"<<endl;
        return false;
    }

    // Checking for available places in the phonebook.
    for(int i=0;i<phoneBookSize;i++)
    {
        if(names[i]==" "&&phones[i]==" ")
        {
            names[i]=name;
            phones[i]=phone;

            entryAddedSuccessfully=true;
            break;
        }
        else
        {
            entryAddedSuccessfully=false;
            continue;    
        }
    }

    if(entryAddedSuccessfully==true && isPhoneNumberValid==true)
    {
        return true;
    }
    else
    {
        cout<<"Attempt to add an entry failed!"<<endl;
        return false;
    }
}

// displayEntryAtIndex function
bool MyPhoneBook::displayEntryAtIndex(int index)
{
    // Checking if the index entered is out of bounds.
    if(index>(phoneBookSize-1) || index<0)
    {
        return false;
    }
    else
    {
        cout<<"Name: "<<names[index]<<endl;
        cout<<"Phone number: "<<phones[index]<<endl;
        return true;
    }
}

//Display entries at indices.
void MyPhoneBook::displayEntryAtIndices(int *indicesArray)
{
    bool isArrayValid = true;

    for (int i = 0; i < phoneBookSize; i++)
    {
        if (indicesArray[i] != 1 && indicesArray[i] != 0)
        {
            cout << "Array entered is not valid." << endl;
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
                cout << "Name " << (i+1)  << ": " << setw(20) << left << names[i];
                cout << "Phone " << (i+1)  << ": " << phones[i];
                cout << endl;
            }
        
        }
    }
    
    
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
            cout << "Name " << (i+1)  << ": " << setw(20) << left << names[i];
            cout << "Phone " << (i+1)  << ": " << phones[i];
            cout << endl;
        }
        
    }
    
}

// findByName function
int * MyPhoneBook::findByName(string name)
{
    //User will enter whether he wants to find just from the beginning of the name string or from any part of the name string
    string findPosition;

    cout<<"\nChoose from this menu:\n\n1- To start with it\nDef- To have it (with a no specific position to find it)\n\n";
    cout<<"Note that: If you entered any character that is not (1), the default(Def) will be choosen and executed\n\n";
    cout<<"Your choice: ";

    cin>>findPosition;

    if(findPosition=="1"){
        for(int i=0;i<phoneBookSize;i++)
        {
            if(names[i].rfind(name,0)!=string::npos)
            {
                findNameArray[i]=1;
            }
            else
            {
                findNameArray[i]=0;
            }
        }
    }
    else
    {
        for(int i=0;i<phoneBookSize;i++)
        {
            if(names[i].find(name)!=string::npos)
            {
                findNameArray[i]=1;
            }
            else
            {
                findNameArray[i]=0;
            }
        }

    }
    

    return findNameArray;
}

// findByPhone function
int * MyPhoneBook::findByPhone(string phone)
{
    //User will enter whether he wants to find just from the beginning of the phone string or from any part of the phone string

    string findPosition;
    cout<<"\nChoose from this menu:\n\n1- To start with it\nDef- To have it (with a no specific position to find it)\n\n";
    cout<<"Note that: If you entered any character that is not (1), the default(Def) will be choosen and executed\n\n";
    cout<<"Your choice: ";

    cin>>findPosition;

    if(findPosition=="1"){
        for(int i=0;i<phoneBookSize;i++)
        {
            if(phones[i].rfind(phone,0)!=string::npos)
            {
                findPhoneArray[i]=1;
            }
            else
            {
                findPhoneArray[i]=0;
            }
        }
    }
    else
    {
        for(int i=0;i<phoneBookSize;i++)
        {
            if(phones[i].find(phone)!=string::npos)
            {
                findPhoneArray[i]=1;
            }
            else
            {
                findPhoneArray[i]=0;
            }
        }

    }
    return findPhoneArray;
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

    if(phone.length()==11)
    {
        for(int i=0;i<phone.length();i++)
        {
            if(allowedPhoneNumberCharacters.find(phone[i])!=string::npos)
            {
                isPhoneNumberValid=true;
            }
            else
            {
                isPhoneNumberValid=false;
                break;
            }
        }
    }
    else
    {
        isPhoneNumberValid=false;
    }

    // This is one of the conditions that leads to entry insertion failure (Phone number being not valid)
    if(isPhoneNumberValid==false)
    {
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


//A function for validating user input in the main function
bool validateUserInput(string &inputText,int &convertedText,string customAllowedCharacters,string customInvalidMessage)
{
    for(int i=0;i<inputText.length();i++)
    {
        if(customAllowedCharacters.find(inputText[i])!=string::npos)
        {
            convertedText=stoi(inputText);
            return true;
        }
        else
        {
            cout<<customInvalidMessage<<endl;
            return false;
        }
    }
    // Return statement to avoid warning from the compiler, code runs normally without it.
    return false;
}

int main()
{   
    string inputSizeOfPhoneBook;
    int sizeOfPhoneBook;
    bool isProgramRunning = true;
    bool sizeValidationResult = false;

   
    cout << "Enter the size of your phonebook: ";
    cin >> inputSizeOfPhoneBook;
    cin.ignore(1000, '\n');

    sizeValidationResult=validateUserInput(inputSizeOfPhoneBook ,sizeOfPhoneBook,"123456789","Invalid Input of Phone book Size!");
        
    if(sizeValidationResult==false)
    {
        isProgramRunning=false;
    }
    
    if(sizeValidationResult==true){
        MyPhoneBook userPhoneBook(sizeOfPhoneBook);
        for(int i=0;i<sizeOfPhoneBook;i++)
        {
            string name;
            string phone;

            enterAgain:
            cout<<"Enter name "<<to_string(i+1)<<": ";
            getline(cin, name);

            cout<<"Enter phone "<<to_string(i+1)<<": ";
            getline(cin, phone);

            bool entryAddedSuccessfully = userPhoneBook.addEntry(name,phone);

            if(entryAddedSuccessfully==0)
            {
                goto enterAgain;
            }
        }
        while (isProgramRunning)
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
            cin.ignore(1000, '\n');

            int finalChoice;
            if(userChoice.length()==1)
            {
                isUserChoiceValid=validateUserInput(userChoice,finalChoice,allowedUserChoiceCharacters,"Invalid Choice! Please choose from the menu!");
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
                    case 1: // Display all entries
                        userPhoneBook.displayAll();
                        break;

                    case 2: // Search by name
                    {
                        string nameToSearchFor;

                        cout<<"Enter the name(Or part of it) you want to search for: ";
                        cin >>nameToSearchFor;
                        cin.ignore(1000, '\n');

                        int * nameSearchResultArray=userPhoneBook.findByName(nameToSearchFor);

                        for(int i=0;i<sizeOfPhoneBook;i++)
                        {
                            if(nameSearchResultArray[i]==1)
                            {
                                cout<<"*Entry at index "<<i<<" is a match: "<<endl;             
                                userPhoneBook.displayEntryAtIndex(i);
                                cout<<""<<endl;
                            }
                            else
                            {
                                cout<<"*Entry at index "<<i<<" is not a match."<<endl;
                                cout<<""<<endl;
                            }
                        }
                        
                        nameSearchResultArray = NULL;
                        break;
                    }
                    case 3: // Search by phone
                    {
                        string phoneToSearchFor;

                        cout<<"Enter the phone number(Or part of it) you want to search for: ";
                        cin >>phoneToSearchFor;
                        cin.ignore(1000, '\n');

                        int * phoneSearchResultArray=userPhoneBook.findByPhone(phoneToSearchFor);

                        for(int i=0;i<sizeOfPhoneBook;i++)
                        {
                            if(phoneSearchResultArray[i]==1)
                            {
                                cout<<"*Entry at index "<<i<<" is a match: "<<endl;             
                                userPhoneBook.displayEntryAtIndex(i);
                                cout<<""<<endl;
                                
                            }
                            else
                            {
                                cout<<"*Entry at index "<<i<<" is not a match."<<endl;
                                cout<<""<<endl;
                            }
                        }

                        phoneSearchResultArray = NULL;
                        break;
                    }
                    case 4: // Find entry by index / indices
                    {
                        string subMenuChoice;
                        string indexOfEntry;
                        int validatedIndexOfEntry;

                        cout<<"Please choose from this menu the operation you want: " << endl;
                        cout<<"A-Find just one entry by its index"<<endl;
                        cout<<"B-Find more than one entry by their indices"<<endl;
                        
                        cout<<"Your Choice: ";
                        cin >> subMenuChoice;
                        cin.ignore(1000, '\n');
                        

                        if(subMenuChoice=="A" ||subMenuChoice=="a")
                        {
                            cout<<"Enter the index of the entry: ";
                            cin>>indexOfEntry;
                            cin.ignore(1000, '\n');

                            if(!validateUserInput(indexOfEntry,validatedIndexOfEntry,"012345689","Invalid Input (Not an Integer)"))
                            {
                                continue;
                            }
                            

                            bool resultOfDisplayAtIndex=userPhoneBook.displayEntryAtIndex(validatedIndexOfEntry);

                            if(resultOfDisplayAtIndex==0)
                            {
                                cout<<"Index out of range!"<<endl;
                            }
                        }
                        else if(subMenuChoice=="B"||subMenuChoice=="b")
                        {
                            // By Indices
                            int * arrayOfIndices = new int [sizeOfPhoneBook];

                            for (int i = 0; i < sizeOfPhoneBook; i++)
                            {
                                cout << "Enter 0 or 1 for entry number " << (i+1) << ": ";
                                cin >> arrayOfIndices[i];
                                cin.ignore(1000, '\n');
                            }
                            
                            cout << endl;
                            userPhoneBook.displayEntryAtIndices(arrayOfIndices);


                            delete [] arrayOfIndices;
                            arrayOfIndices = NULL;
                            
                        }
                        else
                        {
                            cout<<"Invalid choice!"<<endl;
                        }
                        break;
                    }
                    case 5: // Update name by index
                    {    
                        string index;
                        string updatedName;
                        int validatedIndexOfEntry;

                        cout << "Enter index: ";
                        cin >> index;
                        cin.ignore(1000, '\n');
                        

                        if(!validateUserInput(index,validatedIndexOfEntry,"012345689","Invalid Input (Not an Integer)"))
                        {
                                continue;
                        }

                        if (validatedIndexOfEntry < 0 || validatedIndexOfEntry > sizeOfPhoneBook)
                        {
                            cout << "Please enter a correct index.";
                            break;
                        }
                        
                        cout << "Enter updated name: ";
                        getline(cin,updatedName);
                        

                        bool isExecutedCorrectly = userPhoneBook.updateNameAt(updatedName,validatedIndexOfEntry);
                        
                        if (!isExecutedCorrectly)
                        {
                            cout << "Process not executed correctly. Please try again." << endl;
                        }

                        break;
                    }
                    // Update phone by index
                    case 6:
                    {   
                        string index;
                        string updatedPhone;
                        int validatedIndexOfEntry;

                        cout << "Enter index: ";
                        cin >> index;
                        cin.ignore(1000, '\n');

                        if(!validateUserInput(index,validatedIndexOfEntry,"012345689","Invalid Input (Not an Integer)"))
                        {
                            continue;
                        }

                        if (validatedIndexOfEntry < 0 || validatedIndexOfEntry > sizeOfPhoneBook)
                        {
                            cout << "Please enter a correct index.";
                            break;
                        }

                        cout << "Enter updated phone number: ";
                        cin >> updatedPhone;
                        cin.ignore(1000, '\n');
                        
                        bool isExecutedCorrectly = userPhoneBook.updatePhoneAt(updatedPhone,validatedIndexOfEntry);
                        
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
        


        }
    }

     
    
    
    return 0;
}