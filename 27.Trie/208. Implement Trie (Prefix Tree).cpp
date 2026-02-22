// https://leetcode.com/problems/implement-trie-prefix-tree/description/
class Node{
    public:
    bool isEndOfWord;
    Node* children[26];
    Node()
    {
       
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
        }
        temp->isEndOfWord=true;
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
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */