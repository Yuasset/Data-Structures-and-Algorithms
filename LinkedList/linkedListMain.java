import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
public class linkedListMain
{
	public static void main(String[] args) throws IOException
	{
		linkedList lists = new linkedList();
		FileReader file = new FileReader("register_file.txt");
		BufferedReader reader = new BufferedReader(file);
		String lines = reader.readLine();
		String[] smash = null;
		while (lines != null)
		{
			smash = lines.split(",");
			lists.insert(new linkedListNode(Long.valueOf(smash[0]), smash[1], smash[2]));
			lines = reader.readLine();
		}
		reader.close();
		lists.delete(7756591263L);
		System.out.println("Toplam Kayıt Sayısı\t: " + lists.returnRegisterNumber());
		lists.insert(new linkedListNode(4532327123L,"lvxmlqtdta","rtadurkhwy"));
		System.out.println("Toplam Kayıt Sayısı\t: " + lists.returnRegisterNumber());
		lists.insert(new linkedListNode(21,"lvxmlqtdta","rtadurkhwy"));
		long timeGo = System.nanoTime();
		linkedListNode find1 = lists.search(9377761894L);
		long timeFinal = System.nanoTime();
		long totalTime = timeFinal - timeGo;
		System.out.println("Çalışma Zamanı\t\t: " + totalTime / 1000 + " MS");
		lists.print(find1);
		linkedListNode find2 = lists.returnRegister(6);
		lists.print(find2);
	}
}