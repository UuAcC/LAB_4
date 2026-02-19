#pragma once

template<class T>
struct Link {
	T val;
	Link* next;
	Link(T _val = 0, Link* _next = nullptr) : val(_val), next(_next) {}
};

template<class T>
class Iterator {
	Link<T>* t;
public:
	Iterator(Link<T>* _t) : t(_t) {}
	bool hasNext() { return t != nullptr; }
	T next() {
		if (!hasNext()) throw - 1;
		T curr = t->val; t = t->next;
		return curr;
	}
};

template<class T>
class List {
	Link<T>* fp;
public:
	List() { fp = nullptr; }
	~List() { clean(); }
	void delFirst() {
		if (fp == nullptr) return;
		Link<T>* t = fp;
		fp = fp->next;
		delete t;
	}
	void clean() {
		while (fp != nullptr)
			delFirst();
	}
	void addFirst(T v) {
		Link<T>* l = new Link<T>(v, fp);
		fp = l;
	}
	List(const List<T>& other) {
		Link<T>* t1 = other.fp;
		if (t1 == nullptr) {
			fp = nullptr;
			return;
		}
		fp = new Link<T>(t1->val);
		Link<T>* t2 = fp;
		while (t1->next != nullptr) {
			t1 = t1->next;
			t2->next = new Link<T>(t1->val);
			t2 = t2->next;
		}
	}
	T& operator[](int ind) {
		if (ind < 0) throw - 1;
		Link<T>* t = fp;
		for (int i = 0; i < ind; ++i) {
			if (t == nullptr) throw - 1;
			t = t->next;
		}
		if (t == nullptr) throw - 1;
		return t->val;
	}
	int size() {
		int cnt = 0;
		Link<T>* t = fp;
		while (t != nullptr) {
			++cnt; t = t->next;
		}
	}
	void delInd(int n) {
		if (n == 0) { delFirst(); return; }
		Link<T>* temp = fp;
		while (n > 1) {
			if (temp == nullptr) throw - 1;
			temp = temp->next;
			n--;
		}
		Link<T>* d = temp->next;
		temp->next = d->next;
		delete d;
	}
};
