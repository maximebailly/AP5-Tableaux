//
// Created by maxim on 13/12/2024.
//

#ifndef LIST_H
#define LIST_H

#include <iostream>
namespace p24 {
    template<typename T>
    class list {

        struct node { // la classe p24::list<T>::node

            // NOUS UTULISONS UNE "struct" et non une "class"
            // ainsi:
            // - les champs sont "publiques" par défaut
            // - on aura un constructeur équivalent à "node(T val, node* next)" généré pour nous

            T val; // la valeur
            node* next; // le pointeur vers le noeud suivant
        };

        // les attributs de la classe "list" (privés)
        node* head; // un pointeur vers le premier noeud
        node* tail; // un pointeur vers le dernier noeud
        int sz;     // la taille de la liste

    public:
        list() {
            sz = 0;
            head = tail = nullptr;
        }
        void push_front(T val) {
            // on crée un nouveau noeud
            node* new_node = new node(val, head); // le nouveau "premier noeud" inséré entre head et l'ancien premier noeud
            // on édite l'état de notre liste
            if (sz == 0) {
                // la liste était vide
                // 💡 on fera attention à ne pas oublier le "tail" (comme je l'ai fait en cours !) car si on n'a qu'un
                //    noeud il est à la fois le premier et le dernier noeud
                head = tail = new_node;
            } else {
                head = new_node;
            }
            sz++;
        }

        void push_back(T val) {
            // on édite l'état de notre liste
            if (sz == 0) {
                push_front(val); // Un push_back sur une liste vide revient à faire un push_front
            } else {
                node* new_node = new node(val, nullptr); // le nouveau "dernier noeud"
                node* current_node = head; // on part du premier noeud
                (*tail).next = new_node; // La tail actuelle admet comme noeud suivant new_node
                tail = new_node;
            }
            sz++;
        }

        T at(int pos) {
            node* current_node = head; // on part du premier noeud
            for (int i = 0; i < pos; i++) {
                current_node = current_node->next; // ici j'utilise la syntaxe "head->next" qui est équivalent à "(*head).next"
            }
            return current_node->val;
        }
        T operator[](int pos) { return at(pos); }

        void remove(int pos) {
            node* node_n_moins_1 = head; // on part du premier noeud
            node* node_n = head;
            for (int i = 0; i < pos-1; i++) {
                node_n_moins_1 = node_n_moins_1->next; //On parcourt les noeuds jusqu'au pos-1 ème
                }
            node_n = node_n_moins_1->next; // On stocke le noeud suivant actuel, à supprimer
            (*node_n_moins_1).next = (*node_n).next; // On change l'adresse du suivant du pos-1 ème
            delete node_n; // On retire le pos-ème noeud
            sz = sz-1;
        }

        // efface toutes les valeurs de la liste, la ramenant à une taille de 0
        void clear() {
            node* current_node = head;
            node* sauvegarde = current_node;
            for (int i = 0; i < sz; i++) {
                current_node = current_node->next;
                delete sauvegarde;
                sauvegarde = current_node;
            }
            delete current_node;
            sz = 0;
            head = tail = nullptr;
        }

        // on peut copier size() depuis les autres classes 😊
        int size() { return sz; }
    };
}

#endif //LIST_H
