// =========================================================
// File: main.cpp
// Author: Eduardo Rodríguez Gil - A01274913
// Date: 20/09/2021
// =========================================================

#include <bits/stdc++.h>

using namespace std;

string txt1 = "", txt2 = "", txt3 = "", txt4 = "", txt5 = "";

void Read() {
    string line;
    ifstream t1("transmission1.txt"), t2("transmission2.txt"), t3("mcode1.txt"), t4("mcode2.txt"), t5("mcode3.txt");
    while(getline(t1, line)) {
        txt1 = txt1 + line;
    }
    while(getline(t2, line)) {
        txt2 = txt2 + line;
    }
    while(getline(t3, line)) {
        txt3 = txt3 + line;
    }
    while(getline(t4, line)) {
        txt4 = txt4 + line;
    }
    while(getline(t5, line)) {
        txt5 = txt5 + line;
    }
}

// Parte 1

void Maliciosos() {

    // transmission1.txt
    cout << "transmission1.txt: " << endl;
    size_t n = txt1.find(txt3);
    if(n != string::npos) {
        cout << "mcode1.txt - true, start at position " << n << endl;
    }
    else { 
        cout << "mcode1.txt - false" << endl;
    }
    n = txt1.find(txt4);
    if(n != string::npos) {
        cout << "mcode2.txt - true, start at position " << n << endl;
    }
    else {
        cout << "mcode2.txt - false" << endl;
    }
    n = txt1.find(txt5);
    if(n != string::npos) {
        cout << "mcode3.txt - true, start at position "<< n << endl;
    }
    else {
        cout << "mcode3.txt - false" << endl;
    }

    // transmission2.txt
    cout << "\ntransmission2.txt: " << endl;
    n = txt2.find(txt3);
    if(n != string::npos) {
        cout << "mcode1.txt - true, start at position " << n << endl;
    }
    else { 
        cout << "mcode1.txt - false" << endl;
    }
    n = txt2.find(txt4);
    if(n != string::npos) {
        cout << "mcode2.txt - true, start at position " << n << endl;
    }
    else {
        cout << "mcode2.txt - false" << endl;
    }
    n = txt2.find(txt5);
    if(n != string::npos) {
        cout << "mcode3.txt - true, start at position "<< n << endl;
    }
    else {
        cout << "mcode3.txt - false" << endl;
    }
}

string x(string y) {
    string z;
    for(int i = 0; i < y.size(); i++) {
        if(y[i] != ' ') {
            z += "#", z += y[i];
        }
    }
    z += "#";
    return z;
}

// Parte 2

void F(string s) {
    string k = x(s);
    int a, b, c, d, e, f, p[k.length()];
    b = c = 0;
    for(a = 0; a < k.length(); a++) {
        d = b - (a - b);
        if(c > a)
        p[a] = min(c - a, p[d]);
        else p[a] = 0;
        while(k[a + 1 + p[a]] == k[a - 1 - p[a]]) {
            p[a]++;
        }
        if(a + p[a] > c) {
            b = a, c = a + p[a];
        }
    }
    e = f = 0;
    for(a = 1; a < k.length(); a++) {
        if(p[a] > e) {
            e = p[a], f = a;
        }
    }
    int sum = (f - e)/2;
    cout << "mirrored code found, start at " << sum << ", ended at " << e + sum << endl;
}
void Desconocidos() {
    cout << "\ntransmission1.txt:" << endl;
    F(txt1);
    cout << "\ntransmission2.txt:" << endl;
    F(txt2);
}

// Parte 3

void Similar() {
    int x = txt1.size(), y = txt2.size(), z[x + 1][y + 1];
    for(int i = 0; i <= x; i++) {
        for(int j = 0; j <= y; j++) {
            if(i == 0 || j == 0) {
                z[i][j] = 0;
            }
            else if(txt1[i - 1] == txt2[j -1]) {
                z[i][j] = z[i -1][j -1] + 1;
            }
            else {
                z[i][j] = max(z[i - 1][j], z[i][j - 1]);
            }
        }
    }
    cout << "\nthe longest common substring between transmission1.txt and transmission2.txt is " << z[x][y] << " characters long" << endl;
}

// Resultados

int main() {
    Read(), Maliciosos(), Desconocidos(), Similar();
}