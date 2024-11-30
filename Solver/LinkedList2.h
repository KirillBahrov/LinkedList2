#include <iostream>
#include <string> 
#include <sstream>
namespace RUT::MIIT
{
    template <typename T> class LinkedList;

    /*
    *@brief Оператор <<  линейного односвязного списка
    *@param T - тип данных, хранящийся в  классе LinkedList
    *@param output - поток вывода
    *@param LinkedList - линейный односвязный список
    *@return Изменённый поток вывода
    */
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const RUT::MIIT::LinkedList<T>& list);

    template <typename T>
    class LinkedList
    {
    private:
        /**
        * @brief Node - структура узла
        */
        struct Node
        {
            T data;
            Node* next;
            Node(const T& data, Node* next) : data{ data }, next{ next } {}
        };
        Node* head;

    public:
        /**
        * @brief конструктор по умолчанию
        */
        LinkedList();

        /**
        * @brief конструктор для initializer_list
        * @param values - список из объектов типа Т
        */
        LinkedList(std::initializer_list<T> values);

        /**
        * @brief конструктор копирования
        * @param other - другой объект типа LinkedList
        */
        LinkedList(const LinkedList& other);

        /**
        * @brief деструктор
        */
        ~LinkedList();

        /**
        * @brief конструктор копирования перемещением
        * @param other - другой объект типа LinkedList
        */
        LinkedList(LinkedList&& other) noexcept;

        /**
        * @brief оператор присваивания/копирования
        * @param other - другой объект типа LinkedList
        */
        LinkedList& operator=(const LinkedList& other);

        /**
        * @brief метод, проверяющий пуст ли список
        * @return true, если список пуст
        * @return false, если список не пуст
        */
        bool isEmpty() const;

        /**
        * @brief метод ToString для  LinkedList
        * @return возвращает LinkedList как строку
        */
        std::string ToString() const;

        /**
        * @brief метод, добавляющий элемент в конце списка
        * @param value - данные типа Т
        */
        void pushBack(const T& value);

        /**
        * @brief метод, добавляющий новый элемент в начало списка
        * @param value - данные типа Т
        */
        void pushFront(const T& value);

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
        * @param idx - индекс вставляемого элемента
        * @param elem - вставляемый элемент
        */
        void insert(int idx, T elem);

        /**
        * @brief метод, удаляющий эл-т по указанному индексу idx
        * @param idx - индекс удаляемого элемента
        */
        void remove(int idx);

        /**
        * @brief метод вывода переднего элемента LinkedList
        * @return - первый элемент списка
        */
        T peekFront() const;

        /**
        * @brief метод вывода последнего элемента LinkedList
        * @return - последний элемент списка
        */
        T peekBack() const;

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
    std::string LinkedList<T>::ToString() const
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
    void LinkedList<T>::pushBack(const T& value)
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
    void LinkedList<T>::pushFront(const T& value)
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
        os << list.ToString();
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
        size_t index = static_cast<size_t>(idx);
        Node* current = head;
        size_t curr_index = 0;
        while (curr_index < index - 1)
        {
            if (current == nullptr) throw std::out_of_range("Некорректный индекс");
            current = current->next;
            curr_index++;
        }
        Node* tmp = current->next;
        current->next = new Node(elem, tmp);
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
        size_t index = static_cast<size_t>(idx);
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
    inline T LinkedList<T>::peekFront() const
    {
        return head->data;
    }

    template<typename T>
    inline T LinkedList<T>::peekBack() const
    {
        Node* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    template<typename T>
    LinkedList<T>::LinkedList(LinkedList&& other) noexcept
    {
        head = other.head;
        other.head = nullptr;
    }
}