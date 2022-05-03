/**
 * @brief Kumanda düğmesinin sayısal kodunu döndüren işlev
 * 
 * @return uint32_t 
 */
uint32_t dugmeKoduGonder() {
	// decode() işlevi veri yoksa 0 döner, varsa 1 döner
	if (IrReceiver.decode())  
	{
		uint32_t dugme = IrReceiver.decodedIRData.decodedRawData;//kumandaDugme.value;// Results of decoding are stored in result.value     
		logDugme(dugme);
    
		// Bir sonraki değeri al
		IrReceiver.resume();
		return dugme;
	} else {
		return 0;
	}
}

/**
 * @brief 32 bitlik bir değeri ters çevirir.
 * 
 * @param val 32 bitlik sayı
 * @return uint32_t 
 */
uint32_t bitleriTersCevir( uint32_t val )
{
	uint32_t ret = 0;
	for (uint8_t i = 0; i < 32; i++)
	{
		ret = (ret << 1) | ((val >> i) & 1);
	}
	return ret;
}

/**
 * @brief Bir kumanda düğmesine basıldığında seri porta bilgi basan işlev
 * 
 * @param dugme 32bitlik kumanda düğmesi değeri
 */
void logDugme(uint32_t dugme) {
	if(dugme != 0){
		String log = String("[GMK] ")
				+ dugme
				+ String(" ")
				+ bitleriTersCevir(dugme)
				+ String(" dugmesine basildi");
		Serial.println(log);
	}
}