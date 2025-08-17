#include "Trie.h"


// Конструктор узла Trie
TrieNode::TrieNode() : is_end_of_word(false) {}

// Деструктор узла Trie для очистки памяти рекурсивно
TrieNode::~TrieNode() {
    for (auto& pair : children) {
        delete pair.second; // Удаляем всех детей
    }
}

// Конструктор Trie
Trie::Trie() {
    root = new TrieNode(); // Создаем корень
}

// Деструктор Trie
Trie::~Trie() {
    deleteTrie(root); // Удаляем все узлы
}

// Функция для рекурсивного удаления узлов
void Trie::deleteTrie(TrieNode* node) {
    if (!node) return;
    for (auto& pair : node->children) {
        deleteTrie(pair.second); // Удаляем дочерние узлы
    }
    delete node; // Удаляем текущий узел
}

// Вставка слова в Trie
void Trie::insert(const std::string& word) {
    TrieNode* current = root;
    for (char ch : word) {
        // Если текущий символ отсутствует, создаем новый узел
        if (current->children.find(ch) == current->children.end()) {
            current->children[ch] = new TrieNode();
        }
        current = current->children[ch]; // Переходим к следующему узлу
    }
    // Помечаем конец слова
    current->is_end_of_word = true;
}

// Поиск узла по префиксу
TrieNode* Trie::findNode(const std::string& prefix) {
    TrieNode* current = root;
    for (char ch : prefix) {
        // Если символ не найден, возвращаем nullptr
        if (current->children.find(ch) == current->children.end()) {
            return nullptr;
        }
        current = current->children[ch]; // Переходим к следующему узлу
    }
    return current; // Возвращаем узел, соответствующий префиксу
}

// Рекурсивный поиск всех слов, начинающихся с данного узла
void Trie::findAllWords(TrieNode* node, const std::string& prefix, std::vector<std::string>& results) {
    if (!node) return;
    if (node->is_end_of_word) {
        results.push_back(prefix); // Добавляем слово, если достигнут конец слова
    }
    // Рекурсивно ищем все дочерние слова
    for (auto& pair : node->children) {
        findAllWords(pair.second, prefix + pair.first, results);
    }
}