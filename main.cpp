#include "Airline.h"

int main()
{
    Airline al;
    al.addFlight();       //only add two flights for test
    al.addFlight();

    int opt = -1;
    Flight *fl;
    string fn;

    while (true) {
        cout << "Please enter your choices: ";
        cin >> opt;

        switch(opt)
        {
            case 1:                 // display all the flights
                al.displayAll();
                break;
            case 2:                 // book a ticket
                cout << "Please enter flight name: ";
                cin >> fn;
                fl = al.searchFlight(fn);
                if (fl == NULL) {
                    cout << "No related flight" << endl;
                    break;
                }
                fl->display();
                fl->book();
                break;
            case 3:                 // cancel a ticket
                cout << "Please enter flight name: ";
                cin >> fn;
                fl = al.searchFlight(fn);
                if (fl == NULL) {
                    cout << "No related flight" << endl;
                    break;
                }
                fl->cancel();
                fl->display();
                break;
            default:
                cout << "Wrong option. " << endl;
                break;
        }
    }
}
