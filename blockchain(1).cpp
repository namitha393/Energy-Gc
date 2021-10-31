#include <iostream>
#include <ctime>
#include <vector>
#include <stdio.h>
#include <string>

struct TransactionData
{
    double amount;
    std::string senderKey;
    std::string receiverKey;
    time_t timestamp;
    
    TransactionData(){};
    
    TransactionData(double amt, std::string sender, std::string receiver)
    {
        amount = amt;
        senderKey = sender;
        receiverKey = receiver;
    //    timestamp = time;
    };
};

class Block
{
private:
    int index;
    size_t blockHash;
    size_t previousHash;
    size_t generateHash();
    
public:
    // Constuctor
    Block(int idx, TransactionData d, size_t prevHash);
    
    // Get Index
    int getIndex();
    
    // Get Original Hash
    size_t getHash();
    
    // Get Previous Hash
    size_t getPreviousHash();
    
    // Transaction Data
    // Would ordinarily be a private member with a "getter": getData()
    TransactionData data;
    
    // Validate Hash
    bool isHashValid();
};

class Blockchain
{
private:
    int data1=0,data2=0,data3=0;
    
    std::vector<Block> chain;

public:
    // Constuctor
    
    
    // Public Functions
    std::vector<Block> getChain();
    Block *getLatestBlock();
    bool isChainValid();
    void addBlock(TransactionData data);
    void printChain();
    void edit_data1(int x){
    	data1=x;
    }
     void edit_data2(int x){
    	data2=x;
    }
     void edit_data3(int x){
    	data3=x;
    }
    int get_data1(){
        return data1;
    }
    int get_data2(){
        return data2;
    }
    int get_data3(){
        return data3;
    }	
    	
    
};

// Constructor with params
Block::Block(int idx, TransactionData d, size_t prevHash)
{
    index = idx;
    data = d;
    previousHash = prevHash;
    blockHash = generateHash();
}

// private functions
int Block::getIndex()
{
    return index;
}

/*
 Generates hash for current block
 - Includes previousHash in generation
 - ^ Very important
*/
size_t Block::generateHash()
{
    // creating string of transaction data
    std::string toHashS = std::to_string(data.amount) + data.receiverKey + data.senderKey + std::to_string(data.timestamp);
    
    // 2 hashes to combine
    std::hash<std::string> tDataHash; // hashes transaction data string
    std::hash<std::string> prevHash; // re-hashes previous hash (for combination)
    
    // combine hashes and get size_t for block hash
    return tDataHash(toHashS) ^ (prevHash(std::to_string(previousHash)) << 1);
}

// Public Functions
size_t Block::getHash()
{
    return blockHash;
}

size_t Block::getPreviousHash()
{
    return previousHash;
}

bool Block::isHashValid()
{
    return generateHash() == getHash();
}

// Blockchain Constructor


// Public Chain Getter
std::vector<Block> Blockchain::getChain() {
    return chain;
}



// We only need pointer here
// to demonstrate manipulation of transaction data
Block *Blockchain::getLatestBlock()
{
    return &chain.back();
}

void Blockchain::addBlock(TransactionData d)
{
    int index = (int)chain.size();
    std::size_t previousHash = (int)chain.size() > 0 ? getLatestBlock()->getHash() : 0;
    Block newBlock(index, d, previousHash);
    chain.push_back(newBlock);
}

bool Blockchain::isChainValid()
{
    std::vector<Block>::iterator it;
    
    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        if (!currentBlock.isHashValid())
        {
            return false;
        }
        
        // Don't forget to check if this is the first item
        if (it != chain.begin())
        {
            Block previousBlock = *(it - 1);
            if (currentBlock.getPreviousHash() != previousBlock.getHash())
            {
                return false;
            }
        }
    }
    
    return true;
}

void Blockchain::printChain() {
    std::vector<Block>::iterator it;
    
    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        printf("\n\nBlock ===================================");
        printf("\nIndex: %d", currentBlock.getIndex());
        printf("\nAmount: %f", currentBlock.data.amount);
    //    printf("\nSenderKey: %s", currentBlock.data.senderKey.c_str());
    //    printf("\nReceiverKey: %s", currentBlock.data.receiverKey.c_str());
        printf("\nTimestamp: %ld", currentBlock.data.timestamp);
        printf("\nHash: %zu", currentBlock.getHash());
        //printf("\nPrevious Hash: %zu", currentBlock.getPreviousHash());
        printf("\nIs Block Valid?: %d", currentBlock.isHashValid());
    }
}

using namespace std;

int main()
{
    // Start Blockchain
Blockchain awesomeCoin;
int t=0;
while(t>=0){
    cout<<"Type 0 to proceed and -1 to stop"<<endl;
    cin>>t;
    if(t==-1){ break; };    
    // Data for first block
    /*time_t data1Time;
    TransactionData data1(1.5, "Joe", "Sally", time(&data1Time));
    awesomeCoin.addBlock(data1);
    
    time_t data2Time;
    TransactionData data2(0.2233, "Martha", "Fred", time(&data2Time));
    awesomeCoin.addBlock(data2);
    
    // Let's see what's in the awesomeCoin blockchain!
    awesomeCoin.printChain();
    
    // Is it valid?
    printf("\nIs chain still valid? %d\n", awesomeCoin.isChainValid());
    
    // Someone's getting sneaky
    Block *hackBlock = awesomeCoin.getLatestBlock();
    hackBlock->data.amount = 10000; // Oh yeah!
    hackBlock->data.receiverKey = "Jon"; // mwahahahaha!

    // Let's look at data
    awesomeCoin.printChain();

    // Awww! Why is it not valid?
    printf("\nIs chain still valid? %d\n", awesomeCoin.isChainValid());*/
    
    
    cout<<"Please choose who you are"<<endl;
    cout<<"1 for customer"<<endl;
    cout<<"2 for dealer"<<endl;
    cout<<"3 for OEM"<<endl;
    //cout<<"4 for OEM"<<endl;
    int choice;
    cin>>choice;
    if(choice==1){
    	cout<<"enter the amount"<<endl;
    	double amount;
    	cin>>amount;
    	TransactionData data1(amount,"customer","dealer");
   	    awesomeCoin.addBlock(data1);
        awesomeCoin.printChain();
        cout<<endl;
        cout<<"To see stored data type 1 and to edit data type zero"<<endl;
        int d;
        cin>> d;  
        if(d==1){
            cout<<awesomeCoin.get_data1()<<endl;
        } 
        else if(d==0){
            int y;
            cout<<"enter data(only integers) : "<<endl;
            cin>>y;
            awesomeCoin.edit_data1(y);
        }
   }
   else if(choice==2){
        cout<<"enter the amount"<<endl;
    	double amount;
    	cin>>amount;
    	TransactionData data1(amount,"dealer","OEM");
   	    awesomeCoin.addBlock(data1);
        awesomeCoin.printChain();
        cout<<endl;   
        cout<<"To see stored data type 1 and to edit data type zero"<<endl;
        int d;
        cin>> d;
        if(d==1){
            cout<<awesomeCoin.get_data2()<<endl;
        } 
        else if(d==0){
            int y;
            cout<<"enter data(only integers) : "<<endl;
            cin>>y;
            awesomeCoin.edit_data2(y);
        }
   }
   else if(choice==3){
        cout<<"enter the amount"<<endl;
    	double amount;
    	cin>>amount;
    	TransactionData data1(amount,"OEM","Supplier");
   	    awesomeCoin.addBlock(data1);
        awesomeCoin.printChain();  
        cout<<endl; 
        cout<<"To see stored data type 1 and to edit data type zero"<<endl;
        int d;
        cin>> d;
        if(d==1){
            cout<<awesomeCoin.get_data3()<<endl;
        } 
        else if(d==0){
            int y;
            cout<<"enter data(only integers) : "<<endl;
            cin>>y;
            awesomeCoin.edit_data3(y);
        }
   }
};    
    
   return 0;
}
