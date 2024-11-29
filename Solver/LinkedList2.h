#include <iostream>
#include <string> 

namespace RUT::MIIT
{
    template <typename T> class LinkedList;

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const RUT::MIIT::LinkedList<T>& list);

    template <typename T>
    class LinkedList
    {
    private:

        struct Node
        {
            T data;
            Node* next = nullptr;
        };
        Node* head;

    public:
        /**
        * @brief конструктор по умолчанию
        */
        LinkedList();


        explicit LinkedList(std::initializer_list<T> values);

        /**
        * @brief конструктор копирования
        */
        LinkedList(const LinkedList& other);

        /**
        * @brief деструктор
        */
        ~LinkedList();

        /**
        * @brief конструктор перемещения
        */

        LinkedList(LinkedList&& other) noexcept;

        /**
        * @brief оператор присваивания/копирования
        */
        LinkedList& operator=(const LinkedList& other);

        /**
        * @brief метод, проверяющий пуст ли список
        * @return true, если список пуст
        * @return false, если список не пуст
        */
        bool isEmpty() const;

        /**
        * @brief метод, возвращающий строковое представление списка
        */
        std::string toString() const;

        /**
        * @brief метод, добавляющий элемент в конце списка
        */
        void pushBack(T value);

        /**
        * @brief метод, добавляющий новый элемент в начало списка
        */
        void pushFront(T value);

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
        void insert(int idx, T elem);

        /**
        * @brief метод, удаляющий эл-т по указанному индексу idx
        */
        void remove(int idx);


    };
    template<typename T>
    LinkedList<T>::LinkedList() : head(nullptr) {}

    template<typename T>
    LinkedList<T>::LinkedList(std::initializer_list<T> values) : LinkedList()
    {
        for (auto& value : values)
        {
            pushBack(value);
        }
    }

    template<typename T>
    LinkedList<T>::LinkedList(const LinkedList& other) : LinkedList()
    {
        Node* temp = other.head;
        while (temp != nullptr)
        {
            pushBack(temp->data);
            temp = temp->next;
        }
    }

    template<typename T>
    LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other)
    {
        LinkedList temp(other);
        std::swap(this->head, temp.head);
        return *this;
    }

    template<typename T>
    LinkedList<T>::~LinkedList()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    template<typename T>
    bool LinkedList<T>::isEmpty() const
    {
        return head == nullptr;
    }

    template<typename T>
    std::string LinkedList<T>::toString() const
    {
        std::stringstream result;
        Node* temp = head;
        while (temp != nullptr)
        {
            result << temp->data;
            temp = temp->next;
        }
        return result.str();
    }

    template<typename T>
    void LinkedList<T>::pushBack(T value)
    {
        Node* newNode = new Node{ value, nullptr };
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    template<typename T>
    void LinkedList<T>::pushFront(T value)
    {

        Node* newNode = new Node{ value, head };
        head = newNode;
    }

    template<typename T>
    void LinkedList<T>::popBack()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    template<typename T>
    void LinkedList<T>::popFront()
    {
        if (head == nullptr)
        {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list)
    {
        os << list.toString();
        return os;
    }

    template<typename T>
    void LinkedList<T>::insert(int idx, T elem)
    {
        if (idx < 0) throw std::out_of_range("Некорректный индекс");
        if (idx == 0)
        {
            pushFront(elem);
            return;
        }
        size_t index = idx;
        Node* current = head;
        size_t curr_index = 0;
        while (curr_index < index - 1)
        {
            if (current == nullptr) throw std::out_of_range("Некорректный индекс");
            current = current->next;
            curr_index++;
        }
        Node* tmp = current->next;
        current->next = new Node();
        current = current->next;
        current->data = elem;
        current->next = tmp;
    }

    template<typename T>
    void LinkedList<T>::remove(int idx)
    {
        if (idx < 0) throw std::out_of_range("Некорректный индекс");
        if (head == nullptr) throw std::out_of_range("Список пуст");
        if (idx == 0)
        {
            popFront();
            return;
        }
        size_t index = idx;
        Node* current = head;
        size_t curr_index = 0;
        while (curr_index < index - 1)
        {
            if (current == nullptr) throw std::out_of_range("Некорректный индекс");
            current = current->next;
            curr_index++;
        }
        Node* tmp = current->next->next;
        if (tmp == nullptr) throw std::out_of_range("Некорректный индекс");
        delete current->next;
        current->next = tmp;
    }

    template<typename T>
    LinkedList<T>::LinkedList(LinkedList&& other) noexcept
    {
        head = other.head;
        other.head = nullptr;
    }
}
