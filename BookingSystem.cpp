//
// Created by neved on 05/10/2023.
//

#include <iostream>
#include "BookingSystem.h"

using namespace std;


void hookCALL(string a, int x, int y, int z) {
    cout << "Function called! " << a << endl;
    if (x != 0) cout << "Parameter passed! " << x << endl;
    cout << "Previous value! " << y << " New value! " << z << endl;
}

void dumpStartData(string name, int totalWindowsLaptops, int totalMacBooks) {
    cout << "New class of BookingSystem created!" << endl;
    cout << "Name            : " << name << endl;
    cout << "Windows Laptops : " << totalWindowsLaptops << endl;
    cout << "MacBooks        : " << totalMacBooks << endl;
}

BookingSystem::BookingSystem() {
    name = "Trinity Laptop Bookings";
    totalWindowsLaptops = 20;
    totalMacBooks = 20;
    availableWindowsLaptops = 20;
    availableMacBooks = 20;
}

BookingSystem::BookingSystem(string name, int totalWindowsLaptops, int totalMacBooks) {
    DEBUG_LOGGING ? dumpStartData(name, totalWindowsLaptops, totalMacBooks) : void();
    // Check name length isn't longer than 64
    if (name.length() > 64) name = name.substr(0, 64);
    // Check totalWindowsLaptops and totalMacBooks are >= 0
    if (totalWindowsLaptops < 0) totalWindowsLaptops = 0;
    if (totalMacBooks < 0) totalMacBooks = 0;
    // Set our private class variables
    this->name = name;
    this->totalWindowsLaptops = totalWindowsLaptops;
    this->totalMacBooks = totalMacBooks;
    availableWindowsLaptops = totalWindowsLaptops;
    availableMacBooks = totalMacBooks;
}

// RentWindowsLaptop if availableWindowsLaptops > 0
bool BookingSystem::RentWindowsLaptop() {
    if (availableWindowsLaptops > 0) {
        DEBUG_LOGGING ? hookCALL(__FUNCTION__, 0, availableWindowsLaptops, availableWindowsLaptops - 1) : void();
        availableWindowsLaptops--;
        return true;
    } else if (DEBUG_LOGGING) {
        cout << "ERR: " << __FUNCTION__ << " CONDITIONAL FAIL!!" << endl;
    }
    return false;
}

// RentMacBook if availableMacBooks > 0
bool BookingSystem::RentMacBook() {
    if (availableMacBooks > 0) {
        DEBUG_LOGGING ? hookCALL(__FUNCTION__, 0, availableMacBooks, availableMacBooks - 1) : void();
        availableMacBooks--;
        return true;
    } else if (DEBUG_LOGGING) {
        cout << "ERR: " << __FUNCTION__ << " CONDITIONAL FAIL!!" << endl;
    }
    return false;
}

// ReturnWindowsLaptop and check totalWindowsLaptops is correct
void BookingSystem::ReturnWindowsLaptop() {
    if (availableWindowsLaptops < totalWindowsLaptops) {
        DEBUG_LOGGING ? hookCALL(__FUNCTION__, 0, availableWindowsLaptops, availableWindowsLaptops + 1) : void();
        availableWindowsLaptops++;
    } else if (DEBUG_LOGGING) {
        cout << "ERR: " << __FUNCTION__ << " CONDITIONAL FAIL!!" << endl;
    }
}

// ReturnMacBook and check totalMacBooks is correct
void BookingSystem::ReturnMacBook() {
    if (availableMacBooks < totalMacBooks) {
        DEBUG_LOGGING ? hookCALL(__FUNCTION__, 0, availableMacBooks, availableMacBooks + 1) : void();
        availableMacBooks++;
    } else if (DEBUG_LOGGING) {
        cout << "ERR: " << __FUNCTION__ << " CONDITIONAL FAIL!!" << endl;
    }
}

// Return name string
string BookingSystem::getName() {
    return name;
}

// Return totalWindowsLaptops
unsigned int BookingSystem::getTotalWindowsLaptops() {
    return totalWindowsLaptops;
}

// Return totalMacBooks
unsigned int BookingSystem::getTotalMacBooks() {
    return totalMacBooks;
}

// Return availableWindowsLaptops
unsigned int BookingSystem::getAvailableWindowsLaptops() {
    return availableWindowsLaptops;
}

// Return availableMacBooks
unsigned int BookingSystem::getAvailableMacBooks() {
    return availableMacBooks;
}

// Return availableWindowsLaptops + availableMacBooks
unsigned int BookingSystem::getAvailableLaptops() {
    return availableWindowsLaptops + availableMacBooks;
}

// Return currently rented Windows laptops
unsigned int BookingSystem::getRentedWindowsLaptops() {
    return totalWindowsLaptops - availableWindowsLaptops;
}

// Return currently rented MacBooks
unsigned int BookingSystem::getRentedMacBooks() {
    return totalMacBooks - availableMacBooks;
}

// Return total number of rented laptops
unsigned int BookingSystem::getRentedLaptops() {
    return getRentedWindowsLaptops() + getRentedMacBooks();
}

// Add a Windows laptop
void BookingSystem::addWindowsLaptops(unsigned int additionalWindowsLaptops) {
    DEBUG_LOGGING ? hookCALL(__FUNCTION__, additionalWindowsLaptops, availableWindowsLaptops, availableWindowsLaptops + additionalWindowsLaptops) : void();
    totalWindowsLaptops += additionalWindowsLaptops;
    availableWindowsLaptops += additionalWindowsLaptops;
}

// Add a MacBook
void BookingSystem::addMacBooks(unsigned int additionalMacBooks) {
    DEBUG_LOGGING ? hookCALL(__FUNCTION__, additionalMacBooks, availableMacBooks, availableMacBooks + additionalMacBooks) : void();
    totalMacBooks += additionalMacBooks;
    availableMacBooks += additionalMacBooks;
}

// Remove a Windows laptop
void BookingSystem::removeWindowsLaptops(unsigned int removedWindowsLaptops) {
    bool failed = true;
    DEBUG_LOGGING ? hookCALL(__FUNCTION__, removedWindowsLaptops, availableWindowsLaptops, availableWindowsLaptops - removedWindowsLaptops) : void();
    if (removedWindowsLaptops <= availableWindowsLaptops) {
        totalWindowsLaptops -= removedWindowsLaptops;
        availableWindowsLaptops -= removedWindowsLaptops;
        failed = false;
    } else if (DEBUG_LOGGING) {
        cout << "ERR: " << __FUNCTION__ << " CONDITIONAL FAIL!!" << endl;
    }
    if (failed) {
        totalWindowsLaptops -= availableWindowsLaptops;
        availableWindowsLaptops -= availableWindowsLaptops;
    }
}

// Remove a MacBook
void BookingSystem::removeMacBooks(unsigned int removedMacBooks) {
    bool failed = true;
    DEBUG_LOGGING ? hookCALL(__FUNCTION__, removedMacBooks, availableMacBooks, availableMacBooks - removedMacBooks) : void();
    if (removedMacBooks <= availableMacBooks) {
        totalMacBooks -= removedMacBooks;
        availableMacBooks -= removedMacBooks;
        failed = false;
    } else if (DEBUG_LOGGING) {
        cout << "ERR: " << __FUNCTION__ << " CONDITIONAL FAIL!!" << endl;
    }
    if (failed) {
        totalMacBooks -= availableMacBooks;
        availableMacBooks -= availableMacBooks;
    }
}

// Print full report of all current values
void BookingSystem::PrintReport() {
    cout << "---------------------" << endl;
    cout << "Laptop Booking System" << endl;
    cout << "---------------------" << endl;
    cout << "Name                      : " << name << endl;
    cout << "Total Windows Laptops     : " << totalWindowsLaptops << endl;
    cout << "Total MacBooks            : " << totalMacBooks << endl;
    cout << "Rented Windows Laptops    : " << getRentedWindowsLaptops() << endl;
    cout << "Rented MacBooks           : " << getRentedMacBooks() << endl;
    cout << "Rented Laptops            : " << getRentedLaptops() << endl;
    cout << "Available Windows Laptops : " << availableWindowsLaptops << endl;
    cout << "Available MacBooks        : " << availableMacBooks << endl;
    cout << "Available Laptops         : " << availableWindowsLaptops + availableMacBooks << endl;
}
