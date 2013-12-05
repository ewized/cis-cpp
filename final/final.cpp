/*
    Filename: final.cpp
    Problem: Final
    Description: Rabbit vs Turtle, They race and then one wins.
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 12/03/2013
*/
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Field Size
const int FIELD = 70;
typedef char* Field;

// Animal class
class Animal {
    public:
        // Constructors
        Animal(int);
        Animal();
        // Function members
        int get_posistion();
        char get_display();
        string get_name();
        void add_posistion(int);
        void remove_posistion(int);
    private:
        string name;
        char display;
        int posistion;      // The index for where the animal is.
};

// Set up the class with animal type.
Animal::Animal(int type) {
    switch (type) {
        case 1:
            posistion = 0;
            name = "Turtle";
            display = 'T';
            break;
        case 0:
            posistion = 0;
            name = "Hare";
            display = 'H';
            break;
    }
    //cout << "P: " << posistion << endl << "N: " << name << endl << "D: " << display << endl;
}

// The default constructor for Animal.
// Set the animal to hare.
Animal::Animal() {
    posistion = 0;
    name = "Hare";
    display = 'H';
}

// Get the position of the animal in a number.
int Animal::get_posistion() {
    return posistion;
}

// Get the display char of the animal.
char Animal::get_display() {
    return display;
}

// Get the name of the animal.
string Animal::get_name() {
    return name;
}

// Add the amount to the index.
void Animal::add_posistion(int amount) {
    posistion = posistion + amount;
}

// Remove the amount from the index.
void Animal::remove_posistion(int amount) {
    if (posistion-amount < 0)
        posistion = 0;
    else
        posistion = posistion - amount;
}

// Functions
void print_field(int, Animal&, Animal&);
void start();
void tick(int);
void move(Animal&);
bool winner(Animal&, Animal&);

// Print the field
void print_field(int size, Animal& one, Animal& two) {
    // Set up the enviroment
    Field field = new char[size];
    for (int i = 0; i < size; i++)
        field[i] = ' ';
    int one_pos = one.get_posistion();
    int two_pos = two.get_posistion();
    if (one_pos == two_pos)
        field[one_pos] = 'O';
    else {
        field[one.get_posistion()] = one.get_display();
        field[two.get_posistion()] = two.get_display();
    }
    // Display the field.
    // TOP LINE
    for (int i = 0 ; i < size; i++)
        cout << "-";
    cout << endl;
    // TRACK
    for (int i = 0 ; i < size; i++)
        cout << field[i];
    cout << endl;
    // BOTTOM LINE PLUS GUIDE
    for (int i = 0 ; i < size; i++)
        cout << "-";
    cout << endl;
    cout << one.get_display() << " = " << one.get_name() << " | ";
    cout << two.get_display() << " = " << two.get_name() << " | ";
    cout << "O = Ouch" << endl;
    // Blank
    cout << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl;
}

// Start the race
void start() {
    cout << "BANG!!!" << endl;
    cout <<  "AND THEY'RE OFF!!!" << endl;
}

// Ticks to wait
void tick(int wait) {
    long current_time = time(0);
    long wait_time = current_time + wait;

    while (current_time < wait_time) {
        current_time = time(0);
    }
}

// Move the animal
void move(Animal& animal) {
    int r = rand() % 10 + 1;
    if (animal.get_display() == 'H') { // Hare
        switch (r) {
            // 10% big slip
            case 1:
                animal.remove_posistion(12);
                break;
            // 20% sleep
            case 2:
            case 3:
                break;
            // 20% big hop
            case 4:
            case 5:
                animal.add_posistion(9);
                break;
            // 20% small slip
            case 6:
            case 7:
                animal.remove_posistion(2);
                break;
            // 30% small hop
            default:
                animal.add_posistion(1);
                break;
        }
    }
    else if (animal.get_display() == 'T') { // Turtle
        switch (r) {
            // 30% slow plod
            case 1:
            case 2:
            case 3:
                animal.add_posistion(1);
                break;
            // 20% slip
            case 4:
            case 5:
                animal.remove_posistion(6);
                break;
            // 50% fast plot
            default:
                animal.add_posistion(3);
                break;
        }
    }
    // DEBUG: cout << animal.get_display() << " : " << r << endl;
}

// Check if and who is the winner
bool winner(Animal& one, Animal& two) {
    bool results = true; // true keep playing, false stop the loop.
    if (one.get_posistion() >= FIELD) {
        cout << one.get_name() << " won! Yawn..." << endl;
        results = false;
    }
    else if (two.get_posistion() >= FIELD) {
        cout << two.get_name() << " won! Yay!!!" << endl;
        results = false;
    }
    else if (two.get_posistion() == FIELD && one.get_posistion() == FIELD) {
        cout << "Tie!" << endl;
        results = false;
    }
    
    return results;
}

// Traveling through time and space like a boss.
int main() {
    // Set up the enviroment
    srand(time(0));
    Animal hare(0), turtle(1);

    // Run the game
    start();
    do {
        print_field(FIELD, hare, turtle);
        move(turtle);
        move(hare);
        tick(1); // Wait one sec
    } while(winner(hare, turtle));

    return 0;
}
