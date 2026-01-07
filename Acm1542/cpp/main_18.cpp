#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

// G++ 13.2 x64	  Memory limit exceeded	 18	  0.328	  68 000 КБ

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<string, int>> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i].first >> words[i].second;
    }

    // 1. Группируем по префиксам
    unordered_map<string, vector<pair<int, string>>> prefix_map;

    for (const auto& w : words) {
        const string& word = w.first;
        int freq = w.second;
        // Для каждого префикса этого слова
        for (size_t len = 1; len <= word.size(); ++len) {
            string prefix = word.substr(0, len);
            auto& vec = prefix_map[prefix];
            // Вставляем пару (частота, слово)
            vec.emplace_back(freq, word);
            // Поддерживаем размер не более 10, с сортировкой, чтобы худший был в конце
            if (vec.size() > 10) {
                // Сортируем так, чтобы худшие были в конце
                // Худший: меньшая частота, при равной — большее слово
                auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) {
                    if (a.first != b.first) return a.first < b.first;
                    return a.second > b.second;
                };
                // Ищем минимум
                auto min_it = min_element(vec.begin(), vec.end(), cmp);
                swap(*min_it, vec.back());
                vec.pop_back();
            }
        }
    }

    // 2. Теперь отсортируем для каждого префикса по убыванию частоты, при равенстве — по алфавиту
    for (auto& kv : prefix_map) {
        auto& vec = kv.second;
        sort(vec.begin(), vec.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });
    }

    int M;
    cin >> M;

    bool first_query = true;
    for (int q = 0; q < M; ++q) {
        string prefix;
        cin >> prefix;

        if (!first_query) {
            cout << "\n";
        }
        first_query = false;

        auto it = prefix_map.find(prefix);
        if (it != prefix_map.end()) {
            for (const auto& p : it->second) {
                cout << p.second << "\n";
            }
        }
    }

    return 0;
}