#include <bits/stdc++.h>
using namespace std;

class DoublyLinkedListNode
{
public:
    string key;
    int value;
    DoublyLinkedListNode *prev;
    DoublyLinkedListNode *next;

    DoublyLinkedListNode(string key, int value)
    {
        this->key = key;
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }

    void removeBindings()
    {
        if (this->prev != NULL)
            this->prev->next = this->next;
        if (this->next != NULL)
            this->next->prev = this->prev;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList
{
public:
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;

    DoublyLinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    void setHeadTo(DoublyLinkedListNode *node)
    {
        if (this->head == node)
            return;
        else if (this->head == NULL)
        {
            this->head = node;
            this->tail = node;
            return;
        }
        else if (this->head == this->tail)
        {
            this->tail->prev = node;
            this->head = node;
            this->head->next = this->tail;
            return;
        }
        else
        {
            if (this->tail == node)
                this->removeTail();

            node->removeBindings();
            this->head->prev = node;
            node->next = this->head;
            this->head = node;
            return;
        }
    }

    void removeTail()
    {
        if (this->tail == NULL)
            return;

        if (this->head == this->tail)
        {
            this->head = NULL;
            this->tail - NULL;
            return;
        }

        this->tail = this->tail->prev;
        this->tail->next = NULL;
    }
};

class LRUCache
{
public:
    unordered_map<string, DoublyLinkedListNode *> cache;
    int maxSize;
    int curSize;
    DoublyLinkedList listOfMostRecent;


    LRUCache(int maxSize){ 
        this->maxSize = maxSize > 1 ? maxSize : 1; 
        this->curSize = 0;
        this->listOfMostRecent = DoublyLinkedList();    
    }

    void insertKeyValuePair(string key, int value){
        if(this->cache.find(key)==this->cache.end()){
            if(this->curSize == this->maxSize){
                this->evictLeastRecent();
            }
            else this->curSize++;

            this->cache[key]= new DoublyLinkedListNode(key,value);   
        }
        else
        {
            this->replaceKey(key,value);
        }
        this->updateMostRecent(this->cache[key]);
    }

    void insertKeyValuePair(string key, int value)
    {
    }

    int *getValueFromKey(string key)
    {
        if(this->cache.find(key)== this->cache.end())return NULL;
        this->updateMostRecent(this->cache[key]);
        return &this->cache[key]->value;
    }

    string getMostRecentKey()
    {
        if(this->listOfMostRecent.head == NULL)return "";
        return this->listOfMostRecent.head->key;
    }

    void evictLeastRecent(){
        string keyToRemove = this->listOfMostRecent.tail->key;
        this->listOfMostRecent.removeTail();
        this->cache.erase(keyToRemove);
    }

    void updateMostRecent(DoublyLinkedListNode* node){
        this->listOfMostRecent.setHeadTo(node);
    }

    void replaceKey(string key,int value){
        if(this->cache.find(key) == this->cache.end())return;
        this->cache[key]->value = value;
    }
        
};
