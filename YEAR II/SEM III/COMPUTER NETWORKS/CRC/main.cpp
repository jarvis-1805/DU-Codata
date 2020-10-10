#include<iostream>
#define MAX 100

using namespace std;

class CRC
{
    protected:
        int messageSize, generatorSize;
        int message[MAX], generator[MAX], codeword[MAX];
        int crc[MAX], rem[MAX], temp[MAX], temp1[MAX];

    public:
        CRC();
        void crc_calc();
        void generate_codeword();
        void sender();
        void noisy_channel();
        void receiver();
};

CRC::CRC()
{
    cout << "\nEnter Message Size: ";
    cin >> messageSize;
    cout << "Enter Message: ";
    for(int i=0; i<messageSize; i++)
        cin >> message[i];
    
    cout << "\nEnter Generator Size: ";
    cin >> generatorSize;
    cout << "Enter Generator: ";
    for(int i=0; i<generatorSize; i++)
        cin >> generator[i];
}

void CRC::generate_codeword()
{
    for(int i=0; i<messageSize; i++)
        codeword[i] = message[i];
    
    for(int i=messageSize; i<(messageSize+generatorSize-1); i++)
        codeword[i] = 0;
}

void CRC::crc_calc()
{
    for(int i=0; i<(messageSize+generatorSize-1); i++)
        temp[i] = codeword[i];
    
    for(int i=0; i<messageSize; i++)
    {
        int j = 0, k = i;
        if(temp[i] >= generator[j])
            for(j=0; j<generatorSize; j++)
            {
                temp[k] = temp[k] ^ generator[j];
                k++;
            }
    }

    for(int i=0, j=messageSize; i<generatorSize-1 && j<(messageSize+generatorSize-1); i++, j++)
    {
        crc[i] = temp[j];
    }
}

void CRC::sender()
{
    cout << "Message: ";
    for(int i=0; i<messageSize; i++)
        cout << message[i] << " ";
    
    cout << "\nGenerator: ";
    for(int i=0; i<generatorSize; i++)
        cout << generator[i] << " ";
    
    generate_codeword();

    cout << "\nCRC: ";
    crc_calc();
    for(int i=0; i<generatorSize-1; i++)
        cout << crc[i] << " ";
    
    cout << "\nTransmitted Codeword: ";
    for(int i=messageSize, j=0; i<(messageSize+generatorSize-1), j<generatorSize-1; i++, j++)
        codeword[i] = crc[j];
    for(int i=0; i<(messageSize+generatorSize-1); i++)
        cout << codeword[i] << " ";
}

void CRC::noisy_channel()
{
    int nBits, pos;
    cout << "Enter number of Bits to Flip: ";
    cin >> nBits;
    if(nBits == -1 || nBits > (messageSize+generatorSize-1))
        cout << "\nInvalid Request! Codeword not changed.";
    else
        for(int i=0; i<nBits; i++)
        {
            cout << "Enter Bit position to Flip: ";
            cin >> pos;
            codeword[pos-1] ? codeword[pos-1] = 0 : codeword[pos-1] = 1;
        }
}

void CRC::receiver()
{
    cout << "Received Codeword: ";
    for(int i=0; i<(messageSize+generatorSize-1); i++)
        cout << codeword[i] << " ";
}

int main()
{
    cout << "\n============= CRC =============\n";
    CRC ob;
    cout << "\nSENDER\n======\n";
    ob.sender();
    cout << "\n\nNOISY CHANNEL SIMULATION\n========================\n";
    ob.noisy_channel();
    cout << "\nRECEIVER\n========\n";
    ob.receiver();
}