#ifndef RINGCIPHER_H
#define RINGCIPHER_H

#include <string>

class RingCipher
{
private:
    const string Alphabet = {"abcYZuvwxyzABC.'hijk-_=+*TUVWX$#@~`!?,^%defgt0123456789Dplmno\"\\;<>|qrsEFGHIJKLMNOPQRS"};
    const int Key2{13};
    const int Key1{14};

    string Encode(const string &Message)
    {
        string Output1{};
        string Output{};

        // Level 1
        for (auto &x : Message)
        {
            // Guarding for escape sequences
            if (x == ' ' || x == '\t')
            {
                continue;
            }
            Output1 += Alphabet[((Alphabet.find(x) + Key1) < Alphabet.length()) ? (Alphabet.find(x) + Key1) : ((Alphabet.find(x) + Key1) - Alphabet.length())];
        }

        // Level 2
        for (auto &x : Output1)
        {

            Output += Alphabet[(((Alphabet.find(x) ^ Key2) < Alphabet.length()) ? ((Alphabet.find(x) ^ Key2)) : (Alphabet.find(x)))];
        }
        return Output;
    }

    string Decode(const string &Message)
    {
        string Output1{};
        string Output{};

        // Level 2
        for (auto &x : Message)
        {
            // Guarding for escape sequences
            if (x == ' ' || x == '\t')
            {
                continue;
            }

            Output1 += Alphabet[(((Alphabet.find(x) ^ Key2) < Alphabet.length()) ? ((Alphabet.find(x) ^ Key2)) : (Alphabet.find(x)))];
        }

        // Level 1
        for (auto &x : Output1)
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
            Output = Encode(Message.substr(0, Message.length() - 1));
            break;
        case '`':
            Output = Decode(Message.substr(0, Message.length() - 1));
            break;
        default:
            return Message;
        }

        return Output;
    }
};

#endif