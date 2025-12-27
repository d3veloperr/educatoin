#include <iostream>

using namespace std;

const int MAX_WORDS = 50;
const int MAX_WORD_LENGTH = 21;
const int MAX_INPUT_LENGTH = 1000;

bool isLowerCaseLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'а' && c <= 'я');
}

bool isUpperCaseLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'А' && c <= 'Я');
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isValidChar(char c) {
    return isLowerCaseLetter(c) || isUpperCaseLetter(c) || isDigit(c);
}

bool isPunctuation(char c) {
    return c == '.' || c == ',' || c == '!' || c == '?' || c == ';' || c == ':' || c == '-';
}

char toLowerCaseIfLetter(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a';
    }
    if (c >= 'А' && c <= 'Я') {
        return c - 'А' + 'а';
    }
    return c;
}

struct WordList {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int count;
    
    WordList() {
        count = 0;
        for (int i = 0; i < MAX_WORDS; i++) {
            words[i][0] = '\0';
        }
    }
};

void copyWord(char dest[MAX_WORD_LENGTH], const char* src) {
    int i = 0;
    while (src[i] != '\0' && i < MAX_WORD_LENGTH - 1) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

bool addWord(WordList& wordList, const char* word) {
    if (wordList.count >= MAX_WORDS) {
        return false;
    }
    
    copyWord(wordList.words[wordList.count], word);
    wordList.count++;
    return true;
}

int compareStrings(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) return -1;
        if (str1[i] > str2[i]) return 1;
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') return 0;
    if (str1[i] == '\0') return -1;
    return 1;
}

WordList processText(const char* input) {
    WordList result;
    char currentWord[MAX_WORD_LENGTH] = "";
    int wordIndex = 0;
    
    int dotCount = 0;
    
    int i = 0;
    while (input[i] != '\0') {
        char c = input[i];
        
        if (c == '.') {
            dotCount++;
            if (dotCount == 3) {
                if (wordIndex > 0) {
                    currentWord[wordIndex] = '\0';
                    addWord(result, currentWord);
                    currentWord[0] = '\0';
                    wordIndex = 0;
                }
                dotCount = 0;
            }
            i++;
            continue;
        } else if (dotCount > 0) {
            dotCount = 0;
        }
        
        if (isPunctuation(c)) {
            if (wordIndex > 0) {
                currentWord[wordIndex] = '\0';
                addWord(result, currentWord);
                currentWord[0] = '\0';
                wordIndex = 0;
            }
            i++;
            continue;
        }
        
        if (c == ' ' || c == '\t') {
            if (wordIndex > 0) {
                currentWord[wordIndex] = '\0';
                addWord(result, currentWord);
                currentWord[0] = '\0';
                wordIndex = 0;
            }
            i++;
            continue;
        }
        
        if (isValidChar(c)) {
            c = toLowerCaseIfLetter(c);
            
            if (wordIndex < MAX_WORD_LENGTH - 1) {
                currentWord[wordIndex] = c;
                wordIndex++;
            }
            i++;
            continue;
        }
        
        i++;
    }
    
    if (wordIndex > 0) {
        currentWord[wordIndex] = '\0';
        addWord(result, currentWord);
    }
    
    return result;
}

void sortWordsAlphabetically(WordList& wordList) {
    for (int i = 0; i < wordList.count - 1; i++) {
        for (int j = 0; j < wordList.count - i - 1; j++) {
            if (compareStrings(wordList.words[j], wordList.words[j + 1]) > 0) {
                char temp[MAX_WORD_LENGTH];
                copyWord(temp, wordList.words[j]);
                copyWord(wordList.words[j], wordList.words[j + 1]);
                copyWord(wordList.words[j + 1], temp);
            }
        }
    }
}

void printWordsVertically(const WordList& wordList) {
    cout << "\n4. Слова исходной последовательности, выведенные вертикально:\n";
    
    int maxLength = 0;
    for (int i = 0; i < wordList.count; i++) {
        int length = 0;
        while (wordList.words[i][length] != '\0') {
            length++;
        }
        if (length > maxLength) {
            maxLength = length;
        }
    }
    
    for (int row = 0; row < maxLength; row++) {
        for (int i = 0; i < wordList.count; i++) {
            if (wordList.words[i][row] != '\0') {
                cout << wordList.words[i][row] << " ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int main() {
    char inputText[MAX_INPUT_LENGTH];
    WordList words;
    int choice;
    
    cout << "=== Обработка текста ===\n";
    cout << "Выберите способ ввода:\n";
    cout << "1 - Ввод с клавиатуры\n";
    cout << "2 - Ввод из файла\n";
    cout << "Ваш выбор: ";
    cin >> choice;
    cin.ignore();
    
    if (choice == 1) {
        cout << "\nВведите текст (завершите точкой):\n";
        cin.getline(inputText, MAX_INPUT_LENGTH);
        
        int length = 0;
        while (inputText[length] != '\0') {
            length++;
        }
        
        if (length == 0 || inputText[length - 1] != '.') {
            cout << "Ошибка: текст должен заканчиваться точкой!\n";
            return 1;
        }
        
        inputText[length - 1] = '\0';
        
    } else if (choice == 2) {
        char filename[100];
        cout << "\nВведите имя файла: ";
        cin >> filename;
        
        FILE* file = fopen(filename, "r");
        if (file == NULL) {
            cout << "Ошибка: не удалось открыть файл!\n";
            return 1;
        }
        
        int index = 0;
        while (index < MAX_INPUT_LENGTH - 1) {
            int ch = fgetc(file);
            if (ch == EOF) break;
            
            if (ch == '\n') {
                ch = ' ';
            }
            
            inputText[index] = (char)ch;
            index++;
        }
        inputText[index] = '\0';
        
        fclose(file);
        
        int length = 0;
        while (inputText[length] != '\0') {
            length++;
        }
        
        if (length == 0 || inputText[length - 1] != '.') {
            cout << "Ошибка: текст в файле должен заканчиваться точкой!\n";
            return 1;
        }
        
        inputText[length - 1] = '\0';
        
    } else {
        cout << "Ошибка: неверный выбор!\n";
        return 1;
    }
    
    words = processText(inputText);
    
    if (words.count == 0) {
        cout << "Ошибка: не найдено ни одного слова!\n";
        return 1;
    }
    
    if (words.count > MAX_WORDS) {
        cout << "Ошибка: слишком много слов (максимум " << MAX_WORDS << ")!\n";
        return 1;
    }
    
    for (int i = 0; i < words.count; i++) {
        int length = 0;
        while (words.words[i][length] != '\0') {
            length++;
        }
        
        if (length == 0 || length > 10) {
            cout << "Ошибка: слово должно содержать от 1 до 10 символов!\n";
            cout << "Проблемное слово: " << words.words[i] << endl;
            return 1;
        }
    }
    
    cout << "\n=== Результаты обработки ===\n";
    
    cout << "\n1. Обработанные слова:\n";
    for (int i = 0; i < words.count; i++) {
        cout << words.words[i];
        if (i < words.count - 1) {
            cout << " ";
        }
    }
    cout << ".\n";
    
    WordList sortedWords;
    sortedWords.count = words.count;
    for (int i = 0; i < words.count; i++) {
        copyWord(sortedWords.words[i], words.words[i]);
    }
    
    sortWordsAlphabetically(sortedWords);
    cout << "\n3. Слова в алфавитном порядке:\n";
    for (int i = 0; i < sortedWords.count; i++) {
        cout << sortedWords.words[i];
        if (i < sortedWords.count - 1) {
            cout << " ";
        }
    }
    cout << ".\n";
    
    printWordsVertically(words);
    
    return 0;
}