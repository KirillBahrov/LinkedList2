#include <iostream>
#include <string>
#include <initializer_list>
#include <stdexcept>

namespace RUT::MIIT {

    template<typename T>
    class LinkedList {
    private:
        struct Node {
            T data;
            Node* next = nullptr;

            Node(T value) : data(value), next(nullptr) {}
        };

        Node* head;

    public:
        LinkedList() : head(nullptr) {}

        LinkedList(std::initializer_list<T> values) : head(nullptr) {
            for (const auto& value : values) {
                push_back(value);
            }
        }

        LinkedList(const LinkedList& other) : head(nullptr) {
            Node* current = other.head;
            while (current) {
                push_back(current->data);
                current = current->next;
            }
        }

        LinkedList(LinkedList&& other) noexcept : head(other.head) {
            other.head = nullptr;
        }

        ~LinkedList() {
            clear();
        }

        LinkedList& operator=(const LinkedList& other) {
            if (this != &other) {
                clear();
                Node* current = other.head;
                while (current) {
                    push_back(current->data);
                    current = current->next;
                }
            }
            return *this;
        }

        bool isEmpty() const {
            return head == nullptr;
        }

        std::string toString() const {
            std::string result;
            Node* current = head;
            while (current) {
                result += std::to_string(current->data) + " -> ";
                current = current->next;
            }
            result += "null";
            return result;
        }

        void push_back(T value) {
            Node* newNode = new Node(value);
            if (isEmpty()) {
                head = newNode;
            }
            else {
                Node* current = head;
                while (current->next) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }

        void push_front(T value) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }

        void pop_back() {
            if (isEmpty()) throw std::out_of_range("List is empty");
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
            }
            else {
                Node* current = head;
                while (current->next->next) {
                    current = current->next;
                }
                delete current->next;
                current->next = nullptr;
            }
        }

        void pop_front() {
            if (isEmpty()) throw std::out_of_range("List is empty");
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        void insert(int idx, T elem) {
            if (idx < 0) throw std::out_of_range("Index cannot be negative");
            if (idx == 0) {
                push_front(elem);
                return;
            }
            Node* current = head;
            for (int i = 0; current != nullptr && i < idx - 1; ++i) {
                current = current->next;
            }
            if (current == nullptr) throw std::out_of_range("Index exceeds list size");
            Node* newNode = new Node(elem);
            newNode->next = current->next;
            current->next = newNode;
        }

        void remove(int idx) {
            if (idx < 0 || isEmpty()) throw std::out_of_range("Invalid index");
            if (idx == 0) {
                pop_front();
                return;
            }
            Node* current = head;
            for (int i = 0; current != nullptr && i < idx - 1; ++i) {
                current = current->next;
            }
            if (current == nullptr || current->next == nullptr) throw std::out_of_range("Index exceeds list size");
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }

        void clear() {
            while (!isEmpty()) {
                pop_front();
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
            os << list.toString();
            return os;
        }
    };
}

