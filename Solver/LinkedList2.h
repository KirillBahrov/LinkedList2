#include <iostream>
#include <string>
#include <initializer_list>
#include <stdexcept>
#include <sstream>

namespace RUT::MIIT {

    template<typename T>
    /**
    * @brief класс линейный односвязный список
    */
    class LinkedList {
    private:
        /**
        * @brief структура, представляющая один элемент списка
        */
        struct Node {
            T data;
            Node* next = nullptr;

            Node(T value) : data(value), next(nullptr) {}
        };

        Node* head;

        /**
        * @brief метод, использующийся для копирования всех эл-тов из LinkedList<T> в текущий объект списка
        * @param other(const LinkedList&): список, элементы которого нужно копировать в текущий объект списка
        */
        void copy(const LinkedList& other);

    public:
        /**
        * @brief конструктор по умолчанию
        */
        LinkedList();

        /**
        * @brief конструктор с инициализированным списком
        * @param initializer_list<T> инициализированный список
        */
        LinkedList(std::initializer_list<T> values);

        /**
        * @brief конструктор копирования
        */
        LinkedList(const LinkedList& other);

        /**
        * @brief конструктор перемещения
        */
        LinkedList(LinkedList&& other) noexcept;

        /**
        * @brief деструктор
        */
        ~LinkedList();

        /**
        * @brief оператор присваивания/копирования
        */
        LinkedList& operator=(const LinkedList& other);

        /**
        * @brief метод обмена
        */
        void swap(LinkedList& other) noexcept;

        /**
        * @brief метод, проверяющий пуст ли список
        * @return true, если список пуст
        * @return false, если список не пуст
        */
        bool isEmpty() const;

        /**
        * @brief метод, возвращающий строковое представление списка
        * @param Node* head - головной узел связного списка
        */
        std::string ToString() const;

        /**
        * @brief метод, добавляющий элемент в конце списка
        */
        void pushBack(const T& value);

        /**
        * @brief метод, добавляющий новый элемент в начало списка
        */
        void pushFront(T value const);

        /**
        * @brief метод, удаляющий последний элемент списка
        */
        void popBack();

        /**
        * @brief метод, удаляющий первый элемент списка
        */
        void popFront();

        /**
        * @brief метод, вставляющий эл-т в список на указанную позицию idx
        */
        void insert(size_t idx, T elem);

        /**
        * @brief метод, удаляющий эл-т по указанному индексу idx
        */
        void remove(size_t idx);

        /**
        * @brief метод, очищающий список, удаляя все эл-ты
        */
        void clear();

        friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);
    };

    template<typename T>
    inline LinkedList<T>::LinkedList() : 
    {
        Node* Head = nullptr;
    };

    template<typename T>
    inline void LinkedList<T>::copy(const LinkedList& other)
    {
        Node* current = other.head;
        while (current != nullptr)
        {
            pushBack(current->data);
            current = current->next;
        }
    }

    template<typename T>
    inline LinkedList<T>::LinkedList(std::initializer_list<T> values)
    {
        for (const auto& value : values) {
            pushBack(value);
        }
    };

    template<typename T>
    inline LinkedList<T>::LinkedList(const LinkedList& other)
    {
        Node* current = other.head;
        while (current != nullptr) {
            pushBack(current->data);
            current = current->next;
        }
    };

    template<typename T>
    inline LinkedList<T>::LinkedList(LinkedList&& other) noexcept
    {
        other.head = nullptr;
    };

    template<typename T>
    inline LinkedList<T>::~LinkedList()
    {
        clear();
    };

    template<typename T>
    inline LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other)
    {
        if (this != &other) {
            LinkedList<T> copy(other);
            swap(copy);
        }
        return *this;
    };

    template<typename T>
    inline void LinkedList<T>::swap(LinkedList& other) noexcept
    {
        std::swap(head, other.head);
    };

    template<typename T>
    inline bool LinkedList<T>::isEmpty() const
    {
        return head == nullptr;
    };

    template<typename T>
    inline std::string LinkedList<T>::ToString() const
    {
        std::ostringstream oss{};
        Node* current = head;

        while (current != nullptr) {
            oss << current->data << " -> ";
            current = current->next;
        }

        return oss.str();
    };

    template<typename T>
    inline void LinkedList<T>::pushBack(const T& value)
    {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    };

    template<typename T>
    inline void LinkedList<T>::pushFront(const T& value)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
};

    template<typename T>
    inline void LinkedList<T>::popBack()
    {
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
    };

    template<typename T>
    inline void LinkedList<T>::popFront()
    {
        if (isEmpty()) throw std::out_of_range("List is empty");
        Node* temp = head;
        head = head->next;
        delete temp;
    };

    template<typename T>
    inline void LinkedList<T>::insert(size_t idx, const T& elem)
    {
        if (idx == 0) {
            pushFront(elem);
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
    };

    template<typename T>
    inline void LinkedList<T>::remove(size_t idx)
    {
        if (isEmpty()) throw std::out_of_range("Invalid index");
        if (idx == 0) {
            popFront();
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
    };

    template<typename T>
    inline void LinkedList<T>::clear()
    {
        while (!isEmpty()) {
            popFront();
        }
    };

    template<typename T>
    inline std::ostream& LinkedList<T>::operator<<(std::ostream& os, const LinkedList& list)
    {
        os << LinkedList.ToString();
        return os;
    };
