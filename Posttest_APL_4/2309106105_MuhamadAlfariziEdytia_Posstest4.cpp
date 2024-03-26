#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct User {
    string username;
    string password;
    vector<string> pesawat[2]; // Nested array 
};

unordered_map<string, User> database;

void registerUser(const string& username, const string& password, bool isAdmin = false) {
    if (database.find(username) != database.end()) {
        cout << "Username sudah terdaftar." << endl;
    } else {
        User newUser;
        newUser.username = username;
        newUser.password = password;
        database[username] = newUser;
        cout << "Registrasi berhasil." << endl;
    }
}

User* loginUser(const string& username, const string& password, int& loginAttempt) {
    auto it = database.find(username);
    if (it != database.end()) {
        if (it->second.password == password) {
            return &(it->second);
        }
    }
    loginAttempt++;
    return nullptr;
}

void menambahkanPesawat(User& user, const string& pesawat, const string& status) {
    user.pesawat[0].push_back(pesawat); // Menambahkan jenis pesawat
    user.pesawat[1].push_back(status);  // Menambahkan status pesawat
    cout << "Pesawat tempur berhasil ditambahkan." << endl;
}

void lihatPesawat(const User& user) {
    cout << "Daftar Pesawat milik " << user.username << ":" << endl;
    for (int i = 0; i < user.pesawat[0].size(); ++i) {
        cout << "Jenis: " << user.pesawat[0][i] << ", Status: " << user.pesawat[1][i] << endl;
    }
}

int main() {
    int pilih_menu;
    string username, password, pilihan, pesawat, pesawat_baru, status;
    int index;
    int loginAttempt = 0;

    do {
        cout << "Selamat datang! Silakan pilih tindakan:" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == "1") {
            cout << "Masukkan username: ";
            cin >> username;
            cout << "Masukkan password: ";
            cin >> password;
            registerUser(username, password);
        } else if (pilihan == "2") {
            if (loginAttempt >= 3) {
                cout << "Anda telah mencapai batas percobaan login yang gagal. Program berhenti." << endl;
                break;
            }

            cout << "Masukkan username: ";
            cin >> username;
            cout << "Masukkan password: ";
            cin >> password;

            User* user = loginUser(username, password, loginAttempt);
            if (user != nullptr) {
                cout << "Selamat datang, " << username << "!" << endl;
                do {
                    cout << "Menu:" << endl;
                    cout << "1. Tambahkan pesawat tempur" << endl;
                    cout << "2. Lihat daftar pesawat" << endl;
                    cout << "3. Logout" << endl;
                    cout << "Pilihan: ";
                    cin >> pilih_menu;

                    switch (pilih_menu) {
                        case 1: {
                            cout << "Masukkan jenis pesawat: ";
                            cin >> pesawat;
                            cout << "Masukkan status pesawat: ";
                            cin >> status;
                            menambahkanPesawat(*user, pesawat, status);
                            break;
                        }
                        case 2: {
                            lihatPesawat(*user);
                            break;
                        }
                        case 3: {
                            cout << "Logout berhasil." << endl;
                            break;
                        }
                        default: {
                            cout << "Pilihan tidak valid." << endl;
                            break;
                        }
                    }
                } while (pilih_menu != 3);
            } else {
                cout << "Username atau password tidak valid." << endl;
            }
        } else if (pilihan == "3") {
            cout << "Terima kasih telah menggunakan program ini. Sampai jumpa!" << endl;
            break;
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    } while (true);
    return 0;
}
