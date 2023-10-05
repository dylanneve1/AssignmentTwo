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
    if (name.length() > 64) {
        name = name.substr(0, 64);
    }
    this->name = name;
    this->totalWindowsLaptops = totalWindowsLaptops;
    this->totalMacBooks = totalMacBooks;
    availableWindowsLaptops = totalWindowsLaptops;
    availableMacBooks = totalMacBooks;
}

bool BookingSystem::RentWindowsLaptop() {
    if (availableWindowsLaptops > 0) {
        availableWindowsLaptops--;
        return true;
    }
    return false;
}

bool BookingSystem::RentMacBook() {
    if (availableMacBooks > 0) {
        availableMacBooks--;
        return true;
    }
    return false;
}

void BookingSystem::ReturnWindowsLaptop() {
    availableWindowsLaptops++;
}

void BookingSystem::ReturnMacBook() {
    availableMacBooks++;
}

string BookingSystem::getName() {
    return name;
}

unsigned int BookingSystem::getTotalWindowsLaptops() {
    return totalWindowsLaptops;
}

unsigned int BookingSystem::getTotalMacBooks() {
    return totalMacBooks;
}

unsigned int BookingSystem::getAvailableWindowsLaptops() {
    return availableWindowsLaptops;
}

unsigned int BookingSystem::getAvailableMacBooks() {
    return availableMacBooks;
}

unsigned int BookingSystem::getAvailableLaptops() {
    return availableWindowsLaptops + availableMacBooks;
}

unsigned int BookingSystem::getRentedWindowsLaptops() {
    return totalWindowsLaptops - availableWindowsLaptops;
}

unsigned int BookingSystem::getRentedMacBooks() {
    return totalMacBooks - availableMacBooks;
}

unsigned int BookingSystem::getRentedLaptops() {
    return getRentedWindowsLaptops() + getRentedMacBooks();
}

void BookingSystem::addWindowsLaptops(unsigned int additionalWindowsLaptops) {
    totalWindowsLaptops += additionalWindowsLaptops;
    availableWindowsLaptops += additionalWindowsLaptops;
}

void BookingSystem::addMacBooks(unsigned int additionalMacBooks) {
    totalMacBooks += additionalMacBooks;
    availableMacBooks += additionalMacBooks;
}

void BookingSystem::removeWindowsLaptops(unsigned int removedWindowsLaptops) {
    if (removedWindowsLaptops <= totalWindowsLaptops) {
        totalWindowsLaptops -= removedWindowsLaptops;
        availableWindowsLaptops -= removedWindowsLaptops;
    }
}

void BookingSystem::removeMacBooks(unsigned int removedMacBooks) {
    if (removedMacBooks <= totalMacBooks) {
        totalMacBooks -= removedMacBooks;
        availableMacBooks -= removedMacBooks;
    }
}

void BookingSystem::PrintReport() {
    cout << "Booking System Report for " << name << endl;
    cout << "Total Windows Laptops: " << totalWindowsLaptops << endl;
    cout << "Total MacBooks: " << totalMacBooks << endl;
    cout << "Rented Windows Laptops: " << getRentedWindowsLaptops() << endl;
    cout << "Rented MacBooks: " << getRentedMacBooks() << endl;
    cout << "Rented Laptops: " << getRentedLaptops() << endl;
    cout << "Available Windows Laptops: " << availableWindowsLaptops << endl;
    cout << "Available MacBooks: " << availableMacBooks << endl;
    cout << "Available Laptops: " << availableWindowsLaptops + availableMacBooks << endl;
}
