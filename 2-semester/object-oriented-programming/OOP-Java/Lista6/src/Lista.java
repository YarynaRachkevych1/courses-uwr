// Yaryna Rachkevych
// PO Lista 6, Zadanie 1
// (Na bazie zadnia 1, listy 3 - implementacja klasy Lista<T> z odpowiednimi metodami)

import java.io.Serializable;
public class Lista<T> implements Serializable {
    private Node<T> head;
    private Node<T> tail;
    private int size;

    private static class Node<T> implements Serializable{
        T value;
        Node<T> next;
        Node<T> prev;

        public Node(T value) {
            this.value = value;
            this.next = null;
            this.prev = null;
        }
    }


    public void pushFront(T elem) {
        Node<T> newNode = new Node<>(elem);
        if (isEmpty()) {
            tail = newNode;
        } else {
            head.prev = newNode;
        }
        newNode.next = head;
        head = newNode;
        size++;
    }

    public void pushBack(T elem) {
        Node<T> newNode = new Node<>(elem);
        if (isEmpty()) {
            head = newNode;
        } else {
            tail.next = newNode;
        }
        newNode.prev = tail;
        tail = newNode;
        size++;
    }

    public T popFront() throws Exception {
        if (isEmpty()) {
            throw new Exception("Lista jest pusta!");
        }
        Node<T> removedNode = head;
        if (head == tail) {
            tail = null;
        } else {
            head.next.prev = null;
        }
        head = head.next;
        removedNode.next = null;
        size--;
        return removedNode.value;
    }

    public T popBack() throws Exception {
        if (isEmpty()) {
            throw new Exception("Lista jest pusta!");
        }
        Node<T> removedNode = tail;
        if (head == tail) {
            head = null;
        } else {
            tail.prev.next = null;
        }
        tail = tail.prev;
        removedNode.prev = null;
        size--;
        return removedNode.value;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public String printList() {
        StringBuilder sb = new StringBuilder();
        Node<T> current = head;
        while (current != null) {
            sb.append(current.value).append(" ");
            current = current.next;
        }
        return sb.toString();
    }
}
