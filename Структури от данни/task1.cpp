#include <iostream>
#include <cstring>
using std::cin, std::cout, std::endl;
const int NAME_lENGTH = 51;

struct HistogramItem {
    char name[NAME_lENGTH];
    int count;

    bool equals(const char* other_name) {
        return !strcmp(other_name, name);
    }
};

int main () {
    int N;
    cin >> N;
    char **list = new char*[N];

    for(int i = 0; i < N; i++) {
        char name[NAME_lENGTH];
        cin >> name;
        list[i] = new char[NAME_lENGTH];
        strcpy(list[i], name);
    }

    HistogramItem *histogram = new HistogramItem[N];
    int M = 0;

    for(int i = 0; i < N; i++) {
        bool found = false;
        for(int j = 0; j < M && !found; j++) {
            if (histogram[j].equals(list[i])) {
                found = true;
                histogram[j].count ++;
            }
        }

        if (!found) {
            strcpy(histogram[M].name, list[i]);
            histogram[M].count = 1;
            M++;
        }
    }

    for (int i = 0; i < M; i++) {
        cout << histogram[i].name << " " << histogram[i].count << endl;
    }

    for(int i = 0; i < N; i++) {
        delete[] list[i];
    }
    delete[] histogram;
    delete[] list;

    return 0;
}