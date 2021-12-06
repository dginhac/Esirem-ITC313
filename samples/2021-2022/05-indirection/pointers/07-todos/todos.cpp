/*
* @File:    todos.cpp
* @Project: C++ programming - ESIREM 3A IT
* @Author:  Dominique Ginhac <d0m>
* @Email:   dginhac@u-bourgogne.fr
* @Date:    2020-10-21 15:44:06
* @Summary:
*
* @Last Modified by:   d0m
* @Last Modified time: 2021-12-06 14:42:22
*/

#include "todos.h"
#include <iostream>

namespace todo {
    Todos::Todos() {
    }
    void Todos::add(Todo todo) {
        _todos.push_back(todo);
    }
    void Todos::del(int id) {
        if (id < _todos.size()) {
            _todos.erase(_todos.begin()+id);
        }
    }
    void Todos::completed(int id, bool status)  {
        if (id < _todos.size()) {
            _todos.at(id).setCompleted(status);
        }
    }







    Todo* Todos::find(std::string title) {
        auto it = std::find_if(_todos.begin(), _todos.end(),
                               [title](const Todo& obj) {
                                    return obj.title() == title;
                                });
        int index = std::distance(_todos.begin(), it) ;
        return &_todos.at(index);
    }



    

    void Todos::update(Todo* todo, std::string title) {
        todo->updateTitle(title);
    }


    void Todos::sort() {
        std::sort(_todos.begin(),_todos.end(),
            [](Todo const& t1, Todo const& t2) {
                return t1.dueDate() < t2.dueDate();
            }
        );
    }

    Todo Todos::next() const {
        assert (_todos.empty() == false && "No todo");
        auto it = _todos.begin();
        return *it;
    }



    std::ostream& operator<<(std::ostream& os, const Todos& todos) {
        for (const Todo todo: todos._todos)  {
            os << todo;
        }
        return os;
    }


} // todo