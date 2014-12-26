//use below cmd to compile
//gcc aes_test.c -o aes_test -lcrypto

#include <openssl/aes.h>
#include <openssl/evp.h>
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/rand.h>
#include <assert.h>
#include <openssl/err.h>

#define BIG_TEST_SIZE 10240

static void hexdump(FILE *f,const char *title,const unsigned char *s,int l)
{
    int n=0;

    fprintf(f,"%s",title);
    for( ; n < l ; ++n)
    {
        if((n%16) == 0)
            fprintf(f,"\n%04x",n);
        fprintf(f," %02x",s[n]);
    }
    fprintf(f,"\n");
}

int main(int argc, char* argv[])
{
    const KEYSIZE=AES_BLOCK_SIZE;
    char rkey[KEYSIZE+1];
    char rkey2[KEYSIZE+1];
    AES_KEY key;
    char plaintext[BIG_TEST_SIZE];
    char ciphertext[BIG_TEST_SIZE];
    char checktext[BIG_TEST_SIZE];
    char iv[AES_BLOCK_SIZE*4];
    char saved_iv[AES_BLOCK_SIZE*4];
    int err = 0;
    int n;

    RAND_pseudo_bytes((unsigned char*)rkey, sizeof rkey);
    strcpy(iv,"0123456789012345");


    memcpy(saved_iv, iv, sizeof saved_iv);

    strcpy((char*)plaintext,"string to make the random number generator think it has entropy");

    // Straight encrypt

    AES_set_encrypt_key((unsigned char*)rkey, 8*KEYSIZE, &key);
    hexdump(stdout, "plaintext", (unsigned char*)plaintext, strlen(plaintext));
    printf("iv:%s\n", iv);

    AES_cbc_encrypt((unsigned char*)plaintext, (unsigned char*)ciphertext, strlen(plaintext), &key, (unsigned char*)iv,AES_ENCRYPT);
    hexdump(stdout, "ciphertext", (unsigned char*)ciphertext, strlen(plaintext));
    printf("iv:%s\n", iv);


    // Straight decrypt

    AES_set_decrypt_key((unsigned char*)rkey, 8*KEYSIZE, &key);
    memcpy(iv, saved_iv, sizeof iv);
    AES_cbc_encrypt((unsigned char*)ciphertext, (unsigned char*)checktext, strlen(plaintext), &key, (unsigned char*)iv,AES_DECRYPT);
    hexdump(stdout, "checktext", (unsigned char*)checktext, strlen(plaintext));
    printf("iv:%s\n", iv);

    return 0;
}
