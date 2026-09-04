#include <memory>
#include <iostream>


class Node
{
public:
    Node(int id, std::shared_ptr<Node> next_node=nullptr):
        m_id{ id },
        m_next_node{ std::move(next_node) }
    {}

    int get_id() const noexcept {
        return m_id;
    }

    std::shared_ptr<Node> get_next_node() const noexcept {
        return m_next_node;
    }

    void set_next_node(std::shared_ptr<Node> next_node) noexcept {
        m_next_node = std::move(next_node);
    }

private:
    int                   m_id{};
    std::shared_ptr<Node> m_next_node{};
};


