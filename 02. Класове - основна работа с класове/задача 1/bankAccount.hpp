#ifndef _BANK_ACCOUNT_
#define _BANK_ACCOUNT_
#include <cstring>
#include <exception>
const int STRLEN = 21;
const int MINIMUM_PASSWORD_STRLEN = 5;


class BankAccount {
    char IBAN[STRLEN];
    char password[STRLEN];
    double balance;

    // Тези методи ще бъдат използвани вътре в класа и не очакваме да можем да ги достъпим извън него
    void set_password(const char* password);
    bool autenticate(const char* IBAN, const char* password) const;
    void transfer(const char* IBAN, const char* password, const double ammount);

public:
    BankAccount(const char* IBAN, const double balance, const char* password);

    void withdraw(const char* IBAN, const char* password, const double ammount);
    void deposit(const char* IBAN, const char* password, const double ammount);

    double get_balance () const;
    const char* get_IBAN () const; 
};


/* 
   Важно е да запомним, че стойност по подразбиране на аргументите на конструктури и методи
   се задава само веднъж - или при декларацията, или при дефиницията им. 
*/
BankAccount::BankAccount(const char* IBAN = "", const double balance = 0, const char* password = "     ") {
    set_password(password);
    strcpy(this->IBAN, IBAN);
    this->balance = balance;
}


// Използваме допълнителен метод за валидация на данните там, където се налага
void BankAccount::set_password(const char* password) {
    if (strlen(password) < MINIMUM_PASSWORD_STRLEN || strlen(password) > STRLEN - 1) {
        throw std::invalid_argument("The password must be between 5 and 20 symbols");
    }

    strcpy(this->password, password);
}

bool BankAccount::autenticate(const char* IBAN, const char* password) const {
    return (!strcmp(this->IBAN, IBAN) && !strcmp(this->password, password));
}

void BankAccount::transfer(const char* IBAN, const char* password, const double ammount) {
    if (!autenticate(IBAN, password)) {
        throw std::logic_error("Bank account authentication failed!");
    }

    this->balance += ammount;
}

void BankAccount::withdraw(const char* IBAN, const char* password, const double ammount) {
    double to_withdraw = -1 * ammount;
    transfer(IBAN, password, to_withdraw);
}

void BankAccount::deposit(const char* IBAN, const char* password, const double ammount) {
    transfer(IBAN, password, ammount);
}

double BankAccount::get_balance () const {
    return this->balance;
}

const char* BankAccount::get_IBAN () const {
    return this->IBAN;
}




#endif  // _BANK_ACCOUNT_
