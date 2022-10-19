/* 
 Name: Nikita Dubinin 
 Class: CPCS 121, Fall 2022 
 Date: September 14, 2022 
 Programming Assignment: PA1                                                                       
 Description: Calculation cost of the trip
 Notes: -
*/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main (void) {

string origin, destination;
int numDays , numTickets;
double ticketPrice , carPerDayCost , foodPerDayBudget , subtotal , total , virAgentFee , dailyCost;
const int HRS_IN_DAY = 24;

cout << "Hi! This is Skippy, your virtual travel agent. I'm here to help you with the calculation of your's travel cost" << endl;
cout << "Where do you want to travel?" << endl;

getline(cin , destination);

cout << "Oh! " << destination << " is a really interesting place for travelers, it's one of my favorite places on the earth!" << endl;
cout << "Where are you leaving from?" << endl;

getline(cin , origin);

cout << origin << " is a good place to live! I want to visit it in the future." << endl;
cout << "How many days will you be there?" << endl;

cin >> numDays;

cout << "You want to be in " << destination << " for " << numDays * HRS_IN_DAY << " hours? I wish you to complete everything you want there!" << endl;
cout << "What's the ticket price?" << endl;

cin >> ticketPrice;

cout << "And how many tickets do you want?" << endl;

cin >> numTickets;

cout << "Okay, I found " << numTickets << " tickets to " << destination << " for " << ticketPrice << "$! Let's continue, there are only a few steps left!" << endl;
cout << "What's the price of car rent in " << destination << " ?" << endl;

cin >> carPerDayCost;

cout << "Oh wow, " << carPerDayCost << "$ is really expensive, are you sure that you don't want to use a taxi?" << endl;
cout << "How much money do you pawn for the daily food costs?" << endl;

cin >> foodPerDayBudget;

cout << "That's all, now I need couple of seconds to calculate all costs." << endl;

subtotal = ticketPrice * numTickets + carPerDayCost * numDays + foodPerDayBudget * numDays; // Subtotal calculation
virAgentFee = pow(subtotal , 3./5); // Virtual agent fee calculation
total = subtotal + virAgentFee;
dailyCost = total/numDays;

if (virAgentFee >= subtotal * 0.04) { // Works if virtual agent fee is >= than 4% of subtotal
    cout << "Wow, it will be very expencive trip!" << endl;
}

cout << "Appreciate your time! Your trip from " << origin << " to " << destination << " will cost you " << total << "$ dollars in total or " << dailyCost << "$ per day!" << endl;
cout << "Thank you for using Virtual Travel Agent! My name is still Skippy and I wish you a good trip!" << endl;


return 0;
}