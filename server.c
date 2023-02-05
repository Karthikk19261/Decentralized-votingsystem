runServer();
    while(true){
        string msg = recieveFromNetwork();
        if (msg != ""){
             //somebody sent a msg
            vector<string> nodes;
            string tempNodes;
            stringstream X(msg);
            while(getline(X, tempNodes, ' ')){
                nodes.push_back(tempNodes);
            }
            if (nodes[0] != "0"){
                sleep(timer);
                continue;
            }
            cout << "Message to the server detected" << endl;
            cout << "Identifying the node";
            transition();
            if (nodes[2] == "0"){
                cout << "Node: " << nodes[1] << " requesting block";
                transition();
            }
            else if (nodes[2] == "1"){
                cout << "Node: " << nodes[1] << "sent a block" << endl;
            }
            if (nodes[0] == selfId && nodes[2] == "0"){
                sendToNetwork(nodes[1] + " " + nodes[0] + " 2");
                Block toSend = votesChain.giveTop();
                sendBlockToNetwork(toSend);
                cout << "Block sent" << endl;
            }
            else if (nodes[0] == selfId && nodes[2] == "1"){
                Block recievedBlock = recieveBlockFromNetwork();
                cout << "Block received" << endl;
                sendToNetwork(nodes[1] + " " + nodes[0] + " 2");
                cout << "Block appending to the blockchain";
                transition();
                votesChain.addBlock(recievedBlock);
                cout << "Block succesfully appended" << endl;
                cout << "updating Blockchain.dat";
                transition();
                votesChain.update();
                cout << "Blockchain.dat succesfully updated" << endl << endl;
                sendToNetwork("-1 0 3");
            }
        }
        sleep(timer);
    }
