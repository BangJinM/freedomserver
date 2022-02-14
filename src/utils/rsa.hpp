#pragma once

#include <cryptopp/rsa.h>
#include <string>

class RSA
{
public:
	RSA() = default;

	RSA(const RSA &) = delete;
	RSA &operator=(const RSA &) = delete;

	void loadPEM(const std::string &filename);
	void decrypt(char *msg) const;

private:
	CryptoPP::RSA::PrivateKey pk;
};
