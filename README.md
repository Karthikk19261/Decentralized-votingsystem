# Decentralized-voting-system

The need for security in the digital technology is increasing day by day, and a voting system which is assumed to be highly secure from the prototyping phase only faces more challenges than any other software in terms of security and privacy today. Election manipulation, and vote alteration are the key problems within the current classical voting system. Blockchain technology is one of the solutions as it embraces a decentralized system and the entire database is owned by many users.
The objective of the project is to provide a secure voting environment and show that a reliable e-voting scheme is possible using blockchain. Large-scale traditional elections are prone to various security as well as maintenance issues, the project eliminate all those weakness from the classic voting system.

Proposed Methodology

•	The voter will get authenticated from a decentralized database and check if he has the right to vote or not

•	If the voter is valid, the voter will receive the previous block from the blockchain

•	Once the block is received, the voter can cast a vote, and this leads to modification of the already existing blockchain due to the addition of a new block

•	The block is shared and appended to the blockchain

In case of a node or a server failure, even if the blockchain is lost, the last block will still be active in the network and can be used to future expand the chain.

![image](https://user-images.githubusercontent.com/124515180/216833864-fa58422a-ed26-43c5-84fe-b5f66ab1e333.png)

Architecture Diagram

![image](https://user-images.githubusercontent.com/124515180/216833875-ebff55fb-6de1-41dd-9e43-7dfc90043870.png)

Description on Various Modules

![image](https://user-images.githubusercontent.com/124515180/216833899-cfac20dc-55e1-415c-80e1-e0487e13e618.png)

•	Node: - Module will authenticate the user and will directly interact with the server and other nodes (in case of a server failure)

•	Sha: - used to calculate sha256 of the entire block

•	Block: - Will be responsible for creating the blocks and converting them to bits for transmission and vice-versa

•	Networking module: - will be responsible for making the connection between the nodes, the server, and the database (in the proposed prototype, sockets will be used to replicate server-client architecture)

•	Server: - will be initially running the centralized service for all the nodes
