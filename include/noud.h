#pragma once

#include <string>
#include <map>

namespace noud {
    struct Node {
        std::string name = "node";
        Node* parent = NULL;
        std::map <std::string, Node*> children;

        Node();
        Node(Node* parent);

        void destroy();

        void add_child(Node* newChild);

        void add_to_beginning(Node root);
        void add_to(Node* newParent);
        void add_between(Node* back);
    };
}