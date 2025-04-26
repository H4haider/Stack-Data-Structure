#include "TextEditor.h"

int main() {
    TextEditor<char> editor; 
    char choice;

    do {
        cout << endl;
        cout << "--- Simple Text Editor ---"<<endl;
        cout << "1. Type character"<<endl;
        cout << "2. Delete last character"<<endl;
        cout << "3. Undo"<<endl;
        cout << "4. Redo"<<endl;
        cout << "5. Show current text"<<endl;
        cout << "6. Exit"<<endl;
        cout << "Enter choice: "<<endl;
        cin >> choice;

        switch (choice) {
        case '1': {
            char ch;
            cout << "Enter character to type: ";
            cin >> ch;
            editor.typeCharacter(ch);
            break;
        }
        case '2':
            editor.deleteCharacter();
            break;
        case '3':
            editor.undo();
            break;
        case '4':
            editor.redo();
            break;
        case '5':
            editor.showText();
            break;
        case '6':
            cout << "Exiting editor.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != '6');

    return 0;
}