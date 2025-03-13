#ifndef DoubleLinkedList_H_
#define DoubleLinkedList_H_

#include <cstddef>
#include <utility>

template <typename T>
class DoubleLinkedList {
private:
	struct Node {
		T data;
		Node* next;
		Node* prev;

		template<typename... Type>
		Node(Type&&... values) : data(std::forward<Type>(values)...), next(nullptr), prev(nullptr) {}
	};

	Node* head;
	Node* tail;

public:
	DoubleLinkedList() : head(nullptr), tail(nullptr) {}

	~DoubleLinkedList() {
		clear();
	}

	bool empty() const {
		return head == nullptr;
	}

	std::size_t size() const {
		std::size_t SIZE = 0;
		Node* temp = head;
		while (temp != nullptr) {
			SIZE++;
			temp = temp->next;
		}
		return SIZE;
	}

	const Node* first() const {
		return head;
	}

	Node* first() {
		return head;
	}

	const Node* last() const {
		return tail;
	}

	Node* last() {
		return tail;
	}

	template<typename... Type>
	void push_front(Type&&... values) {
		Node* new_temp = new Node(std::forward<Type>(values)...);
		if (head == nullptr) {
			head = tail = new_temp;
			return;
		}
		new_temp->next = head;
		head->prev = new_temp;
		head = new_temp;
	}

	template<typename... Type>
	void push_back(Type&&... values) {
		Node* new_temp = new Node(std::forward<Type>(values)...);
		if (tail == nullptr) {
			head = tail = new_temp;
			return;
		}
		new_temp->prev = tail;
		tail->next = new_temp;
		tail = new_temp;
	}

	void pop_front() {
		if (head == nullptr) {
			return;
		}
		Node* temp = head;
		head = head->next;
		if (head) {
			head->prev = nullptr;
		} else {
			tail = nullptr;
		}
		delete temp;
	}

	template<typename... Type>
	void insert(Node* temp, Type&&... values) {
		if (!temp) return;
		Node* new_temp = new Node(std::forward<Type>(values)...);
		new_temp->next = temp->next;
		new_temp->prev = temp;
		if (temp->next) {
			temp->next->prev = new_temp;
		} else {
			tail = new_temp;
		}
		temp->next = new_temp;
	}

	void clear() {
		Node* temp = nullptr;
		while (head) {
			temp = head;
			head = head->next;
			delete temp;
		}
		tail = nullptr;
	}

	void remove(const T& value) {
		if (!head) return;

		if (head->data == value) {
			Node* temp = head;
			head = head->next;
			if (head) {
				head->prev = nullptr;
			} else {
				tail = nullptr;
			}
			delete temp;
			return;
		}

		Node* current_temp = head;
		while (current_temp && current_temp->data != value) {
			current_temp = current_temp->next;
		}

		if (current_temp) {
			if (current_temp->next) {
				current_temp->next->prev = current_temp->prev;
			} else {
				tail = current_temp->prev;
			}
			current_temp->prev->next = current_temp->next;
			delete current_temp;
		}
	}
};

#endif // !DoubleLinkedList_H_
