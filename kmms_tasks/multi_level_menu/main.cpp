#include "menu.hpp"

using namespace menu_node_actions;

int main(){
    menu_node main_menu;
    menu_node clothes;
    menu_node shoes;
    menu_node jackets;
    menu_node pants;
    menu_node sneakers;
    menu_node boots;

    main_menu.action = &main_menu_action;
    main_menu.children.push_back(&clothes);
    main_menu.children.push_back(&shoes);
    clothes.parent = &main_menu;
    shoes.parent = &main_menu;

    clothes.action = &clothes_action;
    clothes.children.push_back(&jackets);
    clothes.children.push_back(&pants);
    jackets.action = &jackets_action;
    jackets.parent = &clothes;
    pants.action = &pants_action;
    pants.parent = &clothes;

    shoes.action = &shoes_action;
    shoes.children.push_back(&sneakers);
    shoes.children.push_back(&boots);
    sneakers.action = &sneakers_action;
    sneakers.parent = &shoes;
    boots.action = &boots_action;
    boots.parent = &shoes;

    menu_node current = main_menu;

    while (true){
        int answer = current.action();
        switch (answer)
        {
        case 1:
            current = *current.children[0];
            break;
        case 2:
            current = *current.children[1];
            break;
        case 3:
            current = *current.parent;
            break;
        default:
            break;
        }
        
    }
}