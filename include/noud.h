#pragma once

#include <string>
#include <vector>

namespace noud {
    class Node {
protected:
        std::string name = "node";

        Node* parent = NULL;
        std::vector <Node*> children;

public:
        Node();
        Node(Node* parent, std::string name = "node");

        void destroy();

        void add_child(Node* newChild);

        void add_to_beginning(Node root);
        void add_to(Node* newParent);
        void add_between(Node* back);

        Node* get_child_by_index(int index);
        Node* get_child_by_name(std::string name);

        void set_parent(Node* newParent);
        std::vector <Node*> get_children();
        std::string get_name();
        std::string get_type();
        Node* get_parent();
    };
}
