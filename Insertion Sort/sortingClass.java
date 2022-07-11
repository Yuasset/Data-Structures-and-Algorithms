public class sortingClass
{
	void sort(int[] arrayTemp)
	{
		int key, step = 0, capacity = arrayTemp.length;
		for (int count = 1; count < capacity; count++)
		{
			key = arrayTemp[count];
			step = count - 1;
			while(step >= 0 && arrayTemp[step] > key)
			{
				arrayTemp[step + 1] = arrayTemp[step];
				step = step - 1;
			}
			arrayTemp[step + 1] = key;
		}
	}
}