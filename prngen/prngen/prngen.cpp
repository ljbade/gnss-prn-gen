#include <memory>
#include <cstdio>

unsigned short int shift_gps_g1(unsigned short int* g1_reg)
{
	// Shift the G1 register by 1 clock
	// G1 polynomial is 1 + x^3 + x^10, 10 bits

	unsigned short int g1_out    =  *g1_reg & 0x0001;            // Output  comes from stage 10, which is bit 1
	unsigned short int g1_tap_10 = (*g1_reg & 0x0001)      >> 0; // 1st tap comes from stage 10, which is bit 1
	unsigned short int g1_tap_3  = (*g1_reg & 0x0080)      >> 7; // 2nd tap comes from stage  3, which is bit 8
	unsigned short int g1_fb     =  (g1_tap_3 ^ g1_tap_10) << 9; // Taps are modulo 2 added together (XORed), then feedback into stage 1, which is bit 10
					   *g1_reg   = (*g1_reg >> 1) | g1_fb;       // Shift the register 1 bit left then OR the feedback bit into the register
	return g1_out;
}

unsigned short int shift_gps_g2(unsigned short int* g2_reg)
{
	// Shift the G2 register by 1 clock
	// G2 polynomial is 1 + x^2 + x^3 + x^6 + x^8 + x^9 + x^10, 10 bits

	unsigned short int g2_out    =  *g2_reg & 0x0001;            // Output  comes from stage 10, which is bit 1
	unsigned short int g2_tap_10 = (*g2_reg & 0x0001)      >> 0; // 1st tap comes from stage 10, which is bit 1
	unsigned short int g2_tap_9  = (*g2_reg & 0x0002)      >> 1; // 2nd tap comes from stage  9, which is bit 2
	unsigned short int g2_tap_8  = (*g2_reg & 0x0004)      >> 2; // 3rd tap comes from stage  8, which is bit 3
	unsigned short int g2_tap_6  = (*g2_reg & 0x0010)      >> 4; // 4th tap comes from stage  6, which is bit 5
	unsigned short int g2_tap_3  = (*g2_reg & 0x0080)      >> 7; // 5th tap comes from stage  3, which is bit 8
	unsigned short int g2_tap_2  = (*g2_reg & 0x0100)      >> 8; // 6th tap comes from stage  2, which is bit 9
	unsigned short int g2_fb     =  (g2_tap_2 ^ g2_tap_3 ^       // Taps are modulo 2 added together (XORed), then feedback into stage 1, which is bit 10
			                         g2_tap_6 ^ g2_tap_8 ^
									 g2_tap_9 ^ g2_tap_10) << 9;  
		               *g2_reg   = (*g2_reg >> 1) | g2_fb;       // Shift the register 1 bit left then OR the feedback bit into the register
	return g2_out;
}

unsigned short int shift_bds_g1(unsigned short int* g1_reg)
{
	// Shift the G1 register by 1 clock
	// G1 polynomial is 1 + x + x^7 + x^8 + x^9 + x^10 + x^11, 11 bits

	unsigned short int g1_out    =  *g1_reg & 0x0001;            // Output  comes from stage 11, which is bit 1
	unsigned short int g1_tap_11 = (*g1_reg & 0x0001)      >> 0; // 1st tap comes from stage 11, which is bit 1
	unsigned short int g1_tap_10 = (*g1_reg & 0x0002)      >> 1; // 2st tap comes from stage 10, which is bit 2
	unsigned short int g1_tap_9  = (*g1_reg & 0x0004)      >> 2; // 2st tap comes from stage  9, which is bit 3
	unsigned short int g1_tap_8  = (*g1_reg & 0x0008)      >> 3; // 2st tap comes from stage  8, which is bit 4
	unsigned short int g1_tap_7  = (*g1_reg & 0x0010)      >> 4; // 2st tap comes from stage  7, which is bit 5
	unsigned short int g1_tap_1  = (*g1_reg & 0x0400)      >> 10;// 2nd tap comes from stage  1, which is bit 11
	unsigned short int g1_fb     =  (g1_tap_1 ^ g1_tap_7 ^
		                             g1_tap_8 ^ g1_tap_9 ^
									 g1_tap_10^ g1_tap_11) << 10;// Taps are modulo 2 added together (XORed), then feedback into stage 1, which is bit 11
					   *g1_reg   = (*g1_reg >> 1) | g1_fb;       // Shift the register 1 bit left then OR the feedback bit into the register
	return g1_out;
}

unsigned short int shift_bds_g2(unsigned short int* g2_reg)
{
	// Shift the G2 register by 1 clock
	// G2 polynomial is 1 + x + x^2 + x^3 + x^4 + x^5 + x^8 + x^9 + x^11, 11 bits

	unsigned short int g2_out    =  *g2_reg & 0x0001;            // Output  comes from stage 11, which is bit 1
	unsigned short int g2_tap_11 = (*g2_reg & 0x0001)      >> 0; // 1st tap comes from stage 11, which is bit 1
	unsigned short int g2_tap_9  = (*g2_reg & 0x0004)      >> 2; // 2nd tap comes from stage  9, which is bit 3
	unsigned short int g2_tap_8  = (*g2_reg & 0x0008)      >> 3; // 3rd tap comes from stage  8, which is bit 4
	unsigned short int g2_tap_5  = (*g2_reg & 0x0040)      >> 6; // 4th tap comes from stage  5, which is bit 7
	unsigned short int g2_tap_4  = (*g2_reg & 0x0080)      >> 7; // 5th tap comes from stage  4, which is bit 8
	unsigned short int g2_tap_3  = (*g2_reg & 0x0100)      >> 8; // 6th tap comes from stage  3, which is bit 9
	unsigned short int g2_tap_2  = (*g2_reg & 0x0200)      >> 9; // 7th tap comes from stage  2, which is bit 10
	unsigned short int g2_tap_1  = (*g2_reg & 0x0400)      >> 10;// 8th tap comes from stage  1, which is bit 11
	unsigned short int g2_fb     =  (g2_tap_1 ^ g2_tap_2 ^       // Taps are modulo 2 added together (XORed), then feedback into stage 1, which is bit 11
			                         g2_tap_3 ^ g2_tap_4 ^
									 g2_tap_5 ^ g2_tap_8 ^
									 g2_tap_9 ^ g2_tap_11) << 10;  
		               *g2_reg   = (*g2_reg >> 1) | g2_fb;       // Shift the register 1 bit left then OR the feedback bit into the register
	return g2_out;
}


unsigned short int shift_glonass_g(unsigned short int* g_reg)
{
	// Shift the G register by 1 clock
	// G polynomial is 1 + x^5 + x^9, 9 bits

	unsigned short int g_out    =  *g_reg & 0x0001;            // Output  comes from stage 9, which is bit 1
	unsigned short int g_tap_9  = (*g_reg & 0x0001)      >> 0; // 1st tap comes from stage 9, which is bit 1
	unsigned short int g_tap_5  = (*g_reg & 0x0010)      >> 4; // 2nd tap comes from stage 5, which is bit 5
	unsigned short int g_fb     =  (g_tap_5 ^ g_tap_9)   << 8; // Taps are modulo 2 added together (XORed), then feedback into stage 1, which is bit 9
					  *g_reg    = (*g_reg >> 1) | g_fb;        // Shift the register 1 bit left then OR the feedback bit into the register
	return g_out;
}

void set_bit(unsigned char* code, unsigned short int pos, unsigned short int val)
{
	// Sets the bit at position in code to value

	unsigned short int byte = pos / 8;
	unsigned short int bit = 7 - pos % 8;
	code[byte] = (code[byte] & ~(1 << bit)) | (val << bit);
}

unsigned short int get_bit(unsigned char* code, unsigned short int pos)
{
	// Gets the bit at position in code

	unsigned short int val = 0;
	unsigned short int byte = pos / 8;
	unsigned short int bit = 7 - pos % 8;
	val = ((code[byte] >> bit) & 1);
	return val;
}

unsigned short int rev_reg(unsigned short int reg) {
   reg = (reg & 0xFF00) >> 8 | (reg & 0x00FF) << 8;
   reg = (reg & 0xF0F0) >> 4 | (reg & 0x0F0F) << 4;
   reg = (reg & 0xCCCC) >> 2 | (reg & 0x3333) << 2;
   reg = (reg & 0xAAAA) >> 1 | (reg & 0x5555) << 1;
   reg = reg >> 6;
   return reg;
}

void gen_gps_code(unsigned char* gi,
	unsigned short int g2_delay, // G2 code delay in chips, specific to a PRN number
	unsigned short int g2_init)  // G2 code initial register setting, sepecific to a PRN number
{
	//g2_init = rev_reg(g2_init);

	unsigned short int g1_reg = 01777;   // G1 shift register contents, 10 bits long
	                                     // G1 shift register intial setting,  always '11 1111 1111'
	unsigned short int g2_reg = g2_init; // G2 shift register contents, 10 bits long

	// Create space to store the G1, G2, and Gi codes
	unsigned char g1[128];
	unsigned char g2[128];
	memset(g1, 0, 128);
	memset(g2, 0, 128);
	memset(gi, 0, 128);

	// Generate the G1 and G2 chips
	for (unsigned short int i = 0; i < 1023; i++) // C/A PRN codes are 1023 bits long
	{
		set_bit(g1, i, shift_gps_g1(&g1_reg)); // Set the G1 code output bit
		set_bit(g2, i, shift_gps_g2(&g2_reg)); // Set the G2 code output bit
	}

	// Generate the Gi code
	for (unsigned short int i = 0; i < 1023; i++) // C/A PRN codes are 1023 bits long
	{
		unsigned short int g1_bit = get_bit(g1, i);                              // Get the G1 code output bit
		unsigned short int g2i_bit = get_bit(g2, (1023 - g2_delay + i) % 1023);  // Get the delayed G2i code output bit
		unsigned short int gi_bit = g1_bit ^ g2i_bit;                            // G1 and G1i are modulo 2 added together (XORed) to get Gi
		set_bit(gi, i, gi_bit); // Set the Gi code output bit
	}
}

void gen_bds_code(unsigned char* b1i,
	unsigned short int g2_phase_1, // G2 first tap phase, specific to a PRN number
	unsigned short int g2_phase_2) // G2 second tap phase, sepecific to a PRN number
{
	unsigned short int g1_reg = 01252;   // G1 shift register contents, 10 bits long
	unsigned short int g2_reg = 01252;   // G2 shift register contents, 10 bits long
	                                     // G1 & G2 shift register intial setting,  always '010 1010 1010'

	// Create space to store the B1I code
	memset(b1i, 0, 256);
	
	// Generate the B1I code
	for (unsigned short int i = 0; i < 2046; i++) // B1I PRN codes are 2046 bits long
	{
		unsigned short int g1_bit = g1_reg & 0x0001;                               // Get the G1 code output bit
		unsigned short int g2_bit_1 = (g2_reg >> (11 - g2_phase_1)) & 0x0001;      // Get the G2 code first tap bit
		unsigned short int g2_bit_2 = (g2_reg >> (11 - g2_phase_2)) & 0x0001;      // Get the G2 code second tap bit
		unsigned short int g2_bit   =  g2_bit_1 ^ g2_bit_2;                        // G2_1 and G2_2 are modulo 2 added together (XORed) to get G2
		unsigned short int b1i_bit  = g1_bit ^ g2_bit;                             // G1 and G2 are modulo 2 added together (XORed) to get B1I
		set_bit(b1i, i, b1i_bit);                                                  // Set the B1I code output bit
		shift_bds_g1(&g1_reg);                                                     // Shift the G1 code register
		shift_bds_g2(&g2_reg);                                                     // Shift the G2 code register
	}
}

void gen_glonass_code(unsigned char* g)
{
	unsigned short int g_reg = 0777;   // G shift register contents, 9 bits long
	                                   // G shift register intial setting,  always '1 1111 1111'

	// Create space to store the Gcode
	memset(g, 0, 64);

	// TODO: Must do 2 initial shifts to get the '1 1111 1100' first character mentioned in ICD?
	shift_glonass_g(&g_reg);
	shift_glonass_g(&g_reg);

	// Generate the G chips
	for (unsigned short int i = 0; i < 511; i++) // M code is 511 bits long
	{
		set_bit(g, i, shift_glonass_g(&g_reg)); // Set the G1 code output bit
	}
}

int main()
{
	FILE* src = NULL;	
	if (fopen_s(&src, "prns.c", "w") != 0)
	{
		char buf[256] = "";
		_strerror_s(buf, "Error opening prns.c");
		fprintf(stderr, buf);
		return 1;
	}

	// Program to generate GPS C/A PRN codes
	printf("Generating GPS C/A PRN codes...\n");

	fprintf(src, "static const u8 gps_ca_codes[210][128] = {\n");

#include "gps.h"
	
	printf("PRN\tG2 Delay\tG2 Setting\tCorrect Code\tGenerated Code\tCheck\n");
	
	unsigned char gps_ca[210][128]; // Create space to store the C/A codes
	for (unsigned char i = 0; i < 210; i++)
	{
		// Generate each C/A PRN code
		gen_gps_code(gps_ca[i], gps_prn[i][0], gps_prn[i][1]);

		unsigned short int code_start = (gps_ca[i][0] << 2) | gps_ca[i][1] >> 6;
		printf("%3hhu\t%8hu\t%10ho\t%12ho\t%14ho\t", i + 1, gps_prn[i][0], gps_prn[i][1], gps_prn[i][2], code_start);
		if (gps_prn[i][2] == code_start)
			printf("   OK\n");
		else
		{
			printf(" FAIL\n");
			//break;
		}

		for (unsigned char j = 0; j < 8; j++)
		{
			if (j == 0)
				fprintf(src, "  {");
			else
				fprintf(src, "   ");

			for (unsigned char k = 0; k < 16; k++)
			{
				unsigned char bits = gps_ca[i][16 * j + k];
				if ((16 * j + k) == 127)
					bits = bits & 0xFE;
				fprintf(src, "0x%02hhX", bits);
				if (k != 15)
					fprintf(src, ",");
			}

			if (j == 7)
				fprintf(src, "}");
			else
				fprintf(src, ",\n");
		}
		
		if (i == 210)
			fprintf(src, "\n");
		else
			fprintf(src, ",\n\n");
	}

	fprintf(src, "};\n\n");

	printf("Done.\n\n");

	// Program to generate BDS C/A B1I codes
	printf("Generating BDS C/A B1I codes...\n");

	fprintf(src, "static const u8 bds_b1i_codes[37][256] = {\n");

#include "bds.h"
	
	printf("PRN\tG2 Phase 1\tG2 Phase 2\tCorrect Code\tGenerated Code\tCheck\n");
	
	unsigned char bds_b1i[37][256]; // Create space to store the B1I codes
	for (unsigned char i = 0; i < 37; i++)
	{
		// Generate each B1I PRN code
		gen_bds_code(bds_b1i[i], bds_prn[i][0], bds_prn[i][1]);

		unsigned short int code_start = (bds_b1i[i][0] << 3) | bds_b1i[i][1] >> 5; // TODO: need check codes? fix
		printf("%3hhu\t%8hu\t%10hu\t%12ho\t%14ho\t", i + 1, bds_prn[i][0], bds_prn[i][1], 0, code_start);
		if (0 == code_start)
			printf("   OK\n");
		else
		{
			printf(" FAIL\n");
			//break;
		}

		for (unsigned char j = 0; j < 16; j++)
		{
			if (j == 0)
				fprintf(src, "  {");
			else
				fprintf(src, "   ");

			for (unsigned char k = 0; k < 16; k++)
			{
				unsigned char bits = bds_b1i[i][16 * j + k];
				if ((16 * j + k) == 255)
					bits = bits & 0xFC;
				fprintf(src, "0x%02hhX", bits);
				if (k != 15)
					fprintf(src, ",");
			}

			if (j == 15)
				fprintf(src, "}");
			else
				fprintf(src, ",\n");
		}
		
		if (i == 37)
			fprintf(src, "\n");
		else
			fprintf(src, ",\n\n");
	}

	fprintf(src, "};\n\n");

	printf("Done.\n\n");

	// Program to generate GLONASS M ranging code
	printf("Generating GLONASS M ranging code...\n");

	fprintf(src, "static const u8 m_code[64] = \n");
	
	unsigned int m_code_start = 0774; // First 9 bits of M code are '1 1111 1100'

	printf("Correct Code\tGenerated Code\tCheck\n");
	
	unsigned char m[64]; // Create space to store the M code

	// Generate M code
	gen_glonass_code(m);

	unsigned short int code_start = (m[0] << 1) | m[1] >> 7;
	printf("%12ho\t%14ho\t", m_code_start, code_start);
	if (m_code_start == code_start)
		printf("   OK\n");
	else
	{
		printf(" FAIL\n");
	}

	for (unsigned char j = 0; j < 4; j++)
	{
		if (j == 0)
			fprintf(src, "  {");
		else
			fprintf(src, "   ");

		for (unsigned char k = 0; k < 16; k++)
		{
			unsigned char bits = m[16 * j + k];
			if ((16 * j + k) == 63)
				bits = bits & 0xFE;
			fprintf(src, "0x%02hhX", bits);
			if (k != 15)
				fprintf(src, ",");
		}

		if (j == 3)
			fprintf(src, "};\n\n");
		else
			fprintf(src, ",\n");
	}

	printf("Done.\n\n");
	
	// Program to generate Galileo E1B memory code
	printf("Generating Galileo E1B memory code...\n");

	fprintf(src, "static const u8 gal_e1b_codes[50][512] = {\n");

	// Filename that contains the hex codes
	const char e1b_fn[] = "galileo_e1b.txt";

	FILE* e1b = NULL;	
	if (fopen_s(&e1b, e1b_fn, "r") != 0)
	{
		char buf[256] = "";
		_strerror_s(buf, "Error opening E1B");
		fprintf(stderr, buf);
		return 1;
	}
	
	unsigned char gal_e1b[50][512]; // Create space to store the E1B codes
	for (unsigned char i = 0; i < 50; i++)
	{
		// TODO: move into a func like the orthers
		memset(gal_e1b[i], 0, 512); // Clear the memory

		// 1 title line
		// 13 full lines
		// 1 partial line
		// empty line

		for (unsigned char j = 0; j < 32; j++)
		{
			if (j == 0)
				fprintf(src, "  {");
			else
				fprintf(src, "   ");

			for (unsigned char k = 0; k < 16; k++)
			{
				unsigned char bits = gal_e1b[i][16 * j + k];
				if ((16 * j + k) == 511)
					bits = bits & 0xF0;
				fprintf(src, "0x%02hhX", bits);
				if (k != 15)
					fprintf(src, ",");
			}

			if (j == 31)
				fprintf(src, "}");
			else
				fprintf(src, ",\n");
		}
		
		if (i == 50)
			fprintf(src, "\n");
		else
			fprintf(src, ",\n\n");
	}

	fclose(e1b);

	fprintf(src, "};\n\n");
	
	printf("Done.\n\n");

	fclose(src);

	// TODO: split each system into seperate source and output files
	// TODO: integrate into libswiftnav build process - build self using gcc then run in src to spit out generated files - in folder gen? then include in arm build

	return 0;
}