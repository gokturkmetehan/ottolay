#include <Otto.h>

// Bir Otto nesnesi yaratmamız gerekiyor
Otto Otto;

unsigned long int matris;

/**
 * @brief Otto'nun ağzına yürek resmi basar
 * 
 */
void duyguYurek() {
  matris = 0b010010111111111111011110001100;
  Otto.putMouth(matris, false);
  delay(1*1000);
}

/**
 * @brief Mutlu yüz ifadesi basar
 * 
 */
void duyguMutlu1() {
  Otto.putMouth(happyOpen);
    delay(1*1000);
}

/**
 * @brief Otto'nun 8x8 led matrisine yazı yazdırır. Bu işlev sadece büyük
 * ingilizce harfler, sayılar ve ": ; < > = @" biremlerini en çok
 * 9 birem olarak şekilde alır.
 * 
 * Ekrana bir kere yazdırır
 * 
 * @param metin Ottonun ağzında kayarak gösterilecek olan metin
 */
void duyguBas(const char * metin) {
  Otto.writeText (metin,80);
}

