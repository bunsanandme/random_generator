#include <iostream>

using namespace std;

const int N = 10;

int generatePseudorandomNumber(int seed) {
    const int A = 7;
    const int B = 5;
    const int M = 12;
    return (seed*A + B) % M;
}

int getRandomWithBorders(int min, int max, int seed) {
    return min + generatePseudorandomNumber(seed) % (max - min + 1);
}

void randomizeArray(int& a) {
    int* p = &a;
    int max_i = N;
    int temp;
    for(int i = 0; i < max_i - 1; i++) {
        int j = getRandomWithBorders(i, max_i-1, 4545);
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
    }
}

int* getRandomArray(int n, int seed) {
    int* array = new int[n];
    int x = generatePseudorandomNumber(seed);
    array[0] = x;
    for(int i = 1; i < n; i++) {
        array[i] = generatePseudorandomNumber(x);
        x = generatePseudorandomNumber(x);
    }
    return array;
}

int main() {
    int test_array[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    randomizeArray(*test_array);
    for(int i : test_array) {
        cout << i << endl;
    }
    return 0;
}





