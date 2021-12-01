#pragma once

#include <string>

namespace noud {
    struct Node {
        std::string name = "node";
        Node* parent = NULL;

        Node();
        Node(Node* parent);

        void destroy();

        void add_to_beginning(Node root);
        void add_behind(Node* newParent);
    };
}