#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

int main() {
    string filename = "/home/gdzhang/Desktop/test.txt";
    ifstream infile;
    infile.open(filename.data());
    assert(infile.is_open());

    string outfilename = "/home/gdzhang/Desktop/output.csv";
    fstream outfile;
    outfile.open(outfilename, ios::out | ios::trunc);
    assert(outfile.is_open());

    string s;
    string input;
    for (int i = 0; getline(infile, s); i++) {
        switch (i % 3) {
            case 0:
                input = s;
//                cout << input << endl;
                break;
            case 1:
                input += s;
//                cout << input << endl;
                break;
            case 2:
                input += s;
//                cout << input << endl;
                outfile << input << endl;
                break;
        }
    }
    infile.close();
    outfile.close();
    return 0;
}
