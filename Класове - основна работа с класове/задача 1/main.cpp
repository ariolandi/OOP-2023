#include <iostream>
#include <cstring>
#include "bankAccount.hpp"
#include "bank.hpp"
using std::cin, std::cout, std::endl;

int main() {
    int n;
    char IBAN[21], password[21];
    double balance, ammount;

    BankAccount bank_accounts[20];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> IBAN >> password >> balance;
        bank_accounts[i] = BankAccount(IBAN, balance, password);
    }

    Bank bank_with_no_accounts;
    bank_with_no_accounts.add_bank_account(bank_accounts[0]);

    Bank bank(n, bank_accounts);

    cin >> IBAN >> password >> ammount;
    bank_accounts->deposit(IBAN, password, ammount);
    bank_accounts->withdraw(IBAN, password, ammount);

    return 0;
}
