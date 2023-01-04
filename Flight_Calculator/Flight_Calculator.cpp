#include <iostream>
#include <string>
#include <cmath>
using namespace std;


// A list of 10 american cities with their name, latitudes and longitudes
int NUM_CITIES = 11;
//The cities list from the link was extrememly boring, went with more recognizable cities
string cities[11] = {"Miami Beach, FL, USA", "Fargo, ND, USA","Idaho City, ID, USA","New York, NY, USA", "Los Angeles, CA, USA", "Chicago, IL, USA", "Houston, TX, USA", "Phoenix, AZ, USA", "Philadelphia, PN, USA", "San Antonio, TX, USA", "Raleigh, NC, USA"};
double latitudes[11] = {25.793449, 46.877186, 43.828850, 40.7127, 34.0522, 41.8376, 29.7604, 33.4484, 40.0046, 29.4241, 35.7796};
double longitudes[11] = { -80.139198, -96.789803, -115.837860, -74.0059, -118.2437, -87.6298, -95.3698, -112.0720, -75.1652, -97.5164, 78.6382};

// List all cities with their index, latitudes and longitudes
void list_cities() {
    for (int i = 1; i < NUM_CITIES; i++) {
        cout << i << ": " << cities[i] << " ("
             << latitudes[i] << ", " << longitudes[i] << ")" << endl;
    }
}

// Radisu of the earth will never change, so constant
const double R = 3958.8;

// Choose a random value between 460 and 574 for jet speed
int random_speed() {
    return 460 + rand() % (574 - 460 + 1);
}

// Haverstine function which makes me wonder why I went into engineering
// WHoever made math harder sucks
double heversine(double lat1, double long1, double lat2, double long2, double radius) {
    double dLat = (lat2 - lat1) * M_PI / 180;
    double dLon = (long2 - long1) * M_PI / 180;
    lat1 = lat1 * M_PI / 180;
    lat2 = lat2 * M_PI / 180;

    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double c = 2 * asin(sqrt(a));
    return radius * c;
}

// Calculate flight time in hours between two cities per function requested
double getFlightTime(double lat1, double long1, double lat2, double long2) {
    return heversine(lat1, long1, lat2, long2, R) / random_speed();
}

// Check if the cities are valid
// print a message if the cities are invalid then prompt again
// use haversine to get distance and flight time
// repeat until user enters q
void travel() {
    string origin, destination;
    int origin_index, destination_index;
    while (true) {
        list_cities();
        // prompt user to enter origin city index
        cout << "Enter origin city index or enter q to exit: ";
        cin >> origin;
        if (origin == "q") {
            break;
        }
        // print the entered origin city name
        // print error message if the city index is invalid
        origin_index = stoi(origin);
        if (origin_index < 0 || origin_index >= NUM_CITIES) {
            cout << "Invalid origin city index" << endl;
            continue;
        }else{
            cout << "Origin city: " << cities[origin_index] << endl;
        }

        // Create a new cities, latitudes and longitudes array from the old one
        // remove the provided city index from the new list
        string new_cities[NUM_CITIES - 1];
        double new_latitudes[NUM_CITIES - 1];
        double new_longitudes[NUM_CITIES - 1];
        int index = 1;
        for (int i = 1; i < NUM_CITIES; i++) {
            if (i != origin_index) {
                new_cities[index] = cities[i];
                new_latitudes[index] = latitudes[i];
                new_longitudes[index] = longitudes[i];
                index++;
            }
        }

        for (int i = 1; i < NUM_CITIES - 1; i++) {
            cout << i << ": " << new_cities[i] << " ("
                 << new_latitudes[i] << ", " << new_longitudes[i] << ")" << endl;
        }

        // print line divider
        cout << "Enter destination city or enter q to exit: ";
        cin >> destination;

        if (destination == "q") {
            break;
        }

        // print the entered destination city name from the new list
        // print error message if the city index is invalid
        destination_index = stoi(destination);
        if (destination_index < 0 || destination_index >= NUM_CITIES - 1) {
            cout << "Invalid destination city index" << endl;
            continue;
        }else{
            cout << "Destination city: " << new_cities[destination_index] << endl;
        }


        // print line divider
        cout << "----------------------------------------" << endl;

        // print line divider
        cout << "----------------------------------------" << endl;

        // calculate the distance and flight time between the cities
        double distance = heversine(latitudes[origin_index], longitudes[origin_index],
                                    new_latitudes[destination_index], new_longitudes[destination_index], R);
        double flight_time = getFlightTime(latitudes[origin_index], longitudes[origin_index],
                                           new_latitudes[destination_index], new_longitudes[destination_index]);
        
        // print origin and destination cities
        // print the distance and flight time between the cities
        cout << "Origin city: " << cities[origin_index] << endl;
        cout << "Destination city: " << new_cities[destination_index] << endl;
        // distance in 2 dp
        cout << "Distance: " << distance << " miles" << endl;
        // time in 2 dp
        cout << "Flight time: " << flight_time << " hours" << endl;

        // print line divider
        cout << "----------------------------------------" << endl;
        // print a blank line
        cout << endl;
        // print end
        cout << "End" << endl;  // print end
    }
}


// Print a welcome message then list all cities
// then get user travel information
// then print a goodbye message
int main() {
    cout << "Welcome to the travel calculator. Please select origin and destination" << endl;
    // print line divider
    cout << "----------------------------------------" << endl;
    travel();
    // print line divider
    cout << "----------------------------------------" << endl;
    cout << "Goodbye" << endl;
    // print line divider
    cout << "----------------------------------------" << endl;
    return 0;
}

