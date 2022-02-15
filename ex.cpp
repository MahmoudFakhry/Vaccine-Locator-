#include <iostream>
#include <fstream>

using namespace std;

void check_contents(string &contents, string empty) {
    // Constantly waiting and reading...
    ifstream opener;
    opener.open("ListeningToYou.txt");
    opener >> contents;
    opener.close();
}

int valid_int(string str) {
    if (str.length() < 1) {
        return 0;
    }
    for (int i = 0; i < str.length(); i++) {
        char str_char = str[i];
        if ((str_char == '0') || (str_char == '1') || (str_char == '2') || (str_char == '3') || (str_char == '4') || (str_char == '5') || (str_char == '6') || (str_char == '7') || (str_char == '8') || (str_char == '9')) {
        } else {
            return 0;
        }
    }
    return 1;
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

    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
    cout << "Welcome to Vaccine Locator, the easy-to-use Voice to Text helper tool!" << endl;
    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
    cout << "If you don't have a COVID-19 vaccine, you won't be protected against COVID-19." << endl << "Get one today!" << endl << endl;
    do {
        cout << "Allow Vaccine Locator to search for vaccine locations?" << endl;
        cout << "NOTE: You can easily search for hospitals with a single voice input!" << endl
            << "(1) Yes" << endl
            << "(0) No" << endl;
        cin >> check;
        if (!check_TorF(check)) {
            cout << "Sorry, your input was not a 1 or a 0, so please re-input a value." << endl;
        }
    } while (!check_TorF(check));
    if (check == "0") {
        cout << "We'll see you next time! :)" << endl;
        exit(0);
    }
    cout << "Enter your login information." << endl;
    cout << "Username: ";
    cin >> str_user;
    cout << "Password: ";
    cin >> str_pass;
    cout << endl;

    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
    cout << "Welcome! Provide an address (or general location) to find nearby hospitals." << endl;
    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
    cout << "TIP: Speak clearly into the voice-to-text microphone. We want to listen to you speak." << endl;

    f.open("ListeningToYou.txt");
    f >> contents;
    f.close();

    cout << "Detecting input from speaker..." << endl;
    cout << "Interpreting extensive data..." << endl;

    string wait_input = "1";
    t_or_f = "0";
    while (contents == empty) {
        check_contents(contents, empty);
    }

    while ((wait_input == "1") && (t_or_f == "0")) {
        check_contents(contents, empty);
        do {
            cout << "==========" << endl;
            cout << "We heard you say: " << contents << "." << endl;
            cout << "Is this correct?" << endl
                    << "(1) Yes" << endl
                    << "(0) No" << endl;
            cin >> t_or_f;
            if (!check_TorF(t_or_f)) {
                cout << "Sorry, your input was not a 1 or a 0, so please re-input a value." << endl;
            }
        } while (!check_TorF(t_or_f));
        if (t_or_f != "1") {
            cout << "Please speak into the microphone again..." << endl;
            cout << "(1) Finished" << endl;
            do {
                cout << "When finished, please type enter the number 1." << endl;
                cin >> wait_input;
            } while (wait_input != "1");
        }
    }

    if (contents == "Corvallis") {
        cout << "For Corvallis, OR:" << endl;
        cout << "- Good Samaritan Regional Medical Center" << endl;
        cout << "- Student Health Services" << endl;
    } else if (contents == "Portland") {
        cout << "For Portland, OR:" << endl;
        cout << "- OHSU Hospital" << endl;
        cout << "- Adventist Health Portland" << endl;
    } else if (contents == "Redmond") {
        cout << "For Redmond, OR:" << endl;
        cout << "- St. Charles Redmond" << endl;
        cout << "- Redmond Clinic" << endl;
    } else {
        cout << "No hospitals found providing vaccines in this area." << endl;
    }
    cout << "==========" << endl;

    string str_adv;
    do {
        cout << "Would you like to run Advanced Diagnostics (Developer Mode) to verify that the microphone is fully-functioning using the latest update?" << endl;
        cout << "(1) No, thank you" << endl;
        cout << "(0) Run Advanced Diagnostics (Developer Mode)" << endl;
        cin >> str_adv;
        if (!check_TorF(str_adv)) {
            cout << "Sorry, your input was not a 1 or a 0, so please re-input a value." << endl;
        }
    } while (!check_TorF(str_adv));
    if (str_adv == "0") {
        cout << endl;
        cout << "Mechanic Type V123.448.457893.5678933x776" << endl;
        cout << "Noise Sound 938.448.457893.5678933x776 running 755.3xx with 93.334" << endl;
        cout << "Prosessor 2.3 GHz 8-Core Intel Core i9" << endl;
    }
}
