public class stackMain
{
	public static void main(String[] args)
	{
		int capacity = 5;
		stack s = new stack(capacity);
		s.push("Derya");
		s.push(18);
		s.push('d');
		s.push(3.14);
		System.out.println("Yığın Kapasitesi\t: " + s.size());
		System.out.println("Yığın Başındaki Eleman\t: " + s.peek());
		System.out.println("Yığından Eleman Çıkart\t: " + s.pop());
		System.out.println("Yığın Kapasitesi\t: " + s.size());
		System.out.println("Yığın Başındaki Eleman\t: " + s.peek());
	}
}