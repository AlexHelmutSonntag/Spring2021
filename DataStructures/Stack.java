public class Stack<T> implements Stackable<T>{

    private Stack<T> previous;
    private T value;

    Stack(T value)
    {
        this.value = value;
    }

    Stack(Stack<T> previous, T value)
    {
        this.previous = previous;
        this.value = value;
    }
    public void push(T value)
    {
        this.previous = new Stack<T> (this.previous, this.value);
        this.value = value;
    }
    public T pop()
    {
        if(this.isEmpty())
        {
            throw new IllegalArgumentException("Stack is empty");
        }
        T top = this.value;
        this.value = this.previous.value;
        this.previous = this.previous.previous;
        
        return top;
    }

    public T peek()
    {
        return this.value;
    }
    public boolean isEmpty()
    {
        return this.previous == null;
    }

    public int size()
    {
        return this.isEmpty() ? 0 : 1 + this.previous.size();

        // if(this.isEmpty())
        //     return 0;
        // else{
        //     return 1+ this.previous.size();
        }
    }





}
