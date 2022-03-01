#include <fstream>
#include <iostream>

using namespace std;

void clear_is() {
    ofstream file("/Users/skillup/ExMVP/ListeningToYou.txt");
    file << "";
}
void search_input() {
    // Constantly waiting and reading...
    fstream opener; string line;
    opener.open("/Users/skillup/ExMVP/ListeningToYou.txt");
    cin >> line;
    // Write number in i_s.txt
    cout << "in i_s file" << endl;
    //opener.clear();
    clear_is();
    opener << line << endl;
    opener.close();
}

int check_TorF(string str) {
    if (str.length() < 1) {
        return 0;
    }
    if ((str == "0") || (str == "1")) {
    } else {
        return 0;
    }
    return 1;
}

int main() {
    fstream f;
    string check;
    string str_user, str_pass, empty = "", contents, t_or_f;

    clear_is();

    f.open("/Users/skillup/ExMVP/ListeningToYou.txt");

    cout << "––––––––––––––––––––––––––––––––––" << endl;
    cout << "Welcome to Advanced Voice Search!" << endl;
    cout << "––––––––––––––––––––––––––––––––––" << endl;
    cout << "Make sure to speak CLEARLY into the microphone!" << endl
         << endl;

    string line, decide;
    while (1) {
        cout << "–––––––––––––––" << endl;
        cout << "Begin speaking:" << '\n';
        cout << "–––––––––––––––" << endl;

        if (!(f.is_open())) {
            f.open("/Users/skillup/ExMVP/ListeningToYou.txt");
        } if ((f.is_open())) {
            // Clear file contents of i_s.txt
            clear_is();
            cin >> line;
            // Write number in i_s.txt
            f.clear();
            f << line << endl;
            f.close();
        } 
        cout << "Wish to speak again?" << '\n';
        do {
            cin >> decide;
            if (!check_TorF(decide)) {
                cout << "Error: Please enter a 1 or 0." << '\n';
            }
        } while (!check_TorF(decide));
        if (decide == "0") {
            break;
        }
    }

    return 0;
}

