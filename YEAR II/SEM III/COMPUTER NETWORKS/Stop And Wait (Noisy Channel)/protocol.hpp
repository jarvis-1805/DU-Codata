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
    printf("\nEncapsulating Packet [data='%s']...", p.data);
    senderFrame.seq = ++seqSent;
    senderFrame.kind = dat;
    senderFrame.info = &p;
}

void protocol::to_physical_layer(frame &f)
{
    if(f.kind == dat)
        printf("\nSending DataFrame [<kind: %s><sequence: %i>]...", show_kind(f.kind).c_str(), f.seq);
    else
        printf("\nSending ControlFrame [<kind: %s><ack: %i>] to Physical Layer...", show_kind(f.kind).c_str(), f.ack);
}

void protocol::from_physical_layer(frame &f)
{
    printf("\nReceived DataFrame [<kind: %s><sequence: %i>] from Physical Layer...", show_kind(f.kind).c_str(), f.seq);
    printf("\nVerifying Sequence Number...");
    if(seqReceived == f.seq)
        printf("\nDecapsulating DataFrame...");
    else
    {
        printf("\nDuplicate Frame Detected...");
        printf("\nDiscarding Frame...");
    }
}

void protocol::to_network_layer(packet &p)
{
    printf("\nSending Packect [<Data: %s>] to Network Layer...", p.data);
    seqReceived = senderFrame.seq;
    receiverFrame.seq = 0;
    receiverFrame.kind = ack;
    receiverFrame.ack = senderFrame.seq + 1;
}