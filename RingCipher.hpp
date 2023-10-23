#ifndef RINGCIPHER_H
#define RINGCIPHER_H

#include <string>

class RingCipher
{
private:
    const string Alphabet = {"abcYZuvwxyzABC.'hijk-_=+*TUVWX$#@~`!?,^%defgt0123456789Dplmno\"\\;<>|qrsEFGHIJKLMNOPQRS"};
    const int Key1{14};
    const int Key2{13};
    int NewKey{Key2};

    string Encrypt(const string &Message)
    {
        string Output{};
        string Output1{};
        string Output2{};

        // Layer 1
        for (auto &x : Message)
        {
            // Guarding for escape sequences
            if (x == ' ' || x == '\t')
            {
                continue;
            }

            Output1 += Alphabet[((Alphabet.find(x) + Key1) < Alphabet.length()) ? (Alphabet.find(x) + Key1) : ((Alphabet.find(x) + Key1) - Alphabet.length())];
        }

        // Layer 2
        for (auto &x : Output1)
        {
            Output2 += Alphabet[(((Alphabet.find(x) ^ Key2) < Alphabet.length()) ? ((Alphabet.find(x) ^ Key2)) : (Alphabet.find(x)))];
        }

        // Layer 3
        for (auto &x : Output2)
        {
            Output += Alphabet[((Alphabet.find(x) ^ NewKey) < Alphabet.length()) ? (Alphabet.find(x) ^ NewKey) : (Alphabet.find(x))];
            NewKey = (Alphabet.find(x));
        }

        return Output;
    }

    string Decrypt(const string &Message)
    {
        string Output{};
        string Output1{};
        string Output2{};

        // Layer 3
        for (auto &x : Message)
        {
            // Guarding for escape sequences
            if (x == ' ' || x == '\t')
            {
                continue;
            }

            Output1 += Alphabet[((Alphabet.find(x) ^ NewKey) < Alphabet.length()) ? (Alphabet.find(x) ^ NewKey) : (Alphabet.find(x))];
            NewKey = ((Alphabet.find(x) ^ NewKey) < Alphabet.length()) ? (Alphabet.find(x) ^ NewKey) : (Alphabet.find(x));
        }

        // Layer 2
        for (auto &x : Output1)
        {
            Output2 += Alphabet[(((Alphabet.find(x) ^ Key2) < Alphabet.length()) ? ((Alphabet.find(x) ^ Key2)) : (Alphabet.find(x)))];
        }

        // Layer 1
        for (auto &x : Output2)
        {
            Output += Alphabet[((Alphabet.find(x) - Key1 + Alphabet.length()) < Alphabet.length()) ? ((Alphabet.find(x) - Key1) + Alphabet.length()) : (Alphabet.find(x) - Key1)];
        }
        return Output;
    }

public:
    string Run(const string &Message)
    {
        string Output{""};

        switch (Message[Message.length() - 1])
        {

        case '~':
            Output = Encrypt(Message.substr(0, Message.length() - 1));
            break;
        case '`':
            Output = Decrypt(Message.substr(0, Message.length() - 1));
            break;
        default:
            return Message;
        }

        return Output;
    }
};

#endif