#include <utility>

#ifndef SingleLinkedList_H_
#define SingleLinkedList_H_

template <typename T>
class SingleLinkedList {
public:
	class Node {
	public:
		T data;
		Node* next;

		Node (T&& value) : data(std::move(value)), next(nullptr) {} // * ->&&
	};
private:
	Node* head;

public:
	SingleLinkedList() : head(nullptr) {}
	inline ~SingleLinkedList() {
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
		Node* temp = head;
		while (temp != nullptr && temp->next != nullptr) {
			temp = temp->next;
		}
		return temp;
	}

	Node* last() {
		return const_cast<Node*>(const_cast<const SingleLinkedList<T>*>(this)->last());
	}

	template<typename... Type>
	void push_front(Type&&... values) {
		Node* new_temp = new Node(std::forward<Type>(values)...);
		if (head == nullptr) {
			head = new_temp;
			return;
		}
		new_temp->next = head;
		head = new_temp;
	}

	template<typename... Type>
	void push_back(Type&&... values) {
		Node* new_temp = new Node(std::forward<Type>(values)...);
		if (head == nullptr) {
			head = new_temp;
			return;
		}
		Node* lastNode = last();
		lastNode->next = new_temp;
	}

	void pop_back() {
		if (head == nullptr) {
			return;
		}
		if (head->next == nullptr) {
			delete head;
			head = nullptr;
			return;
		}
		Node* temp = head;
		while (temp->next->next != nullptr) {
			temp = temp->next;
		}
		delete temp->next;
		temp->next = nullptr;
	}

	void pop_front() {
		if (head == nullptr) {
			return;
		}
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	template<typename... Type>
	void insert(Node* temp, Type&&... values) {
		Node* new_temp = new Node(std::forward<Type>(values)...);
		new_temp->next = temp->next;
		temp->next = new_temp;
	}

	void clear() {
		Node* temp = nullptr;
		while (head) {
			temp = head;
			head = head->next;
			delete temp;
		}
	}

	void remove(const T& value) {
		if (!head) return;

		if (head->data == value) {
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}

		Node* current_temp = head;
		while (current_temp->next && current_temp->next->data != value) {
			current_temp = current_temp->next;
		}

		if (current_temp->next) {
			Node* temp = current_temp->next;
			current_temp->next = current_temp->next->next;
			delete temp;
		}
	}
};

#endif // !SingleLinkedList_H_
