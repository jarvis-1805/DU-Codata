#include<iostream>
#include<cstring>
#include<cstdlib>
#include "protocol.hpp"

using namespace std;

class stopNwait
{
	protocol pr;
	
    public:
        string buf;
		
        bool flag;
		bool divData;
		
        int count;
        int lim;
		
        eventType event;

        stopNwait(string temp)
        {
            buf = temp;
            flag = false;
            divData = false;
            count = 0;
            lim = 1e6;
        }
		
        void sender();
        void receiver();
};

void stopNwait::sender()
{
	if(!divData)
	{
		lim = buf.length() % MAX_PKT == 0 ? buf.length() / MAX_PKT : buf.length() / MAX_PKT + 1;
		
		cout << "\nDividing data into groups of " << MAX_PKT << "-bit each";
		divData = true;
	}

    cout << "\n\nSender\n=======";
    if(count > 0)
    {
        if(count%2 == 0)
        {
            cout << "\nTimeout Expired!!!";
            flag = true;
        }
        else
        {
            cout << "\nReceived Control Frame [<kind: '" << pr.show_kind(pr.receiverFrame.kind) << "'><ack:'" << pr.receiverFrame.ack << "'>]";
            if(flag)
            {
                count--;
                flag = false;
            }
        }
        if(pr.receiverFrame.kind == nak || flag)
        {
            cout << "\nResending the previous frame...";
            count--;
            flag = true;
        }
    }
    
    while(count < lim)
    {
        do
        {
            if(!flag)
            {
                cout << "\nEncapsulating data D" << count+1 << " in a packet...";
                for(int i=0; i<MAX_PKT; i++)
                    pr.dataPacket.data[i] = buf[i + count * MAX_PKT];
                cout << "\nPassing Packet to Data Link Layer...'" << pr.dataPacket.data << "'";
                event = frameArrival;
            }
            if(pr.wait_for_event(event))
            {
                if(!flag)
                    pr.from_network_layer(pr.dataPacket);
                pr.to_physical_layer(pr.senderFrame);
                event = wait;
            }
            receiver();
        }while(event != wait);
    }

    if(count == lim)
    {
        cout << "\nData ['" << buf << "'] sent successfully...";
        exit(0);
    }
}

void stopNwait::receiver()
{
    cout << "\n\nReceiver\n========";
    if(event == wait)
    {
        pr.from_physical_layer(pr.senderFrame);
        if(!flag)
        {
            pr.to_network_layer(pr.dataPacket);
            count++;
        }
        else
            count += 2;
        pr.to_physical_layer(pr.receiverFrame);
        event = frameArrival;
        sender();
    }
}

int main()
{
	cout << "\n========== STOP AND WAIT ==========\n";
    char temp[100];
    cout << "\nEnter the data: ";
    cin >> temp;
    
    stopNwait *ob = new stopNwait(string(temp));
    ob->sender();
	
    return 0;
}