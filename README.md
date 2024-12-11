# RingCipher
Small personal project for symmetric multi-layer (3) encryption/decryption algorithm implementation, while also featuring variable stream cipher encryption.

When passing a string to the Run() method either append '~' at its end for encryption or '`' for decryption.

Encryption/decryption complexity can be varied by adjusting Key1, Key2 or Alphabet variables. Do NOT add duplicate characters inside Alphabet or it can lead to unintended behavior. Also Key values should not exceed Alphabet.length()/2 or complexity will be reduced.
