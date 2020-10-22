#include<iostream>
#include<string>
#include<cstdio>
#define MAX_PKT 4

using namespace std;

typedef enum
{
    dat,
    ack,
    nak
}frameKind;

typedef enum
{
    wait,
    frameArrival
}eventType;

typedef struct
{
    unsigned char data[MAX_PKT];
}packet;

typedef struct
{
    unsigned int seq;
    unsigned int ack;
    frameKind kind;
    packet *info;
}frame;

class protocol
{
    public:
        int seqSent;
        int seqReceived;

        packet dataPacket;

        frame senderFrame;
        frame receiverFrame;

        protocol()
        {
            seqReceived = seqSent = -1;
        }

        int wait_for_event(eventType);
        string show_kind(frameKind);
        void from_network_layer(packet &);
        void to_physical_layer(frame &);
        void from_physical_layer(frame &);
        void to_network_layer(packet &);
};

int protocol::wait_for_event(eventType e)
{
    return e == frameArrival;
}

string protocol::show_kind(frameKind fk)
{
    switch(fk)
    {
        case dat:
            return "data";
            break;
        case ack:
            return "ack";
            break;
        case nak:
            return "nak";
            break;
        default:
            return "";
    }
}

void protocol::from_network_layer(packet &p)
{
    cout << "\nEncapsulating Packet [data: '" << p.data << "']...";
    senderFrame.seq = ++seqSent;
    senderFrame.kind = dat;
    senderFrame.info = &p;
}

void protocol::to_physical_layer(frame &f)
{
    if(f.kind == dat)
        cout << "\nSending DataFrame [<kind: " << show_kind(f.kind) << "><sequence: " << f.seq << ">] to Physical Layer...";
    else
        cout << "\nSending ControlFrame [<kind: " << show_kind(f.kind) << "><ack: " << f.ack << ">] to Physical Layer...";
}

void protocol::from_physical_layer(frame &f)
{
    cout << "\nReceived DataFrame [<kind: " << show_kind(f.kind) << "><sequence: " << f.seq << ">] from Physical Layer...";
    cout << "\nVerifying Sequence Number...";
    if(seqReceived != f.seq)
        cout << "\nDecapsulating DataFrame...";
    else
    {
        cout << "\nDuplicate Frame Detected...";
        cout << "\nDiscarding Frame...";
    }
}

void protocol::to_network_layer(packet &p)
{
    cout << "\nSending Packect [<data: '" << p.data << "'>] to Network Layer...";
    seqReceived = senderFrame.seq;
    receiverFrame.seq = 0;
    receiverFrame.kind = ack;
    receiverFrame.ack = senderFrame.seq + 1;
}