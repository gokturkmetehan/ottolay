#include <IRremote.h> // kızılötesi kumanda kullanabilmek için gerekli kitaplık

//
// Bacak, Ayak pinleri
//
#define SOL_BACAK 2 // sol bacak pini, servo[0]
#define SAG_BACAK 3 // sağ bacak pini, servo[1]
#define SOL_AYAK  4 // sol ayak pini, servo[2]
#define SAG_AYAK  5 // sağ ayak pini, servo[3]
#define Buzzer   13 // buzzer pini

// Kızılötesi almaç pini
#define KO_ALMAC_PINI 10

// 8x8 Led Matris Pinleri
#define CLK A1 // Clock pin
#define CS  A2 // Chip Select pin
#define DIN A3 // Data In pin
#define YON 0  // 8x8 LED Matris Yönü  Top  = 1, Bottom = 2, Left = 3, Right = 4

void setup()
{
	// Seri monitörü başlat
	Serial.begin(115200);
	Serial.println("[GMK] Seri monitor basladi!");

	// Kızıl ötesi almaç çalışmaya başlasın
	IrReceiver.begin(KO_ALMAC_PINI, ENABLE_LED_FEEDBACK);

	// Ottonun ağzını hazırla
	Otto.initMATRIX(DIN, CS, CLK, YON);
	Otto.clearMouth();
	duyguYurek();

	// Kolları hazırla
	kollariHazirla();

	// Otto'nun pinlerini bildir
	Otto.init(SOL_BACAK, SAG_BACAK, SOL_AYAK, SAG_AYAK, true, Buzzer);
	// Otto dinlenme duruşunda
	Otto.home();
}

void loop()
{
	uint32_t dugme = dugmeKoduGonder();
	if (dugme == 0)
	{
		Otto.home();
	}
	else if (dugme == 3125149440)
	{
		koreografiYap();
	}
	else if (dugme == 3108437760)
	{
		Otto.home();
		Otto.clearMouth();
		duyguBas("METEHAN");
	}
}
