// https://leetcode.com/problems/clone-graph/description/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void helper(Node* node,Node* clone,set<Node*>&visited,map<Node*,Node*>&mp)
    {
        if(node==NULL or clone==NULL) return;
        for(auto it:node->neighbors)
        {
            Node* newNode;
            if(mp.find(it)==mp.end())
            {
                newNode=new Node(it->val);
                mp[it]=newNode;
            }
            else
            {
                newNode=mp[it];
            }
            clone->neighbors.push_back(newNode);
            if(visited.find(it)==visited.end())
            {
                 visited.insert(it);
                 helper(it,newNode,visited,mp);
            }
           
        }


    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* newNode=new Node(node->val);
        set<Node*>visited;
        visited.insert(node);
        map<Node*,Node*>mp;
        mp[node]=newNode;
        helper(node,newNode,visited,mp);
        return newNode;
    }
};