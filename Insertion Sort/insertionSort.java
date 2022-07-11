public class insertionSort
{
	public static void main(String[] args)
	{
		int array[] = {6,2,66,33,8,12,52,11,5};
		System.out.print("Normal Array\t: ");
		for (int count : array) System.out.print(count + " ");
		sortingClass sorting = new sortingClass();
		sorting.sort(array);
		System.out.println();
		System.out.print("Insertion Sort\t: ");
		for (int count : array) System.out.print(count + " ");
	}
}
