#include <bits/stdc++.h>
#include <utility>
using namespace std;

#define int long long
#define f(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ld lond double
#define vi vector<int>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

struct Node
{
    // A Tree Node
    char ch;
    int freq;
    Node *left;
    Node *right;
};


// Function to allocate a new tree node
Node *getNode(Node *left,Node *right,int freq,char ch)
{
    Node *node = new Node();
    node->left = left;
    node->right = right;
    node->ch = ch;
    node->freq = freq;
    return node;
}

// Utility function to check if Huffman Tree contains only a single node
bool isLeaf(Node* root) {
    return root->left == NULL && root->right == NULL;
}

// custom template for priority queue
struct comp
{
    bool operator()(const Node* l, const Node* r) const
    {
        // the highest priority item has the lowest frequency
        return l->freq > r->freq;
    }
};


// Traverse the Huffman Tree and store Huffman Codes in a map.
void encode(Node *root,string s,unordered_map<char, string> &huffmanCode)
{
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL)
    {
        huffmanCode[root->ch] = s;
        return;
    }
    encode(root->left,s+"0",huffmanCode);
    encode(root->right,s+"1",huffmanCode);
    return;
}

void buildHuffmanTree()
{
    string text;
    cin>>text;
    if(text.length()==0)return;
    //will store the frequency of every character
    unordered_map<char,int>mp;
    for(auto it : text)mp[it]++;
    // Create a priority queue to store live nodes of the Huffman tree
    priority_queue<Node*, vector<Node*>, comp> pq;
    // Create a leaf node for each character and add it
    // to the priority queue.
    for(auto it : mp)
    {
        Node *node = getNode(NULL,NULL,it.second,it.first);
        pq.push(node);
    }
    // do till there is more than one node in the queue
    while(pq.size()>1)
    {
	// Create a new internal node with these two nodes
        // as children and with frequency equal to the sum
        // of the two nodes' frequencies. Add the new node
        // to the priority queue.
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        int sum = left->freq + right->freq;
        Node *node = getNode(left,right,sum,'0');
        pq.push(node);
    }
    // root stores pointer to the root of Huffman Tree
    // Traverse the Huffman Tree and store Huffman Codes
    // in a map. Also, print them
    Node *root = pq.top();
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);
    cout << "Huffman Codes are: " << endl;
    for(auto it : huffmanCode)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout << "\nThe original string is:\n" <<endl<<text << endl;
    //Now We'll find out the compressed encoded string;
    string enc = "";
    for(auto it : text)
    {
        enc += huffmanCode[it];
    }
    // Print the encoded string 
    cout << "\nThe encoded string is:\n" << enc << endl;
    // Now we'll find out the original string out of
    // encoded string
    // map to store codes with character
    unordered_map<string,char>huffmanDecode;
    for(auto it : huffmanCode)
    {
        huffmanDecode[it.second] = it.first;
    }
    // Decoded String 
    string decoded_string = "";
    // Prefix string till the huffman code is not matched
    string prefix = "";
    for(auto it : enc)
    {
        prefix += it;
        if(huffmanDecode.find(prefix) != huffmanDecode.end())
        {
            decoded_string += huffmanDecode[prefix];
            prefix = "";
        }
    }
    cout << "\nThe decoded string is:\n";
    cout << decoded_string << "\n";
}

int32_t main()
{
    IOS;
    // no of string to be encoded and decoded
    int t;
    cin>>t;
    while(t--)
    {
        // This function will build huffmantree
        buildHuffmanTree();
    }
}
