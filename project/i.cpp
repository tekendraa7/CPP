#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;

// -------------------------
// Steganography Class
// -------------------------
class Steganography {
private:
    // Convert a string into binary (8-bit per char)
    string toBinary(string text) {
        string binary = "";
        for (char c : text) {
            binary += bitset<8>(c).to_string(); // convert char to 8-bit binary
        }
        return binary;
    }

    // Convert binary string back to text
    string toText(string binary) {
        string text = "";
        for (size_t i = 0; i < binary.size(); i += 8) {
            bitset<8> bits(binary.substr(i, 8));
            text += char(bits.to_ulong());
        }
        return text;
    }

public:
    // -------------------------
    // Encode: Hide message in spaces
    // -------------------------
    void encode(string inputFile, string outputFile, string secret) {
        ifstream in(inputFile);
        ofstream out(outputFile);

        if (!in.is_open() || !out.is_open()) {
            cout << "Error opening files!" << endl;
            return;
        }

        // Convert secret to binary
        string binary = toBinary(secret);
        size_t index = 0;

        string line;
        while (getline(in, line)) {
            for (char c : line) {
                out << c;
                // Hide secret bits inside spaces after characters
                if (index < binary.size()) {
                    if (binary[index] == '0') {
                        out << " ";      // one space for 0
                    } else {
                        out << "  ";     // two spaces for 1
                    }
                    index++;
                }
            }
            out << "\n";
        }

        in.close();
        out.close();
        cout << "Message encoded successfully into " << outputFile << endl;
    }

    // -------------------------
    // Decode: Extract message from spaces
    // -------------------------
    void decode(string stegoFile) {
        ifstream in(stegoFile);

        if (!in.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        string binary = "";
        string line;
        while (getline(in, line)) {
            for (size_t i = 0; i < line.size(); i++) {
                if (line[i] == ' ') {
                    int count = 1;
                    while (i + 1 < line.size() && line[i + 1] == ' ') {
                        count++;
                        i++;
                    }
                    if (count == 1) binary += "0";
                    else if (count == 2) binary += "1";
                }
            }
        }
        in.close();

        if (binary.empty()) {
            cout << "No hidden message found!" << endl;
            return;
        }

        // Convert binary back to text
        string message = toText(binary);
        cout << "Decoded message: " << message << endl;
    }
};

// -------------------------
// Main Function
// -------------------------
int main() {
    Steganography steg;
    int choice;

    cout << "===== Steganography Simulator =====" << endl;
    cout << "1. Encode (Hide Message)" << endl;
    cout << "2. Decode (Extract Message)" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore(); // clear input buffer

    if (choice == 1) {
        string inputFile, outputFile, secret;
        cout << "Enter input text file name: ";
        getline(cin, inputFile);
        cout << "Enter output (stego) file name: ";
        getline(cin, outputFile);
        cout << "Enter secret message to hide: ";
        getline(cin, secret);

        steg.encode(inputFile, outputFile, secret);
    } else if (choice == 2) {
        string stegoFile;
        cout << "Enter stego file name: ";
        getline(cin, stegoFile);
        steg.decode(stegoFile);
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
