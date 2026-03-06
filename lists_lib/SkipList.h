#pragma once
#include <vector>
#include <iostream>
#include <random>

using namespace std;

#define STCtoD static_cast<double>

enum class SkipErrors { ITER_EMPTY, ALREADY_EXISTS };

template<class T>
struct SkipLink {
	vector<SkipLink<T>*> nexts;  
	T val; int lvl;
	SkipLink(int l, const T& v) : val(v), lvl(l + 1), nexts(l + 1, nullptr) {}
    SkipLink(int l) : val(T()), lvl(l + 1), nexts(l + 1, nullptr) {}
};

template<class T>
class Iterator {
private:
    SkipLink<T>* current;
public:
    Iterator(SkipLink<T>* node) : current(node) {}
    bool hasNext() { return current != nullptr; }
    T next() {
        if (!hasNext()) throw SkipErrors::ITER_EMPTY;
        T val = current->value;
        current = current->nextLinks[0];
        return val;
    }
};

template<class T>
class SkipList {
protected:
    SkipLink<T>* head;
    int maxLevel;
    int genLevel() {
        int level = 0;
        while (level < maxLevel && (STCtoD(rand()) / STCtoD(RAND_MAX))) {
            ++level;
        } return level;
    }
public:
    SkipList(int maxLvl = 4, T headval) : maxLevel(maxLvl) {
        srand(time(nullptr));
        head = new SkipLink<T>(headval, maxLevel);
    }
    void insert(const T& v) {
        vector<SkipLink<T>*> to_update(maxLevel + 1, nullptr);
        SkipLink<T>* curr = head;

        for (int i = maxLevel; i >= 0; i--) {
            while (curr->nexts[i] && curr->nexts[i]->val < v) {
                curr = curr->nexts[i];
            }
            to_update[i] = curr;
        }
        curr = curr->nexts[0];

        if (curr && curr->val == v) {
            throw SkipErrors::ALREADY_EXISTS;
        }

        int newLevel = genLevel();
        auto newNode = new SkipLink<T>(v, newLevel);

        for (int i = 0; i <= newLevel; i++) {
            newNode->nexts[i] = to_update[i]->nexts[i];
            to_update[i]->nexts[i] = newNode;
        }
    }
    bool isEmpty() { return head->nexts[0] == nullptr; }
    void delFirst() {
        SkipLink<T>* to_del = head->nexts[0];
        for (int i = to_del->lvl; i >= 0; i--) {
            head->nexts[i] = to_del->nexts[i];
        }
        delete to_del;
    }
    void clear() { while (!isEmpty()) { delFirst(); } }
};