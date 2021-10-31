# Energy-Gc


Blockchain has some fundamental privacy problems by virtue of its design. Specifically, the distributed aspect of a blockchain means that each full node that processes transactions and builds the blockchain necessarily has access to the blockchain transaction data itself.This is a big concern for blockchain and recent interest has been towards enhancing privacy and confidentiality in the blockchain system.

Coming to the Problem statement and our code,
In the blockchain we have 5 users : a customer,a dealer,a manufacturer and 2 suppliers(tier1 and tier2).
Given that  customer’s share information  only to the dealer and the suppliers share information only among themselves and with the manufacturer, confidentiality of information is maintained.
We have tried to implement privacy and confidentiality in a blockchain.
We have used C++ for the same.Demonstration mode is through the command line interface.

We have defined classes for block and blockchain and a struct for the transaction data.
Block:
Each block will have a hash of its own and its previous hash
Blockchain:
addBlock() function will add a newly created block to the chain.
TransactionData:
This is storing the information of transactions.
There is a function isChainValid() which checks if the blockchain is valid after each transaction.
We have diffentiated the users based on the input they give in the command line and their data will be visible to them and the parties who have agreed to share information.(confidentiality)
To prove the privacy,we have added a variable data: which when added or updated will only be visible to the parties who have agreed to share information.
After every transcation we have printed the current state of blockchain that is all the previous transaction happend in the chain.
Thus we have implemented both privacy and confidentiality in a blockchain of small scale.



