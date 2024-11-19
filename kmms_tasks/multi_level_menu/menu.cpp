#include "menu.hpp"


int menu_node_actions::get_answer(){
    int answer;
    std::cin>>answer;
    return answer;
}


int menu_node_actions::main_menu_action(){
    std::cout<<"Вы в главном меню! В чем вы заинтересованы?"<<std::endl<<
          "1. Одежда"<<std::endl<<
          "2. Обувь"<<std::endl<<
          "3. Выход"<<std::endl;
    return get_answer();
    };

int menu_node_actions::clothes_action(){
    std::cout<<"1. Куртки"<<std::endl<<
          "2. Штаны"<<std::endl<<
          "3. обратно"<<std::endl;
    return get_answer();
}

int menu_node_actions::shoes_action(){
    std::cout<<"1. Кроссвки"<<std::endl<<
          "2. Ботинки"<<std::endl<<
          "3. обратно"<<std::endl;
    return get_answer();
}

int menu_node_actions::jackets_action(){
    std::cout<<"1. Пуховичок"<<std::endl<<
          "2. Ветровка"<<std::endl<<
          "3. обратно"<<std::endl;
    get_answer();
    return 3;
}

int menu_node_actions::pants_action(){
    std::cout<<"1. Брюки"<<std::endl<<
          "2. Трикошки"<<std::endl<<
          "3. обратно"<<std::endl;
    get_answer();
    return 3;
}

int menu_node_actions::sneakers_action(){
    std::cout<<"1. Баскетбольные кроссовки"<<std::endl<<
          "2. Теннисные кроссовки"<<std::endl<<
          "3. обратно"<<std::endl;
    get_answer();
    return 3;
}

int menu_node_actions::boots_action(){
    std::cout<<"1. Кожанные ботинки"<<std::endl<<
          "2. Замшевые ботинки"<<std::endl<<
          "3. обратно"<<std::endl;
    get_answer();
    return 3;
}
