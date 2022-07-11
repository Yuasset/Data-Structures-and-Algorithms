#include <iostream> //Kullanıcıya, çıktı ve giriş işlemleri için kolaylık sağlayan kütüphane
#include <math.h> //Genişletilmiş matematik fonksiyonlarını barındıran kütüphane
#include <fstream> //Dosya okuma ve düzenleme işlemlerini gerçekleştirmeyi sağlayan kütüphane
#include <vector> //Ayarlanılabilir dizi ve metodlarını kullanmayı sağlayan kütüphane
using namespace std; //std nesnesini tanımlayarak içerdiği komutları kısa yol olarak kullanmamızı sağlayan tanımlayıcı
int64_t step(int64_t value) //Basamak adetini değer olarak döndüren fonksiyon
{
    int64_t number = value, step = 0; //Basamağı sayılacak veriyi tutan Number değişkeni ve basamak adetini değer olarak tutan Step değişkeni oluşturdum
    while (number > 0) //Verinin basamak değeri 0 olana kadar döngü oluşturdum
    {
        number = number / 10; //Verinin kalansız çıkana kadar 10 sayısına böler ve kalanı Number değişkenine aktarırım
        step++; //Döngüde olduğu sürece basamak adetini tutan değişkeni +1 artırma işlemi yaparım
    }
    return step; //Basamak adetini integer tipinde değer üretirim
}
const vector<string> parse(const string& value, const char& factor) //Vektor tipinde belli bir föktere göre verilerde ayrıştırma yapan fonksiyon
{
    string data; //Ayrıştırılacak veriyi tutan string tipinde Data adlı değişken
    vector<string> vectorArray; //Ayrıştırılan veriyi sırasıyla indisleyen string tipinde VectorArray adında vektör(Ayarlanabilir/genişleyen dizi)
    for (auto character : value) //veri tipini aldığı değere göre otomatik belirleyen Character adlı değişkenen içerisinde :(operatör) ile değerleri eklerken toplam bit adeti kadar döngününün çalışmasını sağlarım 
    {
        if (character != factor) //Döngü içerisinde bit bit olarak eklenen karakterlerin birbirinden ayıran unsurun olmadığı durumda
        {
            data = data + character; //karakterleri tekrar birleştirirme işlemi yaparım
        }
        else if (character == factor && data != "") //Ayırıcı unsur bulunduğu vakit ve Data değişkeni boş değilse
        {
            vectorArray.push_back(data); //Ayırıcı unsurdan önce Data değişkeni içerisinde birleştirilen verileri .push_Back() "sona ekle" metodu kullanarak VectorArray adlı ayarlanılabilir dizinin sonuna indis olarak eklerim
            data = ""; //Ayırıcı unsur bulunmasıyla Data değişkeninimi sonraki veriyi tutmak için boşlatırım
        }
    }
    if (data != "") //Data içeriği boş ise
    {
        vectorArray.push_back(data); //Ayarlanılabilir dizi içerisine Data verisini aktarırım
    }
    return vectorArray; //string tipinde VectorArray adlı vektörü değer olarak döndürürüm
}
struct node //Düğüm
{
    int data1; //Düğüm Birinci içeriği barındıran değişken.
    int data2; //Düğüm İkinci içeriği barındıran değişken.
    struct node* prevLink; //Önceki Pointter'ı işaret eden düğüm
    struct node* nextLink; //Sonraki Pointter'ı işaret eden düğüm
};
struct node* root = NULL; //İlk düğümün Pointter'ını işaret eden düğüm. İlk kez düğüm ekleneceği için başta NULL değer olarak atadım
void add(int Value1, int Value2) //Listeye sırasıyla düğüm ekleyen fonksiyon
{
    struct node* temp = NULL; //Düğüm tanımlanıyor. İlk düğüm tanımlandığında, listede düğümün işaret edeceği herhangi başka bir düğüm olmadığı için, düğüme NULL değeri atandığına dikkate ediniz. Bazı geliştirme ortamlarında bu atama varsayılan olarak gerçekleştiğinden ilk düğüm oluşturulurken NULL değerinin atanması zorunlu değildir
    temp = (struct node*)malloc(sizeof(struct node)); //Düğüm için malloc() fonksiyonu kullanılarak bilgisayar belleğinde düğüm için yer ayrılıyor.  Bu ifadedeki malloc() fonksiyonu bellekte düğüme yer ayrılması için, sizeof() fonksiyonu ise bellekte ayrılacak yerin büyüklüğünü belirlemek için kullanılmıştır. Ayrıca bu ifadenin önüne Casting işlemi için (struct bagliListe*) ifadesi yazılmıştır ki bu işlem tip dönüşümü yapılmasını sağlayarak tip uyuşmazlığının önüne geçilmesini sağlar
    temp->data1 = Value1; //1.Veri içeriğin aktarılacağı yerin seçimi
    temp->data2 = Value2; //2.Veri içeriğin aktarılacağı yerin seçimi
    temp->nextLink = NULL; //Düğümün sonraki düğüm işaret ederken başta NULL işaret etmesini sağlarım
    temp->prevLink = NULL; //Düğümün önceki düğümü işaret ederken başta NULL işaret etmesini sağlarım
    if (root == NULL) //Listede düğüm olup olmadığı sorgulamak için liste başını işaret eden Root düğümünü çağırırım
    {
        root = temp; //Listede düğüm yoksa Temp düğümünü Root düğümünün listede işaret ettiği konuma aktarırım
    }
    else //Listede herhangi bir düğüm var ise
    {
        struct node* locate = root; //Listede var olan düğümler arasında gezmek ve Root düğümünün liste başını işaret edici özelliğini kaybetmemek için Locate adında düğüm oluşturur ve içerisine Root verisini aktarırım
        while (locate->nextLink != NULL) //Locate düğümünü NULL olana kadar sonraki düğümün verisine gitmesini sağlarım
        {
            locate = locate->nextLink; //Locate düğümüne sonra düğümü işaret eden konumu aktarırım
        }
        locate->nextLink = temp; //Locate düğümünün sonraki düğümü işaret eden NULL değerini Temp düğümü verisi ile değişimini sağlarım
        temp->prevLink = locate; //Temp düğümün bir önceki düğümü işaret eden NULL değerini Locate ile bulunan en son düğümü aktarırım. Kısaca, bir sonraki düğümü işaret eden düğümün önceki düğümü işaret eden işaretçisine bir önceki düğümün verisini aktararak bağlantısını sağlarım
    }
}
void printList() //Listenin tamamını yazdıran fonksiyon
{
    if (root == NULL) //İlk düğümü işaret eden düğüm NULL ise
    {
        printf("Liste Boş"); //Listede düğüm olmadığını belirtsin
    }
    else //Listede düğüm varsa
    {
        struct node* locate = root; //Listede gezmek için Root düğümün bilgilerini oluşturulan Locate düğümü içerisine aktarırım
        while (locate != NULL) //Liste başından var olan en son düğüme kadar Locate düğümünün NULL durumunu sorgularım
        {
            printf(" (Sayı1 = %d || Sayı2 = %d) \n", locate->data1, locate->data2); //Çıktı olarak düğüm içerisindeki 1.Sayı ve 2.Sayı değerlerini sırasıyla yazdırırım
            locate = locate->nextLink; //Locate düğümüne bir sonraki düğümü işaret eden bilgiyi aktarırım
        }
    }
}
void reverse(int tempValue) //Düğüm verilerine(Value = 1.Sayi: 0, 2.Sayı: 1) değer alan ve içerikleri tersine sıralayan fonksiyon
{
    struct node* temp = root; //Değişimleri kayıt etmek ve kullanmak için oluşturulan düğüm
    struct node* iter = root; //Listede gezerken verileri taşımak için düğüm oluşturdum
    int nodeLength = 0; //Düğüm adetini sayan integer tipinde değişken

    for (; temp->nextLink != NULL; nodeLength++) //Sınırsız döngü içinde Temp'in toplam düğüm adetini ve bir sonraki düğümlerini bulmayı sağlarım
    {
        temp = temp->nextLink; //Bir sonraki işaret edilen düğümü Temp'e aktar
    }
    if (tempValue == 0) //1.Sayi > 2.Sayı'dan Büyükse (0)
    {
        int i = 0;
        for (; i <= nodeLength / 2; i++) //Sınırsız döngü içinde toplam düğüm adetinin yarısı kadar işlem yapmasını sağlarım. Böylelikle 2.kez düğüm tersten sıralama yapmasına engel olurum
        {
            int pool = iter->data1; //Iter adlı düğümün verisini kaybetmemek ve sonradan kullanmak için Pool adında integer tipi değişkende tutarım
            iter->data1 = temp->data1; //Temp düğümü, en son düğümden başlayarak verileri en baştan başlayan Iter düğümüne atarım
            temp->data1 = pool; //Temp düğümüne Pool değişkeni değerini atarım
            temp = temp->prevLink; //Temp düğümünü sondan bir öndeki düğüme işaret ederim
            iter = iter->nextLink; //Iter düğümünü baştan bir sonraki düğüme işaret ederim
        }
    }
    else if (tempValue == 1) //1.Sayi < 2.Sayı'dan Küçükse (1)
    {
        int i = 0;
        for (; i <= nodeLength / 2; i++) //Sınırsız döngü içinde toplam düğüm adetinin yarısı kadar işlem yapmasını sağlarım. Böylelikle 2.kez düğüm tersten sıralama yapmasına engel olurum
        {
            int pool = iter->data2; //Iter adlı düğümün verisini kaybetmemek ve sonradan kullanmak için Pool adında integer tipi değişkende tutarım
            iter->data2 = temp->data2; //Temp düğümü, en son düğümden başlayarak verileri en baştan başlayan Iter düğümüne atarım
            temp->data2 = pool; //Temp düğümüne Pool değişkeni değerini atarım
            temp = temp->prevLink; //Temp düğümünü sondan bir öndeki düğüme işaret ederim
            iter = iter->nextLink; //Iter düğümünü baştan bir sonraki düğüme işaret ederim
        }
    }
    printList(); //Her işlem sonu değişimleri görmek için listeyi yazdırma fonksiyonunu çağırırım
}
void compare() //Karşılaştırma fonksiyonu
{
    struct node* temp = root; //Düğümlerde sırasıyla gezinebilmek için listede başını işaret eden Root düğümünü aktarırım
    int number1, number2; //Düğüm verileri aralarında karşılaştırma için 2 adet önceden integer tipinde değişken oluşturdum
    while (temp != NULL) //Temp düğümü NULL olana kadar düğümlerde ilerlemesi için döngü oluşturdum
    {
        number1 = temp->data1; //Temp düğümün 1.Verisini Number1 değişkenine aktardım
        number2 = temp->data2; //Temp düğümün 2.Verisini Number1 değişkenine aktardım
        if (number1 > number2) //1.Sayı > 2.Sayı'dan Büyük olursa
        {
            printf("(1.Sayı: %d, 2.Sayı: %d 'dan Büyük olduğu için düğümün 1.Sayıları tersine sıralandı.) \n", number1, number2);
            reverse(0); //1.Verinin tersine sıralanması için Reverse fonksiyonunu çağırdım
        }
        temp = temp->nextLink; //Döngünün ve düğüm karşılaştırmasının devamlığını sağlamak için Temp düğümüne sonraki düğümü işaret eden düğümü aktarırım
    }
    temp = root; // Diğer koşulların karşılaştırılması için düğüm başına geri gelmek wiçin Root düğümünü Temp düğümüne aktardım
    while (temp != NULL)
    {
        number1 = temp->data1; //Temp düğümün 1.Verisini Number1 değişkenine aktardım
        number2 = temp->data2; //Temp düğümün 2.Verisini Number1 değişkenine aktardım
        if (number1 == number2) //1.Sayı = 2.Sayı'ya Eşit olursa
        {
            printf("(1.Sayı: %d = 2.Sayı: %d 'ya  Eşit olduğu için düğümün 2.Sayıları tersine sıralandı.) \n", number1, number2);
            reverse(1); //2.Verinin tersine sıralanması için Reverse fonksiyonunu çağırdım
        }
        temp = temp->nextLink; //Döngünün ve düğüm karşılaştırmasının devamlığını sağlamak için Temp düğümüne sonraki düğümü işaret eden düğümü aktarırım
    }
    temp = root; //Diğer koşulların karşılaştırılması için düğüm başına geri gelmek için Root düğümünü Temp düğümüne aktardım
    while (temp != NULL)
    {
        number1 = temp->data1; //Temp düğümün 1.Verisini Number1 değişkenine aktardım
        number2 = temp->data2; //Temp düğümün 2.Verisini Number1 değişkenine aktardım
        if (number1 < number2) //1.Sayı < 2.Sayı'dan Küçük olursa
        {
            printf("(1.Sayı: %d, 2.Sayı: %d 'dan Küçük olduğu için düğümün sayıları arasında yer değişmi yapıldı.) \n", number1, number2);
            int pool = temp->data1; //Düğüm verileri arasında yer değişikliği yapabilmek için düğümün 1.verisini integer tipinde Pool adlı değişkene aktardım
            temp->data1 = temp->data2; //Düğümün 1.verisine düğümün 2.verisini aktardım
            temp->data2 = pool; //Düğümün 2.verisine öncedne elde tuttuğum Pool değişkeni içindeki düğümün 1.verisini aktardım
            printList(); //İşlem sonunda oluşan değişikliği görebilemek için listeyi yazdıma fonksiyonunu çağırdım
        }
        temp = temp->nextLink; //Döngünün ve düğüm karşılaştırmasının devamlığını sağlamak için Temp düğümüne sonraki düğümü işaret eden düğümü aktarırım
    }
}
int main()
{
    setlocale(LC_ALL, "Turkish"); //Türkçe Karakteri desteklemesi için kullanıyorum
    string data; // Dosyadan okudan verileri elde tutması için Data adında string tipi değişken oluşturdum
    ifstream file; //ifstream adlı kütüphaneyi rahat kullanabilmek adına File adında nesne oluşturdum
    file.open("Sayilar.txt"); //File adlı nesne ile Numberlar.txt adlı metin Filesını açması için open işlevini çalıştırdım
    file >> data; //File adlı nesne ile açtığım Countilar.txt adlı metin Filesının içeriklerini ">>" aktarma operatörü ile Data adlı string tipi değişkenimin içine aktardırdım
    file.close(); //File adlı nesne ile işimi bitirmek için close işlevini gerçekleştirdim
    vector<string> vectorArray{ parse(data, '#') }; //Ayarlanılabilir dizi yardımıyla string tipinde vektör açtım ve içine Fileda yer alan Dataleri ayırma işlemi yapan fonksiyon sonucunu aktardım
    int64_t number1 = _atoi64(vectorArray[0].data()); //Vektörde bulunan bölümlendirilmiş Datayi rahat kullanmak için .data() alt fonksiyonunu ve _atoi64 metodu ile string Data tipini integer Data tipine dönüştürmek için kullandım
    //815102162524 (Number1)
    int64_t number2 = _atoi64(vectorArray[1].data()); //Vektörde bulunan bölümlendirilmiş Datayi rahat kullanmak için .data() alt fonksiyonunu ve _atoi64 metodu ile string Data tipini integer Data tipine dönüştürmek için kullandım
    //622101830754 (Number2)
    if (step(number1) == step(number2)) //Step fonksiyonunun ürettiği basamak adeti, veriler arasında uyumlumu karşılaştırdım
    {
        int Steps = step(number1); //Basamaklar her ikisindede aynı ise Steps değişkenime değeri aktardım
        for (int64_t count = Steps; count > 0; count = count - 3)
        {
            int64_t temp1 = number1 % (int64_t)pow(10, count); //Countının soldan sağa doğru 3 Step elde etmek için modunu aldım
            int64_t temp2 = number2 % (int64_t)pow(10, count); //Countının soldan sağa doğru 3 Step elde etmek için modunu aldım
            temp1 = temp1 - (number1 % (int64_t)pow(10, count - 3)); //Countının soldan sağa sadece 3 basamağını almak için fazla olan Stepları Countıdan çıkardım
            temp2 = temp2 - (number2 % (int64_t)pow(10, count - 3)); //Countının soldan sağa sadece 3 basamağını almak için fazla olan Stepları Countıdan çıkardım
            int64_t value1 = temp1 / (int64_t)pow(10, count - 3); //Countının diğer Steplardan farkı sonucunda oluşan 0 değerli Stepları yok etmek için ise 10 tabanında bölüm gerçekleştirerek 3 Steplı Countı elde etmiş oldum
            int64_t value2 = temp2 / (int64_t)pow(10, count - 3); //Countının diğer Steplardan farkı sonucunda oluşan 0 değerli Stepları yok etmek için ise 10 tabanında bölüm gerçekleştirerek 3 Steplı Countı elde etmiş oldum
            if (((value1 % (int64_t)pow(10, 2)) == value1)) //Üçerli basamaklara ayrılan verilerin üçüncü basamığının olup olmadığını teyit etmek için koşul oluşturdum
            {
                printf("0%d Degerine + 100 eklendi. \n", value1);
                value1 += 100; //Üçüncü basamağı, yok veya 0 ise 100 ekleyerek üçüncü basamağına 1 eklerim
            }
            else if (((value2 % (int64_t)pow(10, 2)) == value2)) //Üçerli basamaklara ayrılan verilerin üçüncü basamığının olup olmadığını teyit etmek için koşul oluşturdum
            {
                printf("0%d Degerine + 100 eklendi. \n", value2);
                value2 += 100; //Üçüncü basamağı, yok veya 0 ise 100 ekleyerek üçüncü basamağına 1 eklerim
            }
            add(value1, value2); //İstenilen üç basamaklı verileri sırasıyla düğüme eklemek üzere Add fonksiyonunu çağırırım
        }
    }
    printf("İlk Liste;\n");
    printList(); //Listeyi yazdıma fonksiyonunu çağırdım
    printf("\n"); //Alt satır
    compare(); //Karşılaştırma fonksiyonunu çağırdım
    printf("\n"); //Alt satır
}//MAİN END
