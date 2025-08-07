#include <iostream>
#include <cstring>

using namespace std;

class Event {
private:
    char* event_name;
    char* event_venue;
    char event_date[11];
    char event_time[9];

public:
    // Default constructor
    Event() {
        event_name = NULL;
        event_venue = NULL;
        strcpy(event_date, "");
        strcpy(event_time, "");
        cout << "Default Constructor Called" << endl;
    }

    // Overloaded constructor
    Event(char event_name[], char event_venue[], char event_date[], char event_time[]) {
        int name_length = strlen(event_name) + 1;
        this->event_name = new char[name_length];
        strcpy(this->event_name, event_name);

        int venue_length = strlen(event_venue) + 1;
        this->event_venue = new char[venue_length];
        strcpy(this->event_venue, event_venue);

        strcpy(this->event_date, event_date);
        strcpy(this->event_time, event_time);

        cout << "Overloaded Constructor Called" << endl;
    }

    // Destructor
    ~Event() {
        delete[] event_name;
        delete[] event_venue;
        cout << "Destructor Called" << endl;
    }

    // Setter functions
    void setEventName(char new_name[]) {
        delete[] event_name;
        int name_length = strlen(new_name) + 1;
        event_name = new char[name_length];
        strcpy(event_name, new_name);
    }

    void setEventVenue(char new_venue[]) {
        delete[] event_venue;
        int venue_length = strlen(new_venue) + 1;
        event_venue = new char[venue_length];
        strcpy(event_venue, new_venue);
    }

    void setEventDate(char new_date[]) {
        strcpy(event_date, new_date);
    }

    void setEventTime(char new_time[]) {
        strcpy(event_time, new_time);
    }

    // Getter functions
    char* getEventName() {
        return event_name;
    }

    char* getEventVenue() {
        return event_venue;
    }

    char* getEventDate() {
        return event_date;
    }

    char* getEventTime() {
        return event_time;
    }
};

int main() {
    Event event("OOP LAB-06", "Google Classroom", "17-07-2023", "05:00 PM");
    event.setEventName("OOP LAB-QUIZ");

    cout << "Event Name: " << event.getEventName() << endl;
    cout << "Event Venue: " << event.getEventVenue() << endl;
    cout << "Event Date: " << event.getEventDate() << endl;
    cout << "Event Time: " << event.getEventTime() << endl;

    return 0;
}

