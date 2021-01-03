#include <iostream>
#include <cmath>

#ifndef MARMOSET_TESTING
int main();
#endif

char* encode(char *plaintext, unsigned long key);
char* decode(char *ciphertext, unsigned long key);

char* encode(char *plaintext, unsigned long key) {

	unsigned char dataset_s[256];
	unsigned char R;
	unsigned int r;
	unsigned long bit_wise { 0 };
	unsigned int i { 0 }, j { 0 }, temp;
	long k;

	for (unsigned int g = 0; g < 256; g++) {
		dataset_s[g] = g;
	}
	for (unsigned int x = 0; x < 256; x++) {

		k = i % 64; //Step a

		bit_wise = (1L << k) & key; 				// set bitwise only to k shifted left by one-bit and key
		bit_wise >>= k; 							// set bit_wise to itself shifted by one-bit to the right
		j = (j + dataset_s[i] + bit_wise) % 256;    // step b

		temp = dataset_s[i];             //Set new int a to data_s[i]
		dataset_s[i] = dataset_s[j]; //Set i equal to j
		dataset_s[j] = temp;            //Set j equal to a

		i = (i + 1) % 256;
	}

	unsigned int counter { 0 };
	//unsigned int counter5 {0};
	while (plaintext[counter] != '\0') {
		counter++;
	}
	int old_count = counter; // excludes the added null characters

	unsigned int remainder{0};
	unsigned int byte_number { 0 };

	while (counter % 4 != 0) {
		counter++;
		//counter5++;
	}

	counter += 1;
	unsigned int size { counter };
	//std::cout << "Size" << size << std::endl;
	unsigned char *text = new unsigned char[size]();
	text[size-1] = '\0';


	for (int f = 0; f < old_count; ++f) {
		text[f] = plaintext[f];
		//std::cout << text[f] << std::endl;
	}


	unsigned int tempo { (5 * (size / 4)) + 1 };
	char *ciphertext = new char[tempo];

	//Armour
	for (unsigned int q { 0 }; q < size - 1; ++q) {
		i = (i + 1) % 256;
		j = (j + dataset_s[i]) % 256;

		temp = dataset_s[i];             //Set new int a to data_s[i]
		dataset_s[i] = dataset_s[j]; //Set i equal to j
		dataset_s[j] = temp;            //Set j equal to a

		r = (dataset_s[i] + dataset_s[j]) % 256;
		R = dataset_s[r];
		text[q] = text[q] ^ R;
		//std::cout << (int)text[q] << std::endl;
	}

	for (unsigned int e { 0 }; e < size / 4; e++) {

		byte_number = ((text[(e * 4)] << 24) + (text[(e * 4) + 1] << 16)
				+ (text[(e * 4) + 2] << 8) + (text[(e * 4) + 3]));

		for (unsigned int i = 0; i < 5; i++) {          // why doesn't --i work?
			remainder = byte_number % 85;
			ciphertext[(e * 5) + (4 - i)] = remainder + 33;
			byte_number /= 85;
		}
	}

	ciphertext[tempo-1] = '\0';
	return ciphertext;
}

char* decode(char *ciphertext, unsigned long key) {

	unsigned char dataset_s[256];
	unsigned int R{0};
	unsigned int r{0};
	unsigned long bit_wise { 0 };
	unsigned int i { 0 }, j { 0 }, temp;
	long k;

	unsigned int counter{0};

	for(counter; ciphertext[counter] != '\0'; counter++){}

	unsigned int size{0};
	size = 4*(counter/5)+1;

	unsigned long reverse{0};
	char *plaintext = new char[size];
	std::size_t counter2 = 0;

	//converting from ciphertext to plaintext

	for (unsigned long f{0}; f < counter; f+=5) {

		reverse = ((ciphertext[f] -'!') * pow(85, 4) + (ciphertext[f+1] -'!') * pow(85, 3) + (ciphertext[f + 2] -'!') * pow(85, 2) + (ciphertext[f+3] -'!') * pow(85, 1) + (ciphertext[f+4] -'!') * pow(85, 0));

		plaintext[f-counter2] = (reverse >> 24);
		plaintext[f+1-counter2] = ((reverse >> 16) << 24) >> 24;
		plaintext[f+2-counter2] = ((reverse >> 8) << 24) >> 24;   //I said plaintext was one char tried to excess it with one char
		plaintext[f+3-counter2] = (reverse << 24) >> 24;

		counter2++;
	}

	for (unsigned int g = 0; g < 256; g++) {
			dataset_s[g] = g;
		}
		for (unsigned int x = 0; x < 256; ++x) {

			k = i % 64; //Step a

			bit_wise = (1L << k) & key; 				// set bitwise only to k shifted left by one-bit and key
			bit_wise >>= k; 							// set bit_wise to itself shifted by one-bit to the right
			j = (j + dataset_s[i] + bit_wise) % 256;    // step b

			temp = dataset_s[i];             //Set new int a to data_s[i]
			dataset_s[i] = dataset_s[j];     //Set i equal to j
			dataset_s[j] = temp;             //Set j equal to a

			i = (i + 1) % 256;
		}


	for (unsigned int q {0}; q < size; ++q) {
			i = (i + 1) % 256;
			j = (j + dataset_s[i]) % 256;

			temp = dataset_s[i];             //Set new int a to data_s[i]
			dataset_s[i] = dataset_s[j];     //Set i equal to j
			dataset_s[j] = temp;             //Set j equal to a

			r = (dataset_s[i] + dataset_s[j]) % 256;
			R = dataset_s[r];
			plaintext[q] = plaintext[q] ^ R;
		}

	plaintext[size-1] = '\0';
	return plaintext;
}

#ifndef MARMOSET_TESTING
int main() {

	char a[]{ "study" };
	char b[] { "A Elbereth Gilthoniel silivren penna miriel o menel aglar elenath! Na-chaered palan-diriel o galadhremmin ennorath, Fanuilos, le linnathon nef aear, si nef aearon!" };

	std::cout << "\"" << a << "\"" << std::endl;

	char *ciphertext{ encode( a, 3408 ) };

	std::cout << "\"" << ciphertext << "\"" << std::endl;

	char *plaintext{ decode (ciphertext, 3408) };

	std::cout << "\"" << plaintext << "\"" << std::endl;

	delete[] plaintext;
	plaintext = nullptr;
	delete[] ciphertext;
	ciphertext = nullptr;

	std::cout << "\"" << b << "\"" << std::endl;

	ciphertext = encode( b, 3408 );

	std::cout << "\"" << ciphertext << "\"" << std::endl;

	plaintext = decode (ciphertext, 3408);

	std::cout << "\"" << plaintext << "\"" << std::endl;

	delete[] plaintext;
	plaintext = nullptr;
	delete[] ciphertext;
	ciphertext = nullptr;

	return 0;
}
#endif
