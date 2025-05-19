#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>
#include <future>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#include "DoubleLinkedList.h"
#include "Student.h"

using namespace std;
using namespace chrono;

// Sorting Algorithm Functions (Tasks 1 & 2)
struct SortAlgorithm {
    string name;
    function<void(vector<int>&)> func;
};

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; ++j)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;
    int max_val = *max_element(arr.begin(), arr.end());
    vector<int> count(max_val + 1, 0);
    for (int num : arr) ++count[num];
    int index = 0;
    for (int i = 0; i <= max_val; ++i)
        while (count[i]--)
            arr[index++] = i;
}

void radixSort(vector<int>& arr) {
    if (arr.empty()) return;
    int max_num = *max_element(arr.begin(), arr.end());
    for (int exp = 1; max_num / exp > 0; exp *= 10) {
        vector<int> output(arr.size()), count(10, 0);
        for (int num : arr) count[(num / exp) % 10]++;
        for (int i = 1; i < 10; ++i) count[i] += count[i - 1];
        for (int i = arr.size() - 1; i >= 0; --i)
            output[--count[(arr[i] / exp) % 10]] = arr[i];
        arr = output;
    }
}

vector<int> generateRandomArray(int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 2 * n);
    vector<int> arr(n);
    for (int& num : arr)
        num = dis(gen);
    return arr;
}

long long measureSort(function<void(vector<int>&)> sortFunc, vector<int> arr) {
    long long duration = -1;
    auto future = async(launch::async, [&]() {
        auto start = high_resolution_clock::now();
        sortFunc(arr);
        auto end = high_resolution_clock::now();
        return duration_cast<nanoseconds>(end - start).count();
        });

    if (future.wait_for(minutes(5)) == future_status::timeout) {
        cout << "Timeout after 5 minutes.\n";
        return -1;
    }
    return future.get();
}

void runSortingBenchmark() {
    const int NUM_TEST_RUNS = 10;
    const vector<int> ARRAY_SIZES = { 10, 100, 500, 5000, 25000, 100000 };
    const string OUTPUT_FILENAME = "sorting_results.csv";

    vector<SortAlgorithm> sortingAlgorithms = {
        {"Bubble Sort", [](vector<int>& v) { bubbleSort(v); }},
        {"Insertion Sort", [](vector<int>& v) { insertionSort(v); }},
        {"Merge Sort", [](vector<int>& v) { mergeSort(v, 0, v.size() - 1); }},
        {"Quick Sort", [](vector<int>& v) { quickSort(v, 0, v.size() - 1); }},
        {"Counting Sort", [](vector<int>& v) { countingSort(v); }},
        {"Radix Sort", [](vector<int>& v) { radixSort(v); }}
    };

    ofstream outputFile(OUTPUT_FILENAME);
    outputFile << "Algorithm,Array Size,Run,Time (ns)\n";

    for (const auto& algo : sortingAlgorithms) {
        for (int size : ARRAY_SIZES) {
            if ((algo.name == "Bubble Sort" || algo.name == "Insertion Sort") && size > 5000) {
                cout << "Skipping " << algo.name << " for size " << size << endl;
                continue;
            }
            for (int run = 1; run <= NUM_TEST_RUNS; ++run) {
                vector<int> arr = generateRandomArray(size);
                long long time_ns = measureSort(algo.func, arr);

                outputFile << algo.name << "," << size << "," << run << "," << time_ns << "\n";
                cout << "Completed: " << algo.name << " | Size: " << size
                    << " | Run: " << run << " | Time(ns): " << time_ns << "\n";
            }
        }
    }

    outputFile.close();
    cout << "\nResults written to " << OUTPUT_FILENAME << endl;
}

// Student data pool
// there are more "female" names than "male" on purpose 

string firstNames[] = { "Emily", "Jacob", "Michael", "Madison", "Emma", "Joshua", "Matthew", 
"Olivia", "Hannah", "Abigail", "Isabella","Daniel","Christopher","Alyssa","Chloe","Jonathan", 
"Noah", "Jasmine", "Morgan", "Kevin", "Elijah","Makayla","Brooke","Issac","Hunter","Faith", "Zoe",
"Juan", "Aiden","Sofia", "Vanessa", "Julian", "Jesus", "Maya", "Jordan", "Autumn","Xavier", "Wyatt",
"Aaliyah", "Mariah", "Miguel", "Antonio","Cheyenne","Naomi","Mario","Luigi","Crystal","Hope",
"Tyrone", "Kendrick","Arianna", "Nicki", "Jamie", "Kent", "Bruce", "Kaden", "Jayden","Mercedes", 
"Destiny", "Dream", "Tamika", "Shantel", "Jade", "Jada","Kai", "Ace" };
string lastNames[] = { "Smith","Johnson", "Williams", "Brown","Jones", "Garcia","Miller","Davis",
"Rodriguez","Martinez", "Hernandez","Lopez", "Gonzales", "Wilson","Anderson","Taylor", "Moore", 
"Jackson","Martin", "Lee", "Perez", "Thompson", "White","Harris", "Sanchez", "Clark","Ramirez", 
"Lewis","Robinson", "King","Nguyen","Morales","Reyes","Sanders", "Castillo","Kim", "Howard",
"Brooks","Lyons","Caldwell","Rauls","Parker","James","Ridley","Love", "Rodgers", "Gardner",
"Butler","Scott","Revis", "Sawyer","Stroud", "Aiyuk", "Beckham", "Haliburton","Lillard","Bol", 
"Holiday" };
string majors[] = { "Business","Marketing","Finance","Biochemistry","Nursing","Psychology",
"Chemistry","Biology", "Computer Engineering","Civil Engineering","Mechanical Engineering",
"Computer Science","Information Technology","Architecture","Art", "Education", 
"Aerospace Engineering", "Mathematics", "Social Sciences","Criminal Justice", "Law" };

string randomName(const string arr[], int size) {
    return arr[rand() % size];
}

int randomMNumber() {
    int result = 10000000 + rand() % 90000000;
    return result;
}

string randomMajor() {
    // weights for major categories
    vector<pair<int, int>> majorRanges = {
        {0, 2},    // Business
        {3, 7},    // Health Professions
        {8, 10},   // Engineering
        {11, 13},  // CS/IT
        {14, 17},  // Liberal Arts
        {18, 20}   // Law/Criminal Justice
    };
    vector<int> weights = { 6, 5, 4, 3, 2, 1 };

    // weighted index pool
    vector<int> pool;
    for (int i = 0; i < majorRanges.size(); ++i) {
        for (int j = 0; j < weights[i]; ++j) {
            pool.push_back(i);
        }
    }

    int rangeIndex = pool[rand() % pool.size()];
    int start = majorRanges[rangeIndex].first;
    int end = majorRanges[rangeIndex].second;
    int majorIndex = start + rand() % (end - start + 1);

    return majors[majorIndex];
}

void runStudentInterface() {
    DoubleLinkedList<Student> studentList;
    for (int i = 0; i < 50; ++i) {
        string fn = randomName(firstNames, sizeof(firstNames) / sizeof(firstNames[0]));
        string ln = randomName(lastNames, sizeof(lastNames) / sizeof(lastNames[0]));
        int mNum = randomMNumber();
        string major = randomMajor();
        Student* temp = new Student(fn, ln, mNum, major);
        studentList.addItem(temp);
    }

    int choice, direction;
    do {
        cout << "\n--- Student Sort Menu ---\n";
        cout << "1. Sort by First Name\n";
        cout << "2. Sort by Last Name\n";
        cout << "3. Sort by MNumber\n";
        cout << "4. Display Students\n";
        cout << "0. Back to Main Menu\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            cout << "1. Ascending\n2. Descending\nDirection: ";
            cin >> direction;
        }

        switch (choice) {
        case 1:
            studentList.sortByFirstName(direction == 1);
            break;
        case 2:
            studentList.sortByLastName(direction == 1);
            break;
        case 3:
            studentList.sortByMNumber(direction == 1);
            break;
        case 4:
            studentList.display();
            break;
        }

    } while (choice != 0);
}


int main() {
    srand(static_cast<unsigned int>(time(0)));

    int topChoice;
    do {
        cout << "\n=== Lab 12 Menu ===\n";
        cout << "1. Run Sorting Algorithm Benchmarks (Tasks 1 & 2)\n";
        cout << "2. Run Student List Interface (Task 3)\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> topChoice;

        switch (topChoice) {
        case 1: runSortingBenchmark(); break;
        case 2: runStudentInterface(); break;
        }

    } while (topChoice != 0);

    return 0;
}
