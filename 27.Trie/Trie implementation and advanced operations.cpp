#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int count;
    int countOfWordsEndedHere;
    bool isEndOfWord;
    Node* children[26];
    Node()
    {
        count=0;
        countOfWordsEndedHere=0;
        isEndOfWord=false;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
    }
};


class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        int n=word.size();
        Node* temp=root;
        for(int i=0;i<n;i++)
        {
            if(temp->children[word[i]-'a']==NULL)
            {
                 temp->children[word[i]-'a']=new Node();
            }
            
            temp=(temp->children)[word[i]-'a'];
            temp->count=temp->count+1;
        }
        temp->isEndOfWord=true;
        temp->countOfWordsEndedHere=temp->countOfWordsEndedHere+1;
    }
    
    bool search(string word) {
        int n=word.size();
        Node* temp=root;
        for(int i=0;i<n;i++)
        {
            if(temp->children[word[i]-'a']==NULL) return false;
            temp=(temp->children)[word[i]-'a'];
        }
        if(temp->isEndOfWord==false) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        int n=prefix.size();
        Node* temp=root;
        for(int i=0;i<n;i++)
        {
            if(temp->children[prefix[i]-'a']==NULL) return false;
            temp=temp->children[prefix[i]-'a'];
        }
        return true;
    }
    int countWordsEqualTo(string word)
    {
        int n=word.size();
        Node* temp=root;
        for(int i=0;i<n;i++)
        {
            if(temp->children[word[i]-'a']==NULL) return 0;
            temp=temp->children[word[i]-'a'];
        }
        return temp->countOfWordsEndedHere;
    }
    int countWordsStartingWith(string word)
    {
        int n=word.size();
        Node* temp=root;
        for(int i=0;i<n;i++)
        {
            if(temp->children[word[i]-'a']==NULL) return 0;
            temp=temp->children[word[i]-'a'];
        }
        return temp->count;
    }
    void erase(string word)
    {
        int n=word.size();
        Node* temp=root;
        for(int i=0;i<n;i++)
        {
            if(temp->children[word[i]-'a']==NULL)
            {
                cout<<word<<" Word not found"<<endl;
                return;
            }
            temp=temp->children[word[i]-'a'];
            temp->count=temp->count-1;
        }
        temp->countOfWordsEndedHere=temp->countOfWordsEndedHere-1;
        if(temp->countOfWordsEndedHere==0)
        {
           temp->isEndOfWord=false; 
        }
        cout<<"Word:"<<word<<" erased successfully"<<endl;
    }
};
int main()
{
    string input1[]={"Trie", "insert","insert", "search", "search","search", "startsWith", "insert", "search","countWordsEqualTo",
    "countWordsEqualTo","countWordsEqualTo","erase","erase","countWordsEqualTo","countWordsStartingWith"};
    string input2[]={"", "apple","apple", "apple","shivanshu", "app", "app", "app", "app","app","apple","shivanshu","shivanshu","apple","apple","appl"};
    int n=sizeof(input1)/sizeof(input1[0]);
    Trie* trieObj;
    for(int i=0;i<n;i++)
    {
        if(input1[i]=="Trie")
        {
            trieObj=new Trie();
        }
        else if(input1[i]=="insert")
        {
            trieObj->insert(input2[i]);
            cout<<"Inserted:"<<input2[i]<<endl;
        }
        else if(input1[i]=="search")
        {
            bool a=trieObj->search(input2[i]);
            cout<<"Searched for: "<<input2[i]<<" and result is :- "<<a<<endl;
        }
        else if(input1[i]=="startsWith")
        {
            bool a=trieObj->startsWith(input2[i]);
            cout<<"Checked for startsWith and input is :-"<<input2[i]<<" and result is:-"<<a<<endl;
        }
        else if(input1[i]=="countWordsEqualTo")
        {
            int count=trieObj->countWordsEqualTo(input2[i]);
            cout<<"countWordsEqualTo:"<<input2[i]<<" are:- "<<count<<endl;
        }
        else if(input1[i]=="erase")
        {
            trieObj->erase(input2[i]);
        }
        else if(input1[i]=="countWordsStartingWith")
        {
            int a=trieObj->countWordsStartingWith(input2[i]);
            cout<<"countWordsStartingWith:-"<<a<<endl;
        }
    }
}