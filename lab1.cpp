#include <iostream>
#include <vector>

using namespace std;

// Функція для очищення вводу, якщо користувач ввів щось зайве
void clearInput() {
    cin.clear();
    while (cin.get() != '\n');
}

void task1() {
    cout << "\n--- Task 1 (Count zeros) ---" << endl;
    int n, count = 0, x;
    cout << "Enter count of elements: ";
    if (!(cin >> n)) return;

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) count++;
    }
    cout << "Result (zeros): " << count << endl;
}

void task2() {
    cout << "\n--- Task 2 (Max negative after T) ---" << endl;
    int n, T;
    cout << "Enter n: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Enter T: ";
    cin >> T;

    int posT = -1;
    for (int i = 0; i < n; i++) {
        if (A[i] == T) {
            posT = i; // знайде останнє входження T
        }
    }

    if (posT == -1 || posT == n - 1) {
        cout << "T not found or no elements after T" << endl;
        return;
    }

    int maxNeg = -2147483647; // Мінімальне можливе int
    int index = -1;

    for (int i = posT + 1; i < n; i++) {
        if (A[i] < 0) {
            if (index == -1 || A[i] >= maxNeg) {
                maxNeg = A[i];
                index = i;
            }
        }
    }

    if (index != -1)
        cout << "Index of max negative: " << index << endl;
    else
        cout << "No negative numbers after T" << endl;
}

void task3() {
    cout << "\n--- Task 3 (Array B calculation) ---" << endl;
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n <= 1) {
        cout << "Error: n must be > 1" << endl;
        return;
    }

    vector<double> A(n), B(n);
    double sum = 0;

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i];
    }

    cout << "Result B: ";
    for (int i = 0; i < n; i++) {
        B[i] = (sum - A[i]) / (n - 1);
        cout << B[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\n========== MENU ==========" << endl;
        cout << "1 - Task 1\n2 - Task 2\n3 - Task 3\n0 - Exit" << endl;
        cout << "Choose: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Use numbers." << endl;
            clearInput();
            continue;
        }

        if (choice == 0) break;

        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        default: cout << "Try again (1-3)" << endl;
        }
    }
    return 0;
}