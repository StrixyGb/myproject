#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <sstream>
#include "Networks.h"
#include "User.h"
#include "Wallet.h"
#include "UserLogining.h"


void main() {
    User u;
	Userreglog usrlog;
	Wallet wallet;
	int choice;
	int choicew;
    int choose;
    int choosetpup;
	string login, password1, password2;
    int amntusdt;
    int amntbtc;
    int amnteth;
    int choosen;
    do {
        usrlog.menureglog();
        cout << "\nEnter your choice ~~> ";
        cin >> choice;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
            cin >> choice;
        }

        string login, password1, password2;

        switch (choice) {
        case 1:
            cout << "Enter your new login: ";
            cin >> login;
            cout << "Enter new password: ";
            cin >> password1;
            cout << "Rewrite your password: ";
            cin >> password2;
            usrlog.registerUser(login, password1, password2);
            if (usrlog.loginUser(login, password1)) {
                do {

                    cout << "\n\n\t\t    WEB3 WALLET   \n\n"
                        << "\t            Balance: " << wallet.findtotalbalance() << "$\n\n"
                        << "\t   1)Send    2)TopUp     3)Exchange     \n\n"
                        << "\t ____________________________________\n"
                        << "\t USDT                       " << wallet.gettrcbalance() << "USDT " << wallet.findusdtdollar() << "$" << "\n"
                        << "\t BTC                        " << wallet.getbtcbalance() << "BTC  " << wallet.findbtcdollar() << "$" << "\n"
                        << "\t ETH                        " << wallet.getethbalance() << "ETH  " << wallet.findethdollar() << "$" << "\n\n";

                    wallet.displayTransactionHistory();
                    cout << "\nEnter your choice: ";
                    cin >> choicew;
                    switch (choicew)
                    {
                    case 1:
                        cout << "\n\n\t\t    SENDING PAGE     \n\n"
                            "\n\tYour Actives: \n\n"
                            << "\t USDT                       " << wallet.gettrcbalance() << "USDT " << wallet.findusdtdollar() << "$" << "\n"
                            << "\t BTC                        " << wallet.getbtcbalance() << "BTC  " << wallet.findbtcdollar() << "$" << "\n"
                            << "\t ETH                        " << wallet.getethbalance() << "ETH  " << wallet.findethdollar() << "$" << "\n\n";
                        cout << "\nChoose which coin you want to send(USDT -1,BTC - 2,ETH - 3): ";
                        cin >> choose;
                        switch (choose)
                        {
                        case 1:
                            cout << "Enter ammount of USDT you want to transfer: ";
                            cin >> amntusdt;
                            wallet.sendtrc(amntusdt);
                            break;
                        case 2:
                            cout << "Enter ammount of BTC you want to transfer: ";
                            cin >> amntbtc;
                            wallet.sendbtc(amntbtc);

                            break;
                        case 3:
                            cout << "Enter ammount of ETH you want to transfer: ";
                            cin >> amnteth;
                            wallet.sendeth(amnteth);
                            break;
                        default:
                            break;
                        }
                        break;
                    case 2:
                        cout << "\n\n\t\t    TOP-UP PAGE     \n\n"
                            "\nYour Actives: \n\n"
                            << "\t USDT                       " << wallet.gettrcbalance() << "USDT " << wallet.findusdtdollar() << "$" << "\n"
                            << "\t BTC                        " << wallet.getbtcbalance() << "BTC  " << wallet.findbtcdollar() << "$" << "\n"
                            << "\t ETH                        " << wallet.getethbalance() << "ETH  " << wallet.findethdollar() << "$" << "\n\n";
                        cout << "\nChoose wich crypto you want to top-up(USDT -1,BTC - 2,ETH - 3): ";
                        cin >> choosetpup;
                        switch (choosetpup)
                        {
                        case 1:
                            cout << "\n\n\tHere is your USDT(TRC20) adress: \n"
                                "\n\t_________________________________________\n";
                            cout << "\n\t" << u.gettrcadress() << "\n";
                            cout << "\n\nEnter ammount in USDT you want top-up your balance for: ";
                            cin >> amntusdt;
                            wallet.topuptrc(amntusdt);
                            break;
                        case 2:
                            cout << "\n\n\tHere is your BTC(BTC) adress: "
                                "\n\t_________________________________________\n";

                            cout << "\n\t" << u.getbtcadress() << "\n";
                            cout << "\n\nEnter ammount in BTC you want top-up your balance for: ";
                            cin >> amntbtc;
                            wallet.topupbtc(amntbtc);
                            break;
                        case 3:
                            cout << "\n\n\tHere is your ETH(ERC20) adress: \n"
                                "\n\t_________________________________________\n";
                            cout << "\n\t" << u.getethadress() << "\n";
                            cout << "\n\nEnter ammount in ETH you want top-up your balance for: ";
                            cin >> amnteth;
                            wallet.topupeth(amnteth);
                            break;
                        default:
                            break;
                        }
                        break;
                    case 3:
                        cout << "\n\n\t\t    EXCHANGE PAGE     \n\n"
                            "\n\tYour Actives: \n\n"
                            << "\t USDT                       " << wallet.gettrcbalance() << "USDT " << wallet.findusdtdollar() << "$" << "\n"
                            << "\t BTC                        " << wallet.getbtcbalance() << "BTC  " << wallet.findbtcdollar() << "$" << "\n"
                            << "\t ETH                        " << wallet.getethbalance() << "ETH  " << wallet.findethdollar() << "$" << "\n\n";
                        cout << "\nChoose which coin you want to exchange from usdt to(BTC - 1,ETH - 2): ";
                        cin >> choosen;

                        switch (choosen) 
                        {
                        case 1:
                            cout << "Enter usdt amount you want to change to BTC: ";
                            cin >> amntusdt;
                            wallet.exchangeUSDTtoBTC(amntusdt);
                            break;
                        case 2:
                            cout << "Enter usdt amount you want to change to ETH: ";
                            cin >> amntusdt;
                            wallet.exchangeUSDTtoETH(amntusdt);
                        default:
                            break;
                        }
                        /*cout << "Enter usdt amount you want to change to btc: ";
                        cin >> amntusdt;
                        wallet.exchangeUSDTtoBTC(amntusdt);*/
                        break;
                    default:
                        break;
                    }

                } while (choicew != 0);
            }
            break; 
        case 2:
            cout << "\nEnter your login: ";
            cin >> login;
            cout << "\nEnter your password: ";
            cin >> password1;
            usrlog.loginUser(login, password1);
            do {
               cout << "\n\n\t\t    WEB3 WALLET   \n\n"
                    << "\t            Balance: " << wallet.findtotalbalance() << "$\n\n"
                    << "\t   1)Send    2)TopUp     3)Exchange     \n\n"
                    << "\t ____________________________________\n"
                    << "\t USDT                       " << wallet.gettrcbalance() << "USDT " << wallet.findusdtdollar() << "$" << "\n"
                    << "\t BTC                        " << wallet.getbtcbalance() << "BTC  " << wallet.findbtcdollar() << "$" << "\n"
                    << "\t ETH                        " << wallet.getethbalance() << "ETH  " << wallet.findethdollar() << "$" << "\n";
               wallet.displayTransactionHistory();
               cout << "\nEnter your choice: ";
               cin >> choicew;
               switch (choicew)
               {
               case 1:
                   cout << "\n\n\t\t    SENDING PAGE     \n\n"
                       "\n\tYour Actives: \n\n"
                       << "\t USDT                       " << wallet.gettrcbalance() << "USDT " << wallet.findusdtdollar() << "$" << "\n"
                       << "\t BTC                        " << wallet.getbtcbalance() << "BTC  " << wallet.findbtcdollar() << "$" << "\n"
                       << "\t ETH                        " << wallet.getethbalance() << "ETH  " << wallet.findethdollar() << "$" << "\n\n";
                   cout << "\nChoose which coin you want to send(USDT -1,BTC - 2,ETH - 3): ";
                   cin >> choose;
                   switch (choose)
                   {
                   case 1:
                       cout << "Enter ammount of USDT you want to transfer: ";
                       cin >> amntusdt;
                       wallet.sendtrc(amntusdt);
                       break;
                   case 2:
                       cout << "Enter ammount of BTC you want to transfer: ";
                       cin >> amntbtc;
                       wallet.sendbtc(amntbtc);

                       break;
                   case 3:
                       cout << "Enter ammount of ETH you want to transfer: ";
                       cin >> amnteth;
                       wallet.sendeth(amnteth);
                       break;
                   default:
                       break;
                   }
                   break;
               case 2:
                   cout << "\n\n\t\t    TOP-UP PAGE     \n\n"
                       "\nYour Actives: \n\n"
                       << "\t USDT                       " << wallet.gettrcbalance() << "USDT " << wallet.findusdtdollar() << "$" << "\n"
                       << "\t BTC                        " << wallet.getbtcbalance() << "BTC  " << wallet.findbtcdollar() << "$" << "\n"
                       << "\t ETH                        " << wallet.getethbalance() << "ETH  " << wallet.findethdollar() << "$" << "\n\n";
                   cout << "\nChoose wich crypto you want to top-up(USDT -1,BTC - 2,ETH - 3): ";
                   cin >> choosetpup;
                   switch (choosetpup)
                   {
                   case 1:
                       cout << "\n\n\tHere is your USDT(TRC20) adress: \n"
                           "\n\t_________________________________________\n";
                       cout << "\n\t" << u.gettrcadress() << "\n";
                       cout << "\n\nEnter ammount in USDT you want top-up your balance for: ";
                       cin >> amntusdt;
                       wallet.topuptrc(amntusdt);
                       break;
                   case 2:
                       cout << "\n\n\tHere is your BTC(BTC) adress: "
                           "\n\t_________________________________________\n";

                       cout << "\n\t" << u.getbtcadress() << "\n";
                       cout << "\n\nEnter ammount in BTC you want top-up your balance for: ";
                       cin >> amntbtc;
                       wallet.topupbtc(amntbtc);
                       break;
                   case 3:
                       cout << "\n\n\tHere is your ETH(ERC20) adress: \n"
                           "\n\t_________________________________________\n";
                       cout << "\n\t" << u.getethadress() << "\n";
                       cout << "\n\nEnter ammount in ETH you want top-up your balance for: ";
                       cin >> amnteth;
                       wallet.topupeth(amnteth);
                       break;
                   default:
                       break;
                   }
                   break;
               case 3:
                   cout << "\n\n\t\t    EXCHANGE PAGE     \n\n"
                       "\n\tYour Actives: \n\n"
                       << "\t USDT                       " << wallet.gettrcbalance() << "USDT " << wallet.findusdtdollar() << "$" << "\n"
                       << "\t BTC                        " << wallet.getbtcbalance() << "BTC  " << wallet.findbtcdollar() << "$" << "\n"
                       << "\t ETH                        " << wallet.getethbalance() << "ETH  " << wallet.findethdollar() << "$" << "\n\n";
                   cout << "\nChoose which coin you want to exchange from usdt to(BTC - 1,ETH - 2): ";
                   cin >> choosen;

                   switch (choosen)
                   {
                   case 1:
                       cout << "Enter usdt amount you want to change to BTC: ";
                       cin >> amntusdt;
                       wallet.exchangeUSDTtoBTC(amntusdt);
                       break;
                   case 2:
                       cout << "Enter usdt amount you want to change to ETH: ";
                       cin >> amntusdt;
                       wallet.exchangeUSDTtoETH(amntusdt);
                   default:
                       break;
                   }
                   break;
               default:
                   break;
               }
            } while (choicew !=0);
            break;
        case 3:
            exit(0); 
            break;
        default:
            cerr << "Invalid choice." << endl;
            break;
        }
    } while (true);
	
	
}
	


