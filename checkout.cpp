// Name
// Section #
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "person.cpp"
#include "book.cpp"

using namespace std;

void printMenu() {
    cout << "----------Library Book Rental System----------" << endl;
    cout << "1.  Book checkout" << endl;
    cout << "2.  Book return" << endl;
    cout << "3.  View all available books" << endl;
    cout << "4.  View all outstanding rentals" << endl;
    cout << "5.  View outstanding rentals for a cardholder" << endl;
    cout << "6.  Open new library card" << endl;
    cout << "7.  Close library card" << endl;
    cout << "8.  Exit system" << endl;
    cout << "Please enter a choice: ";
}

void readBooks(vector<Book *> & myBooks) {

  int n, id;
  string cat, ti, au;
  string file = "books.txt";
  string filler;
  ifstream infile;
  infile.open(file);
  while(!infile.eof())
  {
    getline(infile, filler);
    n++;
  }

  infile.close();
  infile.open();

  for (int i = 0; i < n; i++)
  {
    infile >> id;
    infile >> ti >> au >> cat;
    Book newBook (id, ti, au, cat);
    myBooks->push_back(newBook);
  }
}

void readPersons(vector<Person *> & myCardholders) {

    int card, n;
    bool check;
    string first, last, filler;
    string file = "persons.txt";
    ifstream infile;

    infile.open(file);
    while(!infile.eof())
    {
      getline(infile, filler);
      n++
    }
    infile.close();

    infile.open(file);
    for (int i = 0; i < n; i++)
    {
      infile >> card;
      infile >> check;
      infile >> first >> last;
      Person newPerson(card, check, first, last);
      myCardholders->push_back(newPerson);
    }
}

void readRentals(vector<Book *> & myBooks, vector<Person *> myCardholders) {

    int n, a, b;
    string filler,
          file = "rentals.txt";
    ifstream infile;;
    infile.open(file);
    while (!infile.eof())
    {
      getline(infile, filler);
      n++
    }

    infile.close();
    infile.open(file);
    for (int i = 0; i < n; n++)
    {
      infile >> a >> b;
      if (b == myCardholders.at(i)->getId())
      {
        if (myCardholders.at(i)->isActive == 1)
        {
          cout << "name: " << myCardholders.at(i)->fullName() << endl;
          cout << "Books rented: " << endl;

          for (int j = 0; j < n; j++)
          {
            if (a == myBooks.at(j)->getID)
            {
              cout << myBooks.at(j)->getTitle() << endl;
              cout << myBooks.at(j)->getAuthor() << endl;
              cout << myBooks.at(j)->getCategory() << endl;
            }
          }
        }
      }
    }
}

void openCard(vector<Person *> & myCardholders, int nextID) {

    ifstream infile;
    int n;
    string fileIn = "persons.txt",
                filler;

    infile.open(fileIn)
    while(infile.is_open())
    {
      getline(infile, filler);
      n++;
    }

    infile.close();

    for(int i = 0; i < n; i++)
    {
      if(nextID == myCardholders.at(i)->getId())
      {
        if (myCardholders.at(i)->isActive() == 0)
        {
          myCardholders.at(i)->isActive() = 1;
        }

        else
        {
          cout << "This card is already activated..." << end;
        }
      }
    }
}

void closeCard(vector<Person *> & myCardholders, int nextID)
{
  ifstream infile;
  int n;
  string fileIn = "persons.txt",
              filler;

  infile.open(fileIn)
  while(infile.is_open())
  {
    getline(infile, filler);
    n++;
  }
  infile.close();

  for(int i = 0; i < n; i++)
  {
    if(nextID == myCardholders.at(i)->getId())
    {
      if (myCardholders.at(i)->isActive() == 1)
      {
        myCardholders.at(i)->isActive() = 0;
      }

      else
      {
        cout << "This card is already deactivated..." << end;
      }
    }
  }
}

void update(vector<Book *> & myBooks, vector<Person *> myCardholders)
{
  ofstream outfile;
  string bookFile = "books.txt", personFile = "person.txt", filler, fill;
  outfile.open(personFile)
  for (int i = 0; i < myCardholders->size(); i++)
  {
    outfile << myCardholders.at(i)->getID();
    outfile << mycardholders.at(i)->isActive();
    outfile << mycardhodlers.at(i)->fullName() << endl;

  }

  outfile.close();
  outfile.open(bookFile);
  for (int j = 0; j < myBooks-.size(); i++)
  {
    outfile << myBooks.at(i)->getCategory() << endl;
    outfile << myBooks.at(i)->getTitle() << endl;
    outfile << myBooks.at(i)->getAuthor() << endl;
    outfile << myBooks.at(i)->getCategory() << endl << endl;
  }
}

Book * searchBook(vector<Book *> myBooks, int id) {
    return nullptr;
}


int main()
{
    vector<Book *> books;
    vector<Person *> cardholders;

    int choice, bID, cardID;
    string firstName, lastName;
    char decision;
    readBooks(books);
    readPersons(cardholders);
    do
    {
        // If you use cin anywhere, don't forget that you have to handle the <ENTER> key that
        // the user pressed when entering a menu option. This is still in the input stream.
        printMenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Please enter the card ID: ";
                cin >> cardID;
                for (int i = 0; i < persons->size(); i++)
                {
                  if(cardID == persons.at(i)->getID())
                  {
                    cout << "cardholder: " << persons.at(i)->fullName() << endl;
                    cout << "Please enter the ID of the book: ";
                    cin >> bID;
                    for (int i = 0; i < books.size(); i++)
                    {
                      if(bID == books.at(i)->getID())
                      {
                        cout << "BookName: " << books.at(i)->
                      }
                    }


                  }
                }


                break;

            case 2:
                // Book return
                cout << "Please enter the book ID to return: ";
                cin >> bID;
                break;

            case 3:
                // View all available books
                for (int i = 0; i < books->size(); i++)
                {
                  cout << books.at(i)->getId() << endl;
                  cout << books.at(i)->getTitle() << endl;
                  cout << books.at(i)->getauthot() << endl;
                  cout << books.at(i)->getCategory() << endl << endl;
                }

                break;

            case 4:
                // View all outstanding rentals
                break;

            case 5:
                // View outstanding rentals for a cardholder
                cout << "Please enter the number for the cardholder: "
                cin >> cardID;
                break;

            case 6:
                // Open a new card
                string fullname;
                cout << "Please enter the first name: ";
                cin >> firstName;
                cout << "Please enter the last name: ";
                cin >> lastName;
                fullname = firstName + " " + lastName;

                for (int i = 0; i < persons->size(); i++)
                {
                  if (fullname == persons.at(i)->fullName())
                  {
                    if (persons.at(i)->isActive == 0)
                    {
                      persons.at(i)->isActive = 1;
                    }

                    else if (persons.at(i)->isActive == 1)
                    {
                      cout << "error";
                      break;
                    }

                    else
                    {
                      break;
                    }
                  }
                }

                break;

            case 7:
                // Close library card
                cout << "Please enter the card ID: ";
                cin >> cardID;
                cout  << "Are you sure you want to deactivate card (y/n)?";
                cin >> decision;

                if (decision == 'y' || decision == 'Y')
                {
                  closeCard(cardholders, cardID);
                  cout << "card is now closed"
                }

                else if (decision == 'n' || decision == 'N')
                {
                    break;
                }

                else
                {
                  cout << "error, resetting page..."
                  break;
                }
                break;

            case 8:
                // Must update records in files here before exiting the program
                update(books, cardholders);
                break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
   } while(choice != 8);
      return 0;
}
