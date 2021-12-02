#include <noud.h>

namespace noud {
    Node::Node(Node* parent) : parent(parent) { }

    void Node::destroy() {
        for (std::pair<std::string, Node*> pair : children) {
            pair.second->parent = parent;
            children.erase(pair.first);
        }
        delete parent;
    }

    void Node::add_child(Node* newChild) {
        newChild->parent = this;
        children.insert(std::pair<std::string, Node*>(newChild->name, newChild));
    }

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
}
