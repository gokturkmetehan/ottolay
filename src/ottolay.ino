#include <IRremote.h>

//
// El, Bacak, Ayak pinleri nerede:
//
#define SOL_BACAK	2		// sol bacak pini, servo[0]
#define SAG_BACAK	3		// sağ bacak pini, servo[1]
#define SOL_AYAK	4		// sol ayak pini, servo[2]
#define SAG_AYAK	5		// sağ ayak pini, servo[3]
#define Buzzer		13	// buzzer pini

// Kızılötesi almaç pini nerede:
#define IR_RECEIVE_PIN 10
//int IR_RECEIVE_PIN = 10;

// 8x8 Led Matris Pinleri
#define CLK A1 // Clock pin
#define CS A2  // Chip Select pin
#define DIN A3 // Data In pin
#define Orientation 0// 8x8 LED Matrix orientation  Top  = 1, Bottom = 2, Left = 3, Right = 4



void setup() {
	// Seri monitörü başlat
	Serial.begin(115200);
	Serial.println("[GMK] Seri monitor basladi!");

	// Kızıl ötesi almaç çalışmaya başlasın
	IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

	// Ottonun ağzını hazırla
	Otto.initMATRIX( DIN, CS, CLK, Orientation);
  Otto.clearMouth();
	duyguYurek();

	// Otto'nun pinlerini bildir
	Otto.init(SOL_BACAK, SAG_BACAK, SOL_AYAK, SAG_AYAK, true, Buzzer);
	// Otto dinlenme duruşunda
	Otto.home();
}

void loop() {
	uint32_t dugme = dugmeKoduGonder();
	if (dugme == 0) {
		Otto.home();
	} else if (dugme == 3125149440){
		Otto.clearMouth();
		Otto.walk(1,1000,1);
		Otto.home();
	} else if (dugme == 3108437760){
		Otto.home();
		Otto.clearMouth();
		duyguBas("METEHAN");
	}
}
