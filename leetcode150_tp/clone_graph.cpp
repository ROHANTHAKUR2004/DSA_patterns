
class Solution {
public:
   unordered_map<Node* , Node*> mp;

   void dfs(Node* original, Node* cloned){
        
        for(auto it : original->neighbors){

            // mp not found clone to bnao
            if(mp.find(it) == mp.end()){
            // nayi node bnao;
             Node* cloneng = new Node(it->val);

             // map kardo 
             mp[it] = cloneng;
             // uska neigbours to attac kardo 
             cloned->neighbors.push_back(cloneng);
             //dfs
             dfs(it, cloneng);
            }
            // else agar to bss map kar do
            else  cloned->neighbors.push_back(mp[it]);

        }    
   }
    Node* cloneGraph(Node* original) {
        mp.clear();
        if(!original) return NULL;
        // make clone;

        Node* cloned = new Node(original->val);

        mp[original] = cloned;

        // dfs

        dfs(original , cloned);
        return cloned;
    }
};