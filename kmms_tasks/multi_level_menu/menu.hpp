#ifndef MENU_HPP
#define MENU_HPP


#include <vector>
#include <iostream>

namespace menu_node_actions{
    struct menu_node{
        menu_node* parent;
        std::vector<menu_node*> children;
        int answer;
        int (*action)();
    };

    int get_answer();

    int main_menu_action();
    int clothes_action();
    int shoes_action();
    int jackets_action();
    int pants_action();
    int sneakers_action();
    int boots_action();

}

#endif