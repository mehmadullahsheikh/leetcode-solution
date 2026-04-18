#include<bits/stdc++.h>
using namespace std;

// we can use a trie to store the folder structure. we can insert all the paths in the trie and then we can populate the subFolder for each node in the trie. we can use a map to count the frequency of each subFolder and then we can delete the duplicate folders from the trie. finally, we can construct the result from the trie.

class Solution {
public:
    struct node{
        string name;
        string subFolder;
        unordered_map<string,node*> children;
    };
    node* getNode(string val){
        node* temp=new node();
        temp->name=val;
        temp->subFolder="";
        return temp;
    }
    void insert(node* root,vector<string>&path){
        for(auto&folder:path){
            if(!root->children.count(folder)){
                root->children[folder]=getNode(folder);
            }
            root=root->children[folder];
        }
    }
    string populate(node* root,unordered_map<string,int>&subFolderMap){
        vector<pair<string,string>> allChild;
        for(auto &[childName,child]:root->children){
            string subResult=populate(child,subFolderMap);
            allChild.push_back({childName,subResult});
        }
        sort(begin(allChild),end(allChild));
        string completePath="";
        for(auto &[name,result]:allChild){
            completePath+="("+name+result+")";
        }
        root->subFolder=completePath;
        if(!completePath.empty()){
            subFolderMap[completePath]++;
        }
        return completePath;
    }
    void deleteFolder(node* root,unordered_map<string,int>&subFolderMap){
        for(auto it=root->children.begin();it!=root->children.end();){
            auto name=it->first;
            auto node=it->second;
            if(!node->subFolder.empty() &&subFolderMap[node->subFolder]>1){
                it=root->children.erase(it);
            }
            else{
                deleteFolder(node,subFolderMap);
                it++;
            }
        }
    }
    void constructPath(node* root, vector<string> &path,vector<vector<string>> &result){
        for(auto &[childName,child]:root->children){
            path.push_back(childName);
            result.push_back(path);
            constructPath(child,path,result);
            path.pop_back();
        }
    }
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        node* root=getNode("/");
        //building trie
       for(auto path:paths){
          insert(root,path);
       }
       // populate subFoldetr
       unordered_map<string,int> subFolderMap;
       populate(root,subFolderMap);

       // delete duplicate folder;
       deleteFolder(root,subFolderMap);

       vector<vector<string>> result;
       vector<string> path;
       constructPath(root,path,result);
       return result;
    }
};