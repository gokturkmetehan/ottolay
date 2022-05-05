#include <Servo.h> // kol servoları için gerekli kitaplık

//
// Kol pinleri
//
#define SOL_KOL 6 // sol kol pini
#define SAG_KOL 7 // sağ kol pini

//
// kol servolari için nesne yaratıyoruz
//
Servo KOLSOL, KOLSAG;

// kol servolari için gerekli değişkenler
int adj[] = {0, 0,};
int pos[] = {90, 90};
int shift = 60;
int shift_inc = 10;
int shift_delay = 50;

/**
 * @brief `setup()` işlevi içerisinde kolları ilklendirmek gerekiyor.
 * Bu işi `kollariHazirla()` işlevi ile yapıyoruz.
 * Bu işlev setup() işlevinde çağrılmazsa kollar çalışmaz
 */
void kollariHazirla()
{
	KOLSOL.attach(SOL_KOL);
	KOLSAG.attach(SAG_KOL);
	move_servo();
	delay(100);
}

/**
 * @brief Her iki kolu aynı anda yukarı kaldırır
 *
 * @param tekrar işlevin kaç kere çalışacağı bilgisi
 */
void kollarYukari(int tekrar)
{
	for (int i = 0; i < tekrar; i++)
	{
		KOLSOL.write(160);
		KOLSAG.write(20);
		delay(shift_delay);
	}
}

/**
 * @brief Her iki kolu aynı anda aşağı indirir
 *
 * @param tekrar işlevin kaç kere çalışacağı bilgisi
 */
void kollarAsagi(int tekrar)
{
	for (int i = 0; i < tekrar; i++)
	{
		KOLSOL.write(20);
		KOLSAG.write(160);
		delay(shift_delay);
	}
}

/**
 * @brief sol kolu sallar
 *
 * @param tekrar işlevin kaç kere çalışacağı bilgisi
 */
void kolSallaSol(int tekrar)
{
	for (int i = 0; i < tekrar; i++)
	{
		for (int angle = 90; angle < 90 + shift; angle += shift_inc)
		{
			pos[1] = angle;
			move_servo();
			delay(shift_delay);
		}
		for (int angle = 90 + shift; angle > 90 - shift; angle -= shift_inc)
		{
			pos[1] = angle;
			move_servo();
			delay(shift_delay);
		}
		for (int angle = 90 - shift; angle < 90; angle += shift_inc)
		{
			pos[1] = angle;
			move_servo();
			delay(shift_delay);
		}
	}
}

/**
 * @brief sağ kolu sallar
 *
 * @param tekrar işlevin kaç kere çalışacağı bilgisi
 */
void kolSallaSag(int tekrar)
{
	for (int i = 0; i < tekrar; i++)
	{
		for (int angle = 90; angle < 90 + shift; angle += shift_inc)
		{
			pos[2] = angle;
			move_servo();
			delay(shift_delay);
		}
		for (int angle = 90 + shift; angle > 90 - shift; angle -= shift_inc)
		{
			pos[2] = angle;
			move_servo();
			delay(shift_delay);
		}
		for (int angle = 90 - shift; angle < 90; angle += shift_inc)
		{
			pos[2] = angle;
			move_servo();
			delay(shift_delay);
		}
	}
}

void move_servo()
{
	KOLSOL.write(pos[1] + adj[1]);
	KOLSAG.write(pos[2] + adj[2]);
}