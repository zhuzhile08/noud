#include <noud.h>

namespace noud {
    Node::Node(Node* parent) : parent(parent) { }

    void Node::destroy() {
        delete parent;
    }

    void Node::add_to_beginning(Node root) {
        parent = NULL;
        root.parent = this;
    }

    void Node::add_behind(Node* newParent) {
        parent = newParent;
    }
}
