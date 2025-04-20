#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tourist {
public:
    string name;
    int age;
    string contactNumber;

    void inputTouristInfo() {
        cout << "Enter your Name: ";
        getline(cin, name);

        cout << "Enter your Age: ";
        cin >> age;
        cin.ignore();  

        cout << "Enter your Contact Number: ";
        getline(cin, contactNumber);
    }

    void displayTouristInfo() const {
        cout << "Tourist Name: " << name
             << ", Age: " << age
             << ", Contact Number: " << contactNumber << endl;
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
        cin.ignore();  

        cout << "Enter Tour Name: ";
        getline(cin, name);

        cout << "Enter Tour Price: ";
        cin >> price;
        cin.ignore();

        cout << "Enter Tour Date (DD/MM/YYYY): ";
        getline(cin, tourDate);

        cout << "Enter Destination: ";
        getline(cin, destination);

        booked = 0;  
    }

    void displayDetails() const {
        cout << "ID: " << id
             << ", Name: " << name
             << ", Price: " << price
             << ", Booked: " << booked
             << ", Tour Date: " << tourDate
             << ", Destination: " << destination
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

        for (auto& tour : tours) {
            if (tour.id == id) {
                cout << "Enter number of bookings: ";
                cin >> tour.booked;
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

                "The holy city of Varanasi, located on the banks of the Ganges, is known for its ghats, temples, and spiritual significance.  \n    available seats : 50 \n days : 5 days/3 night  \n \n -----HOTEL NAME : HOTEL KASHI PRIDE \n----------------------------------------------------- "},

           {"Golden Temple : \n"
                "The Golden Temple in Amritsar is a revered Sikh shrine, known for its stunning golden architecture and peaceful ambiance.\n \n  available seats : 40 \n   days : 5 days/3 night \n \n  ------ HOTEL NAME : HOTEL GOLDEN \n----------------------------------------------------------"},

           {"Hampi : \n"
                "Hampi, a UNESCO World Heritage Site, features ancient temples, ruins, and captivating landscapes from the Vijayanagar Empire.\n \n available seats : 10 \n  days : 4days / 3night \n \n ------HOTEL NAME : HOTEL HUMPI KING \n------------------------------------------------------"},

           {"Kedarnath : \n"
                "Kedarnath is a famous pilgrimage site in Uttarakhand, home to the Kedarnath Temple, located amidst the scenic Himalayas.\n \n available seats : 20 \n   days :  4 days/3 night \n \n ---------HOTEL NAME : KEDAR VALLEY RESORT \n---------------------------------------------------------"},

           {"Mysore Palace : \n"
                "Mysore Palace is an iconic royal residence, known for its magnificent architecture and opulent interiors, located in the city of Mysore.\n \n available seats : 10 \n   days : 3 days/2 night \n \n -----HOTEL NAME : MYSORE COUNTRY RETREAT \n---------------------------------------------"},

           {"Taj Mahal : \n"
                "The Taj Mahal in Agra is a UNESCO World Heritage Site, famous for its white marble architecture, built as a symbol of love.\n \n available seats : 60 \n   days : 2 days/1 night \n \n------HOTEL NAME : HOTEL TAJ RESORT \n-------------------------------------------------------- "},

           {"Gateway of India : \n"
                "The Gateway of India in Mumbai is an iconic monument, symbolizing India's colonial past, built to commemorate the visit of King George V. \n \n available seats : 100 \n   days : 2 days/1 night \n \n----HOTEL NAME : OBERA \n--------------------------------------------"},

           {"Delhi : \n"
                "Delhi, the capital city of India, is a bustling metropolis known for its historical monuments, vibrant markets, and rich cultural heritage.\n \n available seats : 50 \n   days : 3 days/2 night \n \n ----HOTEL NAME : HOTEL AJANTA \n-------------------------------------------"},

           {"Ooty : \n"
                "Ooty, located in the Nilgiri hills, is a serene hill station known for its lush greenery, tea gardens, and pleasant weather.\n \n available seats : 40  \n   days : 4 days/3 night \n \n-------HOTEL NAME :  GEM PARK OOTY \n------------------------------------------------------- "},

           {"Darjeeling : \n"
                "Darjeeling, known as the 'Queen of the Hills,' is famous for its scenic tea plantations, vibrant culture, and stunning views of the Kanchenjunga.\n \n available seats : 80  \n   days : 4 days/3 night \n \n-----HOTEL NAME : HOTEL ROYAL \n-------------------------------------"},
                
           {"Shimla : \n"
                "Shimla is a popular hill station known for its colonial architecture, scenic landscapes, and pleasant weather, located in Himachal Pradesh.\n \n available seats : 90 \n   days : 3 days/2 night \n \n------HOTEL NAME : THE GREEN PARK SHIMLA \n-------------------------------------------"}
            
        };

        cout << "Available Tours:\n";
        for (int i = 0; i < 11; i++) {
            cout << i + 1 << ". " << toursList[i].destination << endl;
            cout << "   " << toursList[i].description << endl;
            cout << "   Available Seats: " << toursList[i].totalSeats << endl;
            cout << "----------------------------------------------------------\n";
        }
    }

    void bookAvailableTour() {
        string destinations[] = {"Varanasi", "Golden Temple", "Hampi", "Kedarnath", "Mysore Palace", "Taj Mahal", 
                                  "Gateway of India", "Delhi", "Ooty", "Darjeeling", "Shimla"};
        float prices[] = {20000.0, 25000.0, 32000.0, 45000.0, 3800.0, 10000.0, 5000.0, 9500.0, 40000.0, 40000.0, 30000.0};

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

        Tourist tourist;
        cin.ignore();  
        tourist.inputTouristInfo();

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
};

// Function for login page
bool login() {
    string username;
    string password;

    string validUsername = "tour";
    string validPassword = "tour123";

    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    if (username == validUsername && password == validPassword) {
        return true;
    } else {
        cout << "Invalid username or password. Please try again." << endl;
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
        cout << "7. Exit\n";
        cout << "----------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

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
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
