#include <iostream>

using namespace std;

double tidak = 0;
double ya = 0;
double emosirendah = 0;
double emosisedang = 0;
double emositinggi = 0;
double provrendah = 0;
double provsedang = 0;
double provtinggi = 0;
double provsangattinggi = 0;
double emosi = 50;
double provokasi = 95;
double yStar;

int main() {
    //hitung emosi
    cout << emosi << endl;
    if ((emosi > 0) && (emosi <= 25)) {
        emosirendah = 1;
    }
    else if ((emosi > 25) && (emosi <= 50)) {
        emosirendah = (50 - emosi) / 25;
        emosisedang = (emosi - 25) / 25;
    }
    else if ((emosi > 50) && (emosi <= 75)) {
        emositinggi = (emosi - 50) / 25;
        emosisedang = (75 - emosi) / 25;
    }
    else if (emosi <= 100) {
        emositinggi = 1;
    }
    //hitung provokasi
    cout << provokasi << endl;
    if ((provokasi > 0) && (provokasi <= 20)) {
        provrendah = 1;
    }
    else if ((provokasi > 20) && (provokasi <= 40)) {
        provrendah = (40 - provokasi) / 20;
        provsedang = (provokasi - 20) / 20;
    }
    else if ((provokasi > 40) && (provokasi <= 60)) {
        provtinggi = (provokasi - 40) / 20;
        provsedang = (60 - provokasi) / 20;
    }
    else if ((provokasi > 60) && (provokasi <= 80)) {
        provtinggi = (provokasi - 60) / 20;
        provsangattinggi = (80 - provokasi) / 20;
    }
    else if ((provokasi > 80) && (provokasi <= 100)) {
        provtinggi = 1;
    }

    cout << endl;
    cout << "Emosi" << endl;
    cout << "Rendah = " << emosirendah << endl;
    cout << "Sedang = " << emosisedang << endl;
    cout << "Tinggi = " << emositinggi << endl;
    cout << endl;
    cout << "Provokasi" << endl;
    cout << "Rendah = " << provrendah << endl;
    cout << "Sedang = " << provsedang << endl;
    cout << "Tinggi = " << provtinggi << endl;
    cout << "Sangat Tinggi = " << provsangattinggi << endl;
    cout << endl;

    //fuzzy rules
    if (emosirendah > 0) {
        if (provrendah > 0) {
            if (emosirendah < provrendah) {
                tidak = emosirendah;
            }
            else {
                tidak = provrendah;
            }
        }
        if (provsedang > 0) {
            if (tidak > provsedang) {
                tidak = provsedang;
            }
        }
        if (provtinggi > 0) {
            if (tidak < provtinggi) {
                tidak = provtinggi;
            }
        }
        if (provsangattinggi > 0) {
            if (provsangattinggi < emosirendah) {
                ya = provsangattinggi;
            }
            else {
                ya = emosirendah;
            }
        }
    }
    if (emosisedang > 0) {
        if (provrendah > 0) {
            if (emosisedang < provrendah) {
                tidak = emosisedang;
            }
            else {
                tidak = provrendah;
            }
        }
        if (provsedang > 0) {
            if (tidak > provsedang) {
                tidak = provsedang;
            }
        }
        if (provtinggi > 0) {
            if (provtinggi < emosisedang) {
                tidak = provtinggi;
            }
        }
        if (provsangattinggi > 0) {
            if (provsangattinggi < emosirendah) {
                ya = provsangattinggi;
            }
            else {
                ya = emosirendah;
            }
        }
    }
    if (emositinggi > 0) {
        if (provrendah > 0) {
            if (emositinggi < provrendah) {
                tidak = emositinggi;
            }
            else {
                tidak = provrendah;
            }
        }
        if (provsedang > 0) {
            if (tidak > provsedang) {
                tidak = provsedang;
            }
        }
        if (provtinggi > 0) {
            if (provtinggi > emosirendah) {
                ya = provtinggi;
            }
            else {
                ya = emosirendah;
            }
        }
        if (provsangattinggi > 0) {
            if (ya > provsangattinggi) {
                ya = provsangattinggi;
            }
        }
    }

    if (ya > 1) {
        ya = 0;
    }
    if (tidak > 1) {
        tidak = 0;
    }

    cout << "ya = " << ya << endl;
    cout << "tidak = " << tidak << endl;

    yStar = (tidak * 100 + ya * 50) / (tidak + ya);
    cout << yStar << endl;

    if (yStar > 50) {
        cout << "tidak" << endl;
    }
    else {
        cout << "ya" << endl;
    }
}
