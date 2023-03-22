#include <iostream>
#include <cstring>
#include <stdexcept>
using std::cin, std::cout, std::endl;

struct Product {
    char product_name[51];
    double amount;
    char metric;

    void read() {
        cout << "product, ammount and metric (l - liter, g - gr, c - count): "; 
        cin >> product_name >> amount >> metric;
    }

    void print() const {
        cout << product_name << ": " << amount << " " << metric << endl;
    }
};

struct ProductList {
    int product_count;
    Product list[100];

    void read() {
        cout << "Products count: "; 
        cin >> product_count;

        for(int i = 0; i < product_count; i++) {
            list[i].read();
        }
    }

    void print() const {
        cout << "Products:" << endl;

        for(int i = 0; i < product_count; i++) {
            cout << "* ";
            list[i].print(); 
        }

        cout << endl;
    }
};

struct Recipe {
    char title[51];
    ProductList products;
    char instructions[1025];

    void read() {
        cout << "Title: ";
        cin.getline(title, 50);
        
        products.read();
        cin.ignore();

        cout << "Cooking instructions: ";
        cin.getline(instructions, 1024);
    }

    void print() const {
        cout << "=== " << title << " ===" << endl;

        products.print();

        cout << instructions << endl;
    }
};

struct RecipeBook {
    int recipe_count;
    Recipe recipies[100];

    void init() {
        recipe_count = 0;
    }

    void add_recipe(const Recipe& new_recipe) {
        recipies[recipe_count] = new_recipe;
        recipe_count++;
    }

    const Recipe& search_by_title(const char* title) const {
        for(int i = 0; i < recipe_count; i++) {
            if (!strcmp(recipies[i].title, title)) return recipies[i];
        }

        throw std::runtime_error("Recipe with this title not found!");
    }

    void print() const {
        for(int i = 0; i < recipe_count; i++) {
            recipies[i].print();
            cout << "-------------------" << endl;
        }
        cout << endl;
    }
};

int main() {
    Recipe cookies {"cookies", 
                    {2, {{"sugar", 300, 'g'}, 
                         {"chokolate", 100, 'g'}}}, 
                    "Bake in the oven"};

    RecipeBook book;
    book.init();
    book.add_recipe(cookies);
    book.print();

    Recipe cookies_found = book.search_by_title("cookies");
    cookies_found.print();

    try {
        Recipe not_found = book.search_by_title("djfh");
    } catch (std::runtime_error e) {
        cout << e.what() << endl;
    }

    return 0;
}
