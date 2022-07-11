public class linkedListNode
{
	linkedListNode pointer;
	int first, last;
	long number;
	String name, surname;
	public linkedListNode(long termNumber)
	{
		this.number = termNumber;
		this.pointer = null;
	}
	public linkedListNode(long termNumber, String termName, String termSurname)
	{
		this.number = termNumber;
		this.name = termName;
		this.surname = termSurname;
	}
}