/*************************
 * @file noud.h
 * @author Zhile Zhu (zhuzhile08@gmail.com)
 * 
 * @brief a library for linked list systems
 * 
 * @version 1.1
 * @date 2021-11-29
 * 
 * @copyright Copyright (c) 2022
 *************************/

#pragma once

#include <string>
#include <vector>

namespace noud {

/// @brief a node / linked list system
class Node {
public:
    /**
     * @brief defautl constructor of the Node object. has no use
     */
    Node();
    /**
     * @brief construct a new Node object
     * 
     * @param parent parent of the node
     * @param name name of the node
     */
    Node(Node* parent, const std::string name = "node");
    /**
     * @brief destroy the Node object
     */
    ~Node();
    /**
     * @brief destroy the Node object. has the same functionality as the destructor 
     */
    void destroy();

    /**
     * @brief add a child object
     * 
     * @param newChild 
     */
    void add_child(Node* newChild);

    /**
     * @brief add the node to the front of a tree
     * 
     * @param root the node that is going to be behind this one
     */
    void add_to_beginning(Node root);

    /**
     * @brief add node to another node
     * 
     * @param newParent the new parent of the node
     */
    void add_to(Node* newParent);

    /**
     * @brief add node between two nodes
     * @cond this only works when the parameter newParent is not at the front of a scene tree
     * 
     * @param newParent the new parent of the node
     */
    void add_between(Node* newParent);

    /**
     * @brief get the child by index
     * 
     * @param index index of the child to find
     * @return Node* 
     */
    Node* get_child_by_index(const int index) const;

    /**
     * @brief get the child by name
     * @brief it's very inefficient, since it has to loop though every child until it finds the desired node
     * 
     * @param name name of the child to find
     * @return Node* 
     */
    Node* get_child_by_name(const std::string name) const;

    /**
     * @brief set the parent
     * 
     * @param newParent the parent
     */
    void set_parent(Node* newParent);

    /**
     * @brief get the children
     * 
     * @return std::vector <Node*> 
     */
    std::vector <Node*> get_children() const;

    /**
     * @brief get the name
     * 
     * @return std::string 
     */
    std::string get_name() const;

    /**
     * @brief get the parent
     * 
     * @return Node* 
     */
    Node* get_parent() const;

protected:
    std::string name = "node";

    Node* parent = NULL;
    std::vector <Node*> children;
};

} // namespace noud
