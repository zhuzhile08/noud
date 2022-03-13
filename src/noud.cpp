#include "noud.h"

namespace noud {

Node::Node() { }

Node::Node(Node* parent, const std::string name) : parent(parent), name(name) { }

Node::~Node() {
    while (!children.empty()) {
        Node* node = children.back();
        node->parent = parent;
        delete node;
    }

    children.erase(children.begin(), children.end());
    delete parent;
}

void Node::destroy() {
    while (!children.empty()) {
        Node* node = children.back();
        node->parent = parent;
        delete node;
    }

    children.erase(children.begin(), children.end());
    delete parent;
}

void Node::add_child(Node* newChild) {
    newChild->parent = this;
    children.push_back(newChild);
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

Node* Node::get_child_by_index(const int index) const {
    return children[index];
}

Node* Node::get_child_by_name(const std::string name) const {
    int index = 0;
    Node* currentNode = children[index];
    while (currentNode->get_name()!= name) {
        index++;
        Node* currentNode = children[index];
    }
    return currentNode;
}

void Node::set_parent(Node* newParent) {
    parent = newParent;
}

std::vector <Node*> Node::get_children() const {
    return children;
}

std::string Node::get_name() const {
    return name;
}

Node* Node::get_parent() const {
    return parent;
}

} // namespace noud
