class Node<E> {
    private E element;
    private Node<E> next;

    public Node(){
        this(null, null);
    }
    public Node(E element, Node<E> next){
        this.element = element;
        this.next = next;
    }

    public e getElement() {
        return this.element;
    }
    public Node<E> getNext() {
        return this.next;
    }
    public void setElement(E element){
        this.element = element;
    }
    public void setNext(Node<E> next){
        this.next = next;
    }
}

interface Stack<E>{
    public int size();
    public boolean isEmpty();
    public <E> top() throws StackEmptyException;

    public void push(Object element);
    public <E> pop() throws StackEmptyException;
}

class NodeStack<E> implements Stack{
    private Node<E> top;
    private int size;

    public NodeStack(){
        top = null;
        size = 0;
    }

    public int size() {
        return size;
    }
    public boolean isEmpty() {
        return (size==0);
    }

    public E top() throws StackEmptyException{
        return top.getElement();
    }
    public void pop() throws StackEmptyException{
        if(size==0){
            throw new StackEmptyException("Stack is empty!");
        }
        this.top = top.next();
    }

    public void push(e element){
        Node<E> temp = new Node<E>(elemennt, top);
        top = temp;
        size++;
    }

    
}
