#include <iostream>
#include <locale>
#include <cwctype> // для towlower и towupper
#include <string>

int main() {
    // Устанавливаем русскую локаль
    std::locale::global(std::locale("ru_RU.utf8"));
    std::wcin.imbue(std::locale());
    std::wcout.imbue(std::locale());

    std::wstring input;
    wchar_t choice;

    // Ввод строки
    std::wcout << L"Введите строку: ";
    std::getline(std::wcin, input);

    // Ввод выбора регистра
    std::wcout << L"Выберите регистр (L - нижний, U - верхний): ";
    std::wcin >> choice;

    // Преобразование строки
    if (choice == L'L' || choice == L'l') {
        for (wchar_t &ch : input) ch = std::towlower(ch);
        std::wcout << L"Строка в нижнем регистре: " << input << std::endl;
    } 
    else if (choice == L'U' || choice == L'u') {
        for (wchar_t &ch : input) ch = std::towupper(ch);
        std::wcout << L"Строка в верхнем регистре: " << input << std::endl;
    } 
    else {
        std::wcout << L"Некорректный выбор регистра!" << std::endl;
        return 1;
    }

    return 0;
}
