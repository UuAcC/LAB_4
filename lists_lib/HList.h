#pragma once
#include <utility>
#include <iostream>

template<class T>
struct HLink {
	T val;
	HLink<T>* next;
	HLink() : val(T()), next(this) {}
	HLink(const T& _val) : val(_val), next(this) {}
	HLink(const T& _val, HLink* _next) : val(_val), next(_next) {}
};

template<class T>
class Iterator {
	HLink<T>* curr;
	HLink<T>* head;
public:
	Iterator(HLink<T>* c, HLink<T>* l) : curr(c), head(l) {}
	bool hasNext() { return curr != head; }
	T next() {
		if (!hasNext()) throw - 1;
		T curr_val = curr->val; curr = curr->next;
		return curr_val;
	}
};

template<class T>
class HList {
protected:
	HLink<T>* head;
	HLink<T>* last;
	HLink<T>* addAfter(HLink<T>* p, T val) {
		HLink<T>* t = new HLink<T>(val, p->next);
		p->next = t;
		return t;
	}
public:
	HList() { head = new HLink<T>(); last = head; }
	HList(const HList<T>& other) {
		HLink<T>* t1 = other.head->next;
		head = new HLink<T>();
		last = head;
		while (t1 != other.head) {
			addLast(t1->val);
			t1 = t1->next;
		}
	}
	HList<T>& operator=(const HList<T>& other) {
		if (this == &other) return *this;
		this->clear(); delete this->head;
		HLink<T>* t1 = other.head->next;
		head = new HLink<T>();
		last = head;
		while (t1 != other.head) {
			addLast(t1->val);
			t1 = t1->next;
		}
		return *this;
	}
	HList(HList<T>&& other) noexcept {
		head = other.head; other.head = nullptr;
		last = other.last; other.last = nullptr;
	}
	HList<T>& operator=(HList<T>&& other) noexcept {
		if (this == &other) return *this;
		this->clear(); delete this->head;
		head = other.head; other.head = nullptr;
		last = other.last; other.last = nullptr;
		return *this;
	}
	void addFirst(T val) { addAfter(head, val); }
	void addLast(T val) { last = addAfter(last, val); }
	void insertAfter(int i, T val) {
		HLink<T>* t = head; int j = 0;
		while ((head != last) && (j < i)) {
			t = t->next; ++i;
		} if (j != i) throw - 1;
		addAfter(t->next, val);
	}
	void clear() { while (head != last) { delFirst(); } }
	~HList() { clear(); delete head; }
	void delFirst() {
		if (head == last) throw - 1;
		HLink<T>* to_del = head->next;
		if (to_del == last) { head->next = head; last = head; }
		else { head->next = to_del->next; }
		delete to_del;
	}
	void delLast() {
		if (head == last) throw - 1;
		HLink<T>* t = head;
		while (t->next != last)
			t = t->next;
		delete last;
		t->next = head; last = t;
	}
	Iterator<T> itr() const { return Iterator<T>(head->next, head); }
	friend std::ostream& operator<<(std::ostream& out, const HList<T>& list) {
		Iterator<T> iter = list.itr(); out << "[ ";
		if (iter.hasNext()) { out << iter.next(); }
		while (iter.hasNext()) { out << ", " << iter.next(); }
		out << " ]"; return out;
	}
};