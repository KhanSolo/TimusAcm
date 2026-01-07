// Accepted

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<string, int>> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i].first >> words[i].second;
    }

    // Сортируем по алфавиту
    sort(words.begin(), words.end());

    int M;
    cin >> M;

    vector<string> queries(M);
    for (int i = 0; i < M; ++i) {
        cin >> queries[i];
    }

    // Для сохранения результатов для уникальных префиксов
    unordered_map<string, vector<string>> precomputed;

    // Обрабатываем каждый уникальный префикс
    for (const string& prefix : queries) {
        // Если уже обработали, пропускаем
        if (precomputed.find(prefix) != precomputed.end()) {
            continue;
        }

        // Находим диапазон слов с префиксом prefix
        auto start_it = lower_bound(words.begin(), words.end(), make_pair(prefix, 0),
            [](const pair<string, int>& a, const pair<string, int>& b) {
                return a.first < b.first;
            });

        // Если нет слов с таким префиксом, сохраняем пустой вектор
        if (start_it == words.end() || start_it->first.compare(0, prefix.size(), prefix) != 0) {
            precomputed[prefix] = vector<string>();
            continue;
        }

        // Min-heap для хранения топ-10 (частота, слово)
        // Компаратор: меньшая частота или при равной частоте — большее слово (по алфавиту) будет наверху
        auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);

        // Проходим по всем словам с данным префиксом
        for (auto it = start_it; it != words.end() && it->first.compare(0, prefix.size(), prefix) == 0; ++it) {
            pq.push({it->second, it->first});
            if (pq.size() > 10) {
                pq.pop();
            }
        }

        // Извлекаем из heap и сортируем по убыванию частоты, при равенстве — по алфавиту
        vector<pair<int, string>> temp;
        while (!pq.empty()) {
            temp.push_back(pq.top());
            pq.pop();
        }
        sort(temp.begin(), temp.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });

        // Сохраняем только слова (в нужном порядке)
        vector<string> result;
        for (const auto& p : temp) {
            result.push_back(p.second);
        }
        precomputed[prefix] = result;
    }

    // Вывод результатов для запросов
    bool first_query = true;
    for (const string& prefix : queries) {
        if (!first_query) {
            cout << "\n";
        }
        first_query = false;

        const vector<string>& result = precomputed[prefix];
        for (const string& word : result) {
            cout << word << "\n";
        }
    }

    return 0;
}