//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2003-2015 Andras Varga
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

simple DolevS
{
    parameters:
        @display("i=block/routing");
        int f = default(1);
        int n = default(5);
    gates:
        input in[];  // declare in[] and out[] to be vector gates
        output out[];
}

network DolevStrong
{
    types:
        channel Channel extends ned.DelayChannel {
            delay = 100ms;
        }
    
    submodules:
        DS[5]: DolevS;
    connections:

        DS[0].out++ --> Channel --> DS[1].in++;
        DS[0].in++ <-- Channel <-- DS[1].out++;
        DS[0].out++ --> Channel --> DS[2].in++;
        DS[0].in++ <-- Channel <-- DS[2].out++;
        DS[0].out++ --> Channel --> DS[3].in++;
        DS[0].in++ <-- Channel <-- DS[3].out++;
        DS[0].out++ --> Channel --> DS[4].in++;
        DS[0].in++ <-- Channel <-- DS[4].out++;
        DS[1].out++ --> Channel --> DS[2].in++;
        DS[1].in++ <-- Channel <-- DS[2].out++;
        DS[1].out++ --> Channel --> DS[3].in++;
        DS[1].in++ <-- Channel <-- DS[3].out++;
        DS[1].out++ --> Channel --> DS[4].in++;
        DS[1].in++ <-- Channel <-- DS[4].out++;
        DS[2].out++ --> Channel --> DS[3].in++;
        DS[2].in++ <-- Channel <-- DS[3].out++;
        DS[2].out++ --> Channel --> DS[4].in++;
        DS[2].in++ <-- Channel <-- DS[4].out++;
        DS[3].out++ --> Channel --> DS[4].in++;
        DS[3].in++ <-- Channel <-- DS[4].out++;

        
}

