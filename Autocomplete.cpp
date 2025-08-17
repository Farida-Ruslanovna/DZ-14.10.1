// DZ 14.10.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "Trie.h"

int main() {
    setlocale(LC_ALL, "Russian");
    // Инициализация словаря
    std::vector<std::string> dictionary = {
        "apple", "application", "app", "apex",
        "banana", "band", "bandana", "bandwidth",
        "cat", "cater", "cattle"
    };

    // Создаем объект Trie
    Trie trie;
    // Вставляем все слова из словаря
    for (const auto& word : dictionary) {
        trie.insert(word);
    }

    std::cout << "Автодополнение. Введите часть слова или 'exit' для выхода.\n";

    while (true) {
        std::cout << "Введите часть слова: ";
        std::string prefix;
        std::getline(std::cin, prefix); // Ввод пользователя

        if (prefix == "exit") break; // Выход по команде

        // Поиск узла по префиксу
        TrieNode* node = trie.findNode(prefix);
        if (node) {
            std::vector<std::string> suggestions;
            // Получение всех слов с данным префиксом
            trie.findAllWords(node, prefix, suggestions);
            if (!suggestions.empty()) {
                std::cout << "Варианты продолжения:\n";
                for (const auto& word : suggestions) {
                    std::cout << word << "\n"; // Вывод вариантов
                }
            }
            else {
                std::cout << "Нет подходящих вариантов.\n"; // Нет подходящих слов
            }
        }
        else {
            std::cout << "Нет подходящих вариантов.\n"; // Префикс не найден
        }
    }

    return 0;
}