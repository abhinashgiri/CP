struct Trie_Node{
    int terminal;
    Trie_Node *child[26];
    int cnt;
};

Trie_Node* init(){
    Trie_Node* node=new Trie_Node;
    node->cnt=0;
    node->terminal=0;
    for (int i = 0; i < 26; ++i){
        node->child[i]= nullptr;
    }
    return node;
}

void insert(Trie_Node*root,string &s){
    Trie_Node*temp=root;
    for (int i = 0; s[i]; ++i){
        int ind=(s[i]-'a');
        if(temp->child[ind]== nullptr){
            temp->child[ind]=init();
        }
        temp=temp->child[ind];
        temp->cnt++;
        if(s[i+1]=='\0'){
            temp->terminal++;
        }
    }
}

int sum(Trie_Node*root,string &s){
    Trie_Node*temp=root;
    int ans  = 0;
    for (int i = 0; s[i]; ++i){
        int ind=(s[i]-'a');
        temp = temp->child[ind];
        ans += temp->cnt;
    }
    return ans;
}


void getAllStrings(Trie_Node*curr,string &curr_word,bool &found){
    if(curr== nullptr)return;
    if(curr->terminal>0){
        cout<<curr_word<<"\n";
        found=true;
    }
    for (int i = 0; i < 26; ++i){
        if(curr->child[i]==nullptr)continue;
        char ch=i;
        curr_word.push_back(ch);
        getAllStrings(curr->child[i],curr_word,found);
        curr_word.pop_back();
    }
}
