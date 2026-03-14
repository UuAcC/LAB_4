#pragma once
#include <vector>
#include <iostream>
#include <random>

using namespace std;

enum class SkipErrors { EMPTY, ALREADY_EXISTS, OUT_OF_ORDER };

template<class T>
struct SkipLink {
	vector<SkipLink<T>*> nexts;  
	T val; int lvl;
	SkipLink(int l, const T& v) : val(v), lvl(l), nexts(l + 1, nullptr) {}
    SkipLink(int l) : val(T()), lvl(l), nexts(l + 1, nullptr) {}
};

template<class T>
class Iterator {
private:
    SkipLink<T>* curr;
public:
    Iterator(SkipLink<T>* node) : curr(node) {}
    bool hasNext() { return curr != nullptr; }
    T next() {
        if (!hasNext()) throw SkipErrors::EMPTY;
        T val = curr->val;
        curr = curr->nexts[0];
        return val;
    }
};

//template<class T> bool SkipList<T>::SkipListRandomInitialized;

template<class T>
class SkipList {
protected:
    SkipLink<T>* head;
    vector<SkipLink<T>*> lasts;
    int maxLevel;
    int genLevel() {
        if (!SkipListRandomInitialized) initRandom();
        int level = 0;
        while (level < maxLevel && 
            (static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) > 0.5) {
            ++level;
        } return level;
    }
    void updateLasts() {
        SkipLink<T>* t = head;
        for (int i = maxLevel; i >= 0; i--) {
            while (t->nexts[i]) { t = t->nexts[i]; }
            lasts[i] = t;
        }
    }
    static bool SkipListRandomInitialized;
public:
    static void initRandom() { 
        srand(time(nullptr));
        SkipListRandomInitialized = true;
    }
    SkipList(const T& headval, int maxLvl = 3) : maxLevel(maxLvl) {
        if (!SkipListRandomInitialized) initRandom();
        head = new SkipLink<T>(maxLevel, headval);
        lasts = vector<SkipLink<T>*>(maxLevel + 1, head);
    }
    SkipList(const SkipList& other) { // вроде O(N*logN)
        if (!SkipListRandomInitialized) initRandom();
        this->maxLevel = other.maxLevel;
        this->head = new SkipLink<T>(maxLevel, other.head->val);
        this->lasts = vector<SkipLink<T>*>(maxLevel + 1, head);
        auto currToCpy = other.head->nexts[0];
        while (currToCpy) {
            this->insert(currToCpy->val);
            currToCpy = currToCpy->nexts[0]; // без перекрутки реализовать.
        }
        this->updateLasts();
    }
    SkipList& operator=(const SkipList& other) {
        if (this != &other) {
            this->clear(); 
            delete this->head;
            if (!SkipListRandomInitialized) initRandom();
            this->maxLevel = other.maxLevel;
            this->head = new SkipLink<T>(maxLevel, other.head->val);
            this->lasts = vector<SkipLink<T>*>(maxLevel + 1, head);
            auto currToCpy = other.head->nexts[0];
            while (currToCpy) {
                this->insert(currToCpy->val);
                currToCpy = currToCpy->nexts[0];
            }
            this->updateLasts();
        }
        return *this;
    }
    SkipList(SkipList&& other) noexcept {
        this->head = other.head;
        other.head = nullptr;
        this->maxLevel = other.maxLevel;
        other.maxLevel = NULL;
        lasts = std::move(other.lasts);
    }
    SkipList& operator=(SkipList&& other) noexcept {
        if (this != &other) {
            this->clear(); 
            delete this->head;
            this->head = other.head;
            other.head = nullptr;
            this->maxLevel = other.maxLevel;
            other.maxLevel = NULL;
            lasts = std::move(other.lasts);
        }
        return *this;
    }
    Iterator<T> itr() const { 
        return Iterator<T>(head->nexts[0]); 
    }
    void insert(const T& v) { // должно быть O(logN)
        vector<SkipLink<T>*> to_update(maxLevel + 1, nullptr);
        SkipLink<T>* curr = head;

        for (int i = maxLevel; i >= 0; i--) {
            while (curr->nexts[i] && curr->nexts[i]->val > v) {
                curr = curr->nexts[i];
            }
            to_update[i] = curr;
        }
        curr = curr->nexts[0];

        if (curr && curr->val == v) {
            throw SkipErrors::ALREADY_EXISTS;
        }

        int newLevel = genLevel();
        auto newNode = new SkipLink<T>(newLevel, v);

        for (int i = 0; i <= newLevel; i++) {
            newNode->nexts[i] = to_update[i]->nexts[i];
            to_update[i]->nexts[i] = newNode;
        }
        this->updateLasts();
    }
    void addLast(const T& v) { // O(1) вроде
        if (v > lasts[0]->val) throw SkipErrors::OUT_OF_ORDER;
        if (v == lasts[0]->val) throw SkipErrors::ALREADY_EXISTS;
        else {
            int newLevel = genLevel();
            auto newNode = new SkipLink<T>(newLevel, v);
            for (int i = 0; i <= newLevel; ++i) {
                lasts[i]->nexts[i] = newNode;
                lasts[i] = newNode;
            }
        }
    }
    bool isEmpty() { return head->nexts[0] == nullptr; }
    void delFirst() {
        if (isEmpty()) throw SkipErrors::EMPTY;
        SkipLink<T>* to_del = head->nexts[0];
        for (int i = to_del->lvl; i >= 0; i--) {
            head->nexts[i] = to_del->nexts[i];
        }
        delete to_del;
        this->updateLasts();
    }
    void clear() { while (!isEmpty()) { delFirst(); } }
    ~SkipList() { if (head) { clear(); delete head; } }
};