#pragma once
#include <string>

//В этой задаче для простоты не требуется делать контейнер шаблонным,
//но это вполне допускается по желанию студента.
typedef int value_type;
class LinkedList {
    friend class iterator;
    struct Node {
        value_type value;
        Node* prev;
        Node* next;

        Node();
        explicit Node(value_type val);
        explicit Node(value_type val, Node* prev, Node* next);
    };

    Node* tail;
    int capacity = 0;

public:
    //Ознакомление с итераторами входит в задачу.
    //Коротко, итератор - это объект, позволяющий удобно перебирать элементы
    //некоторой последовательности. На C++ итераторы обычно реализуют с помощью
    //переопределения операций инкремента/декремента (сдвиг на следующий
    //или предыдущий элемент последовательности) и операций разыменования и
    //косвенного доступа (получение элемента коллекции, на который указывает
    //итератор).
    class iterator {
        friend class LinkedList;
        Node* curInList;
    public:
        iterator();
        explicit iterator(Node* node);
        iterator & operator=(const iterator & other);
        bool operator!=(const iterator & other) const;
        bool operator==(const iterator & other) const;
        //Возвращает ссылку на текущий элемент коллекции.
        value_type & operator*();
        //Возвращает указатель на текущий элемент коллекции.
        value_type * operator->();

        iterator & operator++();
        iterator operator++(int);
        iterator & operator--();
        iterator operator--(int);
        iterator operator+(int shift);
        iterator operator-(int shift);
    };
    class const_iterator {
        Node* curInList;
    public:
        const_iterator();
        explicit const_iterator(Node* node);
        const_iterator & operator=(const const_iterator & other);
        bool operator!=(const const_iterator & other) const;
        bool operator==(const const_iterator & other) const;
        //Возвращает ссылку на текущий элемент коллекции.
        const value_type & operator*() const;
        //Возвращает указатель на текущий элемент коллекции.
        const value_type * operator->() const;

        const_iterator & operator++();
        const_iterator operator++(int);
        const_iterator & operator--();
        const_iterator operator--(int);
        const_iterator operator+(int shift);
        const_iterator operator-(int shift);
    };
    /* Конструкторы */
    LinkedList();
    LinkedList(const LinkedList & other);
    LinkedList(LinkedList && other) noexcept ;

    /* Деструктор */
    ~LinkedList();

    /* Оператор присваивания */
    LinkedList & operator=(const LinkedList & other);
    LinkedList & operator=(LinkedList && other);

    /* Доступ к итераторам */
    //Возвращает итератор, указывающий на первый элемент списка.
    iterator begin();
    const_iterator cbegin() const;
    //Возвращает итератор, указывающий на элемент списка, следующий за последним
    //т.е. отсутствующий в списке.
    iterator end();
    const_iterator cend() const;

    /* Размерность */
    //Возвращает размер списка.
    int size() const;
    //Возвращает истину, если список пуст.
    bool empty() const;

    /* Доступ к элементам */
    //Возвращает ссылку на первый элемент списка.
    value_type & front();
    const value_type & front() const;
    //Возвращает ссылку на последний элемент списка.
    value_type & back();
    const value_type & back() const;

    /* Модификаторы */
    //Удаляет элемент, на который указывает итератор pos.
    iterator erase(iterator position);
    //Удаляет элементы в интервале [begin, end).
    iterator erase(iterator begin, iterator end);
    //Удаляет все вхождения value в список.
    int remove(const value_type & value);
    //Очищает список.
    void clear();

    //Удаляет последний элемент списка.
    void pop_back();
    //Удаляет первый элемент списка.
    void pop_front();
    //Добавляет значение value в конец списка.
    void push_back(const value_type & value);
    //Добавляет значение value в начало списка.
    void push_front(const value_type & value);
    //Вставляет значение value перед элементом, на который указывает before
    iterator insert(iterator before, const value_type & value);

    /* Операторы внутренние */
    //Присоединяет other к списку.
    LinkedList & operator+=(const LinkedList & other);

    /* Операторы внешние */
    friend bool operator!=(const LinkedList & left, const LinkedList & right);
    friend bool operator==(const LinkedList & left, const LinkedList & right);

};

/* Операторы внешние */
//Сравнивает 2 листа
bool operator!=(const LinkedList & left, const LinkedList & right);
bool operator==(const LinkedList & left, const LinkedList & right);

//Возвращает лист объединяющий 2 листа.
LinkedList operator+(const LinkedList & left, const LinkedList & right);