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
#include <unordered_map>

namespace noud {

/// @brief a node / linked list system
class Node {
public:
    /**
     * @brief default constructor of the Node object. has no use
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
    void add_to_beginning(Node root) noexcept;

    /**
     * @brief add node to another node
     * 
     * @param newParent the new parent of the node
     */
    void add_to(Node* newParent) noexcept;

    /**
     * @brief add node between two nodes
     * @cond this only works when the parameter newParent is not at the front of a scene tree
     * 
     * @param newParent the new parent of the node
     */
    void add_between(Node* newParent);

    /**
     * @brief get the child by name
     * 
     * @param name name of the child to find
     * @return Node* 
     */
    constexpr Node* get_child_by_name(const std::string name) const;

    /**
     * @brief set the parent
     * 
     * @param newParent the parent
     */
    void set_parent(Node* newParent) noexcept;

    /**
     * @brief get the children
     * 
     * @return std::unordered_map <std::string, Node*>
     */
    constexpr std::unordered_map <std::string, Node*> get_children() const noexcept;

    /**
     * @brief get the name
     * 
     * @return std::string 
     */
    constexpr std::string get_name() const noexcept;

    /**
     * @brief get the parent
     * 
     * @return Node* 
     */
    constexpr Node* get_parent() const noexcept;

protected:
    std::string name = "node";

    Node* parent = NULL;
    std::unordered_map <std::string, Node*> children;
};

} // namespace noud
