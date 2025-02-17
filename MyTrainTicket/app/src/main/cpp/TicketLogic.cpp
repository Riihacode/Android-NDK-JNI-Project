//
// Created by ACER on 17/02/2025.
//

#include "TicketLogic.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int seats[10][5] = {
        {1, 1, 0 ,1, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
};

string getSeatStatus(int row, int col);
int calculateTotalPrice(int pricePerTicket, int numberOfTickets);
int calculateFactorial(int n);
int searchSeat(int target);
vector<int> sortSeats(vector<int> seats);