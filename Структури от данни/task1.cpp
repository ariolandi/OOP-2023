#include <iostream>
#include <cstring>
using std::cin, std::cout, std::endl;
const int NAME_lENGTH = 51;

struct HistogramItem {
    char name[NAME_lENGTH];
    int count;

    bool equals(const char* other_name) const {
        return !strcmp(other_name, name);
    }
};

int main () {
    int N;
    cin >> N;
    char **list = new char*[N];

    for(int i = 0; i < N; i++) {
        list[i] = new char[NAME_lENGTH];
        cin >> list[i];
    }

    // хистограмата няма да съдържа повече от N различни записа
    HistogramItem *histogram = new HistogramItem[N];
    int M = 0;

    for(int i = 0; i < N; i++) {
        bool found = false;
        // обхождаме всички имена в хистограмата, докато текущото не е вече намерено
        for(int j = 0; j < M && !found; j++) {
            // при намиране на съвпадение, увеличаваме съответния брояч
            // и отбелязваме текущата дума за намерена
            if (histogram[j].equals(list[i])) {
                found = true;
                histogram[j].count ++;
            }
        }

        // ако думата не е намерена, то я добавяме в края на хистограмата 
        if (!found) {
            strcpy(histogram[M].name, list[i]);
            histogram[M].count = 1;
            M++;
        }
    }

    // намираме индекса с най-голям брояч
    int mostFrequentIndex = 0;
    for (int i = 1; i < M; i++) {
        if(histogram[i].count > histogram[mostFrequentIndex].count) {
            mostFrequentIndex = i;
        }
    }

    cout << histogram[mostFrequentIndex].name << " " << histogram[mostFrequentIndex].count << endl;

    for(int i = 0; i < N; i++) {
        delete[] list[i];
    }
    delete[] histogram;
    delete[] list;

    return 0;
}
