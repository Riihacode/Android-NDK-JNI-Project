//
// Created by ACER on 17/02/2025.
//

#ifndef MY_TRAIN_TICKET_TICKETLOGIC_H
#define MY_TRAIN_TICKET_TICKETLOGIC_H

#include <string>
#include <vector>

using namespace std;

struct Ticket {
    int id;
    string name;
    int seatNumber;
};

string getSeatStatus(int row, int col);
int calculateTotalPrice(int pricePerTicket, int numberOfTickets);
int calculateFactorial(int n);
int searchSeat(int target);
vector<int> sortSeats(vector<int> seats);

#endif //MY_TRAIN_TICKET_TICKETLOGIC_H
