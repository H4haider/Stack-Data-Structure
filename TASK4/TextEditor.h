#include <iostream>
using namespace std;

template <typename T>
class TextEditor {
private:
    static const int msize = 100;
    T text[msize];
    int textLength;
    T undoStack[msize];
    T redoStack[msize];
    int undoTop;
    int redoTop;

public:
    TextEditor() : textLength(0), undoTop(-1), redoTop(-1) {
    }

    void typeCharacter(T ch) {
        if (textLength < msize) {
            text[textLength++] = ch;
            undoStack[++undoTop] = ch;
            redoTop = -1;  
        }
        else {
            cout << "Text Stack full"<<endl;
        }
    }

    void deleteCharacter() {
        if (textLength > 0) {
            T deleted = text[--textLength];
            undoStack[++undoTop] = deleted;
            redoTop = -1;  
        }
        else {
            cout << "Text Stack is empty" << endl;
        }
    }

    void undo() {
        if (undoTop >= 0) {
            T lastAction = undoStack[undoTop--];
            if (textLength > 0) {
                textLength--;
            }
            redoStack[++redoTop] = lastAction;
        }
        else {
            cout << "Nothing to undo"<<endl;
        }
    }

    void redo() {
        if (redoTop >= 0) {
            T lastAction = redoStack[redoTop--];
            text[textLength++] = lastAction;
            undoStack[++undoTop] = lastAction;
        }
        else {
            cout << "Nothing to redo"<<endl;
        }
    }

    void showText() const {
        cout << "Current Text: "<<endl;
        for (int i = 0; i < textLength; i++) {
            cout << text[i];
        }
        cout << endl<<endl;
    }
};


