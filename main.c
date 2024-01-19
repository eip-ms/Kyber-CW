#include <stdint.h>
#include <stdlib.h>
#include <kyber-c/kem.h>

#include "simpleserial.h"

#define SS_VER SS_VER_2_1

uint8_t kyber_handle(uint8_t cmd, uint8_t scmd, uint8_t len, uint8_t *buf)
{
	 uint8_t pk[CRYPTO_PUBLICKEYBYTES];
	 uint8_t sk[CRYPTO_SECRETKEYBYTES];
	 uint8_t ct[CRYPTO_CIPHERTEXTBYTES];
	 uint8_t key_a[CRYPTO_BYTES];
	 uint8_t key_b[CRYPTO_BYTES];

	//generate keys
	crypto_kem_keypair(&pk, &sk);

	trigger_high();

	crypto_kem_enc(scmd, key_b, pk);

	trigger_low();
}

int main()
{
	platform_init();
	init_uart();

	trigger_setup();

	simpleserial_init();

	simpleserial_addcmd('p', 16, kyber_handle);

	while(1)
		simpleserial_get();	
}