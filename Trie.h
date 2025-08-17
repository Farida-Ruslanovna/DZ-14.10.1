#pragma once


#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
#include <unordered_map>

// Класс узла Trie
class TrieNode {
public:
    bool is_end_of_word; 
    std::unordered_map<char, TrieNode*> children; // Дети узла (следующие символы)

    TrieNode();  // Конструктор
    ~TrieNode(); // Деструктор для освобождения памяти
};

// Класс Trie (дерево для автодополнения)
class Trie {
public:
    Trie();
    ~Trie();

    // Вставка слова в Trie
    void insert(const std::string& word);
    // Поиск узла по префиксу
    TrieNode* findNode(const std::string& prefix);
    // Рекурсивный поиск всех слов, начинающихся с данного узла
    void findAllWords(TrieNode* node, const std::string& prefix, std::vector<std::string>& results);

private:
    TrieNode* root; // Корень дерева
    // Функция для удаления дерева
    void deleteTrie(TrieNode* node);
};

#endif 