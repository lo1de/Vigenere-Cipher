#include<iostream>

using namespace std;

string vigenere_encrypt(const string& plaintext, const string& key)
{
	string ciphertext;
	ciphertext.resize(plaintext.length());
	for (int i = 0; i < plaintext.length(); ++i) {
			ciphertext[i] = ((plaintext[i] - 'a') + (key[i % key.length()] - 'a')) % 26;
			ciphertext[i] += 'a';
	}

	return ciphertext;
}

string vigenere_decrypt(const string& ciphertext, const string& key)
{
	string decrypted;
	decrypted.resize(ciphertext.length());
	for (int i = 0; i < ciphertext.length(); ++i)
	{
		decrypted[i] = ((ciphertext[i] - 'a') - (key[i % key.length()] - 'a')) % 26;
		decrypted[i] += 'a';
	}

	return decrypted;
}

int main()
{
	string text, key;

	cout << "Enter your text" << endl;
	cin >> text;

	cout << "Enter your key" << endl;
	cin >> key;

	for (auto& symbol : text) {
		if (isupper(symbol)) symbol += 32;
	}
	
	text.erase(std::remove_if(text.begin(), text.end(),
		[](unsigned char x) {return std::isdigit(x); }),
		text.end());

	string ciphertext = vigenere_encrypt(text, key);
	cout << "Ciphertext:" << endl;
	cout << ciphertext << endl << endl;

	cout << "Encrypted:" << endl;
	cout << vigenere_decrypt(ciphertext,key) << endl << endl;
	

	return 0;
}