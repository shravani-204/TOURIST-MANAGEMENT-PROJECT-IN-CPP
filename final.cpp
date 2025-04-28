#include <iostream>
#include <string>
#include <vector>
#include <limits> 
#include <algorithm>
using namespace std;

class Tourist {
public:
    string name;
    int age;
    string contactNumber;
    
      void inputTouristInfo() {
        cout << "Enter your full Name (First Middle Last): ";
        getline(cin, name);
        while (count(name.begin(), name.end(), ' ') < 2) {
            cout << "Invalid FULL NAME. Please enter in 'First Middle Last' format: ";
            getline(cin, name);
        }
        cout << "Enter your Age: ";
        cin >> age;
        while(cin.fail() || age <=0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize> :: max(), '\n');
            cout<<"invalid age. please enter valid age :";
            cin>>age;
        }
        cin.ignore();  

        cout << "Enter your Contact Number: ";
        getline(cin, contactNumber);
        while(contactNumber.length()<10 || contactNumber.length()>15)
        {
            cout<<"invalid contact number . please enter a valid number : ";
            getline(cin,contactNumber);
        }
    }

    void displayTouristInfo() const {
        cout << "Tourist Name: " << name <<endl;
        cout << " Age: " << age<<endl;
        cout  << " Contact Number: " << contactNumber << endl;
    }
};

class Tour {
public:
    int id;
    string name;
    float price;
    int booked;
    string tourDate;
    string destination;
    string description;
    Tourist touristInfo;  
    Tour() : booked(0) {}

    void inputDetails() {
        cout << "Enter Tour ID: ";
        cin >> id;
        while(cin.fail()){
         cin.clear();
        cin.ignore(numeric_limits<streamsize> :: max(), '\n');
        cout<<"invalid input . tour ID must be a number : ";
        cin>>id;
        }
        cin.ignore();  

        cout << "Enter Tour Name: ";
        getline(cin, name);
      


        cout << "Enter Tour Price: ";
        cin >> price;
        while(cin.fail() || price <=0){
            cin.clear();
           cin.ignore(numeric_limits<streamsize> :: max(), '\n');
           cout<<"invalid price . please enter valid price : ";
           cin>>price;
        }
        cin.ignore();

        cout << "Enter Tour Date (DD/MM/YYYY): ";
        getline(cin, tourDate);
        while(tourDate.length() != 10 || tourDate[2] !='/' || tourDate[5] !='/')
        {
              cout<<"invalid date format. please enter in DD/MM/YYYY format. "; 
              getline(cin, tourDate);
        }

        cout << "Enter Destination: ";
        getline(cin, destination);

        booked = 0;  
    }

    void displayDetails() const {
        cout << "ID: " << id<<endl;
        cout << " Name: " << name<<endl;
         cout << " Price: " << price<<endl;
         cout << " Booked: " << booked<<endl;
         cout << " Tour Date: " << tourDate<<endl;
         cout << " Destination: " << destination
             << endl;
    }
};

class TouristManagementSystem {
private:
    vector<Tour> tours;

public:
    void addTour() {
        Tour newTour;
        newTour.inputDetails();
        tours.push_back(newTour);
        cout << "Tour added successfully." << endl;
    }

    void updateBookings() {
        int id;
        bool found = false;

        cout << "Enter Tour ID to update booking status: ";
        cin >> id;
        while(cin.fail()){
            cin.clear();
           cin.ignore(numeric_limits<streamsize> :: max(), '\n');
           cout<<"invalid input . tour ID must be a number : ";
           cin>>id;
        }

        
        for (auto& tour : tours) {
            if (tour.id == id) {
                cout << "Enter number of bookings: ";
                cin >> tour.booked;
                while(cin.fail() || tour.booked<0)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize> :: max() , '\n');
                    cout<<"invalid input. Please enter valid number :";
                    cin>>tour.booked;
                }
                found = true;
                cout << "Bookings updated successfully." << endl;
                break;
            }
        }

        if (!found) {
            cout << "Tour not found." << endl;
        }
    }

    void viewTours() const {
        if (tours.empty()) {
            cout << "No tours to display." << endl;
            return;
        }

        cout << "Tour List:" << endl;
        for (const auto& tour : tours) {
            tour.displayDetails();
            // Calculate the total cost for the tour
            float totalCost = tour.price * tour.booked;
            cout << "Total Cost for " << tour.booked << " tourist(s): Rs. " << totalCost << endl;
            cout << "----------------------------------------------------------\n";
        }
    }

    void deleteTour() {
        int id;
        bool found = false;

        cout << "Enter Tour ID to delete: ";
        cin >> id;
        while(cin.fail()){
            cin.clear();
           cin.ignore(numeric_limits<streamsize> :: max(), '\n');
           cout<<"invalid input . tour ID must be a number : ";
           cin>>id;
        }
       

        for (size_t i = 0; i < tours.size(); ++i) {
            if (tours[i].id == id) {
                cout << "Tour " << tours[i].name << " (ID: " << tours[i].id << ") deleted successfully" << endl;
                tours.erase(tours.begin() + i); 
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Tour not found." << endl;
        }
    }

    void availableTours() {
        struct TourInfo {
            string destination;
            string description;
            int totalSeats;
        };

        TourInfo toursList[] = {

            {"Varanasi : \n"

                "The holy city of Varanasi, located on the banks of the Ganges, is known for its ghats, temples, and spiritual significance.  \n  available seats : 40 \n  days : 5 days/3 night  \n \n -----HOTEL NAME : HOTEL KASHI PRIDE \n,----------------------------------------------------------- "},

           {"Golden Temple : \n"
                "The Golden Temple in Amritsar is a revered Sikh shrine, known for its stunning golden architecture and peaceful ambiance.\n \n  available seats : 40 \n   days : 5 days/3 night \n \n  ------ HOTEL NAME : HOTEL GOLDEN \n---------------------------------------------------------------"},

           {"Hampi : \n"
                "Hampi, a UNESCO World Heritage Site, features ancient temples, ruins, and captivating landscapes from the Vijayanagar Empire.\n \n available seats : 10 \n  days : 4days / 3night \n \n ------HOTEL NAME : HOTEL HUMPI KING \n------------------------------------------------------------"},

           {"Kedarnath : \n"
                "Kedarnath is a famous pilgrimage site in Uttarakhand, home to the Kedarnath Temple, located amidst the scenic Himalayas.\n \n available seats : 20 \n   days :  4 days/3 night \n \n ---------HOTEL NAME : KEDAR VALLEY RESORT \n---------------------------------------------------------"},

           {"Mysore Palace : \n"
                "Mysore Palace is an iconic royal residence, known for its magnificent architecture and opulent interiors, located in the city of Mysore.\n \n available seats : 10 \n   days : 3 days/2 night \n \n -----HOTEL NAME : MYSORE COUNTRY RETREAT \n---------------------------------------------"},

           {"Taj Mahal : \n"
                "The Taj Mahal in Agra is a UNESCO World Heritage Site, famous for its white marble architecture, built as a symbol of love.\n \n available seats : 60 \n   days : 2 days/1 night \n \n------HOTEL NAME : HOTEL TAJ RESORT \n-------------------------------------------------------------- "},

           {"Gateway of India : \n"
                "The Gateway of India in Mumbai is an iconic monument, symbolizing India's colonial past, built to commemorate the visit of King George V. \n \n available seats : 100 \n   days : 2 days/1 night \n \n----HOTEL NAME : OBERA \n------------------------------------------------------------"},

           {"Delhi : \n"
                "Delhi, the capital city of India, is a bustling metropolis known for its historical monuments, vibrant markets, and rich cultural heritage.\n \n available seats : 50 \n   days : 3 days/2 night \n \n ----HOTEL NAME : HOTEL AJANTA \n----------------------------------------------------"},

           {"Ooty : \n"
                "Ooty, located in the Nilgiri hills, is a serene hill station known for its lush greenery, tea gardens, and pleasant weather.\n \n available seats : 40  \n   days : 4 days/3 night \n \n-------HOTEL NAME :  GEM PARK OOTY \n--------------------------------------------------------------"},

           {"Darjeeling : \n"
                "Darjeeling, known as the 'Queen of the Hills,' is famous for its scenic tea plantations, vibrant culture, and stunning views of the Kanchenjunga.\n \n available seats : 80  \n   days : 4 days/3 night \n \n-----HOTEL NAME : HOTEL ROYAL \n----------------------------------------------"},
                
           {"Shimla : \n"
                "Shimla is a popular hill station known for its colonial architecture, scenic landscapes, and pleasant weather, located in Himachal Pradesh.\n \n available seats : 90 \n   days : 3 days/2 night \n \n------HOTEL NAME : THE GREEN PARK SHIMLA \n-------------------------------------------"}
            
        };

        cout << "Available Tours:\n";
        for (int i = 0; i < 11; i++) {
            cout << i + 1 << ". " << toursList[i].destination << endl;
            cout << "   " << toursList[i].description << endl;
           
            cout << "----------------------------------------------------------\n";
        }
    }


    void bookAvailableTour() {
        string destinations[] = {"Varanasi", "Golden Temple", "Hampi", "Kedarnath", "Mysore Palace", "Taj Mahal", 
                                  "Gateway of India", "Delhi", "Ooty", "Darjeeling", "Shimla"};
        float prices[] = {20000.0, 25000.0, 32000.0, 45000.0, 38000.0, 10000.0, 5000.0, 9500.0, 40000.0, 40000.0, 30000.0};

        cout << "Choose a destination to book:\n";
        for (int i = 0; i < 11; i++) {
            cout << i + 1 << ". " << destinations[i] << " - Price: Rs." << prices[i] << endl;
        }

        int choice;
        cout << "Enter the number of the destination you want to book: ";
        cin >> choice;

        if (choice < 1 || choice > 11) {
            cout << "Invalid choice!" << endl;
            return;
        }

        cout << "You have selected " << destinations[choice - 1] << " with a price of Rs." << prices[choice - 1] << endl;

        string tourDate;
        cout << "Enter the date for the tour (DD/MM/YYYY): ";
        cin >> tourDate;
        getline(cin, tourDate);
        while(tourDate.length() != 10 || tourDate[2] !='/' || tourDate[5] !='/')
        {
              cout<<"invalid date format. please enter in DD/MM/YYYY format. "; 
              getline(cin, tourDate);
        }

        Tourist tourist;
        cin.ignore();  
        tourist.inputTouristInfo();

        cout<<"select payment method : \n";
        cout<<"1. credit/debit card : \n";
        cout<<"2. UPI  : \n";
        cout<<"3. NET BANKING  : \n";

        int paymentChoice;
        while(paymentChoice < 1 || paymentChoice >3){
            cout<<"invalid choice. please select 1, 2 or 3 : ";
            cin>>paymentChoice;
        }
        switch (paymentChoice){
            case 1:
            cout<<"processing credit / debit card payment ...\n";
            break;
            case 2:
            cout<<"processing UPI payment ...\n";
            break;
            case 3:
            cout<<"processing NET BANKING payment ...\n";
            break;
        }
        cout<<"payment successful !!! \n";
        
      
        
       
        
        Tour bookedTour;
        bookedTour.id = tours.size() + 1;
        bookedTour.name = destinations[choice - 1];
        bookedTour.price = prices[choice - 1];
        bookedTour.booked = 1;
        bookedTour.tourDate = tourDate;
        bookedTour.destination = destinations[choice - 1];
        bookedTour.description = "A popular tour destination.";
        bookedTour.touristInfo = tourist;

        tours.push_back(bookedTour);

        cout << "Tour booked successfully!\n";
  }  

  void summerOffers() {
    string summerList[] = {
        "Goa Beach Retreat\nHotel: Sea Breeze Resort\nSeats: 30\nDays: 5 days/4 nights\nOffer: 15% off",
        "Ladakh Adventure Camp\nHotel: Himalayan View Camp\nSeats: 20\nDays: 6 days/5 nights\nOffer: Free guided trek",
        "Manali Hill Escape\nHotel: Pine Valley Resort\nSeats: 40\nDays: 5 days/4 nights\nOffer: Complimentary breakfast",
        "Rishikesh River Rafting\nHotel: Riverside Camp\nSeats: 25\nDays: 3 days/2 nights\nOffer: 10% off + Free Yoga Session",
        "Andaman Islands Tour\nHotel: Coral Bay Resort\nSeats: 15\nDays: 6 days/5 nights\nOffer: Free scuba diving session"
    };

    cout << "Special Summer Tour Offers:\n";
    for (int i = 0; i < 5; ++i) {
        cout << i + 1 << ". " << summerList[i]
             << "\n----------------------------------------------------------\n";
    }
}


 
};


bool isValidUsername(const string & username){
    if(username.length() !=5)
    return false;
    for(char c : username){
        if(!islower(c))
        return false;
    }
       return true;
    }
   

    bool isValidPassword(const string & password){
        if(password.length() != 8)
        return false;
        for(char c : password){
            if(!isdigit(c))
            return false;
        }
           return true;
        }
       
bool login() {
    string username;
    string password;

    
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

   if(isValidUsername(username) && isValidPassword(password))
   {
     cout<<"Login Successful. WELCOME, "<<username <<endl;
     return true;
   }
   else{
    if(!isValidUsername(username))
    cout<<"invalid USERNAME. it must be 5 LOWERCASE letters only  ."<<endl;
    if(!isValidPassword(password))
    cout<<"invalid PASSWORD. it must be 8 DIGITS only ."<<endl;
    return false;
   }
}

int main() {
    cout << "-------------------------------\n";
    cout << "Welcome to the Tourist Management System\n";
    cout << "-------------------------------\n";

    bool isLoggedIn = false;
    while (!isLoggedIn) {
        cout << "\nPlease log in to continue:\n";
        cout<<"----------------------------------\n";
        isLoggedIn = login();
    }
  
    TouristManagementSystem system;
    int choice;

    do {
        cout << "\nTourist Management System\n";
        cout << "----------------------------------\n";
        cout << "1. Add Tour\n";
        cout << "----------------------------------\n";
        cout << "2. Update Tour Bookings\n";
        cout << "----------------------------------\n";
        cout << "3. View Tours\n";
        cout << "----------------------------------\n";
        cout << "4. Delete Tour\n";
        cout << "----------------------------------\n";
        cout << "5. Available Tours\n";
        cout << "----------------------------------\n";
        cout << "6. Book an Available Tour\n";
        cout << "----------------------------------\n";
        cout << "7. Special Summer Offers\n";
        cout << "----------------------------------\n";
        cout << "8. Exit\n"; 
      
        cout << "----------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        while (cin.fail() || choice<1 || choice>8)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize> :: max(),'\n');
            cout<<"INVALID CHOICE . please enter number between 1 and 8 : ";
            cin>>choice;
        }

        switch (choice) {
            case 1:
                system.addTour();
                break;
            case 2:
                system.updateBookings();
                break;
            case 3:
                system.viewTours();
                break;
            case 4:
                system.deleteTour();
                break;
            case 5:
                system.availableTours();
                break;
            case 6:
                system.bookAvailableTour();
                break;
        
                case 7:
                 system.summerOffers(); 
                break;
                case 8: 
                cout << "Exiting system. Goodbye!\n";
                 break;
            default :
            cout<<"Invalid choice. try again. "<<endl;
            
            }  
        }
        while(choice != 8);
        return 0;
    }
