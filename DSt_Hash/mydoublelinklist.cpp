
#ifndef MYDLL_H
#define MYDLL_H

#include <iostream>

#define MAXINT  2147483647
#define MININT  -2147483648

template <class T>
class DList { 

    protected: 
        struct node {
            T key;
            struct node *next;
            struct node *prev;
        };
        typedef struct node *NODEPTR;
        NODEPTR head;  // Points to first node
        NODEPTR tail;  // Points to last node

    public:
        DList();
        ~DList();

        bool isEmpty();
        int size();
        void push( T nu );
        T pop();

        void insertAfter( T a, T b ) ;
        
        int search( T val );        
        bool contains( T val );
        void remove( T val );

        T max();
        T min();

        void displayForward();
        void displayBackward();
        void display(); // forward

};

template <class T>
DList<T>::DList() {
    head = nullptr;
    tail = nullptr;
}

template <class T>
DList<T>::~DList() {

    NODEPTR p, q;

    if ( isEmpty() ) {
        return;
    }

    p = head; 
    while ( p != nullptr ) {
        q = p->next;
        delete p;
        p = q;
    }
}

template <class T>
bool DList<T>::isEmpty() {
    if (head == nullptr) { 
        return true ;
    } else { 
        return false ;
    }
}


template <class T>
int DList<T>::size() {

    if ( isEmpty() ) return 0;

    NODEPTR p = head;
    int N = 0;
    while( p != nullptr  ) {
        N++;
        p=p->next;
    }
    return N;
}

template <class T>
void DList<T>::push( T nu ) { // Appends to front of list

    //std::cout << "here inside \n";

    NODEPTR p; 

    p = new node;

    p->key = nu;
    p->next = head;
    p->prev = nullptr;    

    if (head != nullptr) {
        head->prev = p;
    }
    if (tail == nullptr) {
        tail = p;
    }

    head = p;

    //std::cout << head << '\n';
    //std::cout << p->next << '\n';
    //std::cout << p->key << '\n';

    //std::cout << "here end inside \n";

}

template <class T>
T DList<T>::pop( ) { // remove node from front of list

    NODEPTR p;
    T returnval;

    if (isEmpty()){
        std::cout << "Error, list is empty.\n";
        return (T)0;
    }

    p          = head;
    returnval  = p->key;
    head       = p->next;
    head->prev = nullptr;
    delete p;    
    return returnval;

}

template <class T> 
int DList<T>::search( T val ) {

    NODEPTR p = head;
    int i = 0;

    while ( p != nullptr ){
        if (p->key == val ){
            return i;
        } else {
            p = p->next;
            i++;
        }
    }

    return i;
    std::cout << "Error: value, " << val << ", was not found.";
} 

template <class T> 
bool DList<T>::contains( T val ) {

    NODEPTR p = head;

    while ( p != nullptr ){
        if (p->key == val ){
            return true;
        } else {
            p = p->next;
        }
    }

    return false;
} 

template <class T> 
void DList<T>::remove( T val ) {

    NODEPTR p = head;

    while ( p != nullptr ){
        if (p->key == val ){
            //----------------------------
            if (p->next != nullptr) {
                (p->next)->prev = p->prev;
            }
            if (p->prev != nullptr) {
                (p->prev)->next = p->next;
            }            

            if (p == head) {
                head = p->next;
            } 
            if (p == tail) {
                tail = p->prev;
            }

            delete p;            
            return;
            //----------------------------
        } else {
            p = p->next;
        }
    }
    
    std::cout << "warning: value, " << val << ", was not found. Nothing happened.";
} 

template <class T>
T DList<T>::max() {

    if ( isEmpty() ) { return MININT; }

    T returnval = head->key;

    NODEPTR p = head->next;

    while (  p != nullptr ) {

        if (p->key > returnval ) {
            returnval = p->key;
        }
        p = p->next;
    }

    return returnval;
}

template <class T>
T DList<T>::min() {

    if ( isEmpty() ) { return MAXINT; }

    T returnval = head->key;

    NODEPTR p = head->next;

    while (  p != nullptr ) {

        if (p->key < returnval ) {
            returnval = p->key;
        }
        p = p->next;
    }

    return returnval;
}

template <class T>
void DList<T>::insertAfter( T old, T nu ) { // insert nu after old

    NODEPTR p, q;

    p = head;
    while ( p != nullptr ) {
        if ( p->key == old ) {

            q = new node;
            q->key = nu;
            q->next = p->next;
            q->prev = p;
            p->next = q;

            if (q->next != nullptr) {
                (q->next)->prev = q;
            }

            return;

        } else {
            p = p->next;
        }        
    }

    std::cout << "error: value, " << old << " was not found in list. Item was not inserted.\n";

}


template <class T>
void DList<T>::displayForward( ) {

    if (isEmpty()) {
        std::cout << "list: H[ ]T\n"; 
    } else { 
        NODEPTR p;

        std::cout << "list: H[ ";
        p = head;
        while ( p != nullptr ) {
            std::cout << (p->key) << ", ";
            p = p->next;
        }
        std::cout <<  " ]T\n";
    }
    
}

template <class T>
void DList<T>::displayBackward( ) {

    if (isEmpty()) {
        std::cout << "list: T[ ]H\n"; 
    } else { 
        NODEPTR p;

        std::cout << "list: T[ ";
        p = tail;
        while ( p != nullptr ) {
            std::cout << (p->key) << ", ";
            p = p->prev;
        }
        std::cout <<  " ]H\n";
    }
    
}

template <class T>
void DList<T>::display( ) {

    if (isEmpty()) {
        std::cout << "[ ]"; 
    } else { 
        NODEPTR p;

        std::cout << "[ ";
        p = head;
        while ( p != nullptr ) {
            std::cout << (p->key) << " ";
            p = p->next;
        }
        std::cout <<  "]";
    }
    
}


#endif