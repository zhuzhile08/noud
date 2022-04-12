#include "noud.h"

namespace noud {

Node::Node() { }

Node::Node(Node* parent, const std::string name) : parent(parent), name(name) { }

Node::~Node() {
    destroy();
}

void Node::destroy() {
    for (auto& [name, child] : children) child->set_parent(parent);
}

void Node::add_child(Node* newChild) {
    newChild->parent = this;
    children[newChild->get_name()] = newChild;
}

void Node::add_to_beginning(Node root) noexcept {
    parent = nullptr;
    root.parent = this;
}

void Node::add_to(Node* newParent) noexcept {
    parent = newParent;
}

void Node::add_between(Node* back) {
    parent = back->parent;
    add_child(back);
}

Node* Node::get_child_by_name(const std::string name) const {
    return children.at(name);
}

void Node::set_parent(Node* newParent) noexcept {
    parent = newParent;
}

std::unordered_map <std::string, Node*> Node::get_children() const noexcept {
    return children;
}

std::string Node::get_name() const noexcept {
    return name;
}

Node* Node::get_parent() const noexcept {
    return parent;
}

} // namespace noud
