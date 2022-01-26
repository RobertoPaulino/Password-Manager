

class encdec {

public:
    char encrypt(int key, char value);
    char decrypt(int key, char value);
};


char encdec::encrypt(int key, char value)
{
    char encryption = key + value;
    return encryption;
}


char encdec::decrypt(int key, char value)
{
    char decryption = key - value;
    return decryption;
}