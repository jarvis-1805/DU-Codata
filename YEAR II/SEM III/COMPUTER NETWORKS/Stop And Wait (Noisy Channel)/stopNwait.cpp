#include<cstring>
#include <cstdlib>
#include "protocol.hpp"

class stopNwait : public protocol
{
    public:
        string buf;
        bool flag, divData;
        int count;
        int lim;
        eventType event;

        stopNwait(string temp)
        {
            buf = temp;
            flag = false;
            divData = false;
            count = 0;
            lim = 1e4;
        }

        void sender();
        void receiver();
};

void stopNwait::sender()
{
    if(!divData)
    {
        lim = buf.length() % MAX_PKT == 0 ? buf.length() / MAX_PKT : buf.length() / MAX_PKT + 1;
        
        printf("\nDividing data into groups of %i-bit each", MAX_PKT);
        divData = true;
    }
    
    printf("\n\nSender\n=======");
    if(count > 0)
    {
        if(count%2 == 0)
        {
            printf("\nTimeout Expired!!!");
            flag = true;
        }
        else
        {
            printf("\nReceived ControlFrame [<kind: '%s'><ack:'%i'>]", show_kind(receiverFrame.kind).c_str(), receiverFrame.ack);
            if(flag)
            {
                count--;
                flag = false;
            }
        }
        if(receiverFrame.kind == nak || flag)
        {
            printf("\nResending the previous frame...");
            count--;
            flag = true;
        }
    }
    
    while(count < lim)
    {
        while(event != wait)
        {
            if(!flag)
            {
                printf("\nEncapsulating data D%i in a packet...", count+1);
                for(int i=0; i<MAX_PKT; i++)
                    dataPacket.data[i] = buf[i + count * MAX_PKT];
                printf("\nPassing Packet to Data Link Layer...");
                event = frameArrival;
            }
            if(wait_for_event(event))
            {
                if(!flag)
                    from_network_layer(dataPacket);
                to_physical_layer(senderFrame);
                event = wait;
            }
            receiver();
        }
    }

    if(count == lim)
    {
        printf("\nData [%s] sent successfully...", buf.c_str());
        exit(0);
    }
}

void stopNwait::receiver()
{
    printf("\n\nReceiver\n========");
    if(event == wait)
    {
        from_physical_layer(senderFrame);
        if(flag == 0)
        {
            to_network_layer(dataPacket);
            count++;
        }
        else
            count += 2;
        to_physical_layer(receiverFrame);
        event = frameArrival;
        sender();
    }
}

int main()
{
    char temp[100];
    printf("\nEnter the data: ");
    scanf("%s", temp);
    
    stopNwait *ob = new stopNwait(string(temp));
    ob->sender();

    return 0;
}