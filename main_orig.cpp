#include <iostream>

namespace p24 {
    template <typename T, int size> // s'applique à toute la classe
    class array {
    private:
        T data[size]; // data = pointeur, tableau de size elements de type T, référencé par un tableau qui s'appelle data

    public:
        void fill(T a) {
            for (int i = 0; i < size; i++) {
                *(data+i) = a;
                // même chose que data[i] = a
            }
        }
        T at(int n) {
            return data[n]; // ou *(data+n)
        }
        int taille() {
            return size;
        }
        T& operator[](int n) { // Permet d'écrire b[4] par exemple
            return data[n];
        }
        T* begin() {
            return data;
        }
        T* end() {
            return data + taille();
        }
    };
    template <typename T>
    class vector { //On le déclarera sur le tas, donc par
        // int * p = new int[10]
    private:
        T* data; // Pointeur nommé data (qui pointe vers un objet de type T
        int size;
        int capacity;
    public:
        vector() {
            size=0;
            data = nullptr;
            capacity = 0;
        }
        void fill(T a) {
            for (int i = 0; i < size; i++) {
                *(data+i) = a;
                // même chose que data[i] = a
            }
        }
        T at(int n) {
            return data[n];
        }
        void resize() {
            if (capacity == 0) {
                capacity = 1;
                T* new_data = new T[capacity];
                new_data[0] = data[0];
                data = new_data;
            }
            else {
                T* new_data = new T[2*capacity];
                for (int i = 0; i < size; i++) {
                    new_data[i] = data[i];
                }
                data = new_data;
            }
            delete[] data; // sur le tas, ne se delete pas tout seul
        }
        void push_back(T a) {
            if (size >= capacity-1) {
                resize();
                data[size] = a;
                size += 1 ;
            }
            else {
                data[size] = a;
                size += 1 ;
            }
        }
        T& operator[](int n) {
            return data[n];
        }
        T* begin() {
            return data;
        }
        T* end() {
            return data+size;
        }
        int taille() {
            return size;
        }
    };

    template <typename T>
    class list {
    private:
        struct node;
        node * head; // Pointeur vers un noeud appelé head
        node * tail;
        int size;

        struct node { // Struct = classe ou tout est public
            T valeur;
            node * next ; //adresse du suivant
        };

    public:
        list() {
            size = 0;
            head = nullptr;
            tail = nullptr;
        }

        void push_front(T val) {
            node * new_node = new node(val, head);
            head = new_node;
            size ++;
            if (!tail) {
                tail = new_node;
            }
        }
        T at(int n) {
            node * p = head; // pointeur p de type node initalisé à head
            for (int i = 0; i < n; i++) {
                p = (*p).next;
            }
            return (*p).valeur;
        }
        void push_back(T val) {}
    };
}


int main() {
    p24::array<int,5> b;
    b.fill(10);
    //std::cout << b[3] << std::endl;
    p24::vector<int> v;
    v.push_back(5);
    std::cout << v.taille() << std::endl;
    for (int i = 0; i < v.taille(); i++) {
        std::cout << v[i] << std::endl;
    }

    //p24::list<int> l;
    //l.push_front(10);
    //std::cout << l.at(0) << std::endl;
    return 0;
}