#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Library
{
public:
    int bookId;
    string title;
    string author;
    int issued;
};

int main()
{
    Library book[100];

    int count = 0;
    int choice;
    int searchId;

    string searchTitle;
    string searchAuthor;

    ifstream infile("library.txt");

    while(infile >> book[count].bookId
                 >> book[count].title
                 >> book[count].author
                 >> book[count].issued)
    {
        count++;
    }

    infile.close();

    do
    {
        cout << "\n\n===== LIBRARY MANAGEMENT SYSTEM =====";

        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search By Title";
        cout << "\n4. Search By Author";
        cout << "\n5. Issue Book";
        cout << "\n6. Return Book";
        cout << "\n7. Save Records";
        cout << "\n8. Exit";

        cout << "\n\nEnter Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:

                cout << "\nEnter Book ID : ";
                cin >> book[count].bookId;

                cout << "Enter Book Title : ";
                cin >> book[count].title;

                cout << "Enter Author Name : ";
                cin >> book[count].author;

                book[count].issued = 0;

                count++;

                cout << "\nBook Added Successfully!";
                break;

            case 2:

                if(count == 0)
                {
                    cout << "\nNo Books Found!";
                }
                else
                {
                    for(int i=0;i<count;i++)
                    {
                        cout << "\n\nBook ID : "
                             << book[i].bookId;

                        cout << "\nTitle : "
                             << book[i].title;

                        cout << "\nAuthor : "
                             << book[i].author;

                        if(book[i].issued == 0)
                            cout << "\nStatus : Available";
                        else
                            cout << "\nStatus : Issued";
                    }
                }

                break;

            case 3:

                cout << "\nEnter Book Title : ";
                cin >> searchTitle;

                for(int i=0;i<count;i++)
                {
                    if(book[i].title == searchTitle)
                    {
                        cout << "\nBook Found";

                        cout << "\nBook ID : "
                             << book[i].bookId;

                        cout << "\nAuthor : "
                             << book[i].author;
                    }
                }

                break;

            case 4:

                cout << "\nEnter Author Name : ";
                cin >> searchAuthor;

                for(int i=0;i<count;i++)
                {
                    if(book[i].author == searchAuthor)
                    {
                        cout << "\nBook Found";

                        cout << "\nBook ID : "
                             << book[i].bookId;

                        cout << "\nTitle : "
                             << book[i].title;
                    }
                }

                break;

            case 5:

                cout << "\nEnter Book ID : ";
                cin >> searchId;

                for(int i=0;i<count;i++)
                {
                    if(book[i].bookId == searchId)
                    {
                        if(book[i].issued == 0)
                        {
                            book[i].issued = 1;

                            cout << "\nBook Issued Successfully!";
                        }
                        else
                        {
                            cout << "\nBook Already Issued!";
                        }
                    }
                }

                break;

            case 6:

                cout << "\nEnter Book ID : ";
                cin >> searchId;

                for(int i=0;i<count;i++)
                {
                    if(book[i].bookId == searchId)
                    {
                        if(book[i].issued == 1)
                        {
                            book[i].issued = 0;

                            cout << "\nBook Returned Successfully!";
                        }
                        else
                        {
                            cout << "\nBook is Already Available!";
                        }
                    }
                }

                break;

            case 7:

                {
                    ofstream outfile("library.txt");

                    for(int i=0;i<count;i++)
                    {
                        outfile << book[i].bookId << " "
                                << book[i].title << " "
                                << book[i].author << " "
                                << book[i].issued << endl;
                    }

                    outfile.close();

                    cout << "\nRecords Saved Successfully!";
                }

                break;

            case 8:

                {
                    ofstream outfile("library.txt");

                    for(int i=0;i<count;i++)
                    {
                        outfile << book[i].bookId << " "
                                << book[i].title << " "
                                << book[i].author << " "
                                << book[i].issued << endl;
                    }

                    outfile.close();

                    cout << "\nData Saved. Exiting...";
                }

                break;

            default:

                cout << "\nInvalid Choice!";
        }

    }while(choice != 8);

    return 0;
}