//
// Created by Christopher Vaughn on 10/24/25.
// downloaded on 11/16/25 by Natalia Meza 
//

#ifndef CIRCULARTEMPLATEDLIST_LINKEDLIST_H
#define CIRCULARTEMPLATEDLIST_LINKEDLIST_H
#include <iostream>

// Template for a singly linked list node that holds a pointer to a Media object (or derived type).
template <typename T>
struct Node {
    T* data; // Pointer to the media object (song, podcast, etc.)
    Node<T>* next;  // pointer to the next node in the list

    Node(T media) : data(media), next(nullptr) {}
};

// === 5. Hard-coded LinkedList Class (Singly, Non-Circular) ===
// This list is only capable of managing Media* objects (Song*, Podcast*, etc.) and is forward-only.
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* current; // For traversal purposes


public:
    // Constructor: Initializes an empty list
    LinkedList() : head(nullptr), tail(nullptr), current(nullptr) {}

    // Destructor: Cleans up all nodes and the Media objects they point to.
    ~LinkedList() {
        if (head == nullptr) 
        return; // If the list is empty, nothing to delete

        Node<T>* temp = head->next;

        while (temp != head) {
            Node<T>* doomed = temp;
            temp = temp->next;

            delete doomed->data; // Delete the Media object
            delete doomed;      // Delete the node itself
        }

        delete head->data; // Delete the Media object in the head node
        delete head;      // Delete the head node

        head = nullptr;
        tail = nullptr;
        current = nullptr;

        std::cout << "\n[Playlist cleanup complete. All memory deallocated.]" << std::endl;
    }

    // Insertion: Adds a new Media pointer to the end of the list.
    void insert(T newMedia) {
        Node<T>* newNode = new Node<T>(newMedia);

        if (head == nullptr) { // if the list is empty, set head and tail to the new node
            head = tail = current = newNode;
            tail->next = head; // for circular behavior, but since this is non-circular, we set next to nullptr
        } 
        else { // Otherwise, append to the end and update tail
            tail->next = newNode;
            tail = newNode;
            tail->next = head; 
        }
    }

    // Traversal: Displays all media items in the list.
    void displayList() const {
        if (head == nullptr) {
            std::cout << "\n[Playlist is empty.]" << std::endl;
            return;
        }
        Node<T>* temp = head;
        int index = 1;

        std::cout << "\n--- Current Playlist ---" << std::endl;
        
        do {
            std::cout << index++ << ". " << temp->data->toString() << std::endl;
            temp = temp->next;
        }
        while (temp != head);

        std::cout << "------------------------" << std::endl;
    }

    // Simple play method for demonstration (students will expand this later)
    void playNext() {
        if (current == nullptr) {
            std::cout << "[Playlist is empty.]" << std::endl;
            return; 
        } 

        current->data->play(); // Call the play method of the current media item
        current = current->next; // Move to the next item in the list
        }
    };

#endif //CIRCULARTEMPLATEDLIST_LINKEDLIST_H