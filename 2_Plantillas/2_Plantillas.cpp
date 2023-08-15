#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
class  DataHelper
{
    T data;

public:
    DataHelper(T newData)
    {
        data = newData;
    }

    void print()
    {
        cout << sizeof(T) << " " << data << "\n";
    }

    void printToFile(const char* fileName, bool binary = false)
    {
        if (!binary)
        {
            fstream myFile(fileName, ios_base::out);

            if (myFile.is_open())
            {
                myFile << data << "\n";
                myFile.close();
            }
            else
            {
                cout << "Wow, you suck guys\n";
            }
        }
        else
        {
            fstream myFile(fileName, ios_base::out | ios_base::binary);
            if (myFile.is_open())
            {
                myFile << sizeof(T) << " " << data << "\n";
                myFile.close();
            }
            else
            {
                cout << "Wow, you suck guys\n";
            }
        }
    }
};

int main()
{
    cout << "Tamanos\n";
    cout << "int: " << sizeof(int) << "\n";
    cout << "float: " << sizeof(float) << "\n";
    cout << "double: " << sizeof(double) << "\n";
    cout << "char: " << sizeof(char) << "\n";
    cout << "string: " << sizeof(string) << "\n";

    DataHelper<char>* myChar = new  DataHelper<char>(12);
    DataHelper<float>* myFloat = new  DataHelper<float>(sizeof(float));

    DataHelper<char*>* myChars = new  DataHelper<char*>((char*) "Ayoooo");

    myChar->print();
    myFloat->print();
    myChars->print();

    myChar->printToFile("char.danger");

    myFloat->printToFile("float.txt");
    myFloat->printToFile("float.bin", true);

    fstream archivo("starbit.bmp", ios_base::in | ios_base::out);
    if (archivo.is_open())
    {
        char* buffer = new char[8];
        while (!archivo.eof())
        {
            archivo.read(buffer,8);
            cout << hex << buffer << "\n";
        }
    }
}
