#include <iostream>
#include <fstream>
using namespace std;


class crypt {
    int key;

    
    char c;

public:
    void encrypt(int key, string filein, string fileout);
    void decrypt(int key, string filein, string fileout);
};

void crypt::encrypt(int key, string filein, string fileout)
{

    fstream fin, fout;

    fin.open(filein, fstream::in);
    fout.open(fileout, fstream::out);

    while (fin >> noskipws >> c) {
        int temp = (c + key);
        
        fout << (char)temp;
    }

    
    fin.close();
    fout.close();
}


void crypt::decrypt(int key, string filein, string fileout)
{
    
    fstream fin;
    fstream fout;
    fin.open(filein, fstream::in);
    fout.open(fileout, fstream::out);

    while (fin >> noskipws >> c) {

        
        int temp = (c - key);
        fout << (char)temp;
    }

    fin.close();
    fout.close();
}

int main(int argc, char* argv[])
{
    crypt crypt;
    
    
    if (std::string(argv[1]) == "-e") {
        crypt.encrypt(atoi(argv[2]), std::string(argv[3]), std::string(argv[4]));
        return 0;
    }
    if (std::string(argv[1]) == "-d") {
        crypt.decrypt(atoi(argv[2]), std::string(argv[3]), std::string(argv[4]));
        return 0;
    }
    if (std::string(argv[1]) == "-h") {
        cout << argv[0] << " [-e] [key] [input file] [output file] -- Encrypt" << endl;
        cout << argv[0] << " [-d] [key] [input file] [output file] -- Decrypt" << endl;
        cout << argv[0] << " [-h] -- Help" << endl;
        return 0;
    }
    cout << argv[0] << " " << argv[1] << " " << argv[2] << " " << argv[3] << " " << argv[4] << " -- You wrote" << endl;
    cout << argv[0] << " [-e] [key] [input file] [output file] -- Encrypt" << endl;
    cout << argv[0] << " [-d] [key] [input file] [output file] -- Decrypt" << endl;
    cout << argv[0] << " [-h] -- Help" << endl;
}
