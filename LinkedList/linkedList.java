public class linkedList
{
	linkedListNode start;
	public int size;
	public linkedList()
	{
		this.start = null;
	}
	public void insert(linkedListNode tempValue)
	{
		linkedListNode temp = start;
		linkedListNode tempPointer = null;
		while(temp != null && tempValue.number > temp.number)
		{
			tempPointer = temp;
			temp = temp.pointer;
		}
		if (tempPointer == null)
		{
			start = tempValue;
		}
		else
		{
			tempPointer.pointer = tempValue;
		}
		tempValue.pointer = temp;
		sorting();
		size ++;
	}
	public linkedListNode search(long termNumber)
	{
		linkedListNode temp = start;
		linkedListNode find = null;
		while(temp.pointer != null)
		{
			if(temp.number == termNumber)
			{
				find = temp;
				break;
			}
			temp = temp.pointer;
		}		
		return find;
	}
	public void sorting()
	{
		linkedListNode temp = start;
		int reSort = 0;
		int lastSort = size;
		while(temp != null)
		{
			temp.first = reSort;
			reSort = reSort + 1;
			temp.last = lastSort;
			lastSort = lastSort - 1;
			temp = temp.pointer;
		}
	}
	public linkedListNode returnRegister(long termFirst)
	{
		linkedListNode temp = start;
		linkedListNode find = null;
		while(temp.pointer != null)
		{
			if(temp.first == termFirst)
			{
				find = temp;
				break;
			}
			temp = temp.pointer;
		}
		return find;
	}
	public long delete(long address)
	{
		linkedListNode temp = start;
		linkedListNode tempPointer = null;
		if(temp != null && address == temp.number)
		{
			long K = start.number;
			start = temp.pointer;
			size = size - 1;
			sorting();
			return K;
		}
		while(temp != null && address != temp.number)
		{
			tempPointer = temp;
			temp = temp.pointer;
		}
		if(temp == null)
		{
			return - 1;
		}
		long K = temp.number;
		tempPointer.pointer = temp.pointer;
		size = size - 1;
		sorting();
		return K;
	}
	public int returnRegisterNumber()
	{
		return size;
	}
	public void print(linkedListNode tempNode)
	{
		System.out.println("Number: " + tempNode.number + ",\tName: " + tempNode.name + ",\tSurname: " + tempNode.surname + ",\tFirst: " + tempNode.first + ",\tLast: " + tempNode.last);
	}
}