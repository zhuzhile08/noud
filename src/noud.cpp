#include <noud.h>

namespace noud {
    Node::Node(Node* parent, std::string name) : parent(parent), name(name) { }

    void Node::destroy() {
        while (!children.empty()) {
            Node* node = children.back();
            node->parent = parent;
            delete node;
        }
        children.erase(children.begin(), children.end());
        delete parent;
    }
// function to add a child
    void Node::add_child(Node* newChild) {
        newChild->parent = this;
        children.push_back(newChild);
    }

// functions to add current node to tree
    void Node::add_to_beginning(Node root) {
        parent = NULL;
        root.parent = this;
    }

    void Node::add_to(Node* newParent) {
        parent = newParent;
    }

    void Node::add_between(Node* back) {
        parent = back->parent;
        add_child(back);
    }

// functions to get children
    Node* Node::get_child_by_index(int index) {
        return children[index];
    }
    
    Node* Node::get_child_by_name(std::string name) {
        int index = 0;
        Node* currentNode = children[index];
        while (currentNode->get_name() != name) {
            index++;
            Node* currentNode = children[index];
        }
        return currentNode;
    }

// getters and setters
    void Node::set_parent(Node* newParent) {
        parent = newParent;
    }

    std::vector <Node*> Node::get_children() {
        return children;
    }
    
    std::string Node::get_name() {
        return name;
    }
    
    Node* Node::get_parent() {
        return parent;
    }
}
