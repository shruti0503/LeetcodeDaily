class Node {
public:
    string data;
    Node* next;
    Node* back;

    // Default constructor
    Node() : data(""), next(nullptr), back(nullptr) {}

    // Constructor with data parameter
    Node(string x) : data(x), next(nullptr), back(nullptr) {}

    // Constructor with data, next, and back parameters
    Node(string x, Node* nextNode, Node* backNode) : data(x), next(nextNode), back(backNode) {}
};
class Browser
{
    public:

    Node* currentPage;
    // tuf
    Browser(string &homepage)
    {
        // Write you code here
        currentPage= new Node(homepage)
    }

    void visit(string &url)
    {
        // Write you code here
        Node* newNode=new Node(url); // new node =>  fb
        currentPage->next=newNode; // tuf-> fb
        newNode->back=currentPage;// tuf <- fb
        currentPage=newNode; // tuf <=> fb (currentPage)
    }

    string back(int steps)
    {
        // tuf <=> fb <=> insta <=> git
        // Write you code here
        while(steps){
            if(currentPage){
                currentPage=currentPage->next;

            }
            else{
                break;
            }
            steps--;
        }

        return currentPage->data;
    }

    string forward(int steps)
    {
        // Write you code here
        while(steps){
            if(currentPage->next){
                currentPage=currentPage->next;
            }
            else break;
            steps --;
        }
        return currentPage->data;
    }
};
