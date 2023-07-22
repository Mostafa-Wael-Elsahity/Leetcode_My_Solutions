class Trie{ // we don't use it if length is long because it take a lot of memory using trie with map or linked list 
    private:
        // here u can control the number of children of each node
        Trie *child[26]; // array of child nodes of this node in the trie tree
        int cntPrefix;   // number of prefix that pass here
        int cntEnd;      // number of words that end here
    public:
    Trie(){
        cntPrefix = 0;
        cntEnd = 0;
        memset(child,0,sizeof(child));
    }


    void insert(string s){ // O(length of string)
        Trie *cur=this;
        for(char c:s){
            if(cur->child[c-'a']==NULL)
                cur->child[c-'a']=new Trie();
            cur=cur->child[c-'a'];
            cur->cntPrefix++;
        }
        cur->cntEnd++;
    }

    int search(string s){ // O(length of string)
        Trie *cur=this;
        for(char c:s){
            if(cur->child[c-'a']==NULL)
                return 0;
            cur=cur->child[c-'a'];
        }
        return cur->cntEnd;
    } 


    // delete trie 
    void deleteTrie(){ // O(# nodes)
        for(int i=0;i<26;i++){
            if(child[i]!=NULL){
                child[i]->deleteTrie();
                delete child[i];
                child[i]=NULL;
            }
        }
    }
    
};
class Solution {
public:
    Trie *root=new Trie();
    int n,m;
    bitset<15>vis[15];
    const int dx[4]={0,0,1,-1};
    const int dy[4]={1,-1,0,0};
    void backTrack(int i,int j,int ctr,string &s,vector<vector<char>>& board){
        root->insert(s);
        if(!ctr) return;
        for(int k=0;k<4;k++){
            int x=dx[k]+i,y=dy[k]+j;
            if(x<n&&x>=0&&y>=0&&y<m&&!vis[x][y]){
                s+=board[x][y];
                vis[x][y]=1;
                backTrack(x,y,ctr-1,s,board);
                s.pop_back();
                vis[x][y]=0;
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string s="";
                s+=board[i][j];
                vis[i][j]=1;
                backTrack(i,j,9,s,board);
                vis[i][j]=0;
            }
        }
        vector<string>ans;
        for(auto word:words)
            if(root->search(word))
                ans.push_back(word);
        return ans;
    }
};