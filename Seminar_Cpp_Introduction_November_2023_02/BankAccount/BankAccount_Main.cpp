// ===========================================================================
// BankAccount_Main.cpp
// ===========================================================================

#include "BankAccount.h"

void  exerciseBankAccount()
{
    BankAccount firstAccount;
    firstAccount.print();

    BankAccount secondAccount;
    secondAccount.deposit(50);
    secondAccount.withdraw(25);
    secondAccount.print();

    BankAccount thirdAccount;
    thirdAccount.deposit(100);
    thirdAccount.print();
    thirdAccount.setInterestRate(5.0);
    thirdAccount.updateInterest(365);
    thirdAccount.print();

    if (secondAccount < thirdAccount) {
        std::cout << 
            "Auf Konto " << secondAccount.getAccountNumber() 
            << " ist mehr Geld als auf " << secondAccount.getAccountNumber() 
            << std::endl;
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================
