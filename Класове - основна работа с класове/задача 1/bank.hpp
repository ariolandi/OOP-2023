#ifndef __BANK__
#define __BANK__
#include <cstring>
#include "bankAccount.hpp"
const int BANK_ACCOUNTS_COUNT = 20;
const int INVALID_INDEX = -1;

class Bank {
    BankAccount bank_accounts[20];
    int count;

    int find_bank_account_index(const char* IBAN) const;
    void remove_account(const int index);

public:
    Bank();
    Bank(const int count, const BankAccount* bank_accounts);

    void add_bank_account(const BankAccount &new_bank_account);

    void withdraw(const char* IBAN, const char* password, const double ammount);
    void deposit(const char* IBAN, const char* password, const double ammount);
};


Bank::Bank() {
    this->count = 0;
}

Bank::Bank(const int count, const BankAccount* bank_accounts) {
    this->count = count;

    for (int i = 0; i < count; i++) {
        this->bank_accounts[i] = bank_accounts[i];
    }
}


int Bank::find_bank_account_index(const char* IBAN) const {
    for (int i = 0; i < this->count; i++) {
        if(!strcmp(this->bank_accounts[i].get_IBAN(), IBAN)) return i;
    }

    return INVALID_INDEX;
}

void Bank::remove_account(const int index) {
    this->count --;

    for (int i = index; i < this->count; i++) {
        this->bank_accounts[i] = this->bank_accounts[i + 1];
    }
}

void Bank::add_bank_account(const BankAccount &new_bank_account) {
    if (this->count == BANK_ACCOUNTS_COUNT) {
        throw std::logic_error("This bank has no more space!");
    }
    
    int index = find_bank_account_index(new_bank_account.get_IBAN());
    if (index != INVALID_INDEX) {
        throw std::logic_error("Bank account with this IBAN already exists!");
    }

    this->bank_accounts[this->count] = new_bank_account;
    this->count++;
}

void Bank::withdraw(const char* IBAN, const char* password, const double ammount) {
    int index = find_bank_account_index(IBAN);
    if (index == INVALID_INDEX) {
        throw std::logic_error("Bank account with this IBAN does not exist!");
    }

    this->bank_accounts[index].withdraw(IBAN, password, ammount);

    if (this->bank_accounts[index].get_balance() < 0) remove_account(index);
}

void Bank::deposit(const char* IBAN, const char* password, const double ammount) {
    int index = find_bank_account_index(IBAN);
    if (index == INVALID_INDEX) {
        throw std::logic_error("Bank account with this IBAN does not exist!");
    }

    this->bank_accounts[index].deposit(IBAN, password, ammount);
}


#endif // __BANK__