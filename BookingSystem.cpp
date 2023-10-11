//
// Created by neved on 05/10/2023.
//

#include <iostream>
#include "BookingSystem.h"

using namespace std;

BookingSystem::BookingSystem() {
    name = "Trinity Laptop Bookings";
    totalWindowsLaptops = 20;
    totalMacBooks = 20;
    availableWindowsLaptops = 20;
    availableMacBooks = 20;
}

BookingSystem::BookingSystem(string name, int totalWindowsLaptops, int totalMacBooks) {
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
        availableWindowsLaptops--;
        return true;
    }
    return false;
}

// RentMacBook if availableMacBooks > 0
bool BookingSystem::RentMacBook() {
    if (availableMacBooks > 0) {
        availableMacBooks--;
        return true;
    }
    return false;
}

// ReturnWindowsLaptop and check totalWindowsLaptops is correct
void BookingSystem::ReturnWindowsLaptop() {
    if (availableWindowsLaptops < totalWindowsLaptops) {
        availableWindowsLaptops++;
    }
}

// ReturnMacBook and check totalMacBooks is correct
void BookingSystem::ReturnMacBook() {
    if (availableMacBooks < totalMacBooks) {
        availableMacBooks++;
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
    totalWindowsLaptops += additionalWindowsLaptops;
    availableWindowsLaptops += additionalWindowsLaptops;
}

// Add a MacBook
void BookingSystem::addMacBooks(unsigned int additionalMacBooks) {
    totalMacBooks += additionalMacBooks;
    availableMacBooks += additionalMacBooks;
}

// Remove a Windows laptop
void BookingSystem::removeWindowsLaptops(unsigned int removedWindowsLaptops) {
    if (removedWindowsLaptops <= totalWindowsLaptops) {
        totalWindowsLaptops -= removedWindowsLaptops;
        availableWindowsLaptops -= removedWindowsLaptops;
    }
}

// Remove a MacBook
void BookingSystem::removeMacBooks(unsigned int removedMacBooks) {
    if (removedMacBooks <= totalMacBooks) {
        totalMacBooks -= removedMacBooks;
        availableMacBooks -= removedMacBooks;
    }
}

// Print full report of all current values
void BookingSystem::PrintReport() {
    cout << "---------------------" << endl;
    cout << "Laptop Booking System" << endl;
    cout << "---------------------" << endl;
    cout << "Name                      : " << name <, endl;
    cout << "Total Windows Laptops     : " << totalWindowsLaptops << endl;
    cout << "Total MacBooks            : " << totalMacBooks << endl;
    cout << "Rented Windows Laptops    : " << getRentedWindowsLaptops() << endl;
    cout << "Rented MacBooks           : " << getRentedMacBooks() << endl;
    cout << "Rented Laptops            : " << getRentedLaptops() << endl;
    cout << "Available Windows Laptops : " << availableWindowsLaptops << endl;
    cout << "Available MacBooks        : " << availableMacBooks << endl;
    cout << "Available Laptops         : " << availableWindowsLaptops + availableMacBooks << endl;
}
