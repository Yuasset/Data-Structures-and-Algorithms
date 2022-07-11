public class stack
{
	private int top;
	private Object[] element;
	stack(int capacity)
	{
		element = new Object[capacity];
		top = top - 1;
	}
	void push(Object data)
	{
		if(isFull())
		{
			System.out.println("Stack dolu");
		}
		else
		{
			top = top + 1;
			element[top] = data;
		}
	}
	Object pop()
	{
		if (isEmpty())
		{
			System.out.println("Stack boş");
			return null;
		}
		else
		{
			Object data = element[top];
			element[top] = null;
			top = top - 1;
			return data;
		}
	}
	boolean isEmpty()
	{
		return (top == -1);
	}
	boolean isFull()
	{
		return (top + 1 == element.length);
	}
	Object peek()
	{
		if (isEmpty())
		{
			System.out.println("Stack boş");
			return null;
		}
		else
		{
			return element[top];
		}
	}
	int size()
	{
		return top + 1;
	}
}