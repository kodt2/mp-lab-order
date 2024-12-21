#include <iostream>
template<typename T>
class Tlist {
private:
	struct Node {
		T data;
		Node* next;
	};
	class iterator {
	public:
		Node* node;
		iterator() {
			node = nullptr;
		}
		iterator(Node* n) {
			node = n;
		}
		Node& operator*() {
			return *node;
		}
		Node operator*() const {
			return *node;
		}
		iterator& operator++() {
			node = node->next;
			return *this;
		}
		bool operator==(iterator iter) {
			return node == iter.node;
		}
		bool operator!=(iterator iter) {
			return node != iter.node;
		}
	};
	Node* first;
	Node* e;
public:
	Tlist() {
		first = nullptr;
		e = nullptr;
	};
	~Tlist() {
		Node* current = first;
		Node* temp;
		while (current != nullptr) {
			temp = current;
			current = current->next;
			delete temp;
		}
		first = nullptr;
		e = nullptr;
	};
	iterator push_back(T value) {
		if (e != nullptr && first != nullptr) {
			Node* temp = new Node();
			e->next = temp;
			e = temp;
			return iterator(first);
		}
		else {
			Node* temp = new Node();
			e = temp;
			first = temp;
			return iterator(first);
		}
	};
	T top() {
		if (first == nullptr) {
			throw "order is empty";
		}
		return first->data;
	}
	iterator pop() {
		if (first == nullptr) {
			throw "order is empty";
		}
		Node* temp = first;
		first = first->next;
		delete temp;
		return iterator(first);
	};
	size_t size() {
		size_t i = 0;
		Node* current = first;
		while (current != nullptr) {
			//std::cout << current->data << " ";
			current = current->next;
			i++;
		}
		return i;
	};
	bool operator==(const Tlist& list) const {
		bool res = true;
		Node* current2 = list.first;
		Node* current1 = first;
		while (current1 != nullptr || current2 != nullptr) {
			if ((current1 == nullptr && current2 != nullptr) || (current2 == nullptr && current1 != nullptr)) {
				res = false;
				return res;
			}
			if (current1->data != current2->data) {
				res = false;
				return res;
			}
			current1 = current1->next;
			current2 = current2->next;
		}
		return res;
	}
	bool operator!=(const Tlist& list) const {
		return !(*this == list);
	}
};