#include <iostream>
#include <string> 

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

        /**
        * @brief конструктор для initializer_list
        * @param values - список из объектов типа Т
        */
        explicit LinkedList(std::initializer_list<T> values);

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
        * @brief метод toString для  LinkedList
        * @return возвращает LinkedList как строку
        */
        std::string toString() const;

        /**
        * @brief метод, добавляющий элемент в конце списка
        * @param value - данные типа Т
        */
        void push_back(T value);

        /**
        * @brief метод, добавляющий новый элемент в начало списка
        * @param value - данные типа Т
        */
        void push_front(T value);

        /**
        * @brief метод, удаляющий последний элемент списка
        */
        void pop_back();

        /**
       * @brief метод, удаляющий первый элемент списка
       */
        void pop_front();

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


    };
    template<typename T>
    LinkedList<T>::LinkedList() : head(nullptr) {}

    template<typename T>
    LinkedList<T>::LinkedList(std::initializer_list<T> values) : LinkedList()
    {
        for (auto& value : values)
        {
            push_back(value);
        }
    }

    template<typename T>
    LinkedList<T>::LinkedList(const LinkedList& other) : LinkedList()
    {
        Node* temp = other.head;
        while (temp != nullptr)
        {
            push_back(temp->data);
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
    void LinkedList<T>::push_back(T value)
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
}
template<typename T>
void LinkedList<T>::push_front(T value)
{

    Node* newNode = new Node{ value, head };
    head = newNode;
}

template<typename T>
void LinkedList<T>::pop_back()
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
void LinkedList<T>::pop_front()
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
        push_front(elem);
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
        pop_front();
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