/**
 * Linked list implementation using smart pointers
 */


#include <memory>
#include <iostream>
#include <unordered_set>
#include <mutex>
#include <thread>


class Node
{
public:
    Node(int id, std::shared_ptr<Node> next_node=nullptr):
        m_id{ id },
        m_next_node{ std::move(next_node) }
    {}

    [[nodiscard]] int
    get_id() const noexcept {
        return m_id;
    }

    [[nodiscard]] std::shared_ptr<Node>
    get_next_node() const noexcept {
        return m_next_node;
    }

    void set_next_node(std::shared_ptr<Node> next_node) noexcept {
        m_next_node = std::move(next_node);
    }

private:
    int                   m_id{};
    std::shared_ptr<Node> m_next_node{};
};


class Linked_list
{
public:
    Linked_list():
        m_head{ nullptr }
    {}

    void print_list() const noexcept;
    void append_node(int node_id) noexcept;
    void add_node_after(int node_id, int after) noexcept;
    void delete_node(int node_id) noexcept;

private:
    std::shared_ptr<Node>   m_head{};
    std::unordered_set<int> m_ids{};
    mutable std::mutex      m_mut{};

    bool node_exists(int node_id) const noexcept;
};


void
Linked_list::print_list() const noexcept
{
    std::lock_guard<std::mutex> lock{ m_mut };

    std::shared_ptr<Node> ptr{ m_head };

    std::cout << "[ ";
    while (ptr != nullptr) {
        std::cout << ptr->get_id() << ' ';
        ptr = ptr->get_next_node();
    }
    std::cout << "]\n";
}


void
Linked_list::append_node(int node_id) noexcept
{
    std::lock_guard<std::mutex> lock{ m_mut };

    if (node_exists(node_id)) {
        throw std::runtime_error{ "Node to append already exists" };
    }

    if (m_head == nullptr) {
        // list doesn't exist yet
        m_head = std::make_shared<Node>(node_id);
    } else {
        // list already exists
        auto ptr{ m_head };
        while (ptr->get_next_node() != nullptr) {
            ptr = ptr->get_next_node();
        }

        ptr->set_next_node(std::make_shared<Node>(node_id));
    }
    m_ids.insert(node_id);
}


void
Linked_list::add_node_after(int node_id, int after) noexcept
{
    std::lock_guard<std::mutex> lock{ m_mut };

    if (node_exists(node_id)) {
        throw std::runtime_error{ "Node to add already exists" };
    }

    if (!node_exists(after)) {
        throw std::runtime_error{ "Node to add after doesn't exist"};
    }

    auto ptr{ m_head };
    while (ptr->get_id() != after) {
        ptr = ptr->get_next_node();
    }

    auto new_node{ std::make_shared<Node>(node_id) };
    new_node->set_next_node(std::move(ptr->get_next_node()));
    ptr->set_next_node(std::move(new_node));

    m_ids.insert(node_id);
}


void
Linked_list::delete_node(int node_id) noexcept
{
    std::lock_guard<std::mutex> lock{ m_mut };

    if (!node_exists(node_id)) {
        throw std::runtime_error{ "Node to delete doesn't exist" };
    }

    auto ptr{ m_head };
    std::shared_ptr<Node> prev{ nullptr };

    while (ptr->get_id() != node_id) {
        prev = ptr;
        ptr  = ptr->get_next_node();
    }

    if (prev == nullptr) {
        // delete head
        m_head = std::move(m_head->get_next_node());
    } else {
        prev->set_next_node(std::move(ptr->get_next_node()));
    }

    m_ids.erase(node_id);
}


bool
Linked_list::node_exists(int node_id) const noexcept
{
    if (m_ids.count(node_id) != 0) {
        return true;
    }
    return false;
}


void thread1(Linked_list& list)
{
    std::thread t{ &Linked_list::delete_node, &list, 20 };
    std::cout << "Inside thread 1\n";
    t.detach();
}


void thread2(Linked_list& list)
{
    std::thread t{ &Linked_list::print_list, &list };
    std::cout << "Inside thread 2\n";
    t.detach();
}


int main()
{
    Linked_list list{};

    list.append_node(10);
    list.append_node(20);
    list.append_node(30);

   thread1(list);
   thread2(list);

   std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
