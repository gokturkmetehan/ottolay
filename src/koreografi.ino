void koreografiYap()
{
	Otto.clearMouth();
	Otto.putMouth(thunder);
	for (int count = 0; count < 2; count++)
	{
		Otto.walk(1, 1000, 1); // FORWARD
	}
	kollarAsagi(1);
	Otto.putMouth(happyOpen);
	for (int count = 0; count < 5; count++)
	{
		Otto.moonwalker(1, 1000, 25, 1);
	}
	kollarYukari(1);
	for (int count = 0; count < 2; count++)
	{
		Otto.walk(1, 1000, -1); // BACKWARD
	}
	Otto.putMouth(smile);
	for (int count = 0; count < 5; count++)
	{
		Otto.moonwalker(1, 1000, 25, -1);
	}
	kolSallaSol(1);
	Otto.putMouth(tongueOut);
	for (int count = 0; count < 2; count++)
	{
		Otto.swing(1, 1000, 25);
	}
	kolSallaSag(1);
	Otto.putMouth(heart);
	for (int count = 0; count < 2; count++)
	{
		Otto.jitter(1, 1000, 25);
	}
	for (int count = 0; count < 2; count++)
	{
		Otto.flapping(1, 1000, 25, 1);
	}
	kollarAsagi(1);
	Otto.putMouth(vamp2);
	for (int count = 0; count < 2; count++)
	{
		Otto.flapping(1, 1000, 25, -1);
	}
	for (int count = 0; count < 5; count++)
	{
		Otto.tiptoeSwing(1, 1000, 25);
	}
	for (int count = 0; count < 3; count++)
	{
		Otto.updown(1, 1000, 25);
	}
	Otto.writeText("BETULHOCA", 80);
}