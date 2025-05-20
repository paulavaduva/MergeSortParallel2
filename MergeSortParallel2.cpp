#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm>
#include <omp.h>

using namespace std;

const int THRESHOLD = 10000;

vector<int> readFromFile(const string& filename) {
    vector<int> numbers;
    ifstream file(filename);
    int num;
    while (file >> num)
        numbers.push_back(num);
    return numbers;
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void parallelMergeSort(vector<int>& arr, int left, int right, int depth = 0) {
    if (right - left <= THRESHOLD) {
        sort(arr.begin() + left, arr.begin() + right + 1);
        return;
    }

    int mid = left + (right - left) / 2;

    if (depth <= 4) {
#pragma omp parallel sections
        {
#pragma omp section
            parallelMergeSort(arr, left, mid, depth + 1);
#pragma omp section
            parallelMergeSort(arr, mid + 1, right, depth + 1);
        }
    }
    else {
        parallelMergeSort(arr, left, mid, depth + 1);
        parallelMergeSort(arr, mid + 1, right, depth + 1);
    }

    merge(arr, left, mid, right);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Trebuie sa specifici fisierul de intrare.\n";
        return 1;
    }

    string filename = argv[1];
    vector<int> data = readFromFile(filename);

    if (data.empty()) {
        cerr << "Fisierul este gol sau nu poate fi citit.\n";
        return 1;
    }

    auto start = chrono::high_resolution_clock::now();

    parallelMergeSort(data, 0, data.size() - 1);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    cout << "Sortare finalizata pentru " << filename << " in " << duration.count() << " ms\n";

    return 0;
}
