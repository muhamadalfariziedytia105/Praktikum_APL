#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int pilihan;
    double suhu;

    while (true) {
        cout << "\nMenu Konversi Suhu:\n";
        cout << "1. Konversi Celcius ke Fahrenheit\n";
        cout << "2. Konversi Celcius ke Kelvin\n";
        cout << "3. Konversi Fahrenheit ke Celcius\n";
        cout << "4. Konversi Fahrenheit ke Kelvin\n";
        cout << "5. Konversi Kelvin ke Celcius\n";
        cout << "6. Konversi Kelvin ke Fahrenheit\n";
        cout << "7. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan suhu dalam Celcius: ";
                cin >> suhu;
                cout << "Suhu dalam Fahrenheit: " << ((suhu * 9/5) + 32) << " derajat Fahrenheit\n";
                break;

            case 2:
                cout << "Masukkan suhu dalam Celcius: ";
                cin >> suhu;
                cout << "Suhu dalam Kelvin: " << (suhu + 273.15) << " Kelvin\n";
                break;

            case 3:
                cout << "Masukkan suhu dalam Fahrenheit: ";
                cin >> suhu;
                cout << "Suhu dalam Celcius: " << ((suhu - 32) * 5/9) << " derajat Celcius\n";
                break;

            case 4:
                cout << "Masukkan suhu dalam Fahrenheit: ";
                cin >> suhu;
                cout << "Suhu dalam Kelvin: " << (((suhu - 32) * 5/9) + 273.15) << " Kelvin\n";
                break;

            case 5:
                cout << "Masukkan suhu dalam Kelvin: ";
                cin >> suhu;
                cout << "Suhu dalam Celcius: " << (suhu - 273.15) << " derajat Celcius\n";
                break;

            case 6:
                cout << "Masukkan suhu dalam Kelvin: ";
                cin >> suhu;
                cout << "Suhu dalam Fahrenheit: " << (((suhu - 273.15) * 9/5) + 32) << " derajat Fahrenheit\n";
                break;

            case 7:
                cout << "Program berakhir. Sampai jumpa!";
                return 0;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.";
        }
    }

    return 0;
}