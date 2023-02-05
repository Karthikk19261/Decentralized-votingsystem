voters = readConfig();
    runNode();
    if (condition == true){
        condition = false;
        runNode();
    }
    while (true){
         //running as a server
        while(true){
            std::string msg = recieveFromNetwork();
            if (msg == "")
                break;
            std::vector<std::string> nodes;
            std::string tempNodes;
            std::stringstream X(msg);
            while(getline(X, tempNodes, ' ')){
                nodes.push_back(tempNodes);
            }
            if (nodes[2] == "5")
                break;
            sleep(6);
        }
        std::string testt= selfID + “ “ + selfID + “ 4”;
        sendToNetwork(testt);
        sleep(timer);
        while(1){
            std::string msg = recieveFromNetwork();
            if (msg != ""){
                sleep(2);
                std::vector<std::string> nodes;
                std::string tempNodes;
                std::stringstream X(msg);
                while(getline(X, tempNodes, ' ')){
                    nodes.push_back(tempNodes);
                }
                if (nodes[0] != selfId){
                    sleep(timer);
                    continue;
                }
                if (nodes[0] == selfId && nodes[2] == "0"){
                    sendToNetwork(nodes[1] + " " + nodes[0] + " 2");
                    Block toSend;
                    if (votesChain.giveSize() != 0){
                        toSend = votesChain.giveTop();
                    }
                    else{ //when server and nodes crashes in between
                        std::cout << "Server failed without registering any votes" << std::endl;
                        return 0;
                    }
                    sendBlockToNetwork(toSend);
                    std::cout << "Block Sent" << std::endl;
                }
                else if (nodes[0] == selfId && nodes[2] == "1"){
                    Block recievedBlock = recieveBlockFromNetwork();
                    std::cout << "Block received" << std::endl;
                    sendToNetwork(nodes[1] + " " + nodes[0] + " 2");
                    votesChain.addBlock(recievedBlock);
                    std::cout << "Block succesfully appended" << std::endl;
                    votesChain.update();
                    std::cout << "Blockchain.dat succesfully updated" << std::endl;
                    sendToNetwork("-1 " + selfId + " 4");
                }
            }}}
