#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

const int ARRAYS_SIZE = 4;

void swapInPairs(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapBlocks2(vector<int> &vec, int (&arr)[ARRAYS_SIZE]) {
    for (int i = 0; i < ARRAYS_SIZE; ++i) {
        swapInPairs(vec[i], *(arr + i));
    }
}

// массив передается по указателю просто показать, что это тоже имеет место
void printResult(vector<int> &vec, const int* arr, size_t size) {
    printf("vector | array\n");
    for (size_t i{}; i < size; ++i) {
        printf("%6i | %5i\n", vec[i], *(arr + i));
    }
}

int main() {
    vector<int> a = {1,2,3,4};
    int b[] = {2,4,6,8};

    swapBlocks2(a, b);
    printResult(a, b, sizeof(b) / sizeof(*b));
}
