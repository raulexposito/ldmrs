#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

#include <sys/types.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>


int conectarConServidor (
						char *Host_Servidor,
						char *Servicio)
{
	struct sockaddr_in Direccion;
	struct servent *Puerto;
	struct hostent *Host;
	int Descriptor;
	
	Puerto = getservbyname (Servicio, "tcp");
	if (Puerto == NULL)
		return -1;
	
	Host = gethostbyname (Host_Servidor);
	if (Host == NULL)
		return -1;
	
	Direccion.sin_family = AF_INET;
	Direccion.sin_addr.s_addr = ((struct in_addr *)(Host->h_addr))->s_addr;
	Direccion.sin_port = Puerto->s_port;
	
	Descriptor = socket (AF_INET, SOCK_STREAM, 0);
	if (Descriptor == -1)
		return -1;
	
	if (connect (
				 Descriptor,
				 (struct sockaddr *)&Direccion,
				 sizeof (Direccion)) == -1)
	{
		return -1;
	}
	
	return Descriptor;
}

void recibeDelLaser (int fd, void *Datos, int Longitud)
{
	read (fd, Datos, Longitud);
}


void mandaAlLaser (int fd, void *Datos, int Longitud)
{
	write (fd, Datos, Longitud);
}


uint8_t* comandoViernes () {
	uint8_t* buffer = new uint8_t[26];
	buffer[0] = 0xAF; // magic word
	buffer[1] = 0xFE;
	buffer[2] = 0xC0;
	buffer[3] = 0xC2;
	buffer[4] = 0x00; // Size of previous message, here just left to nullL
	buffer[5] = 0x00;
	buffer[6] = 0x00;
	buffer[7] = 0x00;
	buffer[8] = 0x00; // Size of data block
	buffer[9] = 0x00;
	buffer[10] = 0x00;
	buffer[11] = 0x19;
	buffer[12] = 0x00;	// Reserved + source Id
	buffer[13] = 0x00;
	buffer[14] = 0x20;	// Data Type - 2010 = command
	buffer[15] = 0x10;
	buffer[16] = 0x00;	// 4* ntpp time (s) + 4* fractions of a second
	buffer[17] = 0x00;
	buffer[18] = 0x00;
	buffer[19] = 0x00;
	buffer[20] = 0x00;
	buffer[21] = 0x00;
	buffer[22] = 0x00;
	buffer[23] = 0x00;
	
	buffer[24] = 0x20;	// Command Type - 0020 = start measure
	buffer[25] = 0x00;
	return buffer;
}


uint8_t* comandoReset () {
	uint8_t* buffer = new uint8_t[28];
	buffer[0] = 0xAF; // magic word
	buffer[1] = 0xFE;
	buffer[2] = 0xC0;
	buffer[3] = 0xC2;
	buffer[4] = 0x00; // Size of previous message, here just left to nullL
	buffer[5] = 0x00;
	buffer[6] = 0x00;
	buffer[7] = 0x00;
	buffer[8] = 0x00; // Size of data block
	buffer[9] = 0x00;
	buffer[10] = 0x00;
	buffer[11] = 0x04;
	buffer[12] = 0x00;	// Reserved + source Id
	buffer[13] = 0x00;
	buffer[14] = 0x20;	// Data Type - 2010 = command
	buffer[15] = 0x10;
	buffer[16] = 0x00;	// 4* ntpp time (s) + 4* fractions of a second
	buffer[17] = 0x00;
	buffer[18] = 0x00;
	buffer[19] = 0x00;
	buffer[20] = 0x00;
	buffer[21] = 0x00;
	buffer[22] = 0x00;
	buffer[23] = 0x00;
	
	buffer[24] = 0x00;	// Command Type - 0000 = RESET
	buffer[25] = 0x00;	
	buffer[26] = 0x00;
	buffer[27] = 0x00;		
	return buffer;
}

uint8_t* comandoGetPort () {
	uint8_t* buffer = new uint8_t[30];
	buffer[0] = 0xAF; // magic word
	buffer[1] = 0xFE;
	buffer[2] = 0xC0;
	buffer[3] = 0xC2;
	buffer[4] = 0x00; // Size of previous message, here just left to nullL
	buffer[5] = 0x00;
	buffer[6] = 0x00;
	buffer[7] = 0x00;
	buffer[8] = 0x00; // Size of data block
	buffer[9] = 0x00;
	buffer[10] = 0x00;
	buffer[11] = 0x06;
	buffer[12] = 0x00;	// Reserved + source Id
	buffer[13] = 0x00;
	buffer[14] = 0x20;	// Data Type - 2010 = command
	buffer[15] = 0x10;
	buffer[16] = 0x00;	// 4* ntpp time (s) + 4* fractions of a second
	buffer[17] = 0x00;
	buffer[18] = 0x00;
	buffer[19] = 0x00;
	buffer[20] = 0x00;
	buffer[21] = 0x00;
	buffer[22] = 0x00;
	buffer[23] = 0x00;

	buffer[24] = 0x11;	// Command Type - 0011 = get param
	buffer[25] = 0x00;
	buffer[26] = 0x00;	//reservado
	buffer[27] = 0x00;
	buffer[28] = 0x01;	// Obtener Puerto
	buffer[29] = 0x10;



	return buffer;
}


uint8_t* comandoGetGateway () {
	uint8_t* buffer = new uint8_t[30];
	buffer[0] = 0xAF; // magic word
	buffer[1] = 0xFE;
	buffer[2] = 0xC0;
	buffer[3] = 0xC2;
	buffer[4] = 0x00; // Size of previous message, here just left to nullL
	buffer[5] = 0x00;
	buffer[6] = 0x00;
	buffer[7] = 0x00;
	buffer[8] = 0x00; // Size of data block
	buffer[9] = 0x00;
	buffer[10] = 0x00;
	buffer[11] = 0x06;
	buffer[12] = 0x00;	// Reserved + source Id
	buffer[13] = 0x00;
	buffer[14] = 0x20;	// Data Type - 2010 = command
	buffer[15] = 0x10;
	buffer[16] = 0x00;	// 4* ntpp time (s) + 4* fractions of a second
	buffer[17] = 0x00;
	buffer[18] = 0x00;
	buffer[19] = 0x00;
	buffer[20] = 0x00;
	buffer[21] = 0x00;
	buffer[22] = 0x00;
	buffer[23] = 0x00;

	buffer[24] = 0x11;	// Command Type - 0011 = get param
	buffer[25] = 0x00;
	buffer[26] = 0x00;	//reservado
	buffer[27] = 0x00;
	buffer[28] = 0x03;	// Obtener Gateway
	buffer[29] = 0x10;



	return buffer;
}


uint8_t* comandoGetSubnetMask () {
	uint8_t* buffer = new uint8_t[30];
	buffer[0] = 0xAF; // magic word
	buffer[1] = 0xFE;
	buffer[2] = 0xC0;
	buffer[3] = 0xC2;
	buffer[4] = 0x00; // Size of previous message, here just left to nullL
	buffer[5] = 0x00;
	buffer[6] = 0x00;
	buffer[7] = 0x00;
	buffer[8] = 0x00; // Size of data block
	buffer[9] = 0x00;
	buffer[10] = 0x00;
	buffer[11] = 0x06;
	buffer[12] = 0x00;	// Reserved + source Id
	buffer[13] = 0x00;
	buffer[14] = 0x20;	// Data Type - 2010 = command
	buffer[15] = 0x10;
	buffer[16] = 0x00;	// 4* ntpp time (s) + 4* fractions of a second
	buffer[17] = 0x00;
	buffer[18] = 0x00;
	buffer[19] = 0x00;
	buffer[20] = 0x00;
	buffer[21] = 0x00;
	buffer[22] = 0x00;
	buffer[23] = 0x00;

	buffer[24] = 0x11;	// Command Type - 0011 = get param
	buffer[25] = 0x00;
	buffer[26] = 0x00;	//reservado
	buffer[27] = 0x00;
	buffer[28] = 0x02;	// Obtener subnet mask
	buffer[29] = 0x10;



	return buffer;
}

uint8_t* comandoGetIP () {
	uint8_t* buffer = new uint8_t[30];
	buffer[0] = 0xAF; // magic word
	buffer[1] = 0xFE;
	buffer[2] = 0xC0;
	buffer[3] = 0xC2;
	buffer[4] = 0x00; // Size of previous message, here just left to nullL
	buffer[5] = 0x00;
	buffer[6] = 0x00;
	buffer[7] = 0x00;
	buffer[8] = 0x00; // Size of data block
	buffer[9] = 0x00;
	buffer[10] = 0x00;
	buffer[11] = 0x06;
	buffer[12] = 0x00;	// Reserved + source Id
	buffer[13] = 0x00;
	buffer[14] = 0x20;	// Data Type - 2010 = command
	buffer[15] = 0x10;
	buffer[16] = 0x00;	// 4* ntpp time (s) + 4* fractions of a second
	buffer[17] = 0x00;
	buffer[18] = 0x00;
	buffer[19] = 0x00;
	buffer[20] = 0x00;
	buffer[21] = 0x00;
	buffer[22] = 0x00;
	buffer[23] = 0x00;
	
	buffer[24] = 0x11;	// Command Type - 0011 = get param
	buffer[25] = 0x00;	
	buffer[26] = 0x00;	//reservado
	buffer[27] = 0x00;	
	buffer[28] = 0x00;	// Obtener direccion IP
	buffer[29] = 0x10;



	return buffer;
}

uint8_t* comandoSetIP () {
	uint8_t* buffer = new uint8_t[34];
	buffer[0] = 0xAF; // magic word
	buffer[1] = 0xFE;
	buffer[2] = 0xC0;
	buffer[3] = 0xC2;
	buffer[4] = 0x00; // Size of previous message, here just left to nullL
	buffer[5] = 0x00;
	buffer[6] = 0x00;
	buffer[7] = 0x00;
	buffer[8] = 0x00; // Size of data block
	buffer[9] = 0x00;
	buffer[10] = 0x00;
	buffer[11] = 0x0A;
	buffer[12] = 0x00;	// Reserved + source Id
	buffer[13] = 0x00;
	buffer[14] = 0x20;	// Data Type - 2010 = command
	buffer[15] = 0x10;
	buffer[16] = 0x00;	// 4* ntpp time (s) + 4* fractions of a second
	buffer[17] = 0x00;
	buffer[18] = 0x00;
	buffer[19] = 0x00;
	buffer[20] = 0x00;
	buffer[21] = 0x00;
	buffer[22] = 0x00;
	buffer[23] = 0x00;

	buffer[24] = 0x10;	// Command Type - 0010 = set param
	buffer[25] = 0x00;
	buffer[26] = 0x00;	//reservado
	buffer[27] = 0x00;
	buffer[28] = 0x00;	// Set direccion IP
	buffer[29] = 0x10;
	buffer[30] = 0x0D;	//direccion IP
	buffer[31] = 0x96;
	buffer[32] = 0x75;
	buffer[33] = 0xA3;



	return buffer;
}

uint8_t* comandoSetGateway () {
	uint8_t* buffer = new uint8_t[34];
	buffer[0] = 0xAF; // magic word
	buffer[1] = 0xFE;
	buffer[2] = 0xC0;
	buffer[3] = 0xC2;
	buffer[4] = 0x00; // Size of previous message, here just left to nullL
	buffer[5] = 0x00;
	buffer[6] = 0x00;
	buffer[7] = 0x00;
	buffer[8] = 0x00; // Size of data block
	buffer[9] = 0x00;
	buffer[10] = 0x00;
	buffer[11] = 0x0A;
	buffer[12] = 0x00;	// Reserved + source Id
	buffer[13] = 0x00;
	buffer[14] = 0x20;	// Data Type - 2010 = command
	buffer[15] = 0x10;
	buffer[16] = 0x00;	// 4* ntpp time (s) + 4* fractions of a second
	buffer[17] = 0x00;
	buffer[18] = 0x00;
	buffer[19] = 0x00;
	buffer[20] = 0x00;
	buffer[21] = 0x00;
	buffer[22] = 0x00;
	buffer[23] = 0x00;

	buffer[24] = 0x10;	// Command Type - 0010 = set param
	buffer[25] = 0x00;
	buffer[26] = 0x00;	//reservado
	buffer[27] = 0x00;
	buffer[28] = 0x03;	// Set gateway
	buffer[29] = 0x10;
	buffer[30] = 0x02;	//gateway
	buffer[31] = 0x96;
	buffer[32] = 0x75;
	buffer[33] = 0xA3;



	return buffer;
}

uint8_t* comandoSetPort () {
	uint8_t* buffer = new uint8_t[34];
	buffer[0] = 0xAF; // magic word
	buffer[1] = 0xFE;
	buffer[2] = 0xC0;
	buffer[3] = 0xC2;
	buffer[4] = 0x00; // Size of previous message, here just left to nullL
	buffer[5] = 0x00;
	buffer[6] = 0x00;
	buffer[7] = 0x00;
	buffer[8] = 0x00; // Size of data block
	buffer[9] = 0x00;
	buffer[10] = 0x00;
	buffer[11] = 0x0A;
	buffer[12] = 0x00;	// Reserved + source Id
	buffer[13] = 0x00;
	buffer[14] = 0x20;	// Data Type - 2010 = command
	buffer[15] = 0x10;
	buffer[16] = 0x00;	// 4* ntpp time (s) + 4* fractions of a second
	buffer[17] = 0x00;
	buffer[18] = 0x00;
	buffer[19] = 0x00;
	buffer[20] = 0x00;
	buffer[21] = 0x00;
	buffer[22] = 0x00;
	buffer[23] = 0x00;

	buffer[24] = 0x10;	// Command Type - 0010 = set param
	buffer[25] = 0x00;
	buffer[26] = 0x00;	//reservado
	buffer[27] = 0x00;
	buffer[28] = 0x01;	// Set port
	buffer[29] = 0x10;
	buffer[30] = 0x50;	//port
	buffer[31] = 0x00;
	buffer[32] = 0x00;
	buffer[33] = 0x00;



	return buffer;
}

uint8_t* comandoSaveConfig () {
	uint8_t* buffer = new uint8_t[28];
	buffer[0] = 0xAF; // magic word
	buffer[1] = 0xFE;
	buffer[2] = 0xC0;
	buffer[3] = 0xC2;
	buffer[4] = 0x00; // Size of previous message, here just left to nullL
	buffer[5] = 0x00;
	buffer[6] = 0x00;
	buffer[7] = 0x00;
	buffer[8] = 0x00; // Size of data block
	buffer[9] = 0x00;
	buffer[10] = 0x00;
	buffer[11] = 0x04;
	buffer[12] = 0x00;	// Reserved + source Id
	buffer[13] = 0x00;
	buffer[14] = 0x20;	// Data Type - 2010 = command
	buffer[15] = 0x10;
	buffer[16] = 0x00;	// 4* ntpp time (s) + 4* fractions of a second
	buffer[17] = 0x00;
	buffer[18] = 0x00;
	buffer[19] = 0x00;
	buffer[20] = 0x00;
	buffer[21] = 0x00;
	buffer[22] = 0x00;
	buffer[23] = 0x00;

	buffer[24] = 0x04;	// Command Type - 0004 = save config
	buffer[25] = 0x00;
	buffer[26] = 0x00;	//reservado
	buffer[27] = 0x00;




	return buffer;
}


int main ()
{
	//while (true) {
	int descriptorSocketServidor = conectarConServidor ("laser13", "puerto_laser");
	if (descriptorSocketServidor == 1)
	{
		printf ("No puedo establecer conexion con el servidor\n");
		return (-1);
	}
	
	uint8_t* buffer;
	
//	 buffer = comandoViernes();mandaAlLaser (descriptorSocketServidor, buffer, 26);


//	 buffer = comandoGetPort();mandaAlLaser (descriptorSocketServidor, buffer, 30);recibeDelLaser (descriptorSocketServidor, buffer, 32);
//	 buffer = comandoGetSubnetMask();mandaAlLaser (descriptorSocketServidor, buffer, 30);recibeDelLaser (descriptorSocketServidor, buffer, 32);
//	 buffer = comandoGetGateway();mandaAlLaser (descriptorSocketServidor, buffer, 30);recibeDelLaser (descriptorSocketServidor, buffer, 32);
//	buffer = comandoSetIP();mandaAlLaser (descriptorSocketServidor, buffer, 34);recibeDelLaser (descriptorSocketServidor, buffer, 26);
//	buffer = comandoSetPort();mandaAlLaser (descriptorSocketServidor, buffer, 34);recibeDelLaser (descriptorSocketServidor, buffer, 26);
//	 buffer = comandoSetGateway();mandaAlLaser (descriptorSocketServidor, buffer, 34);recibeDelLaser (descriptorSocketServidor, buffer, 26);
//	buffer = comandoSaveConfig();mandaAlLaser (descriptorSocketServidor, buffer, 28);recibeDelLaser (descriptorSocketServidor, buffer, 26);
	buffer = comandoGetIP();mandaAlLaser (descriptorSocketServidor, buffer, 30);recibeDelLaser (descriptorSocketServidor, buffer, 32);
//
//
//	 buffer = comandoReset();mandaAlLaser (descriptorSocketServidor, buffer, 28);

//	printf("el buffer es %h",buffer);
	
	//recibeDelLaser (descriptorSocketServidor, buffer, 32);
	
	
//	printf ("Soy cliente, He recibido : %d\n", buffer);
	close (descriptorSocketServidor);
	//}
}
