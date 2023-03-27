#include<bits/stdc++.h>
using namespace std;

// node for tree
struct Node {
    char data;
    unsigned freq;
    Node *left, *right;

    Node(char data, unsigned freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }

    ~Node() {
        delete left;
        delete right;
    }
};

struct comp {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void encode(Node* root, string str, unordered_map<char, string> &huffmanCode) {
    if (root == nullptr) {
        return;
    }

    if (!root->left && !root->right) {
        huffmanCode[root->data] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}


Node* buildHuffmanTree(string text) {
    unordered_map<char, unsigned> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, comp> pq;

    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    return pq.top();
}

string huffmanEncode(string text) {
    Node* root = buildHuffmanTree(text);

    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    std::set<char> uniqueChar;
    string result = "";
    for (char ch : text) {
        uniqueChar.insert(ch);
        result += huffmanCode[ch];
    }
    std::cout<<"Char  |  Code"<<std::endl;
    for (char ch:uniqueChar){
        std::cout<<" '"<<ch<<"'     "<<huffmanCode[ch]<<std::endl;
    }

    delete root;
    return result;
}


int main() {
    std::cout<<"Enter string input: ";
    string text;
    std::getline(std::cin,text);
    string encodedText = huffmanEncode(text);
    cout << "Encoded text: " << encodedText << endl;
    return 0;
}