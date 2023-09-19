def key_scheduling(key):
    S = list(range(256))

    j = 0
    for i in range(256):
        j = (j + S[i] + ord(key[i % len(key)])) % 256
        S[i], S[j] = S[j], S[i]
    
    return S

def psuedo_random(S, plaintext):
    i = j =  0
    stream = []

    for char in range(len(plaintext)):
        i = (i + 1) % 256
        j = (j + S[i]) % 256
        S[i], S[j] = S[j], S[i]
        key = S[(S[i] + S[j]) % 256]
        stream.append(key)
    
    return stream

def encrypt(stream, plaintext):
    ciphertext = []

    for i in range(len(plaintext)):
        ciphertext.append(ord(plaintext[i]) ^ stream[i])

    return bytes(ciphertext)

def decrypt(stream, ciphertext):
    decryptedstream = []

    for i in range(len(ciphertext)):
        decryptedstream.append(ciphertext[i] ^ stream[i])

    decryptedtext = ""
    for i in decryptedstream:
        decryptedtext = decryptedtext + chr(i)

    return decryptedtext

def main():
    plaintext = "THAT IS BLOODY LOVELY"
    key = "63727970746969"

    print(f"Plaintext: {plaintext}")

    S = key_scheduling(key)
    stream = psuedo_random(S, plaintext)

    ciphertext = encrypt(stream, plaintext)
    print(f"Ciphertext: {ciphertext}")

    decryptedtext = decrypt(stream, list(ciphertext))
    print(f"Decrypted text: {decryptedtext}")

if __name__ == "__main__":
    main()
