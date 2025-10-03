#include <iostream>
#include <string>
#include <fstream> 
#include <stdexcept>
using namespace std;

class file_utils {
public:
    /**
     * @brief Зчитує весь вміст файлу в рядок.
     *
     * @param file_path Шлях до файлу.
     * @return std::string Вміст файлу.
     * @throws std::runtime_error якщо файл не вдалося відкрити.
     */
    static string read_file_to_string(const string& file_path) {
        ifstream file_stream(file_path);

        if (!file_stream.is_open()) {
            throw runtime_error("Не вдалося відкрити файл для читання: " + file_path);
        }

        return string((istreambuf_iterator<char>(file_stream)),
            istreambuf_iterator<char>());
    }

    /**
     * @brief Записує рядок у файл.
     *
     * @param file_path Шлях до файлу. Якщо файл існує, його буде перезаписано.
     * @param content Рядок, який потрібно записати.
     * @throws std::runtime_error якщо файл не вдалося відкрити для запису.
     */
    static void write_string_to_file(const string& file_path, const string& content) {
        ofstream file_stream(file_path);

        if (!file_stream.is_open()) {
            throw runtime_error("Не вдалося відкрити файл для запису: " + file_path);
        }

        file_stream << content;
    }
};

int menu() {
    cout << "\n--------------Menu--------------\n";
    cout << "0  - Exit\n";
    cout << "1  - Show text\n";
    cout << "2  - Amout of symb\n";
    cout << "3  - Search world\n";
    cout << "4  - Change world\n";
    cout << "5  - Delete a world\n";
    cout << "6  - Reverse\n";


    int choice;

    cout << "Enter your choice: ";
    (cin >> choice).get();
    return choice;
}



int main() {

    /*string s1;
    string s2 = "hello";
    string s3(s2);
    string s4(10, '*');
    cout << s4;*/

    /*string str1 = "hello";
    string str2 = "world";

    string str3 = str1 + " " + str2;

    cout << str3;*/

    /*string str1 = "hello";
    string str2 = "world";

    str1 += str2;

    cout << str1 << "\n" << str2;*/

    /*string str1 = "hello";
    string str2;
    str2 = str1;

    cout << str1 << "\n" << str2;*/

    /*string str = "hello world";

    cout << str[4];
    str[4] = 'a';

    cout << "\n" << str;*/

    //string str1 = "hello";
    //string str2 = "hello";
    //
    //*if (str1 == str2)
    //    cout << "Equals";
    //else
    //    cout << "Not Equals";*/
    //
    //if (str1 > str2)
    //    cout << "First is bigger";
    //else
    //    cout << "Second is bigger";

    //insert

    /*string str = "hello world";
    str.insert(6, "all ");
    cout << str;*/

    //erase

    /*string str = "hello world";
    str.erase(2, 3);
    cout << str;*/

    // replace

    /*string str = "hello world";
    str.replace(6, 5, "all");
    cout << str;*/

    //length

    /*string str = "hello world";

    cout << str.length();*/

    //find 

    /*string str = "hello all world all hello all hi";

    int pos = str.find("all", 10);

    cout << pos;*/

    /*string str = "hello all world all hello all hi";
    string search = "all";
    int pos = str.find(search);

    if (pos == -1)
        cout << "not found!";
    else {
        while (pos != -1) {
            cout << pos << " ";
            str.erase(pos, search.length());
            pos = str.find(search, pos + 1);
        }
    }

    cout << "\n" << str;*/

    /*string str = "hello all world";

    string res = str.substr(6, 3);

    cout << res;*/

    /*string str = "a";

    if (str.empty()) {
        cout << "String is empty";
    }*/

    /*string str;
    getline(cin, str);
    cout << str;*/

    /*string str = "helzlo all wozrldz";

    string search = "z";
    int pos = str.find(search);
    
    if (pos == -1)
    cout << "not found!";
    else {
        while (pos != -1) {
            str.erase(pos, search.length());
            pos = str.find(search, pos);
        }
    }

    str.insert(str.length() / 2, "ABC");

    cout << "\n" << str;*/

    string file_path = "data.txt";

    string text = file_utils::read_file_to_string(file_path);

    

    file_utils::write_string_to_file(file_path, "hello");

    int choice, pos, count = 0;
    string search, w1, w2;
    do {
        choice = menu();

        switch (choice)
        {
        case 1:
            cout << text << "\n";
            break;
        case 2:
            cout << text.length();
            break;
        case 3:
            cout << "Enter whar we are searching: ";
            cin >> search;
            pos = text.find(search);

            if (pos == -1)
                cout << "not found!";
            else {
                while (pos != -1) {
                    cout << " " << pos;
                    text.erase(pos, search.length());
                    pos = text.find(search, pos);
                    count++;
                }
            }
            cout << "\nCount: " << count;
            break;
        case 4:
            cout << "Enter which world we are chenging: ";
            cin >> w1;
            cout << "Enter world we are chenging on: ";
            cin >> w2;
            pos = text.find(search);

            if (pos == -1)
                cout << "not found!";
            else {
                while (pos != -1) {
                    cout << " " << pos;
                    text.insert(pos, w2);
                    pos = text.find(search, pos);
                    count++;
                }
            }
            cout << "\nCount: " << count;
            break;
        default:
            break;
        }
    } while (true);
    return 0;
}