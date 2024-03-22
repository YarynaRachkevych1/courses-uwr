// Yaryna Rachkevych
// PO Lista 6, Zadanie 2
// (Na bazie zadnia 1, listy 3 - implementacja klasy Lista<T> z odpowiednimi metodami)
// Medoty .remove, .removeAll oraz .retainAll nie są zaimplementowane w odpowiedni sposób


import java.util.Collection;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class Lista2<T>  implements Collection<T>{
    private Node<T> head;
    private Node<T> tail;
    private int size;

    private static class Node<T>{
        T value;
        Node<T> next;
        Node<T> prev;

        public Node(T value) {
            this.value = value;
            this.next = null;
            this.prev = null;
        }

        public T getValue() {
            return this.value;
        }

        public Node<T> getNext(){
            return this.next;
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

    // Pomocnicza metoda żeby usunąć node z listy
    private void removeNode(Node<T> node) throws Exception {
        if (node == head) {
            popFront();
        }
    }

    // Implementacja metod kolekcji
    @Override
    public int size() {
        int s = 0;
        for (T ignored : this) {
            s++;
        }
        return s;
    }

    public boolean isEmpty() {
        if (head == null){
            return true;
        }
        return false;
    }

    @Override
    public boolean contains(Object o) {
        for (T t : this) {
            if (t.equals(o)) {
                return true;
            }
        }
        return false;
    }

    @Override
    public Iterator<T> iterator() {
        return new ListaIterator();
    }

    // klasa iterator
    private class ListaIterator implements Iterator<T> {
        private Node<T> actualItem = head;

        @Override
        public boolean hasNext() {
            return actualItem != null;
        }

        @Override
        public T next() {
            if (!hasNext()) {
                throw new NoSuchElementException();
            }
            T value = actualItem.getValue();
            actualItem = actualItem.getNext();
            return value;
        }
    }


    @Override
    public Object[] toArray() {
        Object[] arr = new Object[size];
        int i = 0;
        for (T element : this) {
            arr[i++] = element;
        }
        return arr;
    }

    @Override
    public <T1> T1[] toArray(T1[] arr) {
        int i = 0;
        for (T element : this) {
            arr[i++] = (T1) element;
        }
        return arr;
    }

    @Override
    public boolean add(T t) {
        pushBack(t);
        return true;
    }

    @Override
    public boolean remove(Object o) {
        return false;
    }

    @Override
    public boolean containsAll(Collection<?> c) {
        for (Object o : c) {
            if (!contains(o)) {
                return false;
            }
        }
        return true;
    }

    @Override
    public boolean addAll(Collection<? extends T> c) {
        for (T t: c){
            add(t);
        }
        return true;
    }

    @Override
    public boolean removeAll(Collection<?> c) {
        return false;
    }

    @Override
    public boolean retainAll(Collection<?> c) {
        return false;
    }

    @Override
    public void clear() {
        head = tail = null;
        size = 0;
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
