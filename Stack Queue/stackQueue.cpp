#include <stdio.h>
#include <iostream> //Kullanıcıya, çıktı ve giriş işlemleri için kolaylık sağlayan kütüphane
using namespace std; //std nesnesini tanımlayarak içerdiği komutları kısa yol olarak kullanmamızı sağlayan tanımlayıcı
#define capacity 10 //Sabit değerli değişken
int queue[capacity]; //Kuyruk yapısını tutacak dizi
int rear = -1; //Kuyruğa en son eklenen elemanın sırasını taşır
int front = -1; //Kuyruktaki ilk elamanın sırasını taşır

struct node //Düğüm
{
    int data; //Düğüm verisi
    struct node* link; //Sonraki düğümü işaret eden düğüm
};
struct node* top = NULL; //Liste başını işaret eden düğüm
void enQueue() //Kuyruğa eleman ekleyen fonksiyon
{
    int value; //Dışarıdan alınan değeri tutan değişken
    if (capacity - 1 == rear) //Rear(arka) dizi kapasitesinin bir eksiğine eşit ise
    {
        printf("Kuyruk Dolu\n");
    }
    else
    {
        if (front == -1) //Front(ön) başı tutan değişken -1 ise
        {
            front = 0; //Front(ön) liste başını oluştur.
        }
        printf("Bir eleman giriniz: ");
        scanf_s("%d", &value); //Dışarıdan eleman iste ve Value değişkeni içine aktar
        rear++; //Rear(arka) değişkenini bir arttır
        queue[rear] = value; //Dışarıdaki değeri Rear(arka) değişkeninin tuttuğu indis değerini kullanarak diziye içine aktar
    }
}
void push(int tempValue) //Yığına eleman ekleyen fonksiyon
{
    struct node* temp; //Düğüm oluştur
    temp = (struct node*)malloc(sizeof(struct node)); //Düğüm için genişletilebilir bellek alanı ayır
    temp->data = tempValue; //Düğüm Data içeriğine tempValue değişkeni değerini aktar
    temp->link = top; //Düğümün sonraki düğüm işaretçisine Top düğümünü aktar
    top = temp; //Yığın liste başını tutan Top düğümü içine Temp düğümünü aktar
}
void printQueue() //Kuyruk elemanlarını yazdıran fonksiyon
{
    if (front == -1 || front > rear) //Front(ön) düğümü -1 ve Rear(arka) düğümünden büyük ise
    {
        printf("Kuyruk boş\n");
        return;
    }
    printf("\nKuyruk elemanları: ");
    for (int i = front; i <= rear; i++) //Front(ön) düğümünü i değişkeni sayacına aktar ve i değişkenini Rear(arka) düğümün tuttuğu sıra değerine ulaşına kadar birer arttır
    {
        printf("%d, ", queue[i]); //Kuyruğu sırasıyla yazdır
    }
}
void printStack() //Yığın elemanlarını yazdıran fonksiyon
{
    if (top == NULL) //Yığın başını tutan düğüm NULL ise
    {
        printf("Yığın boş\n");
    }
    else
    {
        struct node* temp = top; //Temp düğümü oluştur ve Top düğümünü aktar
        printf("\nYığın elemanları: ");
        while (temp != NULL) //Temp düğümünün bir sonraki düğümü işaret ederen Link düğümü NULL olana kadar döngüyü çalıştır
        {
            printf("%d, ", temp->data); //Temp düğümü verilerini yazıdır
            temp = temp->link; //Temp düğümünü bir sonraki düğüm işaretiçisi ile eşleştir.
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Turkish"); //Türkçe Karakteri desteklemesi için kullanıyorum
    int total = 0, average = 0, i = 0;
    while (i < 10) //10 kez Kuyruğa ekle fonksiyonunu çağıran döngü
    {
        enQueue(); //Kuyruğa ekle: 10, 20, 50, 5, 80, 70, 35, 45, 18, 7
        i++;
    }
    printQueue(); //Kuyruğu yazdır
    for (i = front + 1; i <= rear + 1; i++) //Elemanların Total değerini bul
    {
        total = total + queue[i]; //Sırayla kuyruktaki elemanları, Total değişkeni ile topla
    }
    average = total / capacity; //Ortalama değer
    printf("\nOrtalamadan(%d) büyük sayılar: ", average);
    for (i = 0; i < capacity; i++)
    {
        if (queue[i] > average) //Ortalamaladan büyük değerleri, Yığına aktar
        {
            push(queue[i]); //Kuyruk elemanlarının ortalamadan büyük olanlarını Push() fonksiyonu ile Stack(Yığın) listesine ekle
            printf("%d, ", queue[i]); //Ortalamadan büyük olanları ekrana yazdır
        }
    }
    printStack(); //Yığını yazdır
    int final[capacity], step = 0; //Büyük olan değerleri listelemek için Final adlı diziyi oluştur ve diziye eklenecek eleman sayısı kadar harici bir Step adında sayaç görevi gören değişken oluştur
    struct node* temp = top; //Yığındaki elemanları listelemek için Temp düğümü oluştur ve Top düğümünü içeriye aktar
    while (temp != NULL) //Yığın elemanlarını diziye aktar
    {
        final[step++] = temp->data; //Listemeyi yapacak olan Final dizisi içinde Step adlı değişkeni birer arttır ve değer olarak Temp düğümünün verisini aktar
        temp = temp->link; //Temp düğümünü bir sonraki düğümü işaret eden düğüm ile eşleştir
    }
    printf("\nDizi içeriği: ");
    for (i = 0; i < step; i++) //Dizi elemanlarını yazdır
    {
        printf("%d, ", final[i]); //Final dizisi içeriğini sırasıyla ekrana yazdır
    }
}//MAIN FINAL
