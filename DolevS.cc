//
// This assignment is designed as a part of a take-home exercise for the C-3 workshop
// Author : Nitin Awathare

#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <fstream>


using namespace std;
using namespace omnetpp;


#include "DolevStrong_m.h"


int f;
vector<int> systemAcceptedValue;
int n;
ofstream outputfile;


class DolevS : public cSimpleModule
{
  protected:
    vector<int> acceptedValue;

    virtual DolevStrongMsg *generateMessage(int value, int type);
    virtual void forwardMessage(DolevStrongMsg *msg);
    virtual bool convincedOfValue(DolevStrongMsg *msg);
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
    virtual void byzantineLeader();
    virtual void byzantineNonLeader(DolevStrongMsg *msg);


};

Define_Module(DolevS);

void DolevS::byzantineNonLeader(DolevStrongMsg *ttmsg){
    const char * gateName = "out";
    cGate *destGate = NULL;
    int i = 0;
    int gateSize = gate(gateName, 0)->size();

    if(getIndex()!=0 && getIndex() == f-1){
        do {
                destGate = gate(gateName, i++);
                cGate *nextGate = destGate->getNextGate();
                if (nextGate ) {
                    // cout<<"sento to ******* "<<nextGate->getOwnerModule()->getIndex()<<endl;
                    if((nextGate->getOwnerModule()->getIndex()%2==ttmsg->getMessageType())&&(nextGate->getOwnerModule()->getIndex()>=f)){
                        cout<<"sento to ******* "<<nextGate->getOwnerModule()->getIndex()<<endl;

                        ttmsg->setRound(ttmsg->getRound()+1);
                        ttmsg->setSignCount(ttmsg->getSignCount()+1);
                        ttmsg->insertSignature(ttmsg->getSignCount()-1,getIndex());
                        send(ttmsg->dup(), destGate);
                        // break;
                    }
                }
        } while (i < gateSize);   
    }//Attacker forward a message to attacker to get the signature
    else if(getIndex()!=0 && getIndex() < f){
        do {
                destGate = gate(gateName, i++);
                cGate *nextGate = destGate->getNextGate();
                if (nextGate ) {
                    if(nextGate->getOwnerModule()->getIndex()==getIndex()+1){
                        ttmsg->setRound(ttmsg->getRound()+1);
                        ttmsg->setSignCount(ttmsg->getSignCount()+1);
                        ttmsg->insertSignature(ttmsg->getSignCount()-1,getIndex());
                        send(ttmsg->dup(), destGate);
                        break;
                    }
                }
        } while (i < gateSize);   
    }
}

void DolevS::byzantineLeader(){
    DolevStrongMsg *msg1 = generateMessage(5,0);
    DolevStrongMsg *msg2 = generateMessage(7,1);
    const char * gateName = "out";
    cGate *destGate = NULL;
    int i = 0;
    int gateSize = gate(gateName, 0)->size();

    if(f==1){
        do {
            destGate = gate(gateName, i++);
            cGate *nextGate = destGate->getNextGate();
            if (nextGate ) {
                if(nextGate->getOwnerModule()->getIndex()%2 == msg1->getMessageType())
                    send(msg1->dup(), destGate);
                if(nextGate->getOwnerModule()->getIndex()%2 == msg2->getMessageType())
                    send(msg2->dup(), destGate);
            }
        } while (i < gateSize);        
    }
    else if(f>1){
        do {
            destGate = gate(gateName, i++);
            cGate *nextGate = destGate->getNextGate();
            if (nextGate ) {
                if(nextGate->getOwnerModule()->getIndex()==getIndex()+1){
                    send(msg1->dup(), destGate);
                    send(msg2->dup(), destGate);
                    break;
                }
            }
        } while (i < gateSize);           
    }
}

//Leader send the message initially.
void DolevS::initialize()
{
    // Node 0 sends the first message
    if (getIndex() == 0) {
        f = par("f");
        n = par("n");
        outputfile.open ("output.txt");

        DolevStrongMsg *msg = generateMessage(5,0);
      
        const char * gateName = "out";
        cGate *destGate = NULL;
        int i = 0;
        int gateSize = gate(gateName, 0)->size();
        //In r=0 honest leader broadcasts a message.
        if(f==0){
            do {
                destGate = gate(gateName, i++);
                cGate *nextGate = destGate->getNextGate();
                if (nextGate ) {
                        send(msg->dup(), destGate);
                }
            } while (i < gateSize);        
        }
        else 
            byzantineLeader();
    }
}
//Handle all the message recieved at the node.
void DolevS::handleMessage(cMessage *msg)
{

    DolevStrongMsg *ttmsg = check_and_cast<DolevStrongMsg *>(msg);
    cout<<"Node Index : "<<getIndex()<<"  "<<ttmsg->getValue()<<endl;
    
    cout<<"size of neghbours "<<ttmsg->getSignCount()<<": "<<ttmsg->getSignature(0)<<endl;

    //Byzantine non-leader forward the message to other Byzantine non-sender
    if(getIndex()<f){
        byzantineNonLeader(ttmsg);
    }

    //For round 1...f if honest node recives the message from other nodes they broadcast it to all their neighbors after adding the signature.
    else if(getIndex()>=f){   
        for(int i=0;i<ttmsg->getSignCount();i++)
        {
            if(ttmsg->getSignature(i)==getIndex())
                return;
        }
        
        ttmsg->setRound(ttmsg->getRound()+1);
        acceptedValue.push_back(ttmsg->getValue());
        if(convincedOfValue(ttmsg) && ttmsg->getRound()<f)
        {
            ttmsg->setSignCount(ttmsg->getSignCount()+1);
            ttmsg->insertSignature(ttmsg->getSignCount()-1,getIndex());
            forwardMessage(ttmsg);
        }
    }
}

//Check whether the current node instance is convinced 
//of the value included in the message
bool DolevS::convincedOfValue(DolevStrongMsg *msg){
    //message is signed by the sender (leader) and t-1 other distinct nodes
    if(msg->getSignCount() == msg->getRound() && msg->getSource()==0){
        
        return true;
    }
    return false;    
}

//Honest node forward the message if they are convinced of 
//the value in the message
DolevStrongMsg *DolevS::generateMessage(int value, int type)
{
    // Produce source and destination addresses.
    int src = getIndex();  // our module index
    int n = getVectorSize();  // module vector size


    char msgname[20];
    sprintf(msgname, "DolevStrong-%d", src);

    // // Create message object and set source and destination field.
    DolevStrongMsg *msg = new DolevStrongMsg(msgname);
    msg->setSignatureArraySize(n);
    for(int i=0;i<n;i++){
        msg->setSignature(i, -1);
    }
    msg->setSource(src);
    msg->setSignCount(1);
    msg->setRound(0);
    msg->insertSignature(msg->getSignCount()-1,0);
    msg->setValue(value);
    msg->setMessageType(type);
    return msg;
}

//Honest node call this menthod to broadcast the message.
void DolevS::forwardMessage(DolevStrongMsg *msg)
{
    //Do not send to the nodes who have already signed the message.
    vector<int> notToSend;
    for(int i=0;i<msg->getSignCount();i++)
    {
        notToSend.push_back(msg->getSignature(i));
    }

    const char * gateName = "out";
    cGate *destGate = NULL;
    int i = 0;
    int gateSize = gate(gateName, 0)->size();

    do {
        destGate = gate(gateName, i++);
        cGate *nextGate = destGate->getNextGate();
        if (nextGate ) {
            if(find(notToSend.begin(), notToSend.end(), nextGate->getOwnerModule()->getIndex()) == notToSend.end())
                send(msg->dup(), destGate);
        }
    } while (i < gateSize);
}

//At round f+1 (when similation end), all the honest nodes 
//print the values they are convinced of.
void DolevS::finish(){
    if(getIndex()>=f && getIndex()!=0){
        cout<<"accepted value by node "<<getIndex()<<" is ";
        outputfile << "accepted value by node "<<getIndex()<<" is ";

        if(acceptedValue.size()>1){
            outputfile<<"Default"<<endl;
            cout<<"Default"<<endl;
            systemAcceptedValue.push_back(-1);
        }
        else{
            outputfile<<acceptedValue[0]<<endl;
            cout<<acceptedValue[0]<<endl;
            systemAcceptedValue.push_back(acceptedValue[0]);
        }
        
    }
    cout<<"------------------------------------------------"<<endl;
    
    //This is just to print the message, you can omit this
    if(systemAcceptedValue.size()==n-f){
        int intitialValue = systemAcceptedValue[0];
        for(int i = 1;i<n-f;i++){
            if(intitialValue !=systemAcceptedValue[i]){
                cout<<"*******************************************"<<endl;
                cout<<"Consistency violated"<<endl;
                cout<<"*******************************************"<<endl;
            }
            intitialValue = systemAcceptedValue[i];
        }

    }
}