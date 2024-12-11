# RingCipher
 A rather simplistic symmetric encryption library that combines substitution and XOR operations with a dynamic feedback mechanism. It features:

- Multi-layered Encryption: It uses three distinct layers of transformation, including rotational substitution, XOR-based manipulation, and a stateful dynamic key update.
- Custom Character Set (A non-standard alphabet ensures flexibility and obfuscation beyond traditional ASCII encryption that can also be varied by the users).
- Bidirectional Operation
- Dynamic Keying

To operate:
When passing a string to the Run() method either append '~' at its end for encryption or '`' for decryption.

Encryption/decryption complexity can be varied by adjusting Key1, Key2 or Alphabet variables. Do NOT add duplicate characters inside Alphabet or it can lead to unintended behavior. Also, Key values should not exceed Alphabet.length()/2 or complexity will be critically diminished.
