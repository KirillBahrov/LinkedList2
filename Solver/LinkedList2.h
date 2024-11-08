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
        LinkedList() {}

        LinkedList(std::initializer_list<T> values) {
            for (const auto& value : values) {
                push_back(value);
            }
        }

        LinkedList(const LinkedList& other) {
            Node* current = other.head;
            while (current) {
                push_back(current->data);
                current = current->next;
            }
        }

        LinkedList(LinkedList&& other) noexcept {
            other.head = nullptr;
        }

        ~LinkedList() {
            clear();
        }

        LinkedList& operator=(const LinkedList& other) {
            list<T> copy{ other }; 
            swap(copy);
            return *this;
        }



        bool isEmpty() const {
            return head == nullptr;
        }

        std::string ToString(Node* head) {
            std::ostringstream oss; 
            Node* current = head;

            while (current) {
                oss << current->data << " -> "; 
                current = current->next; 
            }

            oss << "null"; 
            return oss.str(); 
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

        void push_front(T value const) {
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

        void insert(size_t idx, T elem) {
            if (idx == 0) {
                push_front(elem);
                return;
            }
            Node* current = head;
            if (current == nullptr) throw std::out_of_range("Index exceeds list size");
            for (size_t i = 0; current != nullptr && i < idx - 1; ++i) {
                current = current->next;
            }
            Node* newNode = new Node(elem);
            newNode->next = current->next;
            current->next = newNode;
        }

        void remove(size_t idx) {
            if ( isEmpty()) throw std::out_of_range("Invalid index");
            if (idx == 0) {
                pop_front();
                return;
            }
            Node* current = head;
            for (size_t i = 0; current != nullptr && i < idx - 1; ++i) {
                current = current->next;
            }
            if (current == nullptr) throw std::out_of_range("Index exceeds list size");
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

