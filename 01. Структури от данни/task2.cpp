#include <iostream>
#include <cmath>
using std::cin, std::cout, std::endl, std::sqrt, std::swap;

struct Point {
    double x, y;

    // когато приемаме обект като параметър, искаме да получим константна референция (псевдоним) към него
    // това се прави от съображения за памет - обектите могат да бъдат значително по-обемни от данните с прости типове
    double distance(const Point& other) const {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }

    // осигуряваме си по-приятно въвеждане на данните
    void read() {
        cin >> x >> y;
    }
};

struct Triangle {
    Point a, b, c;

    double area() const {
        double ab = a.distance(b);
        double bc = b.distance(c);
        double ca = c.distance(a);
        double p = (ab + bc + ca) / 2;

        return sqrt(p * (p - ab) * (p - bc) * (p - ca));
    }

    void read() {
        a.read();
        b.read();
        c.read();
    }
};

// метод на пряката селекция
void sort(double*& arr, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[i]) swap(arr[i], arr[j]);
        }
    }
}

int main() {
    int N;
    cin >> N;

    Triangle *triangles = new Triangle[N];
    for(int i = 0; i < N; i++) {
        triangles[i].read();
    }

    double *calculated_area = new double[N];
    for(int i = 0; i < N; i++) {
        calculated_area[i] = triangles[i].area();
    }

    sort(calculated_area, N);

    // при вече сортиран масив, можем да сравним директно съседните елементи
    int equal_areas = 0;
    for(int i = 1; i < N; i++) {
        equal_areas += (calculated_area[i] == calculated_area[i - 1]);
    }

    cout << equal_areas << endl;


    delete[] calculated_area;
    delete[] triangles;

    return 0;
}
