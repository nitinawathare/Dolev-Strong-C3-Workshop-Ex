//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2003 Ahmet Sekercioglu
// Copyright (C) 2003-2015 Andras Varga
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

message DolevStrongMsg
{
    int source;
    int signCount = 0;
    int signature[];
    int round = 0;
    int value = 0;
    int messageType;
}

