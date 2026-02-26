#pragma once
#include <vector>
#include <iostream>
#include <random>

template<class T>
struct SkipLink {
	std::vector<SkipLink*> nextLinks; 
	T value; int level;
	SkipLink(int l = 0, SkipLink* next_bot = nullptr) : value(T()), level(l) {
		nextLinks[0] = next_bot; 
		for (int i = 0; i < level; ++i) {
			int j = i + 1;
			this->nextLinks[j] = this->nextLinks[i];
			if (this->nextLinks[j] != nullptr) {
				this->nextLinks[j] = this->nextLinks[j]->nextLinks[i];
			}
		}
	}
	SkipLink(T v, int l = 0, SkipLink* next_bot = nullptr) : value(v), level(l) {
		nextLinks[0] = next_bot;
		for (int i = 0; i < level; ++i) {
			int j = i + 1;
			this->nextLinks[j] = this->nextLinks[i];
			if (this->nextLinks[j] != nullptr) {
				this->nextLinks[j] = this->nextLinks[j]->nextLinks[i];
			}
		}
	}
};

template<class T>
class SkipIterator {
	SkipLink<T>* t;
public:
	SkipIterator(SkipLink<T>* _t) : t(_t) {}
	bool hasNext() { return t != nullptr; }
	T next() {
		if (!hasNext()) throw - 1;
		T curr = t->val; t = t->next;
		return curr;
	}
};

template<class T>
class SkipList {
	SkipLink* head;
	SkipLink* last;
	void addAfter(SkipLink* link, T val) {

	}
};