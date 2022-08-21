#include <iostream>
#include <iomanip>

using namespace std;

double speedAdd(int speedLimit, int speed, double BASE_TICKET_FINE);
int SpeedLimit();

int main()
{
    // set base fine and set answer variable
    const double BASE_TICKET_FINE = 60.25;
    char answer = 'y';
    
    while (answer == 'Y' || answer == 'y')  {
        int speedLimit;
        
	// call speedLimit method for randomly set speed
        speedLimit = SpeedLimit();
        cout << "\nThe speed limit is: " << speedLimit << endl;
    
        int speed;
        cout << "Please enter the speed of the driver: " << endl;
        cin >> speed;
    
        cout << "\nThe speed limit is " << speedLimit << endl;
        cout << "The driver's speed was " << speed << endl;
    
        if (speed <= speedLimit) {
            cout << "Driver was not speeding!" << endl;
        }
    
        else {
            double fine = speedAdd(speedLimit, speed, BASE_TICKET_FINE);
        
	    // format the fine for final output
            std::cout << std::fixed;
            std::cout << std::setprecision(2);
            std::cout <<  "The fine is: " << fine << endl;
        }
        
        cout << "\nWould you like to enter another speeding violation?" << endl;
        cin >> answer;
    }
    
    
    
}


double speedAdd(int speedLimit, int speed, double BASE_TICKET_FINE) {
    int overLimit = speed - speedLimit;
    
    if (overLimit <= 5) {
        double ticketCost = BASE_TICKET_FINE * 0;
        return ticketCost += BASE_TICKET_FINE;
    }
    
    else if (overLimit > 5 && overLimit <= 10) {
        double ticketCost = BASE_TICKET_FINE * .05;
        return ticketCost += BASE_TICKET_FINE;
    }
    
    else if (overLimit > 10 && overLimit <= 20) {
        double ticketCost = BASE_TICKET_FINE * .1;
        return ticketCost += BASE_TICKET_FINE;
    }
    
    else if (overLimit > 20) {
         double ticketCost = BASE_TICKET_FINE * .2;
         return ticketCost += BASE_TICKET_FINE;
    }
    
    else {
        return 0;
    }
    
}

int SpeedLimit() {
    int speedLimit = rand() % 65 + 25;
    return speedLimit;
}
